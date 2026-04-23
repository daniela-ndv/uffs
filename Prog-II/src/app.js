const express = require('express');
const alunoRoutes = require('./routes/alunoRoutes');
const disciplinaRoutes = require('./routes/disciplinaRoutes');

const app = express();
app.use(express.json());

// Monta o router no caminho base
app.use('/api/alunos', alunoRoutes);
app.use('/api/disciplinas', disciplinaRoutes);

// handler global de erros
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(err.statusCode || 500).json({ erro: err.message || 'Erro interno' });
});

module.exports = app;