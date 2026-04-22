// O Controller só sabe: receber req, chamar o Model, enviar res.
// Não contém lógica de negócio nem queries SQL.

const DisciplinaModel = require('../models/disciplinaModel');
const RESP_HTTP = require('../../consts');
const helper = require('./helpers');

function listar(req, res){
    const disciplinas = DisciplinaModel.listarTodos(req.query);
    res.status(RESP_HTTP.OK).json({ total: disciplinas.length, disciplinas});
}

function buscar(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const disciplina = DisciplinaModel.buscarPorId(id);
    if (!disciplina) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Disciplina não encontrada' });
    res.status(RESP_HTTP.OK).json(disciplina);
}

function criar(req, res) {
    try {
        const novaDisciplina = DisciplinaModel.criar(req.body);
        res.status(RESP_HTTP.CREATED).set('Location', '/api/disciplinas/' + novaDisciplina.id).json(novaDisciplina);
    } catch (err) {
        res.status(RESP_HTTP.BAD_REQUEST).json({ erro: err.message });
    }
}

function atualizar(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const disciplina = DisciplinaModel.atualizar(id, req.body);
    if (!disciplina) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Disciplina não encontrada' });
    res.status(RESP_HTTP.OK).json(disciplina);
}

function remover(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const ok = DisciplinaModel.remover(id);
    if (!ok) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Disciplina não encontrada' });
    res.status(RESP_HTTP.NO_CONTENT).send();
}

module.exports = { listar, buscar, criar, atualizar, remover };