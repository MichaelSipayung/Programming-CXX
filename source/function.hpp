#ifndef FUNCTION_CXX
#define FUNCTION_CXX
#define NDATA 5
#include <iostream>
#include <vector>
long double fact(int); // function declaration
size_t count_calls(void);
void reset(int *);
void resetByref(int &); // no need address to pass
bool isShorter(const std::string &, const std::string &);
std::string::size_type find_char(const std::string &, char,
                                 std::string::size_type &);
void consParameter(const int);
void passArray(int *);
void passArrayElement(int[10]);
void traverse(const int[10]);
void printCStyleArr(const char *);
void printStantLibConv(const int *, const int *);
void printExplicitSize(const int[], size_t);
void arrayrefAsPar(int (&arr)[10]);
void multDimen(const int[][NDATA], const size_t);
int gcdFind(int, int);
#endif