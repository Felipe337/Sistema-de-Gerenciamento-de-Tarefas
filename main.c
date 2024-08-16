#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100
#define TAM_DESCRICAO 100

#include "func.h"

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
                printf("Opção inválida. Tente novamente.\n"); } }

    return 0;
}
