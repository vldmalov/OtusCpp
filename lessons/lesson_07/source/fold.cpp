#include <iostream>
#include <string>

// C++11
// *************************************
namespace cpp11 {
    // Fake additional function to end the recursion.
    void printAll() {
        std::cout << std::endl;
    }

    template<typename T, typename... Args>
    void printAll(T head, Args... args) {
        std::cout << head << ' ';
        printAll(args...);
    }

    // printAll(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7ul, 8ull);


    // C++11
    // *************************************

    // No a so fake additional function to end the recursion.
    template<typename T>
    T sumAll(T last) {
        return last;
    }
    template<typename T, typename... Args>
    auto sumAll(T head, Args... args) {
        return head + sumAll(args...);
    }

    // sumAll(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    // sumAll(1, 2.0, 3.0f, 4, 5, 6, 7, 8, 9, 10)
    // sumAll(std::to_string(1), std::to_string(2), std::to_string(3)) 


    // And one more C++11
    // *************************************
    // Really fake function...
    template<typename... Args>
    void sumAll_2_fake_function(Args&&... ) {

    }
    template<typename T, typename... Args>
    auto sumAll_2(T head, Args... args) {
        T sum = head;
        // Wrong code!
        // 1. sequence point problem
        // 2. undefined execution order
        sumAll_2_fake_function((sum += args)...); 

        /*
            For this function call:
            sumAll_2(1, 2, 3, 4) 

            it will expanded like this:
            sumAll_2_fake_function(
                (sum + 1),
                (sum + 2),
                (sum + 3),
                (sum + 4)
            );
        */

        return sum;
    }

    // sumAll_2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) 
    // sumAll_2(std::to_string(1), std::to_string(2), std::to_string(3)) 


    void example() {
        std::cout << "******************************" << std::endl;
        std::cout << "cpp11::example()" << std::endl;

        std::cout << R"(printAll(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7, 8, 9, 10))" << std::endl;
        printAll(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7, 8, 9, 10);
        std::cout << std::endl;

        std::cout << R"(sumAll(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))" << std::endl;
        std::cout << "sumAll = " << sumAll(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
        std::cout << std::endl;
        
        std::cout << R"(sumAll(1, 2.0, 3.0f, 4, 5, 6, 7, 8, 9, 10))" << std::endl;
        std::cout << "sumAll = " << sumAll(1, 2.0, 3.0f, 4, 5, 6, 7, 8, 9, 10) << std::endl;
        std::cout << std::endl;
        
        std::cout << R"(sumAll(std::to_string(1), std::to_string(2), std::to_string(3)))" << std::endl;
        std::cout << "sumAll = " 
                << sumAll(std::to_string(1), std::to_string(2), std::to_string(3)) 
                << std::endl << std::endl;
        std::cout << std::endl;

        // Error here - no operator+ for const char* type.
        // std::cout << "sumAll = " << sumAll("1", "2", "3", "4", "5") << std::endl;

        std::cout << R"(sumAll_2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))" << std::endl;
        std::cout << "sumAll_2 = " << sumAll_2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
        std::cout << std::endl;

        std::cout << R"(sumAll_2(1, 2.0, 3.0f, 4, 5, 6, 7, 8, 9, 10))" << std::endl;
        std::cout << "sumAll_2 = " << sumAll_2(1, 2.0, 3.0f, 4, 5, 6, 7, 8, 9, 10) << std::endl;
        std::cout << std::endl;

        std::cout << R"(sumAll_2(std::to_string(1), std::to_string(2), std::to_string(3)))" << std::endl;
        std::cout << "sumAll_2 = " 
                << sumAll_2(std::to_string(1), std::to_string(2), std::to_string(3)) 
                << std::endl << std::endl;
        std::cout << std::endl;
        // Possible output:
        // sumAll_2 = 132
        // sumAll_2 = 123
        // sumAll_2 = 312
        // ...

        std::cout << std::endl << std::endl;
    }
} // namespace cpp11



// Utility class with overloaded operator+ and operator+=.
// Just prints argumets - which is left and which is right.
struct SumLog {
    int value;

    SumLog(int v) : value{v} {};

    SumLog operator+(const SumLog& other) {
        std::cout << "operator+ with this = " << value;
        std::cout << " and other = " << other.value << std::endl;
        SumLog tmp{*this};
        tmp.value += other.value;
        return tmp;
    }

    SumLog& operator+=(const SumLog& other) {
        std::cout << "operator+ with this = " << value;
        std::cout << " and other = " << other.value << std::endl;
        value += other.value;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& stream, const SumLog& value) {
    stream << value.value;
    return stream;
}



namespace cpp17_unary {
    // C++17
    // *************************************
    template<typename... Args>
    auto rightUnaryFold(Args... args) {
        // + - * / % ^ & | = < > << >> += -= *=
        // /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*
        return (args + ...);
    }

    // rightUnaryFold(1, 2, 3, 4, 5) 
    // return (args + ...); -> return (1 + (2 + (3 + (4 + 5))))


    template<typename... Args>
    auto leftUnaryFold(Args... args) {
        return (... + args);
    }

    // leftUnaryFold(1, 2, 3, 4, 5)
    // return (... + args); -> return ((((1 + 2) + 3) + 4) + 5)

    void example() {
        std::cout << "******************************" << std::endl;
        std::cout << "cpp17_unary example" << std::endl;


        std::cout << R"(rightUnaryFold(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))" << std::endl;
        std::cout << "rightUnaryFold = " << rightUnaryFold(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;


        std::cout << R"(rightUnaryFold(std::to_string(1), std::to_string(2), std::to_string(3)))" << std::endl;
        std::cout << "rightUnaryFold = " 
                << rightUnaryFold(std::to_string(1), std::to_string(2), std::to_string(3)) 
                << std::endl << std::endl;


        std::cout << R"(leftUnaryFold(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))" << std::endl;
        std::cout << "leftUnaryFold = " << leftUnaryFold(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
        std::cout << "leftUnaryFold = " 
                << leftUnaryFold(std::to_string(1), std::to_string(2), std::to_string(3)) 
                << std::endl << std::endl;


        std::cout << R"(rightUnaryFold(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5}))" << std::endl;
        std::cout << "rightUnaryFold = "
            << rightUnaryFold(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5})
            << std::endl << std::endl;
        // (1 + (2 + (3 + (4 + 5))))


        std::cout << R"(leftUnaryFold(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5}))" << std::endl;
        std::cout << "leftUnaryFold = "
            << leftUnaryFold(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5})
            << std::endl << std::endl;
        // ((((1 + 2) + 3) + 4) +  5);

        std::cout << std::endl << std::endl;
    }

} // namespace cpp17_unary


namespace cpp17_binary {
    /* **************************************

        + - * / % ^ & | = < > << >> += -= *=
        /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*

    ***************************************/
    template<typename... Args>
    void binaryFold(Args... args) {
        (std::cout << ... << args) << std::endl;
    }

    template<typename... Args>
    void binaryFold2(Args... args) {
        std::string result;
        (result += ... += std::to_string(args));
        std::cout << result << std::endl;
    }

    template<typename T, typename... Args>
    auto binaryFoldLeft(T sum, Args... args) {
        (sum += ... += args);
        return sum;
    }

    template<typename T, typename... Args>
    auto binaryFoldRight(T sum, Args... args) {
        (args += ... += sum);
        return sum;
    }

    void example() {
        std::cout << "******************************" << std::endl;
        std::cout << "cpp17_binary::example:" << std::endl;

        std::cout << R"(binaryFold(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7ul, 8ull))" << std::endl;
        binaryFold(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7ul, 8ull);
        std::cout << std::endl;


        std::cout << R"(binaryFold2(1, 2, 3, 4, 5, 6, 7, 8))" << std::endl;
        binaryFold2(1, 2, 3, 4, 5, 6, 7, 8);
        std::cout << std::endl;


        std::cout << R"(binaryFoldLeft(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5}))";
        std::cout << binaryFoldLeft(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5});
        std::cout << std::endl << std::endl;
        // ((((sum += 2) += 3) += 4) += 5);


        std::cout << R"(binaryFoldRight(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5}))";
        std::cout << binaryFoldRight(SumLog{1}, SumLog{2}, SumLog{3}, SumLog{4}, SumLog{5});
        std::cout << std::endl << std::endl;
        // (2 += (3 += (4 += (5 += sum))))

        std::cout << std::endl << std::endl;
    }

} // cpp17_binary

int main() {

    cpp11::example();

    cpp17_unary::example();

    cpp17_binary::example();

    return 0;
}