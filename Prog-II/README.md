# API REST + Frontend React

Projeto fullstack desenvolvido com Node.js, Express, Sequelize (backend) e React + Vite (frontend), organizado no padrão MVC.

## Conteúdos trabalhados

- API REST
- Node.js + Express
- Padrão MVC
- Princípio DRY
- Promises e `Promise.all`
- Tratamento global de erros
- ORM (Object-Relational Mapper) — Sequelize
- pg-promise
- React (componentes funcionais, JSX, props, estado elevado)
- Hooks: `useState`, `useEffect`, `useCallback`
- Vite (bundler + servidor de desenvolvimento)

## Estrutura do projeto

```
/                  ← backend (Node.js + Express)
  src/
    controllers/
    middlewares/
    models/
    routes/
  config/
  migrations/
  index.js
frontend/          ← frontend (React + Vite)
  src/
    App.jsx
    components/
      CursoForm.jsx    ← formulário controlado de cadastro
      CursoLista.jsx   ← tabela com lista de cursos
  vite.config.js       ← proxy /api → localhost:3000
```

## Como executar

### Backend

1. Instalar dependências:

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

### Frontend

```bash
cd frontend
npm install   # apenas na primeira vez
npm run dev
```

Frontend disponível em `http://localhost:5173`

> O Vite redireciona automaticamente `/api/*` para o backend em `localhost:3000`.

## Scripts disponíveis

### Backend (`/`)

- `npm start` — inicia com Node.
- `npm run dev` — inicia com Nodemon.

### Frontend (`/frontend`)

- `npm run dev` — servidor de desenvolvimento com HMR.
- `npm run build` — build de produção.
- `npm run preview` — pré-visualiza o build de produção.

## Banco de dados (Sequelize + PostgreSQL)

- Gerar migration para aluno:

```bash
npx sequelize-cli migration:generate --name create-aluno
```

- Gerar migration para curso:

```bash
npx sequelize-cli migration:generate --name create-curso
```

- Gerar migration para matrícula:

```bash
npx sequelize-cli migration:generate --name create-matricula
```

- Rodar migrations:

```bash
npx sequelize-cli db:migrate
```

- Verificar status das migrations:

```bash
npx sequelize-cli db:migrate:status
```

## PostgreSQL

```bash
# Acessar com usuário postgres do sistema
sudo -u postgres psql -d prog2
```

## Base URL

`/api`

## Endpoints de alunos

Base: `/api/alunos`

- `GET /` — lista alunos (aceita filtro por query `curso`).
- `GET /:id` — busca aluno por id.
- `GET /:id/completo` — retorna aluno + disciplinas relacionadas.
- `POST /` — cria aluno.
- `PUT /:id` — atualiza aluno completo.
- `PATCH /:id` — atualiza aluno parcial.
- `DELETE /:id` — remove aluno.

## Endpoints de cursos

Base: `/api/cursos`

- `GET /` — lista cursos (aceita filtro por query `descricao`).
- `GET /:id` — busca curso por id.
- `GET /:id/completo` — retorna curso + alunos e matrículas.
- `POST /` — cria curso.
- `PUT /:id` — atualiza curso completo.
- `PATCH /:id` — atualiza curso parcial.
- `DELETE /:id` — remove curso.

## Endpoints de disciplinas

Base: `/api/disciplinas`

- `GET /` — lista disciplinas (aceita filtros por query `nome` e `cargaHoraria`).
- `GET /:id` — busca disciplina por id.
- `POST /` — cria disciplina.
- `PUT /:id` — atualiza disciplina.
- `DELETE /:id` — remove disciplina.

## Endpoints de matrículas

Base: `/api/matriculas`

- `GET /` — lista matrículas.
- `GET /:id` — busca matrícula por id.
- `POST /` — cria matrícula.
- `PUT /:id` — atualiza matrícula completa.
- `PATCH /:id` — atualiza matrícula parcial.
- `DELETE /:id` — remove matrícula.

## Respostas e erros

- Constantes de status HTTP centralizadas em `consts.js`.
- Todas as rotas usam `asyncHandler` para encaminhar erros assíncronos.
- Handler global de erros em `src/middlewares/errorHandler.js` retorna:

```json
{
  "erro": "mensagem do erro"
}
```

Com status `err.statusCode` ou `500`.

## Collection Bruno API

Existe uma coleção pronta em `collecion-brunoApi/` para testar os endpoints.
