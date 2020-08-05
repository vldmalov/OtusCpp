#include <filesystem>
#include <fstream>
#include <iostream>

/**
    Note: 
    use next compile option to compile:
    -lstdc++fs
    ex. Debian gcc8: g++ -std=c++17  ../filesystem.cpp -o filesystem -lstdc++fs
**/

namespace fs = std::filesystem;

int main() {    

    const fs::path currentDir = fs::current_path();

    std::cout << currentDir << std::endl;
    
    const fs::path someFile = currentDir / "subfolder" / "readme.txt";
    std::cout << someFile << std::endl;

    const fs::path otherFile = currentDir / "otherFolder/otherFile.txt";
    std::cout << otherFile << std::endl;

    // parent folder
    std::cout << otherFile.parent_path() << std::endl;
    // filename with extenstion
    std::cout << otherFile.filename() << std::endl;
    // filename only
    std::cout << otherFile.stem() << std::endl;
    // extension
    std::cout << otherFile.extension() << std::endl;

    const fs::path cyrillic = currentDir / L"директория/файл.txt";
    std::cout << cyrillic << std::endl;
    std::cout << cyrillic.u8string() << std::endl;


    const fs::path folder = currentDir / "folder";
    std::cout << "First exists: " << fs::exists(folder) << std::endl;
    try {
        fs::create_directories(folder);
    }
    catch (const fs::filesystem_error& e)
    {
        std::cout << "Exception! " << e.what() << '\n';
    }
    std::cout << "Second exists: " << fs::exists(folder) << std::endl;

    const fs::path wrongFolder = "/not_permitted";

    std::error_code errCode;
    fs::create_directories(wrongFolder, errCode);
    if (errCode) {
        std::cout << "Creation failed! " << errCode.message() << std::endl;
    }

    const fs::path file = folder / "file.txt";
    {
        std::ofstream stream(file.native());
        if (!stream.is_open()) {
            std::cout << "Failed to create file: " << file << std::endl;
        }
        else {
            stream << "Hello, World!" << std::endl;
        }
    }
    auto last_write_time = fs::last_write_time(file);

    // Does not compile - it is too easy for C++
    //std::cout << "last_write_time = " << last_write_time << std::endl;

    // Could be a compile time error (C++ - you know...)
    std::time_t cftime = decltype(last_write_time)::clock::to_time_t(last_write_time); // assuming system_clock
    std::cout << "last_write_time = " << std::asctime(std::localtime(&cftime)) << std::endl;

    // How to print last_write_time ???

    fs::remove(file);

    std::cout << "File exists after remove: " << fs::exists(file) << std::endl;

    return 0;
}