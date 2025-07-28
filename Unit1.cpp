//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <sstream>
#include <iomanip>
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
String TForm1::IntToHex(int value)
{
	std::stringstream stream;
	stream << "0x" << std::uppercase << std::hex << value;
	return String(stream.str().c_str());
}
int TForm1::HesaplaSaldiriHizi(String offsetAdi, int offsetDegeri)
{
	int saldiriHizi = 0;
    if (offsetAdi == "wallhack") {
        saldiriHizi = offsetDegeri - 0xCA;
    }
    else if (offsetAdi == "saldiri_hizi") {
        saldiriHizi = offsetDegeri;
    }
    else if (offsetAdi == "hareket_hizi") {
        saldiriHizi = offsetDegeri + 0x4;
    }
    else if (offsetAdi == "silah_uzunlugu") {
        saldiriHizi = offsetDegeri + 0x8;
    }
    else if (offsetAdi == "player_x") {
        saldiriHizi = offsetDegeri + 0x36;
    }
    else if (offsetAdi == "player_y") {
        saldiriHizi = offsetDegeri + 0x32;
    }
    else if (offsetAdi == "player_z") {
        saldiriHizi = offsetDegeri + 0x2E;
    }
    else if (offsetAdi == "vid") {
        saldiriHizi = offsetDegeri - 0xC6;
    }
    else if (offsetAdi == "one_hit") {
        saldiriHizi = offsetDegeri + 0xAA;
    }
    else if (offsetAdi == "ktype") {
        saldiriHizi = offsetDegeri + 0xA6;
    }
    else if (offsetAdi == "isdead") {
        saldiriHizi = offsetDegeri + 0x5A;
    }
    else if (offsetAdi == "weapon type") {
        saldiriHizi = offsetDegeri + 0x16E;
    }
    return saldiriHizi;
}



void __fastcall TForm1::FormCreate(TObject *Sender)
{
    // Form ba�l��� ve boyutu
    Form1->Caption = "Offset Hesaplay�c� v3.0";
    Form1->Width = 600;
    Form1->Height = 700;
    // Label'lar� ayarla
    Label1->Caption = "Offset Se�in:";
    Label1->Top = 10;
    Label1->Left = 20;
    Label2->Caption = "De�er Girin (0x1E1C veya decimal):";
    Label2->Top = 40;
    Label2->Left = 20;
    Label3->Caption = "Hesaplanan Offsetler:";
    Label3->Top = 100;
    Label3->Left = 20;
    // ComboBox ayarlar�
    ComboBox1->Top = 10;
    ComboBox1->Left = 200;
    ComboBox1->Width = 200;
    ComboBox1->Items->Clear();
    ComboBox1->Items->Add("wallhack");
    ComboBox1->Items->Add("saldiri_hizi");
    ComboBox1->Items->Add("hareket_hizi");
    ComboBox1->Items->Add("silah_uzunlugu");
    ComboBox1->Items->Add("player_x");
    ComboBox1->Items->Add("player_y");
    ComboBox1->Items->Add("player_z");
    ComboBox1->Items->Add("vid");
    ComboBox1->Items->Add("one_hit");
    ComboBox1->Items->Add("ktype");
    ComboBox1->Items->Add("isdead");
    ComboBox1->Items->Add("weapon type");
    ComboBox1->ItemIndex = 0;
    // Edit ayarlar�
    Edit1->Top = 40;
    Edit1->Left = 200;
    Edit1->Width = 200;
    Edit1->Text = "0x1E1C";
    // Button ayarlar�
    Button1->Caption = "Hesapla";
    Button1->Top = 70;
    Button1->Left = 200;
    Button1->Width = 80;

    // Memo ayarlar� - EN �NEML� KISIM
    Memo1->Top = 120;
    Memo1->Left = 20;
    Memo1->Width = Form1->Width - 60;
    Memo1->Height = Form1->Height - 200;
    Memo1->Anchors = TAnchors() << akLeft << akTop << akRight << akBottom;
    // Memo �zellikleri
    Memo1->Clear();
    Memo1->Font->Name = "Consolas";
    Memo1->Font->Size = 9;
    Memo1->ScrollBars = ssBoth;  // Hem yatay hem dikey scroll
    Memo1->WordWrap = false;      // Sat�r kayd�rma kapal� (yatay scroll i�in)
    Memo1->ReadOnly = true;       // Sadece okunur
    // Alternatif: Sadece dikey scroll istiyorsan�z
    // Memo1->ScrollBars = ssVertical;
	// Memo1->WordWrap = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// Input kontrol�
    if (Edit1->Text.IsEmpty()) {
        ShowMessage("L�tfen bir de�er girin!");
        return;
    }
    // Se�ilen offset ad�n� al
    String secilenOffset = ComboBox1->Text;
    // Girilen de�eri al ve d�n��t�r
    String girilenDeger = Edit1->Text.Trim();
    int offsetDegeri = 0;
    try {
        // Hex mi decimal mi kontrol et
        if (girilenDeger.SubString(1, 2).UpperCase() == "0X") {
            // Hex de�er
            offsetDegeri = StrToInt("$" + girilenDeger.SubString(3, girilenDeger.Length() - 2));
        }
        else {
            // Decimal de�er
            offsetDegeri = StrToInt(girilenDeger);
        }
    }
    catch (...) {
        ShowMessage("Ge�ersiz de�er girdiniz!");
        return;
    }
    // Sald�r� h�z�n� hesapla
    int saldiriHizi = HesaplaSaldiriHizi(secilenOffset, offsetDegeri);
    // T�m offsetleri hesapla (form�llere g�re)
    int wallhack = saldiriHizi + 0xCA;
    int hareketHizi = saldiriHizi - 0x4;
    int silahUzunlugu = saldiriHizi - 0x8;
    int playerX = saldiriHizi - 0x36;
    int playerY = saldiriHizi - 0x32;
    int playerZ = saldiriHizi - 0x2E;
    int vid = saldiriHizi + 0xC6;
    int oneHit = saldiriHizi - 0xAA;
    int ktype = saldiriHizi - 0xA6;
    int isdead = saldiriHizi - 0x5A;
    int weaponType = saldiriHizi - 0x16E;
    // Memo'yu temizle ve sonu�lar� yaz
    Memo1->Clear();
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("OFFSET HESAPLAMA SONU�LARI");
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("Girilen: " + secilenOffset + " = " + IntToHex(offsetDegeri) +
                      " (Decimal: " + IntToStr(offsetDegeri) + ")");
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("FORM�LLER:");
    Memo1->Lines->Add("wallhack = sald�r� h�z� + 0xCA");
    Memo1->Lines->Add("hareket h�z� = sald�r� h�z� - 0x4");
    Memo1->Lines->Add("silah uzunlu�u = sald�r� h�z� - 0x8");
    Memo1->Lines->Add("player x = sald�r� h�z� - 0x36");
    Memo1->Lines->Add("player y = sald�r� h�z� - 0x32");
    Memo1->Lines->Add("player z = sald�r� h�z� - 0x2E");
    Memo1->Lines->Add("vid = sald�r� h�z� + 0xC6");
    Memo1->Lines->Add("one hit = sald�r� h�z� - 0xAA");
    Memo1->Lines->Add("ktype = sald�r� h�z� - 0xA6");
    Memo1->Lines->Add("isdead = sald�r� h�z� - 0x5A");
    Memo1->Lines->Add("weapon type = sald�r� h�z� - 0x16E");
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("");
    // Format: Offset_Ad� : Hex_De�er (Decimal: Dec_De�er)
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"wallhack", IntToHex(wallhack).c_str(), wallhack));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"saldiri_hizi", IntToHex(saldiriHizi).c_str(), saldiriHizi));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"hareket_hizi", IntToHex(hareketHizi).c_str(), hareketHizi));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"silah_uzunlugu", IntToHex(silahUzunlugu).c_str(), silahUzunlugu));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"player_x", IntToHex(playerX).c_str(), playerX));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"player_y", IntToHex(playerY).c_str(), playerY));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"player_z", IntToHex(playerZ).c_str(), playerZ));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"vid", IntToHex(vid).c_str(), vid));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"one_hit", IntToHex(oneHit).c_str(), oneHit));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"ktype", IntToHex(ktype).c_str(), ktype));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"isdead", IntToHex(isdead).c_str(), isdead));
    Memo1->Lines->Add(String().sprintf(L"%-20s : %s (Decimal: %d)",
        L"weapon type", IntToHex(weaponType).c_str(), weaponType));
    Memo1->Lines->Add("");
    Memo1->Lines->Add("========================================");
    // �rnek hesaplama g�ster
    Memo1->Lines->Add("");
    Memo1->Lines->Add("HESAPLAMA DETAYI:");
    if (secilenOffset == "wallhack") {
        Memo1->Lines->Add("Wallhack = " + IntToHex(offsetDegeri));
        Memo1->Lines->Add("Sald�r� H�z� = " + IntToHex(offsetDegeri) + " - 0xCA = " + IntToHex(saldiriHizi));
    }
    else if (secilenOffset == "saldiri_hizi") {
        Memo1->Lines->Add("Sald�r� H�z� = " + IntToHex(offsetDegeri) + " (direkt)");
    }
    else if (secilenOffset == "vid") {
        Memo1->Lines->Add("VID = " + IntToHex(offsetDegeri));
        Memo1->Lines->Add("Sald�r� H�z� = " + IntToHex(offsetDegeri) + " - 0xC6 = " + IntToHex(saldiriHizi));
    }
    else {
        Memo1->Lines->Add(secilenOffset + " = " + IntToHex(offsetDegeri));
        Memo1->Lines->Add("Sald�r� H�z� hesapland� = " + IntToHex(saldiriHizi));
    }
}
//---------------------------------------------------------------------------
