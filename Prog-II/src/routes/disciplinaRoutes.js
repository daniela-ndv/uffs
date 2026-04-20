// A rota só conecta URL a Controller

const express = require('express');
const router = express.Router();
const DisciplinaController = require('../controllers/disciplinaCotroller');

router.get('/', DisciplinaController.listar);
router.get('/:id', DisciplinaController.buscar);
router.post('/', DisciplinaController.criar);
router.put('/:id', DisciplinaController.atualizar);
router.delete('/:id', DisciplinaController.remover);

module.exports = router;
