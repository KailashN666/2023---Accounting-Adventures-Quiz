//---------------------------------------------------------------------------

#ifndef LeaderBoardH
#define LeaderBoardH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Menus.hpp>
//---------------------------------------------------------------------------
class TLeaderBoardForm : public TForm
{
__published:	// IDE-managed Components
	TImage *backgroundImage;
	TRoundRect *RoundRect2;
	TLabel *Label11;
	TCircle *Circle;
	TImage *iconImage;
	TCircle *Circle1;
	TImage *iconImage2;
	TCircle *Circle2;
	TImage *iconImage1;
	TRectangle *Rectangle1;
	TLabel *lblquiz1;
	TLabel *lblscore1;
	TRectangle *Rectangle2;
	TLabel *lblquiz2;
	TLabel *lblscore2;
	TRectangle *Rectangle3;
	TLabel *lblquiz3;
	TLabel *lblscore3;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *Label3;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TLeaderBoardForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLeaderBoardForm *LeaderBoardForm;
//---------------------------------------------------------------------------
#endif
