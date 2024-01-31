/*
 * Date.hpp
 *
 *  Created on: Mar 24, 2023
 *      Author: abdullahahmed
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include <string>
using namespace std;

class Date {
public:
	Date();
	virtual ~Date();
	bool numDaysInMonth();
	bool operator++(int day);
	bool operator--(int day);
	bool operator==(const Date& rightDate);
	bool operator<(const Date& rightDate);
	bool operator>(const Date& rightDate);
	friend ostream &operator<<(ostream &myOutput, const Date& dateObject);


	int getDay() const;
	bool setDay(int day);
	int getMonth() const;
	bool setMonth(int month);
	int getYear() const;
	bool setYear(int year);

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_HPP_ */
