#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <runestone/utils/json.h>

class Object
{
private:

	static unsigned int generateID()
	{
		json::JsonRW j("entities.json");

		j.query("item_count").increment();
		unsigned int item_count = j.query("item_count").readInt();

		return item_count;
	}

	unsigned int _id;
	float _def;
	float _hp;
	std::string _name;
	std::string _desc;

protected:
	Object(std::string name, float hp, float def = 0);
	Object(std::string name, std::string desc);
	Object(std::string name, std::string desc, float hp, float def = 0);

	int id() const { return _id; }
	float getHP() const { return _hp; }
	float getDef() const { return _def; }
	std::string getName() const { return _name; }
	std::string getDesc() const { return _desc; }

	virtual void setName(std::string name) = 0;
	virtual void setDesc(std::string desc) = 0;
	virtual void setHP(float hp) = 0;
	virtual void setDef(float def) = 0;
};

#endif