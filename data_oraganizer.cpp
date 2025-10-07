#include <iostream>
#include "colors.h"
using namespace std;

int ARR[100] = {6, 3, 4};
int pos = 3;

void addElement()
{
    char ch;
    do
    {

        if (pos == 100)
        {
            cout << Red << " array is full. More numbers cannot be added \n " << Reset;
            return;
        }

        cout << "Enter the number to add in array :";
        int num;
        cin >> num;
        ARR[pos] = num;
        pos++;
        cout << num << Green << " is added successfully in array\n"
             << Reset;

        cout << endl;

        cout << "Do you want to add another number ? (Y/N) ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void displayElement()
{
    cout << endl;

    cout << Blue << "Array " << Reset << " : ";
    for (int i = 0; i <= pos; i++)
    {
        cout << ARR[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void deleteElement()
{

    string again;
    do
    {

        int target;
        cout << "Which element you want to delete : " << endl;
        displayElement();
        cin >> target;

        bool found = false;

        for (int i = 0; i <= pos; i++)
        {

            if (target == ARR[i])
            {
                found = true;
                pos--;
                for (int j = i; j <= pos; j++)
                {
                    ARR[j] = ARR[j + 1];
                }
            }
        }

        if (found)
        {

            cout << Green << " Your desired element is eliminated \n"
                 << Reset;
        }

        if (!found)
        {

            cout << Red << "Your required element is not present in array \n"
                 << Reset;
        }

        cout << "Do you want to choose another number to delete ? (Yes/No) ";

        cin >> again;

    } while (again == "Yes" || again == "yes");
}

void insertionSort()
{

    for (int i = 1; i <= pos; i++)
    {

        int key = ARR[i];
        int j = i - 1;

        while (j >= 0 && ARR[j] > key)
        {
            ARR[j + 1] = ARR[j];
            j--;
        }

        ARR[j + 1] = key;
    }

    displayElement();
}

void searchElement()
{
    insertionSort();

    cout << "Enter the number you want to search : ";
    int target;
    cin >> target;

    bool found;
 
int low = 0;
int high = pos;
int index=-1;
while(low<=high)
{
    int mid = (low + high) / 2;

        if (target == ARR[mid])
        {
             found = true;
             index=mid;
            break;
        }

        if(target<ARR[mid]){
            high=mid-1;

        }else{
            low=mid+1;
        }

    }

    if(found){
        cout<<endl<<target<<Green<<" is present at index "<<index<<Reset<<endl;
    }


    if(!found){
        cout<<endl<<target<<Red<<" is not present "<<Reset <<endl;
    }


}

void menu()
{

    int choice;
    do
    {

        cout << "\n\n====" << Yellow << "DATA ORGANIZER MENU" << Reset << " ====\n";
        cout << "1. Add element \n";
        cout << "2. Display element \n";
        cout << "3. Delete element \n";
        cout << "4. Sort(Insertion Sort) \n";
        cout << "5. Search element \n";
        cout << "6. Exit \n";

        cout << "Select an option : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            addElement();
            break;

        case 2:
            displayElement();
            break;

        case 3:
            deleteElement();
            break;

        case 4:
            insertionSort();
            break;

        case 5:
            searchElement();
            break;

        case 6:
            cout << Yellow << "\n\nExiting .......\n"
                 << Reset;
            break;

        default:
            cout << Red << "\n Invalide value. Try again !\a " << Reset;
        }
    } while (choice != 6);
}

int main()
{

    menu();

    return 0;
}