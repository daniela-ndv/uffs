const db = require('../models');
const RESP_HTTP = require('../../consts');
const helper = require('./helpers');

async function listar(req, res) {
    try {
        const { id_aluno, id_curso, semestre, situacao, pagina = 1, porPagina = 20 } = req.query;
        const where = {};

        if (id_aluno !== undefined) where.id_aluno = Number.parseInt(id_aluno, 10);
        if (id_curso !== undefined) where.id_curso = Number.parseInt(id_curso, 10);
        if (semestre) where.semestre = semestre;
        if (situacao) where.situacao = situacao;

        const { count, rows } = await db.Matricula.findAndCountAll({
            where,
            include: [{ model: db.Aluno }, { model: db.Curso }],
            limit: Number.parseInt(porPagina, 10),
            offset: (Number.parseInt(pagina, 10) - 1) * Number.parseInt(porPagina, 10),
            order: [['id', 'ASC']],
            distinct: true,
        });

        res.status(RESP_HTTP.OK).json({
            total: count,
            pagina: Number.parseInt(pagina, 10),
            matriculas: rows,
        });
    } catch (err) {
        throw err;
    }
}

async function buscar(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const matricula = await db.Matricula.findByPk(id, {
            include: [{ model: db.Aluno }, { model: db.Curso }],
        });

        if (!matricula) {
            return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Matrícula não encontrada' });
        }

        res.status(RESP_HTTP.OK).json(matricula);
    } catch (err) {
        throw err;
    }
}

async function criar(req, res) {
    try {
        const matricula = await db.Matricula.create(req.body);
        res.status(RESP_HTTP.CREATED).json(matricula);
    } catch (err) {
        throw err;
    }
}

async function atualizar(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const matricula = await db.Matricula.findByPk(id);
        if (!matricula) {
            return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Matrícula não encontrada' });
        }

        const { id_aluno, id_curso, semestre, nota, situacao } = req.body;
        if (id_aluno !== undefined) matricula.id_aluno = id_aluno;
        if (id_curso !== undefined) matricula.id_curso = id_curso;
        if (semestre !== undefined) matricula.semestre = semestre;
        if (nota !== undefined) matricula.nota = nota;
        if (situacao !== undefined) matricula.situacao = situacao;

        await matricula.save();
        res.status(RESP_HTTP.OK).json(matricula);
    } catch (err) {
        throw err;
    }
}

async function atualizarParcial(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const matricula = await db.Matricula.findByPk(id);
        if (!matricula) {
            return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Matrícula não encontrada' });
        }

        await matricula.update(req.body);
        res.status(RESP_HTTP.OK).json(matricula);
    } catch (err) {
        throw err;
    }
}

async function remover(req, res) {
    try {
        const id = helper.obterId(req, res);
        if (id === null) return;

        const qtd = await db.Matricula.destroy({ where: { id } });
        if (qtd === 0) {
            return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Matrícula não encontrada' });
        }

        res.status(RESP_HTTP.NO_CONTENT).send();
    } catch (err) {
        throw err;
    }
}

module.exports = { listar, buscar, criar, atualizar, atualizarParcial, remover };