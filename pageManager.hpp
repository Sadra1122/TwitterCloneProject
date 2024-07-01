#ifndef PAGES_HPP
#define PAGES_HPP

#include "CubbyMenu/CubbyMenu.hpp"
#include <functional>
#include <string>
#include <vector>

using namespace CubbyMenu;
using namespace std;

enum class Page { Home, Login, SignUp, MainPage, Tweets, Settings, CreateTweet, Profile };

static string getUserInput(const std::string& prompt) {
    string input;
    cout << prompt;
    getline(cin >> ws, input);
    return input;
}

class User {
public:
    string name;
    string familyName;
    string username;
    string password;
    User() {};
    User(string name, string familyName, string username, string password) : name(name), familyName(familyName), username(username), password(password) {};
};

using NavigateFunc = std::function<void(Page)>;

Menu createHomePage(NavigateFunc navigate);
Menu createLoginPage(NavigateFunc navigate, User& currentUser);
Menu createSignUpPage(NavigateFunc navigate, User& currentUser);
Menu createMainPage(NavigateFunc navigate, const User& currentUser);
Menu createTweetsPage(NavigateFunc navigate, const User& currentUser);
Menu createSettingsPage(NavigateFunc navigate);
Menu createCreateTweetPage(NavigateFunc navigate, const User& currentUser);
Menu createProfilePage(NavigateFunc navigate, const User& currentUser);

void saveTweet(const string& username, const string& tweet);
vector<pair<string, string>> loadTweets();
vector<pair<string, string>> loadUserTweets(const string& username);

#endif