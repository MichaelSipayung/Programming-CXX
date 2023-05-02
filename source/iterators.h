/* iterator operation on
* container, file stream and etc ..
*/
#ifndef ITERATORS_H
#define ITERATORS_H
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
template<typename Object>
void iter_print_v(const std::vector<Object>&word)
{
    for(auto x:word)
        std::cout<<x<<" ";
    std::cout<<std::endl;
}
template<typename Object>
void iter_print_l(const std::list<Object>&word)
{
    for(auto x:word)
        std::cout<<x<<" ";
    std::cout<<std::endl;
}
template<typename Object>
void iter_back_inst(std::vector<Object>& dest, const std::vector<Object> & source)
{
    std::copy(source.begin(), source.end(), std::back_inserter(dest));
}
template <typename Object>
void iter_front_inst(std::list<Object>& dest, const std::list<Object> & source)
{
    std::copy(source.begin(),source.end(),std::front_inserter(dest));
}
template <typename Container>
void iter_inserter(Container &dest, const Container &source)
{
    std::copy(source.begin(), source.end(), std::inserter(dest,dest.begin()));
    //inserter : insert element by element which not reverse by order
}
#endif