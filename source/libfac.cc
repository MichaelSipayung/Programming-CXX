#include "libfac.h"
void init_tup()
{
    tuple<size_t,size_t,size_t> threeD{1,2,3};
    auto item = std::make_tuple("0-0xxx-12",12,45.5); //rep isbn,count and price
    //accesing the member of a tuple
    auto book  = std::get<0>(item);
    cout<<"access the first member : "<<book<<endl;
}
void init_bit()
{
    bitset<32> bitvec(1U); //32 bits; low order bit is 1, remainding is 0
}
void init_regex()
{
    string pattern("[^c]ei"); //find the characters ei follow a character other than c
    //we want the whole word in which our pattern appears
    pattern = "[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    regex r(pattern); //construct a regex to find pattern
    smatch results; //define an object to hold the results of a search
    string test_str  = "receipt freind theif receive";
    //use r to find a match to pattern in test_str
    if(regex_search(test_str,results,r)) //if there is match
        cout<<results.str()<<endl;      //print the matching word
}
void init_random()
{
    //random number engines are function objects classes
    std::default_random_engine e; //generates random unsigned integers
    cout<<"random number : ";
    for(size_t i=0;i<10;++i)
        cout<<e()<<" ";
    cout<<std::endl;
    //distribution types and engines
    std::uniform_real_distribution<double> u(0,1);
    std::default_random_engine en;
    cout<<"with specific distributin :";
    for(size_t i=0;i<10;++i)
        cout<<u(e)<<" ";
    cout<<std::endl;
    std::default_random_engine use_seed(12);
    std::default_random_engine use_seed_v2(12);
    cout<<"1. using seed : "<<use_seed()<<endl;
    cout<<"2. using seed : "<<use_seed_v2()<<endl;
}