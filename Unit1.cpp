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
    // Form baþlýðý ve boyutu
    Form1->Caption = "Offset Hesaplayýcý v3.0";
    Form1->Width = 600;
    Form1->Height = 700;
    // Label'larý ayarla
    Label1->Caption = "Offset Seçin:";
    Label1->Top = 10;
    Label1->Left = 20;
    Label2->Caption = "Deðer Girin (0x1E1C veya decimal):";
    Label2->Top = 40;
    Label2->Left = 20;
    Label3->Caption = "Hesaplanan Offsetler:";
    Label3->Top = 100;
    Label3->Left = 20;
    // ComboBox ayarlarý
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
    // Edit ayarlarý
    Edit1->Top = 40;
    Edit1->Left = 200;
    Edit1->Width = 200;
    Edit1->Text = "0x1E1C";
    // Button ayarlarý
    Button1->Caption = "Hesapla";
    Button1->Top = 70;
    Button1->Left = 200;
    Button1->Width = 80;

    // Memo ayarlarý - EN ÖNEMLÝ KISIM
    Memo1->Top = 120;
    Memo1->Left = 20;
    Memo1->Width = Form1->Width - 60;
    Memo1->Height = Form1->Height - 200;
    Memo1->Anchors = TAnchors() << akLeft << akTop << akRight << akBottom;
    // Memo özellikleri
    Memo1->Clear();
    Memo1->Font->Name = "Consolas";
    Memo1->Font->Size = 9;
    Memo1->ScrollBars = ssBoth;  // Hem yatay hem dikey scroll
    Memo1->WordWrap = false;      // Satýr kaydýrma kapalý (yatay scroll için)
    Memo1->ReadOnly = true;       // Sadece okunur
    // Alternatif: Sadece dikey scroll istiyorsanýz
    // Memo1->ScrollBars = ssVertical;
	// Memo1->WordWrap = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// Input kontrolü
    if (Edit1->Text.IsEmpty()) {
        ShowMessage("Lütfen bir deðer girin!");
        return;
    }
    // Seçilen offset adýný al
    String secilenOffset = ComboBox1->Text;
    // Girilen deðeri al ve dönüþtür
    String girilenDeger = Edit1->Text.Trim();
    int offsetDegeri = 0;
    try {
        // Hex mi decimal mi kontrol et
        if (girilenDeger.SubString(1, 2).UpperCase() == "0X") {
            // Hex deðer
            offsetDegeri = StrToInt("$" + girilenDeger.SubString(3, girilenDeger.Length() - 2));
        }
        else {
            // Decimal deðer
            offsetDegeri = StrToInt(girilenDeger);
        }
    }
    catch (...) {
        ShowMessage("Geçersiz deðer girdiniz!");
        return;
    }
    // Saldýrý hýzýný hesapla
    int saldiriHizi = HesaplaSaldiriHizi(secilenOffset, offsetDegeri);
    // Tüm offsetleri hesapla (formüllere göre)
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
    // Memo'yu temizle ve sonuçlarý yaz
    Memo1->Clear();
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("OFFSET HESAPLAMA SONUÇLARI");
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("Girilen: " + secilenOffset + " = " + IntToHex(offsetDegeri) +
                      " (Decimal: " + IntToStr(offsetDegeri) + ")");
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("FORMÜLLER:");
    Memo1->Lines->Add("wallhack = saldýrý hýzý + 0xCA");
    Memo1->Lines->Add("hareket hýzý = saldýrý hýzý - 0x4");
    Memo1->Lines->Add("silah uzunluðu = saldýrý hýzý - 0x8");
    Memo1->Lines->Add("player x = saldýrý hýzý - 0x36");
    Memo1->Lines->Add("player y = saldýrý hýzý - 0x32");
    Memo1->Lines->Add("player z = saldýrý hýzý - 0x2E");
    Memo1->Lines->Add("vid = saldýrý hýzý + 0xC6");
    Memo1->Lines->Add("one hit = saldýrý hýzý - 0xAA");
    Memo1->Lines->Add("ktype = saldýrý hýzý - 0xA6");
    Memo1->Lines->Add("isdead = saldýrý hýzý - 0x5A");
    Memo1->Lines->Add("weapon type = saldýrý hýzý - 0x16E");
    Memo1->Lines->Add("========================================");
    Memo1->Lines->Add("");
    // Format: Offset_Adý : Hex_Deðer (Decimal: Dec_Deðer)
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
    // Örnek hesaplama göster
    Memo1->Lines->Add("");
    Memo1->Lines->Add("HESAPLAMA DETAYI:");
    if (secilenOffset == "wallhack") {
        Memo1->Lines->Add("Wallhack = " + IntToHex(offsetDegeri));
        Memo1->Lines->Add("Saldýrý Hýzý = " + IntToHex(offsetDegeri) + " - 0xCA = " + IntToHex(saldiriHizi));
    }
    else if (secilenOffset == "saldiri_hizi") {
        Memo1->Lines->Add("Saldýrý Hýzý = " + IntToHex(offsetDegeri) + " (direkt)");
    }
    else if (secilenOffset == "vid") {
        Memo1->Lines->Add("VID = " + IntToHex(offsetDegeri));
        Memo1->Lines->Add("Saldýrý Hýzý = " + IntToHex(offsetDegeri) + " - 0xC6 = " + IntToHex(saldiriHizi));
    }
    else {
        Memo1->Lines->Add(secilenOffset + " = " + IntToHex(offsetDegeri));
        Memo1->Lines->Add("Saldýrý Hýzý hesaplandý = " + IntToHex(saldiriHizi));
    }
}
//---------------------------------------------------------------------------
