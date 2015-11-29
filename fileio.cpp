#include "fileio.h"
/*
	Copy assignment operator for use in input
*/
User& User::operator=(const User& u)
{
	name=u.get_name();
	scores=u.get_scores();
	image_url=u.get_image();
}
/*
	Overloaded input and output operators, based upon the file format described below.
	
	[# of entries]
	[name] | [# of scores] | [score 1] [score 2] [score 3] [score n] | [image_url] | [high_scorer/not];
*/
istream& operator>>(istream& is, User& u)
{
	string name;	//name of the user
	int numscores;	//number of scores the user has
	int score;	//a single score
	Vector<int> s;	//vector of scores
	char t;		//terminating character
	char t1;	//extra terminating character
	string i;	//image url
	string hs;	//whether the user is the high scorer or not
	bool b=false;		//

	if(!is) return is;	//if file was not opened properly
	is>>name>>t>>numscores>>t1;		//read in name and the number of scores
	if(t!='|'||t1!='|')	//incorrect seperation character
	{
		is.clear(ios_base::failbit);	//set state to fail
		return is;	//leave
	}
	for(int k=0;k<numscores;++k)	//read in the scores
	{
		is>>score;
		s.push_back(score);
	}
	is>>t>>i>>t1>>hs;
	if(t!='|'||t1!='|')	//incorrect seperation character
	{
		is.clear(ios_base::failbit);	//set state to fail
		return is;	//leave
	}
	if(hs=="high_scorer") b=true;
	u = User(name, s, i, b);	//update u to reflect the inputted values
	return is;		//leave with is in a good state
}
/*
	Overloaded output operator, in the same format as the input operator
*/
ofstream& operator<<(ofstream& os, User& u)
{
	if(!os) return os;	//if the file was not properly opened for writing
	os<<u.get_name()<<'|'<<u.get_numscores()<<'|';	//write name and number of scores
	Vector<int> s=u.get_scores();	//get the vector of scores
	for(int i=0;i<u.get_numscores();++i)
	{
		os<<s[i]<<" ";
	}
	os<<u.get_image();	//write the image url
	if(u.hs()==true)	//if the user is the high scorer
	{
		os<<"high_scorer"<<endl;
		return os;	//leave
	}
	os<<"not"<<endl;	//if the user is not the high scorer
	return os;		//leave
}
/*main for file operations testing--not to be used in final program*/
/*int main()
{
	string iname;		//name of input file
	cin>>iname;		//Needs to be changed, either with prompt or to static file name 
	ifstream ist {iname};	//input stream
	if (!ist) error("Can not open input file ",iname);
	User u;		//Test user
	ist>>u;
	cout<<u.get_name()<<endl;
	Vector<int> scores=u.get_scores();
	for(int i=0;i<scores.size();++i)
	{
		cout<<scores[i]<<endl;
	}
	cout<<u.get_image()<<endl;
	return 0;
}*/
