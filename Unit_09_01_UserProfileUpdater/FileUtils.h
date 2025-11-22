#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

// Create an output directory with a timestamp in its name.
// This keeps the original folder untouched and organizes new results.
fs::path createOutputDirectory(const fs::path& inputRoot);

// Read an entire file into a string.
bool readFile(const fs::path& inputPath, std::string& outContent);

// Write a string into a file (creates parent directories if needed).
bool writeFile(const fs::path& outputPath, const std::string& content);

#endif

