/*
 * SMUser.cpp
 *
 *  Created on: May 15, 2023
 *      Author: abdullah ahmed
 */

#include "SMUser.hpp"
#include "Date.hpp"

SMUser::SMUser() {
	// TODO Auto-generated constructor stub
	this->firstName = "";
	this->lastName = "";
	this->userID = "";
}

SMUser::~SMUser() {
	// TODO Auto-generated destructor stub
}

const Date& SMUser::getDateOfMemberShip() const {
	return dateOfMemberShip;
}



bool SMUser::setDateOfMemberShip(const Date &dateOfMemberShip) {
	if (dateOfMemberShip.getDay() == 0 || dateOfMemberShip.getMonth() == 0 || dateOfMemberShip.getMonth() == 0)
	{
		throw "Dates must be valid";
		return false;
	}
	else
	{
		this->dateOfMemberShip = dateOfMemberShip;
		return true;
	}
}

const string& SMUser::getFirstName() const {
	return firstName;
}

bool SMUser::setFirstName(const string &firstName) {
	if (firstName == "")
	{
		throw "Strings cannot be blank";
		return false;
	}
	else
	{
		this->firstName = firstName;
		return true;

	}
}

const string& SMUser::getLastName() const {
	return lastName;
}

bool SMUser::setLastName(const string &lastName) {
	if (lastName == "")
	{
		throw "Strings cannot be blank";
		return false;
	}
	else
	{
		this->lastName = lastName;
		return true;
	}
}


const string& SMUser::getUserId() const {
	return userID;
}

bool SMUser::setUserId(const string &userId) {
	if (userId == "")
	{
		throw "Numbers cannot be blank";
		return false;
	}
	else
	{
		this->userID = userId;
		return true;
	}
}
