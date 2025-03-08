#include <iostream>
#include <string>
using namespace std;

class Task;

class Worker {
    string role;
    string fullName;
    int taskCount = 0;
    Task* tasks[10];

public:
    Worker(string jobTitle, string wName) : role(jobTitle), fullName(wName) {}

    string getFullName() {
        return fullName;
    }

    string getRole() {
        return role;
    }
};

class Task {
    string taskName;
    string dueDate;
    int workerCount = 0;
    Worker* workers[10];

public:
    Task(string name, string deadline) : taskName(name), dueDate(deadline) {}

    void assignWorker(Worker* worker) {
        workers[workerCount] = worker;
        workerCount++;
    }

    void showTaskDetails() {
        cout << "Task Name: " << taskName << endl;
        cout << "Deadline: " << dueDate << endl;
        cout << "\nAssigned Workers:\n" << endl;
        for (int i = 0; i < workerCount; i++) {
            cout << "Worker Name: " << workers[i]->getFullName() << endl;
            cout << "Role: " << workers[i]->getRole() << endl;
        }
    }

    string getTaskName() {
        return taskName;
    }

    string getDueDate() {
        return dueDate;
    }
};

int main() {
    Worker worker1("Head", "Abdullah Hakro");
    Worker worker2("Teacher", "Syed Ali");
    
    Task task1("Programming", "10th March 2025");
    task1.assignWorker(&worker1);
    task1.assignWorker(&worker2);
    task1.showTaskDetails();

    Task task2("Code Testing", "12th March 2025");
    task2.assignWorker(&worker1);
    task2.showTaskDetails();
}
