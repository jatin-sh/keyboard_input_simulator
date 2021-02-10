#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

int main()
{
    Sleep(5000); // wait 5 seconds
    wstring msg = L"Enter text here.";

    vector<INPUT> vec;
    for(auto ch : msg)
    {
        INPUT input = { 0 };
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.wScan = ch;
        vec.push_back(input);

        input.ki.dwFlags |= KEYEVENTF_KEYUP;
        vec.push_back(input);
    }
    //Find a notepad window or another window for send
    // HWND hwnd = FindWindow("Notepad", 0);
    // if (hwnd)
    //     SetForegroundWindow(hwnd);
    // else
    //     std::cout << "no window!\n";

    SendInput(vec.size(), vec.data(), sizeof(INPUT));
    return 0;
}
