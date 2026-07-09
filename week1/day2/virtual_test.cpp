#include <iostream>
using namespace std;

class Op{
public:

    Op() {
        cout << "Op constructor" << endl;
    }
    virtual void run(){
        cout << "Op run" << endl;
    }
    virtual ~Op(){
        cout << "Op destructor" << endl;
    }
};

class AddOp : public Op{
public:
    AddOp() {
        cout << "AddOp constructor" << endl;
    }
    void run() override{
        cout << "AddOp run" << endl;
    }
    virtual ~AddOp() override{
        cout << "AddOp destructor" << endl;
    }
};

int main(){
    Op* op = new AddOp();
    op->run();
    delete op;
    return 0;
}