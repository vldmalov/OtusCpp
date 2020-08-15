#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace from_one_secret_project {

    void getConfiguration(const std::string& path) {
        const std::string pathToMainConfig = 
            path + "/conf/main.conf";

        const std::string pathToConnectionConfig = 
            path + "/conf/connection.conf";

        const std::string pathToUIConfig = 
            path + "/conf/UI.conf";

        // do something with pathToMainConfig
        // do something with pathToConnectionConfig
        // do something with pathToUIConfig
    }

}


namespace old_good_homework {

    struct IpV4 {
        public:
            IpV4(const std::vector<std::string>& tokens) {
                // Is it DTY or WET ?
                byte0 = std::stoi(tokens.at(0));
                byte1 = std::stoi(tokens.at(1));
                byte2 = std::stoi(tokens.at(2));
                byte3 = std::stoi(tokens.at(3));
            }

            uint8_t getByte0() const { return byte0; }
            uint8_t getByte1() const { return byte1; }
            uint8_t getByte2() const { return byte2; }
            uint8_t getByte3() const { return byte3; }

        private:
            uint8_t byte0;
            uint8_t byte1;
            uint8_t byte2;
            uint8_t byte3;
    };

    void ip_filter() {

        using IP = std::vector<uint8_t>;
        using IPList = std::vector<IP>;

        IPList sourceIPList; // = readFromStream

        // sorting
        // std::sort(sourceIPList.begin(), sourceIPList.end());
        for (auto& ip : sourceIPList) {
            for(auto iter = ip.begin(); iter != ip.end(); ++iter) {
                if (iter != ip.begin())
                    std::cout << '.';
                std::cout << *iter;
            }
            std::cout << std::endl;
        }

        // first filtration
        // filter_by_first(sourceIPList, 1);
        for (auto& ip : sourceIPList) {
            for(auto iter = ip.begin(); iter != ip.end(); ++iter) {
                if (iter != ip.begin())
                    std::cout << '.';
                std::cout << *iter;
            }
            std::cout << std::endl;
        }

        // second filtration
        // ...   
    }
}

int main() {

    from_one_secret_project::getConfiguration("/dev/null");
    old_good_homework::ip_filter();

    return 0;
}