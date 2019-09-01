// Member function definitions for abstract base class Employee.
// Note: No definitions given for pure virtual functions.
#include "Employee.h"

Employee::Employee(const string& first_name, const string& surname):
	first_name_(first_name),
	surname_(surname)
{   
}

// Destructor - nothing to do
Employee::~Employee()
{
}

// Return a copy of the first name
string Employee::first_name() const 
{ 
   return first_name_; 
}

// Return a copy of the surname
string Employee::surname() const 
{ 
   return surname_; 
}

// Print the name of the Employee
void Employee::print() const
{ 
	cout << first_name_ << ' ' << surname_; 
}


