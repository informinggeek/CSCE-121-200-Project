#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;



struct Game_Window : Graph_lib::Window {       // inherits from Window
    
    // constructor
    Game_Window(Point xy,             // top lefthand corner
                   int w,                // width
                   int h,                // height
                   const string& title); // label
private:
    Button quit_button;                // end program

   
//Widgets for End Window//
    Out_box score;		   //the user's score
    Out_box words;		   //the number of words the user entered

//Widgets for not high score//
    Out_box high_score;		   //the game's high score
    Out_box hs_name;		   //the name of the high scorer

//Widgets for high score//
    Text congrats;		   //text box congratulating the user on their acheivement
    In_box pic_url;		   //input for the user's picture of themselves


//Functions for End Window//
//-----------------------------------------//
    void quit();   // defined below
    void winner();
    void loser();

    static void cb_quit(Address, Address);   
};

// ----------------------------------------------------------
// now define the parts of Game_Window that were only declared
// inside the class

// constructor:

Game_Window::Game_Window(Point xy, int w, int h, const string& title) :

// initialization - start by calling constructor of base class
Window(xy,w,h,title),


/*End Window definitions*/
//---------------------------------//
//quit button
quit_button(
     Point(100, 300),
     70, 20,
     "Quit",
      cb_quit),
//score outbox
score(
      Point(100,0),
      100, 20,
      "Your Score:"),
words(
     Point(100,50),
     100, 20,
     "Your Words:"),
/*high score definitions*/
//--------------------------------//
congrats(
     Point(x_max()-100,0),
     "You made the High Score!"),
pic_url(Point(100, 100), 100, 20, "Your Picture (JPEG):"),
/*Not high score definitions*/
//--------------------------------//
high_score(
     Point(100, 100),
     100, 20,
     "High Score:"),
hs_name(
     Point(300,150),
     100, 20,
     "Made By:")

// body of constructor follows
{
    // attach buttons and boxes to window
  
    attach(quit_button);
    attach(score);
    attach(words);
    
}

// ----------------------------
// callback function for quit button - boilerplate:
// When the button is pressed, the system invokes the
// specified callback function.  First argument is address of the
// button (which we won't use, so we don't bother to name it).  Second
// argument, named pw, is address of the window containing the pressed
// button, i.e., address of our Game_Window object.  reference_to
// converts the address pw into a reference to a Game_Window object,
// so we can call the quit() function.  Objective is to call function
// quit() which does the real work specific to this button.

void Game_Window::cb_quit(Address, Address pw) {
    reference_to<Game_Window>(pw).quit();   // quit is defined next
}

void Game_Window::quit() {
    hide();
}
void Game_Window::loser()
{
    attach(high_score);
    attach(hs_name);
}
void Game_Window::winner()
{
    attach(pic_url);
}
int main()
try {
    //Vector<User> players;	//vector of Users
    // construct the GUI window
    Game_Window win(Point(100,100),600,400,"Word Game");
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

