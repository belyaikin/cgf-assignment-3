//
// Created by Dmitriy on 18.10.26.
//

#pragma once
#include <string>

namespace assignment::file {
    class FileUtilities final
    {
    public:
        static std::string getFileContents(const char *filename);
    };
}
