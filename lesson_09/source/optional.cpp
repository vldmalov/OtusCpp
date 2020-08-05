#include <iostream>
#include <optional>
#include <string>

struct Employee {
	Employee(
		const std::string& first,
		const std::optional<std::string> middle,
		const std::string last)
	:
		m_firstName{first}
		, m_middleName{middle}
		, m_lastName{last}
	{

	}

	std::string getName() const {
		return m_firstName;
	}

	std::optional<std::string> getMiddle() const {
		return m_middleName;
	}

	std::string getLast() const {
		return m_lastName;
	}

private:
	std::string m_firstName;
	std::optional<std::string> m_middleName;
	std::string m_lastName;
};

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
	os << "First name - " << employee.getName() << std::endl;
	if (auto middle = employee.getMiddle())
		os << "Middle name - " << middle.value() << std::endl;
	os << "Last name - " << employee.getLast() << std::endl;
	return os;
}

int main() {

	Employee employee{
		"First", {}, "Last"
	};
	Employee employee2{
		"Ivan", "Petrovich", "Sidorov"
	};

	std::cout << employee << std::endl;
	std::cout << employee2 << std::endl;

	// Compile error - no operator<< for std::optional
	// std::cout << "MiddleName = " << employee.getMiddle() << std::endl;
	std::cout << "Middle name = " << employee.getMiddle().value_or("none") << std::endl;

	std::cout << std::make_optional<std::string>("Param Pam Pam").value() << std::endl;

	return 0;
}