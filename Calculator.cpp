#include "Calculator.h"
#include <Windows.h>


using namespace calculator;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Calculator);
    return 0;
}