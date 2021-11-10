#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

/**
 *  ͼ��ADT
 */

// mark����ı�־λ
#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    void operator= (const Graph&) {}
    Graph(const Graph&) {}

public:
    Graph() {}
    virtual ~Graph() {}
    // ����һ������V�����㵫�����бߵ�ͼ
    virtual void init(int V) = 0;
    // ������
    virtual int V() = 0;
    // ����
    virtual int E() = 0;
    // ����v�ĵ�һ�����ڶ���
    virtual int first(int v) = 0;
    // ����v1����v2�����һ�����ڶ���
    virtual int next(int v1, int v2) = 0;
    // ���һ����
    virtual void setEdge(int v1, int v2, int weight) = 0;
    // ɾ��һ����
    virtual void delEdge(int v1, int v2) = 0;
    // v1,v2���������Ƿ�����
    virtual bool isEdge(int v1, int v2) = 0;
    // v1,v2������ıߵ�Ȩ��
    virtual int getWeight(int v1, int v2) = 0;
    // v��mark����
    virtual int getMark(int v) = 0;
    // ����v��mark����
    virtual void setMark(int v, int mark) = 0;
};


#endif //ALGORITHM_GRAPH_H
