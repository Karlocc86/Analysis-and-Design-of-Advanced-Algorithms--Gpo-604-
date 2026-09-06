//
// Created by sebas on 07/09/2026.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> merge(const vector<int>& left , const vector<int>& right) {

    vector<int> result;
    int i =0 , j = 0;

    while (i < left.size() && j < right.size()) {


        if (left[i] <= right[j]) {

            result.push_back(left[i]);
            i++;
        }
        else {
            result.push_back(right[j]);
            j++;

        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

vector<int> mergeSort(const vector<int>& arr) {

    if (arr.size() <= 1) return arr;
    int mid = floor(arr.size()/2);
    vector<int> left (arr.begin(), arr.begin() + mid);
    vector<int> right (arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

vector<int> nums = {2,4,6,1,3,5,7,8,0,9,10};

int main() {

    cout<<"Lista no ordenada= ";
    for (int x : nums) cout <<x << " ";

    vector<int> result = mergeSort(nums);

    cout<<"\nLista ordenada= ";
    for (int x : result) cout <<x<<" ";

    return 0;
}