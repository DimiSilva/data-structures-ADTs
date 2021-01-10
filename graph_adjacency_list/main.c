#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "graph.h"

Graph* graph;

void renderPresentation(int option);
void renderOptions();
char*  getOptionTitle(int option);
void goToOption(int option);

void makeAEdgeInsertionInGraph(int option);
void makeAEdgeRemotionFromGraph(int option);
void makeAInDepthSearchInGraph(int option);
void makeAInBreadthSearchInGraph(int option);
void makeAShortestPathSearchInGraph(int option);

int main()
{
    system("chcp 65001  > nul");

    graph = createGraph(5, 5, 0);
    insertEdgeInGraph(graph, 0, 1, 1, 0);
    insertEdgeInGraph(graph, 1, 2, 1, 0);
    insertEdgeInGraph(graph, 2, 4, 1, 0);
    insertEdgeInGraph(graph, 1, 3, 1, 0);
    insertEdgeInGraph(graph, 4, 1, 1, 0);
    insertEdgeInGraph(graph, 1, 3, 1, 0);
    insertEdgeInGraph(graph, 3, 0, 1, 0);
    insertEdgeInGraph(graph, 3, 4, 1, 0);
    insertEdgeInGraph(graph, 4, 1, 1, 0);

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
    printf("3 - Fazer busca em profundidade no grafo\n");
    printf("4 - Fazer busca em largura no grafo\n");
    printf("5 - Fazer busca por menor caminho no grafo\n");
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
    case 3:
        return "Fazer busca em profundidade no grafo";
    case 4:
        return "Fazer busca em largura no grafo";
    case 5:
        return "Fazer busca em menor caminho no grafo";
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
    case 3:
        makeAInDepthSearchInGraph(option);
        break;
    case 4:
        makeAInBreadthSearchInGraph(option);
    case 5:
        makeAShortestPathSearchInGraph(option);
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
    renderPresentation(option);
    isDigraph= getIntUserInput("Digite 1 caso seja digrafo, 0 caso não seja ou um valor negativo caso queira voltar ao menu: ");
    if( isDigraph < 0) return ;
    if(graph->isWeighted)
    {
        renderPresentation(option);
        weight = getFloatUserInput("Digite o peso da aresta ou um valor negativo caso queira voltar ao menu: ");
        if( weight < 0) return ;
    }

    int res = insertEdgeInGraph(graph, origin, destiny, isDigraph, weight);

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
    renderPresentation(option);
    isDigraph= getIntUserInput("Digite 1 caso seja digrafo, 0 caso não seja ou um valor negativo caso queira voltar ao menu: ");
    if( isDigraph < 0) return ;

    int res = removeEdgeFromGraph(graph, origin, destiny, isDigraph);

    renderPresentation(option);

    printf(res == 1 ? "Aresta removida" : "Aresta não encontrada");
}

void makeAInDepthSearchInGraph(int option)
{
    int begin;
    int visited[graph->verticesNumber];

    begin = getIntUserInput("Digite o número da vértice onde a busca será iniciada um valor negativo caso queira voltar ao menu: ");
    if(begin < 0) return ;

    graphDepthFirstSearch(graph, begin, visited);

    renderPresentation(option);

    printf("Resultado da busca: \n");
    for(int i = 0; i < graph->verticesNumber; i++) printf("%d\n", visited[i]);
}

void makeAInBreadthSearchInGraph(int option)
{
    int begin;
    int visited[graph->verticesNumber];

    begin = getIntUserInput("Digite o número da vértice onde a busca será iniciada um valor negativo caso queira voltar ao menu: ");
    if(begin < 0) return ;

    graphBreadthFirstSearch(graph, begin, visited);

    renderPresentation(option);

    printf("Resultado da busca: \n");
    for(int i = 0; i < graph->verticesNumber; i++) printf("%d\n", visited[i]);
}

void makeAShortestPathSearchInGraph(int option)
{
    int begin;
    int previous[graph->verticesNumber];
    float distances[graph->verticesNumber];

    begin = getIntUserInput("Digite o número da vértice onde a busca será iniciada um valor negativo caso queira voltar ao menu: ");
    if(begin < 0) return ;

    graphShortestPathSearch(graph, begin, previous, distances);

    renderPresentation(option);

    printf("Vertices anteriores ao vértice procurado: \n");
    for(int i = 0; i < graph->verticesNumber; i++) printf("%d\n", previous[i]);
    printf("\n");
    printf("Distancias: \n");
    for(int i = 0; i < graph->verticesNumber; i++) printf("%f\n", distances[i]);
}
