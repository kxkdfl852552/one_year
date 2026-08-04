#include <iostream>
using namespace std;

int main() {
    int* p = new int[4];

    for (int i = 0; i <= 3; ++i) {
        p[i] = i;
    }

    delete[] p;

    cout << p[0] << endl;

    return 0;
}