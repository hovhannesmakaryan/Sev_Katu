/*	pos-hearts, dimple 	zarer--dice 
	togos-percentage */
#include "nar.h"
class game_nar:public nar
{
//	size_type size() const;
//	value_type& p_top() const;
	int	color_error();
	int Underflow();
	void put_file_posishn(string,bool);
	void read_file();
	void to_posishn();
	bool eject_Fishes_2 ();
 public:
	void posishn();
	virtual void start_posishn()=0;
	void set_posishn();
	void move_Fish(pos* at, pos* to);
	void move_Fishes(pos* at, pos* to, int n);
	void eject_Fish(pos* at);
	virtual bool eject_Fishes( bool up, togos t=0);
	void game_nar_interface();
};
//short_nar
class short_nar:public game_nar
{
 public:	
	void out_fish(pos);
	void in_fish(pos);
	short_nar();
	void start_posishn();
};
//long_nar
class long_nar:public game_nar
{
 public:
	void start_posishn();
	long_nar();
};