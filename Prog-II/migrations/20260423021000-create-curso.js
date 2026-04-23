'use strict';

/** @type {import('sequelize-cli').Migration} */
module.exports = {
  async up (queryInterface, Sequelize) {
    await queryInterface.createTable('curso', {
      id: { type: Sequelize.INTEGER, primaryKey: true, allowNull: false },
      descricao: { type: Sequelize.TEXT, allowNull: true },
    });
  },

  async down (queryInterface, Sequelize) {
    await queryInterface.dropTable('curso');
  }
};
