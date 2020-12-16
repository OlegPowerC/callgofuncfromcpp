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
//Прототипы функций и тип данных их Go
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
	//Загружаем DLL - путь относительный - относительно exe файла
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
	//Получаем адрес функции
	myFunc = (IntFunc)GetProcAddress(dllp, "GoSum");
	int a,b;
	//И вызываем ее
	int ResulT = myFunc(Edit3->Text.ToInt(),Edit4->Text.ToInt());
	Edit1->Text = String(ResulT);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	StringFunc myFunc;
	//Получаем адрес функции
	myFunc = (StringFunc)GetProcAddress(dllp, "HelloFromGo");
	GoString ResulT = myFunc();
	AnsiString gotoansi;
	//И вызываем ее
	gotoansi = AnsiString(ResulT.p,ResulT.n);
	Edit1->Text = gotoansi;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	StringFunc2 myFunc;
	//Получаем адрес функции
	myFunc = (StringFunc2)GetProcAddress(dllp, "GoAcceptStringParam");

	//Конвертируем wchat_t в char (это Unicode)
	static char c[200];
	memset(c, 0, sizeof(c));
	WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS, Edit2->Text.c_str(), wcslen(Edit2->Text.c_str()), c, 200, NULL, NULL);

	//И вызываем ее
	char * ResulT = myFunc(c);
	AnsiString gotoansi;
	gotoansi = AnsiString(ResulT);
	Edit1->Text = gotoansi;
}
//---------------------------------------------------------------------------
