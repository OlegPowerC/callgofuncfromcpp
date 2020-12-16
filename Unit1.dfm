object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 148
  ClientWidth = 347
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 76
    Top = 43
    Width = 24
    Height = 21
    Caption = '+'
  end
  object Button1: TButton
    Left = 177
    Top = 14
    Width = 152
    Height = 25
    Caption = 'Load DLL'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 18
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Go Sum 2 + 3'
  end
  object Button2: TButton
    Left = 177
    Top = 45
    Width = 152
    Height = 25
    Caption = 'Summ'
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 177
    Top = 76
    Width = 152
    Height = 25
    Caption = 'Get String from Go'
    Enabled = False
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 177
    Top = 107
    Width = 152
    Height = 25
    Caption = 'Call func with string param'
    Enabled = False
    TabOrder = 4
    OnClick = Button4Click
  end
  object Edit2: TEdit
    Left = 18
    Top = 109
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'Test'
  end
  object Edit3: TEdit
    Left = 18
    Top = 43
    Width = 33
    Height = 21
    NumbersOnly = True
    TabOrder = 6
  end
  object Edit4: TEdit
    Left = 106
    Top = 43
    Width = 33
    Height = 21
    NumbersOnly = True
    TabOrder = 7
  end
end
