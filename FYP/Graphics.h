#pragma once
#include <Windows.h>
#include <d2d1.h>
class Graphics {
	// A factory is used to creat many graphics reasaurces
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* rendertarget;
public:
	Graphics();
	~Graphics();

	bool Init(HWND windowhandle);

	// we begin drawing
	void BeginDraw() {
		rendertarget->BeginDraw();
	}
	// then tell the program we have finished drawing ( updates the draw ) 
	void EndDraw() {
		rendertarget->EndDraw();
	}
};

