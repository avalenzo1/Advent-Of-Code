#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

void parseLine(string line)
{
    const regex r("mul\\([0-9]+,[0-9]+\\)");
    smatch m;

    // std::cout << line << '\n';

    if (std::regex_match(line, m, r))
    {
        cout << m.size();
    } else {
        cout << ":(";
    }
}

int main()
{
    ifstream file("./data.txt");
    string line;

    while (getline(file, line))
    {
        parseLine(line);
    }

    return 0;
}