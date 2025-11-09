#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <algorithm>

void LogAnalyzer::analyzeFile(const std::string& filename, const std::vector<std::string>& keywords) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::cout << "Processing: " << filename << std::endl;

    std::string line;

    // TODO: Read each line.
    // For each keyword in 'keywords', check if it exists in the line.
    // If found, increment keywordCounts[keyword] (inside a mutex lock).
    while (std::getline(file, line)) {
        for (const auto& keyword : keywords) {
            if (line.find(keyword) != std::string::npos) {
                std::lock_guard<std::mutex> lock(countMutex);
                keywordCounts[keyword]++;
            }
        }
    }
}

void LogAnalyzer::printSummary() const {
    std::cout << "\n--- Keyword Summary ---\n";

    // TODO: Use std::for_each and a lambda to print keyword counts.

    const std::vector<std::string> order = {
        "[WARN]", "[ERROR]", "[FATAL]", "[INFO]", "[DEBUG]", "[TRACE]"
    };

    for (const auto& kw : order) {
        int val = 0;
        auto it = keywordCounts.find(kw);
        if (it != keywordCounts.end()) val = it->second;

        // In nhãn không ngoặc: WARN, ERROR, ...
        std::string label = kw.substr(1, kw.size() - 2);
        std::cout << label << ": " << val << "\n";
    }

    std::cout << "-----------------------\n";
}
