#pragma once
#include <string>

using namespace std;
class monster
{

public:
	int name;
	int atk;
	int def;
	char type;
	bool act = false;
	monster();
	virtual ~monster();
};

