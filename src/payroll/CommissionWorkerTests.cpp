#include "Commision.h"
#include <memory>
using std::make_shared;
using std::shared_ptr;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Worker that is initialized with no salary has null parameters")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy");

	CHECK(worker->earnings() == 0);
}

TEST_CASE("Worker's base salary is correctly initialized")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",900.00);
	CHECK(worker->earnings() == 900.00);
}

TEST_CASE("Worker's base salary can be changed")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",900.00);
	CHECK(worker->earnings() == 900.00); // Check initial earnings
	worker->salary(250.00); // Change salary
	CHECK(worker->earnings() == 250.00); // Change new earnings
}

TEST_CASE("Worker's commission is correctly initialized")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",0,150.00,1);
	CHECK(worker->earnings() == 150.00);
}

TEST_CASE("Worker's commission can be changed")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",0,150.00,1);
	CHECK(worker->earnings() == 150.00); // Check initial earnings
	worker->commision(230.00); // Change commission
	CHECK(worker->earnings() == 230.00); // Change new earnings
}

TEST_CASE("Worker's items per week is correctly initialized")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",0,1,3);
	CHECK(worker->earnings() == 3);
}

TEST_CASE("Worker's commission can be changed")
{
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",0,1,3);
	CHECK(worker->earnings() == 3); // Check initial earnings
	worker->itemsPerWeek(9); // Change items per week
	CHECK(worker->earnings() == 9); // Change new earnings
}

TEST_CASE("Worker's earnings are correct when everything is initialized at once")
{
	double base_salary = 7496.88;
	double commission = 773.53;
	int items_per_week = 12;
	auto worker = make_shared<CommisionWorker>("Ted", "Ramgasamy",base_salary,commission,items_per_week);

	CHECK(worker->earnings() == (base_salary + (commission*items_per_week)));
}
