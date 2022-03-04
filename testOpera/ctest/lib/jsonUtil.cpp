#include <string>
#include "json/json.h"
#include <iostream>
#include <fstream>
using namespace std;

void readStrJson(); //���ַ����ж�ȡJSON
void readStrProJson(); //���ַ����ж�ȡJSON�����ݸ���Щ��

int main(int argc, char* argv[])
{
	readStrJson();

	cout << "\n\n";
	readStrProJson();

	return 0;
}

//���ַ����ж�ȡJSON
void readStrJson()
{
	//�ַ���
	const char* str =
		"{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
		"\"born\":-100,\"died\":-44}";

	/*
	//json�������£�
	{
		  "praenomen":"Gaius",
		  "nomen":"Julius",
		  "cognomen":"Caezar",
		  "born":-100,
		  "died":-44
	  }
	*/

	Json::Reader reader;
	Json::Value root;

	//���ַ����ж�ȡ����
	if (reader.parse(str, root))
	{
		string praenomen = root["praenomen"].asString();
		string nomen = root["nomen"].asString();
		string cognomen = root["cognomen"].asString();
		int born = root["born"].asInt();
		int died = root["died"].asInt();

		cout << praenomen + " " + nomen + " " + cognomen
			<< " was born in year " << born
			<< ", died in year " << died << endl;
	}

}

//���ַ����ж�ȡJSON�����ݸ���Щ��
void readStrProJson()
{
	string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";
	/*
	//json�������£�
	{
	"name": "json��,
	"array": [
		{
			"cpp": "jsoncpp"
		},
		{
			"java": "jsoninjava"
		},
		{
			"php": "support"
		}
	]
	}
	*/


	Json::Reader reader;
	Json::Value value;

	if (reader.parse(strValue, value))
	{
		string out = value["name"].asString();
		cout << out << endl;
		const Json::Value arrayObj = value["array"];
		for (unsigned int i = 0; i < arrayObj.size(); i++)
		{
			if (!arrayObj[i].isMember("cpp"))
				continue;
			out = arrayObj[i]["cpp"].asString();
			cout << out;
			if (i != (arrayObj.size() - 1))
				cout << endl;
		}
	}
}