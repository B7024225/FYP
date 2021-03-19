#include <Windows.h>
#include "Graphics.h" 

Graphics* graphics;

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

	// ajusting the window size
	RECT rect = { 0,0,800,600 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW,false, WS_EX_OVERLAPPEDWINDOW);

	// we creat the window with parameters and return a handler to the window
	HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,L"MainWindow", L"FYP", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
	// close the window if we dont even make one 
	if (!windowhandle)  return -1 ;

	// we creat a new object of our graphics and then initialise the 2D aspect with a init fucntion
	graphics = new Graphics();
	if (!graphics->Init(windowhandle)) {
		delete graphics;
		return -1;
	}

	// display the window
	ShowWindow(windowhandle, nCmdShow);

	// Main message loop

	float y = 0.0f;
	float ySpeed = 0.0f;

	MSG message;
	message.message = WM_NULL;

	while (message.message != WM_QUIT) {
		if (PeekMessage(&message, NULL,0,0,PM_REMOVE)) {
			DispatchMessage(&message);
		}
		else {
			//UPDATE
			ySpeed += 3.0f;
			y += ySpeed;
			if (y > 600) {
				y = 600;
				ySpeed = -30;
			}

			//RENDER
			graphics->BeginDraw();
			graphics->ClearScreen(0.0f,0.0f,0.5f);
			graphics->DrawCircle(375.0f,y,50.0f,1.0f,1.0f,1.0f,1.0f);

			graphics->EndDraw();

		}
	}


	delete graphics;

	return 0;
}