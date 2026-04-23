'use strict';

/** @type {import('sequelize-cli').Migration} */
module.exports = {
  async up (queryInterface, Sequelize) {
    await queryInterface.createTable('matricula', {
      id: { type: Sequelize.INTEGER, primaryKey: true, autoIncrement: true },
      id_aluno: {
        type: Sequelize.INTEGER,
        allowNull: false,
        references: { model: 'aluno', key: 'id' },
        onUpdate: 'CASCADE',
        onDelete: 'CASCADE'
      },
      id_curso: {
        type: Sequelize.INTEGER,
        allowNull: false,
        references: { model: 'curso', key: 'id' },
        onUpdate: 'CASCADE',
        onDelete: 'RESTRICT'
      },
      semestre: { type: Sequelize.STRING(6), allowNull: false },
      nota: { type: Sequelize.FLOAT, allowNull: true },
      situacao: {
        type: Sequelize.ENUM('CURSANDO', 'APROVADO', 'REPROVADO', 'TRANCADO'),
        allowNull: false,
        defaultValue: 'CURSANDO'
      },
    });
  },

  async down (queryInterface, Sequelize) {
    await queryInterface.dropTable('matricula');
    await queryInterface.sequelize.query('DROP TYPE IF EXISTS "enum_matricula_situacao";');
  }
};
