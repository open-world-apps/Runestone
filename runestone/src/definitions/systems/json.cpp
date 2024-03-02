#include "json.h"
#include <algorithm>

using namespace std;
using namespace rapidjson;

static Document initDoc(string file)
{
	ifstream i(file);
	if (!i.is_open()) {
		cerr << "Error" << endl;
	}

	string json((istreambuf_iterator<char>(i)), istreambuf_iterator<char>());

	Document doc;
	doc.Parse(json.c_str());

	if (doc.HasParseError())
	{
		cerr << "Parse Error";
	}

	i.close();

	return doc;
};

JsonRW::JsonRW(string file) : _doc(initDoc(file)), _file(file)
{
	PrettyWriter<StringBuffer> writer(_buffer);
	_doc.Accept(writer);
}

string JsonRW::read() const
{
	return _buffer.GetString();
}

int JsonRW::readInt()
{
	if (_v.IsInt())
	{
		return _v.GetInt();
	}
	else
	{
		cerr << "Value is not an integer." << endl;

		return 1;
	}
}

float JsonRW::readFloat()
{
	
	if (_v.IsFloat() or _v.IsInt())
	{
		return _v.IsFloat() ? _v.GetFloat() : _v.GetInt();
	}
	else
	{
		cerr << "Value is not a float or an integer";

		return 1;
	}
}

bool JsonRW::readBool()
{
	if (_v.IsBool())
	{
		return _v.GetBool();
	}
	else if (_v.IsNull())
	{
		return false;
	}
	else
	{
		cerr << "Value is not bool." << endl;
		return false;
	}
}

string JsonRW::readString()
{
	if (_v.IsString()) {
		return _v.GetString();
	}
	else {
		cerr << "Value is not a string." << endl;

		return "";
	}
}

/**
 * Loads data from json to be manipulated.
 * 
 * \param query The data to load
 * \return The class instance
 */
JsonRW& JsonRW::load(string query)
{
	_v = _doc[query.c_str()];
	return *this;
}

void JsonRW::replace(string newVal)
{
	_v.SetString(newVal.c_str(), newVal.length());
	write();
}

/**
 * Writes the data to file.
 * 
 */
void JsonRW::write()
{
	Writer<StringBuffer> writer(_buffer);
	_doc.Accept(writer);

	ofstream o(_file);
	o << _buffer.GetString() << endl;
	o.close();
}

void JsonRW::increment()
{
	if (_v.IsNumber())
	{
		if (_v.IsInt())
		{
			_v.SetInt(_v.GetInt() + 1);
		}
		else if (_v.IsFloat())
		{
			_v.SetFloat(_v.GetFloat() + 1);
		}

		write();
	}
	else {
		cerr << "Value is not a number.";
	}
}

void JsonRW::subtract()
{
	if (_v.IsNumber())
	{
		if (_v.IsInt())
		{
			_v.SetInt(_v.GetInt() - 1);
		}
		else if (_v.IsFloat())
		{
			_v.SetFloat(_v.GetFloat() + 1);
		}

		write();
	}
	else
	{
		cerr << "Value is not a number.";
	}
}

void JsonRW::replace(int newVal)
{
	if (_v.IsInt())
	{
		_v.SetInt(newVal);
	}
	else {
		cerr << "Value is not an integer." << endl;
	}
}

void JsonRW::replace(float newVal)
{
	if (_v.IsFloat() or _v.IsInt())
	{
		_v.SetFloat(newVal);
	}
	else
	{
		cerr << "Value is not a float or integer." << endl;
	}
}

/**
 * Reverses a bool value.
 */
void JsonRW::io()
{
	_v.SetBool(_v.GetBool() == false ? true : false);
}
