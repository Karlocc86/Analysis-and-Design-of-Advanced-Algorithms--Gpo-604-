cmake_minimum_required(VERSION 4.2)
project(algoritmosAvanzados)

set(CMAKE_CXX_STANDARD 14)

# 1. QuickSort
add_executable(quickSort
        "c++/DivideAndConquer/SortAlgorithms/QuickSort/quickSort.cpp"
)

# 2. BinarySearch (fíjate que cuelga de SortAlgorithms según tu árbol)
add_executable(binarySearch
        "c++/DivideAndConquer/SortAlgorithms/SearchAlgorithms/binarySearch.cpp"
)

# 3. Greedy Dijkstra
add_executable(greedyDijkstra
        "c++/Greedy/GreedyDijkstra/greedyDijkstra.cpp"
)