#ifndef TYPES_H
#define TYPES_H

struct table {
    int  idtable;
    char ctname[20]; // nome lógico da tabela (ex: "student")
    char ptname[20]; // nome físico (ex: "11.dat")
};
typedef struct table ttable;

struct att {
    int  idtable;
    char atname[20]; // nome do atributo
    char attype;     // S (string) I (integer) F (float) (C Char)
    char isKey;      // 1 é primary key
    char atopt;      // mandatory (0) optional (1)
    int  atlen;      // tamanho em bytes do campo no .dat
};
typedef struct att tatt;

#endif /* TYPES_H */