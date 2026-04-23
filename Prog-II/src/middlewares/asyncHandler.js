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

module.exports = { asyncHandler };