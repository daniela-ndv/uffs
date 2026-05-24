// A rota só conecta URL a Controller

const express = require('express');
const router = express.Router();
const CursoController = require('../controllers/cursoController');
const { asyncHandler } = require('../middlewares/asyncHandler');

router.get('/', asyncHandler(CursoController.listar));
router.get('/:id/completo', asyncHandler(CursoController.buscarCompleto));
router.get('/:id', asyncHandler(CursoController.buscar));
router.post('/', asyncHandler(CursoController.criar));
router.put('/:id', asyncHandler(CursoController.atualizar));
router.patch('/:id', asyncHandler(CursoController.atualizarParcial));
router.delete('/:id', asyncHandler(CursoController.remover));

module.exports = router;
