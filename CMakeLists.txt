cmake_minimum_required(VERSION 3.20)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp dataStructures/list/List.h dataStructures/list/LinkedList.cpp dataStructures/list/LinkedList.h dataStructures/list/ArrayList.cpp dataStructures/list/ArrayList.h dataStructures/node/Node.h dataStructures/list/tool.h util/StringException.h dataStructures/node/NodeWithPool.h dataStructures/node/DoublyNode.h dataStructures/list/DoublyLinkedList.cpp dataStructures/list/DoublyLinkedList.h dataStructures/stack/Stack.h dataStructures/stack/ArrayStack.cpp dataStructures/stack/ArrayStack.h dataStructures/stack/tool.h dataStructures/stack/LinkedStack.cpp dataStructures/stack/LinkedStack.h dataStructures/queue/Queue.h dataStructures/queue/ArrayQueue.cpp dataStructures/queue/ArrayQueue.h dataStructures/queue/LinkedQueue.cpp dataStructures/queue/LinkedQueue.h dataStructures/dictionary/Dictionary.h dataStructures/bin_node/BinNode.h dataStructures/list/CircularLinkedList.cpp dataStructures/list/CircularLinkedList.h dataStructures/list/DoublyCircularLinkedList.cpp dataStructures/list/DoublyCircularLinkedList.h dataStructures/bin_node/tool.cpp dataStructures/bin_node/BSTNode.h)
