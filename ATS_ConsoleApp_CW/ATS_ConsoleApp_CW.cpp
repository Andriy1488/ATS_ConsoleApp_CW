// MAIN FILE
#include "CityPhoneNetwork.h"
#include <fstream>
#include <sstream>

void importSubscriptions(vector <Subscription> &subscriptions)
{
    ifstream file("subscriptions.txt");
    string line;
	if (!file.is_open())
	{
		cout << "Error opening file." << endl;
		return;
	}
	while (getline(file, line))
    {
        stringstream ss(line);
        string name, type, startDate, endDate;
        double price;
        getline(ss, name, ',');
        getline(ss, type, ',');
        getline(ss, startDate, ',');
        getline(ss, endDate, ',');
        ss >> price;
        Subscription subscription(name, type, startDate, endDate, price);
        subscriptions.push_back(subscription);
    }
}

void importLandlineSubscribers(vector <vector<LandlineSubscriber>>& landlineSubscribers, vector<Subscription>& subscriptions)
{
    ifstream file("landlineSubscribers.txt");
    string line;
    int lineCounter = 0;
	int counter = 0;
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, email, address, landlineNumber;
        int age, subscriptionId;
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, email, ',');
        ss >> subscriptionId;
        ss.ignore();
        getline(ss, landlineNumber, ',');
        getline(ss, address, ',');
        LandlineSubscriber subscriber(name, age, email, subscriptions[subscriptionId], landlineNumber, address);
        if (lineCounter % 5 == 0 && lineCounter!=0) counter++;
        landlineSubscribers[counter].push_back(subscriber);
        lineCounter++;
    }
}

void importMobileSubscribers(vector <vector<MobileSubscriber>>& mobileSubscribers, vector<Subscription>& subscriptions)
{
    ifstream file("mobileSubscribers.txt");
    string line;
    int lineCounter = 0;
    int counter = 0;
    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, email, address, mobileNumber;
        int age, subscriptionId;
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, email, ',');
        ss >> subscriptionId;
        ss.ignore();
        getline(ss, mobileNumber, ',');
        getline(ss, address, ',');
        MobileSubscriber subscriber(name, age, email, subscriptions[subscriptionId], mobileNumber, address);
        if (lineCounter % 5 == 0 && lineCounter != 0) counter++;
        mobileSubscribers[counter].push_back(subscriber);
        lineCounter++;
    }
}

int main()
{
    vector <Subscription> subscriptions;
    importSubscriptions(subscriptions);

	vector <vector<LandlineSubscriber>> landlineSubscribers(3);
	importLandlineSubscribers(landlineSubscribers, subscriptions);

	vector <vector<MobileSubscriber>> mobileSubscribers(3);
	importMobileSubscribers(mobileSubscribers, subscriptions);

	vector <ATS> atsList
	{
		ATS("Central ATS", "Kyiv", "Central", landlineSubscribers[0], mobileSubscribers[0]),
		ATS("Western ATS", "Lviv", "Western", landlineSubscribers[1], mobileSubscribers[1]),
		ATS("Eastern ATS", "Kharkiv", "Eastern", landlineSubscribers[2], mobileSubscribers[2])
	};

    CityPhoneNetwork::addSubscription(subscriptions[0]);
    CityPhoneNetwork::addSubscription(subscriptions[1]);
    CityPhoneNetwork::addSubscription(subscriptions[2]);
    CityPhoneNetwork::addSubscription(subscriptions[3]);
    CityPhoneNetwork::addSubscription(subscriptions[4]);
    CityPhoneNetwork::addSubscription(subscriptions[5]);

	CityPhoneNetwork::addATS(atsList[0]);
	CityPhoneNetwork::addATS(atsList[1]);
	CityPhoneNetwork::addATS(atsList[2]);

	for(;;) CityPhoneNetwork::displayMenu();
}
