#include "statement.hpp"
void solveGrade(void){
    const std::vector<std::string> scores={"F","D","C","B","A","A++"};
    std::string letterGrade;
    unsigned grade =60;
    if(grade<60){
        letterGrade= scores[0];
    }
    else{
        letterGrade=scores[(grade-50)/10];
    }
    std::cout<<"we get grade : " << letterGrade<<std::endl;
}
void nestedIf(void){
    const std::vector<std::string> scores={"F","D","C","B","A","A++"};
    std::string letterGrade;
    unsigned grade =70;
    if(grade<60){
        letterGrade=scores[0];
    }
    else{
        letterGrade=scores[(grade-50)/10];
        if(grade%10>7){
            letterGrade+="+";
        }
        else if(grade%10<3){
            letterGrade+="-";
        }
    }
    std::cout<<"using nested if, i get grade : " << letterGrade<<std::endl;
}
void switStatement(void){
    const std::string letter="Allow only one make using nested if, i get grade letterGrade";
    unsigned aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
    unsigned int i=0;
    while (i!=letter.size())
    {
        switch (letter[i])
        {
        case 'a':
            ++aCnt;
            break;
        case 'e':
            ++eCnt;
            break;;
        case 'u':
            ++uCnt;
            break;;
        case 'i':
            ++iCnt;
            break;
        case 'o':
            ++oCnt;
            break;
        default:
            break;
        }
        ++i;
    }
   std::cout<<"Number of vowel a: "<<aCnt<<std::endl;
   std::cout<<"Number of vowel e: "<<eCnt<<std::endl; 
   std::cout<<"Number of vowel i: "<<iCnt<<std::endl; 
   std::cout<<"Number of vowel o: "<<oCnt<<std::endl; 
   std::cout<<"Number of vowel u: "<<uCnt<<std::endl; 
    std::cout<<"Other characters: "<< (letter.size()-(aCnt+eCnt+iCnt+oCnt+uCnt))<<std::endl;
}
void modifySwitchStatement(void){
    const std::string letter="Allow only one make using nested if, i get grade letterGrade";
    int i =0;
    unsigned totalVowel=0,otherCnt=0;
    while (i!=letter.size())
    {
        switch(letter[i]){
            case 'a':case 'e':case 'u':case 'i':case 'o':
                ++totalVowel;break;
            default:
                ++otherCnt;
                break;
        }
        ++i;
    }
    std::cout<<"modify vowel counting program, (vowel total)  : "<<totalVowel<<std::endl;
    std::cout<<"non vowel : " << otherCnt<<std::endl;
}
void whilStatement(void){
    std::vector<int> v;
    int i;
    std::cout<<"input the data, read the data using while : ";
    while (std::cin>>i)
    {
        v.push_back(i);
    }
    std::cout<<"\nok write the data : ";
    std::vector<int>::iterator beg = v.begin();
    while (beg!=v.end() && *beg>=0)
    {
        std::cout<<*beg<<" ";
        ++beg;
    }
    std::cout<<std::endl;
}
void forStatement(void){
    std::string addr="madison street avenue x";
    for(decltype(addr.size()) index=0;index!=addr.size();++index){
        addr[index] = toupper(addr[index]);
    }
    std::cout<<"using for to iterate the data : " << addr<<std::endl;
}
void forStatCapitalize(void){
    std::string addr="madison street avenue x";
    std::cout<<"original address : " << addr<<std::endl;
    for(size_t i =0;i!=addr.size();++i){
        if (i==0)
        {
            addr[i] = toupper(addr[i]);
        }
        else if((i>0) && (isspace(addr[i]))){
            addr[i+1] = toupper(addr[i+1]);
        } 
    }
    std::cout<<"capitalize the address : " << addr<<std::endl;
}
void rangeForStatement(void){
    std::vector<int> naturalNum  = {0,1,2,3,4,5,6,7,8,9};
    std::cout<<"using range for statement to iterate and change the object"<<std::endl;
    std::cout<<"the tast is read and write : ";
    for(auto &x:naturalNum){
        x*=2;   //using reference to change the object which x point
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    /*without reference*/
    std::cout<<"the tast is to read not write : ";
    for(auto x:naturalNum){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}
void doWhileStatement(void){
    std::string rsp;
    std::cout<<"using do while statement ! "<<std::endl;
    do{
        std::cout<<"please enter two number :  ";
        int x=0,y=0;
        std::cin>>x>>y;
        std::cout<<"the sum of " << x <<" and " << y <<" = "<<(x+y)<<std::endl;
        std::cout<<"more ? enter yes or no :";
        std::cin>>rsp;
    }while(!rsp.empty() && rsp[0]!='n'); //test condition
}
void breakStatement(void){
    std::cout<<"using break to stop iteration || tested condition"<<std::endl;
    const std::string addr="Madison avenue street x";
    unsigned i=0;
    while (i!=addr.size())
    {
        std::cout<<" " << addr[i]<<" ";
        if (isspace(addr[i]))
        {
            break;
        }
        ++i;
    }
    std::cout<<"executed the outside while "<< addr<<std::endl;
}
void continueStatement(void){
    std::string buf;
    while (std::cin>>buf && !buf.empty())
    {
        if (buf[0]!='_'){
            continue;//reading until first character begin with underscore
        }
        std::cout<<"using continue statement"<<std::endl;
    }
}
void exceptionThrow(void){
    int x=12,y=13;
    if(x!=y){
        throw std::runtime_error("x not equals to y");
    }
    std::cout<<"do something, because x is equals to y"<<std::endl;
}
void exceptionTryCatch(void){
    std::cout<<"using try catch to handle exception "<<std::endl;
    std::cout<<"input two isbn : ";
    int isbn_1,isbn_2;
    const std::vector<int> number = {1,2,3,4,5,6,7};
    try{
        std::cout<<"test adding two number ? ";
        isbn_1 = isbn_2+number[7];
    }
    catch(std::out_of_range err) {
        std::cout<<err.what() <<"out of range"<<std::endl;
    }
    /*while(std::cin>>isbn_1>>isbn_2){
        try{
            std::cout<<"try to add the book"<<std::endl;
            isbn_1+=isbn_2;
        }
        catch(std::exception err){
            std::cout<<err.what()<<"Try again? Enter y or n"<<std::endl;
            char c;
            std::cin>>c;
            if(!std::cin || c=='n'){
                break;
            }
        }
    }*/
}