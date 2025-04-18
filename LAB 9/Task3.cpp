#include <iostream>
using namespace std;

class Course {
public:
    string courseCode;
    int credits;

    Course(string code, int c) {
        courseCode = code;
        credits = c;
    }

    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

class LectureCourse : public Course {
public:
    LectureCourse(string code, int c) : Course(code, c) {}

    void calculateGrade() {
        cout << "Final Grade = 70% exam + 30% assignments" << endl;
    }

    void displayInfo() {
        cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, int c) : Course(code, c) {}

    void calculateGrade() {
        cout << "Final Grade = 60% lab work + 40% quiz" << endl;
    }

    void displayInfo() {
        cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

int main() {
    LectureCourse lec("CS101", 3);
    LabCourse lab("CS102L", 1);

    Course* c1 = &lec;
    Course* c2 = &lab;

    c1->displayInfo();
    c1->calculateGrade();

    c2->displayInfo();
    c2->calculateGrade();

    return 0;
}