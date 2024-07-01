#include "pageManager.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace CubbyMenu;

vector<string> findUser(string username) {
    ifstream userFile("userAccounts.txt");
    string line;
    
    while (getline(userFile, line)) {
        size_t pos1 = line.find(',');
        if (pos1 != string::npos) {
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            
            string currentUsername = line.substr(pos2 + 1, pos3 - pos2 - 1);
            if (currentUsername == username) {
                return {line.substr(0, pos1),                  // name
                        line.substr(pos1 + 1, pos2 - pos1 - 1), // family name
                        currentUsername,                        // username
                        line.substr(pos3 + 1)};                 // password
            }
        }
    }
    
    return {};  // user not found: return empty
}

Menu createLoginPage(NavigateFunc navigate, User& currentUser) {
    Menu loginMenu;
    loginMenu.add_header("Please enter your details to log in");
    loginMenu.add_item("Enter details", [navigate, &currentUser]{
        bool hasLoggedIn = false;
        string username, password;
        vector<string> userInfo;
        
        while (!hasLoggedIn) {
            username = getUserInput("Enter username: ");
            password = getUserInput("Enter password: ");
            
            userInfo = findUser(username);
            if (!userInfo.empty() && userInfo[3] == password) {
                hasLoggedIn = true;
            } else {
                cout << "Wrong username or password." << endl;
            }
        }
        currentUser = User(userInfo[0], userInfo[1], userInfo[2], userInfo[3]);
        navigate(Page::MainPage);
    });
    loginMenu.add_item("Back to Home Page", [navigate]{ navigate(Page::Home); });
    return loginMenu;
}