// 打印list
template<typename E>
void list_show(E* list, int size) {
    std::cout << "[";
    for (int i = 1; i < size; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << "]" << std::endl;
}

#include "./dataStructures/graph/MatrixGraph.h"
#include "./algorithm/graph/graphs.h"

/**
 *  手动加载图 11.26
 */
void load(Graph* graph) {
    graph->setEdge(1, 2, 10);
    graph->setEdge(1, 4, 20);
    graph->setEdge(1, 6, 2);
    graph->setEdge(2, 1, 10);
    graph->setEdge(2, 3, 3);
    graph->setEdge(2, 4, 5);
    graph->setEdge(3, 2, 3);
    graph->setEdge(3, 5, 15);
    graph->setEdge(4, 2, 5);
    graph->setEdge(4, 1, 20);
    graph->setEdge(4, 5, 11);
    graph->setEdge(4, 6, 10);
    graph->setEdge(5, 4, 11);
    graph->setEdge(5, 6, 3);
    graph->setEdge(5, 3, 15);
    graph->setEdge(6, 1, 2);
    graph->setEdge(6, 4, 10);
    graph->setEdge(6, 5, 3);
}

int main() {
    Graph* graph = new MatrixGraph(7);
    load(graph);
    Dijkstra(graph, 1);
    delete graph;
    return 0;
}