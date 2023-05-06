#include "main.h"
int main(int argc,char ** argv){
    // noCopyIo();
    // flushBuffer();
    // std::string filename="sample.txt";
    // readFile(filename);
    // std::string file_name_1="sample_1.txt";
    // readCsv(file_name_1);
    // max_vec_hold();
    // iterat_el();
    // const_iter_el();
    // rev_iter_el();
    // demo_emplace();   
    // forw_list_it(); 
    // resize_con();
    // manage_cap();
    // copyStr("hello world");
    // numConver();
    // findAl({0,1,2,3,4,5,6,7,8,9});
    // sumElm({0,1,2,3,4,5,6,7,8});
    // std::string perform_modif ="literal";
    // modifyEl(perform_modif);
    // safeInsert(perform_modif);
    // std::string tempObj  = "temporary";
    // std::vector<std::string> sortUniq=
    //     {"the","quick","red","fox","jumps","over","red","slow","the","turtle"};
    // elimDups(sortUniq);
    // //test condition, by length of each word
    // testPredicate({"the","red","fox","jumps","over","red","slow","the","turtle"});
    // useLambda();
    // lamdaWithArgs();
    // useCaptureList({"the","red","fox","jumps","ove","red","slow","the","turtle"},4);
    //using std::bind 
    // std::cout<<"test size : ";
    // using namespace std::placeholders;
    // auto checkSizes  = std::bind(checking_size,_1,6);
    // std::string s_bind = "hello world";
    // bool b1_bind  = checkSizes(s_bind);
    // //std::cout<<"test check size (1:true)?(0:false) : " << check_size("jack",3)<<std::endl;
    // std::cout<<"testing bind object : " << b1_bind<<std::endl;
    // //implementation of the lambda
    // modLambda({"the","red","fox","jumps","ove","red","slow","the","turtle"});
    // test_other_f();
    // test_other_f1();
    // std::cout<<"test bind reference parameter : ";
    // test_bind_print({"the","red","fox","jumps","ove","red","slow","the","turtle"},std::cout);
    // test_bind_corr();
    // //another iterator opearation 
    // //back inserter
    // std::vector<int> iter_nat_num={0,1,2,3,4,5,6,7};
    // std::cout<<"before back_inserter"<<std::endl;
    // iter_print_v(iter_nat_num);
    // std::cout<<"after back inserter : ";
    // iter_back_inst(iter_nat_num,{8,9});//insert in the back of container
    // iter_print_v(iter_nat_num);
    // std::list<int> iter_front_num = {0,1,2,3,4,5,6,7};
    // std::cout<<"applying to lis (front_inserter) : ";
    // iter_print_l(iter_front_num);
    // std::cout<<"after front inserter : ";
    // iter_front_inst(iter_front_num,{8,9});
    // iter_print_l(iter_front_num);
    // //case for vector
    // iter_inserter(iter_nat_num,{10,11});
    // std::cout<<"using inserter for vector: ";
    // iter_print_v(iter_nat_num);
    // //case for list
    // std::cout<<"using inserter for list: ";
    // iter_inserter(iter_front_num,{10,11});
    // iter_print_l(iter_front_num);
    // std::cout<<"applying inserter to string :"<<std::endl;
    // std::string iter_author_name="Anton";
    // iter_print_str(iter_author_name);
    // std::cout<<"after call inserter : ";
    // iter_inserter(iter_author_name,{"Howard "});
    // iter_print_str(iter_author_name);
    //std::istream_iterator<int> istream_iter_test(std::cin),end_of_istream;
    //iter_istream(istream_iter_test,end_of_istream); //ok test pass .
    
    //apply iostream iterator on algorithm
    //number : 23 109 45 89 6 34 12 90 34 23 56 23 8 89 23 i
    /*std::cout<<"input number to sum : ";
    std::istream_iterator<double> istream_iter_test(std::cin),end_of_istream;
    std::cout<<iter_on_alg(istream_iter_test,end_of_istream)<<std::endl;*/
    
    //applying std::ostream_iterator
    //case double
    // std::cout<<"result : ";
    // std::ostream_iterator<double> os_iter_test(std::cout," "); //separate by space for each element
    // iter_ostream(os_iter_test,{5.6,1,2,3,4,5,6,7.0});
    // iter_reverse("jackie");//apply reverse iterator to string
    // //apply to array 
    // const int arr_number[] ={0,1,2,3,4,5,6};
    // iter_reverse(arr_number);
    // //using std::map<keyObject,valueObject>
    // //std::map<std::string,size_t> word_test_map;
    // //wordCounting_map(word_test_map);
    // std::map<std::string, std::string> number_map_test={
    //     {"Daniel","0852-9899-7899"},
    //     {"Jackie","0853-00999-9888"},
    //     {"Lim","0852-9899-7890"},
    //     {"Jackie","0853-00999-8888"},
    //     {"Roller","0852-9899-7799"},
    //     {"Maverick","0853-00999-2888"}
    // };
    // phoneBook_map(number_map_test);
    /*std::cout<<"search name : Roller (result :"<<lookPhone_map(number_map_test,"Roller")<<")";
    std::map<std::string, size_t>elim_set_test;
    std::cout<<"\nignore some word before push to map"<<std::endl;
    elemin_set(elim_set_test,{"The","the","a","A","And","and"});

    //test case int object
    std::cout<<"test the difference between multiset and set"<<std::endl;
    const std::vector<int> number_test_multiset ={0,0,1,1,2,2,3,3,4,4};
    diff_multiSet(number_test_multiset,{std::begin(number_test_multiset),
        std::end(number_test_multiset)},{std::begin(number_test_multiset),
        std::end(number_test_multiset)});
    //test std::pair
    moreType_pair(std::pair<std::string,int>({"jackie",20})); //jackie is 20 y old
    moreType_pair(std::pair<std::string,double>({"Miller",165.5})); //miller have 165.5 kg of the b
    //return a pair of object
    std::cout<<"first : " << create_pair(std::vector<std::string>{"jackie","cliff","barrow"}).first
        <<"\nsecond : " <<create_pair(std::vector<std::string>{"jackie","cliff","barrow"}).second
        <<std::endl;
    std::map<std::string,int>iterator_as_test={{"mike",165}};
    iteratorMap_assoc(iterator_as_test,167); //test success
    //const iterator on map 
    iteratorSet_assoc(std::set<int>{12},3);
    iteratorSet_assoc(std::set<double>{167.0},double{3});
    std::map<std::string,int>name_and_score = {{"june",7},{"April",9},{"Alex",8}};
    iterElement_assoc(name_and_score);
    std::map<std::string,int>alg_insert;
    addElement_map(std::vector<std::string>({"jack","daniel"}), std::vector<int>({12,13}),
        alg_insert);
    addElement_test_print(alg_insert);*/
    // std::multimap<std::string,double>multi_key  = {{"Jackie",65.0},{"Jack",98.6}};
    // //workW_multimap(multi_key,std::string("Jimmy"),63.0,68.0);
    // //erase_map(number_map_test,std::string("Daniel"));
    // accesEl_assoc(std::set<std::string>({"jack","daniel","knuth"}),
    //     number_map_test,std::string("Jackie"));
    // //unordered container
    // unorCon_print(std::unordered_map<std::string,std::string>({
    //     {"Daniel","0852-9899-7899"},
    //     {"Jackie","0853-00999-9888"},
    //     {"Lim","0852-9899-7890"},
    //     {"Jackie","0853-00999-8888"},
    //     {"Roller","0852-9899-7799"},
    //     {"Maverick","0853-00999-2888"}
    // }),std::string("Daniel"));
    std::shared_ptr<int>x_point;
    Smart::hello_ptr(x_point,int(13));
    Smart::alloc_ptr(13.3,"authors"); 
    //test strblob class
    Smart::strBlob mem_dynm;
    mem_dynm.push_back("jack");
    mem_dynm.push_back("jane");
    mem_dynm.push_back("dona");
    std::cout<<"total element : " << mem_dynm.size()<<std::endl;
    std::cout<<"is strblob class empty : "<< mem_dynm.empty()<<std::endl;
    std::cout<<"traverse all the element : ";
    auto begin_trav= mem_dynm.begin_s();
    while(begin_trav!=mem_dynm.end_s())
    {
        std::cout<<*begin_trav<<" | ";
        ++begin_trav;
    }
    std::cout<<std::endl;
    Smart::dealloc_obj();
    std::cout<<"freed memory ... "<<std::endl;
    int *x_freed  = new int(90);
    std::cout<<"original value : " <<*x_freed<<std::endl;
    delete x_freed;
    if(x_freed)
        std::cout<<"success freed ... "<<std::endl;  
    std::cout<<"after freed: "<<*x_freed<<std::endl;
    //delete const object
    const int*cons_obj = new const int(12);//
    delete cons_obj; //freed const obj
    Smart::other_op();
    Smart::manage_con();
    Smart::uniqPtr_alloc();
    Smart::alloc_weakly();
    Smart::acc_weakPtr();
    Smart::array_dyn(3);
    Smart::smart_arr(); 
    Smart::smart_arr2();
    
    return 0;
}
