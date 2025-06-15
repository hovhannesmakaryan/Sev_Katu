#include "game_nar.h"
#include <iostream>

#include <fstream>
#include <string>
//game_nar
//size_type game_nar::size() const{return p_s_f.size(); }
//value_type& game_nar::p_top() const{return p_s_f.top();}

int game_nar::Underflow(){return 1;}
int game_nar::color_error(){return 1;}
void game_nar::eject_Fish(pos* at){ //argument don't can everi pos  ?
	if (!at->posEmpty())
	{//fishes_colors.up_col()
		int num_ej=((at->topFish())->col_fich()==fishes_up[1].col_fich())?num_pos_down:num_pos_up;// up-25, down-26
		pos* to = &taxtak.poses[num_ej];
		move_Fish(at, to);
	}else{
		//	trow noFish_error();
	}
}
bool game_nar::eject_Fishes_2() {
	zarer.view_rezult_dice();
	z_type Zmin =(zarer.rezult_dice[0]<zarer.rezult_dice[1])?zarer.rezult_dice[0]:zarer.rezult_dice[1];
	z_type Zmax =(zarer.rezult_dice[0]<zarer.rezult_dice[1])?zarer.rezult_dice[1]:zarer.rezult_dice[0];
	bool zuyg = (Zmin == Zmax);
	if (zuyg){
		for(int i=0;i<4;i++) eject_Fish(&(taxtak.poses[Zmax]));
	} else {
		eject_Fish(&(taxtak.poses[Zmax]));
		eject_Fish(&(taxtak.poses[Zmin]));
	}
	return 1;
}
bool game_nar::eject_Fishes ( bool up, togos t) {
	eject_Fishes_2();
	return 1;
}
void game_nar::posishn(){  /////?????????
	for (int i = fishes_up.size()-1; i>= 0; i-- )  {
		//puf= &fishes_up[i];
		taxtak.p_ej_pos_up->addFish(&fishes_up[i]);
	//	pfishes_up.pop_back();
	}
	for (int i = fishes_down.size()-1; i>= 0; i-- )  {
		taxtak.p_ej_pos_down->addFish(&fishes_down[i]);
	}
}
void game_nar::put_file_posishn(string line,bool up_line){
	string::iterator iter_st;
	int num;
	int poz = up_line?1:24;
	int i_d = up_line?1:(-1);
	for (iter_st = line.begin();
		iter_st != line.end();
		iter_st++ )
	{
		if ('u'== (*iter_st)) {
			iter_st++;
			if (isdigit(*iter_st)) 	num = int(*iter_st)-48;
			if (isalpha(*iter_st)) 	num = int(*iter_st)-55;
			move_Fishes(taxtak.p_ej_pos_up,&taxtak.poses[poz],num);
			poz+=i_d;
		}else if ('d'== (*iter_st)){
			iter_st++;
			if (isdigit(*iter_st)) 	num = int(*iter_st)-48;
			if (isalpha(*iter_st)) 	num = int(*iter_st)-55;
			move_Fishes(taxtak.p_ej_pos_down,&taxtak.poses[poz],num);
			poz+=i_d;
		}else if ('n'== (*iter_st)) {iter_st++; poz+=i_d;}
	}
}
void game_nar::read_file(){
	string fish_pos_line_up,fish_pos_line_down;
	ifstream formula("set_nar.txt",ios::in);
//	while (!formula.eof()) {  }
		getline(formula, fish_pos_line_up); 
		getline(formula, fish_pos_line_up); //2-th line
		getline(formula, fish_pos_line_down);
		getline(formula, fish_pos_line_down); //4-th line
//	cout << "Your  is\n" << fish_pos_line_up << endl;
//	cout << fish_pos_line_down << endl;
	put_file_posishn(fish_pos_line_up, 1);  
	put_file_posishn(fish_pos_line_down, 0);  //? close file
}
void game_nar::to_posishn(){
	pos* at;
	pos* to;
	for (int num_at=1; num_at<25; num_at++ ) {
		at = &taxtak.poses[num_at];
		if ( !at->posEmpty() ){
		to=((at->topFish())->col_fich()==fishes_up[1].col_fich())?taxtak.p_ej_pos_down:taxtak.p_ej_pos_up;
		move_Fishes(at,to,at->size());
		}
	}
}
void game_nar::set_posishn(){
	to_posishn();
	read_file();
	cout << "\n ---Set file pozition---";
}
void game_nar::move_Fish(pos* at, pos* to){
	if (!(at->posEmpty()))
	{
		if (to->posEmpty()||((at->topFish())->col_fich()==(to->topFish())->col_fich()))
		{
			to->addFish(at->topFish());
			at->subFish();
		}else{
		//	trow color_error();
		}
	}else{
	//	trow noFish_error();
	}
}
void game_nar::move_Fishes(pos* at, pos* to, int n){
	for (int i=0; i<n; i++ ) move_Fish(at,to);
}
void game_nar::game_nar_interface(){
	cout<< "\n       -- GAME  NARDI  --\n\n";
	int a;
/*	cout<< "\n4 - for eject "
		<< "\n5 - for seting in file pozitions\n";
	while(a = nar_interface(0)) {
		switch (a) {
			case 4:
				eject_Fishes(1);
				break;
			case 5:
				set_posishn();
				break;
			default:
				break;
		}
		cout<< "\n4 - for eject "
			<< "\n5 - for set file pozition ";
	}
*/
}
//short_nar
void short_nar::start_posishn(){
	pos* at_u = &taxtak.poses[num_pos_up];
	pos* at_d = &taxtak.poses[num_pos_down];
//	pos* to = &taxtak.poses[0];
	move_Fishes(at_u,&taxtak.poses[1],2);
	move_Fishes(at_u,&taxtak.poses[12],5);
	move_Fishes(at_u,&taxtak.poses[17],3);
	move_Fishes(at_u,&taxtak.poses[19],5);
	move_Fishes(at_d,&taxtak.poses[6],5);
	move_Fishes(at_d,&taxtak.poses[8],3);
	move_Fishes(at_d,&taxtak.poses[13],5);
	move_Fishes(at_d,&taxtak.poses[24],2);
}
short_nar::short_nar(){
	posishn();
	start_posishn();
}
//long_nar
void long_nar::start_posishn(){
	pos* at_u = &taxtak.poses[num_pos_up];
	pos* at_d = &taxtak.poses[num_pos_down];
//	pos* to = &taxtak.poses[0];
	move_Fishes(at_u,&taxtak.poses[12],15);
	move_Fishes(at_d,&taxtak.poses[24],15);
	//Fish* puf,*pdf; 
	//int i=0; 
	//puf= &fishes_up[i];
	//pdf= &fishes_down[i];
	//put_fishes(24,pdf,15);
	//put_fishes(12,puf,15);
}
long_nar::long_nar(){
	posishn();
	start_posishn();
}
