#ifndef ALGORITHM_GRAPHS_H
#define ALGORITHM_GRAPHS_H
/**
 *  ��ͼ��ص��㷨
 */

#include "../../dataStructures/graph/Graph.h"
#include <iostream>
#include "../../dataStructures/queue/Queue.h"
#include "../../dataStructures/stack/Stack.h"
#include "../../dataStructures/stack/LinkedStack.h"
#include "../../dataStructures/queue/LinkedQueue.cpp"
#include "../../dataStructures/graph/ListGraph.h"
#include "../../util/list_tool.h"
#include <vector>

/**
 *  ���ñ������
 */
void reset_mark(Graph* graph) {
    for (int i = 0; i < graph->V(); ++i)
        graph->setMark(i, UNVISITED);
}


/**
 *  ͨ��ͼ��������
 */
void graph_traverse(Graph* G) {
    for (int i = 0; i < G->V(); ++i)
        G->setMark(i, UNVISITED);
    for (int i = 0; i < G->V(); ++i)
        if (G->getMark(i) == UNVISITED) {
            // doSomething()
        }
}

/**
 *  ����������� Depth First Search
 */

// ���ڵݹ�ʵ��
void DFS(Graph* G, int v) {
    // pre_do()
    std::cout << v << " ";
    G->setMark(v, VISITED);
    for (int i = G->first(v); i < G->V(); i = G->next(v, i)) {
        if (G->getMark(i) == UNVISITED) DFS(G, i);
    }
    // post_do()
}

// ����ջʵ��
void DFS_stack(Graph* G, int v) {
    // TODO
}

/**
 *  ����������� Breadth First Search
 */

// ���ڶ���ʵ��
void BFS(Graph* G, int v) {
    auto* queue = new LinkedQueue<int>;
    queue->enqueue(v);
    while (queue->length() > 0) {
        int curr = queue->dequeue();
        if (G->getMark(curr) == VISITED) continue;
        G->setMark(curr, VISITED);
        std::cout << curr << " ";
        int curr_neighbor = G->first(curr);
        while (curr_neighbor < G->V()) {
            queue->enqueue(curr_neighbor);
            curr_neighbor = G->next(curr, curr_neighbor);
        }
    }
}


/**
 *  �������� Topological Sort
 */
void top_sort_recursion_help(Graph* G, int v) {
    G->setMark(v, VISITED);
    for (int curr = G->first(v); curr < G->V(); curr = G->next(v, curr)) {
        if (G->getMark(curr) == UNVISITED)
            top_sort_recursion_help(G, curr);
    }
    // post do
    std::cout << v << " ";
}
// ���ڵݹ�ʵ��
void top_sort_recursion(Graph* G) {
    reset_mark(G);
    for (int i = 0; i < G->V(); ++i)
        if (G->getMark(i) == UNVISITED) {
            top_sort_recursion_help(G, i);
//            std::cout << " | ";
        }
    std::cout << std::endl;
}

// ���ڶ���ʵ��
void top_sort_queue(Graph* G) {
    auto* queue = new LinkedQueue<int>;
    int* count = new int[G->V()];
    // init
    for (int i = 0; i < G->V(); ++i) count[i] = 0;
    // count
    for (int i = 0; i < G->V(); ++i)
        for (int j = G->first(i); j < G->V(); j = G->next(i, j))
            count[j] ++;
    // ������û��ǰ�ö���Ķ���������
    for (int i = 0; i < G->V(); ++i)
        if (count[i] == 0) queue->enqueue(i);
    while (queue->length() > 0) {
        int curr = queue->dequeue();
        // ��ӡ��ǰ����
        std::cout << curr << " ";
        // �Ե�ǰ��������к��ö�����м�һ������countֵΪ0�Ķ���������
        for (int i = G->first(curr); i < G->V(); i = G->next(curr, i)) {
            count[i] --;
            if (count[i] == 0) queue->enqueue(i);
        }
    }
    delete[] count;
    delete queue;
}

// Ѱ����v�㿪ʼ�Ļ�·,vector���ڼ�¼��·��Ϣ
void seek_loop(Graph* G, int v, std::vector<int>* vector) {
    // ���vû�к�������ֱ�Ӻ�����
    if (G->first(v) != G->V()) {
        G->setMark(v, VISITED);
        vector->push_back(v);
    } else return;
    for (int curr = G->first(v); curr < G->V(); curr = G->next(v, curr)) {
        if (G->getMark(curr) == UNVISITED) {
            seek_loop(G, curr, vector);
        } else if (vector->front() == curr) {
            std::cout << "���ڻ�·��" << std::endl;
            for (int i : *vector) std::cout << i << " ";
            std::cout << std::endl;
        }
    }
    G->setMark(v, UNVISITED);
    vector->pop_back();
}

// ���ڶ���ʵ�֣�������·
void top_sort_queue_check_loop(Graph* G) {
    // ���ñ�־����
    reset_mark(G);
    auto* queue = new LinkedQueue<int>;
    int* count = new int[G->V()];
    // init
    for (int i = 0; i < G->V(); ++i) count[i] = 0;
    // count
    for (int i = 0; i < G->V(); ++i)
        for (int j = G->first(i); j < G->V(); j = G->next(i, j))
            count[j] ++;
    // ������û��ǰ�ö���Ķ���������
    for (int i = 0; i < G->V(); ++i)
        if (count[i] == 0) queue->enqueue(i);
    while (queue->length() > 0) {
        int curr = queue->dequeue();
        // ��ӡ��ǰ���㣬�����б��
        std::cout << curr << " ";
        G->setMark(curr, VISITED);
        // �Ե�ǰ��������к��ö�����м�һ������countֵΪ0�Ķ���������
        for (int i = G->first(curr); i < G->V(); i = G->next(curr, i)) {
            count[i] --;
            if (count[i] == 0) queue->enqueue(i);
        }
    }
    // �Ų��·
    std::cout << std::endl;
    for (int i = 0; i < G->V(); ++i) {
        if (G->getMark(i) == UNVISITED) {
            // Ѱ�һ�·
            auto* vector = new std::vector<int>;
            seek_loop(G, i, vector);
            delete vector;
        }
    }
    delete[] count;
    delete queue;
}


/**
 *  ���·���㷨
 */

void print_path(Graph* graph, int start, std::vector<int>* vector) {
    for (int i = graph->first(start); i < graph->V(); i = graph->next(start, i)) {
        vector->push_back(i);
        // print queue
        for (auto item: *vector) std::cout << item << "->";
        std::cout << std::endl;
        print_path(graph, i, vector);
        vector->pop_back();
    }
}

void parse_path(const int* parent, int size, int start = 0) {
    Graph* graph = new MatrixGraph(size);
    for (int i = 0; i < size; ++i) {
        if (parent[i] != -1) {
            graph->setEdge(parent[i], i, 1);
        }
    }
    auto* vector = new std::vector<int>;
    vector->push_back(start);
    print_path(graph, start, vector);
    delete graph;
    delete vector;
}


// Dijkstra
/**
 * @param graph ��Ȩͼ
 * @param v Դ����
 */
void Dijkstra(Graph* graph, int v) {
    // size ������ʾ��ǰδ��ǵĸ���
    int size = graph->V();
    reset_mark(graph);
    // ��¼Դ���㵽��ǰ�������̾���
    int* distance = new int[size];
    for (int i = 0; i < size; ++i) distance[i] = -1; // �����-1��ʾ�߼��ϵ�������
    // ��¼��ǰ������̾����ǰһ������
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
    list_show(distance, graph->V());
//    list_show(parent, graph->V());
    parse_path(parent, graph->V(), v);
    delete[] distance;
    delete[] parent;
}


#endif //ALGORITHM_GRAPHS_H
