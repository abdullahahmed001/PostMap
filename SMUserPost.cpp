/*
 * SMUserPost.cpp
 *
 *  Created on: May 16, 2023
 *      Author: abdullah ahmed
 */

#include "SMUserPost.hpp"

SMUserPost::SMUserPost() {
	// TODO Auto-generated constructor stub
	this->textOfPost = "";
	this->userID = "";
	this->aTime.hours = 0;
	this->aTime.minutes = 0;
	this->aTime.seconds = 0;
}

SMUserPost::~SMUserPost() {
	// TODO Auto-generated destructor stub
}

const Date& SMUserPost::getDateOfPost() const {
	return dateOfPost;
}

bool SMUserPost::setDateOfPost(const Date &dateOfPost) {
	if (dateOfPost.getDay() == 0 || dateOfPost.getMonth() == 0 || dateOfPost.getYear() == 0)
	{
		throw "Dates must be valid";
		return false;
	}
	else
	{
		this->dateOfPost = dateOfPost;
		return true;
	}

}

const string& SMUserPost::getTextOfPost() const {
	return textOfPost;
}

bool SMUserPost::setTextOfPost(const string &textOfPost) {
	if (textOfPost == "")
	{
		throw "Strings cannot be blank";
		return false;
	}
	else
	{
		this->textOfPost = textOfPost;
		return true;
	}
}

const string& SMUserPost::getUserId() const {
	return userID;
}

bool SMUserPost::setUserId(const string &userId) {
	if (userId == "")
	{
		throw "Numbers cannot be zero";
		return false;
	}
	else
	{
		this->userID = userId;
		return true;
	}
}

int SMUserPost::getHours() const {
	return aTime.hours;
}

bool SMUserPost::setHours(int hours) {
	if (hours < 0 || hours > 23)
	{
		throw "Hours weren't set correctly";
		return false;
	}
	else
	{
		this->aTime.hours = hours;
		return true;
	}

}

int SMUserPost::getMinutes() const {
	return aTime.minutes;
}

bool SMUserPost::setMinutes(int minutes) {
	if (minutes < 0 || minutes > 59)
	{
		throw "Minutes weren't set correctly";
		return false;
	}
	else
	{
		this->aTime.minutes = minutes;
		return true;
	}
}

int SMUserPost::getSeconds() const {
	return aTime.seconds;
}

bool SMUserPost::setSeconds(int seconds) {
	if (seconds < 0 || seconds > 59)
	{
		throw "Seconds weren't set correctly";
		return false;
	}
	else
	{
		this->aTime.seconds = seconds;
		return true;
	}
}
