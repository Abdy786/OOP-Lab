#include <iostream>
#include <string>
using namespace std;

// Task 1: Enroll Event Attendees
void enrollAttendees(string listA[], string listB[]) {
    cout << "Enter names for Event A:\n";
    for (int i = 0; i < 5; i++)
        cin >> listA[i];
    cout << "Enter names for Event B:\n";
    for (int i = 0; i < 5; i++)
        cin >> listB[i];
}

// Task 2: Verify Attendance
bool verifyAttendee(string listA[], string listB[], int count, string participant) {
    for (int i = 0; i < count; i++) {
        if (listA[i] == participant || listB[i] == participant)
            return true;
    }
    return false;
}

// Task 3: Compute Total Contributions
int computeContributions(int count) {
    return count * 2 * 10;
}

// Task 4: Show Attendee Names in Reverse
void showReverseList(string list[], int count) {
    for (int i = count - 1; i >= 0; i--)
        cout << list[i] << " ";
    cout << endl;
}

// Task 5: Represent Event Popularity
void generateBarGraph(int value) {
    for (int i = 0; i < value; i++)
        cout << "*";
    cout << endl;
}

int main() {
    string listA[5], listB[5];
    enrollAttendees(listA, listB);
    
    string participant;
    cout << "Enter name to verify: ";
    cin >> participant;
    cout << (verifyAttendee(listA, listB, 5, participant) ? "Registered" : "Not Registered") << endl;
    
    cout << "Total Contributions: " << computeContributions(5) << endl;
    
    cout << "Event A in reverse: ";
    showReverseList(listA, 5);
    cout << "Event B in reverse: ";
    showReverseList(listB, 5);
    
    cout << "Event A Popularity: ";
    generateBarGraph(5);
    cout << "Event B Popularity: ";
    generateBarGraph(5);
    
    return 0;
}
