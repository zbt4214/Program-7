#include <iostream>
using namespace std;

struct Contact
{
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
};

int addContacts(Contact contactList[], int count)
{
    int numOfContacts;
    cout << "Enter the number of contacts: ";
    cin >> numOfContacts;
    for(int i = 0; i < numOfContacts; i++)
    {
        cout << "Enter the first name: ";
        cin.ignore();
        getline(cin, contactList[count].firstName);

        cout << "Enter the last name: ";
        getline(cin, contactList[count].lastName);

        cout << "Enter the phone number: ";
        getline(cin, contactList[count].phoneNumber);

        cout << "Enter the email: ";
        getline(cin, contactList[count].email);
        cout << " " << endl;
        count++;
    }

    return count;
}

void printContacts(Contact contactList[], int count)
{
    for(int i = 0; i < count; i++)
    {
        cout << "First name: " << contactList[i].firstName << endl;
        cout << "Last name: " << contactList[i].lastName << endl;
        cout << "Phone Number: " << contactList[i].phoneNumber << endl;
        cout << "Email: " << contactList[i].email << endl;
    }
}

int Search(Contact contactList[], int count)
{
    string userinput; 
    cout << "Please enter a name to lookup: ";
    getline(cin, userinput);

    bool found = false;

    for(int i = 0; i < count; i++)
    {
        cout << "Debug: Checking last name: " << contactList[i].lastName << endl;
        //check each array entry to see if the Name == what the user input
        if(userinput ==  contactList[i].lastName)
        {
            cout << "Contact found:" << endl;
            cout << "First Name: " << contactList[i].firstName << endl;
            cout << "Last Name: " << contactList[i].lastName << endl;
            cout << "Phone Number: " << contactList[i].phoneNumber << endl;
            cout << "Email: " << contactList[i].email << endl;
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Contact not found" << endl;
    }
    return 0;
}

int main()
{
    Contact contactList[100];
    int count = 0;
    int totalContacts = 0;
    int search_final = 0;

    totalContacts = addContacts(contactList, count);
    printContacts(contactList, count);
    search_final = Search(contactList, count);

}