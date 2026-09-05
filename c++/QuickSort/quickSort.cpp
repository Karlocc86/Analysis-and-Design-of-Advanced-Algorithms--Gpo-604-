//Video de referencia = https://www.youtube.com/watch?v=WprjBK0p6rw
#include <vector>
#include <iostream>
using namespace std;

vector<int> list = {8,2,4,7,1,3,9,6,5,10,11,12,13,14,15};
int n = list.size() - 1;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b= temp;
}

int conquer(vector<int>& list, int left, int right) {
    int pivot = list[right];
    int orange = left -1;

    for ( int green = left ; green <= right ; green++) {
        if (list[green] <= pivot) {
            orange++;
            if (green > orange) {
                swap(list[green], list[orange]);
            }
        }
    }
    return orange;
}


void divide(vector<int>& list, int left, int right) {
    if (left < right) {
        int pivot = conquer(list, left, right); // Aqui queda el pivote, lo usamos para dividir lo demas
        divide(list,left,pivot -1);
        divide(list,pivot + 1, right);
    }
}

int main() {


    cout<<"Lista todavia no ordenada con el nesquick"<<endl;
    for (int x : list) cout<<x<<" ";

    divide(list,0, n);
    cout<<"\nLa supuesta lista ordenada con quicksort=";
    for (int x : list) cout<< x<< " ";

    return 0;
}