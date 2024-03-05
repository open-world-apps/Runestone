#ifndef CHARACTER_H
#define CHARACTER_H

#include <runestone/base/object.h>

struct Character : public Object
{
	std::string firstName;
	std::string middleName;
	std::string lastName;
	std::string bio;
	std::string physical_desc;
	int age;
	float height;
	float weight;

	Character(std::string firstName, std::string middleName, std::string lastName, std::string bio, std::string physical_desc, int age, float height, float weight);

private:
	
};

#endif
