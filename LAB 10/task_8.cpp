#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream config("config.txt");
    config << "123451234512345";
    config.close();
    fstream file("config.txt", ios::in | ios::out);
    file.seekp(5);
    file << "ZZZZZ";
    file.close();
    ifstream read("config.txt");
    string content;
    getline(read, content);
    cout << content;
    read.close();
    return 0;
}
