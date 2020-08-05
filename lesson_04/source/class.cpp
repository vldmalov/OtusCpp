#include <iostream>
#include <vector>

struct foo
{
    foo() = delete;
    foo(int value) {
    }

    virtual ~foo() = default;

    foo & operator=(const foo& rhs) = default;

    virtual void m() = 0;
    virtual void n(int a, double b) {};
};

struct bar : foo
{
    bar() : foo(42) {

    }
    ~bar() = default;

    void m() override {};
    void n(int a, double b) override {};
//    void o() override {}; // only virtual member functions can be marked 'override'
};

int main(int, char *[]) {
    bar b;

    return 0;
}