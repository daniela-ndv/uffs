// O Controller só sabe: receber req, chamar o Model, enviar res.
// Não contém lógica de negócio nem queries SQL.

const db = require('../models');
const { Op } = require('sequelize');
const RESP_HTTP = require('../../consts');
const helper = require('./helpers');

async function listar(req, res) {
    try{
        const { nome, pagina = 1, porPagina = 20 } = req.query;
        const where = {};
        if (nome) where.nome = { [Op.iLike]: '%' + nome + '%' };

        const { count, rows } = await db.Aluno.findAndCountAll({
            where,
            include: [{ model: db.Curso}],
            limit: parseInt(porPagina),
            offset: (parseInt(pagina) - 1) * parseInt(porPagina),
            order: [['nome', 'ASC']],
        });
        res.status(RESP_HTTP.OK).json({ total: count, pagina: parseInt(pagina), alunos: rows });
    } catch (err) {
        throw err;
    }
}

async function buscar(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const aluno = await db.Aluno.findByPk(id);
        if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
        res.status(RESP_HTTP.OK).json(aluno);
    } catch (err) {
        throw err;
    }
}

async function buscarCompleto(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const aluno = await db.Aluno.findByPk(id, {
            include: [
                { model: db.Curso },
                { model: db.Matricula },
            ],
        });
        if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
        res.status(RESP_HTTP.OK).json(aluno);
    } catch (err) {
        throw err;
    }
}

async function criar(req, res) {
    try {
        const aluno = await db.Aluno.create(req.body);
        res.status(RESP_HTTP.CREATED).json(aluno);
    } catch (err) {
        throw err; // erro inesperado asyncHandler captura e retorna 500
    }
}


async function atualizar(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const aluno = await db.Aluno.findByPk(id);
        if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });

        const { nome, matricula, id_curso, ativo } = req.body;
        if (nome      !== undefined) aluno.nome      = nome;
        if (matricula !== undefined) aluno.matricula = matricula;
        if (id_curso  !== undefined) aluno.id_curso  = id_curso;
        if (ativo     !== undefined) aluno.ativo     = ativo;

        await aluno.save();
        res.status(RESP_HTTP.OK).json(aluno);
    } catch (err) {
        throw err;
    }
}

async function atualizarParcial(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const aluno = await db.Aluno.findByPk(id);
        if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });

        await aluno.update(req.body);
        res.status(RESP_HTTP.OK).json(aluno);
    } catch (err) {
        throw err;
    }
}

async function remover(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const qtd = await db.Aluno.destroy({ where: { id } });
        if (qtd === 0) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
        res.status(RESP_HTTP.NO_CONTENT).send();
    } catch (err) {
        throw err;
    }
}

module.exports = { listar, buscar, buscarCompleto, criar, atualizar, atualizarParcial, remover };
