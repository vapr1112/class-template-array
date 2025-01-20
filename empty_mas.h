#pragma once
#include <exception>
#include <iostream>

using namespace std;

class empty_mas : public exception
{
private: 
	string message;
public:
	empty_mas() = default;
	empty_mas(string message_p) : message{ message_p } {}

	virtual const char* what()const noexcept final override { return message.c_str(); }

	virtual ~empty_mas() = default;
};

