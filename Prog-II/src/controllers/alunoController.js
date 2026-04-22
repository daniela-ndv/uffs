// O Controller só sabe: receber req, chamar o Model, enviar res.
// Não contém lógica de negócio nem queries SQL.

const AlunoModel = require('../models/alunoModel');
const RESP_HTTP = require('../../consts');
const helper = require('./helpers');

function listar(req, res) {
    const alunos = AlunoModel.listarTodos(req.query);
    res.status(RESP_HTTP.OK).json({ total: alunos.length, alunos });
}

function buscar(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const aluno = AlunoModel.buscarPorId(id);
    if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.OK).json(aluno);
}

async function buscarCompleto(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;

    try {
        const dados = await AlunoModel.buscarDadosCompletos(id);
        res.status(RESP_HTTP.OK).json(dados);
    } catch (err) {
        if (err.message === 'Aluno não encontrado') {
            return res.status(RESP_HTTP.NOT_FOUND).json({ erro: err.message });
        }
        res.status(RESP_HTTP.INTERNAL_SERVER_ERROR).json({ erro: 'Erro interno ao buscar dados completos' });
    }
}

function criar(req, res) {
    try {
        const novoAluno = AlunoModel.criar(req.body);
        res.status(RESP_HTTP.CREATED).set('Location', '/api/alunos/' + novoAluno.id).json(novoAluno);
    } catch (err) {
        res.status(RESP_HTTP.BAD_REQUEST).json({ erro: err.message });
    }
}

function atualizar(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const aluno = AlunoModel.atualizar(id, req.body);
    if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.OK).json(aluno);
}

function atualizarParcial(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const aluno = AlunoModel.atualizarParcial(id, req.body);
    if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.OK).json(aluno);
}

function remover(req, res) {
    const id = helper.obterId(req, res);
    if (id === null) return;
    const ok = AlunoModel.remover(id);
    if (!ok) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.NO_CONTENT).send();
}

module.exports = { listar, buscar, buscarCompleto, criar, atualizar, atualizarParcial, remover };