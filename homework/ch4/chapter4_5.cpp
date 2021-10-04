// 当curr指向当前位置

// a):插入
//template<typename E>
//void LinkedList<E>::insert(const E &item) {
//    // 更新tail
//    if (curr == tail) {
//        curr->next = new Node<E>(item, nullptr);
//        tail = curr->next;
//    } else {
//        curr->next = new Node<E>(curr->data, curr->next);
//        curr->data = item;
//    }
//    cnt ++;
//}

// b):
// 删除当前位置

template<typename E>
E LinkedList<E>::remove() {
    // 当长度为0时，抛出异常
    if (curr == nullptr) throw StringException("LinkedList::remove()==>No element");
    if (curr == head) {
        head = curr->next;
        E data = curr->data;
        delete curr;
        curr = head;
        cnt --;
        return data;
    }
    Node<E>* tmp = head;
    // 从头寻找curr的前一节点
    while (tmp->next != curr) {
        tmp = tmp->next;
    }
    if (curr == tail) {
        E data = curr->data;
        tail = tmp;
        tmp->next = nullptr;
        delete curr;
        curr = tail;
        cnt --;
        return data;
    }
    tmp->next = curr->next->next;
    // 备份当前值
    E data = curr->data;
    delete curr;
    curr = tmp->next;
    cnt --;
    return data;
}



// 连续删除