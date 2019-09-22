#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#define infile "words.txt"

using namespace std;

/*
Programmer Name: Michael Schloss
Program Name: Anagram Sorter
Date Completed: Semptember 20, 2019  (day of millenial raid)

Assumptions (for file input):
	1) no spaces, caps, or special charaters
	2) 1st number must be EXACTLY how many words are in the file
*/

void buildVector(ifstream &myFile, vector<string> &temp, vector<string> &sorting, int numOfStrings, char word[])
{
	for (int i = 0; i < numOfStrings; i++)
	{
		myFile >> word;
		temp.push_back(word);
		sorting.push_back(word);
	}
}

void sortingVectors(int numOfStrings, vector<string> &sorting)
{
	for (int sortOne = 0; sortOne < numOfStrings; sortOne++)
	{
		for (int sortTwo = 0; sortTwo < numOfStrings; sortTwo++)
		{
			sort(sorting.at(sortOne).begin(), sorting.at(sortOne).end());
			sort(sorting.at(sortTwo).begin(), sorting.at(sortTwo).end());
		}
	}
}

void anagramSeparation(int numOfStrings, vector<string> &temp, vector<string> &sorting, vector<string> &compared)
{
	for (int i = 0; i < numOfStrings; i++)
	{
		int counter = 0;

		if (temp.empty())
		{
			continue;
		}
		for (int countLoop = 0; countLoop < numOfStrings; countLoop++)
		{
			if (sorting.at(i) == sorting.at(countLoop))
			{
				counter++;
			}
		}

		if (counter > 1)
		{
			for (int n = numOfStrings; n > 0; n--)
			{
				if (sorting.at(i).size() == sorting.at(n - 1).size())
				{
					sort(sorting.at(i).begin(), sorting.at(i).end());
					sort(sorting.at(n - 1).begin(), sorting.at(n - 1).end());

					if (sorting.at(i) == sorting.at(n - 1))
					{
						if (sorting.at(i) == "")
						{
							continue;
						}
						else
						{
							compared.push_back(temp.at(n - 1));
							temp.at(n - 1) = "";
							sorting.at(n - 1) = "";
						}
					}
				}
			}
		}
	}
}

void emptyingVectors(vector<string> &temp, vector<string> &sorting, vector<string> &remainders)
{
	while (!temp.empty())
	{
		sorting.erase(sorting.begin() + 0);
		if (temp.front() == "")
		{
			temp.erase(temp.begin() + 0);
		}
		else
		{
			remainders.push_back(temp.at(0));
			temp.erase(temp.begin() + 0);
		}
	}
}

void finalList(vector<string> &sorting, vector<string> &compared, vector<vector<string>> &final)
{
	int i = 0;
	int comparedCounter = 0;
	while (!sorting.empty())
	{
		while (sorting.size() > 1)
		{
			while (sorting.at(0) == sorting.at(1))
			{
				final.at(i).push_back(compared.at(comparedCounter));
				sorting.erase(sorting.begin());
				comparedCounter++;
				if (sorting.size() == 1)
				{
					break;
				}
			}
			final.at(i).push_back(compared.at(comparedCounter));
			sorting.erase(sorting.begin());
			comparedCounter++;
			i++;
		}
		if (sorting.size() == 1)
		{
			break;
		}
		if (sorting.size() > 1)
		{
			final.at(i).push_back(compared.at(comparedCounter));
			sorting.erase(sorting.begin());
		}
	}

	for (int i = 0; i < final.size(); i++)
	{
		sort(final.at(i).begin(), final.at(i).end());
	}
}

void printAnagrams(vector<vector<string>> &final, vector<string> &remainders, int numDisplayed)
{
	if (final.size() >= numDisplayed)
	{
		for (int i = 0; i < numDisplayed; i++)
		{
			cout << "Class of size " << final[i].size() << ": ";

			for (int j = 0; j < final[i].size(); j++)
			{
				cout << final.at(i).at(j) << " ";
			}
			cout << endl;
		}
	}
	else if (final.size() < numDisplayed)
	{
		
		for (int i = 0; i < final.size(); i++)
		{
			cout << "Class of size " << final[i].size() << ": ";

			for (int j = 0; j < final[i].size(); j++)
			{
				cout << final.at(i).at(j) << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < remainders.size(); i++)
		{
			cout << "Class of size 1: " << remainders.at(i) << endl;
		}
		
	}
	else
	{
		cout << "Something went wrong, try again." << endl;
	}
}



bool wayToSort(vector<string> i, vector<string> j) { return i.size() > j.size(); }




int main()
{
	ifstream myFile;
	myFile.open(infile);


	int numOfStrings;
	int numOfDisplayed;
	char word[20];
	vector<string> sortingVec;
	vector<string> tempVec;
	vector<string> alreadyCompared;
	vector<string> remainingSingles;
	

	if (!infile)
	{
		cout << "Something went wrong with opening this program." << endl;
	}

	myFile >> numOfStrings;
	myFile >> numOfDisplayed;
	
	vector<vector<string>> finalVec(numOfStrings);

	// This will put words from words.txt in both the sorting vector and a temporary vector
	buildVector(myFile, tempVec, sortingVec, numOfStrings, word);
	// Both vectors created


	// This will sort every word in the sorting vector alphabetically
	sortingVectors(numOfStrings, sortingVec);
	// Sorting vector is now sorted

	
	// This will take words which occur more than once and putting them into a 3rd vector, which will ONLY hold anagrams (no singles)
	anagramSeparation(numOfStrings, tempVec, sortingVec, alreadyCompared);
	// Anagram vector has been made


	// This will wipe the temp and sorting vectors clean, placing all remaining words in a vector for single words
	emptyingVectors(tempVec, sortingVec, remainingSingles);
	// A home has been made for the singles, and vectors have been zeroed out


	// This will alphabetize the singles vector
	sort(remainingSingles.begin(), remainingSingles.end());
	// Vector sorted
	

	int size = alreadyCompared.size();
	// This will put only anagrammed words in the sortingVec and alphabetize the words individually
	for (int i = 0; i < size; i++)
	{
		sortingVec.push_back(alreadyCompared.at(i));

		sort(sortingVec.at(i).begin(), sortingVec.at(i).end());
	}
	// Anagrams are now shuffled
	


	// This will place all anagrams of eachother on their own lines
	finalList(sortingVec, alreadyCompared, finalVec);
	// Anagrams are now organized
	
	
	// This will erase all empty "rooms" from the vector
	for (int i = 0; i <= finalVec.size(); i++)
	{
		if (i >= finalVec.size())
		{
			continue;
		}
		if (finalVec[i].size() == 0)
		{
			finalVec.erase(finalVec.begin() + i);
			i--;
		}
	}
	// No vacancy
	
	
	// This will sort the # of anagrams in descending order
	sort(finalVec.begin(), finalVec.end());
	sort(finalVec.begin(), finalVec.end(), wayToSort);
	// List has been sorted

	

	// This will display the result
	printAnagrams(finalVec, remainingSingles, numOfDisplayed);
	// Ta-da

	myFile.close();
	system("pause");
	return 0;
}