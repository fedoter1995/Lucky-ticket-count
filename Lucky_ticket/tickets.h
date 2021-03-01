#include <iostream>
#include <cmath>
#include <vector>
#include <thread>

using namespace std;

class tickets
{
private:

	vector<int>firstVector;

	vector<int>secondVector;

	vector<unsigned long long>vectorSum;

	int numeral_system;

	int digitsPart;

	int number_of_digits;

	int coef;

	unsigned long long number_of_lucky_tickets;

	void fillfirstVector()
	{

		for (int i = 0; i < numeral_system * 2 - 1; i++)

		{

			if (i < numeral_system)

			{
				firstVector.push_back(1);
			}
			else
			{
				firstVector.push_back(0);
			}


		}


	}

	void NumberPart()
	{
		if (number_of_digits % 2 == 0)
		{

			digitsPart = number_of_digits / 2;

			coef = 1;

		}
		else
		{

			digitsPart = (number_of_digits - 1) / 2;

			coef = numeral_system;

		}


	}


	void counting()

	{
		NumberPart();

		for (int part = 1; part < digitsPart; part++)
		{



			int range = firstVector.size();

			for (int i = 0; i < firstVector.size(); i++)

			{
				int count = 0;

				int summ = 0;


				for (int j = i; count < numeral_system && j >= 0; j--)

				{

					summ = summ + firstVector[j];

					count++;



				}

				secondVector.push_back(summ);

			}



			firstVector.clear();

			firstVector = secondVector;

			secondVector.clear();

			for (int i = 0; i < numeral_system; i++)
			{

				firstVector.push_back(0);

			}
		}
	}

	void summVector()
	{

		for (int i = 0; i < firstVector.size(); i++)
		{
			if (firstVector[i] > 0)
			{
				unsigned long long sum = pow(firstVector[i], 2);

				vectorSum.push_back(sum);

			}

		}


		number_of_lucky_tickets = 0;

		for (int i = 0; i < vectorSum.size(); i++)
		{

			number_of_lucky_tickets = number_of_lucky_tickets + vectorSum[i];

		}

		number_of_lucky_tickets = number_of_lucky_tickets * coef;
	}


public:

	void SetNumeral_system_and_number_of_digits(int numeral_system, int number_of_digits)
	{

		this->numeral_system = numeral_system;

		this->number_of_digits = number_of_digits;


	}

	void print_number_of_lucky_tickets()
	{

		cout << "Number of lucky tickets = " << number_of_lucky_tickets << endl;

	}



	void test()
	{
		fillfirstVector();


		counting();

		summVector();

	}


	void printVector()
	{
		cout << "firstVector = \t{";

		int count = 0;

		for (auto vecit = firstVector.begin(); vecit != firstVector.end(); vecit++)
		{
			count++;

			if (count % 11 == 0)
			{
				cout << "}" << endl << "\t\t{";
			}

			cout << *vecit << "\t";


		}

		cout << "}" << endl;

	}

	void printSumVector()
	{
		cout << "vectorSum = \t{";

		int count = 0;

		for (auto vecit = vectorSum.begin(); vecit != vectorSum.end(); vecit++)
		{
			count++;

			if (count % 11 == 0)
			{
				cout << "}" << endl << "\t\t{";
			}

			cout << *vecit << "\t";


		}

		cout << "}" << endl;

	}

};