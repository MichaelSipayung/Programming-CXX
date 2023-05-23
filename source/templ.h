/*templates : foundation for generic programming in c++
* function template
* class template 
*/
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include <vector>

class Test_Template{
    public:
        Test_Template()=default;
        Test_Template(const int &arg1, const double &arg2, const std::string &arg3 )
            : x{arg1}, y{arg2}, z{arg3}{}
        void compare_test()const;
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
#endif