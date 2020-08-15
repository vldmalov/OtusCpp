#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <mutex>
#include <string>
#include <tuple>
#include <vector>

#ifdef _MSC_VER 
    #define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

namespace basics {

    void func1() {

        int i = 1;
        char c = 'a';
        double d = 3.14;
        std::string s = "Hello!";

        [[maybe_unused]]
        auto tuple = std::tuple<int, char, double, std::string>{i, c, d, s};

        [[maybe_unused]]
        auto tuple2 = std::make_tuple(i, c, d, s);

        // Since C++17
        [[maybe_unused]]
        auto tuple3 = std::tuple{i, c, d, s};
    }

    void func2() {

        [[maybe_unused]]
        auto vec = std::vector<std::string>{"a", "b", "c", "d"};

        // Since C++17
        [[maybe_unused]]
        auto vec2 = std::vector{"a", "b", "c", "d"};
        // ... but with not the same result!

        [[maybe_unused]]
        auto vec3 = std::vector{std::string{"a"}, std::string{"b"}, std::string{"c"}, std::string{"d"}};
    }


    void func3() {
        std::mutex mutex;

        {
            std::lock_guard<std::mutex> lock{mutex};
            std::lock_guard<decltype(mutex)> lock2{mutex};
        }

        {
            std::lock_guard lock{mutex};
        }
    }

    void func4() {

        std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6};

        // C++11
        std::sort(vec.begin(), vec.end(), std::greater<int>());

        // C++14
        std::sort(vec.begin(), vec.end(), std::greater<>{});

        // C++17
        std::sort(vec.begin(), vec.end(), std::greater{});

    }

} // namespace basics

template<typename T>
struct SomeSuperClass {
    SomeSuperClass(T v) : m_value{v} {}
    
    T getValue() const { return m_value; }
private:
    T m_value;
};

template<typename T>
struct OtherSuperClass {
    OtherSuperClass(T value) : m_valuePtr{std::make_unique<T>(value)} {};

    T getValue() const { return *m_valuePtr; }

private:
    std::unique_ptr<T> m_valuePtr;
};


template<typename T>
struct Buffer {

    Buffer() = default;

    // Will be usefull soon
    // Buffer(const Buffer<int>& lhs) {
    // }

    Buffer(const std::initializer_list<T>& list) : m_buffer{list} {}

    template<typename Iterator>
    Buffer(Iterator begin, Iterator end) : m_buffer{begin, end} {};

    void print() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        for (const auto& v : m_buffer) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }

private:
    std::vector<T> m_buffer;
};

// Middle example
template<typename Iter>
Buffer(Iter begin, Iter end) -> Buffer<typename std::iterator_traits<Iter>::value_type>;

// Hard example
template<typename T>
Buffer(const Buffer<T>& ) -> Buffer<char>;


int main() {
    Buffer buffer{0, 1, 2, 3, 4, 5, 6}; 
    // Call Buffer(const std::initializer_list<T>& list) - it is too easy for the compiler.
    buffer.print();

    std::vector<int> values = {6, 5, 4, 3, 2, 1, 0};
    Buffer buffer3(values.cbegin(), values.cend());
    // Oops... We don-t know a values type. We know only iterator type!
    // So, use deduction guide here:
    // Buffer(Iter begin, Iter end) -> Buffer<typename std::iterator_traits<Iter>::value_type>;
    buffer3.print();

    // Hard example
    // Will not compile.
    // Buffer<char>(const Buffer<int>& ) required

    // Buffer buffer2 = buffer;
    // buffer2.print();

    return 0;
}
