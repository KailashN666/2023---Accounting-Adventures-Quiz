//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <System.SysUtils.hpp>

#pragma hdrstop

#include "Selection.h"
#include "Login.h"
#include "LeaderBoard.h"
#include "GlobalVariables.h"
#include "QuizOne.h"
#include "QuizTwo.h"
#include "QuizThree.h"
#include "ExtraGame.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

TSelectionForm *SelectionForm;
//---------------------------------------------------------------------------
__fastcall TSelectionForm::TSelectionForm(TComponent* Owner)
	: TForm(Owner)
{

}

//---------------------------------------------------------------------------
//Global strut
 userInfo currentUserInfo;

void __fastcall TSelectionForm::FormActivate(TObject *Sender)
{
//	//loads current users data into the structure
//	loadUserData(currentUserInfo);
//
//	lblusername->Text =  currentUserInfo.username;
//	edtname->Text =  currentUserInfo.username;
//	edtsurname->Text = currentUserInfo.surname;
//
//	edtscore1->Text = currentUserInfo.score1;
//	edtscore2->Text = currentUserInfo.score2;
//	edtscore3->Text = currentUserInfo.score3;
}
//---------------------------------------------------------------------------



void __fastcall TSelectionForm::FormCreate(TObject *Sender)
{
//Load TImage component and set it as the background of the form
backgroundImage->Parent = SelectionForm;
backgroundImage->Align = TAlignLayout::Client;
backgroundImage->Bitmap->LoadFromFile("Selection.jpg");
backgroundImage->SendToBack();
}
//---------------------------------------------------------------------------



void __fastcall TSelectionForm::btnLeaderBoardClick(TObject *Sender)
{
    LeaderBoardForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSelectionForm::btnquiz1Click(TObject *Sender)
{
	QuizOneForm->Show();
	SelectionForm->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TSelectionForm::btnquiz2Click(TObject *Sender)
{
	QuizTwoForm->Show();
	SelectionForm->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSelectionForm::btnquiz3Click(TObject *Sender)
{
	QuizThreeForm->Show();
	SelectionForm->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TSelectionForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();  // Terminate the application
}
//---------------------------------------------------------------------------

void __fastcall TSelectionForm::FormShow(TObject *Sender)
{
    //loads current users data into the structure
	loadUserData(currentUserInfo);

	lblusername->Text =  currentUserInfo.username;
	edtname->Text =  currentUserInfo.username;
	edtsurname->Text = currentUserInfo.surname;

	edtscore1->Text = currentUserInfo.score1;
	edtscore2->Text = currentUserInfo.score2;
	edtscore3->Text = currentUserInfo.score3;
}
//---------------------------------------------------------------------------

void __fastcall TSelectionForm::btnextrgameClick(TObject *Sender)
{
	GameForm->Show();
	SelectionForm->Visible = false;
}
//---------------------------------------------------------------------------

