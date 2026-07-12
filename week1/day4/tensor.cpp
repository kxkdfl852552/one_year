#include <iostream>
#include <vector>
using namespace std;

class Tensor {
public:
    Tensor(size_t size) : size_(size), data_(new float[size]) {
        cout << "constructor" << endl;
    }

    ~Tensor() {
        delete[] data_;
        cout << "destructor" << endl;
    }

    Tensor(const Tensor& other) : size_(other.size_), data_(new float[other.size_]) {
        cout << "copy constructor" << endl;
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    Tensor(Tensor&& other) noexcept : size_(other.size_), data_(other.data_) {
        cout << "move constructor" << endl;
        other.size_ = 0;
        other.data_ = nullptr;
    }

private:
    size_t size_;
    float* data_;
};

int main() {
    Tensor a(1024);
    Tensor b = a;
    Tensor c = std::move(a);

    return 0;
}