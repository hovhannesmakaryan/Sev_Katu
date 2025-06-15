/*	pos-hearts 	zar-ivory 	zarer--dice */
#ifndef NAR_H
#define NAR_H
#include"shape.h"
#include <stack>
#include <vector>
using namespace std;
#define num_pos_down 26
#define num_pos_up 25

enum cf {white, black, yellow, green, red, blue, pink, purple, brown, grey, orange};
class cf2{
	int input();
	cf up_color,down_color;
public:
	cf2();
	void chenge_color();
	cf up_col();
	cf down_col();
	void print(cf)const;
};
class Fish:public Shape{
 public:
	virtual cf col_fich() const=0;
	virtual const Fish* operator=(const Fish*)=0;
	void drow() const=0;	
//	void rotate(int angle);
};
class upFish:public Fish,public cf2{
 public:
	const cf color_Fish;
	cf col_fich() const;
	upFish();
	const Fish* operator=(const Fish*);
	const upFish& operator=(const upFish&);
	void drow() const;	
	void rotate(int angle);
};
class downFish:public Fish,public cf2{
 public:
	const cf color_Fish;
	cf col_fich() const;
	const Fish* operator=(const Fish*);
	downFish(); 
	const downFish& operator=(const downFish&);
	void drow() const;	
	void rotate(int angle);
};
enum z_type {mek=1,erku,ereq,chors,hing,vec};
class togos {
	unsigned int val;
 public:
	togos();
	togos(unsigned int);
	void chenge_togos(unsigned int);
	unsigned int get_togos();
};
class zar:public Shape{
	z_type z_val;
 public:
	zar();
	z_type rez_zar() const ;
	void rotate_zar_val(z_type);
	void drow() const;
	void rotate(int angle);	
};
class dice {
	zar zar_a, zar_b;
 public:
	z_type rezult_dice[2];
	void to_dice();
	z_type * view_rezult_dice();
	void show_to_dice();
	void drow() const;
};
class pos:public Shape{
	stack<Fish*> p_s_f; 
 public:
	pos();
	Fish* topFish()const;
	void addFish(Fish*);
	void subFish();
	bool posEmpty()const;
	unsigned int size() const;
	bool drow(int) const;
	void drow() const;
	void rotate(int angle);
};
class quarter{
 public:
	const bool up;
	const bool Left;
	vector<pos> poses_;
	quarter(bool u_d,bool R_L);
};
class nar_taxtak:public Shape{
	void TMech(int min,int i)const;
	void Fish_drow(int j,int i)const;
 public:
	nar_taxtak();
//	class quarter;
//	quarter  q_upL,   qupR,  qdL,  qdR;
//	vector<quarter> Q;
//	pos eject_w;	pos eject_b; 	steak<Fish> out_w;	steak<Fish> out_b;
	vector<pos> poses;
	pos* p_ej_pos_up, *p_ej_pos_down;
	void drow() const;
	void rotate(int angle);
};
class nar{
	cf2 fishes_colors;
public:
	nar_taxtak taxtak;
	dice zarer;
	vector<upFish> fishes_up;
	vector<downFish> fishes_down;
	nar();
	vector<Fish*> pfishes;
	vector<upFish*> pfishes_up;
	vector<downFish*> pfishes_down;
	int nar_interface(bool);
};
#endif