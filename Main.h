//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *backgroundImage;
	TRectangle *Rectangle1;
	TLabel *Label1;
	TRectangle *Rectangle2;
	TLabel *Label2;
	TLabel *Label3;
	TRadioButton *rbLogin;
	TRadioButton *rbRegistration;
	TLabel *lblexit;
	TButton *btnexit;
	void __fastcall btnexitClick(TObject *Sender);
	void __fastcall rbLoginChange(TObject *Sender);
	void __fastcall rbRegistrationChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
