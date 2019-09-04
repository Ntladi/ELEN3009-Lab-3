#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;

enum class Month 
{
	January = 1, 
	February,
	March, 
	April,
	May,
	June,
	July, 
	August, 
	September,
	October,
	November, 
	December
};

class InvalidDate{};

class Date
{
public:
	// parameterized Constructor
	Date(int day, Month month, int year);
	// new default constructor
	Date();
	// return the day of the month
	int	day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;	
	// overload operator in order to compare dates
	bool operator==(const Date& rhs) const;
	// increment the date by one day
	void increment();
	// change the default date if needed
	static void setDefaultDate(int day, Month month, int year){
		default_ = Date{day, month, year};
	}


private:
	// return the number of days in the month_
	int	daysInMonth () const;	
	
	int	day_;
	Month month_;
	int	year_;

	// the default date is stored here
	static Date default_;

};

// standalone function for printing the date
void printDate(const Date& date);

#endif
