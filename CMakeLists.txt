cmake_minimum_required(VERSION 3.20)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/algorithm/*.c"
        "${PROJECT_SOURCE_DIR}/algorithm/*.cpp"
        "${PROJECT_SOURCE_DIR}/algorithm/*.h"
        "${PROJECT_SOURCE_DIR}/dataStructures/*.c"
        "${PROJECT_SOURCE_DIR}/dataStructures/*.cpp"
        "${PROJECT_SOURCE_DIR}/dataStructures/*.h"
        "${PROJECT_SOURCE_DIR}/util/*.c"
        "${PROJECT_SOURCE_DIR}/util/*.cpp"
        "${PROJECT_SOURCE_DIR}/util/*.h")

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SRC_FILES})
#add_executable(algorithm main.cpp dataStructures/list/List.h dataStructures/list/LinkedList.cpp dataStructures/list/LinkedList.h dataStructures/list/ArrayList.cpp dataStructures/list/ArrayList.h dataStructures/node/Node.h dataStructures/list/tool.h util/StringException.h dataStructures/node/NodeWithPool.h dataStructures/node/DoublyNode.h dataStructures/list/DoublyLinkedList.cpp dataStructures/list/DoublyLinkedList.h dataStructures/stack/Stack.h dataStructures/stack/ArrayStack.cpp dataStructures/stack/ArrayStack.h dataStructures/stack/tool.h dataStructures/stack/LinkedStack.cpp dataStructures/stack/LinkedStack.h dataStructures/queue/Queue.h dataStructures/queue/ArrayQueue.cpp dataStructures/queue/ArrayQueue.h dataStructures/queue/LinkedQueue.cpp dataStructures/queue/LinkedQueue.h dataStructures/dictionary/Dictionary.h dataStructures/bin_node/BinNode.h dataStructures/list/CircularLinkedList.cpp dataStructures/list/CircularLinkedList.h dataStructures/list/DoublyCircularLinkedList.cpp dataStructures/list/DoublyCircularLinkedList.h dataStructures/bin_node/tool.h dataStructures/bin_node/BSTNode.h dataStructures/bin_node/leaf_and_intl_1.h dataStructures/bin_node/leaf_and_intl_2.h dataStructures/bin_tree/ArrayCBT.h dataStructures/bin_tree/BinarySearchTree.cpp dataStructures/bin_tree/BinarySearchTree.h dataStructures/dictionary/KVPair.h dataStructures/dictionary/UALDict.h dataStructures/list/SortedArrayList.h dataStructures/dictionary/SALDict.h dataStructures/heap/Heap.cpp dataStructures/heap/Heap.h dataStructures/bin_node/HuffNode.h dataStructures/bin_node/LeafNode.h dataStructures/bin_node/IntlNode.h dataStructures/bin_tree/HuffTree.h util/Compare.h dataStructures/tree/GTNode.h dataStructures/tree/GTree.h util/Timer.h util/Comparable.h util/baseType.h algorithm/sort/Sort.cpp algorithm/sort/Sort.h util/Counter.h util/pretty_print.h util/list_tool.h algorithm/search/search.h algorithm/index/index.h algorithm/sort/inner_sort.h dataStructures/graph/Graph.h dataStructures/graph/MatrixGraph.cpp dataStructures/graph/MatrixGraph.h dataStructures/graph/ListGraph.cpp dataStructures/graph/ListGraph.h algorithm/graph/graphs.h)
