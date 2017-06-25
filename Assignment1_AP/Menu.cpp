#include "Menu.h"
#include<iostream>


//doubles the capacity of option list
void Menu::double_capacity()
{
	max_list_size = max_list_size * 2;
}


//Default constructor
Menu::Menu()
{
	count = 0;
	max_list_size = 1;
	option_list = new Text[max_list_size];
	option_list[0].set(" ");
	top_prompt.set(" ");
	bottom_prompt.set(" ");
	top_text.set(" ");
	bottom_text.set(" ");
}

//copy constructor
Menu::Menu(const Menu &otherMenu)
{
	count = otherMenu.count;
	max_list_size = otherMenu.max_list_size;
	option_list = otherMenu.option_list;
	top_prompt = otherMenu.top_prompt;
	bottom_prompt = otherMenu.bottom_prompt;
	top_text = otherMenu.top_text;
	bottom_text = otherMenu.bottom_text;
}

//destructor
Menu::~Menu()
{
//	cout << "Menu Destructor";
	delete[] option_list;
	option_list = 0;
}

//overloading = operator to copy two menu objects
Menu & Menu::operator=(const Menu &otherMenu)
{
	if (this == &otherMenu) {
		return *this;
	}
	else {
		delete[] option_list;
		this->set_top_prompt(otherMenu.top_prompt);
		this->set_top_message(otherMenu.top_text);
		this->set_bottom_prompt(otherMenu.bottom_prompt);
		this->set_bottom_message(otherMenu.bottom_text);
		count = otherMenu.count;
		option_list = new Text[otherMenu.count];
		for (int i = 0; i < count; i++) {
			option_list[i] = otherMenu.option_list[i];
		}


	}
	return *this;
}

//insert a option list to the existing list at given position 
//and checks if option list is full before inserting ;
//if option list is full, doubles the capacity before inserting to the list
void Menu::insert(int position, Text &newText)
{
	
	if (position > 0) {

		if (size() == max_list_size-1) {
			double_capacity();
			Text* temp = new Text[max_list_size];

			//copy everything in optionlist to temp
			for (int j = 0; j<size(); j++) {
			
				temp[j].set(option_list[j]);
			}

			//move every option to the right of postion to next location
			for (int i = position - 1; i<size(); i++) {
				
				temp[i + 1].set(option_list[i]);
			}

			//Set new option at the given position
			temp[position-1].set(newText);

			//option list points to new optionlist
			delete[] option_list;
			option_list = temp;
			//increase the capacity of option list
			count = count + 1;
		}


		else {
			Text *temp = new Text[size() + 1];
			for (int j = 0; j<size(); j++) {
			
				temp[j].set(option_list[j]);
			}

			//move every option to the right of postion to next location
			for (int i = position - 1; i<size(); i++) {
				
				temp[i + 1].set(option_list[i]);
			}

			//Set new option at the given position
			temp[position-1].set(newText);

			//option list points to new optionlist
			delete[] option_list;
			option_list = temp;
			//increase the capacity of option list
			count = count + 1;
		}
	}
	
	else {
		cout << "Invalid Position" << endl;
	}

	/*Text *temp = new Text[size() + 1];
	//Text *temp = new Text[count];
	//temp[0]="?->";
	cout << "=======insert=======" << endl;

	//copy everything in optionlist to temp
	for (int j = 0; j <= size() - 1; j++) {
		temp[j] = option_list[j];
	}

	//move every option to the right of postion to next location
	for (int i = position; i <= size() - 1; i++) {
		temp[i + 1] = option_list[i];
	}

	//Set new option at the given position
	temp[position] = newText;

	//option list points to new optionlist
	delete[] option_list;
	option_list = temp;
	//increase the capacity of option list
	count = count + 1;
	for (int i = 0; i <= size() - 1; i++) {
		cout << option_list[i] << endl;
	}*/

}

//verfies if the option list is full ,if so doubles the capacity
//pushes new option at end of the existing list 
void Menu::push_back(char *newOption)
{
	
	if (size() == max_list_size) {
		double_capacity();
		Text* temp = new Text[max_list_size];
		for (int i = 0; i < size(); i++) {
			//int_to_string(i);
			temp[i].set(option_list[i]);
		}
		delete[] option_list;
		temp[count].set(newOption);
		option_list = temp;
		count = count + 1;
	}

	else {

		option_list[count].set(newOption);
		count = count + 1;
	}

}

//verfies if the option list is full ,if so doubles the capacity
//pushes new option at end of the existing list 
void Menu::push_back(const Text &newOption)
{
	if (size() == max_list_size) {
		double_capacity();
		Text* temp = new Text[max_list_size];
		for (int i = 0; i < size(); i++) {
			temp[i].set(option_list[i]);
		}
		delete[] option_list;
		temp[count].set(newOption);
		option_list = temp;
		count = count + 1;
	}

	else {

		option_list[count].set(newOption);
		count = count + 1;
	}
}

//Removes the option from a given postion and returns the removed element
Text Menu::remove(int position)
{
	Text removed;

	if (position>=0 && position <=size()) {
	
		removed = option_list[position];
		option_list[position].set('\0');
		//count = count - 1;
		for (int i = position; i < size() - 1; i++) {
			option_list[i] = option_list[i + 1];
		}
		option_list[size() - 1].set('\0');
		count = count - 1;
	}

	else {
		cout << "The postion to remove from must be between [0-" << size()-1 << "].";
	}

	return removed;
}

//returns the size of the current option list
int Menu::size() const
{
	return count;
}


int Menu::capacity()
{
	return 0;
}

//pops out last element from the option list
void Menu::pop_back()
{
	cout << "======delete last element==========" << endl;
	//Set Last Eelement to null
	option_list[count - 1].set('\0');

	//Reduce the number of elements by 1
	count = count - 1;
	
}

//gets the element from specified postion 
Text Menu::get(int position)
{
	Text retrived;
	if (position >= 0 && position <= size()) {
		retrived= option_list[position];
	}

	else {
		//retrived='\0';
		cout << "invalid postion" << "It must be in the range [1, " << size() << "]" << endl;
	}
	return retrived;
}

//appends all  the menu content to Text object
Text Menu::toString() const
{

	Text finalText;
	finalText.append(top_prompt);
	finalText.append("\n");
	finalText.append(top_text);
	finalText.append("\n");
	for (int i = 0; i <=size()-1; i++)
	{
		finalText.append("(");
		finalText.append(finalText.int_to_string(i+1));
		finalText.append(")");
		finalText.append(option_list[i]);
		finalText.append("\n");
	}
	finalText.append(bottom_text);
	finalText.append("\n");
	finalText.append("?->");
	finalText.append(bottom_prompt);

	return finalText;
}

//display menu object by calling toString()
//accepts and validates the choice received from the users
int Menu::read_option_number()
{
	int choice;
	cout<<toString();
	cin >> choice;
	if (!isEmpty()) {
		//cout << "you entered :" << choice;
		while (!(choice >= 1 && choice <= size())) {

			cout << "Invalid choice " << choice << " .It must be in the range [1 ," << size() << "]" << endl;
			cout << "?->";
			cin >> choice;
		}

		//cout << "you entered " << choice << endl;
	}
	else {

		//cout << "You entered :" << choice << endl;
		
	}
	return choice;
}
//set top prompt
void Menu::set_top_prompt(const Text &newText)
{
	top_prompt.set(newText);
}
//set bottom prompt
void Menu::set_bottom_prompt(const Text &newText)
{
	bottom_prompt.set(newText);
}

//set top text
void Menu::set_top_message(const Text &newText)
{
	top_text.set(newText);
}

//set bottom text
void Menu::set_bottom_message(const Text &newText)
{
	bottom_text.set(newText);
}

//clears top prompt
void Menu::clear_top_prompt()
{
	top_prompt.set(" ");
}

//clears bottom prompt
void Menu::clear_bottom_prompt()
{
	bottom_prompt.set(" ");
}

//clears top text
void Menu::clear_top_message()
{
	top_text.set(" ");
}

//clears bottom text
void Menu::clear_bottom_message()
{
	bottom_text.set(" ");
}

//checks if the option list is empty
bool Menu::isEmpty() const
{
	if (count>0) {
		return false;
	}

	else {
		return true;
	}
}


//overloads operator << to output menu object by calling toString() internally
ostream& operator<<(ostream& out, Menu& menu)
{
	out << menu.toString();
	return out;
}