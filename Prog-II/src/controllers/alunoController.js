// O Controller só sabe: receber req, chamar o Model, enviar res.
// Não contém lógica de negócio nem queries SQL.

const AlunoModel = require('../models/alunoModel');
const RESP_HTTP = require('../../consts');

function listar(req, res) {
    const alunos = AlunoModel.listarTodos(req.query);
    res.status(RESP_HTTP.OK).json({ total: alunos.length, alunos });
}

function buscar(req, res) {
    const id = parseInt(req.params.id);
    if (isNaN(id)) return res.status(RESP_HTTP.BAD_REQUEST).json({ erro: 'ID inválido' });
    const aluno = AlunoModel.buscarPorId(id);
    if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.OK).json(aluno);
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
    const id = parseInt(req.params.id);
    const aluno = AlunoModel.atualizar(id, req.body);
    if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.OK).json(aluno);
}

function atualizarParcial(req, res) {
    const id = parseInt(req.params.id);
    const aluno = AlunoModel.atualizarParcial(id, req.body);
    if (!aluno) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.OK).json(aluno);
}

function remover(req, res) {
    const id = parseInt(req.params.id);
    const ok = AlunoModel.remover(id);
    if (!ok) return res.status(RESP_HTTP.NOT_FOUND).json({ erro: 'Aluno não encontrado' });
    res.status(RESP_HTTP.NO_CONTENT).send();
}

module.exports = { listar, buscar, criar, atualizar, atualizarParcial, remover };