#include <iostream>
#include <map>
#include <string>
#include <tuple>

// Example1 - std::tie (C++11)
void example_map_tie() {
    std::cout << "example_map_tie" << std::endl;

    std::map<int, std::string> map;

    std::map<int, std::string>::iterator iter;
    bool inserted;
    std::tie(iter, inserted) = map.emplace(0, "Petia");

    std::cout << "First:" << std::endl;
    std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
    std::cout << "Inserted = " << inserted << std::endl;
    std::cout << std::endl;

    // std::ignore - iter does not needed here
    std::tie(std::ignore, inserted) = map.emplace(0, "Petia");

    std::cout << "Second:" << std::endl;
    std::cout << "Inserted = " << inserted << std::endl;
    std::cout << std::endl;
}

// int main() {
//     example_map_tie();

//     return 0;
// }



// Example2 - structured bindings with std::pair (C++17)
void example_map_bindings() {
    std::cout << "example_map_bindings" << std::endl;

    std::map<int, std::string> map;

    {
        // iter and iserted - simple variables
        auto [iter, inserted] = map.emplace(0, "Petia");

        std::cout << "First:" << std::endl;
        std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
        std::cout << "Inserted = " << inserted << std::endl;
        std::cout << std::endl;
    }

    {
        // 1. scope
        // 2. no ignore here
        
        auto [iter, inserted] = map.emplace(0, "Petia");

        std::cout << "Second:" << std::endl;
        std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
        std::cout << "Inserted = " << inserted << std::endl;
        std::cout << std::endl;
    }

    std::cout << "ranged for" << std::endl;
    map.emplace(1, "Vasia");
    map.emplace(2, "Irina");
    for(auto [key, value] : map) {
        std::cout << "Key = " << key << " Value = " << value << std::endl;
        value = "Petia";
    }
}

// int main() {
//     example_map_bindings();

//     return 0;
// }



// Example3 - structured bindings with POD (C++17)
// POD structure example
struct POD {
    int age;
    double koeff;
    std::string name;
};

void example_pod_bindings() {
    std::cout << "example_pod_bindings" << std::endl;

    {
        std::cout << "auto case:" << std::endl;

        POD pod = {
            41, 
            2.0, 
            "Vasia"
        };

        auto [a, k, n] = pod;        

        std::cout << "age = " << a << " koeff = " << k << " name = " << n << std::endl;

        a = 42;
        k = 2.5;
        n = "Petia";
        std::cout << "age = " << a << " koeff = " << k << " name = " << n << std::endl;
        std::cout << "age = " << pod.age << " koeff = " << pod.koeff << " name = " << pod.name << std::endl;
    }

    {
        std::cout << "auto& case:" << std::endl;

        POD pod = {
            41, 
            2.0, 
            "Vasia"
        };

        auto& [a, k, n] = pod;

        std::cout << "age = " << a << " koeff = " << k << " name = " << n << std::endl;

        a = 42;
        k = 2.5;
        n = "Petia";
        std::cout << "age = " << pod.age << " koeff = " << pod.koeff << " name = " << pod.name << std::endl;
    }

    {
        POD pod = {
            41, 
            2.0, 
            "Vasia"
        };

        const auto [a, k, n] = pod;
        // a = 42; // compile error because of const
    }
}

// int main() {
//     example_pod_bindings();

//     return 0;
// }




//Example4 - structured bindings with private (C++17)

// struct StructWithPrivate {
//     StructWithPrivate(int a, int b, int c)
//         : m_a(a), m_b(b), m_c(c) {

//     }
// private:
//     int m_a;
//     int m_b;
//     int m_c;
// };

// void example_private_bindings() {
//     StructWithPrivate object{0,1,2};
//     auto [a, b, c] = object;
// }

// int main() {
//     example_private_bindings();

//     return 0;
// }



// Example5 - structured bindings with private 2 (C++17)
struct Employee {
    Employee(std::size_t age, const std::string& name, const std::string& secondName)
        : m_age{age}, 
        m_name{name},
        m_secondName{secondName} {

        }

    std::size_t getAge() const { return m_age; }

    std::string getName() const { return m_name; }

    std::string getSecondName() const { return m_secondName; }

private:
    std::size_t m_age;
    std::string m_name;
    std::string m_secondName;
};

namespace std
{
    template<>
    struct tuple_size<Employee>
    {
        static constexpr size_t value = 3;
    };
}

namespace std
{
    template<>
    struct tuple_element<0, Employee>
    {
        using type = size_t;
    };
 
    template<>
    struct tuple_element<1, Employee>
    {
        using type = std::string;
    };
 
    template<>
    struct tuple_element<2, Employee>
    {
        using type = std::string;
    };
}

template <size_t Position>
auto get(Employee&) = delete;

// template <>
// auto get<0>(Employee& employee)
// {
//     return employee.getAge();
// }

// template <>
// auto get<1>(Employee& employee)
// {
//     return employee.getName();
// }

// template <>
// auto get<2>(Employee& employee)
// {
//     return employee.getSecondName();
// }

template<std::size_t Position>
auto get(const Employee& employee) {
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    if constexpr(Position == 0)
        return employee.getAge();
    else if constexpr(Position == 1)
        return employee.getName();
    else if constexpr(Position == 2)
        return employee.getSecondName();
    static_assert(Position >= 0 && Position <= 2, "Something wrong!");
}


void example_private_correct_bindings() {
    std::cout << "example_private_correct_bindings" << std::endl;

    Employee employee{42, "Petia", "Ivanofff"};
    
    auto [age, name, secondName] = employee;
    std::cout << "age = " << age << " name = " << name << " secondName = " << secondName << std::endl;

    age = 40;
    std::cout << "age = " << age << std::endl;
    std::cout << "employee.age = " << employee.getAge() << std::endl;
}

int main() {
    example_private_correct_bindings();

    return 0;
}

