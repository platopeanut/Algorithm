#ifndef ALGORITHM_LISTGRAPH_H
#define ALGORITHM_LISTGRAPH_H
#include "./Graph.h"
#include "../list/List.h"
#include "../list/LinkedList.cpp"

/**
 *  �ڽӱ�ʵ��������Ԫ������
 *  �������ڽӱ�˽��
 */
class Edge {
public:
    // ������
    int vertex;
    // ��Ȩ��
    int weight;
    Edge(): vertex(-1), weight(-1) {}
    Edge(int v, int w): vertex(v), weight(w) {}
};


/**
 *  �ڽӱ�ʵ��ͼ Adjacency List
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

    // ���Ժ���
    void show() {
        for (int i = 0; i < this->vertex_num; ++i) {
            auto* list = this->vertex_list[i];
            std::cout << "List[";
            list->moveToStart();
            for (int j = 0; j < list->length(); ++j) {
                std::cout << list->getValue().vertex << ", ";
                list->next();
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "---------------" << std::endl;
    }
};


#endif //ALGORITHM_LISTGRAPH_H
