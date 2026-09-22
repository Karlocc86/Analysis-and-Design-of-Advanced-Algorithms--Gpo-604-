#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
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

long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

bool allPermutationsAreValid(const vector<vector<int>> &result, const vector<int> &arr)
{
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    set<vector<int>> uniquePermutations;

    for (const vector<int> &perm : result)
    {
        if (perm.size() != arr.size())
        {
            return false;
        }

        vector<int> sortedPerm = perm;
        sort(sortedPerm.begin(), sortedPerm.end());

        if (sortedPerm != sortedArr)
        {
            return false;
        }

        uniquePermutations.insert(perm);
    }

    return uniquePermutations.size() == result.size();
}

void runTest(const string &name, const vector<int> &arr)
{
    vector<vector<int>> result = permutations(arr);
    long long expected = factorial((int)arr.size());
    bool countOk = (long long)result.size() == expected;
    bool validOk = allPermutationsAreValid(result, arr);

    cout << name << ": ";
    if (countOk && validOk)
    {
        cout << "OK (" << result.size() << " permutaciones)" << endl;
    }
    else
    {
        cout << "FALLO (se esperaban " << expected << ", se obtuvieron " << result.size()
             << ", validas: " << (validOk ? "si" : "no") << ")" << endl;
    }
}

int main()
{
    cout << "Ejecutando pruebas de permutations()" << endl;

    runTest("Arreglo vacio", {});
    runTest("Un elemento", {1});
    runTest("Dos elementos", {1, 2});
    runTest("Tres elementos", {1, 2, 3});
    runTest("Cuatro elementos", {1, 2, 3, 4});
    runTest("Numeros negativos y cero", {-1, 0, 1});
    runTest("Cinco elementos", {1, 2, 3, 4, 5});
    runTest("Global nums predefinido", nums);

    return 0;
}
