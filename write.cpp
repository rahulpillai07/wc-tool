#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << " [-c] <filename>" << endl;
        return 1;
    }

    string option = argv[1];
    string filename = argv[2];

    if (option == "-c")
    {
        ifstream fin(filename);
        int byteCount = 0;
        char ch;
        string line;
        int lineCount = 0;
        if (!fin.is_open())
        {
            cerr << "Error opening the file " << filename << endl;
            return 1;
        }
        while (fin.get(ch))
        {
            byteCount++;
        }
        fin.clear();
        fin.seekg(0);
        while (getline(fin, line))
        {
    

            lineCount++;
        }
        fin.close();
        cout << "byte count of the file is " << byteCount << endl;
        cout << "line count of the file is " << lineCount << endl;
    }
    else
    {
        cerr << "Unrecognized action" << endl;
        return 1;
    }
    return 0;
}