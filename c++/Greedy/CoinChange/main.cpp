//
// Created by sebas on 08/09/2026.
//

#include <vector>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>

using namespace std;

int greedyCoinChange(vector<int> coins,int change) {

     int left = 0;
     int right = coins.size() - 1;
     sort(coins.begin(),coins.end());
     int coinsUsed = 0;

     while (right >= 0 && change > 0) {

          if (change >= coins[right] && (change - coins[right]) >= 0) {
               change -= coins[right];
               coinsUsed++;
          }
          else {
               right--;
          }

          if (change == 0) {
               break;
          }
     }

     return (change == 0) ? coinsUsed : -1;

}

//Video Reference: https://www.youtube.com/watch?v=KnWorqyDSLA

int dynammicProgrammingCoinChange(vector<int> coins, int change) {

     //Practicando Funciones modernas de unordered_map
     //Soy conciente de la ineficiencia del Map vs vector
     unordered_map<int,int> minCoinToMakeN;

     int size = coins.size();

     for (int i = 0 ; i <= change ; i++) { //Inicializa en inf o -1, o sea imposibles de crear
          minCoinToMakeN.try_emplace(i,-1);
     }

     minCoinToMakeN.insert_or_assign(0,0);

     for (int coinTurn = 0 ; coinTurn < size ; coinTurn++ ) {

          int coinType = coins[coinTurn];

          for ( int i = coinType ; i <= change ; i++) {

               if (minCoinToMakeN[i - coinType] != -1) {

                    int coinsUsed = minCoinToMakeN[i - coinType] + 1;

                    if (minCoinToMakeN[i] == -1 || coinsUsed < minCoinToMakeN[i]) {
                         minCoinToMakeN.insert_or_assign(i,coinsUsed);
                    }

               }



          }

     }

     return minCoinToMakeN[change];
}

int main() {

     int n = 0;
     cout<<"Ingrese el numero de valores que va a meter: ";
     cin>>n;

     vector<int> tiposDeCambio;

     cout<<"\nIngrese la lista de monedas/billetes vas a  usar: ";

     for ( int i = 0 ; i < n ; i++) {
          int value;
          while (true) {

               cout<<"Ingresa el tipo: "<< i+1 <<" de cambio: ";


               if (cin >> value && value > 0) {

                    tiposDeCambio.push_back(value);
                    break;
               }

               else {
                    cout<< "Mete solo valores enteros positivos\n";
                    cin.clear(); // limpia el estado del cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Limpia el buffer

               }

               tiposDeCambio.push_back(value);
               cout<<"Valor: "<<value<<" correctamente insertado\n";
               break;
          }
     }

     cout<<"Estos son tus monedas infinitas disponibles: {";

     for (int x : tiposDeCambio) {
          cout<<x<<" ";
     }
     cout<<"}\n";

     cout<<"El total a pagar es: ";
     int p;
     cin>>p;


     cout<<"\nCon cuanto vas a pagar?(No se fia, asi que paga mas que lo que tienes que pagar): ";
     int q;
     cin>>q;

     while (p > q) {
          cout<<"Con eso me quedas debiendo; mira, tienes que pagar: "<<p<<" y me estas dando: "<<q<< " checa tus mates\n";
          cout<<"Con cuanto me vas a pagar ahora si: ";
          cin>>q;
     }

     const int change = q - p;

     cout<<"\nEl cambio a devolver es: {"<<change<<"} y el minimo de monedas que se necesita para contruir el cambio es: \n";
     cout<<"Segun el approach Greedy: ";
     int coinsUsed = greedyCoinChange(tiposDeCambio, change);
     cout<<coinsUsed;
     cout<<"\nSegun el approach Dp: ";
     coinsUsed = dynammicProgrammingCoinChange(tiposDeCambio, change);
     cout<<coinsUsed;
     return 0;
};

