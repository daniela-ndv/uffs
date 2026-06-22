module.exports = (sequelize, DataTypes) => {
    // sequelize.define() recebe a instância já configurada
    const Curso = sequelize.define(
        'Curso', // nome do model usado em db.Curso e nos logs do Sequelize
        {
            id: {
                type: DataTypes.INTEGER,
                primaryKey: true,
                autoIncrement: true,
            },
            descricao: DataTypes.TEXT,
        },
        {
            sequelize,
            tableName: 'curso', // nome explícito da tabela no banco
            schema: 'public', // schema do PostgreSQL
            freezeTableName: true, // impede pluralização: Curso cursos (indesejado)
            timestamps: false, // sem colunas createdAt/updatedAt
        },
    );

    // Associações definidas aqui, mas executadas pelo index.js
    // depois que todos os models foram carregados
    Curso.associate = function (models) {
        Curso.hasMany(models.Aluno, { foreignKey: 'id_curso', sourceKey: 'id' });
        Curso.hasMany(models.Matricula, { foreignKey: 'id_curso', sourceKey: 'id' });
    };
    
    return Curso; // OBRIGATÓRIO: o index.js usa o valor retornado
};