import { useState, useEffect } from 'react';
import './CursoForm.css';

// Formulário controlado para cadastro e edição de cursos
// Quando `cursoEditando` é fornecido, opera em modo de edição (PATCH)
function CursoForm({ cursoEditando, onSalvo, onCancelarEdicao }) {
    const [descricao, setDescricao] = useState('');
    const [erro, setErro] = useState('');
    const [sucesso, setSucesso] = useState('');
    const [carregando, setCarregando] = useState(false);

    // Sincroniza o campo com o curso sendo editado
    useEffect(() => {
        if (cursoEditando) {
            setDescricao(cursoEditando.descricao ?? '');
        } else {
            setDescricao('');
        }
        setErro('');
        setSucesso('');
    }, [cursoEditando]);

    const modoEdicao = cursoEditando !== null;

    async function handleSubmit(e) {
        e.preventDefault();
        setErro('');
        setSucesso('');

        if (!descricao.trim()) {
            setErro('Preencha a descrição do curso.');
            return;
        }

        setCarregando(true);
        try {
            const url = modoEdicao ? `/api/cursos/${cursoEditando.id}` : '/api/cursos';
            const metodo = modoEdicao ? 'PATCH' : 'POST';

            const resposta = await fetch(url, {
                method: metodo,
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ descricao }),
            });

            const dados = await resposta.json();

            if (!resposta.ok) {
                setErro(dados.erro || `Erro ${resposta.status}: não foi possível salvar.`);
                return;
            }

            setSucesso(
                modoEdicao
                    ? `Curso "${dados.descricao}" atualizado com sucesso!`
                    : `Curso "${dados.descricao}" cadastrado com sucesso!`
            );
            setDescricao('');
            onSalvo(dados);
        } catch {
            setErro('Erro de conexão. Verifique se o servidor está rodando.');
        } finally {
            setCarregando(false);
        }
    }

    return (
        <section className="curso-form-section">
            <h2>{modoEdicao ? `Editar Curso #${cursoEditando.id}` : 'Cadastrar Novo Curso'}</h2>

            <form className="curso-form" onSubmit={handleSubmit} noValidate>
                <div className="campo">
                    <label htmlFor="descricao">Descrição</label>
                    <input
                        id="descricao"
                        name="descricao"
                        type="text"
                        placeholder="Ex: Ciência da Computação"
                        value={descricao}
                        onChange={e => setDescricao(e.target.value)}
                        disabled={carregando}
                        maxLength={200}
                        autoFocus
                    />
                </div>

                {erro && <p className="mensagem erro">{erro}</p>}
                {sucesso && <p className="mensagem sucesso">{sucesso}</p>}

                <div className="acoes">
                    <button type="submit" className="btn-submit" disabled={carregando}>
                        {carregando ? 'Salvando...' : modoEdicao ? 'Salvar alterações' : 'Cadastrar'}
                    </button>
                    {modoEdicao && (
                        <button
                            type="button"
                            className="btn-cancelar"
                            onClick={onCancelarEdicao}
                            disabled={carregando}
                        >
                            Cancelar
                        </button>
                    )}
                </div>
            </form>
        </section>
    );
}

export default CursoForm;
