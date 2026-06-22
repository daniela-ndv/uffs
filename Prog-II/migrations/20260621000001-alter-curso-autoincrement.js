'use strict';

/** @type {import('sequelize-cli').Migration} */
module.exports = {
  async up(queryInterface) {
    await queryInterface.sequelize.query(`
      CREATE SEQUENCE IF NOT EXISTS public.curso_id_seq OWNED BY public.curso.id;
      ALTER TABLE public.curso ALTER COLUMN id SET DEFAULT nextval('public.curso_id_seq');
      SELECT setval('public.curso_id_seq', COALESCE((SELECT MAX(id) FROM public.curso), 0) + 1, false);
    `);
  },

  async down(queryInterface) {
    await queryInterface.sequelize.query(`
      ALTER TABLE public.curso ALTER COLUMN id DROP DEFAULT;
      DROP SEQUENCE IF EXISTS public.curso_id_seq;
    `);
  },
};
