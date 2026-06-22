import { useState, useEffect } from 'react';
import './shared.css';

function AlunoForm({ editando, onSalvo, onCancelar }) {
    const VAZIO = { nome: '', matricula: '', id_curso: '', ativo: true };
    const [form, setForm] = useState(VAZIO);
    const [cursos, setCursos] = useState([]);
    const [erro, setErro] = useState('');
    const [sucesso, setSucesso] = useState('');
    const [carregando, setCarregando] = useState(false);

    useEffect(() => {
        fetch('/api/cursos?porPagina=100')
            .then(r => r.json())
            .then(d => setCursos(d.cursos ?? []))
            .catch(() => {});
    }, []);

    useEffect(() => {
        if (editando) {
            setForm({
                nome: editando.nome ?? '',
                matricula: editando.matricula ?? '',
                id_curso: editando.id_curso ?? '',
                ativo: editando.ativo ?? true,
            });
        } else {
            setForm(VAZIO);
        }
        setErro(''); setSucesso('');
    }, [editando]);

    function handleChange(e) {
        const { name, value, type, checked } = e.target;
        setForm(prev => ({ ...prev, [name]: type === 'checkbox' ? checked : value }));
    }

    async function handleSubmit(e) {
        e.preventDefault();
        setErro(''); setSucesso('');

        if (!form.nome.trim() || !form.matricula.trim() || !form.id_curso) {
            setErro('Preencha nome, matrícula e curso.');
            return;
        }
        if (!/^\d{7}$/.test(form.matricula)) {
            setErro('Matrícula deve ter exatamente 7 dígitos.');
            return;
        }

        setCarregando(true);
        try {
            const url = editando ? `/api/alunos/${editando.id}` : '/api/alunos';
            const metodo = editando ? 'PATCH' : 'POST';
            const body = { ...form, id_curso: Number(form.id_curso) };

            const resp = await fetch(url, {
                method: metodo,
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(body),
            });
            const dados = await resp.json();
            if (!resp.ok) { setErro(dados.erro || `Erro ${resp.status}`); return; }

            setSucesso(editando ? `Aluno "${dados.nome}" atualizado!` : `Aluno "${dados.nome}" cadastrado!`);
            setForm(VAZIO);
            onSalvo(dados);
        } catch {
            setErro('Erro de conexão.');
        } finally {
            setCarregando(false);
        }
    }

    const modoEdicao = editando !== null;

    return (
        <section className="crud-section">
            <h2>{modoEdicao ? `Editar Aluno #${editando.id}` : 'Cadastrar Novo Aluno'}</h2>
            <form className="crud-form" onSubmit={handleSubmit} noValidate>
                <div className="campo-linha">
                    <div className="campo">
                        <label htmlFor="nome">Nome</label>
                        <input id="nome" name="nome" type="text" placeholder="Nome completo"
                            value={form.nome} onChange={handleChange} disabled={carregando} maxLength={100} />
                    </div>
                    <div className="campo">
                        <label htmlFor="matricula">Matrícula (7 dígitos)</label>
                        <input id="matricula" name="matricula" type="text" placeholder="Ex: 2410001"
                            value={form.matricula} onChange={handleChange} disabled={carregando} maxLength={7} />
                    </div>
                </div>
                <div className="campo-linha">
                    <div className="campo">
                        <label htmlFor="id_curso">Curso</label>
                        <select id="id_curso" name="id_curso" value={form.id_curso}
                            onChange={handleChange} disabled={carregando}>
                            <option value="">Selecione...</option>
                            {cursos.map(c => <option key={c.id} value={c.id}>{c.descricao}</option>)}
                        </select>
                    </div>
                    <div className="campo campo-checkbox">
                        <input id="ativo" name="ativo" type="checkbox"
                            checked={form.ativo} onChange={handleChange} disabled={carregando} />
                        <label htmlFor="ativo">Ativo</label>
                    </div>
                </div>
                {erro && <p className="mensagem erro">{erro}</p>}
                {sucesso && <p className="mensagem sucesso">{sucesso}</p>}
                <div className="acoes-form">
                    <button type="submit" className="btn-submit" disabled={carregando}>
                        {carregando ? 'Salvando...' : modoEdicao ? 'Salvar' : 'Cadastrar'}
                    </button>
                    {modoEdicao && (
                        <button type="button" className="btn-cancelar" onClick={onCancelar} disabled={carregando}>
                            Cancelar
                        </button>
                    )}
                </div>
            </form>
        </section>
    );
}

export default AlunoForm;
