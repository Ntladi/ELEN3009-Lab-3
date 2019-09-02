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


// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
