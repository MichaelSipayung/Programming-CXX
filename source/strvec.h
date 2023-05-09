#ifndef STRVEC_H
#define STRVEC_H
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <memory>
using std::allocator;
#include <utility>
using std::pair;
#include <vector>
using std::vector;
namespace Adv{
class StrVec{
    public:
        StrVec(): //the allocator member is default init
            elements{nullptr},first_free{nullptr},cap{nullptr}{}
        StrVec(const StrVec&); //cp ctor
        StrVec &operator=(const StrVec&); //cp assign
        ~StrVec();
        void push_back(const string&);
        size_t size()const{return first_free-elements;}
        size_t capacity()const{return cap-elements;}
        string *begin() const {return elements;}
        string *end()const{return first_free;}
    private:
        static allocator<string> alloc; //must be define in implementation file
        void chk_n_alloc();
        void free();
        void reallocate();
        string *elements;
        string *first_free;
        string *cap;
};
}
#endif