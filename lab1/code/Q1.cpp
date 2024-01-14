#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputFile("Q1_input.txt");

    ofstream outputFile("Q1_output.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    int length;
    inputFile >> length;

    vector<int> a(length);
    for (int i = 0; i < length; ++i)
    {
        inputFile >> a[i];
    }

    inputFile.close();

    if (length < 2)
    {
        cerr << "Error: Array should have at least two elements." << endl;
        return 1;
    }

    sort(a.begin(),a.end());

    outputFile << "Maximum Sum: " << a[length-1]+a[length-2] << endl;

    outputFile.close();

    return 0;
}
