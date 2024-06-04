//---------------------------------------------------------------------------

#include <sstream>
#include <fstream>

#pragma hdrstop

#include "GlobalVariables.h"

 //stores current user data
std::vector<std::string> loggedIn;


//function that splits data into a vector using input delimitor ::
std::vector<std::string> parseDelimitorSplitter(std::string line,char delimitorType){
	std::vector<std::string> userdata;
	std::stringstream sline(line);

	while(sline.good()){
		std::string stringbefordelim;
		getline(sline,stringbefordelim,delimitorType);
		userdata.push_back(stringbefordelim);
	}

   return userdata;
}

//counts the number of lines in textfile in order to make sure username is unique
int countLinesInFile(const std::string& filename) {
	fstream file;
	int lineCount = 0;
	file.open(filename,ios::in);
	if (file.is_open()) {
	std::string line;
	while (std::getline(file, line)) {
		lineCount++;
	}

	file.close();
	}

	return lineCount;
}

	//struct that is used to store current userInfo
	userInfo currentUserInfo;

	//loads the current user info into the structure
	void loadUserData(userInfo& currentUserInfo){
	currentUserInfo.username =  loggedIn[0];
	currentUserInfo.password =  loggedIn[1];
	currentUserInfo.code = loggedIn[2];
	currentUserInfo.name =  loggedIn[3];
	currentUserInfo.surname =  loggedIn[4];
	currentUserInfo.contactNumber =  loggedIn[5];
	currentUserInfo.idNumber =  loggedIn[6];

	currentUserInfo.score1 =  StrToInt(loggedIn[7].c_str());
	currentUserInfo.score2 =  StrToInt(loggedIn[8].c_str());
	currentUserInfo.score3 =  StrToInt(loggedIn[9].c_str());
	}

	//update the score for current user by using the struct
	//finds current user in text file, stores other users in a string
	//that new string is used to overide textfile, after updating score current users details are stored as well
    void changeScore(userInfo currentUserInfo){

	const AnsiString username_current = currentUserInfo.username.c_str();

	fstream file;
	file.open("Registration_info.txt",ios::in);
	std::string newfile;
	std::string line;

		if(file.is_open()){

		std::vector<std::string> userdata;

		const AnsiString username_current = currentUserInfo.username.c_str();

			while(getline(file,line)){
			userdata = parseDelimitorSplitter(line,':');
			const AnsiString username_v = userdata[0].c_str();


				if (AnsiCompareStr(username_v,username_current)!=0) {

				newfile += line+"\n";

				}

			}

		file.close();

		}

		fstream file2;
		file2.open("Registration_info.txt",ios::out);
		if(file2.is_open()){

			file2<<newfile;
			file2<<AnsiString(currentUserInfo.username)<<":"<<AnsiString(currentUserInfo.password)<<":"<<AnsiString(currentUserInfo.code)<<":"<<AnsiString(currentUserInfo.name)<<":"<<AnsiString(currentUserInfo.surname)<<":"<<AnsiString(currentUserInfo.contactNumber)<<":"<<AnsiString(currentUserInfo.idNumber)<<":"<<AnsiString(currentUserInfo.score1)<<":"<<AnsiString(currentUserInfo.score2)<<":"<<AnsiString(currentUserInfo.score3)<<"\n";

		file2.close();

		}
	}

//---------------------------------------------------------------------------
#pragma package(smart_init)
