#include "pageManager.hpp"
#include <iostream>

using namespace CubbyMenu;

Menu createTweetsPage(NavigateFunc navigate, const User& currentUser) {
    Menu tweetsMenu;
    tweetsMenu.add_header("Tweets");

    auto tweets = loadTweets();
    for (const auto& tweet : tweets) {
        tweetsMenu.add_item(tweet.first + ": " + tweet.second, []{});
    }

    tweetsMenu.add_item("Back to Main Page", [navigate]{ navigate(Page::MainPage); });

    return tweetsMenu;
}