//
//  io.cpp
//  Game
//
//  Created by Rafi Khan on 2016-12-29.
//
//

#include "io.hpp"

std::string read_file(const char* path) {
    std::ifstream t(path);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

    return str;
}

void print(const char* s) {
	std::cout << s;
}

void println(const char* s) {
	std::cout << s << std::endl;
}
