#include "DirectoryProcessor.h"
#include "FileUtils.h"
#include "JsonTransformer.h"
#include "json.hpp"

#include <iostream>

using json = nlohmann::json;

void processDirectory(const fs::path& inputRoot, const fs::path& outputRoot) {

    // Recursively visit all files and subdirectories.
    for (const auto& entry : fs::recursive_directory_iterator(inputRoot)) {

        // Compute the relative path, so we can mirror it in the output folder.
        fs::path relative = fs::relative(entry.path(), inputRoot);
        fs::path outPath = outputRoot / relative;

        // Recreate directory structure (subfolders).
        if (entry.is_directory()) {
            fs::create_directories(outPath);
            continue;
        }

        // Only process .json files.
        if (entry.path().extension() == ".json") {
            std::cout << "Processing: " << entry.path() << "\n";

            std::string content;
            if (!readFile(entry.path(), content)) {
                std::cerr << "Failed to read file.\n";
                continue;
            }

            json j;
            try {
                j = json::parse(content);  // JSON parse
            } catch (const nlohmann::json::parse_error& e) {
                std::cerr << "\nInvalid JSON in file:\n  " << entry.path() << "\n";
                std::cerr << "  Error: " << e.what() << "\n\n";
                continue;
            }


            transformJson(j); // Apply rules

            std::string output = j.dump(4); // Pretty-print JSON with 4 spaces

            if (!writeFile(outPath, output)) {
                std::cerr << "Failed to write file.\n";
            }
        }
    }

    std::cout << "Completed processing all files.\n";
}
