#include <iostream>
#include <vector>
using namespace std;

int get_value(vector<int>& v, int idx){
    return v[idx];
}

int run(){
    vector<int> data = {1, 2, 3};
    cout << get_value(data, 10) << endl;
}

int main() {
    run();
    return 0;
}