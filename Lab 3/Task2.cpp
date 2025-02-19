#include <iostream>
#include <string>
using namespace std;

class FitnessTracker {
private:
    string user;
    int stepGoal;
    int stepsToday;
    double caloriesBurned;

public:
    FitnessTracker(string userName, int dailyGoal) {
        user = userName;
        stepGoal = dailyGoal;
        stepsToday = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps) {
        stepsToday += steps;
    }

    void calculateCalories() {
        caloriesBurned = stepsToday * 0.04;
    }

    void displayProgress() {
        cout << "\nUser: " << user << endl;
        cout << "Daily Step Goal: " << stepGoal << endl;
        cout << "Steps Taken Today: " << stepsToday << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;

        if (stepsToday >= stepGoal) {
            cout << "\n🎉 Fitness Goal Met For Today! 🎉\n" << endl;
        } else {
            cout << "\n🚶 " << (stepGoal - stepsToday) << " steps remaining to reach your goal! 🚶\n" << endl;
        }
    }
};

int main() {
    FitnessTracker userTracker("Laiba", 20000);
    userTracker.logSteps(5000);
    userTracker.calculateCalories();
    userTracker.displayProgress();

    userTracker.logSteps(15000);
    userTracker.calculateCalories();
    userTracker.displayProgress();

    return 0;
}
