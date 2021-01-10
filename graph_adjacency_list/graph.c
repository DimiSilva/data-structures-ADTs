#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"

Graph *createGraph(int verticesNumber, int maxDegree, int isWeighted)
{
    Graph *graph=(Graph*) malloc(sizeof(Graph));
    if(graph != NULL)
    {
        graph->verticesNumber = verticesNumber;
        graph->maxDegree = maxDegree;
        graph->isWeighted = isWeighted != 0 ? 1 : 0;
        graph->degree = (int *) calloc(verticesNumber, sizeof(int));

        graph->edges =  (int **) malloc(verticesNumber*sizeof(int*));
        for(int i = 0; i < verticesNumber; i++) graph->edges[i] = (int *) malloc(maxDegree*sizeof(int));

        if(graph->isWeighted)
        {
            graph->weights=(float**) malloc(verticesNumber*sizeof(float*));
            for(int i = 0; i < verticesNumber; i++) graph->weights[i] = (float*) malloc(maxDegree*sizeof(float));
        }
    }
    return graph;
}

void clearGraph(Graph *graph)
{
    if(graph != NULL)
    {
        for(int i = 0; i < graph->verticesNumber; i++) free(graph->edges[i]);
        free(graph->edges);

        if(graph->isWeighted)
        {
            for(int i = 0; i < graph->verticesNumber; i++) free(graph->weights[i]);
            free(graph->weights);
        }

        free(graph->degree);
        free(graph);
    }
}

int insertEdgeInGraph(Graph * graph, int origin, int destiny, int isDigraph, float weight)
{
    if(graph == NULL) return 0;
    if(origin < 0 || origin >= graph->verticesNumber) return 0;
    if(destiny < 0 || destiny >= graph->verticesNumber) return 0;

    graph->edges[origin][graph->degree[origin]] = destiny;
    if(graph->isWeighted) graph->weights[origin][graph->degree[origin]] = weight;
    graph->degree[origin] ++;

    if(isDigraph == 0) insertEdgeInGraph(graph, destiny, origin, 1, weight);
    return 1;
}

int removeEdgeFromGraph(Graph * graph, int origin, int destiny, int isDigraph)
{
    if(graph == NULL) return 0;
    if(origin < 0 || origin >= graph->verticesNumber) return 0;
    if(destiny < 0 || destiny >= graph->verticesNumber) return 0;

    int elementIndex = 0;
    while(elementIndex<graph->degree[origin] && graph->edges[origin][elementIndex] != destiny) elementIndex++;
    if(elementIndex == graph->degree[origin]) return 0;

    graph->degree[origin] --;
    graph->edges[origin][elementIndex] = graph->edges[origin][graph->degree[origin]];
    if(graph->isWeighted) graph->weights[origin][elementIndex] = graph->weights[origin][graph->degree[origin]];

    if(isDigraph == 0) removeEdgeFromGraph(graph, destiny, origin, 1);
    return 1;
}

void graphDepthFirstSearch(Graph *graph, int begin, int *visited)
{
    int count = 1;
    for (int i = 0; i < graph->verticesNumber; i++) visited[i] = 0;

    depthFirstSearch(graph, begin, visited, count);
}

void depthFirstSearch(Graph *graph, int begin, int *visited, int count)
{
    visited[begin] = count;
    for(int i = 0; i<graph->degree[begin]; i++)
    {
        if(!visited[graph->edges[begin][i]])
            depthFirstSearch(graph, graph->edges[begin][i], visited, count+1);
    }
}

void graphBreadthFirstSearch(Graph *graph, int begin, int *visited)
{
    int count = 1, *queue, queueBegin = 0, queueEnd = 0, currentVertice;
    for (int i = 0; i < graph->verticesNumber; i++) visited[i] = 0;
    queue = (int*) malloc(graph->verticesNumber*sizeof(int));
    queueEnd++;
    queue[queueEnd] = begin;
    visited[begin] = count;

    while(queueBegin != queueEnd)
    {
        queueBegin = (queueBegin + 1) % graph->verticesNumber;
        currentVertice = queue[queueBegin];
        count++;
        for(int i = 0; i < graph->degree[currentVertice]; i++)
        {
            if(!visited[graph->edges[currentVertice][i]])
            {
                queueEnd = (queueEnd + 1) % graph->verticesNumber;
                queue[queueEnd] = graph->edges[currentVertice][i];
                visited[graph->edges[currentVertice][i]] = count;
            }
        }
    }
    free(queue);
}

void graphShortestPathSearch(Graph *graph, int begin, int *previous, float *distances)
{
    int count, neighbor, *visited, smallestDistance;
    count = graph->verticesNumber;
    visited = (int*) malloc(graph->verticesNumber*sizeof(int));

    for(int i = 0; i < graph->verticesNumber; i++)
    {
        previous[i] = -1;
        distances[i] = -1;
        visited[i] = 0;
    }

    distances[begin] = 0;

    while(count > 0)
    {
        smallestDistance = shortestPathSearch(distances, visited, graph->verticesNumber);
        if(smallestDistance == -1) break;

        visited[smallestDistance] = 1;
        count--;

        for(int i = 0; i < graph->degree[smallestDistance]; i++)
        {
            neighbor = graph->edges[smallestDistance][i];
            if(distances[neighbor] < 0)
            {
                distances[neighbor] = distances[smallestDistance] + 1;
                previous[neighbor] = smallestDistance;
            }
            else if(distances[neighbor] > distances[smallestDistance] + 1)
            {
                distances[neighbor] = distances[smallestDistance] + 1;
                previous[neighbor] = smallestDistance;
            }
        }
    }
    free(visited);
}

int shortestPathSearch(float *distances, int *visited, int verticesNumber)
{
    int smallest = -1, first = 1;
    for(int i = 0; i < verticesNumber; i++)
    {
        if(distances[i] >= 0 && visited[i] == 0)
        {
            if(first)
            {
                smallest = i;
                first = 0;
            }
            else
            {
                if(distances[smallest] > distances[i]) smallest = i;
            }
        }
    }
    return smallest;
}
