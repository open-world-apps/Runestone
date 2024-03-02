#include "user.h"

class User : public BaseUser
{
private:
	string _username;

protected:
	void setUsername(string username) override { _username = username; }

public:
	User(string username) : BaseUser(username) {}
};