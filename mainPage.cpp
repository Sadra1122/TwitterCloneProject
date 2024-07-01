#include "pageManager.hpp"
#include <iostream>

using namespace CubbyMenu;

Menu createMainPage(NavigateFunc navigate, const User& currentUser) {
    Menu mainMenu;
    mainMenu.add_header("Welcome, " + currentUser.name + "!");
    mainMenu.add_item("Tweets Timeline", [navigate]{ navigate(Page::Tweets); });
    mainMenu.add_item("Create Tweet", [navigate]{ navigate(Page::CreateTweet); });
    mainMenu.add_item("Settings", [navigate]{ navigate(Page::Settings); });
    mainMenu.add_item("Profile", [navigate]{ navigate(Page::Profile); });
    mainMenu.add_item("Log out", [navigate]{ navigate(Page::Home); });

    return mainMenu;
}