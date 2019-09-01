// Abstract base class Employee
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;
#include <iostream>
using std::cout;

class Employee {
public:
   Employee(const string& first_name, const string& surname);
   virtual ~Employee();						// virtual
   string first_name() const;				// non-virtual
   string surname() const;					// non-virtual
   
   virtual double earnings() const = 0;		// pure virtual
   void print() const;						// non-virtual

private:
   string first_name_;
   string surname_;
};

#endif
