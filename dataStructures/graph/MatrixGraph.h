#ifndef ALGORITHM_MATRIXGRAPH_H
#define ALGORITHM_MATRIXGRAPH_H
#include "./Graph.h"
/**
 *  œ‡¡⁄æÿ’Û µœ÷Õº Adjacency Matrix
 */
class MatrixGraph: public Graph {
private:
    int vertex_num;
    int edge_num;
    int** matrix;
    int* mark_list;
public:

    MatrixGraph(int V) { init(V); }

    ~MatrixGraph() override;

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


#endif //ALGORITHM_MATRIXGRAPH_H
