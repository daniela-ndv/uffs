/* Trabalho Prático: Sistema de Registos de Alunos em Arquivo Binário

Objetivo: Implementar as funções CRUD (Create, Read, Update, Delete) para um  sistema de registos de alunos, manipulando diretamente um arquivo. 
O foco é a eficiência, realizando operações "in-place" (no local)  sempre que possível, sem reescrever o arquivo inteiro.

Testes:

1- Criar um arquivo inicial com 5 alunos 
    typedef struct {     int id;     char nome[TAMANHO_NOME];     float media;     int ativo; // 1 para ativo, 0 para "apagado" (deleção lógica) } Aluno;
2- Listar todos os alunos ativos 
3- Atualizar a média do aluno com ID 3 para 9.5
4- Apagar (logicamente) o aluno com ID 2 (de 1 para 0)
5-  Atualizar um aluno que não existe (ID 99)
 
PS: cada função deve considerar que os dados estão somente no arquivo
*/

#include <stdio.h>
#include <string.h>

#define TAMANHO_NOME 50
#define NOME_ARQUIVO "file.txt"

typedef struct {
    int id; 
    char nome[TAMANHO_NOME]; 
    float media;    
    int ativo; 
} Aluno;

void criarArquivoInicial() {
    FILE *file = fopen(NOME_ARQUIVO, "wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Aluno alunos[5] = {
        {1, "Fulano da Silva", 8.2, 1},
        {2, "Beltrano Souza", 7.5, 1},
        {3, "Ciclano Lima", 6.8, 1},
        {4, "Ana Oliveira", 9.1, 1},
        {5, "Maria Pereira", 5.4, 1}
    };

    fwrite(alunos, sizeof(Aluno), 5, file);
    fclose(file);
    printf("Arquivo criado com 5 alunos.\n");
}

void listarAlunosAtivos() {
    FILE *file = fopen(NOME_ARQUIVO, "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Aluno aluno;
    printf("\nAlunos ativos:\n");
    while(fread(&aluno, sizeof(Aluno), 1, file) == 1){
        if(aluno.ativo == 1){
            printf("ID: %d | Nome: %s | Média: %.2f\n", aluno.id, aluno.nome, aluno.media);
        }
    }
    printf("\n");
    fclose(file);
}

void atualizarMediaAluno(int id, float novaMedia) {
    FILE *file = fopen(NOME_ARQUIVO, "r+b");
    if(file == NULL){
        printf("Erro ao abrir o arquivo para atualização.\n");
        return;
    }

    Aluno aluno;
    int encontrado = 0;
    while(fread(&aluno, sizeof(Aluno), 1, file) == 1){
        if(aluno.id == id){
            aluno.media = novaMedia;
            fseek(file, -sizeof(Aluno), SEEK_CUR);
            fwrite(&aluno, sizeof(Aluno), 1, file);
            encontrado = 1;
            printf("Média do aluno ID %d atualizada para %.2f\n", id, novaMedia);
            break;
        }
    }
    if(!encontrado) printf("Aluno com ID %d não encontrado.\n", id);
    fclose(file);
}

void deletarAluno(int id) {
    FILE *file = fopen(NOME_ARQUIVO, "r+b");
    if(file == NULL){
        printf("Erro ao abrir o arquivo para deleção lógica.\n");
        return;
    }

    Aluno aluno;
    int encontrado = 0;
    while(fread(&aluno, sizeof(Aluno), 1, file) == 1){
        if(aluno.id == id){
            aluno.ativo = 0;
            fseek(file, -sizeof(Aluno), SEEK_CUR);
            fwrite(&aluno, sizeof(Aluno), 1, file);
            encontrado = 1;
            printf("Aluno ID %d deletado logicamente.\n", id);
            break;
        }
    }
    if(!encontrado) printf("Aluno com ID %d não encontrado.\n", id);
    fclose(file);
}

int main(void){

    criarArquivoInicial();

    listarAlunosAtivos();

    atualizarMediaAluno(3, 9.5);

    // Apagar logicamente aluno com ID 2
    deletarAluno(2);

    // Atualizar aluno que não existe (ID 99)
    atualizarMediaAluno(99, 8.0);

    listarAlunosAtivos();

    return 0;
}
