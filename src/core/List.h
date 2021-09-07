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
        // 在当前位置处添加
        virtual void insert(const E& item) = 0;
        // 在表尾添加
        virtual void append(const E& item) = 0;
        // 删除当前位置
        virtual E remove() = 0;
        // 移动当前位置
        virtual void moveToStart() = 0;
        virtual void moveToEnd() = 0;
        virtual void moveToPos(int pos) = 0;
        virtual void prev() = 0;
        virtual void next() = 0;
        // 获取当前位置
        virtual int currPos() const = 0;
        // 获取线性表长度
        virtual int length() const = 0;
        // 获取当前位置的值
        virtual const E& getValue() const = 0;
    };
}


#endif //ALGORITHM_LIST_H
