import { useState } from 'react';
import CursoForm from './components/CursoForm';
import CursoLista from './components/CursoLista';
import AlunoForm from './components/AlunoForm';
import AlunoLista from './components/AlunoLista';
import DisciplinaForm from './components/DisciplinaForm';
import DisciplinaLista from './components/DisciplinaLista';
import MatriculaForm from './components/MatriculaForm';
import MatriculaLista from './components/MatriculaLista';
import './App.css';

const ABAS = [
    { id: 'cursos',      label: 'Cursos' },
    { id: 'alunos',      label: 'Alunos' },
    { id: 'disciplinas', label: 'Disciplinas' },
    { id: 'matriculas',  label: 'Matrículas' },
];

// Hook genérico que encapsula o par (editando, contador) de cada entidade
function useCrud() {
    const [editando, setEditando] = useState(null);
    const [contador, setContador] = useState(0);

    function salvo()    { setEditando(null); setContador(c => c + 1); }
    function editar(x)  { setEditando(x); window.scrollTo({ top: 0, behavior: 'smooth' }); }
    function cancelar() { setEditando(null); }

    return { editando, contador, salvo, editar, cancelar };
}

function App() {
    const [aba, setAba] = useState('cursos');
    const curso      = useCrud();
    const aluno      = useCrud();
    const disciplina = useCrud();
    const matricula  = useCrud();

    return (
        <div className="app">
            <header className="app-header">
                <h1>Sistema Acadêmico</h1>
                <p>GEX613 — Programação II · UFFS</p>
            </header>

            <nav className="app-nav">
                {ABAS.map(a => (
                    <button
                        key={a.id}
                        className={`aba${aba === a.id ? ' aba-ativa' : ''}`}
                        onClick={() => setAba(a.id)}
                    >
                        {a.label}
                    </button>
                ))}
            </nav>

            <main className="app-main">
                {aba === 'cursos' && (
                    <>
                        <CursoForm
                            cursoEditando={curso.editando}
                            onSalvo={curso.salvo}
                            onCancelarEdicao={curso.cancelar}
                        />
                        <CursoLista atualizar={curso.contador} onEditar={curso.editar} />
                    </>
                )}

                {aba === 'alunos' && (
                    <>
                        <AlunoForm editando={aluno.editando} onSalvo={aluno.salvo} onCancelar={aluno.cancelar} />
                        <AlunoLista atualizar={aluno.contador} onEditar={aluno.editar} />
                    </>
                )}

                {aba === 'disciplinas' && (
                    <>
                        <DisciplinaForm editando={disciplina.editando} onSalvo={disciplina.salvo} onCancelar={disciplina.cancelar} />
                        <DisciplinaLista atualizar={disciplina.contador} onEditar={disciplina.editar} />
                    </>
                )}

                {aba === 'matriculas' && (
                    <>
                        <MatriculaForm editando={matricula.editando} onSalvo={matricula.salvo} onCancelar={matricula.cancelar} />
                        <MatriculaLista atualizar={matricula.contador} onEditar={matricula.editar} />
                    </>
                )}
            </main>
        </div>
    );
}

export default App;
