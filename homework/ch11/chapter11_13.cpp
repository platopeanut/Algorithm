#include "./algorithm/graph/path.h"


/**
 *  ????ͼ11.16
 */
void load(Graph* graph) {
    graph->setEdge(0,1,10);
    graph->setEdge(0,2,3);
    graph->setEdge(0,3,20);
    graph->setEdge(2,1,2);
    graph->setEdge(1,3,5);
    graph->setEdge(3,4,11);
    graph->setEdge(2,4,15);
    // test
//    graph->setEdge(4, 2, 15);
}

int main() {
    Graph* graph = new MatrixGraph(5);
    load(graph);
    longest_path(graph, 0);
    delete graph;
    return 0;
}