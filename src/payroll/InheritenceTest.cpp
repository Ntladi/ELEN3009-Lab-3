#include "Fixed.h"
#include "Hourly.h"
#include "Commision.h"
#include "Employee.h"
#include <memory>
#include <vector>
using std::make_shared;
using std::shared_ptr;
using std::vector;

using employee_ptr = shared_ptr<Employee>;
using vec_of_employee_ptrs = vector<shared_ptr<Employee>>;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

double totalWages(const vec_of_employee_ptrs & employees)
{
	double total = 0;

	for(auto &i:employees)
		total += i->earnings();

	return total;
}

TEST_CASE("Test for total wages")
{

	employee_ptr employee1_ptr = make_shared<FixedRateWorker>("Nicolette", "Shea", 1095.50);
	employee_ptr employee2_ptr = make_shared<HourlyWorker>("Naomi", "Banks", 755.00,8.5);
	employee_ptr employee3_ptr = make_shared<CommisionWorker>("Asa", "Akira", 867.00,125.45,7);

	double total = employee1_ptr->earnings() + employee2_ptr->earnings() + employee3_ptr->earnings();

	vec_of_employee_ptrs employees = {employee1_ptr,employee2_ptr,employee3_ptr};

	CHECK(totalWages(employees) == total);
}
