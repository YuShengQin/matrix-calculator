#include "WindowsForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WindowsFormsApplication_cpp::WindowsForm windowsForm;
	Application::Run(%windowsForm);
}
