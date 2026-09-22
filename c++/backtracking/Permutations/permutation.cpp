#include <vector>
#include <iostream>
using namespace std;

vector<int> nums = {1, 2, 3};

void backtrack(vector<int> &path, int n, vector<vector<int>> &solution, vector<bool> &seen, vector<int> &arr)
{

    if (path.size() == n)
    {
        solution.push_back(path);
        return;
    }

    for (int i = 0; i < n; i++)
    {

        if (seen[i])
        {
            continue;
        }

        seen[i] = true;
        path.push_back(arr[i]);
        backtrack(path, n, solution, seen, arr);

        path.pop_back();
        seen[i] = false;
    }
}

vector<vector<int>> permutations(vector<int> arr)
{

    vector<vector<int>> solution;
    vector<int> path;
    vector<bool> seen(arr.size(), false);
    backtrack(path, arr.size(), solution, seen, arr);
    return solution;
}
