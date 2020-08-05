#include <any>
#include <iostream>
#include <mutex>
#include <string>

#include <cassert>

struct SomeStruct {
	int value;
};

std::ostream& operator<<(std::ostream& os, const SomeStruct& value) {
	os << "SomeStruct with value = " << value.value << std::endl;
	return os;
}

#pragma region (Usage)
struct SomeInternalStruct {
	SomeInternalStruct(const std::string& value) 
		: m_value(value) {

		}

	void doSomethingStrange() const {
		std::cout << "My value = " << m_value << std::endl;
	}
private:
	std::string m_value;
};

// target.h
void target(const std::any& value);


void source(const std::string& value) {
	auto any = std::make_any<SomeInternalStruct>(value);
	target(any);
}

// target.cpp
void target(const std::any& value) {
	const auto& casted = std::any_cast<SomeInternalStruct>(value);
	casted.doSomethingStrange();
}
#pragma endregion

int main() {

	std::any any = 10; // int
	// compile error - no operator<< for std::any
	// std::cout << any << std::endl;
	std::cout << std::any_cast<int>(any) << std::endl;
	std::cout << any.type().name() << std::endl;
	std::cout << std::endl;

	any = 2.71828f; // float
	try {
		std::cout << std::any_cast<int>(any) << std::endl;
	}
	catch(const std::bad_any_cast& ex) {
		std::cout << "int cast exception! " << ex.what() << std::endl;
	}
	try {
		std::cout << std::any_cast<double>(any) << std::endl;
	}
	catch(const std::bad_any_cast& ex) {
		std::cout << "double cast exception! " << ex.what() << std::endl;
	}
	std::cout << std::any_cast<float>(any) << std::endl;
	std::cout << any.type().name() << std::endl;

	// We can take a reference also
	float &ref = std::any_cast<float&>(any);
	// And change the value
	ref += 42;
	std::cout << std::any_cast<float>(any) << std::endl;

	// We can take a pointer. And it is noexcept.
	float* ptr = std::any_cast<float>(&any);
	std::cout << *ptr << std::endl;

	char* wrongPtr = std::any_cast<char>(&any);
	assert(wrongPtr == nullptr);

	std::cout << std::endl;

	any = "trololo"; // char []
	try {
		std::cout << std::any_cast<char*>(any) << std::endl;
	}
	catch(const std::bad_any_cast& ex) {
		std::cout << "char* cast exception! " << ex.what() << std::endl;
	}
	std::cout << std::any_cast<const char*>(any) << std::endl;
	std::cout << any.type().name() << std::endl;
	std::cout << std::endl;

	any = std::string("Hello, world!"); // std::string
	std::cout << std::any_cast<std::string>(any) << std::endl;
	std::cout << any.type().name() << std::endl;
	std::cout << std::endl;

	any = SomeStruct{42}; // SomeStruct
	std::cout << std::any_cast<SomeStruct>(any) << std::endl;
	std::cout << any.type().name() << std::endl;
	std::cout << std::endl;

	// Just create a string
	std::any anyWithString{ std::in_place_type<std::string>, "trololo" };

	// Create a temporary string and then move it into the any
	std::any anyWithString2{ std::string{"trololo"} };

	return 0;
}