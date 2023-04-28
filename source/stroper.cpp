#include "stroper.h"
//using substr function
void copyStr(const std::string& x){
    std::string s1= x.substr(0,5); //copy from index 0 -5
    std::cout<<s1<<std::endl;
    std::string s2= x.substr(6); 
}
//using insert function
void insertStr(std::string& x){
    x.insert(x.size(),5,'!'); //insert five exclamation point at the end
    //using erase function
    x.erase(x.size()-5,5);//insert the last five characters from x
    //using append function, insert to the last element
    x.append("miller");
    //using replace
    x.replace(11,3,"5th");//equal to calling erase, replace str from pos 11 with 5th
}
//search operation
void findStr(const std::string& x){
    auto pos = x.find("anna");
    std::cout<<"fin character in position : " << pos<<std::endl;
    std::string numbers="0123456789",name="r2d2";
    auto posFind  = name.find_first_of(numbers); //return 1 the index of first digit in name
    std::cout<<"using find first of : "<<posFind<<std::endl;
    //find first non character of a string
    std::string dept= "03714p3";
    auto firstApp  = dept.find_first_not_of(numbers) ;
    std::cout<<"first apper non character : " << firstApp<<std::endl;
}
//searching backward
void searchBack(const std::string &x){
    auto first_pos =x.rfind("is");
    std::cout<<"searching backward : " << first_pos<<std::endl;
}
//using compare to compare the string
void compareStr(const std::string &x,const std::string&y){
    std::cout<<"compare x == y , x<y , x>y : " << x.compare(y)<<std::endl;
}
//numeric conversion 
void numConver(){
    int i = 42;
    std::string s  = std::to_string(i);//convert the integer to character represent
    std::cout<<"int to string : " << s <<std::endl;
    double d = std::stod(s);    //convert the string s to floating point
    std::cout<<"convert string to floating point : " << d<<std::endl;
    //another case
    std::string s2 ="pi = 3.1425";
    //convert the first substring in s2 that start with digit, d=3.14
    double numCon= std::stod(s2.substr(s2.find_first_of("+-0123456789")));
    std::cout<<"find in the complicated expression (convert) : " << numCon*2 <<std::endl;
}
