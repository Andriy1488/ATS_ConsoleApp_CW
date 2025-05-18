// ATS.h
#pragma once
#include "MobileSubscriber.h"
#include "LandlineSubscriber.h"
#include <algorithm>

enum SortingCriteria
{
	NAME = 0,
	AGE = 1,
	SUBSCRIPTION_TYPE = 2,
	EMAIL = 3
};

class ATS : public IDisplay
{
private:
	int id = 0;
	string name;
	string location;
	string type;
	int capacity;
	vector <LandlineSubscriber> landlineSubscribers;
	vector <MobileSubscriber> mobileSubscribers;

public:
	static int idCounter;
	ATS(string name, string location, string type, vector <LandlineSubscriber> landlineSubscribers, vector <MobileSubscriber> mobileSubscribers) : 
		name(name), location(location), type(type), landlineSubscribers(landlineSubscribers), mobileSubscribers(mobileSubscribers)
	{
		id = idCounter++;
		capacity = landlineSubscribers.size() + mobileSubscribers.size();
	}
	
	int getId() { return id; }
	string getName() { return name; }
	string getLocation() { return location; }
	string getType() { return type; }
	int getCapacity() { return capacity; }
	vector <LandlineSubscriber> getLandlineSubscribers() { return landlineSubscribers; }
	vector <MobileSubscriber> getMobileSubscribers() { return mobileSubscribers; }

	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setLocation(string location) { this->location = location; }
	void setType(string type) { this->type = type; }
	void setCapacity(int capacity) { this->capacity = capacity; }
	void setLandlineSubscribers(vector <LandlineSubscriber> landlineSubscribers) { this->landlineSubscribers = landlineSubscribers; }
	void setMobileSubscribers(vector <MobileSubscriber> mobileSubscribers) { this->mobileSubscribers = mobileSubscribers; }

	void displayTable()
	{
		cout << "Telephone Exchange Table" << endl;
		cout << string(78, '=') << endl;
		cout << left << setw(5) << "ID" << "| " << setw(20) << "Name" << "| " << setw(20) << "Location" << "| " << setw(15) << "Type" << "| " << setw(10) << "Capacity" << "|" << endl;
		cout << string(78, '=') << endl;
	}
	void displayInfo()
	{
		cout << left << setw(5) << id << "| " << setw(20) << name << "| " << setw(20) << location << "| " << setw(15) << type << "| " << setw(10) << capacity << "|" << endl;
		cout << string(78, '-') << endl;
	}
	void addLandlineSubscriber(LandlineSubscriber subscriber)
	{
		landlineSubscribers.push_back(subscriber);
		capacity++;
	}
	void addMobileSubscriber(MobileSubscriber subscriber)
	{
		mobileSubscribers.push_back(subscriber);
		capacity++;
	}
	void displaySubscribers()
	{
		landlineSubscribers[0].displayTable();
		for (auto& subscriber : landlineSubscribers)
		{
			subscriber.displayInfo();
		}
		mobileSubscribers[0].displayTable();
		for (auto& subscriber : mobileSubscribers)
		{
			subscriber.displayInfo();
		}
	}
	void searchSubscriber(string name)
	{
		bool found = false;
		bool showTable = true;
		for (auto& subscriber : landlineSubscribers)
		{
			if (subscriber.getName() == name)
			{
				if (showTable)
				{
					displayTable();
					displayInfo();
					showTable = false;
				}
				subscriber.displayTable();
				subscriber.displayInfo();
				found = true;
			}
		}
		for (auto& subscriber : mobileSubscribers)
		{
			if (subscriber.getName() == name)
			{
				if (showTable)
				{
					displayTable();
					displayInfo();
					showTable = false;
				}
				mobileSubscribers[0].displayTable();
				subscriber.displayInfo();
				found = true;
			}
		}
		if (!found && id == idCounter-1)
		{
			cout << "Subscriber not found." << endl;
			return;
		}
	}
	void sortSubscribers(SortingCriteria sc)
	{
		switch (sc)
		{
		case NAME:
			sort(landlineSubscribers.begin(), landlineSubscribers.end(), [](LandlineSubscriber a, LandlineSubscriber b) { return a.getName() < b.getName(); });
			sort(mobileSubscribers.begin(), mobileSubscribers.end(), [](MobileSubscriber a, MobileSubscriber b) { return a.getName() < b.getName(); });
			break;
		case AGE:
			sort(landlineSubscribers.begin(), landlineSubscribers.end(), [](LandlineSubscriber a, LandlineSubscriber b) { return a.getAge() < b.getAge(); });
			sort(mobileSubscribers.begin(), mobileSubscribers.end(), [](MobileSubscriber a, MobileSubscriber b) { return a.getAge() < b.getAge(); });
			break;
		case SUBSCRIPTION_TYPE:
			sort(landlineSubscribers.begin(), landlineSubscribers.end(), [](LandlineSubscriber a, LandlineSubscriber b) { return a.getSubscription().getType() < b.getSubscription().getType(); });
			sort(mobileSubscribers.begin(), mobileSubscribers.end(), [](MobileSubscriber a, MobileSubscriber b) { return a.getSubscription().getType() < b.getSubscription().getType(); });
			break;
		case EMAIL:
			sort(landlineSubscribers.begin(), landlineSubscribers.end(), [](LandlineSubscriber a, LandlineSubscriber b) { return a.getEmail() < b.getEmail(); });
			sort(mobileSubscribers.begin(), mobileSubscribers.end(), [](MobileSubscriber a, MobileSubscriber b) { return a.getEmail() < b.getEmail(); });
			break;
		default:
			sort(landlineSubscribers.begin(), landlineSubscribers.end(), [](LandlineSubscriber a, LandlineSubscriber b) { return a.getId() < b.getId(); });
			sort(mobileSubscribers.begin(), mobileSubscribers.end(), [](MobileSubscriber a, MobileSubscriber b) { return a.getId() < b.getId(); });
			break;
		}
	}
};

int ATS::idCounter = 1;