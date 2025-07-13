#define PRODUCAO_H
#define TAM_HASH 100

// Definições das estruturas

typedef struct fardo{
   char cultivar[20];
   char tipoDeFeno;
   int diametro;
} Fardo;

typedef struct data{
   int dia;
   int mes;
   int ano;
} Data;

typedef struct producao{
   int codigo;
   Data dataProducao;
   Fardo tipoDeFardo;  
   int qtDeFardos;
   int tempoEmMin;
} Producao;

typedef struct no {
   Producao dado;
   struct no *prev;
   struct no *next;
} No;

typedef struct sentinelaNo {
   No *first;
   No *last;
} SentNo;

// Protótipos das funções

// Ações
int exibeMenu();
SentNo* incluirProducao(SentNo*, No* []);
void alterarProducao(No* []);
SentNo* excluirProducao(SentNo*, No* []);
void consultarPorData(SentNo*);
void consultarPorCultivar(SentNo*);
void listarTodos(SentNo*);

// Auxiliares
No* lerNo(No* []);
int lerCodigoValido(No *tabelaHash[]);
void lerFardo(Fardo *fardo);
Data lerData();
unsigned int funcaoHash(int);
int insereNaTabelaHash(No* [], No*);
int codigoExisteNaTabelaHash(No* [], int);
float calcularAreaMinimaArmazenagem(int qtFardos, int diametroCm);
