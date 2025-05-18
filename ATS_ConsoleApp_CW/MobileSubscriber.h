// MobileSubscriber.h
#pragma once
#include "Subscriber.h"

class MobileSubscriber : public Subscriber, public IDisplay
{
private:
	string address;
	string mobileNumber;
public:
	MobileSubscriber(string name, int age, string email, Subscription subscription, string mobileNumber, string address)
		: Subscriber(name, age, email, subscription), mobileNumber(mobileNumber), address(address) {
	}

	MobileSubscriber(int id, string name, int age, string email, Subscription subscription, string mobileNumber, string address)
		: Subscriber(id, name, age, email, subscription), mobileNumber(mobileNumber), address(address) {
	}

	string getMobileNumber() { return mobileNumber; }
	string getAddress() { return address; }

	void setMobileNumber(string mobileNumber) { this->mobileNumber = mobileNumber; }
	void setAddress(string address) { this->address = address; }

	void displayTable() override
	{
		cout << "Mobile Subscriber Table" << endl;
		cout << string(100, '=') << endl;
		cout << left << setw(5) << "ID" << "| " << setw(20) << "Name" << "| " << setw(10) << "Age" << "| " << setw(20) << "Email" << "| " << setw(15) << "Mobile Number" << "| " << setw(20) << "Address" << "|" << endl;
		cout << string(100, '=') << endl;
	}

	void displayInfo() override {
		cout << left << setw(5) << id << "| " << setw(20) << getName() << "| " << setw(10) << getAge() << "| " << setw(20) << getEmail() << "| " << setw(15) << mobileNumber << "| " << setw(20) << address << "|" << endl;
		cout << string(100, '-') << endl;
	}
};