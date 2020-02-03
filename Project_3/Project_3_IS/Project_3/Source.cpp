#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

/*
Programmer Name: Michael D. Schloss
Program Name: Insertion Sort Timer
Date: 11-9-19
Professor: John P. Baugh
*/

// This will take the elements in the already provded vectors
// and sort them in numerical order from lowest to highest.
// No conditions required.
void InsertionSort(vector<int> &setVec)
{
	int key;
	int placeOrder = 0;

	for (int i = 0; i < setVec.size(); i++)
	{
		key = setVec.at(i);
		placeOrder = i - 1;
		while (placeOrder >= 0 && setVec.at(placeOrder) > key)
		{
			setVec.at(placeOrder + 1) = setVec.at(placeOrder);
			placeOrder = placeOrder - 1;
		}
		setVec.at(placeOrder + 1) = key;
	}
}
// The Vectors have been sorted


// This will display the vectors before and after sorting.
// No conditions required
void DisplaySort(vector<int> setVec)
{
	cout << "Before sort: " << endl;
	for (int i = 0; i < setVec.size(); i++)
	{
		cout << setVec.at(i) << " ";
	}

	InsertionSort(setVec);

	cout << endl << "After sort: " << endl;
	for (int i = 0; i < setVec.size(); i++)
	{
		cout << setVec.at(i) << " ";
	}
}
// Vectors have been displayed.

int main()
{
	vector<int> set250, set500, set750, set1000, set2500;
	vector<int> test = { 15, 42, 3, 107, 47, 66, 13, 88, 1 };
	srand(time(0));

	// These create the vectors
	// Conditions: Must be >= 0 && <= 1000
	for (int i = 0; i < 250; i++)
	{
		set250.push_back(1 + (rand() % 1000));
	}
	for (int i = 0; i < 500; i++)
	{
		set500.push_back(1 + (rand() % 1000));
	}
	for (int i = 0; i < 750; i++)
	{
		set750.push_back(1 + (rand() % 1000));
	}
	for (int i = 0; i < 1000; i++)
	{
		set1000.push_back(1 + (rand() % 1000));
	}
	for (int i = 0; i < 2500; i++)
	{
		set2500.push_back(1 + (rand() % 1000));
	}
	// Vectors have been created

	using namespace chrono;

	// These time the duration to display and sort the vectors.
	// Also call the Display/Sorting methods
	// No conditions required.
	steady_clock::time_point t250_1 = steady_clock::now();
	DisplaySort(set250);
	steady_clock::time_point t250_2 = steady_clock::now();
	duration<double> time_span250 = duration_cast<duration<double>>(t250_2 - t250_1);
	cout << endl << endl << endl << endl;

	steady_clock::time_point t500_1 = steady_clock::now();
	DisplaySort(set500);
	steady_clock::time_point t500_2 = steady_clock::now();
	duration<double> time_span500 = duration_cast<duration<double>>(t500_2 - t500_1);
	cout << endl << endl << endl << endl;

	steady_clock::time_point t750_1 = steady_clock::now();
	DisplaySort(set750);
	steady_clock::time_point t750_2 = steady_clock::now();
	duration<double> time_span750 = duration_cast<duration<double>>(t750_2 - t750_1);
	cout << endl << endl << endl << endl;

	steady_clock::time_point t1000_1 = steady_clock::now();
	DisplaySort(set1000);
	steady_clock::time_point t1000_2 = steady_clock::now();
	duration<double> time_span1000 = duration_cast<duration<double>>(t1000_2 - t1000_1);
	cout << endl << endl << endl << endl;

	steady_clock::time_point t2500_1 = steady_clock::now();
	DisplaySort(set2500);
	steady_clock::time_point t2500_2 = steady_clock::now();
	duration<double> time_span2500 = duration_cast<duration<double>>(t2500_2 - t2500_1);
	cout << endl << endl << endl << endl;
	// Vectors have been timed and displayed.
	

	cout << "Total run time for set250: " << time_span250.count() << " seconds." << endl;
	cout << "Total run time for set500: " << time_span500.count() << " seconds." << endl;
	cout << "Total run time for set750: " << time_span750.count() << " seconds." << endl;
	cout << "Total run time for set1000: " << time_span1000.count() << " seconds." << endl;
	cout << "Total run time for set2500: " << time_span2500.count() << " seconds." << endl;

	system("pause");
	return 0;
}