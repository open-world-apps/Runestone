#ifndef JSON_H
#define JSON_H

#include "headers/abstracts/json_rw_base.h"

class JsonRW : public JsonRWBase
	{
	protected:
		rapidjson::StringBuffer _buffer{};
		rapidjson::Document _doc;
		rapidjson::Value& _v = _doc["initial"];
		std::string _file{};
		std::string _query{};
		std::string _data{};

	public:
		JsonRW(std::string file);
		void write() override;
		void subtract() override;
		void replace(std::string newVal) override;
		void replace(int newVal) override;
		void replace(float newVal) override;
		void io() override;
		void addToArray(std::string val) override;
		void increment() override;
		JsonRW& load(std::string query) override;
		std::string read() const override;
		std::string readString() override;
		bool readBool() override;
		int readInt() override;
		float readFloat() override;
	};
#endif