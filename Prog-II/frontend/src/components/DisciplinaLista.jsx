import { useState, useEffect, useCallback } from 'react';
import './shared.css';

function DisciplinaLista({ atualizar, onEditar }) {
    const [disciplinas, setDisciplinas] = useState([]);
    const [carregando, setCarregando] = useState(true);
    const [erro, setErro] = useState('');
    const [removendo, setRemovendo] = useState(null);

    const buscar = useCallback(async () => {
        setCarregando(true); setErro('');
        try {
            const resp = await fetch('/api/disciplinas');
            if (!resp.ok) throw new Error();
            const dados = await resp.json();
            setDisciplinas(dados.disciplinas);
        } catch { setErro('Não foi possível carregar as disciplinas.'); }
        finally { setCarregando(false); }
    }, []);

    useEffect(() => { buscar(); }, [buscar, atualizar]);

    async function handleExcluir(d) {
        if (!window.confirm(`Excluir a disciplina "${d.nome}"?`)) return;
        setRemovendo(d.id);
        try {
            const resp = await fetch(`/api/disciplinas/${d.id}`, { method: 'DELETE' });
            if (!resp.ok) { const j = await resp.json().catch(() => ({})); alert(j.erro || 'Erro ao excluir.'); return; }
            setDisciplinas(prev => prev.filter(x => x.id !== d.id));
        } catch { alert('Erro de conexão.'); }
        finally { setRemovendo(null); }
    }

    return (
        <section className="crud-section">
            <h2>Disciplinas Cadastradas</h2>
            {carregando && <p className="status">Carregando...</p>}
            {erro && <p className="status erro">{erro}</p>}
            {!carregando && !erro && disciplinas.length === 0 && <p className="status vazio">Nenhuma disciplina cadastrada.</p>}
            {disciplinas.length > 0 && (
                <table className="crud-tabela">
                    <thead><tr><th>ID</th><th>Nome</th><th>Código</th><th>C.H. (h)</th><th>Ações</th></tr></thead>
                    <tbody>
                        {disciplinas.map(d => (
                            <tr key={d.id}>
                                <td>{d.id}</td>
                                <td>{d.nome}</td>
                                <td>{d.codigo}</td>
                                <td>{d.cargaHoraria}</td>
                                <td className="acoes-celula">
                                    <button className="btn-acao editar" onClick={() => onEditar(d)} disabled={removendo === d.id}>Editar</button>
                                    <button className="btn-acao excluir" onClick={() => handleExcluir(d)} disabled={removendo === d.id}>
                                        {removendo === d.id ? '...' : 'Excluir'}
                                    </button>
                                </td>
                            </tr>
                        ))}
                    </tbody>
                </table>
            )}
        </section>
    );
}

export default DisciplinaLista;
