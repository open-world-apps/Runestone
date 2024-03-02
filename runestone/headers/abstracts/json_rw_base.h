#ifndef JSON_RW_BASE_H
#define JSON_RW_BASE_H

#include <iostream>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <string>
#include <type_traits>

enum DataType {
	Null = 0,
	Bool = 2,
	Object = 3,
	Array = 4,
	String = 5,
	Number = 6,
};

class JsonRWBase
{
	protected:
		virtual void write() = 0;
		virtual void replace(std::string newVal) = 0;
		virtual void replace(int newVal) = 0;
		virtual void io() = 0;
		virtual void replace(float newVal) = 0;
		virtual void addToArray(std::string val) = 0;
		virtual void subtract() = 0;
		virtual void increment() = 0;
		virtual JsonRW& load(std::string query) = 0;
		virtual std::string read() const = 0;
		virtual std::string readString() = 0;
		virtual bool readBool() = 0;
		virtual int readInt() = 0;
		virtual float readFloat() = 0;
};

#endif
