/*
* friend function and friend class best practice
* declare and define on the same header
*/
#ifndef FRIEND_PRACT
#define FRIEND_FACT
#include <iostream>
namespace Frn{
class Friend_Pract{
friend void fstate( const Friend_Pract&)noexcept(true);
    public:
        Friend_Pract(int x, double y): data{x}, nextState{y}{}
    private:
        int data;
        double nextState;
};
void fstate(const Friend_Pract&st)noexcept(true)
{
    auto x  = st.data;
}
}

#endif