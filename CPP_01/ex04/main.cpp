#include <string>
#include <iostream>
#include <fstream>

#define ERROR_EXIT_FLAG 1
#define INVALID_ARGS_SIZE "Invalid number of arguments.\n"
#define USAGE "Usage: ./replace <file_name> <search> <replace>\n"
#define SOURCE_FILE_ERROR "Error opening source file"
#define OUTPUT_FILE_ERROR "Error opening output file"
#define FILE_EXTENSION ".replace"

void displayUsage() { std::cout << INVALID_ARGS_SIZE << USAGE; }

int handleErrorForIfstream(std::ifstream &file, const std::string &errorMsg) {
    std::cerr << errorMsg << std::endl;
    if (file.is_open())
        file.close();
    return ERROR_EXIT_FLAG;
}

int handleErrorForOfstream(std::ofstream &file, const std::string &errorMsg) {
    std::cerr << errorMsg << std::endl;
    if (file.is_open())
        file.close();
    return ERROR_EXIT_FLAG;
}

std::string replaceAllWithoutReplace(const std::string &line, const std::string &toFindToken, const std::string &toReplaceToken) {
    if (toFindToken.empty())
        return line;

    std::string result;
    result.reserve(line.length());

    std::string::size_type start_pos = 0;
    std::string::size_type pos;

    while ((pos = line.find(toFindToken, start_pos)) != std::string::npos) {
        result.append(line, start_pos, pos - start_pos);
        result += toReplaceToken;
        start_pos = pos + toFindToken.length();
    }
    result += line.substr(start_pos);
    return result;
}

int FindAndReplace(const std::string &toFindToken, const std::string &toReplaceToken, const std::string &dest_file_name)
{
    std::ifstream sourceFile(dest_file_name, std::ios::in);
    if (!sourceFile)
        return handleErrorForIfstream(sourceFile, SOURCE_FILE_ERROR);

    if (sourceFile.peek() == std::ifstream::traits_type::eof())
        return handleErrorForIfstream(sourceFile, SOURCE_FILE_ERROR);

    std::string text = dest_file_name + FILE_EXTENSION;
    std::ofstream outputFile(text);
    if (!outputFile)
        return (sourceFile.close(), handleErrorForOfstream(outputFile, OUTPUT_FILE_ERROR));

    std::string line;
    while (std::getline(sourceFile, line))
        outputFile << replaceAllWithoutReplace(line, toFindToken, toReplaceToken) << std::endl;

    sourceFile.close();
    outputFile.close();
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        displayUsage();
        return ERROR_EXIT_FLAG;
    }

    std::string dest_file_name = argv[1];
    std::string toFindToken = argv[2];
    std::string toReplaceToken = argv[3];

    return FindAndReplace(toFindToken, toReplaceToken, dest_file_name);
}
