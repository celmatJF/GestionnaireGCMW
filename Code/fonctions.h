#pragma once
#include <string>


void AddStudent(std::string TabStudent[30], float TabNotation[30]);
void liste(std::string tabElv[30]);
float moyenne(float tabNote[30]);
void searchElv(std::string tabElv[30], float tabNote[30],std::string& nom, int& index, float& note);
float bestNote(float tabNote[30]);