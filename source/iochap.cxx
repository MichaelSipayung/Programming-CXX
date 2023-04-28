#include "iochap.h"
void noCopyIo(){
    std::fstream out1,out2;
    std::cout<<"error copy out1 = out2" <<std::endl; 
}
void condState(){
    std::cout<<"managging the error in io"<<std::endl;
    int x; //we hove user input int
    while (std::cin>>x)
    {
        std::cout<<" - " << x ;
    }
    std::cout<<std::endl;
}
void manageState(){
    auto oldState  = std::cin.rdstate(); //remember the current state
    std::cin.clear();
}
void flushBuffer(){
    std::cout<<"flush using endl"<<std::endl;
    std::cout<<"flush using (flush)"<<std::flush;
    std::cout<<"flush using (ends)"<<std::ends;
    std::cout<<std::unitbuf;
    //no buffering, flush imidiately
    std::cout<<"flush imidiately all write (unitbuf)"<<std::endl;
    std::cout<<std::nounitbuf; //return to normall buffering
}
