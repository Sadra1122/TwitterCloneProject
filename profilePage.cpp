#include "pageManager.hpp"
#include <iostream>

using namespace CubbyMenu;

Menu createProfilePage(NavigateFunc navigate, const User& currentUser) {
    Menu profileMenu;
    profileMenu.add_header("Profile: " + currentUser.name + " " + currentUser.familyName);
    profileMenu.add_item("Username: " + currentUser.username, []{});

    auto userTweets = loadUserTweets(currentUser.username);
    for (const auto& tweet : userTweets) {
        profileMenu.add_item("Tweet: " + tweet.second, []{});
    }

    profileMenu.add_item("Back to Main Page", [navigate]{ navigate(Page::MainPage); });

    return profileMenu;
}