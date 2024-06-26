//---------------------------------------------------------------------------

#include <fmx.h>

#include<vector>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#pragma hdrstop

#include "QuizOne.h"
#include "GlobalVariables.h"
#include "Selection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TQuizOneForm *QuizOneForm;
//---------------------------------------------------------------------------
//global variable
userInfo currentUserInfo; //make sure to add to all


	template <class T>
	class Question {
	private:
		// Variable of type T
		T FocusQuestion;
		T CorrectAnswer;

	public:
		 Question(){
		}

		Question(T cQuest, T cAnswer){
			FocusQuestion=cQuest;
			CorrectAnswer=cAnswer;
		}

		T GetFocusQuestion() {
			return FocusQuestion;
		}

		T GetCorrectAnswer() {
			return CorrectAnswer;
		}
	};

	static std::vector<Question <std::string>> LoadQuestions(){

	std::ifstream inputFile("Level 1 Bank.txt");

	 if (!inputFile){
		ShowMessage("Failed to open the file!");
	 }


	std::string sa1;
	std::string sa2;

	static std::vector<Question<std::string>> questions;

	for (int i = 1; i < 28; i++) {
			std::getline(inputFile, sa1);
			std::getline(inputFile, sa2);
			Question q = Question(sa1,sa2);
			questions.push_back(q);
	}

	inputFile.close();

	return questions;
	}

    static int GenerateRandomNumber() {
	int MinRange = 0; // Minimum range value
	int MaxRange = 26; // Maximum range value

	// Generate a random number within the specified range
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(MinRange, MaxRange);
	int iRandomNumber = dist(mt);
	return iRandomNumber;
	}

    static std::vector<Question<std::string>>VectorQuestions;
	static int IndexArray [10];
	//score object
	Score Points = Score(0);
	static int QuestionCounter = 0;
	static Question<std::string> CurrentQuestion;

__fastcall TQuizOneForm::TQuizOneForm(TComponent* Owner)
	: TForm(Owner)
{

	VectorQuestions=LoadQuestions();

	int RandomNumber = GenerateRandomNumber();

	IndexArray[QuestionCounter] = RandomNumber;
	QuestionCounter += 1;
	CurrentQuestion = VectorQuestions[RandomNumber];

	UnicodeString uniQuestion = UnicodeString(CurrentQuestion.GetFocusQuestion().c_str());
	lblQuestion->Text = uniQuestion;
	lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
	lblScore->Text = "Your score is " + IntToStr(Points.getPoints()) + "/100";
	Progress->Value = QuestionCounter;

}
//---------------------------------------------------------------------------

void __fastcall TQuizOneForm::ConfirmButtonClick(TObject *Sender)
{
   static int RandomNumber;
   static bool Found;
   static int I;
   static UnicodeString uniQuestion;


   if (rgpTrue->IsChecked) {
	  if (CurrentQuestion.GetCorrectAnswer() == "True") {
		  ++Points;

		  if (QuestionCounter < 10) {
			 RandomNumber = GenerateRandomNumber();

			 Found = false;
			 for (I = 0; I < 10; I++) {
				 if (IndexArray[I] == RandomNumber) {
					 Found = true;
				 }
			 }

			 if (Found == true) {
				 do{
				   RandomNumber = GenerateRandomNumber();

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

			 uniQuestion = UnicodeString(CurrentQuestion.GetFocusQuestion().c_str());
			 lblQuestion->Text = uniQuestion;
			 lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 Progress->Value = QuestionCounter;
		  }else{
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 rgpTrue->Enabled = false;
			 ConfirmButton->Enabled= false;
			 rgpFalse->Enabled = false;

			 ShowMessage("Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.");


             currentUserInfo.score1 = Points.getPoints();      /////////////////////new
			 changeScore(currentUserInfo);     				   ////////////////////new
		  }

	  }else{
		  if (QuestionCounter < 10) {
			 RandomNumber = GenerateRandomNumber();

			 Found = false;
			 for (I = 0; I < 10; I++) {
				 if (IndexArray[I] == RandomNumber) {
					 Found = true;
				 }
			 }

			 if (Found == true) {
				 do{
				   RandomNumber = GenerateRandomNumber();

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

			 uniQuestion = UnicodeString(CurrentQuestion.GetFocusQuestion().c_str());
			 lblQuestion->Text = uniQuestion;
			 lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 Progress->Value = QuestionCounter;
		  }else{
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 rgpTrue->Enabled = false;
			 ConfirmButton->Enabled= false;
			 rgpFalse->Enabled = false;

			 ShowMessage("Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.");


             currentUserInfo.score1 = Points.getPoints();      /////////////////////new
			 changeScore(currentUserInfo);     				   ////////////////////new
		  }
	  }

	  rgpTrue->IsChecked = false;
   }else if (rgpFalse->IsChecked){
	  if (CurrentQuestion.GetCorrectAnswer() == "False") {
		  ++Points;

		  if (QuestionCounter < 10) {
			 RandomNumber = GenerateRandomNumber();

			 Found = false;
			 for (I = 0; I < 10; I++) {
				 if (IndexArray[I] == RandomNumber) {
					 Found = true;
				 }
			 }

			 if (Found == true) {
				 do{
				   RandomNumber = GenerateRandomNumber();

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

			 uniQuestion = UnicodeString(CurrentQuestion.GetFocusQuestion().c_str());
			 lblQuestion->Text = uniQuestion;
			 lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 Progress->Value = QuestionCounter;
		  }else{
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 rgpTrue->Enabled = false;
			 ConfirmButton->Enabled= false;
			 rgpFalse->Enabled = false;

			 ShowMessage("Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.");


             currentUserInfo.score1 = Points.getPoints();      /////////////////////new
			 changeScore(currentUserInfo);     				   ////////////////////new
		  }

	  }else{
		  if (QuestionCounter < 10) {
			 RandomNumber = GenerateRandomNumber();

			 Found = false;
			 for (I = 0; I < 10; I++) {
				 if (IndexArray[I] == RandomNumber) {
					 Found = true;
				 }
			 }

			 if (Found == true) {
				 do{
				   RandomNumber = GenerateRandomNumber();

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

			 uniQuestion = UnicodeString(CurrentQuestion.GetFocusQuestion().c_str());
			 lblQuestion->Text = uniQuestion;
			 lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 Progress->Value = QuestionCounter;
		  }else{
			 lblScore->Text = "Your score is " +IntToStr(Points.getPoints()) + "/100";
			 rgpTrue->Enabled = false;
			 ConfirmButton->Enabled= false;
			 rgpFalse->Enabled = false;

			 ShowMessage("Congratulations. You have completed phase of the quiz with a score of " + IntToStr(Points.getPoints()) + " out of 100.");


             currentUserInfo.score1 = Points.getPoints();      /////////////////////new
			 changeScore(currentUserInfo);     				   ////////////////////new
		  }
	  }

	  rgpFalse->IsChecked = false;
   }else{
	   ShowMessage("You have not selected an option!");
   }

}
//---------------------------------------------------------------------------

void __fastcall TQuizOneForm::rgpFalseClick(TObject *Sender)
{

PlaySound(TEXT("Buzzer.wav"), NULL, SND_FILENAME);
rgpTrue->IsChecked = false;

}
//---------------------------------------------------------------------------

void __fastcall TQuizOneForm::rgpTrueClick(TObject *Sender)
{

PlaySound(TEXT("Correct.wav"), NULL, SND_FILENAME);
rgpFalse->IsChecked = false;

}
//---------------------------------------------------------------------------

void __fastcall TQuizOneForm::FormCreate(TObject *Sender)
{
    Image2->Bitmap->LoadFromFile("LevelPic.jpg");
}
//---------------------------------------------------------------------------


void __fastcall TQuizOneForm::FormActivate(TObject *Sender)
{
	loadUserData(currentUserInfo);       ////////////////////////////////new
}
//---------------------------------------------------------------------------

void __fastcall TQuizOneForm::FormClose(TObject *Sender, TCloseAction &Action)
{

static std::vector<Question<std::string>>VectorQuestions;
	IndexArray [10];
	//score object
	Points = Score(0);
	QuestionCounter = 0;
	Question<std::string> CurrentQuestion;


	VectorQuestions=LoadQuestions();

	int RandomNumber = GenerateRandomNumber();

	IndexArray[QuestionCounter] = RandomNumber;
	QuestionCounter += 1;
	CurrentQuestion = VectorQuestions[RandomNumber];

	UnicodeString uniQuestion = UnicodeString(CurrentQuestion.GetFocusQuestion().c_str());
	lblQuestion->Text = uniQuestion;
	lblQuestionNumber->Text = "Question " +IntToStr(QuestionCounter) + " of 10";
	lblScore->Text = "Your score is " + IntToStr(Points.getPoints()) + "/100";
	Progress->Value = QuestionCounter;

	rgpTrue->Enabled = true;
	ConfirmButton->Enabled= true;
	rgpFalse->Enabled = true;

	SelectionForm->Visible= true;
}
//---------------------------------------------------------------------------

