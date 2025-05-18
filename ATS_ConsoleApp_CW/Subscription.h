// Subscribtion.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "IDisplay.h"

using namespace std;

class Subscription : public IDisplay
{
private:
	int id;
	string name;
	string type;
	string startDate;
	string endDate;
	double price;
public:
	Subscription() : id(0), name(""), type(""), startDate(""), endDate(""), price(0.0) {}
	Subscription(string name, string type, string startDate, string endDate, double price)
		: name(name), type(type), startDate(startDate), endDate(endDate), price(price) 
	{
		id = idCount++;
	}

	static int idCount;

	int getId() { return id; }
	string getName() { return name; }
	string getType() { return type; }
	string getStartDate() { return startDate; }
	string getEndDate() { return endDate; }
	double getPrice() { return price; }

	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setStartDate(string startDate) { this->startDate = startDate; }
	void setEndDate(string endDate) { this->endDate = endDate; }
	void setPrice(double price) { this->price = price; }

	void displayTable() override
	{
		cout << "Subscription Table" << endl;
		cout << string(85, '=') << endl;
		cout << left << setw(5) << "ID" << "| " << setw(20) << "Name" << "| " << setw(15) << "Type" << "| " << setw(15) << "Start Date" << "| " << setw(15) << "End Date" << "| " << setw(5) << "Price" << "|" << endl;
		cout << string(85, '=') << endl;
	}

	void displayInfo() override {
		cout << left << setw(5) << id << "| " << setw(20) << name << "| " << setw(15) << type << "| " << setw(15) << startDate << "| " << setw(15) << endDate << "| " << setw(5) << price << "|" << endl;
		cout << string(85, '-') << endl;
	}
};
