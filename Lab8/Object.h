#pragma once
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

class Object
{
public:
	Object(void);
	virtual void show() = 0; 
	virtual void input() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
	~Object(void);
};
