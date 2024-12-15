#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int isSafe(string n)
{
    stringstream ss(n);

    int prevNum = -1;
    int currNum = 0;
    int direction = 0;

    while (ss >> currNum)
    {
        if (prevNum == -1)
        {
            // do nothing
        }
        else
        {
            if ((abs(currNum - prevNum)) <= 0 || (abs(currNum - prevNum) >= 4))
            {
                return 0;
            }

            if (!direction) {
                if (prevNum < currNum) {
                    direction = 1;
                } else {
                    direction = -1;
                }
            } else {
                if (((prevNum < currNum) && direction == -1) || ((prevNum > currNum) && direction == 1)) {
                    return 0;
                }
            }
        }

        prevNum = currNum;
    }

    return 1;
}

int main()
{
    cout << "Welcome to Day 2 of Advent Of Code" << endl;

    cout << endl;
    cout << "Beggining tests..." << endl;
    cout << endl;

    cout << "testing for input '7 6 4 2 1'" << endl;
    if (!isSafe("7 6 4 2 1"))
    {
        cerr << "returned false when should return true" << endl;
        return 1;
    }

    cout << "testing for input '1 2 7 8 9'" << endl;
    if (isSafe("1 2 7 8 9"))
    {
        cerr << "returned true when should return false" << endl;
        return 1;
    }

    cout << "testing for input '9 7 6 2 1" << endl;
    if (isSafe("9 7 6 2 1"))
    {
        cerr << "returned true when should return false" << endl;
        return 1;
    }

    cout << "testing for input '1 3 2 4 5'" << endl;
    if (isSafe("1 3 2 4 5"))
    {
        cerr << "returned true when should return false" << endl;
        return 1;
    }

    cout << "testing for input '8 6 4 4 1'" << endl;
    if (isSafe("8 6 4 4 1"))
    {
        cerr << "returned true when should return false" << endl;
        return 1;
    }

    cout << "testing for input '1 3 6 7 9'" << endl;
    if (!isSafe("1 3 6 7 9"))
    {
        cerr << "returned false when should return true" << endl;
        return 1;
    }

    cout << "All tests passed! Running solution..." << endl;
    cout << endl;

    ifstream file("./data.txt");
    string line;

    int safeCount = 0;

    while (getline(file, line))
    {
        if (isSafe(line))
            safeCount++;
    }

    cout << safeCount << endl;

    return 0;
}