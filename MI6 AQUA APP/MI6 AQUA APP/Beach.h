#pragma once
#include <iostream>

enum Flag
{
	green, yellow, red
};

class Beach
{
public:
	void setName(std::string name)
	{
		name_ = name;
	}
	std::string returnName()
	{
		return name_;
	}
	void setGroundSwell(bool groundSwell)
	{
		groundSwell_ = groundSwell;
	}
	bool returnGround()
	{
		return groundSwell_;
	}
	void setBeachUmbrellaPrice(double beachUmbrellaPrice)
	{
		beachUmbrellaPrice_ = beachUmbrellaPrice;
	}
	double returnUmbrellaPrice()
	{
		return beachUmbrellaPrice_;
	}
	void setSunbedPrice(double sunbedPrice)
	{
		sunbedPrice_ = sunbedPrice;
	}
	double returnSunbedPrice()
	{
		return sunbedPrice_;
	}
	void setSwimmingPermission(bool swimmingPermission)
	{
		swimmingPermission_ = swimmingPermission;
	}
	bool returnSwimmingPermission()
	{
		return swimmingPermission_;
	}
	void setSwimmingFlag(Flag flag)
	{
		flag_ = flag;
	}
	Flag returnFlag()
	{
		return flag_;
	}
private:
	std::string name_;
	bool groundSwell_;
	double beachUmbrellaPrice_;
	double sunbedPrice_;
	bool swimmingPermission_;
	Flag flag_;
};