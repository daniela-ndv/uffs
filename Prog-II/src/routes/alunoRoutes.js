// A rota só conecta URL a Controller

const express = require('express');
const router = express.Router();
const AlunoController = require('../controllers/alunoController');

router.get('/', AlunoController.listar);
router.get('/:id', AlunoController.buscar);
router.post('/', AlunoController.criar);
router.put('/:id', AlunoController.atualizar);
router.patch('/:id', AlunoController.atualizarParcial);
router.delete('/:id', AlunoController.remover);

module.exports = router;
