#ifndef ALGORITHM_NODEWITHPOOL_H
#define ALGORITHM_NODEWITHPOOL_H

#include <iostream>

template<typename E>
class NodeWithPool {
private:
    // 回收站，Stack结构
    static NodeWithPool<E>* freeList;
public:
    E data;
    NodeWithPool<E>* next;

    NodeWithPool(const E& data, NodeWithPool<E>* next = nullptr):data(data), next(next){}
    NodeWithPool(NodeWithPool<E>* next = nullptr):next(next) {}

    // 重载new
    // 重载operator new 必须返回void*
    void* operator new(size_t) {
        // 这里还可以进行一个优化：每次new获取100个空间
        if (freeList == nullptr) return ::new NodeWithPool<E>;//这里返回可以不添加类型
//        std::cout << "NodeWithPool::new::" << freeList->data << std::endl;//test
        NodeWithPool<E>* tmp = freeList;
        freeList = freeList->next;
        return tmp;
    }
    // 重载delete
    // void* 指针需要转换
    void operator delete(void* ptr) {
        // 这里不能：ptr = (NodeWithPool<E>*)ptr
        ((NodeWithPool<E>*)ptr)->next = freeList;
        freeList = (NodeWithPool<E>*)ptr;
//        std::cout << "NodeWithPool::delete" << ((NodeWithPool<E>*)ptr)->data<< std::endl;//test
    }
    static void poolShow() {
        std::cout << "NodePool[";
        NodeWithPool<E>* tmp = freeList;
        while(tmp != nullptr) {
            std::cout << tmp->data << ", ";
            tmp = tmp->next;
        }
        std::cout << "]" << std::endl;
    }
};

template<typename E>
NodeWithPool<E>* NodeWithPool<E>::freeList = nullptr;

#endif // ALGORITHM_NODEWITHPOOL_H