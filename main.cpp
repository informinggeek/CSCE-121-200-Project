#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;



// ----------------------------------------------------------
// Struct for main Game_Window
// ----------------------------------------------------------
struct Game_Window : Graph_lib::Window {
public:
    Game_Window(Point xy,int w,int h,const string& title);
    int grid_size = 0;
    
private:
    Button quit_button;         // end program
    Button create_grid;         // create the grid
    In_box name_in;             // box for entering x coord of next point
    Menu grid_menu;             // menu of color choices for the lines
    Button grid_menu_button;    // button to display the color menu
    
    
    
    // ----------------------------------------------------------
    
    // ----------------------------------------------------------
    
    
    
    // functions defined below outside of struct
    void hide_menu();
    void three_pressed();
    void four_pressed();
    void five_pressed();
    void menu_pressed();
    void next();
    void quit();
    
    // callback functions; declared here and defined below
    static void cb_threexthree(Address, Address);
    static void cb_fourxfour(Address, Address);
    static void cb_fivexfive(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
};




// ----------------------------------------------------------
// now define the parts of Game_Window that were only declared inside class
// ----------------------------------------------------------
Game_Window::Game_Window(Point xy, int w, int h, const string& title) :
Window(xy,w,h,title),                                                                       // call constructor or base class
create_grid(Point(x_max()/2 - 150,y_max()/2 - 20),250,40,"Create Grid",cb_next),            // initialize the next button
quit_button(Point(x_max()-70,0),70, 20,"Quit",cb_quit),                                     // initialize quit button
name_in(Point(x_max()/2 - 140,y_max()/2 - 50),100, 20,"Name:"),                             // initialize the outbox
grid_menu(Point(x_max() - 275,y_max()/2 - 50),120, 20,Menu::vertical,"Grid"),               // initialize the color menu
grid_menu_button(Point(x_max() - 275,y_max()/2 - 50),120, 20,"Select Grid Size",cb_menu)    // initialize the menu button

{
    attach(create_grid);
    attach(quit_button);
    attach(name_in);
    
    grid_menu.attach(new Button(Point(0,0),0,0,"3x3",cb_threexthree));
    grid_menu.attach(new Button(Point(0,0),0,0,"4x4",cb_fourxfour));
    grid_menu.attach(new Button(Point(0,0),0,0,"5x5",cb_fivexfive));
    
    attach(grid_menu);
    
    grid_menu.hide();
    
    attach(grid_menu_button);
    
    // ----------------------------------------------------------
    
    // ----------------------------------------------------------
    
}









// ----------------------------------------------------------
// definitions of previously declared functions inside struct
// ----------------------------------------------------------
void Game_Window::hide_menu() {
    grid_menu.hide();
    grid_menu_button.show();
}
void Game_Window::menu_pressed() {
    grid_menu_button.hide();
    grid_menu.show();
}
void Game_Window::three_pressed() {
    grid_size = 3;
    hide_menu();
}
void Game_Window::four_pressed() {
    grid_size = 4;
    hide_menu();
}
void Game_Window::five_pressed() {
    grid_size = 5;
    hide_menu();
}
void Game_Window::next() {
    detach(grid_menu_button);
    detach(name_in);
    detach(create_grid);
}
void Game_Window::quit() {
    hide();
}
// ----------------------------------------------------------

// ----------------------------------------------------------







// ----------------------------------------------------------
// Boilerplate code for callback functions
// ----------------------------------------------------------
void Game_Window::cb_quit(Address, Address pw) {
    reference_to<Game_Window>(pw).quit();
}
void Game_Window::cb_next(Address, Address pw) {
    reference_to<Game_Window>(pw).next();
}
void Game_Window::cb_threexthree(Address, Address pw) {
    reference_to<Game_Window>(pw).three_pressed();
}
void Game_Window::cb_fourxfour(Address, Address pw) {
    reference_to<Game_Window>(pw).four_pressed();
}
void Game_Window::cb_fivexfive(Address, Address pw) {
    reference_to<Game_Window>(pw).five_pressed();
}
void Game_Window::cb_menu(Address, Address pw) {
    reference_to<Game_Window>(pw).menu_pressed();
}
// ----------------------------------------------------------

// ----------------------------------------------------------



int main()
try {
    Game_Window win(Point(100,100),600,400,"Welcome");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
    }
    catch(...) {
        cerr << "some exception\n";
        return 2;
    }

