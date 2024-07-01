#include "pageManager.hpp"
#include <iostream>

using namespace CubbyMenu;

Menu createSettingsPage(NavigateFunc navigate) {
    Menu settingsMenu;
    settingsMenu.add_header("Settings");
    settingsMenu.add_item("Log out", [navigate]{ navigate(Page::Home); });
    settingsMenu.add_item("Back to Main Page", [navigate]{ navigate(Page::MainPage); });

    return settingsMenu;
}