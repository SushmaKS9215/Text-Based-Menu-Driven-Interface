#ifndef MENU_H
#define MENU_H
#include "Text.h";
#include<iostream>
using namespace std;

class Menu {

private: Text* option_list;
		 int count;
		 int max_list_size;
		 Text top_prompt;
		 Text bottom_prompt;
		 Text top_text;
		 Text bottom_text;
		 void double_capacity();
		
public: 
	Menu();
	Menu(const Menu&);
	virtual ~Menu();
	Menu& operator=(const Menu&);
	void insert(int, Text&);
	void push_back(char*);
	void push_back(const Text&);
	Text remove(int);
	int size() const;
	int capacity();
	void pop_back();
	Text get(int);
	Text toString() const;
	int read_option_number();
	void set_top_prompt(const Text&);
	void set_bottom_prompt(const Text&);
	void set_top_message(const Text&);
	void set_bottom_message(const Text&);
	void clear_top_prompt();
	void clear_bottom_prompt();
	void clear_top_message();
	friend ostream& operator<<(ostream&, Menu&);
	void clear_bottom_message();
	bool isEmpty() const;
};
#endif