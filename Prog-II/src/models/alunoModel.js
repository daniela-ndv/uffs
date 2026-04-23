// O Model encapsula TODA a lógica de dados.
// O Controller nunca acessa o banco diretamente.

// estilo funcional com validações e associações.

module.exports = (sequelize, DataTypes) => {
    const Aluno = sequelize.define(
        'Aluno',
        {
            id: { type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true },
            nome: {
                type: DataTypes.STRING(100),
                allowNull: false,
                validate: {
                    notEmpty: { msg: 'O nome não pode ser vazio' },
                    len: { args: [2, 100], msg: 'Nome deve ter entre 2 e 100 caracteres' },
                },
            },
            matricula: {
                type: DataTypes.STRING(7),
                allowNull: false,
                unique: { msg: 'Esta matrícula já está cadastrada' },
                validate: {
                    is: { args: /^\d{7}$/, msg: 'Matrícula deve ter exatamente 7 dígitos' },
                },
            },
            id_curso: { type: DataTypes.INTEGER, allowNull: false },
            ativo: { type: DataTypes.BOOLEAN, defaultValue: true },
        },
        {
            tableName: 'aluno',
            schema: 'public',
            freezeTableName: true,
            timestamps: false,
        },
    );

    Aluno.associate = function (models) {
        Aluno.belongsTo(models.Curso, { foreignKey: 'id_curso', targetKey: 'id' });
        Aluno.hasMany(models.Matricula, { foreignKey: 'id_aluno', sourceKey: 'id' });
    };

    return Aluno;
};
