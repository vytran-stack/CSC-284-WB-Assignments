#ifndef DIRECTORYPROCESSOR_H
#define DIRECTORYPROCESSOR_H

#include <filesystem>

namespace fs = std::filesystem;

// Walk through input directory, read each JSON file,
// transform it, and write the result to the output directory.
void processDirectory(const fs::path& inputRoot, const fs::path& outputRoot);

#endif
