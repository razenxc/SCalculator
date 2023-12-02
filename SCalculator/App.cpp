#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("C++ GUI");
	mainFrame->SetClientSize(200, 250);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}