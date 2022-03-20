#include "pch.h"

using namespace System;

#include "MainForm.h"

using namespace System::Windows::Forms;
using namespace MineHati;

[STAThread]
int main() {
	MineHati::Menu menu;
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm::Form1()); 
	return 0;
}