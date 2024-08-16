#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100
#define TAM_DESCRICAO 100

typedef struct {
    int id;
    char descricao[TAM_DESCRICAO];
    int prioridade;  // 1 = Alta, 2 = Média, 3 = Baixa
    int concluida;   // 0 = Não, 1 = Sim
} Tarefa;

Tarefa listaTarefas[MAX_TAREFAS];
int totalTarefas = 0;

// Função para adicionar uma nova tarefa
void adicionarTarefa() {
    if (totalTarefas >= MAX_TAREFAS) {
        printf("Lista de tarefas cheia! Não é possível adicionar mais tarefas.\n");
        return;
    }

    Tarefa novaTarefa;
    novaTarefa.id = totalTarefas + 1;

    printf("Digite a descrição da tarefa: ");
    getchar();  // Limpar buffer do stdin
    fgets(novaTarefa.descricao, TAM_DESCRICAO, stdin);
    novaTarefa.descricao[strcspn(novaTarefa.descricao, "\n")] = '\0';  // Remover nova linha

    printf("Digite a prioridade da tarefa (1 = Alta, 2 = Média, 3 = Baixa): ");
    scanf("%d", &novaTarefa.prioridade);

    novaTarefa.concluida = 0;

    listaTarefas[totalTarefas] = novaTarefa;
    totalTarefas++;

    printf("Tarefa adicionada com sucesso!\n");
}

// Função para exibir todas as tarefas
void exibirTarefas() {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("Lista de Tarefas:\n");
    for (int i = 0; i < totalTarefas; i++) {
        printf("ID: %d, Descrição: %s, Prioridade: %d, Concluída: %s\n",
               listaTarefas[i].id,
               listaTarefas[i].descricao,
               listaTarefas[i].prioridade,
               listaTarefas[i].concluida ? "Sim" : "Não");
    }
}

// Função para marcar uma tarefa como concluída
void concluirTarefa() {
    int id;
    printf("Digite o ID da tarefa a ser concluída: ");
    scanf("%d", &id);

    for (int i = 0; i < totalTarefas; i++) {
        if (listaTarefas[i].id == id) {
            listaTarefas[i].concluida = 1;
            printf("Tarefa concluída com sucesso!\n");
            return;
        }
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

// Função para excluir uma tarefa
void excluirTarefa() {
    int id;
    printf("Digite o ID da tarefa a ser excluída: ");
    scanf("%d", &id);

    for (int i = 0; i < totalTarefas; i++) {
        if (listaTarefas[i].id == id) {
            for (int j = i; j < totalTarefas - 1; j++) {
                listaTarefas[j] = listaTarefas[j + 1];
            }
            totalTarefas--;
            printf("Tarefa excluída com sucesso!\n");
            return;
        }
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

// Função principal
int main() {
    int opcao;

    while (1) {
        printf("\nSistema de Gerenciamento de Tarefas\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Exibir tarefas\n");
        printf("3. Concluir tarefa\n");
        printf("4. Excluir tarefa\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                exibirTarefas();
                break;
            case 3:
                concluirTarefa();
                break;
            case 4:
                excluirTarefa();
                break;
            case 5:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
