#include "pageManager.hpp"
#include <iostream>

using namespace CubbyMenu;

Menu createCreateTweetPage(NavigateFunc navigate, const User& currentUser) {
    Menu createTweetMenu;
    createTweetMenu.add_header("Create a Tweet");
    createTweetMenu.add_item("Post Tweet", [&currentUser, navigate]{
        string tweet = getUserInput("Enter your tweet: ");
        saveTweet(currentUser.username, tweet);
        cout << "Tweet posted." << endl;
        navigate(Page::MainPage);
    });
    createTweetMenu.add_item("Back to Main Page", [navigate]{ navigate(Page::MainPage); });

    return createTweetMenu;
}