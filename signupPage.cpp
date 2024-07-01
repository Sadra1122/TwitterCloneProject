#include "pageManager.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace CubbyMenu;

vector<string> findUser(string username);

Menu createSignUpPage(NavigateFunc navigate, User& currentUser) {
    Menu signUpMenu;
    signUpMenu.add_header("Please enter your details to sign up:");

    signUpMenu.add_item("Enter details", [navigate, &currentUser]{ 
        string name = getUserInput("Enter name: ");
        string familyName = getUserInput("Enter family name: ");
        
        string username = getUserInput("Enter username (must be unique): ");
        while (!findUser(username).empty())
            username = getUserInput("Username already taken; enter another username (must be unique): ");
        
        string password = getUserInput("Enter password: ");

        ofstream userFile("userAccounts.txt", ios::app);
        if (userFile.is_open()) {
            userFile << name << "," << familyName << "," << username << "," << password << endl;
            userFile.close();
            cout << "Account created successfully!" << endl;
        } else {
            cout << "Error: Couldn't open userAccounts.txt" << endl;
        }
        
        currentUser = User(name, familyName, username, password);
        navigate(Page::MainPage);
    });

    signUpMenu.add_item("Back to Home Page", [navigate]{ navigate(Page::Home); });
    return signUpMenu;
}