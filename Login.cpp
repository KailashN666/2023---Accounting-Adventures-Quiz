//---------------------------------------------------------------------------

#include <fmx.h>

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#pragma hdrstop

#include "Main.h"
#include "Login.h"
#include "Selection.h"
#include "GlobalVariables.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TLoginForm *LoginForm;
//---------------------------------------------------------------------------
//GlobalVariables

//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TLoginForm::RoundRect1Click(TObject *Sender)
{
	//ShowMessage("Check");
	if ((edtusername->Text == "") && (edtpassword->Text == "")) {
		ShowMessage("ERROR! PLEASE ENTER A USERNAME AND THE CORRESPONDING PASSWORD");
		return ;
	} else if (edtusername->Text == "") {
		ShowMessage("ERROR! PLEASE ENTER A USERNAME");
		return ;
	} else if (edtpassword->Text == "") {
		ShowMessage("ERROR! PLEASE ENTER A PASSWORD");
		return ;
	}

	bool flagpwd = false;
	bool flaguser = false;
	fstream file;
	file.open("Registration_info.txt",ios::in);
	if (file.is_open()) {
		std::string sline;

		while((getline(file,sline)) && (flagpwd==false)){
			std::vector<std::string> userdata = parseDelimitorSplitter(sline,':');

			//change according to where user is stored
			const AnsiString username_v = userdata.at(0).c_str();
			const AnsiString username_e = edtusername->Text;

			if (AnsiCompareStr(username_v,username_e)==0) {

				flaguser = true;

				//change according to where password is stored
				const AnsiString password_v = userdata.at(1).c_str();
				const AnsiString password_e = edtpassword->Text;

				const AnsiString code_v = userdata.at(2).c_str();

				if((AnsiCompareStr(password_v,password_e)==0) || (AnsiCompareStr(code_v,password_e)==0 && password_e != "NO CODE") ){
					 ShowMessage("SUCCESSFULL LOGIN");

					 loggedIn = userdata;

					 LoginForm->Visible = false;
					 SelectionForm->Show();
					 //terminates while if it reaches this stage
					 flagpwd = true;
				}  else {

					  int password_chk = MessageDlg("ERROR! PLEASE ENTER THE CORRECT PASSWORD", TMsgDlgType::mtError, TMsgDlgButtons() << TMsgDlgBtn::mbRetry << TMsgDlgBtn::mbCancel, 0);
					  if(password_chk == mrRetry){
							edtpassword->Text = "";
					  }

				}

			}
		}

		if (flaguser == false) {

			int user_chk = MessageDlg("SORRY USER DOES NOT EXIST. PLEASE PROVID VALID LOGIN DETAILS", TMsgDlgType::mtError, TMsgDlgButtons() << TMsgDlgBtn::mbRetry << TMsgDlgBtn::mbCancel, 0);
			if(user_chk == mrRetry){
			   edtusername->Text = "";
			   edtpassword->Text = "";
			}

		}

        file.close();//new

	} else {
			int no_users = MessageDlg("SORRY NO USERS REGISTERED AS OF YET", TMsgDlgType::mtError, TMsgDlgButtons() << TMsgDlgBtn::mbOK, 0);
			   edtusername->Text = "";
			   edtpassword->Text = "";
			}
	}


//---------------------------------------------------------------------------
void __fastcall TLoginForm::FormCreate(TObject *Sender)
{
//Load TImage component and set it as the background of the form
backgroundImage->Parent = LoginForm;
backgroundImage->Align = TAlignLayout::Client;
backgroundImage->Bitmap->LoadFromFile("Login.jpg");
backgroundImage->SendToBack();

//iconImage
iconImage->Parent = Circle;
iconImage->Align = TAlignLayout::Center;
iconImage->Height = 60;
iconImage->Width = 60;
iconImage->Bitmap->LoadFromFile("User.ico");
iconImage->WrapMode = TImageWrapMode::Fit;
}
//---------------------------------------------------------------------------






void __fastcall TLoginForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	MainForm->Visible = true;
	Close();
}
//---------------------------------------------------------------------------

