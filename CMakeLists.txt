cmake_minimum_required(VERSION 4.2)
project(algoritmosAvanzados)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(quickSort
        "c++/DivideAndConquer/SortAlgorithms/QuickSort/quickSort.cpp"
)

add_executable(binarySearch
        "c++/DivideAndConquer/SearchAlgorithms/BinarySearch/binarySearch.cpp"
)

add_executable(greedyDijkstra
        "c++/Greedy/GreedyDijkstra/MyGraph.cpp"
        "c++/Greedy/GreedyDijkstra/MyGraph.h"
        c++/Greedy/GreedyDijkstra/main.cpp
        c++/Greedy/GreedyDijkstra/Dijkstra.cpp
        c++/Greedy/GreedyDijkstra/Dijkstra.h


)

add_executable(coinChange

        "c++/Greedy/CoinChange/main.cpp"


)

enable_testing()

add_executable(testDijkstra
        "c++/Greedy/GreedyDijkstra/MyGraph.cpp"
        "c++/Greedy/GreedyDijkstra/Dijkstra.cpp"
        "c++/Greedy/GreedyDijkstra/test_dijkstra.cpp"
)

add_test(NAME DijkstraTest COMMAND testDijkstra)

add_library(mergeSort
        "c++/DivideAndConquer/SortAlgorithms/MergeSort/mergeSort.cpp"
)

enable_testing()
add_executable(testMergeSort
        "c++/DivideAndConquer/SortAlgorithms/MergeSort/test_mergeSort.cpp"
)

target_link_libraries(testMergeSort PRIVATE mergeSort)
add_test(NAME MergeSortTest COMMAND testMergeSort)
