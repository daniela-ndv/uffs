const express = require('express');
const alunoRoutes = require('./routes/alunoRoutes');
const disciplinaRoutes = require('./routes/disciplinaRoutes');

const app = express();
app.use(express.json());

// Monta o router no caminho base
app.use('/api/alunos', alunoRoutes);
app.use('/api/disciplinas', disciplinaRoutes);

module.exports = app;