#include "./algorithm/graph/graphs.h"
#include "./dataStructures/graph/MatrixGraph.h"
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
    graph->setEdge(5, 4, 11);
    graph->setEdge(5, 6, 3);
    graph->setEdge(5, 3, 15);
    graph->setEdge(6, 1, 2);
    graph->setEdge(6, 4, 10);
    graph->setEdge(6, 5, 3);
}

/**
 *
 *  手动加载图 11.14
 */
void load2(Graph* graph) {
    graph->setEdge(1, 2, 1);
    graph->setEdge(1, 3, 1);
    graph->setEdge(2, 6, 1);
    graph->setEdge(2, 5, 1);
    graph->setEdge(2, 4, 1);
    graph->setEdge(3, 4, 1);
    graph->setEdge(4, 5, 1);
    graph->setEdge(5, 7, 1);
    // 测试，形成回路
    graph->setEdge(5, 2, 1);
}
int main()
{
    // 这里之所以创建7个点，原因是下标方便与图 11.26 上的点下标保持一致
    Graph* graph = new MatrixGraph(7);
    // 加载图 11.26
    load2(graph);
    std::cout << "基于递归：" << std::endl;
    top_sort_recursion(graph);
    std::cout << "基于队列：" << std::endl;
    top_sort_queue_check_loop(graph);
    return 0;
}


//深度优先：
//1 2 3 5 4 6
//广度优先：
//1 2 4 6 3 5
