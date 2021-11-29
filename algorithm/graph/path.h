#ifndef ALGORITHM_PATH_H
#define ALGORITHM_PATH_H

#include "graphs.h"




/**
 *  DAG(有向无环图)最长路径
 */
void longest_path(Graph* graph, int v = 0) {
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
    for (int curr = graph->first(v); curr < graph->V(); curr = graph->next(v, curr)) {
        distance[curr] = graph->getWeight(v, curr);
        parent[curr] = v;
    }
    // loop
    while (size > 0) {
        // find max distance && distance != -1
        int max_distance, max_index;
        for (max_index = 0; max_index < graph->V(); ++max_index)
            if (graph->getMark(max_index) == UNVISITED) break;
        max_distance = distance[max_index];
        for (int i = max_index + 1; i < graph->V(); ++i) {
            if (graph->getMark(i) == UNVISITED && distance[i] != -1) {
                // change
                if (max_distance == -1 || distance[i] > max_distance) {
                    max_index = i;
                    max_distance = distance[i];
                }
            }
        }
        // handle next
        graph->setMark(max_index, VISITED);
        size --;
        for (int curr = graph->first(max_index); curr < graph->V(); curr = graph->next(max_index, curr)) {
            if (graph->getMark(curr) == UNVISITED) {
                int tmp = graph->getWeight(max_index, curr) + distance[max_index];
                // change
                if (distance[curr] == -1 || distance[curr] < tmp) {
                    distance[curr] = tmp;
                    parent[curr] = max_index;
                }
            }
        }
    }
    // show
//    for (int i = 0; i < graph->V(); ++i) std::cout << graph->getMark(i) << " ";
//    std::cout << std::endl;
    list_show(distance, graph->V());
//    list_show(parent, graph->V());
    parse_path(parent, graph->V(), v);
    delete[] distance;
    delete[] parent;
}



void Floyd(int graph[5][5], int size) {
    int** path = new int*[size];
    for (int i = 0; i < size; ++i) path[i] = new int[size];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            path[i][j] = 0;
        }
    }
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    // show
    for (int i = 0; i < size; ++i) {
        list_show(graph[i], size);
    }
    std::cout << "路径" << std::endl;
    for (int i = 0; i < size; ++i) {
        list_show(path[i], size);
    }
    for (int i = 0; i < size; ++i) delete[] path[i];
    delete[] path;
}

#endif //ALGORITHM_PATH_H
