// A rota só conecta URL a Controller

const express = require('express');
const router = express.Router();
const DisciplinaController = require('../controllers/disciplinaController');
const { asyncHandler } = require('../middlewares/asyncHandler');

router.get('/', asyncHandler(DisciplinaController.listar));
router.get('/:id', asyncHandler(DisciplinaController.buscar));
router.post('/', asyncHandler(DisciplinaController.criar));
router.put('/:id', asyncHandler(DisciplinaController.atualizar));
router.delete('/:id', asyncHandler(DisciplinaController.remover));

module.exports = router;
