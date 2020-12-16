//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const wchar_t* library = L"test.dll";
//��������� ������� � ��� ������ �� Go
typedef int (*IntFunc)(int a, int b);
typedef struct { const char *p; ptrdiff_t n; } _GoString_;
typedef _GoString_ GoString;
typedef GoString (*StringFunc)();
typedef char * (*StringFunc2)(char * a);
HINSTANCE dllp;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//��������� DLL - ���� ������������� - ������������ exe �����
	dllp = LoadLibrary(library);

	if (dllp)
	{
		ShowMessage("Library loaded!");
		Button2->Enabled = true;
		Button3->Enabled = true;
		Button4->Enabled = true;
		Button1->Enabled = false;
	}
	else
	{
		ShowMessage(GetLastError());
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	IntFunc  myFunc;
	//�������� ����� �������
	myFunc = (IntFunc)GetProcAddress(dllp, "GoSum");
	int a,b;
	//� �������� ��
	int ResulT = myFunc(Edit3->Text.ToInt(),Edit4->Text.ToInt());
	Edit1->Text = String(ResulT);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	StringFunc myFunc;
	//�������� ����� �������
	myFunc = (StringFunc)GetProcAddress(dllp, "HelloFromGo");
	GoString ResulT = myFunc();
	AnsiString gotoansi;
	//� �������� ��
	gotoansi = AnsiString(ResulT.p,ResulT.n);
	Edit1->Text = gotoansi;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	StringFunc2 myFunc;
	//�������� ����� �������
	myFunc = (StringFunc2)GetProcAddress(dllp, "GoAcceptStringParam");

	//������������ wchat_t � char (��� Unicode)
	static char c[200];
	memset(c, 0, sizeof(c));
	WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS, Edit2->Text.c_str(), wcslen(Edit2->Text.c_str()), c, 200, NULL, NULL);

	//� �������� ��
	char * ResulT = myFunc(c);
	AnsiString gotoansi;
	gotoansi = AnsiString(ResulT);
	Edit1->Text = gotoansi;
}
//---------------------------------------------------------------------------
