# API REST 

Projeto de API REST desenvolvido com Node.js e Express, organizado em padrao MVC.

## Conteudos trabalhados

- API REST
- Node.js + Express
- Padrao MVC
- Principio DRY
- Promises e `Promise.all`
- Tratamento global de erros


## Como executar

1. Instalar as dependencias:

```bash
npm install
```

2. Rodar em modo desenvolvimento:

```bash
npm run dev
```

3. Ou rodar em modo normal:

```bash
npm start
```

Servidor padrão: `http://localhost:3000`

## Scripts disponiveis

- `npm start`: inicia com Node.
- `npm run dev`: inicia com Nodemon.


## Base URL

`/api`

## Endpoints de alunos

Base: `/api/alunos`

- `GET /` lista alunos (aceita filtro por query `curso`).
- `GET /:id` busca aluno por id.
- `GET /:id/completo` retorna aluno + disciplinas relacionadas.
- `POST /` cria aluno.
- `PUT /:id` atualiza aluno completo.
- `PATCH /:id` atualiza aluno parcial.
- `DELETE /:id` remove aluno.


## Endpoints de disciplinas

Base: `/api/disciplinas`

- `GET /` lista disciplinas (aceita filtros por query `nome` e `cargaHoraria`).
- `GET /:id` busca disciplina por id.
- `POST /` cria disciplina.
- `PUT /:id` atualiza disciplina.
- `DELETE /:id` remove disciplina.


## Respostas e erros

- Constantes de status HTTP centralizadas em `consts.js`.
- Rotas de alunos usam `asyncHandler` para encaminhar erros assincornos.
- Handler global de erros em `src/app.js` retorna:

```json
{
	"erro": "mensagem do erro"
}
```

Com status `err.statusCode` ou `500`.

## Collection Bruno API

Existe uma colecao pronta em `collecion-brunoApi/` para testar os endpoints.
