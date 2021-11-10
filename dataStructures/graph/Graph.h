#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

/**
 *  图的ADT
 */

// mark数组的标志位
#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    void operator= (const Graph&) {}
    Graph(const Graph&) {}

public:
    Graph() {}
    virtual ~Graph() {}
    // 创建一个含有V个顶点但不含有边的图
    virtual void init(int V) = 0;
    // 顶点数
    virtual int V() = 0;
    // 边数
    virtual int E() = 0;
    // 返回v的第一个相邻顶点
    virtual int first(int v) = 0;
    // 返回v1的在v2后面第一个相邻顶点
    virtual int next(int v1, int v2) = 0;
    // 添加一条边
    virtual void setEdge(int v1, int v2, int weight) = 0;
    // 删除一条边
    virtual void delEdge(int v1, int v2) = 0;
    // v1,v2两个顶点是否相邻
    virtual bool isEdge(int v1, int v2) = 0;
    // v1,v2相关联的边的权重
    virtual int getWeight(int v1, int v2) = 0;
    // v的mark数组
    virtual int getMark(int v) = 0;
    // 设置v的mark数组
    virtual void setMark(int v, int mark) = 0;
};


#endif //ALGORITHM_GRAPH_H
