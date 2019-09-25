// Definition of class CommisionWorker
#ifndef PAYROLL_COMMISION_H_
#define PAYROLL_COMMISION_H_
#include "Employee.h"

class CommisionWorker: public Employee
{
public:
	CommisionWorker(const string &first_name, const string &surname, double base_salary = 0.0, double commission = 0.0, int itemsPerWeek = 0);
	void salary( double );
	void commision( double );
	void itemsPerWeek( double );

	virtual double earnings() const override;
	virtual void print() const override;

private:
	double base_salary_;
	double commission_;
	int items_per_week_;
};

#endif
