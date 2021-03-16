#include <Windows.h>
 
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow) {
	// we creat the window class that wil allow us to display
	WNDCLASSEX windowclass;
	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));// zero out the memory
	// we set up the windowclass details
	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH) COLOR_WINDOW; // background color of the window
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.lpszClassName = L"MainWindow";
	windowclass.style = CS_HREDRAW | CS_VREDRAW; // when the window is re sized horizontaly or verticaly we re-draw the screen

	RegisterClassEx(&windowclass);

	// we creat the window with parameters and return a handler to the window
	HWND windowhandle = CreateWindow(L"MainWindow", L"FYP", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, hInstance, 0);
	// close the window if we dont even make one 
	if (!windowhandle)  return -1 ;
	// display the window
	ShowWindow(windowhandle, nCmdShow);

	//Start the message loop
	MSG message;
	while (GetMessage(&message, NULL, 0, 0)) {
		DispatchMessage(&message);
	}

	return 0;
}