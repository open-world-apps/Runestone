#ifndef ITEM_H
#define ITEM_H

#include "../abstracts/object.h"

class Item : public Object
{
private:
	std::string _insp_str;
public:
	Item();
	Item(std::string name, float hp, int def);
	Item(std::string name, std::string def);
	Item(std::string name, std::string desc, float hp, int def);

	std::string inspect();
	void adjustHP(float val);
	void setName(std::string name) override;
	void setDesc(std::string desc) override;
	void setHP(float hp) override;

	/*
	--------------------------------------------------
	|	Name: Smirnoff               defense: 5 hp: 34 |
	|------------------------------------------------|
	| Description																		 |
	| Looks like a bottle of booze.                  |
	|																								 |
	|________________________________________________|
	*/
};

#endif