import { useState, useEffect, useCallback } from 'react';
import './CursoLista.css';

// Lista todos os cursos com botões de editar e excluir
// onEditar: sobe o curso selecionado para o App
// atualizar: qualquer mudança nessa prop dispara um novo fetch
function CursoLista({ atualizar, onEditar }) {
    const [cursos, setCursos] = useState([]);
    const [carregando, setCarregando] = useState(true);
    const [erro, setErro] = useState('');
    const [removendo, setRemovendo] = useState(null); // id do curso sendo removido

    const buscarCursos = useCallback(async () => {
        setCarregando(true);
        setErro('');
        try {
            const resposta = await fetch('/api/cursos');
            if (!resposta.ok) throw new Error(`Erro ${resposta.status}`);
            const dados = await resposta.json();
            setCursos(dados.cursos);
        } catch {
            setErro('Não foi possível carregar os cursos.');
        } finally {
            setCarregando(false);
        }
    }, []);

    // Rebusca sempre que `atualizar` mudar (novo cadastro, edição ou exclusão)
    useEffect(() => {
        buscarCursos();
    }, [buscarCursos, atualizar]);

    async function handleExcluir(curso) {
        if (!window.confirm(`Excluir o curso "${curso.descricao}"?`)) return;

        setRemovendo(curso.id);
        try {
            const resposta = await fetch(`/api/cursos/${curso.id}`, { method: 'DELETE' });
            if (!resposta.ok) {
                const dados = await resposta.json().catch(() => ({}));
                alert(dados.erro || `Erro ${resposta.status} ao excluir.`);
                return;
            }
            // Atualiza a lista localmente sem novo fetch
            setCursos(anterior => anterior.filter(c => c.id !== curso.id));
        } catch {
            alert('Erro de conexão ao tentar excluir.');
        } finally {
            setRemovendo(null);
        }
    }

    return (
        <section className="curso-lista-section">
            <h2>Cursos Cadastrados</h2>

            {carregando && <p className="status">Carregando...</p>}
            {erro && <p className="status erro">{erro}</p>}

            {!carregando && !erro && cursos.length === 0 && (
                <p className="status vazio">Nenhum curso cadastrado ainda.</p>
            )}

            {cursos.length > 0 && (
                <table className="curso-tabela">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Descrição</th>
                            <th>Ações</th>
                        </tr>
                    </thead>
                    <tbody>
                        {cursos.map(curso => (
                            <tr key={curso.id}>
                                <td>{curso.id}</td>
                                <td>{curso.descricao}</td>
                                <td className="acoes-celula">
                                    <button
                                        className="btn-acao editar"
                                        onClick={() => onEditar(curso)}
                                        disabled={removendo === curso.id}
                                    >
                                        Editar
                                    </button>
                                    <button
                                        className="btn-acao excluir"
                                        onClick={() => handleExcluir(curso)}
                                        disabled={removendo === curso.id}
                                    >
                                        {removendo === curso.id ? '...' : 'Excluir'}
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

export default CursoLista;
