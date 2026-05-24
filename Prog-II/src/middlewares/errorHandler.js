// handler global de erros
function errorHandler(err, req, res, next) {
    console.error(err.stack);

    if (err.name === 'SequelizeUniqueConstraintError') {
        return res.status(409).json({ erro: err.errors?.[0]?.message || err.message });
    }

    if (err.name === 'SequelizeValidationError' || err.name === 'SequelizeForeignKeyConstraintError') {
        const mensagem = err.errors?.map(item => item.message).join('; ');
        return res.status(400).json({ erro: mensagem || err.message });
    }

    res.status(err.statusCode || 500).json({ erro: err.message || 'Erro interno' });
}

module.exports = { errorHandler };