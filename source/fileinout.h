#ifndef FILE_IN_OUT_H
#define FILE_IN_OUT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
struct Reading
{
    int hour;
    double temperature;
};
struct StudentData
{
    unsigned int number;
    std::string nim;
    std::string name;
};
struct PersonalInfo{
    std::string name;
    std::vector<std::string> phones;
};
void fileStreamIn();
void fileStreamOut();
void readFile(const std::string &);
void readCsv(const std::string &);
void readStrStream();
#endif