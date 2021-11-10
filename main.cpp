#include "./dataStructures/graph/Graph.h"
#include "./dataStructures/graph/MatrixGraph.h"
#include "./algorithm/graph/graphs.h"

//    int size = 6;
//    int** matrix = new int*[size];
//    for (int i = 0; i < size; ++i) matrix[i] = new int[size];
//    Graph* graph = load_graph_from_matrix(matrix, size);

//MatrixGraph* load_graph_from_matrix(int** matrix, int size) {
//    auto* graph = new MatrixGraph(size);
//    for (int i = 0; i < size; ++i)
//        for (int j = 0; j < size; ++j)
//            graph->setEdge(i, j, matrix[i][j]);
//    return graph;
//}

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
    graph->setEdge(5,4,11);
    graph->setEdge(5,6,3);
    graph->setEdge(5,3,15);
    graph->setEdge(6,1,2);
    graph->setEdge(6,4,10);
    graph->setEdge(6,5,3);
}


int main()
{
    Graph* graph = new MatrixGraph(7);
    load(graph);
    DFS(graph, 1);
    return 0;
}