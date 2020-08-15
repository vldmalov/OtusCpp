#include <iostream>
#include <string>
#include <type_traits>

#ifdef _MSC_VER 
	#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

namespace motivation {

	// C++11 example
	struct SomeStruct {

		// 1 problem
		explicit SomeStruct(const std::string& value)
			: m_string{value} {
				std::cout << "value ctor" << std::endl;
			}

		// 2 problem
		SomeStruct(const SomeStruct& other) {
			std::cout << "copy ctor" << std::endl;
			m_string = other.m_string;
		}

		template<typename TT>
		SomeStruct(TT&& value) 
			: m_string{std::forward<TT>(value)} {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			std::cout << "universal ctor" << std::endl;
		}

		const std::string& getString() {
			return m_string;
		}

	private:
		std::string m_string;
	};

	void example() {

		std::cout << "0. expect universal ctor here!" << std::endl;
		SomeStruct first{"trololo"};
		std::cout << std::endl;

		// 2 problem
		// std::cout << "3. expect copy ctor here!" << std::endl;
		// SomeStruct copy{first};
		// std::cout << std::endl;
		
		// 1 problem
		std::string value = "param";
		std::cout << "1. expect value ctor here!" << std::endl;
		const SomeStruct second{value};
		std::cout << std::endl;

		const std::string cvalue = "trololo";
		std::cout << "2. expect value ctor here!" << std::endl;
		SomeStruct third{cvalue};
		std::cout << std::endl;

		// 2 problem
		std::cout << "4. expect copy ctor here!" << std::endl;
		SomeStruct copy2{second};
		std::cout << std::endl;

	}

} // motivation


namespace sfinae {
		
	struct SomeStruct {

		template<typename TT, 
			typename Fake = 
				typename std::enable_if<
					!std::is_same<typename std::remove_reference<TT>::type, 
						SomeStruct>::value, void>::type
		>
		SomeStruct(TT&& value) : m_value{std::forward<TT>(value)} {

		}

		SomeStruct(const SomeStruct& other) : m_value{other.m_value} {

		}

		const std::string& getValue() const {
			return m_value;
		}

	private:
		std::string m_value;
		std::string m_value2;
	};

void example() {

		std::cout << "0. expect universal ctor here!" << std::endl;
		SomeStruct first{"trololo"};
		std::cout << std::endl;

		// 2 problem
		std::cout << "3. expect copy ctor here!" << std::endl;
		SomeStruct copy{first};
		std::cout << std::endl;
		
		// 1 problem
		std::string value = "param";
		std::cout << "1. expect value ctor here!" << std::endl;
		const SomeStruct second{value};
		std::cout << std::endl;

		const std::string cvalue = "trololo";
		std::cout << "2. expect value ctor here!" << std::endl;
		SomeStruct third{cvalue};
		std::cout << std::endl;

		// 2 problem
		std::cout << "4. expect copy ctor here!" << std::endl;
		SomeStruct copy2{second};
		std::cout << std::endl;

	}

} // sfinae

int main() {

	motivation::example();

	sfinae::example();

	return 0;
}
