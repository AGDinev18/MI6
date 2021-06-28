#pragma once
#include <iostream>

enum Flag
{
	green, yellow, red
};

class Beach
{
public:
	void setGroundSwell(bool groundSwell)
	{
		groundSwell = groundSwell;
	}
	void setBeachUmbrellaPrice(double beachUmbrellaPrice)
	{
		beachUmbrellaPrice = beachUmbrellaPrice;
	}
	void setSunbedPrice(double sunbedPrice)
	{
		sunbedPrice = sunbedPrice;
	}
	void setSwimmingPermission(bool swimmingPermission)
	{
		swimmingPermission = swimmingPermission;
	}
	void setSwimmingFlag(Flag flag)
	{
		flag = flag;
	}
	std::string name;
private:
	bool groundSwell;
	double beachUmbrellaPrice;
	double sunbedPrice;
	bool swimmingPermission;
	Flag flag;
};