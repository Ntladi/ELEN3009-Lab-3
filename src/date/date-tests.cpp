#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// COMMENT OUT THIS TEST AFTER INSPECTING THE OUTPUT 
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
//TEST_CASE("Date has uninitialised state") {
//    // make a prior memory allocations - which will be the case in a typical program
//	auto str = "hello"s;
//
//    Date today;	// rather use: auto today = Date{}; not used here to illustrate the issue
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	auto heritage_day = Date{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);

}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.
TEST_CASE("A zero date is invalid")
{
	CHECK_THROWS_AS(Date(0, Month::January, 2000), InvalidDate);
}

TEST_CASE("A negative date is invalid")
{
	CHECK_THROWS_AS(Date(-4, Month::February, 2000), InvalidDate);
}

TEST_CASE("The 29th or higher of February on a non leap year is invalid")
{
	CHECK_THROWS_AS(Date(29, Month::February, 2001), InvalidDate);
	CHECK_NOTHROW(Date(29, Month::February, 2000));
}

TEST_CASE("The 30th or higher of February is invalid")
{
	CHECK_THROWS_AS(Date(30, Month::February, 2000), InvalidDate);
}

TEST_CASE("The 31st or higher of some months is invalid")
{
	CHECK_THROWS_AS(Date(31, Month::April, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(31, Month::June, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(31, Month::September, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(31, Month::November, 2000), InvalidDate);
}

TEST_CASE("The 32nd or higher of all months is invalid")
{
	CHECK_THROWS_AS(Date(32, Month::January, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(32, Month::March, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(32, Month::May, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(32, Month::July, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(32, Month::August, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(32, Month::October, 2000), InvalidDate);
	CHECK_THROWS_AS(Date(32, Month::December, 2000), InvalidDate);
}


// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    auto date_1 = Date{1, Month::January, 2000};
    auto date_2 = Date{1, Month::January, 2000};

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.

TEST_CASE("Dates where days are equal while the months and years are not, aren't equal")
{
	auto date_1 = Date{2, Month::January, 2000};
	auto date_2 = Date{2, Month::February, 2001};
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Dates where days are not equal while the months and years are, aren't equal")
{
	auto date_1 = Date{3, Month::March, 2002};
	auto date_2 = Date{4, Month::March, 2002};
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Dates where months are equal while the days and years are not, aren't equal")
{
	auto date_1 = Date{5, Month::April, 2003};
	auto date_2 = Date{6, Month::April, 2004};
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Dates where months are not equal while the days and years are, aren't equal")
{
	auto date_1 = Date{7, Month::May, 2005};
	auto date_2 = Date{7, Month::June, 2005};
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Dates where years are equal while the days and months are not, aren't equal")
{
	auto date_1 = Date{8, Month::July, 2006};
	auto date_2 = Date{9, Month::August, 2006};
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Dates where years are not equal while the days and months are, aren't equal")
{
	auto date_1 = Date{10, Month::September, 2007};
	auto date_2 = Date{10, Month::September, 2008};
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Dates where everything is different are not equal")
{
	auto date_1 = Date{11, Month::October, 2009};
	auto date_2 = Date{12, Month::November, 2010};
	CHECK_FALSE(date_1 == date_2);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("On a regular day, only the day increments")
{
	auto date_1 = Date{12, Month::July, 2011};
	date_1.increment();
	CHECK(date_1.day() == 13);
	CHECK(date_1.month() == Month::July);
	CHECK(date_1.year() == 2011);
}

TEST_CASE("If it's the end of February and not a leap year, the day resets and the month increments")
{
	auto date_1 = Date{28, Month::February, 2013};
	date_1.increment();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::March);
	CHECK(date_1.year() == 2013);
}

TEST_CASE("If it's the end of February and a leap year, the day resets and the month increments")
{
	auto date_1 = Date{29, Month::February, 2000};
	date_1.increment();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::March);
	CHECK(date_1.year() == 2000);
}

TEST_CASE("If it's the end of a month with 31 days, the day resets and the month increments")
{
	auto date_1 = Date{31, Month::March, 2014};
	date_1.increment();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::April);
	CHECK(date_1.year() == 2014);
}

TEST_CASE("If it's the end of a month with 30 days, the day resets and the month increments")
{
	auto date_1 = Date{30, Month::June, 2015};
	date_1.increment();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::July);
	CHECK(date_1.year() == 2015);
}

TEST_CASE("If it's the end of the year, the year and month resets and the year increments")
{
	auto date_1 = Date{31, Month::December, 2016};
	date_1.increment();
	CHECK(date_1.day() == 1);
	CHECK(date_1.month() == Month::January);
	CHECK(date_1.year() == 2017);
}

// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.

TEST_CASE("The default constructor sets the date to the correct default value")
{
	auto date_1 = Date();

	CHECK(date_1.day() == 13);
	CHECK(date_1.month() == Month::November);
	CHECK(date_1.year() == 1998);
}

TEST_CASE("The default date can be changed")
{
	Date::setDefaultDate(9, Month::March, 1969);

	auto date_1 = Date();

	CHECK(date_1.day() == 9);
	CHECK(date_1.month() == Month::March);
	CHECK(date_1.year() == 1969);
}

TEST_CASE("Changing the default date does not change the parameters of objects already instantiated with the parameterized constructor")
{
	Date::setDefaultDate(7, Month::September, 2001);
	auto date_1 = Date(24, Month::March, 1965);


	CHECK(date_1.day() == 24);
	CHECK(date_1.month() == Month::March);
	CHECK(date_1.year() == 1965);
}

TEST_CASE("Changing the default date does not change the parameters of objects already instantiated with the default constructor")
{
	Date::setDefaultDate(13, Month::November, 1998);
	auto date_1 = Date();
	Date::setDefaultDate(21, Month::February, 1999);

	CHECK(date_1.day() == 13);
	CHECK(date_1.month() == Month::November);
	CHECK(date_1.year() == 1998);

}
