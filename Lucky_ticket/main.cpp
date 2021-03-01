#include <iostream>
#include "tickets.h"

using namespace std;




int main()

{
	int numeral_sistem = 10;

	int number_of_digits = 4;

	tickets testEX;

	testEX.SetNumeral_system_and_number_of_digits(numeral_sistem, number_of_digits);

	testEX.test();



	testEX.print_number_of_lucky_tickets();


}