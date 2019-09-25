// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "person.h"

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;
}

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
}

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
}


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15);    

    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl;

    auto person_ptr_in_main = printName2();
    printName3(person_ptr_in_main);

    sandile_ptr = make_unique<Person>("Sandile2",11);  
    cout << sandile_ptr->age() << endl;

    return 0;
}

// Exercise 3.1 for the code above

// Assume no compiler optimizations

// (1)
// (a) thabo (in line 21) goes out of scope in line 24 at the end of printName()
// (b) maryanne_ptr (in line 28) goes out of scope in line 31 at the end of printName2()
// (c) person_ptr (in line 33) goes out of scope in line 37 at the end of printName3()
// (d) sandile_ptr (in line 42) goes out of scope in line 54 at the end of main()
// (e) thabo_in_main (in line 44) goes out of scope in line 54 at the end of main()
// (f) person_ptr_in_main (in line 47) goes out of scope in line 54 at the end of main()

// (2)
// The pointee (in line 28) is pointed to by maryanne_ptr, person_ptr_in_main
// and person_ptr over the course of the program's execution. This memory
// is released in at the end of main() (at line 54) when person_ptr_in_main,
// the last object pointing to that block of memory, falls out of scope.

// The pointee (in line 42) is pointed to by sandile_ptr until the program
// reaches line 50. This memory is released when sandile_ptr is overwritten.

// The pointee (in line 50) is pointed to by sandile_ptr until the program
// ends when sandile_ptr falls out of scope.

// (3)
// maryanne_ptr -> temporary return object of printName2() -> person_ptr_in_main -> person_ptr
// Therefore, its copied three times in total after its initialized

// sandile_ptr cannot be copied because unique pointers cannot be copied only overwritten

// (4)
// Due to the order by which they they were initialized, thabo_in_main will go out of scope first
// because it goes off of the stack first. This is then followed by sandile_ptr, which will cause
// its pointee on the heap to be deallocated.
