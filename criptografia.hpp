#pragma once
#include <string>
#include <array>
std::array<int, 32> criptografa(std::string senha);
std::array<int, 32> paraASCII(std::string& senha);
void salvaChave(std::array<int, 32>& senha);