object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Auto Offset'
  ClientHeight = 622
  ClientWidth = 365
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 131
    Top = 8
    Width = 63
    Height = 13
    Caption = 'Offset Se'#231'in:'
  end
  object Label2: TLabel
    Left = 25
    Top = 38
    Width = 170
    Height = 13
    Caption = 'De'#287'er Girin (0x1E1C veya decimal):'
  end
  object Label3: TLabel
    Left = 25
    Top = 77
    Width = 106
    Height = 13
    Caption = 'Hesaplanan Offsetler:'
  end
  object Label4: TLabel
    Left = 144
    Top = 601
    Width = 46
    Height = 13
    Caption = 'JuveSouL'
  end
  object Memo1: TMemo
    Left = 8
    Top = 96
    Width = 337
    Height = 496
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 200
    Top = 8
    Width = 145
    Height = 21
    TabOrder = 1
    Text = 'Offset Se'#231
  end
  object Button1: TButton
    Left = 225
    Top = 65
    Width = 75
    Height = 25
    Caption = 'Hesapla'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 201
    Top = 35
    Width = 121
    Height = 21
    TabOrder = 3
  end
end
