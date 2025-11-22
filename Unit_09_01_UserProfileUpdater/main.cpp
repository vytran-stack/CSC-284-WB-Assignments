#include <iostream>
#include <filesystem>

#include "FileUtils.h"
#include "DirectoryProcessor.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./Program <path_to_user_profiles>\n";
        return 1;
    }

    fs::path inputRoot = argv[1];

    if (!fs::exists(inputRoot)) {
        std::cerr << "Input folder does not exist.\n";
        return 1;
    }
    if (!fs::is_directory(inputRoot)) {
        std::cerr << "Provided path is not a directory.\n";
        return 1;
    }

    fs::path outputRoot = createOutputDirectory(inputRoot);
    std::cout << "Output folder: " << outputRoot << "\n";

    processDirectory(inputRoot, outputRoot);

    return 0;
}
