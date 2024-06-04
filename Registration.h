//---------------------------------------------------------------------------

#ifndef RegistrationH
#define RegistrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TImage *backgroundImage;
	TRectangle *Rectangle1;
	TLabel *Label1;
	TRectangle *Rectangle2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLine *Line1;
	TEdit *edtname;
	TLine *Line2;
	TEdit *edtsurname;
	TLabel *Label6;
	TLabel *Label7;
	TLine *Line3;
	TEdit *edtnumber;
	TLine *Line4;
	TEdit *edtidnumber;
	TRoundRect *btnsave;
	TLabel *Label8;
	TRectangle *Rectangle3;
	TLabel *Label5;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLine *Line8;
	TEdit *edtcode;
	TLabel *Label9;
	TRoundRect *RoundRect1;
	TLabel *Label13;
	TLabel *lblusername;
	TRoundRect *RoundRect3;
	TLabel *Label14;
	TLabel *lblpassword;
	TLabel *Label16;
	TSaveDialog *SaveDialog1;
	TMemo *memlogind;
	TRoundRect *btnClearText;
	TLabel *Label15;
	TRoundRect *btnClose;
	TLabel *Label17;
	TRoundRect *btnregisteruser;
	TLabel *Label18;
	void __fastcall btnCloseClick(TObject *Sender);
	void __fastcall btnClearTextClick(TObject *Sender);
	void __fastcall btnregisteruserClick(TObject *Sender);
	void __fastcall btnsaveClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegistrationForm *RegistrationForm;
//---------------------------------------------------------------------------
#endif
