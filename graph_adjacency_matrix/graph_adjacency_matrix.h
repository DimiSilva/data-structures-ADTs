#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct graphStruct
{
    int verticesNumber;
    int edgesNumber;
    int **edges;
} Graph;

Graph *createGraph(int verticesNumber);

int insertEdgeInGraph(Graph * graph, int origin, int destiny);
int removeEdgeFromGraph(Graph * graph, int origin, int destiny);
#endif // GRAPH_H_INCLUDED
