#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream writer("data.txt");
    writer << "One
";
    writer << "Two
";
    writer << "Three
";
    writer << "Four
";
    writer.close();
    ifstream reader("data.txt");
    reader.seekg(14);
    string row;
    getline(reader, row);
    cout << row;
    reader.close();
    return 0;
}
