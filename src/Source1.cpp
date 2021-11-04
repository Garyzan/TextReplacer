#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <list>

using namespace std;

void replaceAll(string& str, const string& from, const string& to) {
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main(int argc, char* argv[])
{
    const int argcount = argc;
    ifstream itxt;
    ofstream otxt;
    string find = "", repl = "";
    list<string> valnam;
    string in;

    cout << "\n\nQuick Replace tool by Garyzan\n\n\n\tOpened files:\n\n";

    for (int i = 1; i < argc; ++i) {
        cout << "\t\t" << argv[i] << endl;
    }

    cout << "\n\n\tEnter text to be replaced\n\n";
    cin >> find;
    cout << "\n\tEnter replacement text\n\n";
    cin >> repl;
    cout << "\n";

    for (int i = 1; i < argc; ++i) {
        string str = argv[i];
        if (str.substr(str.length() - 4, str.length() - 1) == ".txt") {
            valnam.push_back(str);
        }
        else {
            cout << "\t" << argv[i] << " is not a .txt file" << endl;
        }
    }

    cout << "\n\n\tIn the following file(s), " << find << " will be replaced with " << repl << ":\n\n";
    for (string s : valnam) {
        cout << "\t\t" << s << endl;
    }
    cout << "\n\n\tProceed? (Y|N)\n\n";

    cin >> in;
    if (in == "Y") {
        for (string s : valnam) {

            string str = "";

            itxt.open(s);
            itxt >> str;
            itxt.close();

            replaceAll(str, find, repl);

            otxt.open(s, ios::trunc);
            otxt << str;
            otxt.close();

        }
        cout << "\n\tReplacement finished.\n\tPress any key to exit.";
    }
    else {
        cout << "\n\tReplacement canceled.\n\tPress any key to exit.";
    }

    while(!_kbhit()){}

}