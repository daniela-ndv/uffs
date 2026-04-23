// Usado para exemplo models/alunoModelPgp

require('dotenv').config();

const pgp = require('pg-promise')();

const env = process.env.NODE_ENV || 'development';

const connectionByEnv = {
	development: process.env.DATABASE_URL_DEV,
	test: process.env.DATABASE_URL_TEST,
	production: process.env.DATABASE_URL,
};

const connectionString = connectionByEnv[env];

const connectionConfig = connectionString
	? connectionString
	: {
		  host: process.env.DB_HOST || '127.0.0.1',
		  port: Number.parseInt(process.env.DB_PORT || '5432', 10),
		  database: process.env.DB_NAME || 'prog2_dev',
		  user: process.env.DB_USER || 'postgres',
		  password: process.env.DB_PASSWORD || '',
		  max: Number.parseInt(process.env.DB_POOL_MAX || '10', 10),
	  };

const db = pgp(connectionConfig);

module.exports = db;
