#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
bool isDraggingCircleOne = false;
bool isDraggingCircleTwo = false;
int offsetXCircleOne = 0;
int offsetYCircleOne = 0;
int offsetXCircleTwo = 0;
int offsetYCircleTwo = 0;
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm1::FormActivate(TObject *Sender)
{

	int centerX = Image1->Width / 2;
    int centerY = Image1->Height / 2;
    TCanvas *canvas = Image1->Canvas;
    canvas->MoveTo(0, centerY);
    canvas->LineTo(Image1->Width, centerY);
    canvas->MoveTo(centerX, 0);
    canvas->LineTo(centerX, Image1->Height);


	int stepX = 30;
	for (int x = centerX + stepX; x < Image1->Width; x += stepX) {
		canvas->MoveTo(x, centerY - 5);
		canvas->LineTo(x, centerY + 5);
	}
    for (int x = centerX - stepX; x >= 0; x -= stepX) {
        canvas->MoveTo(x, centerY - 5);
        canvas->LineTo(x, centerY + 5);
	}

	int stepY = 30;
	for (int y = centerY + stepY; y < Image1->Height; y += stepY) {
        canvas->MoveTo(centerX - 5, y);
		canvas->LineTo(centerX + 5, y);
	}
	for (int y = centerY - stepY; y >= 0; y -= stepY) {
        canvas->MoveTo(centerX - 5, y);
		canvas->LineTo(centerX + 5, y);
	}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int centerX = Image1->Width / 2;
    int centerY = Image1->Height / 2;

    Image1->Canvas->Brush->Color = clWhite;
    Image1->Canvas->FillRect(Rect(0, 0, Image1->Width, Image1->Height));

    int centerCircleOneX = centerX + StrToInt(Edit1->Text);
	int centerCircleOneY = centerY + StrToInt(Edit2->Text);
    int radiusCircleOne = StrToInt(Edit3->Text);

    int centerCircleTwoX = centerX + StrToInt(Edit4->Text);
    int centerCircleTwoY = centerY + StrToInt(Edit5->Text);
    int radiusCircleTwo = StrToInt(Edit6->Text);

    double distance = sqrt(pow(centerCircleTwoX - centerCircleOneX, 2) + pow(centerCircleTwoY - centerCircleOneY, 2));

	if (radiusCircleOne < 0 || radiusCircleTwo < 0) {
		Label1->Caption = "Radius musi byc wiekszy od 0";
		return;
	}else{
		 Label1->Caption = "";
	}

	if (distance <= (radiusCircleOne + radiusCircleTwo)) {
		Label1->Caption = "Okragi sie przecinaja.";
	}else{
		 Label1->Caption = "";
	}

    TCanvas *canvas = Image1->Canvas;
    canvas->Pen->Color = clBlack;
	canvas->Pen->Style = psSolid;

    canvas->MoveTo(0, centerY);
    canvas->LineTo(Image1->Width, centerY);
    canvas->MoveTo(centerX, 0);
	canvas->LineTo(centerX, Image1->Height);
    int stepX = 30;
	for (int x = centerX + stepX; x < Image1->Width; x += stepX) {
		canvas->MoveTo(x, centerY - 5);
		canvas->LineTo(x, centerY + 5);
	}
    for (int x = centerX - stepX; x >= 0; x -= stepX) {
        canvas->MoveTo(x, centerY - 5);
        canvas->LineTo(x, centerY + 5);
	}

	int stepY = 30;
	for (int y = centerY + stepY; y < Image1->Height; y += stepY) {
        canvas->MoveTo(centerX - 5, y);
		canvas->LineTo(centerX + 5, y);
	}
	for (int y = centerY - stepY; y >= 0; y -= stepY) {
        canvas->MoveTo(centerX - 5, y);
		canvas->LineTo(centerX + 5, y);
	}

	canvas->Ellipse(centerCircleOneX - radiusCircleOne, centerCircleOneY - radiusCircleOne, centerCircleOneX + radiusCircleOne, centerCircleOneY + radiusCircleOne);
    canvas->Ellipse(centerCircleTwoX - radiusCircleTwo, centerCircleTwoY - radiusCircleTwo, centerCircleTwoX + radiusCircleTwo, centerCircleTwoY + radiusCircleTwo);
}
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
      int X, int Y)
{
    int centerX = Image1->Width / 2;
	int centerY = Image1->Height / 2;

    int circleOneX = centerX + StrToInt(Edit1->Text);
    int circleOneY = centerY + StrToInt(Edit2->Text);
    int circleOneRadius = StrToInt(Edit3->Text);

    int circleTwoX = centerX + StrToInt(Edit4->Text);
    int circleTwoY = centerY + StrToInt(Edit5->Text);
    int circleTwoRadius = StrToInt(Edit6->Text);


	if (sqrt(pow(X - circleOneX, 2) + pow(Y - circleOneY, 2)) <= circleOneRadius) {
		isDraggingCircleOne = true;
        offsetXCircleOne = X - circleOneX;
        offsetYCircleOne = Y - circleOneY;
	}

	else if (sqrt(pow(X - circleTwoX, 2) + pow(Y - circleTwoY, 2)) <= circleTwoRadius) {
        isDraggingCircleTwo = true;
        offsetXCircleTwo = X - circleTwoX;
        offsetYCircleTwo = Y - circleTwoY;
    }
}
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    if (isDraggingCircleOne) {
        int centerX = Image1->Width / 2;
        int centerY = Image1->Height / 2;

        Edit1->Text = IntToStr(X - centerX - offsetXCircleOne);
        Edit2->Text = IntToStr(Y - centerY - offsetYCircleOne);

        Button1Click(Sender);
    }
    else if (isDraggingCircleTwo) {
        int centerX = Image1->Width / 2;
        int centerY = Image1->Height / 2;

        Edit4->Text = IntToStr(X - centerX - offsetXCircleTwo);
        Edit5->Text = IntToStr(Y - centerY - offsetYCircleTwo);

        Button1Click(Sender);
    }
}
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
      int X, int Y)
{
	isDraggingCircleOne = false;
	isDraggingCircleTwo = false;
}


//---------------------------------------------------------------------------

