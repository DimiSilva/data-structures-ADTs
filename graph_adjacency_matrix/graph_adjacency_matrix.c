#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph_adjacency_matrix.h"

Graph *createGraph(int verticesNumber)
{

    Graph *graph=(Graph*) malloc(sizeof(Graph));
    graph->verticesNumber = verticesNumber;
    graph->edgesNumber = 0;

     int **matrix = (int**) calloc(verticesNumber, sizeof(int*));
    for(int i = 0; i < verticesNumber; i++) matrix[i] = (int*) calloc(verticesNumber, sizeof(int));

    for(int i = 0; i < verticesNumber; i++){
        for(int j = 0; j < verticesNumber; j++) matrix[i][j] = 0;
    }

    graph->edges = matrix;
    return graph;
}


int insertEdgeInGraph(Graph * graph, int origin, int destiny)
{
    if(graph == NULL) return 0;

    if(graph->edges[origin][destiny] == 0){
        graph->edges[origin][destiny] = 1;
        graph->edgesNumber++;
    }
    return 1;
}

int removeEdgeFromGraph(Graph * graph, int origin, int destiny)
{
    if(graph == NULL) return 0;

    if(graph->edges[origin][destiny] == 1){
        graph->edges[origin][destiny] = 0;
        graph->edgesNumber--;
    }
    return 1;
}
