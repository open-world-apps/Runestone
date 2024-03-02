#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "json.h"

class Object
{
	static int generateID() {
		JsonRW r("entities.json");
		JsonRW& data = r.load("item_count");
		data.increment();

		return data.readInt();
	};

private:
	int _id;
	int _defense;
	float _hp;
	std::string _name;
	std::string _desc;

protected:
	Object() {
		_id = generateID();
	}

	Object(std::string name, float hp, int def = 0)
	{
		_id = generateID();
		_name = name;
		_hp = hp;
		_defense = def;
	}

	Object(std::string name, std::string desc)
	{
		_id = generateID();
		_name = name;
		_desc = desc;
		_hp = 99999999999999999;
		_defense = 99999999999999999;
	}

	Object(std::string name, std::string desc, float hp, float def = 0)
	{
		_id = generateID();
		_name = name;
		_desc = desc;
		_hp = hp;
	}

	int id() const { return _id; }
	float getHP() const { return _hp; }
	std::string getName() const { return _name; }
	std::string getDesc() const { return _desc; }

	virtual void setName(std::string name) = 0;
	virtual void setDesc(std::string desc) = 0;
	virtual void setHP(float hp) = 0;
	virtual void setDef(int def) = 0;
};

#endif