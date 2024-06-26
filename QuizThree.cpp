//---------------------------------------------------------------------------

#include <fmx.h>

#include<vector>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <Windows.h>
#include <mmsystem.h>

#pragma hdrstop

#include "QuizThree.h"
#include "GlobalVariables.h"
#include "Selection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TQuizThreeForm *QuizThreeForm;
//---------------------------------------------------------------------------
//global variable
userInfo currentUserInfo; //make sure to add to all

class QuestionCalculations{
  public:
	UnicodeString FocusQuestion;
	std::string CorrectAnswer;

	QuestionCalculations(){
	}

	QuestionCalculations(UnicodeString cQuest, std::string cAnswer){
		FocusQuestion=cQuest;
		CorrectAnswer=cAnswer;
	}

};

static std::vector<QuestionCalculations> LoadQuestions(){

	std::ifstream inputFile("Level 3 Bank.txt");

	 if (!inputFile){
		ShowMessage("Failed to open the file!");
	 }


	UnicodeString sa1;
	std::string sa2;

	static std::vector<QuestionCalculations> questions;

	for (int i = 1; i < 53; i++) {
			sa1 = IntToStr(i) + ".png";
			std::getline(inputFile, sa2);
			QuestionCalculations q = QuestionCalculations(sa1,sa2);
			questions.push_back(q);
	}

	inputFile.close();

	return questions;
}

template <typename T>
static T GenerateRandomNumber(T MinRange, T MaxRange) {
     // Generate a random number within the specified range
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<T> dist(MinRange, MaxRange);
	T tRandomNumber = dist(mt);
	return tRandomNumber;
}

static std::vector<QuestionCalculations>VectorQuestions;
static int IndexArray [10];
//score object
Score Points = Score(0);
static int QuestionCounter = 0;
static QuestionCalculations CurrentQuestion;

__fastcall TQuizThreeForm::TQuizThreeForm(TComponent* Owner)
	: TForm(Owner)
{

	VectorQuestions=LoadQuestions();

	int RandomNumber = GenerateRandomNumber<int>(0, 51);

	IndexArray[QuestionCounter] = RandomNumber;
	QuestionCounter += 1;
	CurrentQuestion = VectorQuestions[RandomNumber];

	lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
	lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
	Progress->Value = QuestionCounter;


	TBitmap *bitmap = new TBitmap();

	bitmap->LoadFromFile(CurrentQuestion.FocusQuestion);
	image->Bitmap->Assign(bitmap);

	//delete bitmap;

}
//---------------------------------------------------------------------------
void __fastcall TQuizThreeForm::ConfirmButtonClick(TObject *Sender)
{
   static int RandomNumber;
   static bool Found;
   static int I;
   UnicodeString uniAnswer;

   if (edtAnswer->Text != "") {
	  uniAnswer = edtAnswer->Text;

	  if (UnicodeString(CurrentQuestion.CorrectAnswer.c_str()) == uniAnswer) {
		  ++Points;
		  PlaySound(TEXT("Correct.wav"), NULL, SND_FILENAME);

		  if (QuestionCounter < 10) {
			 RandomNumber = GenerateRandomNumber<int>(0, 51);

			 Found = false;
			 for (I = 0; I < 10; I++) {
				 if (IndexArray[I] == RandomNumber) {
					 Found = true;
				 }
			 }

			 if (Found == true) {
				 do{
				   RandomNumber = GenerateRandomNumber<int>(0, 51);

					Found = false;
					for (I = 0; I < 10; I++) {
						if (IndexArray[I] == RandomNumber) {
							Found = true;
						}
					}
				 } while (Found == true);
			 }

			 IndexArray[QuestionCounter] = RandomNumber;
			 QuestionCounter += 1;
			 CurrentQuestion = VectorQuestions[RandomNumber];

			 TBitmap *bitmap = new TBitmap();

			 bitmap->LoadFromFile(CurrentQuestion.FocusQuestion);
			 image->Bitmap->Assign(bitmap);

			 lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 Progress->Value = QuestionCounter;

		  }else{
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 edtAnswer->Enabled = false;
			 ConfirmButton->Enabled= false;

			 ShowMessage("Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.");

			 lblInstructions->Text = "Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.";

			 //delete bitmap;

			 currentUserInfo.score3 = Points.getPoints();      /////////////////////get new points
			 changeScore(currentUserInfo);     				   ////////////////////chnage score
		  }

	  }else{
		  if (QuestionCounter < 10) {
			 RandomNumber = GenerateRandomNumber<int>(0, 51);

			 Found = false;
			 for (I = 0; I < 10; I++) {
				 if (IndexArray[I] == RandomNumber) {
					 Found = true;
				 }
			 }

			 if (Found == true) {
				 do{
				   RandomNumber = GenerateRandomNumber<int>(0, 51);

					Found = false;
					for (I = 0; I < 10; I++) {
						if (IndexArray[I] == RandomNumber) {
							Found = true;
						}
					}
				 } while (Found == true);
			 }

			 IndexArray[QuestionCounter] = RandomNumber;
			 QuestionCounter += 1;
			 CurrentQuestion = VectorQuestions[RandomNumber];

			 TBitmap *bitmap = new TBitmap();

			 bitmap->LoadFromFile(CurrentQuestion.FocusQuestion);
			 image->Bitmap->Assign(bitmap);

			 lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 Progress->Value = QuestionCounter;
		  }else{
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 edtAnswer->Enabled = false;
			 ConfirmButton->Enabled= false;

			 ShowMessage("Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.");

			 lblInstructions->Text = "Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.";

			 //delete bitmap;

             currentUserInfo.score3 = Points.getPoints();      /////////////////////get new points
			 changeScore(currentUserInfo);     				   ////////////////////chnage score
		  }
	  }

	  edtAnswer->Text = "";
   }else {
	   ShowMessage("You have not inputted an answer!");
   }

}
//---------------------------------------------------------------------------
void __fastcall TQuizThreeForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	std::vector<QuestionCalculations>VectorQuestions;
	IndexArray [10];
	//score object
	Points = Score(0);
	QuestionCounter = 0;
	CurrentQuestion;

    VectorQuestions=LoadQuestions();

	int RandomNumber = GenerateRandomNumber<int>(0, 51);

	IndexArray[QuestionCounter] = RandomNumber;
	QuestionCounter += 1;
	CurrentQuestion = VectorQuestions[RandomNumber];

	lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
	lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
	Progress->Value = QuestionCounter;


	TBitmap *bitmap = new TBitmap();

	bitmap->LoadFromFile(CurrentQuestion.FocusQuestion);
	image->Bitmap->Assign(bitmap);

	edtAnswer->Enabled = true;
	ConfirmButton->Enabled= true;

	SelectionForm->Visible= true;
}
//---------------------------------------------------------------------------
void __fastcall TQuizThreeForm::FormCreate(TObject *Sender)
{
    Image1->Bitmap->LoadFromFile("LevelPic.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TQuizThreeForm::FormActivate(TObject *Sender)
{
    loadUserData(currentUserInfo);       ////////////////////////////////load user
}
//---------------------------------------------------------------------------
