//---------------------------------------------------------------------------

#include <vector>

#ifndef GlobalVariablesH
#define GlobalVariablesH

//extern used to link
extern std::vector<std::string> loggedIn;

//spliting vector
std::vector<std::string> parseDelimitorSplitter(std::string line,char delimitorType);

//counts lines in textfile
int countLinesInFile(const std::string& filename);

//structure
extern struct userInfo{

	UnicodeString username;
	UnicodeString password;
    UnicodeString code;
	UnicodeString name;
	UnicodeString surname;
	UnicodeString contactNumber;
	UnicodeString idNumber;
	int score1;
	int score2;
	int score3;

};

//loads Data
void loadUserData(userInfo& currentUserInfo);

//updates score
void changeScore(userInfo currentUserInfo);

//score class
class Score{
   private:

	int points = 0;

   public:

   Score(int num){
   this->points = num;
   }


	Score& operator++(){
	points = points + 10;
	return *this;
	}

   int getPoints(){
	return points;
   }

};

//---------------------------------------------------------------------------
#endif
