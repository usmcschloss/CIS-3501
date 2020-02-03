#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>

/* help from: https://www.youtube.com/watch?v=Y2UpnCnMB-s
Programmer Name: Michael D. Schloss
Program Name: Quick Sorting Timer
Date: 11-9-19
Class: CIS-3501  /  Fall 2019
Professor: John P. Baugh
*/

using namespace std;

// This will manage the partitions portion of the Quick Sort
// Conditions: Must have properly built the vectors.
int QSpartition(vector<int>& setVec, int begin, int end)
{
	int temp, i, x, j;
	x = setVec.at(end);
	i = begin - 1;

	for (j = begin; j <= end; j++)
	{
		if (setVec.at(j) < x)
		{
			i++;
			temp = setVec.at(i);
			setVec.at(i) = setVec.at(j);
			setVec.at(j) = temp;
		}
	}
	i++;
	temp = setVec.at(i);
	setVec.at(i) = setVec.at(end);
	setVec.at(end) = temp;

	return i;
}
// Partitions managed.


// This will do the overall Quick Sorting of the given vectors
// Conditions: Must have accurately executed the partitions.
void QuickSort(vector<int> &setVec, int begin, int end)
{
	int partitionValue;
	if (begin <= end)
	{
		partitionValue = QSpartition(setVec, begin, end);
		QuickSort(setVec, begin, partitionValue - 1);
		QuickSort(setVec, partitionValue + 1, end);
	}
}
// Vectors have been sorted.


// This will display the given vectors before and after sorting
// Conditions: Must have accurately executed the Quick Sort.
void DisplaySort(vector<int> setVec)
{
	cout << "Before sort: " << endl;
	for (int i = 0; i < setVec.size(); i++)
	{
		cout << setVec.at(i) << " ";
	}

	QuickSort(setVec, 0, (setVec.size() - 1));

	cout << endl << "After sort: " << endl;
	for (int i = 0; i < setVec.size(); i++)
	{
		cout << setVec.at(i) << " ";
	}
}
// Vectors displayed.


int main()
{
	vector<int> set250, set500, set750, set1000, set2500;
	//vector<int> test = { 15, 42, 3, 107, 47, 66, 13, 88, 1 };
	srand(time(0));

	//DisplaySort(test);

	// The following 'for' loops will create the vectors.
	// Conditions: element values must be >= 0 && <= 1000
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

	using namespace chrono;

	// These record the duration of sorting and displaying the vectors
	// Also calls the Display/Soring methods.
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
	// Sorting has been timed
	// Vectors have been sorted and dispalyed


	cout << "Total run time for set250: " << time_span250.count() << " seconds." << endl;
	cout << "Total run time for set500: " << time_span500.count() << " seconds." << endl;
	cout << "Total run time for set750: " << time_span750.count() << " seconds." << endl;
	cout << "Total run time for set1000: " << time_span1000.count() << " seconds." << endl;
	cout << "Total run time for set2500: " << time_span2500.count() << " seconds." << endl;

	system("pause");
	return 0;
}