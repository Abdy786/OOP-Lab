#include <iostream>
#include <string>
using namespace std;

struct Worker
{
    string fullName;
    int workHours;
    int payPerHour;
};

int main()
{
    Worker staffMember;
    int totalWorkers;
    cout << "Enter the number of employees: ";
    cin >> totalWorkers;
    Worker *staffList = new Worker[totalWorkers];

    for (int i = 0; i < totalWorkers; i++)
    {
        cout << "Enter details for employee [" << i + 1 << "]: " << endl;
        cout << "Full Name: ";
        cin >> staffList[i].fullName;
        cout << "Hourly Wage: ";
        cin >> staffList[i].payPerHour;
        cout << "Hours Worked: ";
        cin >> staffList[i].workHours;
    }
    int calculatedSalary;
    for (int i = 0; i < totalWorkers; i++)
    {
        calculatedSalary = staffList[i].payPerHour * staffList[i].workHours;
        cout << "Total salary for employee [" << i + 1 << "]: " << calculatedSalary << endl;
    }
    delete[] staffList;
}