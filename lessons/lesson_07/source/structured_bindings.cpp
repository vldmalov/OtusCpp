#include <iostream>
#include <map>
#include <string>
#include <tuple>


#pragma region (map)
// std::map motivation
void func_map() {
	std::map<int, std::string> map;

	std::cout << "\nfunc_map()\n";
	{
		auto[ iter, inserted ] = map.emplace(0, "Petia");
		std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
		std::cout << "Inserted = " << inserted << std::endl;
	}
	{
		auto[ iter, inserted ] = map.emplace(0, "Petia");
		std::cout << "Key = " << iter->first << " Value = " << iter->second << std::endl;
		std::cout << "Inserted = " << inserted << std::endl;
	}
}
#pragma endregion (map)


#pragma region(POD)
// POD structure example
struct POD {
	int i;
	double d;
	std::string s;
};

void func_pod() {
	std::cout << "\nfunc_pod()\n";
	POD pod = {41, 2.0, "Vasia"};
	auto [i, d, s] = pod;
	std::cout << "i = " << i << " d = " << d << " s = " << s << std::endl;
	i = 42;
	d = 2.5;
	s = "Petia";
	std::cout << "i = " << pod.i << " d = " << pod.d << " s = " << pod.s << std::endl;
}
#pragma endregion (POD)


auto getTuple() {
	return std::tuple(41, 2.0, "Vasia");
}

void func_tuple() {
	std::cout << "\nfunc_tuple\n";
	std::string name;
	std::tie(std::ignore, std::ignore, name) = getTuple();
	std::cout << "name = " << name << std::endl;
}

#pragma region (WithPrivate)
// struct StructWithPrivate {
// 	StructWithPrivate(int a, int b, int c)
// 		: m_a(a), m_b(b), m_c(c) {

// 	}
// private:
// 	int m_a;
// 	int m_b;
// 	int m_c;
// };

// void func_private() {
// 	StructWithPrivate object{0,1,2};
// 	auto [a, b, c] = object;
// }
#pragma endregion


#pragma region (Employee)
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
auto get(const Employee&) = delete;
 
template <>
auto get<0>(const Employee& employee)
{
    return employee.getAge();
}
 
template <>
auto get<1>(const Employee& employee)
{
    return employee.getName();
}
 
template <>
auto get<2>(const Employee& employee)
{
    return employee.getSecondName();
}

void func_employee() {
	std::cout << "\nfunc_employee\n";
	Employee employee{42, "Petia", "Ivanofff"};
	auto [age, name, secondName] = employee;
	std::cout << "age = " << age << " name = " << name << " secondName = " << secondName << std::endl;
}
#pragma endregion(Employee)


int main() {
	func_map();

//	func_pod();

//	func_tuple();

//	func_employee();

	return 0;
}