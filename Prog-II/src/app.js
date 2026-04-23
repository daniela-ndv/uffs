const express = require('express');
const alunoRoutes = require('./routes/alunoRoutes');
const disciplinaRoutes = require('./routes/disciplinaRoutes');
const { errorHandler } = require('./middlewares/errorHandler.js');

const app = express();
app.use(express.json());

// Monta o router no caminho base
app.use('/api/alunos', alunoRoutes);
app.use('/api/disciplinas', disciplinaRoutes);

app.use(errorHandler);

module.exports = app;