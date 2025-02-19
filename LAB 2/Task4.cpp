#include <iostream>
#include <string>
using namespace std;

int main()
{
    int strCount;
    cout << "Enter the number of strings: ";
    cin >> strCount;
    string *stringArray = new string[strCount];
    
    for (int i = 0; i < strCount; i++)
    {
        cout << "Enter string: ";
        cin >> stringArray[i];
    }
    
    cout << "Your entered strings: ";
    for (int i = 0; i < strCount; i++)
    {
        cout << stringArray[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < strCount - 1; i++)
    {
        for (int j = 0; j < strCount - i - 1; j++)
        {
            if (stringArray[j] > stringArray[j + 1])
            {
                swap(stringArray[j], stringArray[j + 1]);
            }
        }
    }
    
    cout << "Alphabetically ordered strings: " << endl;
    for (int i = 0; i < strCount; i++)
    {
        cout << stringArray[i] << endl;
    }
    
    delete[] stringArray;
}
