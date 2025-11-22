#include "FileUtils.h"
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

// Creates a directory such as:
//    user_profiles_updated_20251120_183501
fs::path createOutputDirectory(const fs::path& inputRoot) {
    using namespace std;

    // Get current system time.
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);

    tm localTm{};
#ifdef _WIN32
    localtime_s(&localTm, &t);
#else
    localtime_r(&t, &localTm);
#endif

    // Format the timestamp.
    ostringstream oss;
    oss << "user_profiles_updated_" << put_time(&localTm, "%Y%m%d_%H%M%S");

    // The output folder sits next to the input folder.
    fs::path outputRoot = inputRoot.parent_path() / oss.str();
    fs::create_directories(outputRoot);

    return outputRoot;
}

// Read an entire file's content into a string.
bool readFile(const fs::path& inputPath, std::string& outContent) {
    std::ifstream in(inputPath);
    if (!in) return false;

    // Read all characters into the string.
    outContent.assign((std::istreambuf_iterator<char>(in)),
                      std::istreambuf_iterator<char>());
    return true;
}

// Write content into a file, creating folders if needed.
bool writeFile(const fs::path& outputPath, const std::string& content) {
    fs::create_directories(outputPath.parent_path());

    std::ofstream out(outputPath);
    if (!out) return false;

    out << content;
    return out.good();
}
