#include"nar.h"
#include<iostream>
#include<stdlib.h>
#include<algorithm>

//cf2
//class cf2{cf up_color,down_color;}
cf2::cf2(){	up_color=cf(0);	down_color=cf(1);}
cf cf2::up_col(){return up_color;}
cf cf2::down_col(){return down_color;}
void cf2::print(cf col)const{
	switch (col){
		case white:
			cout<<"white";
			break;
		case black:
			cout<<"black";
			break;
		case yellow:
			cout<<"yellow";
			break;
		case green:
			cout<<"green";
			break;
		case red:
			cout<<"red";
			break;
		case blue:
			cout<<"blue";
			break;
		case pink:
			cout<<"pink";
			break;
		case purple:
			cout<<"purple";
			break;
		case brown:
			cout<<"brown";
			break;
		case grey:
			cout<<"grey";
			break;
		case orange:
			cout<<"orange";
			break;
	}
}
int cf2::input(){  //is error if no namber
	static int b=100;
	int a=0;
	while (true){
		cin >> a;
		if (a>=0 && a<11){ 
			if (a!=b)
				break; 
			else 
				cout << "set anather down player color -";	
		} else
				cout << "select 0-10 numbers";					
	}
	b=a;
	return a;
}
void cf2::chenge_color(){
	cout << "selecting colors are\n";
	for(int i=0;i<11;i++) {cout<<"\n"<<i<<" - ";print(cf(i)); }
	cout<<"\nset  up  player color -";
	up_color = cf(input());
	cout << "set down player color -";
	down_color = cf(input());
	cout << "\nok\n"<<endl;
	cout << "\t up  player color is - ";
	print(up_col());
	cout<<"\n\tdown player color is - ";
	print(down_col());
	cout<<endl;
}
//Fish
//class Fish{}
//upFish
upFish::upFish():color_Fish(cf2::up_col()){}
void upFish::drow() const {cout<<char(1); }
void upFish::rotate(int angle){}
cf upFish::col_fich() const{return color_Fish;}
const upFish& upFish::operator=(const upFish& f){return *this;}
const Fish* upFish::operator=(const Fish*){return this;}
//downFish
downFish::downFish():color_Fish(cf2::down_col()){}
void downFish::drow() const {cout<<char(2); }
void downFish::rotate(int angle){}
cf downFish::col_fich() const{return color_Fish;}
const downFish& downFish::operator=(const downFish& f){return *this;}
const Fish* downFish::operator=(const Fish*){return this;}
//class zar{	z_type z_val;}
z_type random_z(){ 
/*	static z_type z = mek;
	z_type * pz = &z;
	//pz =pz +1;
	return *pz; //time.secund % 10 + 1; 
	*/
//	static unsigned int l=1;
//		l++;
//	srand(l);
	int  i =(double(rand())/RAND_MAX)*6+1;
	return z_type(i);
}
//zar
//togos
togos::togos():val(0) {}
togos::togos(unsigned int i):val(i){}
void togos::chenge_togos(unsigned int i){ val=(i<100)?i:100; }
unsigned int togos::get_togos(){return val;}
zar::zar(){z_val=random_z();}
z_type zar::rez_zar() const {return z_val;}
void zar::rotate_zar_val(z_type z ) { z_val=z;}
void zar::drow() const{
	cout<<"\n  ___"
		<<"\n / "<<rez_zar() <<"/|"
		<<"\n --- |"
		<<"\n | |/"
		<<"\n ---";
}
void zar::rotate(int) {}
//dice
//class dice {zar zar_a, zar_b;}
void dice::to_dice(){
	zar_a.rotate_zar_val(random_z());
	zar_b.rotate_zar_val(random_z());
}
z_type * dice::view_rezult_dice(){
	rezult_dice[0]=zar_a.rez_zar();
	rezult_dice[1]=zar_b.rez_zar();
	return rezult_dice;
} 
void dice::drow() const{
	zar_a.drow();
	zar_b.drow();
}
//pos
pos::pos(){}
Fish* pos::topFish()const{return p_s_f.top();}
void pos::addFish(Fish* f){	p_s_f.push(f);}
bool pos::posEmpty()const{return p_s_f.empty();}
void pos::subFish(){if (!posEmpty()) {p_s_f.pop();}else{/*error*/}}
unsigned int pos::size() const{return (p_s_f.size());}
void pos::rotate(int angle){}
void pos::drow() const{cout << "o";}
bool pos::drow(int i) const{
	if (p_s_f.empty()||(i>p_s_f.size())){	
		return false;
	}else{
		p_s_f.top()->drow();
		return true;
	}
}
//quarter
quarter::quarter(bool u_d,bool R_L):up(u_d),Left(R_L){}
//nar_taxtak
nar_taxtak::nar_taxtak(){
	pos p;
	for (int i=0; i<29;i++)	poses.push_back(p);
	p_ej_pos_up = &poses[num_pos_up];
	p_ej_pos_down = &poses[num_pos_down];
	//	quarter  qupL(1,1),   qupR(1,0),  qdL(0,0),  qdR(0,1);
}
void nar_taxtak::Fish_drow(int j,int i)const{
		if (((0==i)||(18==i))||(!(poses[j].drow(i))))	cout<<" ";
}
void nar_taxtak::TMech(int min,int i)const{
	if ((0==i)||(18==i)){
		for (int j=min; j<min+6;j++) poses[j].drow();
	} else {
		for (int j=min; j<min+6;j++) {
			if (!(poses[j].drow(i))){
				Fish_drow(25-j,18-i);
			}
		}
	}
}
void nar_taxtak::drow() const{
	cout	<<		"\n __________   __________ "
			<<		"\n|  ______  |||  ______  |";
	int maxNum =19;
	for(int i=0;i<maxNum;i++){
		cout	<<	"\n|"; 
					    Fish_drow(num_pos_up,i);
		cout	<<      "|";
						  TMech(1,i);
		cout	<<			   "| | | |";
										TMech(7,i);
		cout	<<							"|";
								  			  Fish_drow(num_pos_down,maxNum-i-1);
		cout	<<							  "|";
	}		
	cout	<<		"\n| |______| ||| |______| |"
			<<		"\n|__________| |__________|"
			<<		"\n";
}
void nar_taxtak::rotate(int angle){}
//nar
nar::nar(){
	zarer.to_dice();
	upFish uf;
	downFish df;
//	upFish* puf;
//	downFish* pdf;
	for(int i=0;i<15;++i) {  //?
		fishes_up.push_back(uf);
		pfishes_up.push_back(&(fishes_up[i]));
		fishes_down.push_back(df);
		pfishes_down.push_back(&(fishes_down[i]));
	}
	Fish* pf;
	for(int i=0;i<fishes_up.size();++i) {
		pf = &fishes_up[i];
		pfishes.push_back(pf);
	}
	for(int i=0;i<fishes_down.size();++i) {
		pf = &fishes_down[i];
		pfishes.push_back(pf);
	}
//	copy(pfishes.begin(),pfishes.end(),puf);
//	copy(pfishes.begin(),pfishes.end(),fishes_down.begin());
}
int nar::nar_interface(bool continu){
	static bool first=1;
	static bool CH_col=0;
	int a;

	if (first){
	 first=0;
	cout<< "\n       --   NARDI  --\n\n"
		<< "default fishes colors\n"
		<< "\t up  player is - white\n"
		<< "\tdown player is - black\n";
	cout<< "\n1 - for chenje colors" ;
	taxtak.drow();
	zarer.drow();
		CH_col=1;
	}
	cout<< "\n";
	for(int i=0;i<pfishes.size();++i) pfishes[i]->drow();	
	cout    << "\n2 - for drow "
			<< "\n3 - for to dice"
			<< "\n9 - for exit"
			<<endl;
	do {
	//while(true){
		cin>>a;
		switch (a) {
			case 1:
				if (CH_col) {
					fishes_colors.chenge_color();
					CH_col=0;
				}
				cout<< "\n1 - don't chenjing colors \n" ;
				break;
			case 2:
				taxtak.drow();
				break;
			case 3:
				zarer.to_dice();
				zarer.drow();
				break;
		//	case 4:
		//		return 0;
		//		break;
			case 9:
				cout << "\n  GAME exit";
				return 0;
				break;
			default:
				return a;
				//throw input_error();
		}
	}while(continu);
	return a;
}
void rotate_all(vector<Shape>& v,int anle){
	//for(int i=0;i>v.size();++i) v[i]->rotate(angle);
}
