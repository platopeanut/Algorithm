#include "MatrixGraph.h"
#include "../../util/StringException.h"

MatrixGraph::~MatrixGraph() {
    delete[] mark_list;
    for (int i = 0; i < vertex_num; ++i) delete[] matrix[i];
    delete[] matrix;
}

void MatrixGraph::init(int V) {
    this->vertex_num = V;
    this->edge_num = 0;
    // ����mark����
    this->mark_list = new int[this->vertex_num];
    // ��־λȫ����Ϊunvisited
    for (int i = 0; i < vertex_num; ++i) mark_list[i] = UNVISITED;
    // ����matrix����
    matrix = new int*[vertex_num];
    for (int i = 0; i < vertex_num; ++i)
        matrix[i] = new int[vertex_num];
    // ��matrix����Ԫ�أ���Ȩ�أ���Ϊ0
    for (int i = 0; i < vertex_num; ++i)
        for (int j = 0; j < vertex_num; ++j)
            matrix[i][j] = 0;
}

int MatrixGraph::V() {
    return vertex_num;
}

int MatrixGraph::E() {
    return edge_num;
}

int MatrixGraph::first(int v) {
    for (int i = 0; i < vertex_num; ++i)
        if (matrix[v][i] != 0) return i;
    return vertex_num;
}

int MatrixGraph::next(int v1, int v2) {
    // ��v2����һ��Ԫ���±꿪ʼ����
    for (int i = v2 + 1; i < vertex_num; ++i)
        if (matrix[v1][i] != 0) return i;
    return vertex_num;
}

void MatrixGraph::setEdge(int v1, int v2, int weight) {
    // ��֤weight������
    if (weight <= 0) throw StringException("MatrixGraph::setEdge()==> weight must be positive");
    if (matrix[v1][v2] == 0) edge_num ++;
    matrix[v1][v2] = weight;
}

void MatrixGraph::delEdge(int v1, int v2) {
    if (matrix[v1][v2] != 0) edge_num --;
    matrix[v1][v2] = 0;
}

bool MatrixGraph::isEdge(int v1, int v2) {
    return matrix[v1][v2] != 0;
}

int MatrixGraph::getWeight(int v1, int v2) {
    return matrix[v1][v2];
}

int MatrixGraph::getMark(int v) {
    return mark_list[v];
}

void MatrixGraph::setMark(int v, int mark) {
    mark_list[v] = mark;
}
