#include "ListGraph.h"

ListGraph::~ListGraph() {
    delete[] mark_list;
    for (int i = 0; i < vertex_num; ++i)
        delete vertex_list[i];
    delete[] vertex_list;
}

void ListGraph::init(int V) {
    vertex_num = V;
    edge_num = 0;
    // �����������
    mark_list = new int[vertex_num];
    // �������������Ԫ����Ϊunvisited
    for (int i = 0; i < vertex_num; ++i)
        mark_list[i] = UNVISITED;
    // �����ڽӱ�����
    vertex_list = new List<Edge>*[vertex_num];
    // ������ÿһ��Ԫ�ؽ��г�ʼ��
    for (int i = 0; i < vertex_num; ++i)
        vertex_list[i] = new LinkedList<Edge>;
}

int ListGraph::V() {
    return vertex_num;
}

int ListGraph::E() {
    return edge_num;
}

int ListGraph::first(int v) {
    if (vertex_list[v]->length() == 0)
        return vertex_num;
    vertex_list[v]->moveToStart();
    return vertex_list[v]->getValue().vertex;
}

int ListGraph::next(int v1, int v2) {
    // v1,v2���ڽӵ���v2����v1�����һ���ڽӵ�
    // ����isEdge()���Ὣcurrָ��ͣ����v2����������ڣ�
    if (isEdge(v1, v2) && vertex_list[v1]->currPos() + 1 < vertex_list[v1]->length()) {
        vertex_list[v1]->next();
        return vertex_list[v1]->getValue().vertex;
    } else return vertex_num;
}

void ListGraph::setEdge(int v1, int v2, int weight) {
    if (weight <= 0) throw StringException("ListGraph::setEdge()==> weight must be positive");
    vertex_list[v1]->moveToStart();
    for (int i = 0; i < vertex_list[v1]->length(); ++i) {
        auto curr = vertex_list[v1]->getValue().vertex;
        if (curr == v2) {
            vertex_list[v1]->remove();
            vertex_list[v1]->insert(Edge(v2, weight));
            return;
        }
        else if (curr > v2) break; // ע��������break
        vertex_list[v1]->next();
    }
    // �����������������Ϊ0ʱ���Լ�v2�Ǳ������Ԫ��
    edge_num ++;
    vertex_list[v1]->insert(Edge(v2, weight));
}

void ListGraph::delEdge(int v1, int v2) {
    if (isEdge(v1, v2)) {
        edge_num --;
        vertex_list[v1]->remove();
    }
}

bool ListGraph::isEdge(int v1, int v2) {
    vertex_list[v1]->moveToStart();
    for (int i = 0; i < vertex_list[v1]->length();  ++i){
        if (vertex_list[v1]->getValue().vertex == v2) return true;
        vertex_list[v1]->next();
    }
    return false;
}

int ListGraph::getWeight(int v1, int v2) {
    if (isEdge(v1, v2)) return vertex_list[v1]->getValue().weight;
    return 0;
}

int ListGraph::getMark(int v) {
    return mark_list[v];
}

void ListGraph::setMark(int v, int mark) {
    mark_list[v] = mark;
}
