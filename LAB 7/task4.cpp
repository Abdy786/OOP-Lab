#include <iostream>
using namespace std;

class Individual {
    protected:
    string fullName;
    int yearsOld;
    double phoneNumber;
    string homeAddress;
    public:
    Individual(string n, int a, double cn, string ad) : fullName(n), yearsOld(a), phoneNumber(cn), homeAddress(ad) {}
    virtual void showDetails() {
        cout << "Full Name: " << fullName << endl;
        cout << "Age: " << yearsOld << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Home Address: " << homeAddress << endl;
    }
    void updateDetails(double cont, string addr) {
        homeAddress = addr;
        phoneNumber = cont;
        cout << "Details Updated!" << endl;
    }
};

class MedicalPatient : public Individual {
    protected:
    int patientID;
    string medicalHistory;
    string assignedDoctor;
    public:
    MedicalPatient(string n, int a, double cn, string ad, int id, string mh, string da) : Individual(n, a, cn, ad), patientID(id), medicalHistory(mh), assignedDoctor(da) {}
    void showDetails() override {
        Individual::showDetails();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Assigned Doctor: " << assignedDoctor << endl;
    }
};

class MedicalDoctor : public Individual {
    protected:
    string specialization;
    double consultationFee;
    string patientList[10];
    int patientCount;
    public:
    MedicalDoctor(string n, int a, double cn, string ad, string sp, double cf) : Individual(n, a, cn, ad), specialization(sp), consultationFee(cf), patientCount(0) {}
    void addPatient(string patName) {
        if (patientCount < 10) {
            patientList[patientCount] = patName;
            patientCount++;
        }
    }
    void showDetails() override {
        Individual::showDetails();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        for (int i = 0; i < patientCount; i++) {
            cout << patientList[i] << " , ";
        }
        cout << endl;
    }
};

class MedicalNurse : public Individual {
    protected:
    string assignedWard;
    string shiftTimings;
    public:
    MedicalNurse(string n, int a, double cn, string ad, string aw, string st) : Individual(n, a, cn, ad), assignedWard(aw), shiftTimings(st) {}
    void showDetails() override {
        Individual::showDetails();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class HospitalAdmin : public Individual {
    protected:
    string department;
    double salary;
    public:
    HospitalAdmin(string n, int a, double cn, string ad, string dp, double sl) : Individual(n, a, cn, ad), department(dp), salary(sl) {}
    void updateDetails(double cont, string addr, double newSalary) {
        Individual::updateDetails(cont, addr);
        salary = newSalary;
        cout << "Salary updated to $" << salary << endl;
    }
    void showDetails() override {
        Individual::showDetails();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    MedicalPatient pat1("Ali", 12, 213123123, "Orangi", 1, "Retardation", "Dr. Murtaza");
    MedicalDoctor doc1("Murtaza", 42, 321312312, "Korangi", "Dentist", 5000);
    MedicalNurse nur1("Saalim", 30, 131231232, "DHA", "A-12", "6:00 AM - 8:00 PM");
    HospitalAdmin admin1("Abdullah", 66, 21313123, "Gulshan", "Cardiology", 30000);
    doc1.addPatient("Rameez");

    cout << "Patient Info: ";
    pat1.showDetails();

    cout << "Doctor Info: ";
    doc1.showDetails();

    cout << "Nurse Info: ";
    nur1.showDetails();

    cout << "Administrator Info: ";
    admin1.showDetails();

    return 0;
}