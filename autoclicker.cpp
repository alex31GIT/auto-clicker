//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
#include <iostream>  //https://docs.microsoft.com/fr-fr/cpp/standard-library/iostream?view=msvc-160                                       //
#include <windows.h> //library for windows fonctionnality (https://docs.microsoft.com/en-us/windows/win32/api/winbase/)                   //                                                                                                                     //    
#include <chrono>    //https://en.cppreference.com/w/cpp/chrono                                                                           //
#include "Header.h"                                                                                                                       //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

using namespace std;
using namespace std::chrono;

int main() {
    //Initialisation of oldtime(register the time on the launch of the programm)
    auto oldtime = system_clock::now();
    
    char keys_start = ' ';
    char keys_end = ' ';
    //Initialisation of the variable click (if click=0(right button), if click=1(left_button))
    int click = 0;


    double cps = 0;

    bool launch = false;

    bool run = true;

    //user inputs
    keys_start = set_start_key();
    cps = set_cps();
    click = set_click();
    keys_end = set_end_key();

    while (run) {

        if (GetAsyncKeyState(keys_start)) {
            launch = true;           
        }

        if (GetAsyncKeyState(keys_end)) {
            launch = false;
        }

        if (launch) {

            auto duration = system_clock::now() - oldtime;
            //convert duration to double
            auto ms = duration_cast<milliseconds>(duration).count();
            //cps = 1s/click; 1000ms = 1s; ms = duration converted in double
            if (ms > 1000/*ms*/ / cps) {
                if (click == 0) {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//pressed right button
                    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//unpressed right button
                }
                else {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//pressed left button
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//unpressed left button
                }
                // reset oldtime to current time
                oldtime = system_clock::now();
            }          
        }           
    }

    return 0;
}
