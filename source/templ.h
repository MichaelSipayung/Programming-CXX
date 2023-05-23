/*templates : foundation for generic programming in c++
* function template
* class template 
*/
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <cstring>
class Test_Template{
    public:
        Test_Template()=default;
        Test_Template(const int &arg1, const double &arg2, const std::string &arg3 )
            : x{arg1}, y{arg2}, z{arg3}{}
        void compare_test()const;
        void compare_str()const;
    private:
        int x;
        double y;
        std::string z;
};
template <typename T>
int compare(const T& v1, const T& v2)
{
    if(v1<v2)
        return -1;
    if(v2<v1)
        return 1;
    return 0;
}
template <typename T>
T foo(T *p){
    T tmp = *p; //tmp will have the type to which p points
    return tmp;
}
//nontype template parameters
template<unsigned N, unsigned M>
int compare_s(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1,p2);
}
inline void sigma()
{
    auto temp = 0.0;
    cout<<"optimize small .."<<endl;
}
//inline function template
template<typename T>inline T min(const T&str_1, const T&str_2)
{
    T tmp = str_1;
    return tmp;
}
//writing type-independent code
//allowing compare two pointer
//minimize the operator requirement for template
template <typename T> int compare_ind(const T&v1, const T&v2)
{
    if(std::less<T>()(v1,v2)) return -1;
    if(std::less<T>()(v2,v1)) return 1;
}
#endif