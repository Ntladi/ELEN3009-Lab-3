// Member function definitions for class HourlyWorker

#include "Hourly.h"

// Constructor
HourlyWorker::HourlyWorker (const string& first_name, const string& surname,
							double wage, double weekly_hours)
							: Employee(first_name, surname),  // call base-class constructor
							  wage_(wage),
							  weekly_hours_(weekly_hours)
{}

void HourlyWorker::wage(double wage)
{
	wage_ = wage;
}

void HourlyWorker::hours(double weekly_hours)
{
	weekly_hours_ = weekly_hours;
}

// Get the HourlyWorker's pay
double HourlyWorker::earnings() const
{
   if ( weekly_hours_ <= 40 ) // no overtime
      return wage_ * weekly_hours_;
   else               // overtime is paid at wage * 1.5
      return 40 * wage_ + (weekly_hours_ - 40) * wage_ * 1.5;
}

// Print the HourlyWorker's name
void HourlyWorker::print() const
{
   cout << "Hourly worker: ";
   // re-use Employee's print function (DRY principle)
   Employee::print();
}
