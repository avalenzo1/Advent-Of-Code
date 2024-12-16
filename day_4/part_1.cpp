#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void checkForSolves(const vector<string>& grid, vector<string>& solved, int r, int c, int& count) {
    if (grid[r][c] != 'X') return;
    
    if (grid[r][c] == 'X' && grid[r][c-1] == 'M' && grid[r][c-2] == 'A' && grid[r][c-3] == 'S') {
        // check left
        solved[r][c] = 'X';
        solved[r][c-1] = 'M';
        solved[r][c-2] = 'A';
        solved[r][c-3] = 'S';

        count++;
    }

    if (grid[r][c] == 'X' && grid[r][c+1] == 'M' && grid[r][c+2] == 'A' && grid[r][c+3] == 'S') {
        // check right
        solved[r][c] = 'X';
        solved[r][c+1] = 'M';
        solved[r][c+2] = 'A';
        solved[r][c+3] = 'S';
        count++;

    }

    if (grid[r][c] == 'X' && grid[r-1][c] == 'M' && grid[r-2][c] == 'A' && grid[r-3][c] == 'S') {
        // check top
        solved[r][c] = 'X';
        solved[r-1][c] = 'M';
        solved[r-2][c] = 'A';
        solved[r-3][c] = 'S';
        count++;

    }

    if (grid[r][c] == 'X' && grid[r+1][c] == 'M' && grid[r+2][c] == 'A' && grid[r+3][c] == 'S') {
        // check bottom
        solved[r][c] = 'X';
        solved[r+1][c] = 'M';
        solved[r+2][c] = 'A';
        solved[r+3][c] = 'S';
        count++;

    }

    if (grid[r][c] == 'X' && grid[r-1][c-1] == 'M' && grid[r-1][c-2] == 'A' && grid[r-1][c-3] == 'S') {
        // check top-left
        solved[r][c] = 'X';
        solved[r-1][c-1] = 'M';
        solved[r-2][c-2] = 'A';
        solved[r-3][c-3] = 'S';
        count++;

    }

    if (grid[r][c] == 'X' && grid[r-1][c+1] == 'M' && grid[r-2][c+2] == 'A' && grid[r-3][c+3] == 'S') {
        // check top-right
        solved[r][c] = 'X';
        solved[r-1][c+1] = 'M';
        solved[r-2][c+2] = 'A';
        solved[r-3][c+3] = 'S';
        count++;

    }

    if (grid[r][c] == 'X' && grid[r+1][c-1] == 'M' && grid[r+2][c-2] == 'A' && grid[r+3][c-3] == 'S') {
        // check bottom-left
        solved[r][c] = 'X';
        solved[r+1][c-1] = 'M';
        solved[r+2][c-2] = 'A';
        solved[r+3][c-3] = 'S';
        count++;

    }

    if (grid[r][c] == 'X' && grid[r+1][c+1] == 'M' && grid[r+2][c+2] == 'A' && grid[r+3][c+3] == 'S') {
        // check bottom-right
        solved[r][c] = 'X';
        solved[r+1][c+1] = 'M';
        solved[r+2][c+2] = 'A';
        solved[r+3][c+3] = 'S';
        count++;

    }
}

int main()
{
    ifstream file("data.txt");

    vector<string> grid;
    string col_str;

    vector<string> solved_grid;

    int count = 0;

    while (file >> col_str)
    {
        string empty(col_str.size(), '.');
        solved_grid.push_back(empty);
        grid.push_back(col_str);
    }

    for (size_t r = 0; r < grid.size(); ++r)
    {
        for (size_t c = 0; c < grid.at(r).size(); ++c)
        {
            checkForSolves(grid, solved_grid, r, c, count);
        }
    }

    cout << "Solved Grid:" << endl;
    for (size_t r = 0; r < solved_grid.size(); ++r)
    {
        for (size_t c = 0; c < solved_grid.at(r).size(); ++c)
        {
            cout << solved_grid[r][c];
        }
        cout << endl;
    }

    cout << "XMAS Count: " << count << endl;

    file.close();
}