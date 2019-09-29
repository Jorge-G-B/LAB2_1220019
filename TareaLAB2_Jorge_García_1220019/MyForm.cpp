#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TareaLAB2JorgeGarcía1220019::MyForm form;
	Application::Run(%form);
	return 0;
}
