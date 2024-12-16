#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

int parseCalculation(string text) {
    size_t tokens[3] = {text.find("("), text.find(","), text.find(")")};

    int X = stoi(text.substr(tokens[0] + 1, tokens[1] - tokens[0] - 1));
    int Y = stoi(text.substr(tokens[1] + 1, tokens[2] - tokens[1] - 1));

    return X * Y;
}

int parseLine(string text)
{
    regex pattern( "mul\\([0-9]+,[0-9]+\\)");
    smatch match;
    int total = 0;

    while(regex_search(text, match, pattern))
    {
        std::cout << "Found substring: " << match[0] << std::endl;

        total += parseCalculation(match[0]);

        text = match.suffix().str();
    }

    return total;
}

int main()
{
    ifstream file("./data.txt");
    string line;
    int total = 0;

    while (getline(file, line))
    {
        total += parseLine(line);
    }
    
    cout << "Total: " << total << endl;

    return 0;
}