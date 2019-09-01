// FixedRateWorker class derived from Employee
#ifndef FIXED_H
#define FIXED_H
#include "Employee.h"

class FixedRateWorker : public Employee {
public:
   FixedRateWorker(const string& first_name, const string& surname, 
				   double weekly_salary = 0.0);
   void salary(double weekly_salary);	// set weekly salary

   virtual double earnings() const override;
   void print() const;

private:
   double weekly_salary_; 
};

#endif
