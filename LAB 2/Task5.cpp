#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the array length: ";
    cin >> size;

    int *numbers = new int[size];

    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> *(numbers + i);
    }

    cout << "Array contents: ";
    for (int i = 0; i < size; i++)
    {
        cout << *(numbers + i) << " ";
    }
    cout << endl;

    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += *(numbers + i);
    }

    cout << "Total sum of elements: " << total << endl;

    delete[] numbers;

    return 0;
}
