// LandlineSubscriber.h
#pragma once
#include "Subscriber.h"

class LandlineSubscriber : public Subscriber, public IDisplay
{
private:
	string landlineNumber;
	string address;
public:
	LandlineSubscriber(int id, string name, int age, string email, Subscription subscription, string landlineNumber, string address)
		: Subscriber(id, name, age, email, subscription), landlineNumber(landlineNumber), address(address) {
	}

	LandlineSubscriber(string name, int age, string email, Subscription subscription, string landlineNumber, string address)
		: Subscriber(name, age, email, subscription), landlineNumber(landlineNumber), address(address) {
	}

	string getLandlineNumber() { return landlineNumber; }
	string getAddress() { return address; }

	void setLandlineNumber(string landlineNumber) { this->landlineNumber = landlineNumber; }
	void setAddress(string address) { this->address = address; }

	void displayTable() override
	{
		cout << "Landline Subscriber Table" << endl;
		cout << string(100, '=') << endl;
		cout << left << setw(5) << "ID" << "| " << setw(20) << "Name" << "| " << setw(10) << "Age" << "| " << setw(20) << "Email" << "| " << setw(15) << "Landline Number" << "| " << setw(20) << "Address" << "|" << endl;
		cout << string(100, '=') << endl;
	}

	void displayInfo() override {
		cout << left << setw(5) << id << "| " << setw(20) << getName() << "| " << setw(10) << getAge() << "| " << setw(20) << getEmail() << "| " << setw(15) << landlineNumber << "| " << setw(20) << address << "|" << endl;
		cout << string(100, '-') << endl;
	}
};