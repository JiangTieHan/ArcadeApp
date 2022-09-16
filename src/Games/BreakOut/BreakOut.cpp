#include "BreakOut.h"
#include <iostream>

void BreakOut::Init(GameController& controller)
{
	std::cout << "BreakOut Game Init()" << std::endl;
}

void BreakOut::Update(uint32_t dt)
{
	std::cout << "BreakOut Game Update()" << std::endl;
}

void BreakOut::Draw(Screen& screen)
{
	std::cout << "BreakOut Game Draw()" << std::endl;
}

std::string BreakOut::GetName() const
{
	return "BreakOut";
}
