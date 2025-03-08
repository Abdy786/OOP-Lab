#include <iostream>
#include <string>
using namespace std;

class Physician {
    string fullName;
    string field;
    int yearsOfPractice;

public:
    Physician(string n, string s, int exp) : fullName(n), field(s), yearsOfPractice(exp) {}

    string getFullName() {
        return fullName;
    }

    string getField() {
        return field;
    }

    int getYearsOfPractice() {
        return yearsOfPractice;
    }
};

class MedicalCenter {
    string centerName;
    Physician** physicians;
    int maxCapacity;
    int docCount;

public:
    MedicalCenter(string name) : centerName(name) {
        docCount = 0;
        maxCapacity = 50;
        physicians = new Physician*[maxCapacity];
    }

    void registerPhysician(Physician* doc) {
        if (docCount == maxCapacity) {
            cout << "Physician capacity reached" << endl;
        } else {
            physicians[docCount] = doc;
            docCount++;
            cout << "Physician registered\n" << endl;
        }
    }

    bool removePhysician(Physician* doc) {
        for (int i = 0; i < docCount; i++) {
            if (physicians[i]->getFullName() == doc->getFullName()) {
                delete physicians[i];
                for (int j = i; j < docCount - 1; j++) {
                    physicians[j] = physicians[j + 1];
                }
                docCount--;
                return true;
            }
        }
        return false;
    }

    void transferPhysician(Physician* doc, MedicalCenter* newCenter) {
        if (removePhysician(doc)) {
            newCenter->registerPhysician(doc);
            cout << "Physician " << doc->getFullName() << " transferred to " << newCenter->centerName << endl;
        } else {
            cout << "Physician not found" << endl;
        }
    }

    void showDetails() {
        cout << "Medical Center: " << centerName << endl;
        cout << "Registered Physicians: \n" << endl;
        for (int i = 0; i < docCount; i++) {
            cout << "Name: " << physicians[i]->getFullName() << endl;
            cout << "Field: " << physicians[i]->getField() << endl;
            cout << "Experience: " << physicians[i]->getYearsOfPractice() << " years\n" << endl;
        }
    }
};

int main() {
    MedicalCenter center1("JSMU");
    Physician doc1("Daneyal Fahmi", "Gynecologist", 2);
    Physician doc2("Raman Dileep", "Gynecologist", 3);
    center1.registerPhysician(&doc1);
    center1.registerPhysician(&doc2);
    center1.showDetails();

    MedicalCenter center2("Agha Khan UH");
    Physician doc3("AbdurRehman", "Psychologist", 34);
    center2.registerPhysician(&doc3);
    center1.transferPhysician(&doc2, &center2);
    center1.removePhysician(&doc2);

    center1.showDetails();
    center2.showDetails();
}
