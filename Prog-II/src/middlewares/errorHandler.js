// handler global de erros
function errorHandler(err, req, res, next) {
    console.error(err.stack);
    res.status(err.statusCode || 500).json({ erro: err.message || 'Erro interno' });
}

module.exports = { errorHandler };