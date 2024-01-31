/*
 * SMUserPost.hpp
 *
 *  Created on: May 16, 2023
 *      Author: abdullah ahmed
 */

#ifndef SMUSERPOST_HPP_
#define SMUSERPOST_HPP_
#include <iostream>
#include <string>
#include "Date.hpp"
using namespace std;

class SMUserPost {
public:

struct PostTime
{
	int hours;
	int minutes;
	int seconds;
};

SMUserPost();
virtual ~SMUserPost();
const Date& getDateOfPost() const;
bool setDateOfPost(const Date &dateOfPost);
const string& getTextOfPost() const;
bool setTextOfPost(const string &textOfPost);
const string& getUserId() const;
bool setUserId(const string &userId);


int getHours() const;
bool setHours(int hours);
int getMinutes() const;
bool setMinutes(int minutes);
int getSeconds() const;
bool setSeconds(int seconds);


private:
	string userID;
	string textOfPost;
	Date dateOfPost;
	PostTime aTime;

};

#endif /* SMUSERPOST_HPP_ */
