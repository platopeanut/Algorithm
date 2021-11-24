#include "./algorithm/graph/graphs.h"
#include "./dataStructures/tree/ParPtrTree.h"
/**
 *  ¼ÓÔØÍ¼11.20
 */
void load(Graph* graph) {
    graph->setEdge(0, 2, 7);
    graph->setEdge(0, 4, 9);
    graph->setEdge(1, 2, 5);
    graph->setEdge(1, 5, 6);
    graph->setEdge(2, 0, 7);
    graph->setEdge(2, 1, 5);
    graph->setEdge(2, 3, 1);
    graph->setEdge(2, 5, 2);
    graph->setEdge(3, 2, 1);
    graph->setEdge(3, 5, 2);
    graph->setEdge(4, 0, 9);
    graph->setEdge(4, 5, 1);
    graph->setEdge(5, 1, 6);
    graph->setEdge(5, 2, 2);
    graph->setEdge(5, 3, 2);
    graph->setEdge(5, 4, 1);
}


int main()
{
    Graph* graph = new MatrixGraph(6);
    load(graph);
    Kruskal(graph);
    delete graph;
    return 0;
}

