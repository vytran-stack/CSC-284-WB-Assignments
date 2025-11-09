#include "LogAnalyzer.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <log_directory>\n";
        return 1;
    }

    std::string folderPath = argv[1];
    LogAnalyzer analyzer;
     /* TODO: Add the rest of the error levels */
    std::vector<std::string> keywords = {"[WARN]", "[ERROR]", "[FATAL]", "[INFO]", "[DEBUG]", "[TRACE]"};
    std::vector<std::thread> threads;

    std::cout << "Analyzing folder: " << folderPath << "\n\n";
    // TODO: Use std::filesystem to iterate through all files in the folder.
    // For each file with ".log" extension:
    //   - Create a thread calling analyzer.analyzeFile(filename, keywords)
    //   - Store the thread in 'threads' vector.

    // TODO: Join all threads after launching.
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (!entry.is_regular_file()) continue;
        if (entry.path().extension() == ".log") {
            std::string filename = entry.path().string();
            threads.emplace_back([&analyzer, filename, &keywords]() {
                analyzer.analyzeFile(filename, keywords);
            });
        }
    }

    if (threads.empty()) {
        std::cout << "No .log files found in: " << folderPath << "\n";
    }

    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    analyzer.printSummary();

    std::cout << "\nAnalysis complete. Processed " << threads.size() << " file"
              << (threads.size() == 1 ? "" : "s") << ".\n";

    return 0;
}