#include "mergeSort.h"

#include <cassert>
#include <vector>

int main()
{
    assert(mergeSort({}).empty());
    assert((mergeSort({7}) == std::vector<int>{7}));
    assert((mergeSort({5, 2, 8, 1, 3}) == std::vector<int>{1, 2, 3, 5, 8}));
    assert((mergeSort({4, -1, 4, 0, -3}) == std::vector<int>{-3, -1, 0, 4, 4}));

    const std::vector<int> original = {3, 1, 2};
    mergeSort(original);
    assert((original == std::vector<int>{3, 1, 2}));

    return 0;
}