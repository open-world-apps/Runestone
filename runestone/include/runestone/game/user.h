#ifndef USER_H
#define USER_H

#include <runestone/base/object.h>
#include <runestone/game/character.h>
#include <runestone/utils/json.h>

class User : public Object
{
private:

	std::string _desc = "A standard user.";
	std::string _username;
	Character* _p_chars;

public:
	User(std::string username);

	virtual Character* getCharacters() = 0;
	virtual Character& getCharacter(unsigned int id) = 0;
	virtual Character& getCharacter(unsigned int id, std::string name) = 0;
	virtual void addCharacter(Character character) = 0;
	virtual void removeCharacter(unsigned int id, std::string name) = 0;
};

#endif