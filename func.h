#ifndef FUNC_H
#define FUNC_H

#define MAX_TAREFAS 100
#define TAM_DESCRICAO 100

typedef struct {
    int id;
    char descricao[TAM_DESCRICAO];
    int prioridade;
    int concluida;
} Tarefa;

extern Tarefa listaTarefas[MAX_TAREFAS];
extern int totalTarefas;

void adicionarTarefa();
void exibirTarefas();
void concluirTarefa();
void excluirTarefa();

#endif
