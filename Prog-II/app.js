const express = require('express');
const alunosRouter = require('./routes/alunos');
const disciplinasRouter = require('./routes/disciplinas');

const app = express();
app.use(express.json());

// Monta o router no caminho base
app.use('/api/alunos', alunosRouter);
app.use('/api/disciplinas', disciplinasRouter);

module.exports = app;