//
// Created by Dmitriy on 23.10.2026.
//

#include "SmfLoader.hpp"

#include <charconv>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../files/FileUtilities.hpp"

namespace assignment::graphics
{
    VertexData SmfLoader::toVertexData(const char *filename)
    {
        const auto contents = files::FileUtilities::getFileContents(filename);
        auto vertexData = VertexData{};
        std::istringstream input(contents);
        std::string line;
        std::size_t lineNumber = 0;

        while (std::getline(input, line))
        {
            ++lineNumber;
            std::istringstream lineInput(line);
            std::string record;
            if (!(lineInput >> record) || record.starts_with('#'))
            {
                continue;
            }

            if (record == "v")
            {
                GLfloat x;
                GLfloat y;
                GLfloat z;
                if (!(lineInput >> x >> y >> z))
                {
                    throw std::runtime_error(
                        std::string(filename) + ":" + std::to_string(lineNumber) +
                        ": vertex must contain three coordinates"
                    );
                }

                vertexData.vertices.insert(vertexData.vertices.end(), {x, y, z});
            }
            else if (record == "f")
            {
                std::vector<GLuint> face;
                std::string indexToken;
                while (lineInput >> indexToken)
                {
                    if (indexToken.starts_with('#'))
                    {
                        break;
                    }

                    std::uint64_t index;
                    const auto [end, error] = std::from_chars(
                        indexToken.data(),
                        indexToken.data() + indexToken.size(),
                        index
                    );
                    if (error != std::errc{} || end != indexToken.data() + indexToken.size() ||
                        index == 0 || index - 1 > std::numeric_limits<GLuint>::max())
                    {
                        throw std::runtime_error(
                            std::string(filename) + ":" + std::to_string(lineNumber) +
                            ": face indices must be positive 1-based integers"
                        );
                    }

                    face.push_back(static_cast<GLuint>(index - 1));
                }

                if (face.size() < 3)
                {
                    throw std::runtime_error(
                        std::string(filename) + ":" + std::to_string(lineNumber) +
                        ": face must contain at least three indices"
                    );
                }

                for (std::size_t i = 1; i + 1 < face.size(); ++i)
                {
                    vertexData.elements.insert(
                        vertexData.elements.end(),
                        {face[0], face[i], face[i + 1]}
                    );
                }
            }
        }

        const auto vertexCount = vertexData.vertices.size() / 3;
        for (const auto index : vertexData.elements)
        {
            if (index >= vertexCount)
            {
                throw std::runtime_error(
                    std::string(filename) + ": face index refers to a missing vertex"
                );
            }
        }

        return vertexData;
    }
}
