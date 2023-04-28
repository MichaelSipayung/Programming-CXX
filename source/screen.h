#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <vector>

class Screen{
    public:
        typedef std::string::size_type pos;\
        //adding constructors
        Screen()=default;
        Screen(pos ht,pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}
        char get()const{
            return contents[cursor];
        }
        inline char get(pos ht,pos wd)const; //explicitly inline
        Screen &move(pos r,pos c); //can be made inline later
        void some_member()const;
        //function that return this
        Screen &set(char);
        Screen &set(pos,pos,char);
        //display overloaded on whether the object is const or not
        Screen &display(std::ostream&os){
            do_display(os); return *this;
        }
        /*const Screen &display(std::ostream &os){
            do_display(os);return /**this;
        }*/
        //friendship between two class
        friend class Window_mgr; //share screen member or data to window_mgr class
        //making a member function a friend
        //clean must have been declared before class screen
        //friend void Window_mgr::clean(ScreenIndex);
        //overloaded function and friendship
        friend std::ostream& storeOn(std::ostream&,Screen&);
    private:
        pos cursor=0;
        pos height=0,width=0;
        std::string contents;
        mutable size_t access_ctr; //may change even in a const object
        void do_display(std::ostream &os)const{
            os<<contents;
        } 
};
//overloaded function and friendship
//extern Bitmap& storeOn(BitMap&,Screen&)
extern std::ostream &storeOn(std::ostream&,Screen &);

//define in the same header, because the declaration explicitly inline function
//all inline function must define in the same header
char Screen::get(pos r,pos c)const{
    pos row=r*width;    //compute the row location
    return contents[row+c]; //return character at the given column
}
inline Screen &Screen::move(pos r,pos c){ //we can specify inline on the function
    pos row = r*width;  //compute the row location
    cursor  = row+c;    //move cursor to the column within that row
    return *this; //return this object as an lvalue
}
inline Screen &Screen::set(char c){
    contents[cursor]=c; //set the new value at the current cursor location
    return *this;   //return this object as an lvalue
}
inline Screen &Screen::set(pos r,pos col,char ch){
    contents[r*width+col] = ch; //set specified location to given value
    return *this;   //return this object as an lvalue
}
class Window_mgr{
    public:
        //location ID for each screen on the window
        using ScreenIndex  = std::vector<Screen>::size_type;
        //reset the screen at the given position to all blanks
        void clear(ScreenIndex);
        //making a member function a friend
        void clean(ScreenIndex);
        //add a screen to the window and returns its index
        ScreenIndex addScreen(const Screen&);
    private:
        //screens this window_mgr is tracking
        std::vector<Screen> screen{Screen(22,80,' ')};
};
struct FirstClass
{
    int data_1;
    std::string contents;
};
struct SecondClass{
    int data_1;
    std::string contents;
};

#endif