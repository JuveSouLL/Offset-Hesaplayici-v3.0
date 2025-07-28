//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TComboBox *ComboBox1;
    TEdit *Edit1;
    TButton *Button1;
    TMemo *Memo1;
	TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
	TLabel *Label4;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
    int HesaplaSaldiriHizi(String offsetAdi, int offsetDegeri);
    String IntToHex(int value);
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
