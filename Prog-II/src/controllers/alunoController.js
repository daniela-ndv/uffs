// O Controller só sabe: receber req, chamar o Model, enviar res.
// Não contém lógica de negócio nem queries SQL.

const AlunoModel = require('../models/alunoModel');

function listar(req, res) {
    const alunos = AlunoModel.listarTodos(req.query);
    res.status(200).json({ total: alunos.length, alunos });
}

function buscar(req, res) {
    const id = parseInt(req.params.id);
    if (isNaN(id)) return res.status(400).json({ erro: 'ID inválido' });
    const aluno = AlunoModel.buscarPorId(id);
    if (!aluno) return res.status(404).json({ erro: 'Aluno não encontrado' });
    res.status(200).json(aluno);
}

function criar(req, res) {
    try {
        const novoAluno = AlunoModel.criar(req.body);
        res.status(201).set('Location', '/api/alunos/' + novoAluno.id).json(novoAluno);
    } catch (err) {
        res.status(400).json({ erro: err.message });
    }
}

function atualizar(req, res) {
    const id = parseInt(req.params.id);
    const aluno = AlunoModel.atualizar(id, req.body);
    if (!aluno) return res.status(404).json({ erro: 'Aluno não encontrado' });
    res.status(200).json(aluno);
}

function atualizarParcial(req, res) {
    const id = parseInt(req.params.id);
    const aluno = AlunoModel.atualizarParcial(id, req.body);
    if (!aluno) return res.status(404).json({ erro: 'Aluno não encontrado' });
    res.status(200).json(aluno);
}

function remover(req, res) {
    const id = parseInt(req.params.id);
    const ok = AlunoModel.remover(id);
    if (!ok) return res.status(404).json({ erro: 'Aluno não encontrado' });
    res.status(204).send();
}

module.exports = { listar, buscar, criar, atualizar, atualizarParcial, remover };