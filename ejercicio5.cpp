//Dado un numero mostrar la suma de sus digitos 

#include <iostream>
#include <cstdlib>

using namespace std;

int suma_digitos(int n) {
    int suma = 0;
    while (n != 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int main() {
    int num;
    cin >> num;
    cout << suma_digitos(num) << endl;

    system("pause");

    return 0;
}
