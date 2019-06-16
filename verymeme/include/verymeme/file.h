#ifndef VERYMEME_FILE_H
#define VERYMEME_FILE_H

#include "verymeme/common.h"

std::string readFile(const std::string& filename, bool binary = false);

void writeFile(const std::string& filename, const std::string& data, bool binary = false);

std::string basename(const std::string& filename);

std::string stem(const std::string& filename);

void checkedChdir(const std::string& path);

#endif  // VERYMEME_FILE_H
