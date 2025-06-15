#include"game_nar.h"
#include <iostream>
using namespace std;
//typedef long_nardi nardi;
void game();

class input_error {
public:void throw_f();
	   input_error(){cerr<<"Error";return;}
};
int main()
{
	int m;
	try{
		game();
	}
	catch(std::ios_base::failure){
		cout<<"error";
		cin >>m;
	}
	cout << "\nNormal exit";
	cin >>m;
	return 0;
}

void game()
{
	game_nar * pnardi;
//	short_nar short_nardi;// 	pnardi = &short_nardi;
//	long_nar long_nardi;  //  pnardi = &long_nardi;

//	pnardi->game_nar_interface();
}
void input_error::throw_f(){
	int f;
	cout<<"\nthrow_f";
	cin >> f;
}
