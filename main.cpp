#include "pageManager.hpp"
#include <iostream>

using namespace std;

int main() {
    Page currentPage = Page::Home;
    User currentUser;

    NavigateFunc navigate = [&currentPage](Page newPage) {
        currentPage = newPage;
    };

    auto homePage = createHomePage(navigate);
    auto loginPage = createLoginPage(navigate, currentUser);
    auto signUpPage = createSignUpPage(navigate, currentUser);

    while (true) {
        switch (currentPage) {
            case Page::Home:
                homePage.print();
                break;
            case Page::Login:
                loginPage.print();
                break;
            case Page::SignUp:
                signUpPage.print();
                break;
            case Page::MainPage:
                createMainPage(navigate, currentUser).print();
                break;
            case Page::Tweets:
                createTweetsPage(navigate, currentUser).print();
                break;
            case Page::Settings:
                createSettingsPage(navigate).print();
                break;
            case Page::CreateTweet:
                createCreateTweetPage(navigate, currentUser).print();
                break;
            case Page::Profile:
                createProfilePage(navigate, currentUser).print();
                break;
        }
        cout << "\n";
    }

    return 0;
}