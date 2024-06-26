//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
#include "Login.h"
#include "Registration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnexitClick(TObject *Sender)
{
	lblexit->TextSettings->FontColor = TAlphaColorRec::Dodgerblue;
	Application->Terminate();  // Terminate the application
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::rbLoginChange(TObject *Sender)
{
	LoginForm->Show();
	rbLogin->IsChecked=false;
	MainForm->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::rbRegistrationChange(TObject *Sender)
{
    RegistrationForm->Show();
	rbRegistration->IsChecked=false;
	MainForm->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
//Load TImage component and set it as the background of the form
backgroundImage->Parent = MainForm;
backgroundImage->Align = TAlignLayout::Client;
backgroundImage->Bitmap->LoadFromFile("Main.jpg");
backgroundImage->SendToBack();
}
//---------------------------------------------------------------------------

