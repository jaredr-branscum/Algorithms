#include<iostream>
#include <vector>
#include<algorithm>
#include <fstream>
#include<sstream>
#include <iomanip>
#include "reuse-stack.hpp"

using namespace std;

static int INFINITE_DISTANCE = -1;

/*
* Add the reuse distance result to the histogram
*/
void AddReuseDistance(vector<int>& histogram, int reuseDistance)
{
    histogram.push_back(reuseDistance);
}

/*
* Manipulates the stack by:
* 1. removing the memoryLocation that was previously found
* 2. reinserting the memoryLocations above it back onto the stack
* 3. pushing the memoryLocation on top of the stack
*/
void popAndPushMemoryAddressBackOntoStack (vector<int>& stack, int memoryLocation)
{
    vector<int> distinctLocations;
    stack.pop_back();
    reverse(distinctLocations.begin(),distinctLocations.end());
    stack.insert(stack.end(), distinctLocations.begin(), distinctLocations.end());
    stack.push_back(memoryLocation);
}

/*
* Test Function for troubleshooting int vector
*/
void printIntVector(vector<int> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << ", ";
    }
}

/*
* Calculates reuse distance for memory address read from the trace
* Removes that memory address from the stack if it exists and pushes that memory address back on top of the stack, preserving the order of the rest of the stack
* Returns reuse distance
*/
int CalculateReuseDistance(int memoryLocation, int time, vector<int>& stack, vector<int>& histogram)
{
    vector<int>::iterator found = std::find(stack.begin(), stack.end(), memoryLocation);
    
    if( found != stack.end()) //found in the stack
    {
        int count = 0;
        vector<int> distinctLocations;
        while (memoryLocation != stack.back())
        {
            count++;
            distinctLocations.push_back(stack.back());
            stack.pop_back();
        }
        popAndPushMemoryAddressBackOntoStack(stack, memoryLocation);
        return count;
    }

    else //not found in the stack
    {
        stack.push_back(memoryLocation);
        return INFINITE_DISTANCE;
    }
}

/*
* Receives the reuse distances that were counted
* Structures the collection into a readable histogram
* Prints the histogram results onto the cout filestream
*/
void PrintHistogram(vector<int> reuse)
{
	sort(reuse.begin(), reuse.end());
	vector<int> histogram;
	histogram.push_back(0); //for infinity reuse distances
	histogram.push_back(0); //for 0 reuse distances

	//if element is distinct, then add element to histogram
	//else increment element in histogram
	for (unsigned int i = 0; i < reuse.size(); i++)
	{
		if (reuse[i] == -1)
		{
			histogram[0]++;
		}

		else if (reuse[i] == 0)
		{
			histogram[1]++;
		}

		else if (reuse[i] >= (histogram.size() - 1))
		{
			histogram.resize((long int)reuse[i] + 2);
			histogram[(long int)reuse[i] + 1]++; //+1 to account for the 0 reuse shift
		}
		else 
		{
			histogram[(long int)reuse[i] + 1]++;
		}	
	}

    cout << "Histogram Printing" << endl;
    cout << setw(25) << "Reuse Distance: infinity" << " Count: " << histogram[0] << endl;
    std::cout << setw(25) << "Reuse Distance: 0" << " Count: " << histogram[1] << endl;

    for (unsigned int i = 2; i < histogram.size(); i++)
	{
		cout << setw(25) << "Reuse Distance: " << i - 1 <<  " Count: " << histogram[i] << endl;
	}
}