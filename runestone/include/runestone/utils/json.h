#ifndef JSON_RW_BASE_H
#define JSON_RW_BASE_H

#include <iostream>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <string>
#include <map>

namespace json
{
	std::map<int, std::string> mappedTypes = {
		{ 0, "NULL" },
		{ 2, "bool" },
		{ 3, "object" },
		{ 4, "array" },
		{ 5, "string" },
		{ 6, "number" },
	};
	
	class JsonRW
	{
	private:
		static rapidjson::Document initDoc(std::string file)
		{
			std::ifstream i(file);
			if (!i.is_open()) {
				std::cerr << "Error" << std::endl;
			}

			std::string json((std::istreambuf_iterator<char>(i)), std::istreambuf_iterator<char>());

			rapidjson::Document doc;
			doc.Parse(json.c_str());

			if (doc.HasParseError())
			{
				std::cerr << "Parse Error" << std::endl;
			}

			i.close();

			return doc;
		};

		std::string _file{};
		std::string _query{};
		rapidjson::Document _doc{};

	public:
		JsonRW();
		JsonRW(std::string file);
		
		 void write();
		 void replace(std::string newVal);
		 void replace(int newVal);
		 void replace(float newVal);
		 void io();
		 void increment();
		 void decrement();
		 void add(float f);
		 void add(int i);
		 void subtract(int i);
		 void subtract(float f);
		 void math(int val);
		 void math(float val);
		 rapidjson::Document& doc();
		 JsonRW& query(std::string query);
		 std::string file() const { return _file; }
		 std::string read();
		 std::string readString();
		 bool readBool();
		 int readInt();
		 float readFloat();
	};
}


#endif
