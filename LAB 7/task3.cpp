#include <iostream>
using namespace std;

class Pass {
    protected:
    int passID;
    string travelerName;
    double cost;
    string travelDate;
    string destination;
    public:
    Pass(int ID, string N, double p, string d, string dest) : passID(ID), travelerName(N), cost(p), travelDate(d), destination(dest) {}
   virtual void book() {
        cout << "Pass booked for " << travelerName << " to " << destination << " on " << travelDate << "" << endl;
    }

   virtual void cancel(){
    cout << "Pass : " << passID << " has been cancelled" << endl;
   }

   virtual void displayPassInfo(){
    cout << "Pass ID : " << passID << endl;
    cout << "Traveler Name :" << travelerName << endl;
    cout << "Cost : " << cost << endl;
    cout << "DATE : " << travelDate << endl;
    cout << "Destination : " << destination << endl;
   }
};
class AirPass : public Pass {
    protected:
    string airline;
    string flightNum;
    string seatClass;
    public:
    AirPass(int ID, string N, double p, string d, string dest, string airline, string flight, string sc) : Pass(ID, N, p, d, dest), airline(airline), flightNum(flight), seatClass(sc) {}
    void displayPassInfo() override {
        Pass::displayPassInfo();
        cout << "Airline :" << airline << endl;
        cout << "Flight Number : " << flightNum << endl;
        cout << "Seat Class : " << seatClass << endl;
    }
};
class RailPass : public Pass {
    protected:
    string trainNum;
    string coachType;
    string departureTime;
    public:
    RailPass(int ID, string N, double p, string d, string dest, string train, string ct, string dt) : Pass(ID, N, p, d, dest), trainNum(train), coachType(ct), departureTime(dt) {}
    void book() override {
        cout << "Seats Assigned in " << coachType << " of Train " << trainNum << " Departing at " << departureTime << endl;
    }
};
class BusPass : public Pass {
    protected:
    string busCompany;
    string seatNum;
    public:
    BusPass(int ID, string N, double p, string d, string dest, string bus, string sn) : Pass(ID, N, p, d, dest), busCompany(bus), seatNum(sn) {}
    void cancel() override {
        cout << "Bus Pass :" << passID << "\nCancelled  " << seatNum << endl;
    }
};
class EventPass : public Pass {
  protected:
  string performerName;
  string venue;
  string seatType;
  public:
  EventPass(int ID, string N, double p, string d, string dest, string artist, string venue, string st) : Pass(ID, N, p, d, dest), performerName(artist), venue(venue), seatType(st) {}
  void displayPassInfo() override {
    Pass::displayPassInfo();
    cout << "Performer Name :" << performerName << endl;
    cout << "Venue : " << venue << endl;
    cout << "Seat Type : " << seatType << endl;
  }  

};

int main() {
    AirPass A1(1, "Ali", 3000, "12-5-25", "Lahore", "Flyjinnah", "A-312", "Economy");
    RailPass R1(2, "Ahmed", 213, "25-7-25", "Berlin", "A-32", "Metro", "10:00 AM");
    BusPass B1(3, "Rameez", 1500, "22-9-25", "Barcelona", "TeamBus", "A-34");
    EventPass E1(4, "Abdy", 2123, "12-08-25", "Paris", "Jennie", "Eiffel Tower", "Vip");
     cout << "\nAir Pass:\n";
    A1.displayPassInfo();
    
    cout << "\nRail Pass:\n";
    R1.book();
    R1.displayPassInfo();
    
    cout << "\nBus Pass:\n";
    B1.cancel();
    B1.displayPassInfo();
    
    cout << "\nEvent Pass:\n";
    E1.displayPassInfo();
}