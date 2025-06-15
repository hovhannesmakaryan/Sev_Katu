
#include"game_nar.h"
class long_nar:public game_nar
{
	void start_posishn();




}

long_nar::long_nar():
{
	void start_posishn();


}

void long_nar::start_posishn()
{
	for(i=0;i<15;++i) {
		move_f(eject_w, poses[24]);
		move_f(eject_b, poses[12]);
	}
}