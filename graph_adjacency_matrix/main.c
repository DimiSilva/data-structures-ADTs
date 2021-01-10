#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "graph_adjacency_matrix.h"

Graph* graph;

void renderPresentation(int option);
void renderOptions();
char*  getOptionTitle(int option);
void goToOption(int option);

void makeAEdgeInsertionInGraph(int option);
void makeAEdgeRemotionFromGraph(int option);

int main()
{
    system("chcp 65001  > nul");

    graph = createGraph(5);
    insertEdgeInGraph(graph, 0, 1);
    insertEdgeInGraph(graph, 1, 2);
    insertEdgeInGraph(graph, 2, 4);
    insertEdgeInGraph(graph, 1, 3);
    insertEdgeInGraph(graph, 4, 1);
    insertEdgeInGraph(graph, 1, 3);
    insertEdgeInGraph(graph, 3, 0);
    insertEdgeInGraph(graph, 3, 4);
    insertEdgeInGraph(graph, 4, 1);

    int option = -1;
    do
    {
        option = -1;
        renderPresentation(option);
        renderOptions();
        scanf("%d", &option);
        if(option < 0 || option > 13)
        {
            printf("Digite uma opção válida!\n");
            pressAnyKeyToContinue();
            continue;
        }

        if(option != 0) goToOption(option);
    }
    while (option != 0);
    return 0;
}

void renderPresentation(int option)
{
    system("cls");
    printf("Grafo");

    if(option != -1)
        printf("\n\nOpção atual: %s:", getOptionTitle(option));

    printf("\n\n");
}

void renderOptions()
{
    printf("Selecione uma operação: \n");
    printf("1 - Fazer inserção de aresta no grafo\n");
    printf("2 - Fazer remoção de aresta do grafo\n");
    printf("0 - Sair\n");
}

char* getOptionTitle(int option)
{
    switch(option)
    {
    case 1:
        return "Fazer inserção de aresta no grafo";
    case 2:
        return "Fazer remoção de aresta do grafo";
    default:
        return "";
    }
}

void goToOption(int option)
{
    renderPresentation(option);
    switch(option)
    {
    case 1:
        makeAEdgeInsertionInGraph(option);
        break;
    case 2:
        makeAEdgeRemotionFromGraph(option);
        break;
    }
    pressAnyKeyToContinue();
}

void makeAEdgeInsertionInGraph(int option)
{
    int origin, destiny, isDigraph;
    float weight;

    origin = getIntUserInput("Digite a origem da aresta ou um valor negativo caso queira voltar ao menu: ");
    if(origin < 0) return ;
    renderPresentation(option);
    destiny = getIntUserInput("Digite o destino da aresta ou um valor negativo caso queira voltar ao menu: ");
    if( destiny < 0) return ;

    int res = insertEdgeInGraph(graph, origin, destiny);

    renderPresentation(option);

    printf(res == 1 ? "Aresta inserida" : "Ocorreu um erro");
}

void makeAEdgeRemotionFromGraph(int option)
{
    int origin, destiny, isDigraph;

    origin = getIntUserInput("Digite a origem da aresta ou um valor negativo caso queira voltar ao menu: ");
    if(origin < 0) return ;
    renderPresentation(option);
    destiny = getIntUserInput("Digite o destino da aresta ou um valor negativo caso queira voltar ao menu: ");
    if( destiny < 0) return ;

    int res = removeEdgeFromGraph(graph, origin, destiny);

    renderPresentation(option);

    printf(res == 1 ? "Aresta removida" : "Aresta não encontrada");
}
