//numero factorial

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;
    cin >> num;
    cout << factorial(num) << endl;

    system ("pause");

    return 0;
}