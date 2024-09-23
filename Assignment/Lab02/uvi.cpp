#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <set>

std::set<std::string> kw{
    "int", "float", "char", "struct", "if", "else", "while", "return"
};
std::set<char> op{
    ';', ',', '=', '<', '>', '!', '+', '-', '*', '/', '&', '|', '(', ')', '[', ']', '{', '}'
};

std::set<std::string> getIdentifier(std::string buffer) {
    auto it = buffer.begin();
    std::string::iterator begin;
    std::set<std::string> identifier;

    auto state = 0;
    while (it != buffer.end()) {
        auto c = *it;
        switch (state) {
            case 0:
                if (std::isalpha(c) || c == '_')
                    begin = it, state = 1;
                else state = 2;
                break;
            case 1:
                if (std::isalpha(c) || std::isdigit(c) || c == '_')
                    break;
                else if (op.find(c) != op.end() || std::isspace(c) || it + 1 == buffer.end()) {
                    if (std::string id(begin, it); kw.find(id) == kw.end())
                        identifier.insert(id);
                    state = 0;
                }
                else state = 2;  // Unsupported CH
                break;
            case 2:
                if (op.find(c) != op.end() || std::isspace(c))
                    state = 0;
                break;
        }
        it++;
    }

    return identifier;
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid # of arguments" << std::endl;
        return 1;
    }

    std::ifstream f {argv[1]};
    std::string buffer;

    f.seekg(0, std::ios::end);
    buffer.resize(f.tellg());
    f.seekg(0), f.read(buffer.data(), buffer.size());
    
    auto ids = getIdentifier(buffer);
    std::cout << std::format("Found {} unique IDs: ", ids.size());
    for (auto id : ids)
        std::cout << id << ", ";
    std::cout << "\b\b";

    return 0;
}