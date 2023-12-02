#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("SCalculator");
	wxIcon icon;
	icon.LoadFile(wxT("resources/scicon.ico"), wxBITMAP_TYPE_ICO);
	mainFrame->SetIcon(icon);
	mainFrame->SetClientSize(200, 300);
	mainFrame->Center();
	mainFrame->SetWindowStyle(mainFrame->GetWindowStyle() & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX));
	mainFrame->Show();
	return true;
}