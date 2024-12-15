#include <iostream>
#include <fstream>
#include <map>
#include <math.h>

using namespace std;

int main()
{
    // Opens file with list of distanes
    ifstream file("./dist.txt");
    int score, lhs, rhs;

    score = 0;

    priority_queue<int> pq_lhs;
    map<int, int> counter_rhs;

    while (file >> lhs && file >> rhs)
    {
        pq_lhs.push(lhs);

        // Initialize rhs counter with lhs number if not exists
        if (!counter_rhs.count(lhs)) {
            counter_rhs[lhs] = 0;
        }

        // Check if rhs in counter_rhs exists
        if (counter_rhs.count(rhs)) {
            // increment
            counter_rhs[rhs]++;
        } else {
            // initialize with 1
            counter_rhs[rhs] = 1;
        }
    }

    while (!pq_lhs.empty()) {
        lhs = pq_lhs.top();
        
        // multiply score by rhs_counter
        score += lhs * counter_rhs[lhs];

        pq_lhs.pop();
    }

    cout << "Similarity score: " << score << endl;
}