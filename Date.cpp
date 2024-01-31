/*
 * Date.cpp
 *
 *  Created on: Mar 24, 2023
 *      Author: abdullahahmed
 */

#include "Date.hpp"
#include <iomanip>

Date::Date() {
	// TODO Auto-generated constructor stub
	this->day = 0;
	this->month = 0;
	this->year = 0;

}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
// Function to check for the number of days for a specific month
bool Date::numDaysInMonth()
{
	if (this->month == 2)
	{
		return 28;
		return true;
	}
	else if (this->month == 4 or this->month == 6 or this->month == 9 or this->month == 11)
	{
		return 30;
		return true;
	}
	else if(this->month == 1 or this->month == 3 or this->month == 5 or this->month == 7 or this->month == 8 or this->month == 10 or this->month == 12)
	{
		return 31;
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator++(int day)
{
	if (this->day == 0 or this->month == 0 or this->year == 0)
	{
		return false;
	}
	this->day++;

	if (this->day > numDaysInMonth())
	{
		this->month++;
		this->day = 1;
	}

	if (this->month > 12)
	{
		this->year++;
		this->month = 1;
	}
	return true;
}

bool Date::operator--(int day)
{
	if (this->day == 0 or this->month == 0 or this->year == 0)
	{
		return false;
	}
	else
	{
		this->day--;
	}
	if (this->day == 0)
	{
		this->month--;
	}

	if (this->month == 0)
	{
		this->year--;
		this->month = 12;
		this->day = numDaysInMonth();

	}
	return true;
}


bool Date::operator==(const Date& rightDate)
{
	if (this->day == rightDate.day and this->month == rightDate.month and this->year == rightDate.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream &operator<<(ostream &myOutput, const Date& dateObject)
{
	if (dateObject.day == 0 or dateObject.month == 0 or dateObject.year == 0)
	{
		myOutput << "Invalid date sent";
	}
	else
	{
		myOutput << setw(2) << setfill('0') << dateObject.month << "/" << setw(2) << setfill('0') << dateObject.day << "/" << setw(2) << setfill('0') << dateObject.year;
	}
	return myOutput;
}

bool Date::operator<(const Date& rightDate)
{
	if (this->year < rightDate.year)
	{
		return true;
	}

	else if (this->year == rightDate.year and this->month < rightDate.month)
	{
		return true;
	}

	else if (this->year == rightDate.year and this->month == rightDate.month and this->day < rightDate.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>(const Date& rightDate)
{
	if (this->year > rightDate.year)
	{
		return true;
	}
	else if (this->year == rightDate.year and this->month > rightDate.month)
	{
		return true;
	}
	else if(this->year == rightDate.year and this->month == rightDate.month and this->day > rightDate.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Date::getDay() const {
	return day;
}

bool Date::setDay(int day) {
	if (this->year == 0 or this->month == 0)
	{
		return false;
	}
	if (this->month == 0)
	{
		this->day = 0;
		return true;
	}
	else if (this->day < 1 or this->day > numDaysInMonth())
	{
		return false;
	}
	else
	{
		this->day = day;
		return true;
	}

}

int Date::getMonth() const {
	return month;
}

bool Date::setMonth(int month) {
	if (this->year == 0)
	{
		return false;
	}
	else if (this->month < 1 or this->month > 12)
	{
		return false;
	}
	else
	{
		this->month = month;
		return true;
	}

}

int Date::getYear() const {
	return year;
}

bool Date::setYear(int year) {
	if (this->year < 1 or this->year > 9999)
	{
		return false;
	}
	else
	{
		this->year = year;
		return true;
	}

}
