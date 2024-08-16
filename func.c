#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

Tarefa listaTarefas[MAX_TAREFAS];
int totalTarefas = 0;

void adicionarTarefa() {
    if (totalTarefas >= MAX_TAREFAS) {
        printf("Lista de tarefas cheia! Não é possível adicionar mais tarefas.\n");
        return; }

    Tarefa novaTarefa;
    novaTarefa.id = totalTarefas + 1;

    printf("Digite a descrição da tarefa: ");
    
    getchar();
    
    fgets(novaTarefa.descricao, TAM_DESCRICAO, stdin);
    novaTarefa.descricao[strcspn(novaTarefa.descricao, "\n")] = '\0';

    printf("Digite a prioridade da tarefa (1 = Alta, 2 = Média, 3 = Baixa): ");
    scanf("%d", &novaTarefa.prioridade);

    novaTarefa.concluida = 0;

    listaTarefas[totalTarefas] = novaTarefa;
    totalTarefas++;

    printf("Tarefa adicionada com sucesso!\n"); }
    

void exibirTarefas() {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return; }

    printf("Lista de Tarefas:\n");
    for (int i = 0; i < totalTarefas; i++) {
        printf("ID: %d, Descrição: %s, Prioridade: %d, Concluída: %s\n",
               listaTarefas[i].id,
               listaTarefas[i].descricao,
               listaTarefas[i].prioridade,
               listaTarefas[i].concluida ? "Sim" : "Não"); } }


void concluirTarefa() {
    int id;
    printf("Digite o ID da tarefa a ser concluída: ");
    scanf("%d", &id);

    for (int i = 0; i < totalTarefas; i++) {
        if (listaTarefas[i].id == id) {
            listaTarefas[i].concluida = 1;
            printf("Tarefa concluída com sucesso!\n");
            return; } }
    printf("Tarefa com ID %d não encontrada.\n", id); }


void excluirTarefa() {
    int id;
    printf("Digite o ID da tarefa a ser excluída: ");
    scanf("%d", &id);

    for (int i = 0; i < totalTarefas; i++) {
        if (listaTarefas[i].id == id) {
            for (int j = i; j < totalTarefas - 1; j++) {
                listaTarefas[j] = listaTarefas[j + 1]; }
            totalTarefas--;
            printf("Tarefa excluída com sucesso!\n");
            return; } }
    printf("Tarefa com ID %d não encontrada.\n", id); }
    
