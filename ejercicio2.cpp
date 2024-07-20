//Dado tres numeros enteros, encuentra el mayor

#include <iostream>
#include <cstdlib>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int mayor = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    
    std::cout << mayor << std::endl;
    
    system("pause");
    
    return 0;
}
