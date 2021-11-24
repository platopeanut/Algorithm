#include "./dataStructures/graph/MatrixGraph.h"
#include "./algorithm/graph/graphs.h"

/**
 *  ÊÖ¶¯¼ÓÔØÍ¼ 11.26
 */
void load(Graph* graph) {
    graph->setEdge(-1+1, -1+2, 10);
    graph->setEdge(-1+1, -1+4, 20);
    graph->setEdge(-1+1, -1+6, 2);
    graph->setEdge(-1+2, -1+1, 10);
    graph->setEdge(-1+2, -1+3, 3);
    graph->setEdge(-1+2, -1+4, 5);
    graph->setEdge(-1+3, -1+2, 3);
    graph->setEdge(-1+3, -1+5, 15);
    graph->setEdge(-1+4, -1+2, 5);
    graph->setEdge(-1+4, -1+1, 20);
    graph->setEdge(-1+4, -1+5, 11);
    graph->setEdge(-1+4, -1+6, 10);
    graph->setEdge(-1+5, -1+4, 11);
    graph->setEdge(-1+5, -1+6, 3);
    graph->setEdge(-1+5, -1+3, 15);
    graph->setEdge(-1+6, -1+1, 2);
    graph->setEdge(-1+6, -1+4, 10);
    graph->setEdge(-1+6, -1+5, 3);
}

int main() {
    Graph* graph = new MatrixGraph(6);
    load(graph);
    Prim(graph, 3);
    delete graph;
    return 0;
}