#include <cstring>
#include <iostream>
#include <string>

namespace basic {

    void func() {
        std::string value = "Hello, world!";
        
        // Ask data and make operation
        auto len = std::strlen(value.data());
        auto pos = std::strstr(value.data(), "world!");

        // Tell, what to do
        auto len2 = value.size();
        auto pos2 = value.find("world!");
    }

}

namespace middle {

    namespace bad {
        void alarm() {
            std::cout << "Alarm!" << std::endl;
        }

        struct TemperatureMetrics {
            double temperature;
        };

        struct Threshold {
            double threshold;
        };

        void checkTemperature(const TemperatureMetrics& metrics, const Threshold& threshold) {
            if (metrics.temperature >= threshold.threshold)
                alarm();
        }
    }

    namespace better {

        struct TemperatureMetrics {
            double temperature;
        };

        struct Threshold {
            double threshold;
        };

        struct TemperatureMonitor {
            public:
                void checkTemperature() {
                    if (metrics.temperature >= threshold.threshold)
                        alarm();
                }
            private:
                void alarm() {
                    std::cout << "Alarm!" << std::endl;
                }

                TemperatureMetrics metrics;
                Threshold threshold;
        };
    }

}

int main() {


    return 0;
}