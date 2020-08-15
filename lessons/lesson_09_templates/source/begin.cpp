#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::pair<const int, std::string>& pair) {
	os << pair.first << "<->" << pair.second;
	return os;
}


template<typename Container>
void printContainter(const Container& values) {
	for (auto v : values)
		std::cout << v << ' ';
	std::cout << std::endl;
}


template<typename Container>
void sort(Container& values) {
	std::cout << "size = " << std::size(values) << std::endl;
	std::cout << (std::empty(values) ? "empty!" : "not empty!") << std::endl;
	std::sort(std::begin(values), std::end(values));
}

namespace basics {

	void example() {
		std::cout << "**************  basics::example  **************" << std::endl;

		int c_array[] = {3, 1, 4, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3};
		printContainter(c_array);

		std::vector<char> vector = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
		printContainter(vector);

		std::map<int, std::string> map = {
			{0, {}},
			{1, {'a'}},
			{2, {"ab"}},
			{3, {"abc"}}
		};
		printContainter(map);

		sort(c_array);
		printContainter(c_array);
		sort(vector);
		printContainter(vector);

		// compile error
		// sort(map);

		std::cout << std::endl << std::endl;
	}


} // namespace basics

namespace middle {
	struct VectorWrapper {
		using Iterator = std::vector<int>::iterator;
		using CIterator = std::vector<int>::const_iterator;

		VectorWrapper(const std::initializer_list<int>& input) 
			: m_values{input} {
		}

		Iterator getBegin() {
			return m_values.begin();
		}

		CIterator getBegin() const {
			return m_values.cbegin();
		}

		Iterator getEnd() {
			return m_values.end();
		}

		CIterator getEnd() const {
			return m_values.cend();
		}

		std::size_t getSize() const {
			return m_values.size();
		}

		bool getEmpty() const {
			return m_values.empty();
		}
	private:
		std::vector<int> m_values;
	};


	VectorWrapper::Iterator begin(VectorWrapper& wrapper) {
		return wrapper.getBegin();
	}

	VectorWrapper::Iterator end(VectorWrapper& wrapper) {
		return wrapper.getEnd();
	}

	VectorWrapper::CIterator begin(const VectorWrapper& wrapper) {
		return wrapper.getBegin();
	}

	VectorWrapper::CIterator end(const VectorWrapper& wrapper) {
		return wrapper.getEnd();
	}


	void example() {
		std::cout << "**************  middle::example  **************" << std::endl;

		VectorWrapper wrapper{0, 9, 2, 1, 7, 5, 4, 3, 8, 6};
		printContainter(wrapper);

		// Hm... What about std::begin or std::end??
		std::sort(wrapper.getBegin(), wrapper.getEnd());

		// https://en.cppreference.com/w/cpp/iterator/begin
		// template< class C >
		// constexpr auto begin( const C& c ) -> decltype(c.begin())

		printContainter(wrapper);
	}

}


int main() {
	basics::example();

	middle::example();

	return 0;
}