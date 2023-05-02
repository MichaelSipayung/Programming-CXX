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
void iter_print_str(const Object&str)
{
    std::cout<<str<<std::endl;
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
//iostream iterators, istream_iterator, ostream_iterator
template<typename Object>
void iter_istream(std::istream_iterator<Object> &word, std::istream_iterator<Object> &eof)
{
    //read from stream, and stop read after type non object or hit the EOF
    std::cout<<"using iostream iterator case (read) : "; 
    std::vector<Object> vec(word,eof); //construct vec from an iterator range
    std::cout<<"show value after encounter the end of file : ";
    iter_print_v(vec);
}
//apply iostream iterator in algorithm
//note library algorithm work with iterator
template <typename Object>
const Object &iter_on_alg(std::istream_iterator<Object> &in,std::istream_iterator<Object> &eof)
{
    std::cout<<"After the summation : ";
    const Object &result=std::accumulate(in,eof,0);
    return result;
}
#endif