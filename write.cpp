#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int countBytes(const string& filename) {
    ifstream fin(filename, ios::binary); // Open the file in binary mode
    int byteCount = 0;
    char ch;

    if (!fin.is_open()) {
        cerr << "Error opening the file " << filename << endl;
        return -1; 
    }

    while (fin.get(ch)) {
        byteCount++;
    }

    fin.close(); 
    return byteCount;
}

int countLines(const string& filename) {
    ifstream fin(filename);
    string line;
    int lineCount = 0;

    if (!fin.is_open()) {
        cerr << "Error opening the file " << filename << endl;
        return -1; 
    }

    while (getline(fin, line)) {
        lineCount++;
    }

    fin.close(); 
    return lineCount;
}


int countWords(const string& filename) {
    ifstream fin(filename);
    string word;
    int wordCount = 0;

    if (!fin.is_open()) {
        cerr << "Error opening the file " << filename << endl;
        return -1; 
    }

    while (fin >> word) {
        wordCount++;
    }

    fin.close(); 
    return wordCount;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " [-c|-l|-w] <filename>" << endl;
        return 1;
    }

    string option = "";
    string filename = argv[1]; 

    if (argc >= 3) {
        option = argv[1];
        filename = argv[2];
    }

    int byteCount = countBytes(filename);
    int lineCount = countLines(filename);
    int wordCount = countWords(filename);

    if (option == "-c") {
        cout << "Byte count of the file is " << byteCount << endl;
    } else if (option == "-l") {
        cout << "Line count of the file is " << lineCount << endl;
    } else if (option == "-w") {
        cout << "Number of words in " << filename << ": " << wordCount << endl;
    } else {
        cout << "Byte Count: " << byteCount << endl;
        cout << "Line Count: " << lineCount << endl;
        cout << "Word Count: " << wordCount << endl;
    }

    return 0;
}
