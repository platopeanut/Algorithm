//
// Created by lenovo on 2021/9/7.
//

#ifndef ALGORITHM_ALIST_H
#define ALGORITHM_ALIST_H

#include "List.h"
#define defaultSize 1024

template <typename E>
class AList: public List<E> {
private:
    int maxSize;
    int listSize;
    int curr;
public:
    AList(int size = defaultSize);
    virtual ~AList();
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
};


#endif //ALGORITHM_ALIST_H
