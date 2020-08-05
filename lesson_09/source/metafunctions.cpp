#include <iostream>

namespace test {

	template<int V>
	struct abs {
		static const int value = V < 0 ? -V : V;
	};


	template<int V>
	struct fact {
		static_assert(V > 0);
		static const int value = V * fact<V-1>::value;
	};

	template<>
	struct fact<0> {
		static const int value = 1;
	};



	template<typename T>
	struct is_int {
			static const bool value = false;
	};
	
	template<>
	struct is_int<int> {
			static const bool value = true;
	};




	template<typename T>
	struct remove_const {
		using type = T;
	};

	template<typename T>
	struct remove_const<const T> {
		using type = T;
	};

}

namespace test2 {
	template<typename T>
	struct type_is {
		using type = T;
	};

	template<typename T>
	struct remove_const : type_is<T> {};

	template<typename T>
	struct remove_const<const T> : type_is<T> {};

	template<typename T>
	using remove_const_t = typename remove_const<T>::type;



	template<bool C, class T, class F>
	struct conditional : type_is<T> {};

	template<class T, class F>
	struct conditional<false, T, F>	: type_is<F> {};

	template<class T, class F>
	struct conditional<true, T, F>	: type_is<T> {};



	template<bool B, class T>
	struct enable_if : type_is<T> {};
	 
	template<class T>
	struct enable_if<false, T> {};


}

int main() {

	std::cout << "abs<10> = " << test::abs<10>::value << std::endl;
	std::cout << "abs<-10> = " << test::abs<-10>::value << std::endl;

	std::cout << "fact<11> = " << test::fact<11>::value << std::endl;
	// std::cout << "fact<-2> = " << test::fact<-2>::value << std::endl;

	return 0;
}