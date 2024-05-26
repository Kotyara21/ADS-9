// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        exit(1);
    }
    char с;
    std::string word;
    BST<std::string> tree;
    while (file.get(с)) {
        if (isalpha(с)) {
            word += tolower(с);
        } else if (!word.empty()) {
            tree.add(word);
            word.clear();
        }
    }
    file.close();
    return tree;
}
