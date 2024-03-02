#include "headers/game/item.h"

using namespace std;

Item::Item() {}
Item::Item(string name, string desc) : Object(name, desc) {}
Item::Item(string name, float hp, int def) : Object(name, hp, def) {}
Item::Item(string name, string desc, float hp, int def) : Object(name, desc, hp, def) {}

void Item::setName(string name)
{
	setName(name);
}

void Item::setDesc(string desc)
{
	setDesc(desc);
}

void Item::setHP(float hp)
{
	setHP(hp);
}

void Item::adjustHP(float val)
{

}

string Item::inspect()
{

}
