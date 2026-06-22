import { useState, useEffect, useCallback } from 'react';
import './shared.css';

function AlunoLista({ atualizar, onEditar }) {
    const [alunos, setAlunos] = useState([]);
    const [carregando, setCarregando] = useState(true);
    const [erro, setErro] = useState('');
    const [removendo, setRemovendo] = useState(null);

    const buscar = useCallback(async () => {
        setCarregando(true); setErro('');
        try {
            const resp = await fetch('/api/alunos?porPagina=100');
            if (!resp.ok) throw new Error();
            const dados = await resp.json();
            setAlunos(dados.alunos);
        } catch { setErro('Não foi possível carregar os alunos.'); }
        finally { setCarregando(false); }
    }, []);

    useEffect(() => { buscar(); }, [buscar, atualizar]);

    async function handleExcluir(aluno) {
        if (!window.confirm(`Excluir o aluno "${aluno.nome}"?`)) return;
        setRemovendo(aluno.id);
        try {
            const resp = await fetch(`/api/alunos/${aluno.id}`, { method: 'DELETE' });
            if (!resp.ok) { const d = await resp.json().catch(() => ({})); alert(d.erro || 'Erro ao excluir.'); return; }
            setAlunos(prev => prev.filter(a => a.id !== aluno.id));
        } catch { alert('Erro de conexão.'); }
        finally { setRemovendo(null); }
    }

    return (
        <section className="crud-section">
            <h2>Alunos Cadastrados</h2>
            {carregando && <p className="status">Carregando...</p>}
            {erro && <p className="status erro">{erro}</p>}
            {!carregando && !erro && alunos.length === 0 && <p className="status vazio">Nenhum aluno cadastrado.</p>}
            {alunos.length > 0 && (
                <table className="crud-tabela">
                    <thead><tr><th>ID</th><th>Nome</th><th>Matrícula</th><th>Curso</th><th>Ativo</th><th>Ações</th></tr></thead>
                    <tbody>
                        {alunos.map(a => (
                            <tr key={a.id}>
                                <td>{a.id}</td>
                                <td>{a.nome}</td>
                                <td>{a.matricula}</td>
                                <td>{a.Curso?.descricao ?? a.id_curso}</td>
                                <td>{a.ativo ? 'Sim' : 'Não'}</td>
                                <td className="acoes-celula">
                                    <button className="btn-acao editar" onClick={() => onEditar(a)} disabled={removendo === a.id}>Editar</button>
                                    <button className="btn-acao excluir" onClick={() => handleExcluir(a)} disabled={removendo === a.id}>
                                        {removendo === a.id ? '...' : 'Excluir'}
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

export default AlunoLista;
