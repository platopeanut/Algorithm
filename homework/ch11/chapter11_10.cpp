// 打印list
template<typename E>
void list_show(E* list, int size) {
    std::cout << "[\t";
    for (int i = 1; i < size; ++i) {
        std::cout << list[i] << "\t";
    }
    std::cout << "]" << std::endl;
}


// Dijkstra
/**
 * @param graph 加权图
 * @param v 源顶点
 */
void Dijkstra(Graph* graph, int v) {
    // size 用于显示当前未标记的个数
    int size = graph->V();
    reset_mark(graph);
    // 记录源顶点到当前顶点的最短距离
    int* distance = new int[size];
    for (int i = 0; i < size; ++i) distance[i] = -1; // 这里的-1表示逻辑上的正无穷
    // 记录当前顶点最短距离的前一个顶点
    int* parent = new int[size];
    for (int i = 0; i < size; ++i) parent[i] = -1;
    // init source vertex
    graph->setMark(v, VISITED);
    size --;
    distance[v] = 0;
    list_show(distance, graph->V());
    for (int curr = graph->first(v); curr < graph->V(); curr = graph->next(v, curr)) {
        distance[curr] = graph->getWeight(v, curr);
        parent[curr] = v;
    }
    // loop
    while (size > 0) {
        list_show(distance, graph->V());
        // find min distance
        int min_distance, min_index;
        for (min_index = 0; min_index < graph->V(); ++min_index)
            if (graph->getMark(min_index) == UNVISITED) break;
        min_distance = distance[min_index];
        for (int i = min_index + 1; i < graph->V(); ++i) {
            if (graph->getMark(i) == UNVISITED && distance[i] != -1) {
                if (min_distance == -1 || distance[i] < min_distance) {
                    min_index = i;
                    min_distance = distance[i];
                }
            }
        }
        // handle next
        graph->setMark(min_index, VISITED);
        size --;
        for (int curr = graph->first(min_index); curr < graph->V(); curr = graph->next(min_index, curr)) {
            if (graph->getMark(curr) == UNVISITED) {
                int tmp = graph->getWeight(min_index, curr) + distance[min_index];
                if (distance[curr] == -1 || distance[curr] > tmp) {
                    distance[curr] = tmp;
                    parent[curr] = min_index;
                }
            }
        }
    }
    // show
//    for (int i = 0; i < graph->V(); ++i) std::cout << graph->getMark(i) << " ";
//    std::cout << std::endl;
//    list_show(distance, graph->V());
//    list_show(parent, graph->V());
    parse_path(parent, graph->V(), v);
    delete[] distance;
    delete[] parent;
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
    Dijkstra(graph, 4);
    delete graph;
    return 0;
}