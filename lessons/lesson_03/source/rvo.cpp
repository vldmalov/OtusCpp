#include <iostream>
#include <string>

// Helper class to trace methods
struct Tracer {
    Tracer() : m_name("empty") {
        std::cout << "default ctor" << std::endl;
    }

    explicit Tracer(const std::string& str) : m_name(str) {
        std::cout << "ctor " << m_name << std::endl;
    }

    Tracer(const Tracer& rhs) {
        std::cout << "copy ctor from " << rhs.m_name << " to " << m_name << std::endl;
        m_name = rhs.m_name;
    }

    // Tracer(Tracer&& rhs) {
    //    std::cout << "move ctor from " << rhs.m_name << std::endl;
    //    m_name = std::move(rhs.m_name);
    // }

    ~Tracer() {
        std::cout << "dtor " << m_name << std::endl;
    }

    Tracer& operator=(const Tracer& rhs) {
        std::cout << "copy assign from " << rhs.m_name << " to " << m_name << std::endl;
        m_name = rhs.m_name;
        return *this;
    }

    // Tracer& operator=(const Tracer& rhs) = delete;

    //Tracer& operator=(Tracer&& rhs) {
    //    std::cout << "move assign from " << rhs.m_name << std::endl;
    //    m_name = std::move(rhs.m_name);
    //    return *this;
    //}
private:
    std::string m_name;
};

// MOVE MAGIC
Tracer&& makeTracer1(const char* name) {
    return std::move(Tracer{name});
}

// RVO
Tracer makeTracer2(const char* name) {
   return Tracer{name};
}


// NRVO
Tracer makeTracer3(const char* name) {
    Tracer tracer{name};
    return tracer;
}

// RVO medium
Tracer makeTracer4(const char* name, int fake) {
    if (fake % 2) {
        return Tracer{name};
    }
    return Tracer{"other"};
}

// NRO medium
Tracer makeTracer5(const char* name, int fake) {
    if (fake % 2) {
        Tracer result1{name};
        return result1;
    }
    else {
        Tracer result2{"other"};
        return result2;
    }
}

int main(int argc, char* argv[]) {
    {
        // auto tracer1 = std::move(makeTracer1("1"));
        // const auto& tracer = std::move(akeTracer1("1"));
    }
    std::cout << "=======" << std::endl;
    {
        auto tracer2 = std::move(makeTracer2("2"));
    }
    std::cout << "=======" << std::endl;
    {
       auto tracer3 = std::move(makeTracer3("3"));
    }
    std::cout << "=======" << std::endl;
    {
        auto tracer4 = std::move(makeTracer4("4", 3));
    }
    std::cout << "=======" << std::endl;
    {
        auto tracer5 = std::move(makeTracer5("5", 98));
    }
    std::cout << "=======" << std::endl;
    return 0;
}

