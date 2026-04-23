'use strict';

/** @type {import('sequelize-cli').Migration} */
module.exports = {
  async up (queryInterface, Sequelize) {
    await queryInterface.createTable('aluno', {
      id:         { type: Sequelize.INTEGER, primaryKey: true, autoIncrement: true },
      nome:       { type: Sequelize.STRING(100), allowNull: false },
      matricula:  { type: Sequelize.STRING(7), allowNull: false, unique: true },
      id_curso:   { type: Sequelize.INTEGER, allowNull: false },
      ativo:      { type: Sequelize.BOOLEAN, defaultValue: true },
    });
  },

  async down (queryInterface, Sequelize) {
    await queryInterface.dropTable('aluno');
  }
};
