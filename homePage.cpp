#include "pageManager.hpp"
#include <iostream>

using namespace CubbyMenu;

Menu createHomePage(NavigateFunc navigate) {
    Menu homeMenu;
    homeMenu.add_header("Welcome to Sadra's Twitter clone; please login or sign up.");
    homeMenu.add_item("Login", [navigate]{ navigate(Page::Login); });
    homeMenu.add_item("Sign up", [navigate]{ navigate(Page::SignUp); });
    homeMenu.add_item("Exit", []{ std::exit(0); });

    return homeMenu;
}