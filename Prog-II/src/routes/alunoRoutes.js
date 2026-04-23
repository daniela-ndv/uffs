// A rota só conecta URL a Controller

const express = require('express');
const router = express.Router();
const AlunoController = require('../controllers/alunoController');
const { asyncHandler } = require('../controllers/helpers');

router.get('/', asyncHandler(AlunoController.listar));
router.get('/:id/completo', asyncHandler(AlunoController.buscarCompleto));
router.get('/:id', asyncHandler(AlunoController.buscar));
router.post('/', asyncHandler(AlunoController.criar));
router.put('/:id', asyncHandler(AlunoController.atualizar));
router.patch('/:id', asyncHandler(AlunoController.atualizarParcial));
router.delete('/:id', asyncHandler(AlunoController.remover));

module.exports = router;
