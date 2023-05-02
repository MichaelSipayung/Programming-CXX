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
    //using std::bind 
    std::cout<<"test size : ";
    using namespace std::placeholders;
    auto checkSizes  = std::bind(checking_size,_1,6);
    std::string s_bind = "hello world";
    bool b1_bind  = checkSizes(s_bind);
    //std::cout<<"test check size (1:true)?(0:false) : " << check_size("jack",3)<<std::endl;
    std::cout<<"testing bind object : " << b1_bind<<std::endl;
    //implementation of the lambda
    modLambda({"the","red","fox","jumps","ove","red","slow","the","turtle"});
    test_other_f();
    test_other_f1();
    std::cout<<"test bind reference parameter : ";
    test_bind_print({"the","red","fox","jumps","ove","red","slow","the","turtle"},std::cout);
    test_bind_corr();
    //another iterator opearation 
    //back inserter
    std::vector<int> iter_nat_num={0,1,2,3,4,5,6,7};
    std::cout<<"before back_inserter"<<std::endl;
    iter_print_v(iter_nat_num);
    std::cout<<"after back inserter : ";
    iter_back_inst(iter_nat_num,{8,9});//insert in the back of container
    iter_print_v(iter_nat_num);
    std::list<int> iter_front_num = {0,1,2,3,4,5,6,7};
    std::cout<<"applying to lis (front_inserter) : ";
    iter_print_l(iter_front_num);
    std::cout<<"after front inserter : ";
    iter_front_inst(iter_front_num,{8,9});
    iter_print_l(iter_front_num);
    //case for vector
    iter_inserter(iter_nat_num,{10,11});
    std::cout<<"using inserter for vector: ";
    iter_print_v(iter_nat_num);
    //case for list
    std::cout<<"using inserter for list: ";
    iter_inserter(iter_front_num,{10,11});
    iter_print_l(iter_front_num);
    std::cout<<"applying inserter to string :"<<std::endl;
    std::string iter_author_name="Anton";
    iter_print_str(iter_author_name);
    std::cout<<"after call inserter : ";
    iter_inserter(iter_author_name,{"Howard "});
    iter_print_str(iter_author_name);
    //std::istream_iterator<int> istream_iter_test(std::cin),end_of_istream;
    //iter_istream(istream_iter_test,end_of_istream); //ok test pass .
    
    //apply iostream iterator on algorithm
    //number : 23 109 45 89 6 34 12 90 34 23 56 23 8 89 23 i
    /*std::cout<<"input number to sum : ";
    std::istream_iterator<int> istream_iter_test(std::cin),end_of_istream;
    std::cout<<iter_on_alg(istream_iter_test,end_of_istream)<<std::endl;*/

    return 0;
}
