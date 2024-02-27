#ifndef OBJECT_H
#define OBJECT_H

#include <string>

using namespace std;

class Object
{
private:
	int _id;
	string _name;
	string _desc;

public:
	Object(int id, string name);
	Object(int id, string name, string desc);

	virtual int id() const = 0;
	virtual string name() const = 0;
	virtual string desc() const = 0;
	virtual void name(string name) = 0;
	virtual void desc(string desc) = 0;
};

#endif