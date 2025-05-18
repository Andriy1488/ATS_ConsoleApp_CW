// Subscriber.h
#pragma once
#include "Subscription.h"

class Subscriber
{
protected:
	int id;
	string name;
	int age;
	string email;
	Subscription subscription;
public:
	Subscriber() : id(0), name(""), age(0), email(""), subscription() {}
	Subscriber(string name, int age, string email, Subscription subscription)
		: name(name), age(age), email(email), subscription(subscription) 
	{
		id = idCounter++;
	}
	Subscriber(int id, string name, int age, string email, Subscription subscription)
		: id(id), age(age), email(email), subscription(subscription) {}

	static int idCounter;

	int getId() { return id; }
	string getName() { return name; }
	int getAge() { return age; }
	string getEmail() { return email; }
	Subscription getSubscription() { return subscription; }

	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setEmail(string email) { this->email = email; }
	void setSubscription(Subscription subscription) { this->subscription = subscription; }

	void displaySubscriber() {
		cout << "Subscriber ID: " << id << endl;
		cout << "Subscriber Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Email: " << email << endl;
	}
};

int Subscriber::idCounter = 1;