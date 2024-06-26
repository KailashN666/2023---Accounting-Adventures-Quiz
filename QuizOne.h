//---------------------------------------------------------------------------

#ifndef QuizOneH
#define QuizOneH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TQuizOneForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TRectangle *Rectangle2;
	TRadioButton *rgpFalse;
	TRadioButton *rgpTrue;
	TButton *ConfirmButton;
	TLabel *Label1;
	TLabel *lblQuestionNumber;
	TProgressBar *Progress;
	TLabel *lblScore;
	TRectangle *Rectangle1;
	TLabel *lblQuestion;
	TLabel *Label2;
	TImage *Image2;
	TStyleBook *StyleBook1;
	void __fastcall ConfirmButtonClick(TObject *Sender);
	void __fastcall rgpFalseClick(TObject *Sender);
	void __fastcall rgpTrueClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TQuizOneForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQuizOneForm *QuizOneForm;
//---------------------------------------------------------------------------
#endif
