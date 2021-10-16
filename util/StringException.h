//
// Created by lenovo on 2021/9/12.
//

#ifndef ALGORITHM_STRINGEXCEPTION_H
#define ALGORITHM_STRINGEXCEPTION_H

#include <exception>
class StringException: public std::exception {
private:
    const char* message;
public:
    StringException(const char* message): message(message) {}

    const char * what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override {
        return message;
    }
};



#endif //ALGORITHM_STRINGEXCEPTION_H
