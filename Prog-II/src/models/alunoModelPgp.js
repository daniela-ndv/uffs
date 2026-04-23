// Exemplo utilizando pg-promise

const db = require('../../config/pgpConnection');

async function listarTodos({ nome, pagina = 1, porPagina = 20 } = {}) {
    // Named parameters (${variavel}) ajudam legibilidade quando ha varios filtros.
    const conditions = [];
    const params = {};

    if (nome) {
        conditions.push('nome ILIKE ${nomeLike}');
        params.nomeLike = `%${nome}%`;
    }

    const where = conditions.length ? `WHERE ${conditions.join(' AND ')}` : '';

    params.limit = Number.parseInt(porPagina, 10);
    params.offset = (Number.parseInt(pagina, 10) - 1) * params.limit;

    const alunos = await db.any(
        `SELECT *
         FROM aluno
         ${where}
         ORDER BY nome ASC
         LIMIT ${'${limit}'} OFFSET ${'${offset}'}`,
        params,
    );

    const { total } = await db.one(
        `SELECT COUNT(*)::int AS total
         FROM aluno
         ${where}`,
        params,
    );

    return { total, alunos };
}

async function buscarPorId(id) {
    return db.oneOrNone('SELECT * FROM aluno WHERE id = $1', [id]);
}

async function criar(dados) {
    // RETURNING * devolve a linha inserida com o id gerado pelo banco.
    return db.one(
        `INSERT INTO aluno (nome, matricula, id_curso)
         VALUES (${ '${nome}' }, ${ '${matricula}' }, ${ '${id_curso}' })
         RETURNING *`,
        dados,
    );
}

module.exports = { listarTodos, buscarPorId, criar };
