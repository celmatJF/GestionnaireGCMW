#pragma once
#include <string>

void serchElv(std::string tabElv[30], float tabNote[30],const std::string& nom, int& index, float& note);
void bestNote(float tabNote[30], float& Best, int& index);
void liste(std::string tabElv[30]);
float moyenne(float tabNote[30]);
void AddStudent(std::string TabStudent[30], float TabNotation[30]);
