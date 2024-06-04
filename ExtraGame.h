//---------------------------------------------------------------------------

#ifndef ExtraGameH
#define ExtraGameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TGameForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btnStillBored;
	TEdit *edtLetter;
	TImage *image;
	TLabel *Label1;
	TLabel *Label2;
	TRectangle *Rectangle1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TRectangle *Rectangle2;
	TLabel *lblAttempts;
	TLabel *lblGuessed;
	TProgressBar *Progress;
	TButton *btnSubmit;
	TStyleBook *StyleBook1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnSubmitClick(TObject *Sender);
	void __fastcall btnStillBoredClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TGameForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGameForm *GameForm;
//---------------------------------------------------------------------------
#endif
