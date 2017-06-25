#include "Text.h"
#include<iostream>
using namespace std;

//Default constructor
Text::Text()
{
	text = new char[1];
	*text = 0;
}

//virtual Destrutor
Text::~Text()
{
	delete[] text;
	text = 0;
	//cout << "Text class destructor"<<endl;
}

//conversion construtor
Text::Text(const char *newText)
{
	if (newText == '\0') {
		text = new char[1];
		text[0] = '\0';
		text = nullptr;
	}
	else {
		text = new char[strlen(newText) + 1];
		strcpy(text, newText);
	}
	
}

//copy constructor
Text::Text(const Text &newText)
{
	if (newText.text == '\0') {
		text = new char[1];
		text[0] = '\0';
		text = nullptr;
	}
	else {
		text = new char[strlen(newText.text) + 1];
		strcpy(text, newText.text);

	}
	
}

//set this object text to new text
void Text::set(char *newText)
{
	if (newText == '\0') {
		text = new char[1];
		text[0] = '\0';
		text = nullptr;
	}
	else {
		text = new char[strlen(newText) + 1];
		strcpy(text, newText);
	}
	
}

//set this object text to new text overload
void Text::set(const Text &newText)
{
	if (newText.text == '\0') {
		text = new char[1];
		text[0] = '\0';
		text = nullptr;
	}
	else {
		text = new char[strlen(newText.text) + 1];
		strcpy(text, newText.text);

	}
	
}

//overloading = operator for copying text objects
Text & Text::operator=(const Text &newText)
{
	text = newText.text;
	return *this;
}

//append passed text to this text object 
void Text::append(const char *newText)
{
	if (newText == '\0') {
		text = new char[1];
		text[0] = '\0';
		text = nullptr;
	}
	else {
		char *temp = new char[strlen(newText) + strlen(text) + 2];
		strcpy(temp, text);
		delete[] text;
		strcat(temp, " ");
		strcat(temp, newText);
		text = new char[strlen(newText) + strlen(text) + 2];
		strcpy(text, temp);
	}
	

}
//append the passed text to this object's text
void Text::append(const Text &newText)
{
	if (newText.text == '\0') {
		text = new char[1];
		text[0] = '\0';
		text = nullptr;
	}
	else {
		char *temp = new char[strlen(newText.text) + strlen(text) + 2];
		strcpy(temp, text);
		delete[] text;
		strcat(temp, " ");
		strcat(temp, newText.text);
		text = new char[strlen(newText.text) + strlen(text) + 2];
		strcpy(text, temp);
	}
	
}

//Source : Professor Sadeg Gaderpanah 
//To convert integer to string
Text Text::int_to_string(int x)
{
	// since our Text class offers append functions (as opposed tosome prefix function)
	// we first reverse the input integer
	int xReversed = 0;
	do {
		int d = x % 10; // extract rightmost digit
		x /= 10;        //throw away the rightmost digit of x
		xReversed = xReversed * 10 + d; // form xReversed
	} while (x != 0);
	//cout << "xReversed: " << xReversed << endl;

	// now, we disect xReversed into its digits,
	// converting them each to corresponding char,
	// and appending each char to our Text object text.
	x = xReversed;
	Text text;
	char str[2]{}; // a cstring of length 1
	do {
		int d = x % 10;
		x /= 10;
		str[0] = '0' + d; // digit to char
		text.append(str); // append to our Text object
	} while (x != 0);
	//cout << "text: " << text << endl;
	return text;
	//return Text();
}
//Computes length of this text
int Text::length() const
{
	
	return strlen(text);
}

//Check if text is empty
bool Text::isEmpty() const
{
	if (text == 0) 
		return true;
	
	else
		return false;
}

//overload insertion operator to display Text object
ostream& operator<<(ostream& out, const Text &newText) {

	out << newText.text;
	return out;
}