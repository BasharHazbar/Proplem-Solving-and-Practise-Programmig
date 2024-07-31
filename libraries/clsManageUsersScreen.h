#pragma once
#include <iostream>
#include  "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
    enum choseMenusManageUserOptions{
        showUsers = 1, addUser = 2, deleteUser = 3, updateUser = 4, findUser = 5, mainMenu= 6
    };

    static void clearSystem() {
        system("cls");
    }

    static void goBackToManageUsersMenu() {
        cout << "\n\n\nPress Any key to go back to Manager Users menus....";
        system("pause>0");
        showManageUsersMenu();
    }

    static short readMainMenuOptions() {
        cout << "\t\t\t\t\tchoose what do you want to do ? [1 - 6] ? ";
        return clsInputValidate::ReadIntNumberBetween(1, 6, "enter number between 1 - 6 ? ");
    }

    static void showAllUsersScreen() {
        clearSystem();
        clsUsersListScreen::showUserList();
    }

    static void showAddUserScreen() {
        clearSystem();
        clsAddNewUserScreen::addNewUser();
    }

    static void showDeleteUserScreen() {
        clearSystem();
        clsDeleteUserScreen::deleteUser();
    }

    static void showUpdateUsersScreen() {
        clearSystem();
        clsUpdateUserScreen::UpdateUser();
    }

    static void showFindUserScreen() {
        clearSystem();
        clsFindUserScreen::findUser();
    }

    static void showExitOpration() {
        clearSystem();
    }

    static void performManageUsersMenuOption(choseMenusManageUserOptions menusManageUserOptions) {
        switch (menusManageUserOptions)
        {
        case clsManageUsersScreen::showUsers:
            showAllUsersScreen();
            goBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::addUser:
            showAddUserScreen();
            goBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::deleteUser:
            showDeleteUserScreen();
            goBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::updateUser:
            showUpdateUsersScreen();
            goBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::findUser:
            showFindUserScreen();
            goBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::mainMenu:
            showExitOpration();
            break;
        default:
            break;
        }
    }


public:
    static void showManageUsersMenu() {


        if (!checkAccessRight(clsUser::enPermissions::pManageUser)) {
            return;
        }

        clearSystem();
        drawScreenHeader("Manage Users Menu");
      
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t\tMenu Manage Users Screeen\n";
        cout << "\t\t\t\t\t===============================================\n";
        cout << "\t\t\t\t\t\t[1] Show Users List.\n";
        cout << "\t\t\t\t\t\t[2] Add New Users.\n";
        cout << "\t\t\t\t\t\t[3] Delete Users.\n";
        cout << "\t\t\t\t\t\t[4] Update Users.\n";
        cout << "\t\t\t\t\t\t[5] Find Users.\n";
        cout << "\t\t\t\t\t\t[6] Main Menu.\n";
        cout << "\t\t\t\t\t===============================================\n";

        performManageUsersMenuOption((choseMenusManageUserOptions)readMainMenuOptions());
    }
};

