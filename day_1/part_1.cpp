#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    // Opens file with list of distanes
    ifstream file("./dist.txt");
    int sum, lhs, rhs;

    sum = 0;

    priority_queue<int> pr_lhs;
    priority_queue<int> pr_rhs;

    while (file >> lhs && file >> rhs)
    {
        pr_lhs.push(lhs);
        pr_rhs.push(rhs);
    }

    while (!pr_lhs.empty() && !pr_rhs.empty()) {
        lhs = pr_lhs.top();
        rhs = pr_rhs.top();

        pr_lhs.pop();
        pr_rhs.pop();

        sum += abs(rhs - lhs);
    }

    cout << "Distance Sum: " << sum << endl;
}