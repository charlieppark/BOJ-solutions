#include <iostream>

int main() {
    long long a, b;
    
    using namespace std;
    cin >> a >> b;

    long long c;
    
    if (a >= b) {
        c = a - b;
    } else {
        c = b - a;
    }
    
    cout << c;
}