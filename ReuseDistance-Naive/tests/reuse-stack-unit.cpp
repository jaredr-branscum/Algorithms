#include<iostream>
#include <vector>
#include<algorithm>
#include <fstream>
#include<sstream>
#include <iomanip>
#include "./../src/reuse-stack.hpp"

using namespace std;

int main()
{
    int time = 1;
    vector<int> histogram;
    vector<int> stack;

    ifstream file;
    file.open("./test-data/test-data-1.txt");
    string str;
    int memoryLocation;
    while (getline(file, str))
    {
        memoryLocation = stoi(str);
        //run search algorithm
        int reuseDistance = CalculateReuseDistance(memoryLocation, time, stack, histogram );
        AddReuseDistance(histogram, reuseDistance);
        time++;
    }
    file.close();
    cout << "Number of lines: " << time - 1 << endl;
    cout << "Printing Histogram" << endl;
    PrintHistogram(histogram);

}

/*
* Unit Tests
*/