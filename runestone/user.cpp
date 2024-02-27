#include "user.h"

class User : private Object
{
private:
	int _id;
	string _username;
	string _password;
	string _email;
	string _name;

public:
	User(string username, string password, string email) : Object(_id, _name)
	{
		_username = username;
		_password = password;
		_email = email;
	}
};