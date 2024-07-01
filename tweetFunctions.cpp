#include "pageManager.hpp"
#include <fstream>
#include <algorithm>

void saveTweet(const string& username, const string& tweet) {
    ofstream tweetFile("tweets.txt", ios::app);
    tweetFile << username << "," << tweet << endl;
}

vector<pair<string, string>> loadTweets() {
    vector<pair<string, string>> tweets;
    ifstream tweetFile("tweets.txt");
    string line;

    while (getline(tweetFile, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            string username = line.substr(0, pos);
            string tweet = line.substr(pos + 1);
            tweets.emplace_back(username, tweet);
        }
    }

    reverse(tweets.begin(), tweets.end());
    return tweets;
}

vector<pair<string, string>> loadUserTweets(const string& username) {
    vector<pair<string, string>> userTweets;
    auto allTweets = loadTweets();

    for (const auto& tweet : allTweets) {
        if (tweet.first == username) {
            userTweets.push_back(tweet);
        }
    }

    return userTweets;
}