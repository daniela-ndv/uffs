const express = require('express');
const router = express.Router();
const MatriculaController = require('../controllers/matriculaController');
const { asyncHandler } = require('../middlewares/asyncHandler');

router.get('/', asyncHandler(MatriculaController.listar));
router.get('/:id', asyncHandler(MatriculaController.buscar));
router.post('/', asyncHandler(MatriculaController.criar));
router.put('/:id', asyncHandler(MatriculaController.atualizar));
router.patch('/:id', asyncHandler(MatriculaController.atualizarParcial));
router.delete('/:id', asyncHandler(MatriculaController.remover));

module.exports = router;