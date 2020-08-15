#include <iostream>
#include <map>
#include <memory>
#include <string>

#include <cassert>

struct DefaultCtor {
    DefaultCtor() {
        std::cout << "default ctor" << std::endl;
    }

    DefaultCtor(const std::string& value) 
        : m_value{value} {
    }

    DefaultCtor(const DefaultCtor&) {
        std::cout << "copy ctor" << std::endl;
    }

    DefaultCtor(DefaultCtor&&) {
        std::cout << "move ctor" << std::endl;
    }

    DefaultCtor& operator=(const DefaultCtor& ) {
        std::cout << "copy operator=" << std::endl;
        return *this;
    }

    DefaultCtor& operator=(DefaultCtor&& ) {
        std::cout << "move operator=" << std::endl;
        return *this;
    }
private:
    std::string m_value;
};

struct NoDefaultCtor {
    NoDefaultCtor() = delete;

    NoDefaultCtor(const std::string& value) 
        : m_value{value} {
    }

    NoDefaultCtor(const NoDefaultCtor&) {
        std::cout << "copy ctor" << std::endl;
    }

    NoDefaultCtor(NoDefaultCtor&&) {
        std::cout << "move ctor" << std::endl;
    }

    NoDefaultCtor& operator=(const NoDefaultCtor& ) {
        std::cout << "copy operator=" << std::endl;
        return *this;
    }

    NoDefaultCtor& operator=(NoDefaultCtor&& ) {
        std::cout << "move operator=" << std::endl;
        return *this;
    }
private:
    std::string m_value;
};

void insert_or_assign() {
    using id_t = std::size_t;
    using name_t = DefaultCtor;

    std::map<id_t, name_t> clients;

    std::cout << "old way with DefaultCtor type:" << std::endl;
    // 1. requires default constructor
    // 2. returns only T& - not iterator
    clients[20] = std::string{"Vasia"};

    std::cout << std::endl;

    std::cout << "insert_or_assign way with DefaultCtor type:" << std::endl;
    // 1. no default constructor need
    // 2. iterator as a result
    auto iter = clients.insert_or_assign(20, std::string{"Vasia"});

    std::cout << std::endl;


    std::cout << "insert_or_assign way with NoDefaultCtor type:" << std::endl;
    std::map<id_t, NoDefaultCtor> values;
    // Compile error - no default constructor
    // values[10] = NoDefaultCtor{"trololo"};
    auto iter2 = values.insert_or_assign(20, NoDefaultCtor{"trololo"});

    std::cout << std::endl;
}


void try_emplace() {
    std::map<int, std::unique_ptr<std::string>> clients;

    auto ptr = std::make_unique<std::string>("Vasia");
    auto result1 = clients.emplace(20, std::move(ptr));
    assert(!ptr);

    auto ptr2 = std::make_unique<std::string>("Vasia");
    auto result2 = clients.emplace(20, std::move(ptr2));
    // assert(ptr2);
    // result2.first - iterator
    // result2.second - flag

    auto ptr3 = std::make_unique<std::string>("Vasia");
    auto result3 = clients.try_emplace(20, std::move(ptr3));
    assert(ptr3);
}



int main() {

    insert_or_assign();

    try_emplace();

    return 0;
}