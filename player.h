#pragma once
#include "monster.h"
#include <vector>
class player
{

	
public:
	int life;
	string name;
	vector<monster> cards;
	//queue<monster> atk_que;
	//queue<monster> def_que;
	player(string name);
	virtual ~player();
};

