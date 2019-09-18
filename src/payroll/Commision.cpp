#include <Commision.h>

CommisionWorker::CommisionWorker(const string &first_name, const string &surname, double base_salary, double commission, int itemsPerWeek)
:Employee(first_name,surname),
 base_salary_(base_salary),
 commission_(commission),
 items_per_week_(itemsPerWeek)
{}

void CommisionWorker::salary(double base_salary)
{
	base_salary_ = base_salary;
}
void CommisionWorker::commision(double commission)
{
	commission_ = commission;
}

void CommisionWorker::itemsPerWeek(double items_per_week)
{
	items_per_week_ = items_per_week;
}

double CommisionWorker::earnings() const
{
	return base_salary_ + (commission_*items_per_week_);
}

void CommisionWorker::print() const
{
	cout << "CommisionWorker: ";
	Employee::print();
}
