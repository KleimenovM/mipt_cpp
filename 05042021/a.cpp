#include <fstream>
#include <iostream>
#include <chrono>
#include <cstring>

class Vector {
public:
    Vector();
    ~Vector();
    void push_front(int elem);
    void push_back(int elem);
    void push_at(int at, int elem);
private:
    Vector content;
    int size;
    int cap;
};

Vector::Vector()
{
    this->size = 0;
    this->cap = 33;
    this->content = new int[33];
}

Vector::~Vector()
{
    delete this->content;
}

void Vector::push_front(int elem)
{
    if (this->size == this->cap) {
        int* to_delete = this->content;
        this->content = new int[this->cap * 2];
        this->cap *= 2;
        for (int i = 0; i < this->size; i++) {
            this->content[i] = to_delete[i];
        }
        delete to_delete;
    }

    this->content[this->size] = elem;
    this->size++;
}

void Vector::push_at(int at, int elem)
{
    if (this->size == this->cap) {
        int* to_delete = this->content;
        this->content = new int[this->cap * 2];
        this->cap *= 2;
        for (int i = 0; i < this->size; i++) {
            this->content[i] = to_delete[i];
        }
        delete to_delete;
    }

    for (int i = this->size; i > at; i--) {
        this->content[i] = this->content[i - 1];
    }
    this->content[at] = elem;
    this->size++;
}

void Vector::push_back(int elem) {
    int* to_delete = this->content;
    if (this->size == this->cap)
        this->cap *= 2;
    this->content = new int[this->cap];
    this->content[0] = elem;
    for (int i = 1; i < this->size + 1; i++) {
        this->content[i] = to_delete[i - 1];
    }
    size++;
    delete to_delete;
}

int main() {
    std::ofstream fout("results.csv");
    for (long int N = 500000; N < 10000000; N += 160000) {
        std::cout << "N = " << N << std::endl;
        Vector v;
        for (long int i = 0; i < N; i++) {
            v.push_front(i);
        }

        auto start = std::chrono::high_resolution_clock::now();
        v.push_back(42);
        auto end = std::chrono::high_resolution_clock::now();
        auto n_sec = end - start;
        fout << N << "," << n_sec.count() << std::endl;
        std::cout << "N = " << N << " done" << std::endl;
    }
    fout.close();
    std::cout << "end" << std::endl;

    return 0;
}
