#include <iostream>
#include <memory>
using namespace std;

class Buffer {
public:
    Buffer(size_t size) : size_(size) {
        data_ = new float[size_];
        cout << "Buffer created" << endl;
    }

    ~Buffer() {
        delete[] data_;
        cout << "Buffer destroyed" << endl;
    }

private:
    float* data_;
    size_t size_;
};

int main() {
    {
        unique_ptr<Buffer> p1 = make_unique<Buffer>(1024);
    }

    {
        shared_ptr<Buffer> p2 = make_shared<Buffer>(2048);
        shared_ptr<Buffer> p3 = p2;
        cout << "use_count = " << p2.use_count() << endl;
    }

    return 0;
}