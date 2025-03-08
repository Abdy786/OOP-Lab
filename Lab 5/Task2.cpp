#include <iostream>
#include <string>

using namespace std;

class Learner {
private:
    int regNo;
    string fullName;
    int* marks;

public:
    Learner(int id, string fname, int score[]) : regNo(id), fullName(fname) {
        marks = new int[10];
        for (int i = 0; i < 10; i++) {
            marks[i] = score[i];
        }
    }

    Learner(const Learner& copy) : regNo(copy.regNo), fullName(copy.fullName) {
        marks = new int[10];
        for (int i = 0; i < 10; i++) {
            marks[i] = copy.marks[i];
        }
    }

    ~Learner() {
        delete[] marks;
    }

    void showDetails() {
        cout << "Learner Registration No: " << regNo << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Marks Obtained: ";
        for (int i = 0; i < 10; i++) {
            cout << marks[i] << " ";
        }
        cout << "\n" << endl;
    }
};

int main() {
    int marksList[] = {23, 52, 42, 93, 13, 98, 77, 28, 23, 79};
    Learner learner1(1234, "Abdullah Hakro", marksList);
    cout << "Original Learner Details: \n" << endl;
    learner1.showDetails();
    Learner duplicateLearner = learner1;
    cout << "Copied Learner Details: " << endl;
    duplicateLearner.showDetails();
}
