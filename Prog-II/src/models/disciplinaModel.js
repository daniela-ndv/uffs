// O Model encapsula TODA a lógica de dados.
// O Controller nunca acessa o banco diretamente.

let disciplinas = [
    { id: 1, nome: 'Algortimos avançados', codigo: 'CC104', cargaHoraria: 75 },
    { id: 2, nome: 'Programação II', codigo: 'CC111', cargaHoraria: 60 },
];
let proximoId = 3;


function listarTodos(filtros = {}) {
    let resultado = [...disciplinas];
    if (filtros.codigo) {
        resultado = resultado.filter(a => a.codigo === filtros.codigo.toUpperCase());
    }
    return resultado;
}

function buscarPorId(id) {
    return disciplinas.find(a => a.id === id) || null;
}

function criar(dados) {
    if (!dados.nome || !dados.codigo || !dados.cargaHoraria) {
        throw new Error('Campos obrigatórios ausentes');
    }

    const existe = disciplinas.find(a => a.codigo === dados.codigo);
    if (existe) throw new Error('Código já cadastrado');

    const novaDisciplina = { id: proximoId++, ...dados };
    disciplinas.push(novaDisciplina);
    return novaDisciplina;
}

function atualizar(id, dados) {
    const idx = disciplinas.findIndex(a => a.id === id);
    if (idx === -1) return null;
    disciplinas[idx] = { ...disciplinas[idx], ...dados, id };
    return disciplinas[idx];
}

function remover(id) {
    const idx = disciplinas.findIndex(a => a.id === id);
    if (idx === -1) return false;
    disciplinas.splice(idx, 1);
    return true;
}

module.exports = { listarTodos, buscarPorId, criar, atualizar, remover };
