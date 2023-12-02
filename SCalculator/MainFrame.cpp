#include "MainFrame.h"

enum ids
{
	id_textbar,
	id_result,
	id_one,
	id_two,
	id_three,
	id_four,
	id_five,
	id_six,
	id_seven,
	id_eight,
	id_nine,
	id_zero,
	id_multiply,
	id_divide,
	id_minus,
	id_plus,
	id_dot
};

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxTextCtrl* res = new wxTextCtrl(panel, id_textbar, "", wxPoint(0, 10), wxSize(200, -1), wxTE_READONLY);

	wxButton* seven = new wxButton(panel, id_seven, "7", wxPoint(0, 25), wxSize(50, 50));
	wxButton* eight = new wxButton(panel, id_eight, "8", wxPoint(50, 25), wxSize(50, 50));
	wxButton* nine = new wxButton(panel, id_nine, "9", wxPoint(100, 25), wxSize(50, 50));
	wxButton* divide = new wxButton(panel, id_divide, "/", wxPoint(150, 25), wxSize(50, 50));

	wxButton* four = new wxButton(panel, id_four, "4", wxPoint(0, 75), wxSize(50, 50));
	wxButton* five = new wxButton(panel, id_five, "5", wxPoint(50, 75), wxSize(50, 50));
	wxButton* six = new wxButton(panel, id_six, "6", wxPoint(100, 75), wxSize(50, 50));
	wxButton* multiply = new wxButton(panel, id_multiply, "x", wxPoint(150, 75), wxSize(50, 50));

	wxButton* one = new wxButton(panel, id_one, "1", wxPoint(0, 125), wxSize(50, 50));
	wxButton* two = new wxButton(panel, id_two, "2", wxPoint(50, 125), wxSize(50, 50));
	wxButton* three = new wxButton(panel, id_three, "3", wxPoint(100, 125), wxSize(50, 50));
	wxButton* minus = new wxButton(panel, id_minus, "-", wxPoint(150, 125), wxSize(50, 50));

	wxButton* zero = new wxButton(panel, id_zero, "0", wxPoint(0, 175), wxSize(50, 50));
	wxButton* dot = new wxButton(panel, id_dot, ".", wxPoint(50, 175), wxSize(50, 50));
	wxButton* result = new wxButton(panel, id_result, "=", wxPoint(100, 175), wxSize(50, 50));
	wxButton* plus = new wxButton(panel, id_plus, "+", wxPoint(150, 175), wxSize(50, 50));

	panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick);

	CreateStatusBar();
}

void MainFrame::OnButtonClick(wxCommandEvent& event)
{
	wxLogStatus("1");
}
