#ifndef LIBRARY_FACILITIES
#define LIBRARY_FACILITIES
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <tuple>
using std::tuple;
#include <vector>
using std::vector;
#include <bitset>
using std::bitset;
#include <regex>
using std::regex;
using std::smatch;
using std::regex_search;
#include <random>
#include <iomanip>
using std::setprecision; //manipulator that take an arg
void init_tup();
void init_bit();
void init_regex();
void init_random();
void ctr_boolean_f();
void ctr_integral_f();
void ctr_floating_f();
#endif