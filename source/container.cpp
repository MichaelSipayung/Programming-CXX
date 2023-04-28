#include "container.h"
void max_vec_hold(){
    std::cout<<"maximum elemen can hold by vector : ";
    std::vector<int> max_hol;
    std::cout<<max_hol.max_size();
}
void iterat_el(){
    std::vector<int> fin_num   = {11,33,44,55,66,77,88,99};
    auto begin  = fin_num.begin();
    auto end  = fin_num.end();
    std::cout<<"\nusing iterator, traverse element : ";
    while (begin!=end)
    {
        std::cout<<" " << (*begin) <<" | ";
        ++begin;
    }
    std::cout<<std::endl;
}
void const_iter_el(){
    std::vector<double> num_fin  = { 12.0,14.0,23.0,33.0,44.0,55.0,31.0};
    std::vector<double>::const_iterator begin, end ;
    std::cout<<"just print the element, using const iterator"<<std::endl;
    begin = num_fin.cbegin();
    end  = num_fin.cend();
    while (begin!=end)
    {
        std::cout<<*begin<<" | ";
        ++begin;
    }
    std::cout<<std::endl;
}
void rev_iter_el(){
    std::list<std::string> name ={"Milton","Shakespare","Austen"};
    std::list<std::string>::reverse_iterator begin ,end;
    begin  = name.rbegin();
    end  = name.rend();
    std::cout<<"using reverse iterator on list contaoiner : " ;
    while (begin!=end)
    {
        std::cout<<*begin<<" | ";
        ++begin;
    }
     
}
//initialize the container
void init_con(){
    std::list<std::string>authors  = {"bob","jane","jack"};
    std::list<std::string> curAuthor  = authors;
    std::vector<const char*> articl  = {"ab article","ac article","ad article"};
    std::vector<std::string> cast_articl  (articl.begin(), articl.end()); //initialize
}
void init_con_arr(){
    std::array<int,42> hold_42;
    std::array<std::string,12> hold_str;
    std::array<int,10> list_init  = {0,1,2,3,4,5,6,7,8,9};
    std::array<int,10> copt_arr  = list_init;
}
//copy container
void copy_con(){
    std::array<int,3> def_val  = {1,2,3};
    std::array<int,3> copy_val;
    copy_val = def_val;
    //using assign for the container except array
    //initialize the element
    std::list<std::string> out_name ={"jack","daniel","bob"};
    std::vector<std::string> assign_con(out_name.cbegin(), out_name.cend());
    //another way to initialize 
    //takes an integral value and an element value
    assign_con.assign(10,"default");
}
void swap_con(){
    std::list<int> nat_num  = {0,1,2,3,4,5,6};
    std::list<int> inte_num  = {-1,-2,-3,0,1,2,3};
    //using swap, to swap the container
    std::swap(nat_num,inte_num);
}
//container size operation 
void check_size(){
    std::list<int> demo_size_op ={1,2,3,4};
    //checking the size
    if(demo_size_op.size()>12){
        std::cout<<"using size to determine the number of element"<<std::endl;
    }
    if (demo_size_op.empty())
    {
        std::cout<<"using emepty to check if container has no element"<<std::endl;
    }
    if (demo_size_op.max_size()<1e3)
    {
        std::cout<<"using max_size to check total element \
            can hold in container"<<std::endl;
    }
}
void relat_op(){
    std::list<std::string> aut_1  = {"jack","miller"};
    std::list<std::string> aut_2 = {"jack","miller","fall"};
    if (aut_1==aut_2)
    {
        std::cout<<"the first container equal two the second"<<std::endl;
    }
    if (aut_1<aut_2)
    {
        std::cout<<"compare the first container two the second"<<std::endl;
    }    
}
//adding element to a container
void add_el(){
    std::vector<int> nat_num  = {0,1,2,3,4,5,6,7,8};
    std::cout<<"size element in the container" << nat_num.size() <<std::endl;
    //adding element in the back of the container 
    nat_num.push_back(10);
    std::cout<<"size element in the container" << nat_num.size() <<std::endl;
    //string case 
    std::string book_num  = "AX-0098-MATH";
    std::cout<<"original size : " << book_num.size() <<std::endl;
    book_num.push_back('X');
    std::cout<<"after add in the end of the string (size) : " << book_num.size() <<std::endl;
    //using push front, except for vector
    std::list<int> nat_num_ls  = {0,1,2,3};
    nat_num_ls.push_front(4); //after adding a new element . [4,0,....3]
    //using insert
    std::list<std::string> pub_name ={"MIT","ITB Press","Orelly"};
    pub_name.insert(pub_name.begin(), " Andi"); // pub_name becomes Andi, MIT, ...
    //insert a range of elements
    std::vector<int> nega_num  = {-1,-2,-3,-4};
    nega_num.insert(nega_num.end(), 10, -10); //insert -10 ten times to the end of the element
    //using emplace, construct rather than copy the element
    std::vector<DemoEmplace> add_emplace;
    add_emplace.emplace_back("Jack",12,14.000); //using 3 argument    
}
//adding element using emplace, construct rather than copy
void demo_emplace(){
    std::vector<DemoEmplace> personal_data;
    personal_data.emplace_back("Daniel",3,45.000);
    std::cout<<"isbn : " << personal_data[0].x<<std::endl;
    std::cout<<"total sold : " << personal_data[0].sold<<std::endl;
    std::cout<<"price : " << personal_data[0].price<<std::endl;
    //using emplace back to list
    std::list<DemoEmplace> another_data;
    another_data.emplace_back("Jack",3,35.00);
    auto begin = another_data.begin();
    std::cout<<"isbn :  " << begin->x <<std::endl;
    std::cout<<"number of sold : "<< begin->sold<<std::endl;
    std::cout<<"price : " << begin->price<<std::endl;
    //using emplace front to lis, not work for vector
    //must match the contructor for the element type
    another_data.emplace_front("Mitchell",12,89.00);
    begin = another_data.begin();
    std::cout<<"isbn :  " << begin->x <<std::endl;
    std::cout<<"number of sold : "<< begin->sold<<std::endl;
    std::cout<<"price : " << begin->price<<std::endl;    
    //look how different the operation for push_back
    std::vector<DemoVector> diff_emplace ;
    //create local temporary object and than push to the container
    diff_emplace.push_back(DemoVector{"Jackie",13,89.00});
    //traverse the element through subscript
    std::cout<<"isbn num : " << diff_emplace[0].x <<std::endl;
}
void acc_el(){
    std::list<std::string> name  = {"Jack","Miller","Doe"};
    if (!name.empty())
    {
        std::cout<<"not empty container !"<<std::endl;
        std::cout<<"using front to access the first element : "<< name.front()<<std::endl;
        std::cout<<"access the last element using back : "<< name.back()<<std::endl;
    }
    //member return references
    std::list<int> nat_num  = {0,1,2,3,4,5,6,7,8};
    if (!nat_num.empty())
    {
        nat_num.front()  = 42; //change 0 to 42
        auto &v  = nat_num.back();//get a reference to the last element
        v= 30; //changes the element in nat_num
    }
    //safe random access
    std::vector<int> num= {0,1,2,3,4,5};
    if (!num.empty())
    {
        //safe access the data
        //runtime error
        std::cout<<"Access the last_el + 1 ! error " << num[6]<<std::endl;
        //throws an out_of_range exception
        std::cout<<"using at : " << num.at(6)<<std::endl;
    }
}
void err_el(){
    std::list<int> item_num  = {9,3,5,78,31,76};
    if (!item_num.empty())
    {
        std::cout<<"errase the item_num element: " << item_num.back()<<std::endl;
        //errase the element
        item_num.pop_back();
        //now the item_num has 5 element
    }
    //special case for list, using pop_front
    std::list<int> nat_num  =  {0,12,5,7,8,9};
    if (!nat_num.empty())
    {
        std::cout<<"erase the element in the first position : " << nat_num.front()<<std::endl;
        nat_num.pop_front();
    }
    //using erase 
    std::list<std::string> author_name  = {"Knuth","Arthur","Graham"};
    if (!author_name.empty())
    {
        std::cout<<"using erase to remove the element : " << *author_name.begin()<<std::endl;
        author_name.erase(author_name.begin());
        //remove the last element
        author_name.erase(author_name.end());
    }
    //string case  
    std::string nick_nm  = "Sipayung";
    std::cout<<"string case, erase the first element : " << *nick_nm.begin() <<std::endl;
    nick_nm.erase(nick_nm.begin());
    //remove all element 
    nick_nm.clear();
    if (nick_nm.empty())
    {
        std::cout<<"ok all element have removed using erase"<<std::endl;
    }
}
void demo_err_el(){
    std::list<int> num  =  {0,1,2,3,4,5,6,7,8,9};
    auto it =  num.begin();
    if(!num.empty()){
        while (it!=num.end())
        {
            if (*it%2) //looking if it odd element
            {
            //remove that
                num.erase(it);
            }
            else{
                ++it;
            }
        }
    }
}
void rem_by_pair(){
    std::list<int> num = {1,2,3,4,5,6,7,8};
    //using iterator pair to remove the element
    num.erase(num.begin(), ++num.begin());// remove the first element and the next element
}
void forw_list_it(){
    std::forward_list<int> nat_num  = {0,1,2,3,4,5,6,7,8};
    //remove and move the element 
    auto prev = nat_num.before_begin(); //denotes element "off the start"
    auto curr  = nat_num.begin();
    std::cout<<"\ncurrent container : " <<std::endl;
    if (!nat_num.empty())
    {
        for (auto first_el = nat_num.begin(); first_el!=nat_num.end(); ++first_el){
            std::cout<<" | " << *first_el <<" ";
        }
    }   
    std::cout<<std::endl;
    std::cout<<"using erase after : "<<std::endl;    
    if (!nat_num.empty())
    {
        while (curr!=nat_num.end())
        {
            if (*curr%2)    //if the element is odd number
            {
                curr  = nat_num.erase_after(prev); //erase it and move curr
            }
            else{
                prev  = curr;   //move the iterator to denote next
                ++curr; //element and one before the next element
            }
            for (auto first_el = nat_num.begin(); first_el!=nat_num.end(); ++first_el){
                std::cout<<" | " << *first_el <<" ";
            }
            std::cout<<std::endl;
        }
    }
    auto prev_pos  = nat_num.before_begin();
    auto curr_pos  = nat_num.begin();
    std::cout<<"curr_value : " << *curr_pos  <<std::endl;
    //call erase_after
    std::cout<<"call erase after"<<std::endl;
    curr_pos  = nat_num.erase_after(prev_pos);
    std::cout<<"curr_value : " << *curr_pos <<std::endl; 
}
void resize_con(){
    std::list<int> nat_num = {0,1,2,3,4,5,6,7,8};
    if (!nat_num.empty())
    {
        std::cout<<"current size : " << nat_num.size()<<std::endl;
        //resize the container
        nat_num.resize(15,0);// resize container
        std::cout<<"after resize the element : " << nat_num.size() <<std::endl;
    }
}
//demonstrate how we can safely remove or add element to the container
void safe_it(){
    std::vector<int> nat_num  = {0,1,2,3,4,5,6,7,8};
    auto iter = nat_num.begin();
    if (!nat_num.empty())
    {
        //duplicate the odd element
        //remove the even value
        while (iter!=nat_num.end())
        {
            //insert before iter
            if (*iter%2)
            {
                iter  = nat_num.insert(iter,*iter); //duplicate the odd element
                iter+=2; //advance past this element and the one inserted before it
            }
            else{
                iter = nat_num.erase(iter); //remove even elemen
                //don't advance the iterator
                //iter denotes the element after the one we erased
            }        
        }
    }
}
void manage_cap(){
    std::vector<int> nat_num  ={0,1,2,3,4,5,6,7,8};
    if (!nat_num.empty())
    {
        std::cout<<"vactor size : "<< nat_num.size()<<std::endl;
        //using capacity
        //how many elements it can hold before more space must be allocated
        std::cout<<"capacity : "<< nat_num.capacity() <<std::endl;
        //set capacity to at least 50
        nat_num.reserve(50);
        std::cout<<"after reserve (capacity): " << nat_num.capacity()<<std::endl;
    }
}
