const express = require('express');
const router = express.Router();

// Banco de dados em memória para disciplinas (substituir por DB real depois)
let disciplinas = [
    { id: 1, nome: "Programacao Web", codigo: "SI101", cargaHoraria: 60 },
    { id: 2, nome: "Estruturas de Dados", codigo: "CC102", cargaHoraria: 80 },
    { id: 3, nome: "Banco de Dados", codigo: "CC103", cargaHoraria: 64 },
];
let proximoId = 4;

// GET /disciplinas lista todas (filtro opcional por codigo)
router.get('/', (req, res) => {
    const { codigo } = req.query;
    const resultado = codigo
        ? disciplinas.filter(d => d.codigo.toLowerCase() === codigo.toLowerCase())
        : disciplinas;
    res.status(200).json({ total: resultado.length, disciplinas: resultado });
});

// GET /disciplinas/:id
router.get('/:id', (req, res) => {
    const id = parseInt(req.params.id);
    if (isNaN(id)) {
        return res.status(400).json({ erro: "ID deve ser um número inteiro" });
    }
    const disciplina = disciplinas.find(d => d.id === id);
    if (!disciplina) {
        return res.status(404).json({ erro: "Disciplina com id " + id + " não encontrada" });
    }
    res.status(200).json(disciplina);
});

// POST /disciplinas cria
router.post('/', (req, res) => {
    const { nome, codigo, cargaHoraria } = req.body;
    if (!nome || !codigo || cargaHoraria == null) {
        return res.status(400).json({
            erro: "Dados inválidos",
            detalhes: [
                !nome && { campo: "nome", mensagem: "Obrigatório" },
                !codigo && { campo: "codigo", mensagem: "Obrigatório" },
                cargaHoraria == null && { campo: "cargaHoraria", mensagem: "Obrigatório" },
            ].filter(Boolean)
        });
    }
    const existe = disciplinas.find(d => d.codigo === codigo);
    if (existe) {
        return res.status(409).json({ erro: "Código " + codigo + " já cadastrado" });
    }
    const novaDisciplina = { id: proximoId++, nome, codigo, cargaHoraria };
    disciplinas.push(novaDisciplina);
    res.status(201)
        .set('Location', '/api/disciplinas/' + novaDisciplina.id)
        .json(novaDisciplina);
});

// PUT /disciplinas/:id substitui completo
router.put('/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const { nome, codigo, cargaHoraria } = req.body;
    if (!nome || !codigo || cargaHoraria == null) {
        return res.status(400).json({
            erro: "PUT requer todos os campos: nome, codigo, cargaHoraria"
        });
    }
    const indice = disciplinas.findIndex(d => d.id === id);
    if (indice === -1) {
        return res.status(404).json({ erro: "Disciplina não encontrada" });
    }
    disciplinas[indice] = { id, nome, codigo, cargaHoraria };
    res.status(200).json(disciplinas[indice]);
});

// PATCH /disciplinas/:id atualização parcial
router.patch('/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const indice = disciplinas.findIndex(d => d.id === id);
    if (indice === -1) {
        return res.status(404).json({ erro: "Disciplina não encontrada" });
    }
    disciplinas[indice] = { ...disciplinas[indice], ...req.body, id };
    res.status(200).json(disciplinas[indice]);
});

// DELETE /disciplinas/:id
router.delete('/:id', (req, res) => {
    const id = parseInt(req.params.id);
    const indice = disciplinas.findIndex(d => d.id === id);
    if (indice === -1) {
        return res.status(404).json({ erro: "Disciplina não encontrada" });
    }
    disciplinas.splice(indice, 1);
    res.status(204).send();
});

module.exports = router;
