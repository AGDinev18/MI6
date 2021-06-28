#pragma once
#include <iostream>
class Beach
{
public:
	void setQuantity(float x)
	{
		quantity = x;
	}
private:
	std::string region;
	float quantity;
};