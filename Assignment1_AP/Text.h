#ifndef TEXT_H
#define TEXT_H
#include<iostream>
using namespace std;
class Text {

private:
	char* text;
	
public:
	virtual ~Text();
	Text();
	Text(const char*);
	Text(const Text&);
	void set(char*);
	void set(const Text&);
	Text& operator=(const Text&);
	void append(const char*);
	void append(const Text&);
	int length() const;
	bool isEmpty() const;
	friend ostream& operator<<(ostream&, const Text&);
	Text int_to_string(int);
};
#endif 