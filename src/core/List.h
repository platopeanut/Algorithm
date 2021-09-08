//
// Created by lenovo on 2021/9/7.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

namespace Peanut {

    template <typename E> class List {
    private:
        void operator= (const List&) {}
        List(const List&) = default;

    public:
        List() = default;
        virtual ~List() = default;

        virtual void clear() = 0;
        // �ڵ�ǰλ�ô����
        virtual void insert(const E& item) = 0;
        // �ڱ�β���
        virtual void append(const E& item) = 0;
        // ɾ����ǰλ��
        virtual E remove() = 0;
        // �ƶ���ǰλ��
        virtual void moveToStart() = 0;
        virtual void moveToEnd() = 0;
        virtual void moveToPos(int pos) = 0;
        virtual void prev() = 0;
        virtual void next() = 0;
        // ��ȡ��ǰλ��
        virtual int currPos() const = 0;
        // ��ȡ���Ա���
        virtual int length() const = 0;
        // ��ȡ��ǰλ�õ�ֵ
        virtual const E& getValue() const = 0;
    };
}


#endif //ALGORITHM_LIST_H
