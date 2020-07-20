#include "MyString.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace assignment1;
int main()
{
	MyString s1("");
	s1.Interleave(""); // s1Àº ¡°H eWlolrold¡±

	std::cout << s1.GetCString() << std::endl;

	//assignment1::MyString my1("pope pope");
	//std::string s1("pope pope");

	//const char* cString = my1.GetCString();
	//assignment1::MyString copied(my1);

	//// E0, E1
	//assert(my1.IndexOf("p") == s1.find("p"));

	//assert(my1.LastIndexOf("p") == s1.rfind("p"));

	//assert(my1.IndexOf("pop") == s1.find("pop"));
	//assert(my1.LastIndexOf("pop") == s1.rfind("pop"));

	//assert(my1.IndexOf("popen") == s1.find("popen"));
	//assert(my1.LastIndexOf("popen") == s1.rfind("popen"));

	//assert(my1.IndexOf("pope pope love") == s1.find("pope pope love"));
	//assert(my1.LastIndexOf("pope pope love") == s1.rfind("pope pope love"));

	//// E2, E3
	//assert(my1.IndexOf("") == s1.find(""));
	//assert(my1.LastIndexOf("") == s1.rfind(""));

	//// E4
	//assert(my1 == copied);                    // value
	//assert(my1.GetCString() == cString);                // reference

	return 0;
}