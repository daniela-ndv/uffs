import { useState, useEffect, useCallback } from 'react';
import './shared.css';

const BADGE = { CURSANDO: '#3b82f6', APROVADO: '#16a34a', REPROVADO: '#dc2626', TRANCADO: '#9ca3af' };

function MatriculaLista({ atualizar, onEditar }) {
    const [matriculas, setMatriculas] = useState([]);
    const [carregando, setCarregando] = useState(true);
    const [erro, setErro] = useState('');
    const [removendo, setRemovendo] = useState(null);

    const buscar = useCallback(async () => {
        setCarregando(true); setErro('');
        try {
            const resp = await fetch('/api/matriculas?porPagina=100');
            if (!resp.ok) throw new Error();
            const dados = await resp.json();
            setMatriculas(dados.matriculas);
        } catch { setErro('Não foi possível carregar as matrículas.'); }
        finally { setCarregando(false); }
    }, []);

    useEffect(() => { buscar(); }, [buscar, atualizar]);

    async function handleExcluir(m) {
        if (!window.confirm(`Excluir a matrícula #${m.id}?`)) return;
        setRemovendo(m.id);
        try {
            const resp = await fetch(`/api/matriculas/${m.id}`, { method: 'DELETE' });
            if (!resp.ok) { const j = await resp.json().catch(() => ({})); alert(j.erro || 'Erro ao excluir.'); return; }
            setMatriculas(prev => prev.filter(x => x.id !== m.id));
        } catch { alert('Erro de conexão.'); }
        finally { setRemovendo(null); }
    }

    return (
        <section className="crud-section">
            <h2>Matrículas</h2>
            {carregando && <p className="status">Carregando...</p>}
            {erro && <p className="status erro">{erro}</p>}
            {!carregando && !erro && matriculas.length === 0 && <p className="status vazio">Nenhuma matrícula registrada.</p>}
            {matriculas.length > 0 && (
                <table className="crud-tabela">
                    <thead><tr><th>ID</th><th>Aluno</th><th>Curso</th><th>Semestre</th><th>Nota</th><th>Situação</th><th>Ações</th></tr></thead>
                    <tbody>
                        {matriculas.map(m => (
                            <tr key={m.id}>
                                <td>{m.id}</td>
                                <td>{m.Aluno?.nome ?? m.id_aluno}</td>
                                <td>{m.Curso?.descricao ?? m.id_curso}</td>
                                <td>{m.semestre}</td>
                                <td>{m.nota ?? '—'}</td>
                                <td>
                                    <span style={{ color: BADGE[m.situacao], fontWeight: 600 }}>{m.situacao}</span>
                                </td>
                                <td className="acoes-celula">
                                    <button className="btn-acao editar" onClick={() => onEditar(m)} disabled={removendo === m.id}>Editar</button>
                                    <button className="btn-acao excluir" onClick={() => handleExcluir(m)} disabled={removendo === m.id}>
                                        {removendo === m.id ? '...' : 'Excluir'}
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

export default MatriculaLista;
