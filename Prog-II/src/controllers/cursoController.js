// O Controller só sabe: receber req, chamar o Model, enviar res.
// Não contém lógica de negócio nem queries SQL.

const db = require('../models');
const { Op } = require('sequelize');
const RESP_HTTP = require('../../consts');
const helper = require('./helpers');

async function listar(req, res) {
    try{
        const { descricao, completo, pagina = 1, porPagina = 20 } = req.query;
        const where = {};
        if (descricao) where.descricao = { [Op.iLike]: '%' + descricao + '%' };

        const include = [];
        if (completo === 'true') {
            include.push({ model: db.Aluno });
            include.push({ model: db.Matricula });
        }

        const { count, rows } = await db.Curso.findAndCountAll({
            where,
            include,
            limit: Number.parseInt(porPagina, 10),
            offset: (Number.parseInt(pagina, 10) - 1) * Number.parseInt(porPagina, 10),
            order: [['id', 'ASC']],
            distinct: true,
        });
        res.status(RESP_HTTP.OK).json({ total: count, pagina: Number.parseInt(pagina, 10), cursos: rows });
    } catch (err) {
        throw err;
    }
}

async function buscar(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const curso = await db.Curso.findByPk(id);
        if (!curso) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Curso não encontrado' });
        res.status(RESP_HTTP.OK).json(curso);
    } catch (err) {
        throw err;
    }
}

async function buscarCompleto(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const curso = await db.Curso.findByPk(id, {
            include: [
                { model: db.Aluno },
                { model: db.Matricula },
            ],
        });
        if (!curso) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Curso não encontrado' });
        res.status(RESP_HTTP.OK).json(curso);
    } catch (err) {
        throw err;
    }
}

async function criar(req, res) {
    try {
        const curso = await db.Curso.create(req.body);
        res.status(RESP_HTTP.CREATED).json(curso);
    } catch (err) {
        throw err; // erro inesperado asyncHandler captura e retorna 500
    }
}


async function atualizar(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const curso = await db.Curso.findByPk(id);
        if (!curso) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Curso não encontrado' });

        const { id: novoId, descricao } = req.body;
        if (novoId !== undefined) curso.id = novoId;
        if (descricao !== undefined) curso.descricao = descricao;

        await curso.save();
        res.status(RESP_HTTP.OK).json(curso);
    } catch (err) {
        throw err;
    }
}

async function atualizarParcial(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const curso = await db.Curso.findByPk(id);
        if (!curso) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Curso não encontrado' });

        await curso.update(req.body);
        res.status(RESP_HTTP.OK).json(curso);
    } catch (err) {
        throw err;
    }
}

async function remover(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const qtd = await db.Curso.destroy({ where: { id } });
        if (qtd === 0) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Curso não encontrado' });
        res.status(RESP_HTTP.NO_CONTENT).send();
    } catch (err) {
        throw err;
    }
}

module.exports = { listar, buscar, buscarCompleto, criar, atualizar, atualizarParcial, remover };
