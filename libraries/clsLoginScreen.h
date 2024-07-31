#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLogInRegister.h"
#include "clsDate.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

    // MY WAY
    //static void loginRegister() {

    //    clsLogInRegister loginData = clsLogInRegister(clsDate::getSystemDateTimeString(), currentUser.getUserName(), currentUser.getPassword(),
    //        currentUser.getPermissions()
    //    );
    //   loginData.sava();
    //}

    static bool loging() {
        bool isFaildLogin = false;
        short faildLoginCounter = 3;
        string userName, password;
        do {
            if (isFaildLogin) {
                cout << "\n\ninvalid usercode and password\n";
                cout << "you have " << --faildLoginCounter << " trail (s) to login \n\n";
            }
            if (faildLoginCounter == 0) {
                cout << "\n\nyou are locked after 3 time trails\n\n";
                return false;
            }

            cout <<  "enter the user name ? ";
            userName = clsInputValidate::ReadString();

            cout << "enter the password ? ";
            password = clsInputValidate::ReadString();

            currentUser = clsUser::find(userName,password);


            isFaildLogin = currentUser.isEmpty();


        } while (isFaildLogin);

        //loginRegister();
        // teacher way

        currentUser.loginRgister();

        clsMainScreen::showMainMenu();

        return true;
        
    }

public:
    static bool showLogingScreen() {
        system("cls");
        drawScreenHeader("Login Screen");
        return loging();
    }
};

