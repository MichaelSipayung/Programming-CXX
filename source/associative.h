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
const std::string lookPhone_map(const std::map<std::string, std::string>&phone, 
    const std::string &name)
{
    const std::string not_found=" empty";
    for(const auto &fetchObj:phone)
    {
        if(fetchObj.first==name)
        {
            const std::string found = fetchObj.second;
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
//looking the difference between set, multiset
//multiset allow duplicate key
template<typename Object>
void diff_multiSet(const std::vector<Object>&data,const std::set<Object>&set_obj,
    const std::multiset<Object> &mulSet_obj)
{
    std::cout<<" vector size : " << data.size() <<std::endl;
    std::cout<<" set size (not allowed dupplicate key): " <<set_obj.size()<<std::endl;
    std::cout<<" multiset size : " << mulSet_obj.size() << std::endl;
}
//using std::pair, defined in utility header
//first and second data member defined as public
//a pair hold two data member
template<typename Object_1,typename Object_2>
void moreType_pair(const std::pair<Object_1, Object_2>&ex_pair)
{
    std::cout<<"first : " << ex_pair.first<<" second : "<<ex_pair.second<<std::endl;
}
//return pair object
//if vector is empty explicitly construc the value
template<typename Object>
const std::pair<Object,size_t>&create_pair(const std::vector<Object> &data)
{
    const auto &temp  = std::pair<Object,size_t>(data.back(),data.back().size());
    const auto &isEmpt = std::pair<Object,size_t>();
    if(!data.empty())
        return temp;
    else
        return isEmpt;
}
//associative container additional type aliases
//key_type, mapped_type,value_type
template<typename Object_1,typename Object_2>
void typeAliases_assCon(const std::set<Object_1>&x, const std::map<Object_1,Object_2>&y)
{
    std::set<int>::value_type v1; //v1 is a string
    std::map<double,int>::value_type v2; //v2 is a int
}
//associative container iterator
template<typename Object_1,typename Object_2>
void iteratorMap_assoc(std::map<Object_1,Object_2>&x,const Object_2&val)
{
    auto map_it = x.begin(); //get an iterator to an element in x
    std::cout<<"begin iterator (key) : "<< map_it->first<<" begin iterator (value) : "
        <<map_it->second<<std::endl;
    //key is const, never change
    //but value is nonconst object
    map_it->second=val;
    std::cout<<"value is noncost (modify it) : "<<map_it->second<<std::endl;
}
//set iterator is const object
template<typename Object>
void iteratorSet_assoc(const std::set<Object>&x, const Object&val)
{
    for(auto i:x)
        std::cout<<i<<" | ";
    std::cout<<"dont write! const iterator"<<std::endl;
    auto alterAddition = *x.begin()+val; //can't modify it directly
    std::cout<<"another way: " << alterAddition<<std::endl;
}
//traverse all element using iterator
template<typename Object_1,typename Object_2>
void iterElement_assoc(const std::map<Object_1,Object_2>&x)
{
    auto begin  = std::begin(x);
    auto end  =std::end(x);
    //for map output is alphabetical order
    while(begin!=end)
    {
        std::cout<<"first : "<< begin->first<<" second : " << begin->second<<std::endl;
        ++begin;
    }
}
//associative container and algorithm
//adding element to container
template<typename Object>
void addElement_set(const std::vector<Object>&source,std::set<Object>&dest)
{
    dest.insert(source.cbegin(), source.cend());
    std::cout<<"\nshow value after insert using iterator"<<std::endl;
    for(auto x:dest)
        std::cout<<x<<" | ";
    std::cout<<std::endl;
    //using list initializer list
    //dest.insert({value....})
}
//adding element to map
template<typename Object_1,typename Object_2>
void addElement_map(const std::vector<Object_1>&source_key, const std::vector<Object_2>&source_val,
    std::map<Object_1,Object_2>&dest)
{ 
    auto begin_k  = std::begin(source_key);
    auto end_k  = std::end(source_key);
    auto begin_val  = std::begin(source_val);
    auto end_val  = std::end(source_val);
    while(begin_k!=end_k)
    {
        dest.insert({*begin_k,*begin_val}); //remember to insert {key, value}
        ++begin_val;
        ++begin_k;
    }
    std::cout<<"insert success .."<<std::endl;
}
template<typename Object_1,typename Object_2>
void addElement_test_print(const std::map<Object_1,Object_2>&x)
{ 
    std::cout<<"test adding element to map using insert"<<std::endl;
    for(const auto &i:x)
        std::cout<<i.first<<" | "<<i.second<<std::endl;
}
//allowing insert the same key to multimap
//no need return bool, because insert element always return true
template<typename Object_1,typename Object_2>
void workW_multimap(std::multimap<Object_1,Object_2> &auth, const Object_1&x_1,const Object_2&x_2,
    const Object_2 &x_3)
{
    //case 1
    auth.insert({x_1,x_2});
    auth.insert({x_1,x_3});//insert the same key 
    std::cout<<"fetch the object with same key"<<std::endl;
    for(const auto&i:auth)
        std::cout<<i.first<<" | "<<i.second<<std::endl;
}
template<typename Object_1,typename Object_2>
void erase_map(std::map<Object_1,Object_2>&auth, const Object_1&key)
{
    std::cout<<"erase using key : " << auth.erase(key)<<std::endl;
    auto erase_all  = auth.erase(std::cbegin(auth),std::cend(auth));
    if(auth.empty())
        std::cout<<"erase all element";
    else
        std::cout<<"fail to erase element"<<std::endl;
}
template<typename Object_1,typename Object_2>
void accesEl_assoc(const std::set<Object_1>&x, const std::map<Object_1,Object_2>&y,const Object_1&z)
{
    std::cout<<"subscript op on set : " << *x.begin()<<std::endl;
    auto find_set  = x.find(z); //using member function not generic form
    if(find_set==x.end())
        std::cout<<"sorry... not found"<<std::endl;
    else
        std::cout<<"found.... dereference it : "<< *find_set<<std::endl;
    //pay attention work with map, if key exist ok, but if not write it!
    if(y.find(z)==y.end())
        std::cout<<"ok key not exist, don't add new key"<<std::endl;
    else
        std::cout<<"key exist.. show it"<<std::endl;
}
//case for multimap, using count to tell the total object with the same key
//if the first key found the next value is it neighbours
template<typename Object_1,typename Object_2>
void find_multiKey(const std::multimap<Object_1,Object_2>&x,const Object_2&src)
{
    auto entries  = x.count(src); //num element
    auto iter= x.find(src);//first entry, return iterator
    //guarante that if find do something
    while(entries)
    {
        std::cout<<iter->second<<std::endl;
        ++iter; //advance to the next title
        --entries; //keep track of how many we'he printed
    }
}
//using lower_bound and upper bound
template<typename Object_1, typename Object_2>
void find_multiKey_d(const std::multimap<Object_1,Object_2>&x, const Object_2&src)
{
    auto beg  = x.lower_bound(src);
    auto end  = x.upper_bound(src);
    while(beg!=end)
    {
        std::cout<<beg->second<<std::endl; //fetch each value with the given key
        ++beg;
    }
}
//using unordered container
//using has function rather than compare the element
template<typename Object_1, typename Object_2>
void unorCon_print(const std::unordered_map<Object_1,Object_2>&x,const Object_1&key)
{
    std::cout<<"see.. different order on containers"<<std::endl;
    for(const auto &word:x)
        std::cout<<word.first<<" " <<word.second<<std::endl;
    std::cout<<"searching using key : "<<key<<std::endl;
    auto find_key  = x.find(key);
    if(find_key==x.end())
        std::cout<<"not found ... "<<std::endl;
    else 
        std::cout<<"oh found it ...it's value :  "<< find_key->second<<std::endl;
}
#endif