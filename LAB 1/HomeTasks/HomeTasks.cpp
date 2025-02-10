#include <iostream>
using namespace std;

// Task 1: Gather AQI Data for 4 Cities Over 7 Days
void inputAQIData(int airQuality[4][7])
{
    for (int city = 0; city < 4; city++)
    {
        cout << "Enter AQI for city " << city + 1 << ":\n";
        for (int day = 0; day < 7; day++)
        {
            cin >> airQuality[city][day];
        }
    }
}

// Task 2: Compute Weekly Average AQI for Each City
void computeWeeklyAverage(int airQuality[4][7])
{
    for (int city = 0; city < 4; city++)
    {
        int total = 0;
        for (int day = 0; day < 7; day++)
        {
            total += airQuality[city][day];
        }
        cout << "City " << city + 1 << " Weekly AQI: " << total / 7 << endl;
    }
}

// Task 3: Determine the City with the Highest AQI
void determineWorstCity(int airQuality[4][7])
{
    int highestAvg = 0, worstCityIndex = 0;
    for (int city = 0; city < 4; city++)
    {
        int total = 0;
        for (int day = 0; day < 7; day++)
        {
            total += airQuality[city][day];
        }
        int average = total / 7;
        if (average > highestAvg)
        {
            highestAvg = average;
            worstCityIndex = city;
        }
    }
    cout << "City " << worstCityIndex + 1 << " has the worst air quality (Highest AQI: " << highestAvg << ")" << endl;
}

// Task 4: Present AQI Data in a Table Format
void showAQIData(int airQuality[4][7])
{
    cout << "City\\Day\t";
    for (int day = 0; day < 7; day++)
    {
        cout << "Day " << day + 1 << "\t";
    }
    cout << endl;

    for (int city = 0; city < 4; city++)
    {
        cout << "City " << city + 1 << "\t";
        for (int day = 0; day < 7; day++)
        {
            cout << airQuality[city][day] << "\t";
        }
        cout << endl;
    }
}

// Task 5: Identify Days Exceeding AQI Threshold
void detectCriticalDays(int airQuality[4][7])
{
    int dangerThreshold = 150;
    for (int city = 0; city < 4; city++)
    {
        cout << "City " << city + 1 << " critical pollution days (AQI > " << dangerThreshold << "):\n";
        for (int day = 0; day < 7; day++)
        {
            if (airQuality[city][day] > dangerThreshold)
            {
                cout << "Day " << day + 1 << ": " << airQuality[city][day] << endl;
            }
        }
    }
}

int main()
{
    int airQuality[4][7];

    inputAQIData(airQuality);
    computeWeeklyAverage(airQuality);
    determineWorstCity(airQuality);
    showAQIData(airQuality);
    detectCriticalDays(airQuality);

    return 0;
}