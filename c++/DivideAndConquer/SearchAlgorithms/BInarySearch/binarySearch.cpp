#include <iostream>
#include <random>
#include <cmath>
using namespace std;

random_device rd; //Semilla del sistema

mt19937 gen(rd()); //Motor Mersenne Twister

uniform_int_distribution<int> dist(0, 101); //Definir la distribuicion/limite

int target = dist(gen);


int binarySearch(int low, int high) {

    if (low <= high) {

        int mid = low + floor(high - low)/2;

        if (mid == target) {
            return mid;
        }else if (mid <= target) {
            return binarySearch(mid + 1, high);
        }
        else {
            return binarySearch(low, mid - 1);
        }

    }

    return -1;
}

int main() {

    cout<<"El numero a adivinar es:" << " " << target <<endl;
    int numeroEncontrado = binarySearch(0,100);

    cout<<"Se encontro el numero?\n si si, sera target en caso contrario sera -1: "<<numeroEncontrado <<endl;




    return 0;
}


