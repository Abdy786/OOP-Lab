#include <iostream>
#include <string>
using namespace std;

class Stage {
    string stageName;
    int stageNumber;

public:
    Stage(string sname, int snum) : stageName(sname), stageNumber(snum) {}

    string getStageName() {
        return stageName;
    }

    int getStageNumber() {
        return stageNumber;
    }
};

class Game {
    string title;
    string category;
    int totalStages;
    Stage** stages;
    int stageCount;

public:
    Game(string t, string c, int numStages, Stage* firstStage) : title(t), category(c), totalStages(numStages), stageCount(0) {
        if (totalStages > 0) {
            stages = new Stage*[totalStages];
            addStage(firstStage);
        }
    }

    void addStage(Stage* stage) {
        if (stageCount < totalStages) {
            stages[stageCount] = stage;
            stageCount++;
        } else {
            cout << "Maximum stage limit reached" << endl;
        }
    }

    void showGameDetails() {
        cout << "Game Title: " << title << endl;
        cout << "Category: " << category << endl;
        cout << "Stages: " << endl;
        for (int i = 0; i < stageCount; i++) {
            cout << "Stage " << stages[i]->getStageNumber() << ": " << stages[i]->getStageName() << endl;
        }
    }

    ~Game() {
        for (int i = 0; i < stageCount; i++) {
            delete stages[i];
        }
        delete[] stages;
    }
};

int main() {
    Stage stage1("Start", 1);
    Game game1("Side Quest", "Assassination", 3, &stage1);
    Stage stage2("Mid Fight", 2);
    Stage stage3("Finale", 3);
    game1.addStage(&stage2);
    game1.addStage(&stage3);

    game1.showGameDetails();

    return 0;
}
