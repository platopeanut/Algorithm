#ifndef ALGORITHM_GRAPHS_H
#define ALGORITHM_GRAPHS_H
/**
 *  ��ͼ��ص��㷨
 */

#include "../../dataStructures/graph/Graph.h"
#include <iostream>

/**
 *  ͨ��ͼ��������
 */
void graph_traverse(Graph* G) {
    for (int i = 0; i < G->V(); ++i)
        G->setMark(i, UNVISITED);
    for (int i = 0; i < G->V(); ++i)
        if (G->getMark(i) == UNVISITED)
            // doSomething()
}

/**
 *  ����������� Depth First Search
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
 *  ����������� Breadth First Search
 */

void BFS(Graph* G, int v) {
    // pre_do()
    G->setMark(v, VISITED);


    // post_do()
}

#endif //ALGORITHM_GRAPHS_H
