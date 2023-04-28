#include "fileinout.h"
#define MAX_STUDENT 20
void fileStreamIn(){
    std::ifstream inputStream("freeglut.cxx");
    std::string s;
    if (!inputStream)
    {
        std::cout<<"file not exist "<<std::endl;
    }
    inputStream.close();
}
void fileStreamOut(){
    std::ofstream outStream("freegluts.txt",std::ofstream::app);
    int x[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    if (!outStream)
    {
        std::cout<<"file not ready"<<std::endl;
    }
    else{
        std::cout<<"file ready "<< "size : "<< sizeof(outStream)<<std::endl;
        std::cout<<"write data to file"<<std::endl;
        for (size_t i = 0; i < sizeof(x)/sizeof(x[0]); ++i)
        {
            outStream<<x[i] <<" ";
        }
    }
    outStream.close();
}
void readFile(const std::string &file_name){
    std::cout<<"please input file name"<<std::endl;
    std::ifstream ist{file_name};
    std::vector<Reading> temps;
    int hour,i=0;
    double temprature;
    if (!ist)
    {
        std::cout<<"can't open input file : "<<file_name<<std::endl;
    }
    else{
        std::cout<<"file : " << file_name<<" exist"<<std::endl;
        while (ist>>hour>>temprature)
        {
            temps.push_back(Reading{hour,temprature});
        }
        std::cout<<"after reading from file : "<< file_name<<std::endl;
        std::cout<<"show vector"<<std::endl;
        while (i!=temps.size())
        {
            std::cout<<temps[i].hour<<" " <<temps[i].temperature<<std::endl;
            ++i;
        }
    }
    ist.close();
}
void readCsv(const std::string &file_name){
    std::ifstream read(file_name);
    if (read)
    {
        std::cout<<"file : " << file_name <<" exist "<<std::endl;
    }
    else{
        std::cout<<"file not exist, make file : " << file_name <<std::endl;
    }
    unsigned number;
    std::string nim,name;
    std::vector<StudentData> data;
    size_t i=0;
    while (read>>number>>nim>>name)
    {
        data.push_back(StudentData{number,nim,name});
        std::cout<<number<<std::endl;  
    }
    std::cout<<"success store data in vector"<<std::endl;
    std::cout<<"show data in terminal"<<std::endl;
    i=0; //reset counter
    while (i!=MAX_STUDENT)
    {
        std::cout<<data[i].number <<" " << data[i].nim<<" " << data[i].name<<std::endl;
        ++i;
    }
    read.close();    
}
void readStrStream(){
    std::string line,word;
    std::vector<PersonalInfo> people;
    while (std::getline(std::cin,line))
    {
        PersonalInfo info;
        std::istringstream record(line);//bine record to the line we just read
        record>>info.name; // read the name
        while (record>>word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    
}

