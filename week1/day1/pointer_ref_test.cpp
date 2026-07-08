#include <iostream>
using namespace std;

void add_by_pointer(int* x) {
    if (x) {
        *x += 1;
    }
}

void add_by_reference(int& x) {
    x += 1;
}

void print_const_ref(const int& x) {
    cout << x << endl;
}

class Counter {
public:
    static int count;

    Counter() {
        count++;
    }

    static void print_count() {
        cout << "count = " << count << endl;
    }
};

int Counter::count = 0;

int main() {
    int a = 10;

    add_by_pointer(&a);
    add_by_reference(a);
    print_const_ref(a);

    Counter c1;
    Counter c2;
    Counter::print_count();

    return 0;
}
