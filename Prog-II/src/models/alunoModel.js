// O Model encapsula TODA a lógica de dados.
// O Controller nunca acessa o banco diretamente.

const DisciplinaModel = require('./disciplinaModel');

let alunos = [
    { id: 1, nome: 'Ana Souza', matricula: '2024001', curso: 'CC' },
    { id: 2, nome: 'Bruno Lima', matricula: '2024002', curso: 'CC' },
];
let proximoId = 3;

// Relação simples aluno -> disciplinas para o exercício de Promise.all
const matriculasPorAluno = [
    { alunoId: 1, disciplinaId: 1 },
    { alunoId: 1, disciplinaId: 2 },
    { alunoId: 2, disciplinaId: 2 },
];

// Regra de negócio centralizada aqui (DRY!)
function validarMatricula(matricula) {
    return /^\d{7}$/.test(matricula);
}

function listarTodos(filtros = {}) {
    let resultado = [...alunos];
    if (filtros.curso) {
        resultado = resultado.filter(a => a.curso === filtros.curso.toUpperCase());
    }
    return resultado;
}

function buscarPorId(id) {
    return alunos.find(a => a.id === id) || null;
}

function criar(dados) {
    if (!dados.nome || !dados.matricula || !dados.curso) {
        throw new Error('Campos obrigatórios ausentes');
    }
    if (!validarMatricula(dados.matricula)) {
        throw new Error('Formato de matrícula inválido');
    }
    const existe = alunos.find(a => a.matricula === dados.matricula);
    if (existe) throw new Error('Matrícula já cadastrada');

    const novoAluno = { id: proximoId++, ...dados };
    alunos.push(novoAluno);
    return novoAluno;
}

// PUT - exige objeto completo
function atualizar(id, dados) {
    const idx = alunos.findIndex(a => a.id === id);
    if (idx === -1) return null;

    if (!dados.nome || !dados.matricula || !dados.curso) {
        throw new Error('Campos obrigatórios ausentes para PUT');
    }

    if (!validarMatricula(dados.matricula)) {
        throw new Error('Formato de matrícula inválido');
    }

    const existe = alunos.find(a => a.matricula === dados.matricula && a.id !== id);
    if (existe) throw new Error('Matrícula já cadastrada');

    alunos[idx] = {
        id,
        nome: dados.nome,
        matricula: dados.matricula,
        curso: dados.curso
    };

    return alunos[idx];
}

// PATCH - atualiza parcialmente
function atualizarParcial(id, dados) {
    const idx = alunos.findIndex(a => a.id === id);
    if (idx === -1) return null;
    alunos[idx] = { ...alunos[idx], ...dados, id };
    return alunos[idx];
}

function remover(id) {
    const idx = alunos.findIndex(a => a.id === id);
    if (idx === -1) return false;
    alunos.splice(idx, 1);
    return true;
}

async function buscarAlunoAsync(alunoId) {
    const aluno = buscarPorId(alunoId);
    if (!aluno) {
        throw new Error('Aluno não encontrado');
    }
    return aluno;
}

async function buscarDisciplinasDoAlunoAsync(alunoId) {
    const disciplinaIds = matriculasPorAluno
        .filter(m => m.alunoId === alunoId)
        .map(m => m.disciplinaId);

    const disciplinas = DisciplinaModel.listarTodos();
    return disciplinas.filter(d => disciplinaIds.includes(d.id));
}

async function buscarDadosCompletos(alunoId) {
    // Promise.all(): aguarda TODAS as Promises. Se uma falhar, rejeita tudo
    // Ideal quando todas as operações são necessárias e independentes
    const [aluno, disciplinas] = await Promise.all([
        buscarAlunoAsync(alunoId),
        buscarDisciplinasDoAlunoAsync(alunoId),
    ]);

    return { aluno, disciplinas };
}

module.exports = {listarTodos, buscarPorId, criar, atualizar, atualizarParcial, remover, buscarDadosCompletos };