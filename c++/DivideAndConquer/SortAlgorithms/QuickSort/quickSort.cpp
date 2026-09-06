// Video de referencia = https://www.youtube.com/watch?v=WprjBK0p6rw
#include <vector>
#include <iostream>
using namespace std;

vector<int> list = {8, 2, 4, 7, 1, 3, 9, 6, 5, 10, 11, 12, 13, 14, 15};
int n = list.size() - 1;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &list, int left, int right)
{
    int pivot = list[right];
    int orange = left - 1;

    for (int green = left; green <= right; green++)
    {
        if (list[green] <= pivot)
        {
            orange++;
            if (green > orange)
            {
                swap(list[green], list[orange]);
            }
        }
    }
    return orange; // Regresamos la posicion donde quedo el pivote,
                   // se usa para dividir luego el arreglo
}

void quickSort(vector<int> &list, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(list, left, right); // Aqui queda el pivote, lo usamos para dividir lo demas
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

int main()
{

    cout << "Lista todavia no ordenada con el nesquick" << endl;
    for (int x : list)
        cout << x << " ";

    quickSort(list, 0, n);
    cout << "\nLa supuesta lista ordenada con quicksort=";
    for (int x : list)
        cout << x << " ";

    return 0;
}
