// O Model encapsula TODA a lógica de dados.
// O Controller nunca acessa o banco diretamente.

let disciplinas = [
    { id: 1, nome: 'Algortimos avançados', codigo: 'CC104', cargaHoraria: 75 },
    { id: 2, nome: 'Programação II', codigo: 'CC111', cargaHoraria: 60 },
];
let proximoId = 3;

function normalizarCodigo(codigo) {
    return typeof codigo === 'string' ? codigo.toUpperCase() : codigo;
}

function normalizarNome(nome) {
    return typeof nome === 'string' ? nome.trim().toLowerCase() : nome;
}

function validarCamposObrigatoriosDisciplina(dados) {
    if (!dados.nome || !dados.codigo || !dados.cargaHoraria) {
        throw new Error('Campos obrigatórios ausentes');
    }
}

// Em atualização, ignora o próprio id para não gerar falso duplicado
function validarCodigoUnico(codigo, idIgnorado = null) {
    const codigoNormalizado = normalizarCodigo(codigo);
    const existe = disciplinas.find(a => a.codigo === codigoNormalizado && a.id !== idIgnorado);
    if (existe) throw new Error('Código já cadastrado');
}

function validarDisciplina(dados, idIgnorado = null) {
    validarCamposObrigatoriosDisciplina(dados);
    validarCodigoUnico(dados.codigo, idIgnorado);
}

function listarTodos(filtros = {}) {
    let resultado = [...disciplinas];

    if (filtros.cargaHoraria !== undefined) {
        const cargaHoraria = Number.parseInt(filtros.cargaHoraria, 10);
        if (!Number.isNaN(cargaHoraria)) {
            resultado = resultado.filter(a => a.cargaHoraria === cargaHoraria);
        }
    }

    if (filtros.nome) {
        const nome = normalizarNome(filtros.nome);
        resultado = resultado.filter(a => normalizarNome(a.nome) === nome);
    }

    return resultado;
}

function buscarPorId(id) {
    return disciplinas.find(a => a.id === id) || null;
}

function criar(dados) {
    const novaDisciplina = { id: proximoId++, ...dados };
    validarDisciplina(novaDisciplina);
    disciplinas.push(novaDisciplina);
    return novaDisciplina;
}

function atualizar(id, dados) {
    const idx = disciplinas.findIndex(a => a.id === id);
    if (idx === -1) return null;

    const disciplinaAtualizada = { ...disciplinas[idx], ...dados, id };
    validarDisciplina(disciplinaAtualizada, id);

    disciplinas[idx] = disciplinaAtualizada;
    return disciplinas[idx];
}

function remover(id) {
    const idx = disciplinas.findIndex(a => a.id === id);
    if (idx === -1) return false;
    disciplinas.splice(idx, 1);
    return true;
}

module.exports = { listarTodos, buscarPorId, criar, atualizar, remover };
