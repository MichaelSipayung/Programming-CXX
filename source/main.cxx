#include "main.h"
int main(int argc,char ** argv){
    noCopyIo();
    flushBuffer();
    std::string filename="sample.txt";
    readFile(filename);
    std::string file_name_1="sample_1.txt";
    readCsv(file_name_1);
    max_vec_hold();
    iterat_el();
    const_iter_el();
    rev_iter_el();
    demo_emplace();   
    forw_list_it(); 
    resize_con();
    manage_cap();
    copyStr("hello world");
    numConver();
    findAl({0,1,2,3,4,5,6,7,8,9});
    sumElm({0,1,2,3,4,5,6,7,8});
    std::string perform_modif ="literal";
    modifyEl(perform_modif);
    safeInsert(perform_modif);
    std::string tempObj  = "temporary";
    std::vector<std::string> sortUniq=
        {"the","quick","red","fox","jumps","over","red","slow","the","turtle"};
    elimDups(sortUniq);
    //test condition, by length of each word
    testPredicate({"the","red","fox","jumps","over","red","slow","the","turtle"});
    useLambda();
    lamdaWithArgs();
    useCaptureList({"the","red","fox","jumps","ove","red","slow","the","turtle"},4);
    
    return 0;
}
