/*
* associative container section from the c++ programming langguage
* map and set
*/
#ifndef ASSOC_CONT_H
#define ASSOC_CONT_H
#include <iostream>
#include <vector>
#include <map>
#include <utility> //using pair member
#include <set>
template<typename Object>
void wordCounting_map(std::map<Object,size_t>&word)
{
    std::cout<<"\nword counting problem (input) : ";
    std::string key;
    while(std::cin>>key)
        ++word[key];
    for(const std::pair<std::string,size_t> &w:word) //using std::pait ro read each key value on map
        std::cout<<w.first<<" occurs "<< w.second
            <<((w.second)?" times": " time")<<std::endl;
}
void phoneBook_map(const std::map<std::string, std::string> &phone)
{
    std::cout<<"phone book program "<<std::endl;
    for(auto &x:phone)
        std::cout<<x.first<<" \t : " << x.second<<std::endl;
}
const std::string &lookPhone_map(const std::map<std::string, std::string>&phone, 
    const std::string &name)
{
    const std::string &not_found=" empty";
    for(const auto &fetchObj:phone)
    {
        if(fetchObj.first==name)
        {
            const std::string &found = fetchObj.second;
            return found;
            break;
        }   
    }
    return (not_found);
}
//using set, program: ignore common words like the, end, or and so on
//the program also word with another type eq. int, double and so on
template<typename Object>
void elemin_set(std::map<Object,size_t>&word_count, const std::set<Object>&excl)
{
    //test case: string
    const std::vector<std::string> &test_elim ={"and","the","bird","song","in","the","night","alone","a"};
    auto begin  = std::begin(test_elim);
    auto end  = std::end(test_elim);
    while(begin!=end)
    {
        if(excl.find(*begin)==excl.end()) //not equal to set? ok write 
            ++word_count[*begin]; //increase the counter
        else
            std::cout<<"eliminate : " << *begin<<std::endl;
        ++begin;
    }
    std::cout<<"result (eliminate word in the set) : "<<std::endl;
    for (const auto &x:word_count)
        std::cout<<x.first<<":" << x.second<<std::endl;
}
#endif