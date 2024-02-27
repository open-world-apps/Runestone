#include "object.h"

class Object
{
private:
	int _id;
	string _name;
	string _desc;

public:
	Object(int id, string name)
	{
		_id = id;
		_name = name;
	}

	Object(int id, string name, string desc)
	{
		_id = id;
		_name = name;
		_desc = desc;
	}

	int id() const { return _id; }

	string name() const { return _name; }
	string desc() const { return _desc; }
	
	void name(string name) { _name = name; }
	void desc(string desc) { _desc = desc; }
};