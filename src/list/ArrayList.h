//
// Created by lenovo on 2021/9/7.
//

#ifndef ALGORITHM_ARRAYLIST_H
#define ALGORITHM_ARRAYLIST_H

#include "List.h"
#define defaultSize 1024

namespace Peanut {

    template <typename E>
    class ArrayList: public List<E> {
    private:
        int maxSize;
        int listSize;
        int curr;
        E* listArray;
    public:
        ArrayList(int size = defaultSize);
        virtual ~ArrayList();
        virtual void clear();
        virtual void insert(const E& item);
        virtual void append(const E& item);
        virtual E remove();
        virtual void moveToStart();
        virtual void moveToEnd();
        virtual void moveToPos(int pos);
        virtual void prev();
        virtual void next();
        virtual int currPos() const;
        virtual int length() const;
        virtual const E& getValue() const;

        void show();
    };
}


#endif //ALGORITHM_ARRAYLIST_H
