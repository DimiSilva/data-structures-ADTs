#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct graph
{
    int isWeighted;
    int verticesNumber;
    int maxDegree;
    int **edges;
    float ** weights;
    int *degree;
} Graph;

Graph *createGraph(int verticesNumber, int maxDegree, int isWeighted);
void clearGraph(Graph *graph);

int insertEdgeInGraph(Graph * graph, int origin, int destiny, int isDigraph, float weight);
int removeEdgeFromGraph(Graph * graph, int origin, int destiny, int isDigraph);

void graphDepthFirstSearch(Graph *graph, int begin, int *visited);
void depthFirstSearch(Graph *graph, int begin, int *visited, int count);
void graphBreadthFirstSearch(Graph *graph, int begin, int *visited);
void graphShortestPathSearch(Graph *graph, int begin, int *previous, float *distances);
int shortestPathSearch(float *distances, int *visited, int verticesNumber);
#endif // GRAPH_H_INCLUDED
