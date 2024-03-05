#include <runestone/utils/json.h>
#include <format>

using namespace std;
using namespace json;
using namespace rapidjson;

JsonRW::JsonRW() {}
JsonRW::JsonRW(string file) : _doc(initDoc(file)), _query("game_data") {}

Document& JsonRW::doc()
{
	return _doc;
}

string JsonRW::file() const
{
	return _file;
}

void JsonRW::write()
{
	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
	_doc.Accept(writer);

	ofstream o(_file);
	o << _buffer.GetString() << endl;
	o.close();
}

void JsonRW::replace(string newVal)
{
	Value& _data = _doc[_query.c_str()];
	_data.SetString(newVal.c_str(), newVal.length());
	write();
}

void JsonRW::replace(int newVal)
{
	Value& _data = _doc[_query.c_str()];
	_data.SetInt(newVal);
	write();
}

void JsonRW::replace(float newVal)
{
	Value& _data = _doc[_query.c_str()];
	_data.SetFloat(newVal);
	write();
}

void JsonRW::io()
{
	Value& _data = _doc[_query.c_str()];
	
	if (_data.IsBool())
	{
		_data.GetBool() == true 
			? _data.SetBool(false)
			: _data.SetBool(true);
	}
	else
		cerr << "Value is not a bool." << endl;

	write();
}

JsonRW& JsonRW::query(string query)
{
	_query = query;

	return *this;
}

void JsonRW::math(int i)
{
	Value& _data = _doc[_query.c_str()];

	if (_data.IsInt() or _data.IsFloat()) {
		_data.IsInt()
			? _data.SetInt(_data.GetInt() + i)
			: _data.SetFloat(_data.GetFloat() + i);
	}
	else {
		cerr << format("Data is incorrect data type: {}", _data) << endl;
	}
}

void JsonRW::math(float f)
{
	Value& _data = _doc[_query.c_str()];

	if (_data.IsInt() or _data.IsFloat()) {
		_data.IsFloat()
			? _data.SetFloat(_data.GetFloat() + f)
			: _data.SetFloat(_data.GetInt() + f);
	}
	else {
		cerr << format("Data is incorrect data type: {}", _data) << endl;
	}
}

void JsonRW::add(int i)
{
	math(i);
}

void JsonRW::add(float f)
{
	math(f);
}

void JsonRW::subtract(int i)
{
	math(-i);
}

void JsonRW::subtract(float f)
{
	math(-f);
}

void JsonRW::increment()
{
	math(1);
}

void JsonRW::decrement()
{
	math(-1);
}

string JsonRW::read()
{
	return buffer().GetString();
}

int JsonRW::readInt()
{
	Value& _data = _doc[_query.c_str()];

	if (_data.IsInt())
		return _data.GetInt();
	else
	{
		cerr << format("Received data is not an int: {}", mappedTypes[_data.GetType()]) << endl;
		return 1;
	}
}

float JsonRW::readFloat()
{
	Value& _data = _doc[_query.c_str()];

	if (_data.IsFloat())
		return _data.GetFloat();
	else
	{
		cerr << format("Received data is not a float: {}", mappedTypes[_data.GetType()]) << endl;
		return 1;
	}
}

string JsonRW::readString()
{
	Value& _data = _doc[_query.c_str()];

	if (_data.IsString())
		return _data.GetString();
	else
	{
		cerr << format("Received data is not a string: {}", mappedTypes[_data.GetType()]) << endl;
		return "false";
	}
}

bool JsonRW::readBool()
{
	Value& _data = _doc[_query.c_str()];

	if (_data.IsBool())
		return _data.GetBool();
	else
	{
		cerr << format("Received data is not a bool: {}", mappedTypes[_data.GetType()]) << endl;
		return false;
	}
}
