// Dynamic memory allocations for student records
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string fullName;
    int rollNumber;
    int obtainedMarks;
};

int main()
{
    Student record;
    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;

    Student *records = new Student[studentCount];
    for (int i = 0; i < studentCount; i++)
    {
        cout << "Enter details for student [" << i + 1 << "]:" << endl;
        cout << "Name: ";
        cin >> records[i].fullName;
        cout << "Roll No: ";
        cin >> records[i].rollNumber;
        cout << "Marks: ";
        cin >> records[i].obtainedMarks;
    }
    
    int totalMarks = 0;
    for (int i = 0; i < studentCount; i++)
    {
        totalMarks += records[i].obtainedMarks;
    }

    int averageMarks = totalMarks / studentCount;

    cout << "The average marks of the students is: " << averageMarks << endl;

    delete[] records;
}
