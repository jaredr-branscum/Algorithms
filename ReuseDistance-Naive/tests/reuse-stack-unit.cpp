#include<iostream>
#include <vector>
#include<algorithm>
#include <fstream>
#include<sstream>
#include <iomanip>
#include <assert.h>
#include <set>
#include <stdlib.h>

#include "./../src/reuse-stack.hpp"

using namespace std;

/*
* Process Dataset files
*/
vector<int> ProcessDataSet(string filepathUrl)
{
    ifstream file;
    vector<int> trace;
    string str;
    file.open(filepathUrl);
    while (getline(file, str))
    {
        int memoryLocation = stoi(str);
        trace.push_back(memoryLocation);
    }
    file.close();
    cout << "Dataset: " << filepathUrl << " processed successfully" << endl;
    return trace;
}

/*
* Unit Testing Calculate Reuse Distance
*/

void verifyReuseofAdjacentElements()
{
    int memoryLocation = 0;
    vector<int> stack = {0};
    assert(0 == CalculateReuseDistance(memoryLocation, stack));
    cout << "verifyReuseofAdjacentElements Test Passed" << endl;
}

void verifyReuseofElementNotFound()
{
    int memoryLocation = 0;
    vector<int> stack = {1};
    assert(-1 == CalculateReuseDistance(memoryLocation, stack));
    cout << "verifyReuseofElementNotFound Test Passed" << endl;
}

void verifyReuseofNonAdjacentElements()
{
    int memoryLocation = 0;
    vector<int> stack = {0,1,2};
    assert(2 == CalculateReuseDistance(memoryLocation, stack));
    cout << "verifyReuseofNonAdjacentElements Test Passed" << endl;
}

void verifyReuseofEmptyStack()
{
    int memoryLocation = 0;
    vector<int> stack;
    assert(-1 == CalculateReuseDistance(memoryLocation, stack));
    cout << "verifyReuseofEmptyStack Test Passed" << endl;
}

void verifyStackAlwaysHasUniqueIntegers(vector<int> trace)
{
    //verify by running CalculateReuseDistance on a dataset
    vector<int> histogram;
    vector<int> stack;
    string str;
    int memoryLocation;
    for (int i = 0; i < trace.size(); i++)
    {
        memoryLocation = trace[i];
        int reuseDistance = CalculateReuseDistance(memoryLocation, stack);
        set<int> s(stack.begin(), stack.end());
        assert(s.size() == stack.size()); //check that no duplicates exist
    }
    cout << "verifyStackAlwaysHasUniqueIntegers Test Passed" << endl;
}

/*
* Unit Testing CreateHistogram
*/

void verifyInfiniteReuseHistogram()
{
    vector<int> reuse = {-1};
    vector<int> histogram = CreateHistogram(reuse);
    assert(histogram[0] == 1);
    cout << "verifyInfiniteReuseHistogram Test Passed" << endl;
}

void verifyZeroReuseHistogram()
{
    vector<int> reuse = {0};
    vector<int> histogram = CreateHistogram(reuse);
    assert(histogram[1] == 1);
    cout << "verifyZeroReuseHistogram Test Passed" << endl;
}

void verifyEmptyReuseHistogram()
{
    vector<int> reuse;
    vector<int> histogram = CreateHistogram(reuse);
    assert(histogram[0] == 0);
    assert(histogram[1] == 0);
    cout << "verifyEmptyReuseHistogram Test Passed" << endl;
}

void PrintHistogram(vector<int> histogram)
{
    cout << "Histogram Printing" << endl;
    cout << setw(25) << "Reuse Distance: inf" << " Count: " << histogram[0] << endl;
    std::cout << setw(25) << "Reuse Distance: 0" << " Count: " << histogram[1] << endl;

    for (unsigned int i = 2; i < histogram.size(); i++)
    {
        cout << setw(25) << "Reuse Distance: " << i - 1 <<  " Count: " << histogram[i] << endl;
    }
    cout << endl;
}

void verifyNormalReuseHistogram(vector<int> dataset)
{
    cout << "Testing the following dataset: ";
    printIntVector(dataset);
    cout << endl;
    vector<int> reuse;
    vector<int> stack;
    vector<int> histogram;
    for (unsigned int i = 0; i < dataset.size(); i++)
    {
        int reuseValue = CalculateReuseDistance(dataset[i], stack);
        AddReuseDistance(reuse, reuseValue);
    }
    cout << "Reuse vector is: ";printIntVector(reuse);cout << endl;
    histogram = CreateHistogram(reuse);
    PrintHistogram(histogram);
}

int main()
{
    system("Color 0A");
    vector<int> datasetEmpty;
    vector<int> dataset1 = ProcessDataSet("./test-data/test-data-1.txt");
    vector<int> dataset2 = ProcessDataSet("./test-data/test-data-2.txt");
    vector<int> dataset3 = ProcessDataSet("./test-data/test-data-3.txt");
    vector<int> dataset4 = ProcessDataSet("./test-data/test-data-4.txt");
    vector<int> dataset5 = ProcessDataSet("./test-data/test-data-5.txt");

    verifyReuseofAdjacentElements();
    verifyReuseofElementNotFound();
    verifyReuseofNonAdjacentElements();
    verifyReuseofEmptyStack();
    verifyStackAlwaysHasUniqueIntegers(dataset1);
    verifyStackAlwaysHasUniqueIntegers(dataset2);
    verifyStackAlwaysHasUniqueIntegers(dataset3);
    verifyStackAlwaysHasUniqueIntegers(dataset4);
    verifyStackAlwaysHasUniqueIntegers(dataset5);
    verifyStackAlwaysHasUniqueIntegers(datasetEmpty);
    verifyInfiniteReuseHistogram();
    verifyZeroReuseHistogram();
    verifyEmptyReuseHistogram();
    cout << "================================" << endl;
    verifyNormalReuseHistogram(datasetEmpty);
    verifyNormalReuseHistogram(dataset1);
    verifyNormalReuseHistogram(dataset2);
    verifyNormalReuseHistogram(dataset3);
    verifyNormalReuseHistogram(dataset4);
    verifyNormalReuseHistogram(dataset5);
}
