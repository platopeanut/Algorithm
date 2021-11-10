#ifndef ALGORITHM_LISTGRAPH_H
#define ALGORITHM_LISTGRAPH_H
#include "./Graph.h"
#include "../list/List.h"
#include "../list/LinkedList.h"

/**
 *  邻接表实现中链表元素类型
 *  该类型邻接表私有
 */
class Edge {
public:
    // 点索引
    int vertex;
    // 边权重
    int weight;
    Edge(): vertex(-1), weight(-1) {}
    Edge(int v, int w): vertex(v), weight(w) {}
};


/**
 *  邻接表实现图 Adjacency List
 */
class ListGraph: public Graph {
private:
    int vertex_num;
    int edge_num;
    List<Edge>** vertex_list;
    int* mark_list;

public:

    ListGraph(int V) { init(V); }

    ~ListGraph() override;

    void init(int V) override;

    int V() override;

    int E() override;

    int first(int v) override;

    int next(int v1, int v2) override;

    void setEdge(int v1, int v2, int weight) override;

    void delEdge(int v1, int v2) override;

    bool isEdge(int v1, int v2) override;

    int getWeight(int v1, int v2) override;

    int getMark(int v) override;

    void setMark(int v, int mark) override;
};


#endif //ALGORITHM_LISTGRAPH_H
