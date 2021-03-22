#include "SpriteSheet.h"



SpriteSheet::SpriteSheet(const wchar_t* filename, Graphics* graphics) {
	//initialise
	this->graphics = graphics;
	bitmap = NULL;
	HRESULT hr; 

	//Creat WIC Factory
	hr = CoInitialize(NULL);
	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&wicFactory);

	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(
		filename,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&wicDecoder
		);
	
	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	//Conver from wic to D2D1 format
	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	hr = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.0,
		WICBitmapPaletteTypeCustom
	);

	// Use Converter to create an D2D1Bitmap
		graphics->GetRenderTarget()->CreateBitmapFromWicBitmap(
		wicConverter,
		NULL,
		&bitmap
	);

		if (wicFactory) wicFactory->Release();
		if (wicDecoder) wicDecoder->Release();
		if (wicConverter) wicConverter->Release();
		if (wicFrame) wicFrame->Release();

}

SpriteSheet::~SpriteSheet() {
	if (bitmap) bitmap->Release();
}
//Draw Image at 0.0f
void SpriteSheet::Draw(float x, float y) {
	graphics->GetRenderTarget()->DrawBitmap(
		bitmap,
		D2D1::RectF(x,y,bitmap->GetSize().width,bitmap->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f, bitmap->GetSize().width, bitmap->GetSize().height)
	);
}