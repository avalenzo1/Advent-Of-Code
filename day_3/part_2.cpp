#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

int parseCalculation(string text)
{
    size_t tokens[3] = {text.find("("), text.find(","), text.find(")")};

    int X = stoi(text.substr(tokens[0] + 1, tokens[1] - tokens[0] - 1));
    int Y = stoi(text.substr(tokens[1] + 1, tokens[2] - tokens[1] - 1));

    return X * Y;
}

int parseLine(string text, bool &enabled)
{
    string text_cpy = text;

    regex multiply_fun_pattern("mul\\([0-9]+,[0-9]+\\)");
    regex do_fun_pattern("do\\(\\)");
    regex dont_fun_pattern("don't\\(\\)");

    smatch match;

    int pos = 0;
    int total = 0;

    map<int, string> tokens; // <index, substring>

    while (regex_search(text, match, do_fun_pattern))
    {
        pos += match.position();

        tokens[pos] = match[0];

        pos += match[0].length();

        text = match.suffix().str();
    }

    text = text_cpy;
    pos = 0;

    while (regex_search(text, match, dont_fun_pattern))
    {
        pos += match.position();

        tokens[pos] = match[0];
        pos += match[0].length();

        text = match.suffix().str();
    }

    text = text_cpy;
    pos = 0;

    while (regex_search(text, match, multiply_fun_pattern))
    {
        pos += match.position();

        tokens[pos] = match[0];
        pos += match[0].length();
        text = match.suffix().str();
    }

    for (auto &[index, substr] : tokens)
    {
        if (substr == "do()")
        {
            // cout << "Enabled multiplication" << endl;
            enabled = true;
        }
        else if (substr == "don't()")
        {
            // cout << "Disabled multiplication" << endl;
            enabled = false;
        }
        else
        {
            if (enabled)
            {
                total += parseCalculation(substr);
            }
            else
            {
                // cout << "Ignored calculation" << endl;
            }
        }
    }

    return total;
}

int main()
{
    ifstream file("./data.txt");
    string line;
    int total = 0;
    bool enabled = true;

    while (getline(file, line))
    {
        total += parseLine(line, enabled);
    }

    cout << "Total: " << total << endl;

    return 0;
}