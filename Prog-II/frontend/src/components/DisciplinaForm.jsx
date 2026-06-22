import { useState, useEffect } from 'react';
import './shared.css';

function DisciplinaForm({ editando, onSalvo, onCancelar }) {
    const VAZIO = { nome: '', codigo: '', cargaHoraria: '' };
    const [form, setForm] = useState(VAZIO);
    const [erro, setErro] = useState('');
    const [sucesso, setSucesso] = useState('');
    const [carregando, setCarregando] = useState(false);

    useEffect(() => {
        if (editando) {
            setForm({ nome: editando.nome ?? '', codigo: editando.codigo ?? '', cargaHoraria: editando.cargaHoraria ?? '' });
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

        if (!form.nome.trim() || !form.codigo.trim() || !form.cargaHoraria) {
            setErro('Preencha todos os campos.');
            return;
        }

        setCarregando(true);
        try {
            const url = editando ? `/api/disciplinas/${editando.id}` : '/api/disciplinas';
            const metodo = editando ? 'PUT' : 'POST';
            const body = { ...form, cargaHoraria: Number(form.cargaHoraria) };

            const resp = await fetch(url, {
                method: metodo,
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(body),
            });
            const dados = await resp.json();
            if (!resp.ok) { setErro(dados.erro || `Erro ${resp.status}`); return; }

            setSucesso(editando ? `Disciplina "${dados.nome}" atualizada!` : `Disciplina "${dados.nome}" cadastrada!`);
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
            <h2>{modoEdicao ? `Editar Disciplina #${editando.id}` : 'Cadastrar Nova Disciplina'}</h2>
            <form className="crud-form" onSubmit={handleSubmit} noValidate>
                <div className="campo">
                    <label htmlFor="dis-nome">Nome</label>
                    <input id="dis-nome" name="nome" type="text" placeholder="Ex: Programação II"
                        value={form.nome} onChange={handleChange} disabled={carregando} maxLength={100} />
                </div>
                <div className="campo-linha">
                    <div className="campo">
                        <label htmlFor="dis-codigo">Código</label>
                        <input id="dis-codigo" name="codigo" type="text" placeholder="Ex: CC111"
                            value={form.codigo} onChange={handleChange} disabled={carregando} maxLength={10} />
                    </div>
                    <div className="campo">
                        <label htmlFor="dis-carga">Carga Horária (h)</label>
                        <input id="dis-carga" name="cargaHoraria" type="number" placeholder="Ex: 60"
                            value={form.cargaHoraria} onChange={handleChange} disabled={carregando} min={1} />
                    </div>
                </div>
                {erro && <p className="mensagem erro">{erro}</p>}
                {sucesso && <p className="mensagem sucesso">{sucesso}</p>}
                <div className="acoes-form">
                    <button type="submit" className="btn-submit" disabled={carregando}>
                        {carregando ? 'Salvando...' : modoEdicao ? 'Salvar' : 'Cadastrar'}
                    </button>
                    {modoEdicao && (
                        <button type="button" className="btn-cancelar" onClick={onCancelar} disabled={carregando}>Cancelar</button>
                    )}
                </div>
            </form>
        </section>
    );
}

export default DisciplinaForm;
