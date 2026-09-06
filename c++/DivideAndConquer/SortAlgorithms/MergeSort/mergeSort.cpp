//
// Created by sebas on 07/09/2026.
//

#include "mergeSort.h"

#include <vector>

std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right)
{

    std::vector<int> result;
    std::vector<int>::size_type i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {

        if (left[i] <= right[j])
        {

            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

std::vector<int> mergeSort(const std::vector<int> &arr)
{

    if (arr.size() <= 1)
        return arr;
    const auto mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}
