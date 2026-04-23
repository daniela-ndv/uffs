// carrega automaticamente todos os models da pasta e executa suas associações
// Esse é DRY em nível de infraestrutura: adicionar um novo model ao projeto não exige nenhuma alteração no index.js.

'use strict';

const fs = require('fs');
const path = require('path');
const Sequelize = require('sequelize');
const sequelize = require('../../config/localConnection');

const basename = path.basename(__filename); // 'index.js'
const db = {};

// 1. Lê todos os arquivos .js da pasta models/
// exceto o próprio index.js e arquivos ocultos
fs.readdirSync(__dirname)
  .filter(file =>
    file.indexOf('.') !== 0 && // ignora arquivos ocultos (.gitkeep, etc.)
    file !== basename && // ignora o próprio index.js
    file.slice(-3) === '.js' // só arquivos .js
  )
  .forEach(file => {
    const factory = require(path.join(__dirname, file));

    // Ignora arquivos de model legados que não usam assinatura (sequelize, DataTypes).
    if (typeof factory !== 'function') return;

    const model = factory(sequelize, Sequelize.DataTypes);
    db[model.name] = model;
  });

// 3. Depois que TODOS os models foram carregados, executa as associações.
// Isso garante que nenhum model depende da ordem de carregamento dos arquivos.
Object.keys(db).forEach(modelName => {
  if (db[modelName].associate) {
    db[modelName].associate(db);
  }
}); 

// 4. Expõe a instância e a classe Sequelize para uso externo
db.sequelize = sequelize;
db.Sequelize = Sequelize;

module.exports = db;