#include "object.h"

class User : private Object
{
private:
	int _id;
	string _username;
	string _password;
	string _email;
	string _name;
	
	virtual string password() const = 0;
	virtual void password(string password) = 0;

public:
	User(string username, string password, string email);
	virtual string username() const = 0;
	virtual string email() const = 0;
	virtual void username(string username) = 0;
	virtual void email(string email) = 0;
};

