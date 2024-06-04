//---------------------------------------------------------------------------

#include <fmx.h>

#include <fstream>

#include <System.SysUtils.hpp>

#include <vector>

#include<string>

#pragma hdrstop

#include "LeaderBoard.h"
#include "GlobalVariables.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TLeaderBoardForm *LeaderBoardForm;
//---------------------------------------------------------------------------
__fastcall TLeaderBoardForm::TLeaderBoardForm(TComponent* Owner)
	: TForm(Owner)
{
}

std::vector<std::string> get_highest_score(std::string textfile,int quiznum){

		std::string line;
		std::vector<std::string> highscore;
		std::vector<std::string> lowscore;
		int hscore = 0;
		int lscore = 0;

	fstream file;
	file.open(textfile,ios::in);
	if(file.is_open()){


		//inisializes the first line to line
		getline(file,line);
		highscore = parseDelimitorSplitter(line,':');

		//iterates through textfile searching for higest score
		while(getline(file,line)){
		lowscore  = parseDelimitorSplitter(line,':');

		int hscore =  StrToInt(highscore[quiznum].c_str());
		int lscore =  StrToInt(lowscore[quiznum].c_str());


			if (lscore>hscore) {

                //2 vectors
				highscore = lowscore;
			}

		}

		file.close();
	}

	return highscore;
}
//---------------------------------------------------------------------------
void __fastcall TLeaderBoardForm::FormActivate(TObject *Sender)
{
		std::vector<std::string> highscoreq1 = get_highest_score("Registration_info.txt",7);
		std::vector<std::string> highscoreq2 = get_highest_score("Registration_info.txt",8);
		std::vector<std::string> highscoreq3 = get_highest_score("Registration_info.txt",9);

		lblquiz1->Text = highscoreq1[0].c_str();
		lblquiz2->Text = highscoreq2[0].c_str();
		lblquiz3->Text = highscoreq3[0].c_str();

		lblscore1->Text = AnsiString("Score: ") + highscoreq1[7].c_str();
		lblscore2->Text = AnsiString("Score: ") +highscoreq2[8].c_str();
		lblscore3->Text = AnsiString("Score: ") +highscoreq3[9].c_str();
}
//---------------------------------------------------------------------------
void __fastcall TLeaderBoardForm::FormCreate(TObject *Sender)
{
//Load TImage component and set it as the background of the form
backgroundImage->Parent = LeaderBoardForm;
backgroundImage->Align = TAlignLayout::Client;
backgroundImage->Bitmap->LoadFromFile("LeaderBoard.jpg");
backgroundImage->SendToBack();

//iconImage
iconImage->Parent = Circle;
iconImage->Align = TAlignLayout::Center;
iconImage->Height = 60;
iconImage->Width = 60;
iconImage->Bitmap->LoadFromFile("Trophy.ico");
iconImage->WrapMode = TImageWrapMode::Fit;

//iconImage
iconImage1->Parent = Circle1;
iconImage1->Align = TAlignLayout::Center;
iconImage1->Height = 60;
iconImage1->Width = 60;
iconImage1->Bitmap->LoadFromFile("Trophy2.ico");
iconImage1->WrapMode = TImageWrapMode::Fit;
//iconImage1->BringFoward();

//iconImage
iconImage2->Parent = Circle2;
iconImage2->Align = TAlignLayout::Center;
iconImage2->Height = 60;
iconImage2->Width = 60;
iconImage2->Bitmap->LoadFromFile("Trophy3.ico");
iconImage2->WrapMode = TImageWrapMode::Fit;
//iconImage1->BringFoward();
}
//---------------------------------------------------------------------------

