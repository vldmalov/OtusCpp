#include <iostream>
#include <vector>

namespace motivation {

    struct Point {
        Point() = default;
        Point(int x, int y)
            : m_x{x}, m_y{y} {}
    private:
        int m_x;
        int m_y;
    };

    struct Line {
        Line(const Point& p1, const Point& p2)
            : m_p1{p1}, m_p2{p2} {

        }

        Point getP1() const { return m_p1; }
        Point getP2() const { return m_p2; }
    private:
        Point m_p1;
        Point m_p2;
    };

    void example() {
//        Line line( Point(), Point() );

        // o_O !? 
        // Compile error:
        // error: request for member 'getP1' in 'motivation::line', which is of non-class type 
        // 'motivation::Line(motivation::Point (*)(), motivation::Point (*)())'
        // Point p = line.getP1(); 

        // Now it works
        Line line2{ Point{}, Point{} };
        line2.getP1();
    }

}


void example1() {
    int i[4] = {1, 2, 3, 4};
    int j[] = {1, 2, 3, 4};
    int k[4] = {1, 2};
}

struct foo {
    int a{-1};
    int b{-2};
    int c{-3};
};

void example2() {
    std::cout << "\nexample2" << std::endl;

    foo f;

    std::cout << f.a << std::endl;
    std::cout << f.b << std::endl;
    std::cout << f.c << std::endl;

    foo f2{1, 2};

    std::cout << f2.a << std::endl;
    std::cout << f2.b << std::endl;
    std::cout << f2.c << std::endl;
}


struct bar {
    bar() = default;

    // bar(int a_, int b_) : a(a_ * 10), b(b_ * 10), c(30) {};
    // bar(std::initializer_list<int> il) : a(il.size()), b(0), c(0) {};

    int a{-1};
    int b{-2};
    int c{-3};
};

void example3() {
    std::cout << "\nexample3" << std::endl;

    bar value{1, 2};
    std::cout << value.a << std::endl;
    std::cout << value.b << std::endl;
    std::cout << value.c << std::endl;

    // bar value2(1, 2);
    // std::cout << value2.a << std::endl;
    // std::cout << value2.b << std::endl;
    // std::cout << value2.c << std::endl;

    // bar value3{1, 2, 3, 4, 7, 8, 9};
    // std::cout << value3.a << std::endl;
    // std::cout << value3.b << std::endl;
    // std::cout << value3.c << std::endl;
}

void example4() {
    std::vector<int> values(10, 0);
    std::vector<int> values2{10, 0}; // Hm...
}

int main(int, char *[]) {

    motivation::example();

    example1();

    example2();

    example3();

    example4();

    return 0;
}
