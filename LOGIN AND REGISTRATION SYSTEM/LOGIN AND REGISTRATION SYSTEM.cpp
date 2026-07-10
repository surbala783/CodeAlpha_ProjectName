#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Input Validation
    if (username == "" || password == "")
    {
        cout << "Error! Username and Password cannot be empty.\n";
        return;
    }

    string filename = username + ".txt";

    // Check if username already exists
    ifstream checkFile(filename.c_str());

    if (checkFile.is_open())
    {
        cout << "Error! Username already exists.\n";
        checkFile.close();
        return;
    }

    checkFile.close();

    // Create new user file
    ofstream outFile(filename.c_str());

    outFile << username << endl;
    outFile << password << endl;

    outFile.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string storedUser, storedPass;

    cout << "\n===== USER LOGIN =====\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    string filename = username + ".txt";

    ifstream inFile(filename.c_str());

    if (!inFile.is_open())
    {
        cout << "Error! User not found.\n";
        return;
    }

    inFile >> storedUser;
    inFile >> storedPass;

    inFile.close();

    if (username == storedUser && password == storedPass)
    {
        cout << "Login Successful! Welcome " << username << ".\n";
    }
    else
    {
        cout << "Invalid Password!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n=============================\n";
        cout << " LOGIN & REGISTRATION SYSTEM\n";
        cout << "=============================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
