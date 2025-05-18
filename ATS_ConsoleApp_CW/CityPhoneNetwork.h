// CityPhoneNetwork.h
#pragma once
#include "ATS.h"
#include "Windows.h"

class CityPhoneNetwork
{
private:
	static vector <ATS> atsList;
	static vector <Subscription> subscriptionList;
	static string mode;

public:
	static void addSubscription(Subscription sub) {
		subscriptionList.push_back(sub);
	}

	static void removeSubscription(int id) {
		if (id > 0 && id <= subscriptionList.size()) {
			subscriptionList.erase(subscriptionList.begin() + id - 1);
		}
		else {
			cout << "Invalid subscription ID." << endl;
		}
	}

	static void updateSubscription(int id, Subscription sub) {
		if (id > 0 && id <= subscriptionList.size()) {
			sub.setId(id);
			subscriptionList[id - 1] = sub;
		}
		else {
			cout << "Invalid subscription ID." << endl;
		}
	}

	static void addATS(ATS ats) {
		atsList.push_back(ats);
	}

	static int findSubscriber(int id)
	{
		int result = -2;
		for (auto& ats : atsList) {
			for (auto& subscriber : ats.getLandlineSubscribers()) {
				if (subscriber.getId() == id) {
					result = ats.getId();
					break;
				}
			}
			for (auto& subscriber : ats.getMobileSubscribers()) {
				if (subscriber.getId() == id) {
					result = ats.getId();
					if (result > -2) result = -1;
					break;
				}
			}
		}
		if (result == -2) {
			cout << "Subscriber not found." << endl;
		}
		else if (result == -1) {
			cout << "Subscriber found in multiple ATS." << endl;
		}
		return result;
	}

	static void addSubscriber()
	{
		string name, email, address;
		int age, subscriptionId, atsID;
		Subscription sub;

		cout << "Enter subscriber name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter subscriber age: ";
		cin >> age;
		cout << "Enter subscriber email: ";
		cin.ignore();
		getline(cin, email);
		cout << "Enter address: ";
		getline(cin, address);
		cout << "Enter subscription type id: ";
		cin >> subscriptionId;

		if (subscriptionId > 0 && subscriptionId <= subscriptionList.size()) {
			sub = subscriptionList[subscriptionId - 1];
		}
		else {
			cout << "Invalid subscription ID." << endl;
		}

		cout << "Choose subscriber type:" << endl;
		cout << "1. Landline" << endl;
		cout << "2. Mobile" << endl;
		int subscriberType;
		cin >> subscriberType;

		if (subscriberType == 1)
		{
			string landlineNumber;
			cout << "Enter landline number: ";
			cin >> landlineNumber;

			cout << "Enter ATS ID to add subscriber: ";
			cin >> atsID;

			if (atsID > 0 && atsID <= atsList.size())
			{
				atsList[atsID - 1].addLandlineSubscriber(LandlineSubscriber(name, age, email, sub, landlineNumber, address));
			}
			else
			{
				cout << "Invalid ATS ID." << endl;
			}
		}
		else if (subscriberType == 2)
		{
			string mobileNumber;
			cout << "Enter mobile number: ";
			cin >> mobileNumber;
			cout << "Enter ATS ID to add subscriber: ";
			cin >> atsID;

			if (atsID > 0 && atsID <= atsList.size())
			{
				atsList[atsID - 1].addMobileSubscriber(MobileSubscriber(name, age, email, sub, mobileNumber, address));
			}
			else
			{
				cout << "Invalid ATS ID." << endl;
			}
		}
		else
		{
			cout << "Invalid subscriber type." << endl;
		}

		cout << "Subscriber added successfully." << endl;
	}

	static void displayMenu()
	{
		cout << string(50, '+') << endl;
		cout << "City Phone Network Management System" << endl;
		cout << "1. Display All Subscriptions" << endl;
		cout << "2. Display All ATS" << endl;
		cout << "3. Display All Subscribers" << endl;
		cout << "4. Display Complete Info About an ATS" << endl;
		cout << "5. Search Subscriber" << endl;
		cout << "6. Sort Subscribers" << endl;
		cout << "7. Add Subscriber" << endl;
		cout << "8. Add Subscription" << endl;
		cout << "9. Update Subscription" << endl;
		cout << "10. Remove Subscription" << endl;
		cout << "11. Display contacts" << endl;
		cout << "12. Toggle " << mode << " mode" << endl;
		cout << "404. Exit" << endl;
		cout << string(50, '+') << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1:
			subscriptionList[0].displayTable();
			for (auto& sub : subscriptionList) {
				sub.displayInfo();
			}
			break;
		case 2:
			atsList[0].displayTable();
			for (auto& ats : atsList) {
				ats.displayInfo();
			}
			break;
		case 3:
			for (auto& ats : atsList) {
				cout << ats.getId() << " - " << ats.getName() << endl;
				cout << string(78, '+') << endl;
				ats.displaySubscribers();
				system("pause");
				system("cls");
			}
			break;
		case 4:
		{
			int atsChoice;
			cout << "Enter ATS ID to display complete info: ";
			cin >> atsChoice;
			system("cls");

			if (atsChoice > 0 && atsChoice <= atsList.size()) {
				atsList[atsChoice - 1].displayTable();
				atsList[atsChoice - 1].displayInfo();
				atsList[atsChoice - 1].displaySubscribers();
			}
			else {
				cout << "Invalid ATS ID." << endl;
			}
			break;
		}
		case 5:
		{
			string searchName;
			cout << "Enter subscriber name to search: ";
			cin.ignore();
			getline(cin, searchName);
			for (auto& ats : atsList) {
				ats.searchSubscriber(searchName);
			}
			break;
		}
		case 6:
		{
			cout << "Choose sorting type below:" << endl;
			cout << "1. Sort by Name" << endl;
			cout << "2. Sort by Age" << endl;
			cout << "3. Sort by Subscription Type" << endl;
			cout << "4. Sort by Email" << endl;
			cout << "Enter your choice: ";
			int sortChoice;
			cin >> sortChoice;

			for (auto& ats : atsList) {
				ats.sortSubscribers(static_cast<SortingCriteria>(sortChoice - 1));
			}
			break;
		}
		case 7:
		{
			addSubscriber();
			break;
		}
		case 8:
		{
			string name, type, startDate, endDate;
			double price;
			cout << "Enter subscription name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter subscription type: ";
			getline(cin, type);
			cout << "Enter subscription start date: ";
			getline(cin, startDate);
			cout << "Enter subscription end date: ";
			getline(cin, endDate);
			cout << "Enter subscription price: ";
			cin >> price;
			addSubscription(Subscription(name, type, startDate, endDate, price));
			break;
		}
		case 9:
		{
			int id;
			cout << "Enter subscription ID to update: ";
			cin >> id;
			if (id > 0 && id <= subscriptionList.size()) {
				string name, type, startDate, endDate;
				double price;
				cout << "Enter new subscription name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter new subscription type: ";
				getline(cin, type);
				cout << "Enter new subscription start date: ";
				getline(cin, startDate);
				cout << "Enter new subscription end date: ";
				getline(cin, endDate);
				cout << "Enter new subscription price: ";
				cin >> price;
				updateSubscription(id, Subscription(name, type, startDate, endDate, price));
				cout << "Subscription updated successfully." << endl;
			}
			else {
				cout << "Invalid subscription ID." << endl;
			}
			break;
		}
		case 10:
		{
			int id;
			cout << "Enter subscription ID to remove: ";
			cin >> id;
			removeSubscription(id);
			cout << "Subscription removed successfully." << endl;
			break;
		}
		case 11:
			displayContacts();
			break;
		case 12:
			toggleMode();
			break;
		case 404:
			exit(0);
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;

		}
		system("pause");
		system("cls");
	}

	static void toggleMode()
	{
		if (mode == "dark")
		{
			mode = "light";
			system("color F0");
			cout << "Switched to light mode." << endl;
		}
		else
		{
			mode = "dark";
			system("color 0F");
			cout << "Switched to dark mode." << endl;
		}
	}

	static void displayContacts()
	{
		cout << string(50, '+') << endl;
		cout << "City Phone Network Contacts:" << endl;
		cout << "1. Customer Service: 0800-123-456" << endl;
		cout << "2. Technical Support: 0800-654-321" << endl;
		cout << "3. Billing Inquiries: 0800-789-012" << endl;
		cout << "4. General Inquiries: 0800-345-678" << endl;
		cout << "5. Emergency Services: 112" << endl;
		cout << "6. Complaints: 0800-987-654" << endl;
		cout << string(50, '+') << endl;
	}
};

vector<ATS> CityPhoneNetwork::atsList;
vector<Subscription> CityPhoneNetwork::subscriptionList;
string CityPhoneNetwork::mode = "dark";