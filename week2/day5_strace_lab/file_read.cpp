#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream fin("not_exist.txt");

    if (!fin.is_open()) {
        cerr << "open file failed" << endl;
        return 1;
    }

    string line;
    getline(fin, line);
    cout << line << endl;

    return 0;
}