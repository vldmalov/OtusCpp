#include <iostream>
#include <vector>
#include <initializer_list>

struct Aggregate1 {
	int i;
	std::string s;
	float f;

	void print() {
		std::cout << "Aggregate{" << "i=" << i << ",s=" << s << ",f=" << f << "}" << std::endl;
	}
};

struct Aggregate2 {
	int i;
	std::string s;
	float f = 1.0; // C++14

	void print() {
		std::cout << "Aggregate{" << "i=" << i << ",s=" << s << ",f=" << f << "}" << std::endl;
	}
};

struct NonAggregate1 {
	NonAggregate1() = default;
	NonAggregate1(int i) : i{i}, s{""}, f{2.0} {}
	int i;
	std::string s;
	float f = 1.0;

	void print() {
		std::cout << "Aggregate{" << "i=" << i << ",s=" << s << ",f=" << f << "}" << std::endl;
	}
};

struct NonAggregate2 {
	NonAggregate2() = default;
	NonAggregate2(std::initializer_list<int> l) : i{} {}
	int i;
	std::string s;
	float f = 1.0;

	void print() {
		std::cout << "Aggregate{" << "i=" << i << ",s=" << s << ",f=" << f << "}" << std::endl;
	}
};

int main() {
	Aggregate1 agg1 = {42, "hello world", 3.5f};
	agg1.print();

	// C++14
	Aggregate2 agg2 = {42, "hello world"};
	agg2.print();

	// NonAggregate1 nonAgg1 = {42, "hello world", 3.5f};
}