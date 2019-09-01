// Member function definitions for class FixedRateWorker

#include "Fixed.h"

// Constructor
FixedRateWorker::FixedRateWorker(const string& first_name, const string& surname, double weekly_salary)
   : Employee(first_name, surname),  // call base-class constructor
	 weekly_salary_(weekly_salary)	 
{}   
	 

   
void FixedRateWorker::salary(double weekly_salary)	// set weekly salary
{
	weekly_salary_ = weekly_salary;
}

// Get the FixedRateWorker's pay
double FixedRateWorker::earnings() const { return weekly_salary_; }

// Print the FixedRateWorker's name 
void FixedRateWorker::print() const
{
   cout << "FixedRateWorker: ";
   // re-use Employee's print function (DRY principle)
   Employee::print();
}
