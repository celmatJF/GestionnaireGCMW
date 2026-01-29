#pragma once
#include <string>
using namespace std;

struct eleve   
{
    string nom;
    float note;
};

struct Variables{
    char choix;
    bool exit = false;
    float res;
    string nom;
    int index;
    float Best;
    float note;
};

inline constexpr const char* RED = "\033[31m";
inline constexpr const char* GREEN = "\033[32m";
inline constexpr const char* YELLOW = "\033[33m";
inline constexpr const char* LIGHTBLUE = "\033[34m";
inline constexpr const char* PURPLE = "\033[35m";
inline constexpr const char* BLUE = "\033[36m";
inline constexpr const char* RESET = "\033[0m";