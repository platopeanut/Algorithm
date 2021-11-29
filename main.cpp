//#include "./algorithm/graph/path.h"
//
//#define MAX 100
//
//int main()
//{
//    // 图11.16
//    int graph[][5] = {
//            0,10,3,20,MAX,
//            MAX,0,MAX,5,MAX,
//            MAX,2,0,MAX,15,
//            MAX,MAX,MAX,0,11,
//            MAX,MAX,MAX,MAX,0
//    };
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            if (graph[i][j] != MAX)
//            graph[i][j] = -graph[i][j];
//        }
//    }
//    Floyd(graph, 5);
//}

#include "./algorithm/graph/path.h"


/**
 *  加载图11.16
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