#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream log("sensor_log.txt");
    log << "Sensor 1: 22.3 C" << endl;
    cout << log.tellp() << endl;
    log << "Sensor 2: 45.8 %RH" << endl;
    cout << log.tellp() << endl;
    log.close();
    return 0;
}
