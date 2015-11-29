/*
	Header file for the file input/output operations, User class, and Letter class, including the overloaded input and output operators.
*/
#include "std_lib_facilities_4.h"
//#include "Graph.h"
//#include "Window.h"
//#include "GUI.h"
/*
	Class for the game Users. The User's data will be stored after the program exits. Each User consists of:
	a name string, a vector of integer scores, and an image url string.
*/
class User
{
	string name;	//name of the user
	Vector<int> scores;	//Vector of the user's scores
	string image_url;	//url to the image of the user
	bool is_high_score;	//if the user is the high scorer
public:
	User() {}		//default constructor
	User(string n, Vector<int> s, string i, bool ihs): name(n), scores(s), image_url(i), is_high_score(ihs) {}	//constructor
	string get_name() const {return name;}		//function to return the name
	Vector<int> get_scores() const {return scores;}		//function to return the user's scores
	int get_numscores() const {return scores.size();}
	string get_image() const {return image_url;}		//function to return the image url
	bool hs() const {return is_high_score;}
	User& operator=(const User&);	//copy assignment
};
//------------------------------------------------------------------
/*
	Class for the buttons through which the user will input the letters for words.
*/
/*class Letter : public Button
{
	bool is_pressed = false;	//determines if the button is pressed or not
public:
	Letter (Point xy, int w, int h, const string& label) : Button(xy, w, h, label) {}	//constructor
	void button_pressed();		//if the button is pressed, set the is_pressed boolean to true
	void attach(Window&);		//attach the button to the window
};*/
