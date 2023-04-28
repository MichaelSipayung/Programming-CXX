#include "screen.h"
void Screen::some_member()const{
    ++access_ctr; //keep a count of the calls to any member function
}
void Window_mgr::clear(ScreenIndex i){
    Screen &s = screen[i];
    s.contents = std::string(s.height*s.width,' ');
}
//understanding scope in the class
//return screen index in the scope (window_mgr)
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen&s){
    screen.push_back(s);
    return screen.size()-1;
}