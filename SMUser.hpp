/*
 * SMUser.hpp
 *
 *  Created on: May 15, 2023
 *      Author: abdullah ahmed
 */

#ifndef SMUSER_HPP_
#define SMUSER_HPP_
#include <string>
#include <iostream>
#include "Date.hpp"
using namespace std;

class SMUser {
public:
	SMUser();
	virtual ~SMUser();
	const Date& getDateOfMemberShip() const;
	bool setDateOfMemberShip(const Date &dateOfMemberShip);
	const string& getFirstName() const;
	bool setFirstName(const string &firstName);
	const string& getLastName() const;
	bool setLastName(const string &lastName);
	const string& getUserId() const;
	bool setUserId(const string &userId);

private:
	string userID;
	string firstName;
	string lastName;
	Date dateOfMemberShip;



};

#endif /* SMUSER_HPP_ */
