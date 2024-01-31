//============================================================================
// Name        : CS2Chapter17Project.cpp
// Author      : Abdullah Ahmed
// Version     :
// Copyright   : Don't steal my code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "SMUserPost.hpp"
#include "Date.hpp"
#include "SMUser.hpp"
using namespace std;
int main() {

	// declare all the variables needed
	int userChoice = 0;
	string iDOfUser = "";
	string fileName = "";
	string inputRecord;
	ifstream firstInputFile("SMUsers.csv");
	ifstream secondInputFile("SMUserPosts.csv");
	ofstream firstOutputFile("UserErrors.txt");
	ofstream secondOutputFile("PostErrors.txt");
	Date myDate;


	// Requirement # 3
	map<string, SMUser*> SMUsersMap;
	pair<string, SMUser*> SMUserPair; // created a pair structure
	map<string, SMUser*>::iterator smUserMapIT; // iterator has a key and a value
	multimap<string, SMUserPost*> smUsersPostsMultiMap; // a multi map of SMUserPost pointers
	multimap<string, SMUserPost*>::iterator postIT;
	pair<string, SMUser*> SMUserPostsPair;

	/*
	 * Perform file validation to check whether the file exists or not. If the file doesn't exist,
	 * display an error message and end the program. Otherwise read both csv files
	 */

	// Over here, we are reading SMUsers.csv into a map of SMUser pointers
	if (!firstInputFile.good())   // good function will check if the stream is good enough to work
	{
		cout << "File doesn't exist" << endl;
		return (-999);
	}
	else
	{
		cout << "Going to read the file now" << endl;
		string temp = "";
		while (!firstInputFile.eof()) {
			SMUser* anSMUser = nullptr;
			anSMUser = new SMUser();

			getline(firstInputFile, inputRecord);
			if (inputRecord.length() == 0)
			{
				continue;
			}
			stringstream strStream(inputRecord);
			getline(strStream, temp, ',');
			try
			{
				anSMUser->setUserId(temp);
				cout << "This is the User ID: " << temp << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " << e << endl;
			}
			getline(strStream, temp, ',');
			try
			{
				anSMUser->setFirstName(temp);
				cout << "This is the first name: " << temp << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " <<  e << endl;
			}
			getline(strStream, temp, ',');
			try
			{
				anSMUser->setLastName(temp);
				cout << "This is the last name: " <<  temp << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " << e << endl;
			}
			getline(strStream, temp, ',');
			try
			{
				myDate.setYear(stoi(temp));
				cout << "This is the year set: " << myDate.getYear() << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " << e << endl;
			}
			getline(strStream, temp, ',');
			try
			{
				myDate.setMonth(stoi(temp));
				cout << "This is the month set: " << myDate.getMonth() << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " << e << endl;
			}
			getline(strStream, temp, ',');
			try
			{
				myDate.setDay(stoi(temp));
				cout << "This is the day set: " << myDate.getDay() << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " << e << endl;
			}
		//	getline(strStream, temp, ',');
			try
			{
				anSMUser->setDateOfMemberShip(myDate);
				cout << "This is the date of membership: " << myDate.getDate() << endl;
			}
			catch(const char* e)
			{
				firstOutputFile << "Error: " << e << endl;
			}

			if (SMUsersMap.insert(make_pair(anSMUser->getUserId(), anSMUser)).second == false)
			{
				firstOutputFile << inputRecord << endl;
				firstOutputFile << "User ID wasn't inserted correctly" << endl;
				continue; // since the user already exists, skip it. Don't add it to the map
				delete anSMUser;
			}
			else
			{
				cout << "User id inserted correctly" << endl;
			}

	}
	firstInputFile.close();
	//firstOutputFile.close();

	// Now going to read SMUserPosts.csv files into a multi map of SMUserPost pointers
	//multimap<string, SMUserPost*> smUsersPostsMultiMap; // a multi map of SMUserPost pointers
	//multimap<string, SMUserPost*>::iterator smUsersPostsMultiMapIT;
	//pair<string, SMUser*> SMUserPostsPair;

		if (!secondInputFile.good())
		{
			cout << "File doesn't exist" << endl;
			return (-999);
		}
		else {
			while(!secondInputFile.eof())
			{
				SMUserPost* anSMUserPost = nullptr;
				anSMUserPost = new SMUserPost();

				getline(secondInputFile, inputRecord);
				if (inputRecord.length() == 0)
				{
					continue;
				}
				stringstream strStream(inputRecord);
				getline(strStream, temp, ',');
				try
				{
					anSMUserPost->setUserId(temp);
					cout << "This is the User ID: " << temp << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, user ID wasn't set: " << e << endl;
				}
				getline(strStream, temp, ',');
				try
				{
					myDate.setYear(stoi(temp));
					cout << "This is the year set: " << temp << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, year wasn't set correctly: " << e << endl;
				}
				getline(strStream, temp, ',');
				try
				{
					myDate.setMonth(stoi(temp));
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, month wasn't set correctly: " << e << endl;
				}
				getline(strStream, temp, ',');
				try
				{
					myDate.setDay(stoi(temp));
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, day wasn't set correctly: " << e << endl;
				}
				//getline(strStream, temp, ',');
				try
				{
					anSMUserPost->setDateOfPost(myDate);
					cout << "This is the date of the post: " << myDate.getDate() << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, date wasn't set correctly: " <<  e << endl;
				}
				getline(strStream, temp, ',');
				try
				{
					anSMUserPost->setSeconds(stoi(temp));
					cout << "This is the number of seconds: " << temp << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, number of seconds weren't set: " << e << endl;
					continue;
				}
				getline(strStream, temp, ',');
				try
				{
					anSMUserPost->setMinutes(stoi(temp));
					cout << "This is the number of minutes: " << temp << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, minutes weren't set: " << e << endl;
					continue;
				}
				getline(strStream, temp, ',');
				try
				{
					anSMUserPost->setHours(stoi(temp));
					cout << "This is the number of hours: " << temp << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, hours weren't set: " << e << endl;
					continue;
				}
				getline(strStream, temp, ',');
				try
				{
					anSMUserPost->setTextOfPost(temp);
					cout << "This is the post: " << temp << endl;
				}
				catch(const char* e)
				{
					secondOutputFile << "Error, text of post wasn't set: " << e << endl;
					continue;
				}
				if (SMUsersMap.count(anSMUserPost->getUserId()) == 1)
				{
					smUsersPostsMultiMap.insert(make_pair(anSMUserPost->getUserId(), anSMUserPost));
					cout << "User id inserted correctly in multi map" << endl;
				}
				else
				{
					secondOutputFile << anSMUserPost->getUserId() << endl;
					secondOutputFile << inputRecord << endl;
					secondOutputFile << "User id wasn't inserted correctly" << endl;
					delete anSMUserPost;
				}
				/*
				if (smUsersPostsMultiMap.insert(make_pair(anSMUserPost->getUserId(), anSMUserPost))->second == false)
				{
					secondOutputFile << inputRecord << endl;
					secondOutputFile << "User ID wasn't inserted correctly" << endl;
					delete anSMUserPost;
					continue;
				}
				else
				{
					cout << "User id inserted correctly" << endl;
				}
				*/
			}
			secondInputFile.close();
			//secondOutputFile.close();
		}
}


while(userChoice != 5) {
	cout << "        Main Menu  " << endl;
	cout << "=============================================" << endl;
	cout << "\t1. Display all Users" << endl;
	cout << "\t2. Display a Specific User" << endl;
	cout << "\t3. Display all Posts" << endl;
	cout << "\t4. Display Posts from a Specific User" << endl;
	cout << "\t5. Exit the program" << endl;
	cout << "==============================================" << endl;

	cout << "Select a menu option: " << endl;
	cin >> userChoice;

	switch(userChoice)
	{
		case 1:
		{
			cout << "Report for SM Users" << endl;
			cout << "-------------------" << endl;
			cout << setw(20) << left << "User ID";
			cout << setw(20) << left << "First Name";
			cout << setw(20) << left << "Last Name";
			cout << setw(30) << left << "Date of Membership";
			cout << "Number Of Posts" << endl;

			cout << setw(20) << left << "-------";
			cout << setw(20) << left << "---------";
			cout << setw(20) << left << "----------";
			cout << setw(30) << left << "-----------------";
			cout << "----------------" << endl;


			for (auto x: SMUsersMap) {

				int countOfPost = 0;
				//string countSMUserID = x.second->getUserId();
				for(auto y: smUsersPostsMultiMap)
				{
					if (x.second->getUserId() == y.second->getUserId())
					{
						countOfPost++;
					}
				}
				cout << setw(20) << left << x.second->getUserId();
				cout << setw(20) << left << x.second->getFirstName();
				cout << setw(20) << left << x.second->getLastName();
				cout << setw(30) << left << x.second->getDateOfMemberShip();
				cout << setw(20) << right << countOfPost << endl;

	}
			break;
		}
		case 2:
		{
			cout << "Enter an SM User ID: " << endl;
			cin >> iDOfUser;

			if (SMUsersMap.count(iDOfUser) == 0)
			{
				cout << "User doesn't exist: " << iDOfUser << endl;
			}
			else
			{
				int countOfPost = 0;
				string countSMUserID = iDOfUser;

				for(auto y: smUsersPostsMultiMap)
				{
					if (iDOfUser == y.second->getUserId())
					{
						countOfPost++;
					}
				}
				cout << "The user does exist" << endl;
				cout << setw(20) << left << "User ID";
				cout << setw(20) << left << "First Name";
				cout << setw(20) << left << "Last Name";
				cout << setw(30) << left << "Date of Membership";
				cout << "Number Of Posts" << endl;

				cout << setw(20) << left << "-------";
				cout << setw(20) << left << "---------";
				cout << setw(20) << left << "----------";
				cout << setw(30) << left << "-----------------";
				cout << "----------------" << endl;


				cout << setw(20) << left << SMUsersMap[iDOfUser]->getUserId();
				cout << setw(20) << left << SMUsersMap[iDOfUser]->getFirstName();
				cout << setw(20) << left << SMUsersMap[iDOfUser]->getLastName();
				cout << setw(30) << left << SMUsersMap[iDOfUser]->getDateOfMemberShip();
				cout << setw(20) << right << countOfPost << endl;
			}

			break;
		}
		case 3:
		{
			cout << "Second Report for SM Users" << endl;
			cout << "--------------------------" << endl;

			cout << setw(20) << left << "User ID";
			cout << setw(20) << left << "Date of Post";
			cout << setw(20) << left << "Hours";
			cout << setw(20) << left << "Minutes";
			cout << setw(20) << left << "Seconds";
			cout << setw(30) << left << "The text of the post" << endl;

			cout << setw(20) << left << "-------";
			cout << setw(20) << left << "------------";
			cout << setw(20) << left << "-------";
			cout << setw(20) << left << "------";
			cout << setw(20) << left << "-------";
			cout << "--------------------" << endl;


			for(auto x: smUsersPostsMultiMap)
			{
				cout << setw(12) << left << x.second->getUserId();
				cout << setw(8) << left << x.second->getDateOfPost();
				cout << setw(20) << left << x.second->getHours();
				cout << setw(20) << left << x.second->getMinutes();
				cout << setw(20) << left << x.second->getSeconds();
				cout << setw(20) << left << x.second->getTextOfPost() << endl;
			}


			break;
		}
		case 4:
		{
			cout << "Please enter an SMUser ID: " << endl;
			cin >> iDOfUser;

			if (SMUsersMap.count(iDOfUser) == 0)
			{
				cout << "User doesn't exist: " << iDOfUser << endl;
			}
			else
			{
				int countOfPost = 0;
				string countSMUserID = iDOfUser;

				for(auto y: smUsersPostsMultiMap)
				{
					if (iDOfUser == y.second->getUserId())
					{
						countOfPost++;
					}
				}
				cout << "The user does exist" << endl;
				cout << setw(20) << left << SMUsersMap[iDOfUser]->getUserId();
				cout << setw(20) << left << SMUsersMap[iDOfUser]->getFirstName();
				cout << setw(20) << left << SMUsersMap[iDOfUser]->getLastName();
				cout << setw(20) << right << countOfPost << endl;


				if (countOfPost == 0)
				{
					cout << "No posts found" << endl;
				}
				else
				{
					cout << "Posts of User" << endl;
					cout << "--------------" << endl;

					multimap<string, SMUserPost*>::iterator postIT;


					auto aRange = smUsersPostsMultiMap.equal_range(iDOfUser);

					for(postIT = aRange.first; postIT != aRange.second; postIT++)
					{
						cout << (*postIT).second->getTextOfPost() << endl;
					}
				}
			}

			break;
		}
		case 5:
		{


			for(auto a = SMUsersMap.begin(); a != SMUsersMap.end(); a++)
			{
				delete a->second;
			}
			SMUsersMap.clear();


			for(auto a = smUsersPostsMultiMap.begin(); a != smUsersPostsMultiMap.end(); a++)
			{
				delete a->second;
			}
			smUsersPostsMultiMap.clear();



			/*
			 * My new code
			 *
			 */

			fstream data_file;

			string data;
			data_file.open("UserErrors.txt", ios::in);
				if (data_file.is_open()) {
				string data;
				while (getline(data_file, data)) {
				          cout << "e";
				          cout << data << '\n';
				 }
				        data_file.close();
				  }

				string data1;
				data_file.open("PostErrors.txt", ios::in);
				if (data_file.is_open()) {
					string data1;
					while (getline(data_file, data1)) {
								   cout << "e";
								    cout << data1 << '\n';
					}
								   data_file.close();
					  }


			if (firstOutputFile.fail())
			{
				cout << "Error opening file" << endl;
			}
			else
			{
				/*
				while(!firstOutputFile.eof())
				{
					cout << inputRecord << endl;
				}
				*/

				firstOutputFile.close();

			}

			ofstream secondOutputFile("PostErrors.txt");

			if (secondOutputFile.fail())
			{
				cout << "Error opening file" << endl;
			}
			else
			{
				/*
				while(!secondOutputFile.eof())
				{
					cout << inputRecord << endl;
				}
				*/
				secondOutputFile.close();

			}

			cout << "Program ending, have a nice day!" << endl; // prints Program ending, have a nice day!
			break;
		}
		default:
		{
			cout << "Invalid menu option" << endl;
			break;
		}

	}
}
	return 0;
}

