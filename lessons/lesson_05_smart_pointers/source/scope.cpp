auto x = 42;

auto foo() {
    return x;
}

template<typename T>
auto bar(T y) {
    return x + y;
}

int main() {
    auto value = foo();
    auto value2 = bar(10);

    return 0;
}