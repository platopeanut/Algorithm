#ifndef ALGORITHM_GRAPHS_H
#define ALGORITHM_GRAPHS_H
/**
 *  与图相关的算法
 */

#include "../../dataStructures/graph/Graph.h"
#include <iostream>

/**
 *  通用图遍历函数
 */
void graph_traverse(Graph* G) {
    for (int i = 0; i < G->V(); ++i)
        G->setMark(i, UNVISITED);
    for (int i = 0; i < G->V(); ++i)
        if (G->getMark(i) == UNVISITED)
            // doSomething()
}

/**
 *  深度优先搜索 Depth First Search
 */
void DFS(Graph* G, int v) {
    // pre_do()
    std::cout << v << " ";
    G->setMark(v, VISITED);
    for (int i = G->first(v); i < G->V(); i = G->next(v, i)) {
        if (G->getMark(i) == UNVISITED) DFS(G, i);
    }
    // post_do()
}

/**
 *  广度优先搜索 Breadth First Search
 */

void BFS(Graph* G, int v) {
    // pre_do()
    G->setMark(v, VISITED);


    // post_do()
}

#endif //ALGORITHM_GRAPHS_H
