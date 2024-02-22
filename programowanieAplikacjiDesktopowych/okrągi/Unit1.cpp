//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int centerX = Image1->Width /  2;
    int centerY = Image1->Height /  2;

	Image1->Canvas->Brush->Color = clWhite;
    Image1->Canvas->FillRect(Rect(0,  0, Image1->Width, Image1->Height));

    int centerCircleOneX = centerX+StrToInt(Edit1->Text);
    int centerCircleOneY = centerY+StrToInt(Edit2->Text);
    int radiusCircleOne = StrToInt(Edit3->Text);

    int centerCircleTwoX = centerX+StrToInt(Edit4->Text);
    int centerCircleTwoY = centerY+StrToInt(Edit5->Text);
    int radiusCircleTwo = StrToInt(Edit6->Text);

	double distance = sqrt(pow(centerCircleTwoX - centerCircleOneX,  2) + pow(centerCircleTwoY - centerCircleOneY,  2));

    Label7->Caption="";

  if (radiusCircleOne < 0 || radiusCircleTwo < 0) {
    ShowMessage("Radius obowiazkowo musi byc wiekszy od 0 !");
    return;
  }

	TCanvas *canvas = Image1->Canvas;

    canvas->Pen->Color = clBlack;
    canvas->Pen->Style = psSolid;

    canvas->MoveTo(0, centerY);
    canvas->LineTo(Image1->Width, centerY);
    canvas->MoveTo(centerX,  0);
	canvas->LineTo(centerX, Image1->Height);

	canvas->Brush->Color = clRed;
	canvas->Ellipse(centerCircleOneX - radiusCircleOne, centerCircleOneY - radiusCircleOne, centerCircleOneX + radiusCircleOne, centerCircleOneY + radiusCircleOne);

	canvas->Brush->Color = clWhite;
	canvas->Ellipse(centerCircleTwoX - radiusCircleTwo, centerCircleTwoY - radiusCircleTwo, centerCircleTwoX + radiusCircleTwo, centerCircleTwoY + radiusCircleTwo);

	if (radiusCircleOne == 0 || radiusCircleTwo == 0) return;

	  if (centerCircleOneX == centerCircleTwoX && centerCircleOneY == centerCircleTwoY && radiusCircleOne == radiusCircleTwo) {
	   Label7->Caption = "Okrag 1 ma dokladny ten sam rozmiar i pozycje, co okag 2";
	  } else if (distance <= abs(radiusCircleOne - radiusCircleTwo)) {
	if (radiusCircleOne > radiusCircleTwo) {
		Label7->Caption = "Okrag 2 jest wewnatrz okregu 1";
	} else {
	TCanvas *canvas = Image1->Canvas;

	canvas->Brush->Color = clRed;
	canvas->Ellipse(centerCircleOneX - radiusCircleOne, centerCircleOneY - radiusCircleOne, centerCircleOneX + radiusCircleOne, centerCircleOneY + radiusCircleOne);

	Label7->Caption = "Okrag 1 jest wewnatrz okregu 2";
	}
  } else if (distance < radiusCircleOne + radiusCircleTwo) {
	Label7->Caption = "Okregi sie stykaja";
  }
}
//---------------------------------------------------------------------------
