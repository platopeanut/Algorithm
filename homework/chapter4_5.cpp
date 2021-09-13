// ��currָ��ǰλ��

// a):����
//template<typename E>
//void LinkedList<E>::insert(const E &item) {
//    // ����tail
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
// ɾ����ǰλ��

template<typename E>
E LinkedList<E>::remove() {
    // ������Ϊ0ʱ���׳��쳣
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
    // ��ͷѰ��curr��ǰһ�ڵ�
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
    // ���ݵ�ǰֵ
    E data = curr->data;
    delete curr;
    curr = tmp->next;
    cnt --;
    return data;
}



// ����ɾ��