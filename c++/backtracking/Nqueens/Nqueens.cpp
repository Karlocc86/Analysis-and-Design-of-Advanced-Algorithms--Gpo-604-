#include <unordered_set>
#include <vector>
using namespace std;
#include <cmath>
#include <iostream>
#include <map>
#include <string>

void backtrack(int r, int n, unordered_set<int> &col, unordered_set<int> &negDiag, unordered_set<int> &posDiag,
               vector<string> &board, vector<vector<string>> &result)
{

    if (r == n)
    {
        result.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++)
    {

        if (col.count(c) || negDiag.count(r - c) || posDiag.count(r + c))
        {
            continue;
        }

        col.insert(c);
        posDiag.insert(r + c);
        negDiag.insert(r - c);
        board[r][c] = 'Q';

        backtrack(r + 1, n, col, negDiag, posDiag, board, result);

        col.erase(c);
        negDiag.erase(r - c);
        posDiag.erase(r + c);
        board[r][c] = '.';
    }
}

unordered_set<int> col;
unordered_set<int> posDiag; // (r + c)
unordered_set<int> negDiag; // (r - c)

vector<vector<string>> solveMqueens(int n)
{

    unordered_set<int> cols;                 // Columnas
    unordered_set<int> posDiag;              // (r + c) approach que la pendiente positiva mantiene los valores (r + c) contantes
    unordered_set<int> negDiag;              // (r - c) approach que la pendiente negativa mantiene los valores (r - c) contantes
    vector<vector<string>> result;           // Vector de vectores de string para mostrar el tablero
    vector<string> board(n, string(n, '.')); // El tablero de n vectores de n caracteres '.'.

    backtrack(0, n, cols, negDiag, posDiag, board, result);
    return result;
}

int main()
{
    int n;
    cout << "Ingrese el tamano del tablero (n): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n debe ser un entero positivo." << endl;
        return 0;
    }

    vector<vector<string>> result = solveMqueens(n);

    cout << "Soluciones encontradas: " << result.size() << endl;

    if (!result.empty())
    {
        cout << "Primera solucion:" << endl;
        for (const string &fila : result[0])
        {
            cout << fila << endl;
        }
    }

    return 0;
}
