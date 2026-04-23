const RESP_HTTP = require('../../consts');

function obterId(req, res) {
    const id = Number.parseInt(req.params.id, 10);
    if (Number.isNaN(id)) {
        res.status(RESP_HTTP.BAD_REQUEST).json({ erro: 'ID inválido' });
        return null;
    }
    return id;
}

// Wrapper para rotas async: 
// captura erros de Promise e encaminha para o middleware global de erros (next).
//
// Passos da função:
// 1. Executa o handler da rota
// 2. Garante que o resultado vire uma Promise
// 3.Captura erro e envia para o middleware de erro do Express, .catch(next) pega qualquer rejeição/erro assíncrono e chama next(err).
// No Express, chamar next com erro encaminha para o handler global de erros.
function asyncHandler(fn) {
    return (req, res, next) => {
        Promise.resolve(fn(req, res, next)).catch(next);
    };
}

module.exports = { obterId, asyncHandler };