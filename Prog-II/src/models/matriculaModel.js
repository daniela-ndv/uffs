//  Associations (Associações) são definidas no método associate de cada model e executadas pelo index.js 
// depois que todos os models foram carregados. Isso garante que nenhum model depende da ordem de carregamento dos arquivos.

"use strict";
module.exports = (sequelize, DataTypes) => {
    const Matricula = sequelize.define('Matricula', {
        id: { type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true },
        id_aluno: { type: DataTypes.INTEGER, allowNull: false },
        id_curso: { type: DataTypes.INTEGER, allowNull: false },
        semestre: { type: DataTypes.STRING(6), allowNull: false },
        nota: { type: DataTypes.FLOAT, allowNull: true },
        situacao: {
            type: DataTypes.ENUM('CURSANDO', 'APROVADO', 'REPROVADO', 'TRANCADO'),
            defaultValue: 'CURSANDO',
        },
    }, {
        tableName: 'matricula', schema: 'public',
        freezeTableName: true, timestamps: false,
    });

    Matricula.associate = function (models) {
        Matricula.belongsTo(models.Aluno, { foreignKey: 'id_aluno', targetKey: 'id' });
        Matricula.belongsTo(models.Curso, { foreignKey: 'id_curso', targetKey: 'id' });
    };

    return Matricula;
};