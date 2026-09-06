cmake_minimum_required(VERSION 4.2)
project(algoritmosAvanzados)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. QuickSort
add_executable(quickSort
        "c++/DivideAndConquer/SortAlgorithms/QuickSort/quickSort.cpp"
)

# 2. BinarySearch (fíjate que cuelga de SortAlgorithms según tu árbol)
add_executable(binarySearch
        "c++/DivideAndConquer/SearchAlgorithms/BinarySearch/binarySearch.cpp"
)

# 3. Greedy Dijkstra
add_executable(greedyDijkstra
        "c++/Greedy/GreedyDijkstra/MyGraph.cpp"
        "c++/Greedy/GreedyDijkstra/MyGraph.h"
        c++/Greedy/GreedyDijkstra/main.cpp
        c++/Greedy/GreedyDijkstra/Dijkstra.cpp
        c++/Greedy/GreedyDijkstra/Dijkstra.h

)