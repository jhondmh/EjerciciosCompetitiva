//Dado un numero determina si es par o impar

#include <iostream>
#include <cstdlib>

using namespace std;

int main (){
    int a;
    int resultado;
    cin >> a;
    cout << (a % 2 ? "El numero es impar" : "El numero es par") << endl;

    system ("pause");

}