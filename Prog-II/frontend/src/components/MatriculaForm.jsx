import { useState, useEffect } from 'react';
import './shared.css';

const SITUACOES = ['CURSANDO', 'APROVADO', 'REPROVADO', 'TRANCADO'];

function MatriculaForm({ editando, onSalvo, onCancelar }) {
    const VAZIO = { id_aluno: '', id_curso: '', semestre: '', nota: '', situacao: 'CURSANDO' };
    const [form, setForm] = useState(VAZIO);
    const [alunos, setAlunos] = useState([]);
    const [cursos, setCursos] = useState([]);
    const [erro, setErro] = useState('');
    const [sucesso, setSucesso] = useState('');
    const [carregando, setCarregando] = useState(false);

    useEffect(() => {
        Promise.all([
            fetch('/api/alunos?porPagina=200').then(r => r.json()),
            fetch('/api/cursos?porPagina=100').then(r => r.json()),
        ]).then(([a, c]) => {
            setAlunos(a.alunos ?? []);
            setCursos(c.cursos ?? []);
        }).catch(() => {});
    }, []);

    useEffect(() => {
        if (editando) {
            setForm({
                id_aluno: editando.id_aluno ?? '',
                id_curso: editando.id_curso ?? '',
                semestre: editando.semestre ?? '',
                nota: editando.nota ?? '',
                situacao: editando.situacao ?? 'CURSANDO',
            });
        } else {
            setForm(VAZIO);
        }
        setErro(''); setSucesso('');
    }, [editando]);

    function handleChange(e) {
        const { name, value } = e.target;
        setForm(prev => ({ ...prev, [name]: value }));
    }

    async function handleSubmit(e) {
        e.preventDefault();
        setErro(''); setSucesso('');

        if (!form.id_aluno || !form.id_curso || !form.semestre.trim()) {
            setErro('Preencha aluno, curso e semestre.');
            return;
        }

        setCarregando(true);
        try {
            const url = editando ? `/api/matriculas/${editando.id}` : '/api/matriculas';
            const metodo = editando ? 'PATCH' : 'POST';
            const body = {
                id_aluno: Number(form.id_aluno),
                id_curso: Number(form.id_curso),
                semestre: form.semestre,
                situacao: form.situacao,
                nota: form.nota !== '' ? Number(form.nota) : null,
            };

            const resp = await fetch(url, {
                method: metodo,
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(body),
            });
            const dados = await resp.json();
            if (!resp.ok) { setErro(dados.erro || `Erro ${resp.status}`); return; }

            setSucesso(editando ? `Matrícula #${dados.id} atualizada!` : `Matrícula #${dados.id} criada!`);
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
            <h2>{modoEdicao ? `Editar Matrícula #${editando.id}` : 'Nova Matrícula'}</h2>
            <form className="crud-form" onSubmit={handleSubmit} noValidate>
                <div className="campo-linha">
                    <div className="campo">
                        <label htmlFor="mat-aluno">Aluno</label>
                        <select id="mat-aluno" name="id_aluno" value={form.id_aluno} onChange={handleChange} disabled={carregando}>
                            <option value="">Selecione...</option>
                            {alunos.map(a => <option key={a.id} value={a.id}>{a.nome} ({a.matricula})</option>)}
                        </select>
                    </div>
                    <div className="campo">
                        <label htmlFor="mat-curso">Curso</label>
                        <select id="mat-curso" name="id_curso" value={form.id_curso} onChange={handleChange} disabled={carregando}>
                            <option value="">Selecione...</option>
                            {cursos.map(c => <option key={c.id} value={c.id}>{c.descricao}</option>)}
                        </select>
                    </div>
                </div>
                <div className="campo-linha">
                    <div className="campo">
                        <label htmlFor="mat-semestre">Semestre</label>
                        <input id="mat-semestre" name="semestre" type="text" placeholder="Ex: 2024/1"
                            value={form.semestre} onChange={handleChange} disabled={carregando} maxLength={6} />
                    </div>
                    <div className="campo">
                        <label htmlFor="mat-situacao">Situação</label>
                        <select id="mat-situacao" name="situacao" value={form.situacao} onChange={handleChange} disabled={carregando}>
                            {SITUACOES.map(s => <option key={s} value={s}>{s}</option>)}
                        </select>
                    </div>
                </div>
                <div className="campo">
                    <label htmlFor="mat-nota">Nota (opcional)</label>
                    <input id="mat-nota" name="nota" type="number" placeholder="0.0 – 10.0"
                        value={form.nota} onChange={handleChange} disabled={carregando} min={0} max={10} step={0.1} />
                </div>
                {erro && <p className="mensagem erro">{erro}</p>}
                {sucesso && <p className="mensagem sucesso">{sucesso}</p>}
                <div className="acoes-form">
                    <button type="submit" className="btn-submit" disabled={carregando}>
                        {carregando ? 'Salvando...' : modoEdicao ? 'Salvar' : 'Registrar'}
                    </button>
                    {modoEdicao && (
                        <button type="button" className="btn-cancelar" onClick={onCancelar} disabled={carregando}>Cancelar</button>
                    )}
                </div>
            </form>
        </section>
    );
}

export default MatriculaForm;
