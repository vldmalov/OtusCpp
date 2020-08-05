#include <iostream>
#include <list>
#include <string>
#include <variant>
#include <vector>

#ifdef _MSC_VER 
	#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif


struct Visitor {
	void operator()(int) {
		std::cout << "Hello from Visitor with int!" << std::endl;
	}
	void operator()(double) {
		std::cout << "Hello from Visitor with double!" << std::endl;
	}
	void operator()(const std::string& ) {
		std::cout << "Hello from Visitor with std::string!" << std::endl;
	}
	void operator()(const std::vector<int>& ) {
		std::cout << "Hello from Visitor with std::vector<int>!" << std::endl;
	}
};

int main() {
	std::variant<int, double, std::string, std::vector<int>>
		superValue;

	superValue = 42;
	std::cout << "index = " << superValue.index() << std::endl;
	std::cout << std::get<int>(superValue) << std::endl;
	try {
		std::cout << std::get<double>(superValue) << std::endl;
	} catch(const std::bad_variant_access& ex) {
		std::cout << "get double exception! " << ex.what() << std::endl;
	}

	// compile error - variant index out of bounds
	// std::cout << std::get<char>(superValue) << std::endl;
	std::visit(Visitor{}, superValue);
	std::cout << std::endl;

	superValue = 42.0;
	std::cout << "index = " << superValue.index() << std::endl;
	try {
		std::cout << std::get<int>(superValue) << std::endl;
	} catch(const std::bad_variant_access& ex) {
		std::cout << "get int exception! " << ex.what() << std::endl;
	}
	std::visit(Visitor{}, superValue);
	std::cout << std::endl;

	superValue = "Hello, Vasia!";
	std::cout << "index = " << superValue.index() << std::endl;
	std::cout << std::get<std::string>(superValue) << std::endl;
	std::visit(Visitor{}, superValue);
	std::visit(
		[](auto&& arg) {
			using T = decltype(arg);
			if constexpr (std::is_same_v<T, int>)
				std::cout << "constexpr if and int";
			else if constexpr (std::is_same_v<T, double>)
				std::cout << "constexpr if and double";
			else if constexpr (std::is_same_v<T, std::string>)
				std::cout << "constepr if and std::string";
		},
		superValue
	);

	return 0;
}