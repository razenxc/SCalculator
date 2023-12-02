#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
	// enums
	enum ids
	{
		id_resultbar,
		id_previousbar,
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
	// funcs
	MainFrame(const wxString& title);
	void OnButtonClick(wxCommandEvent& event);
	double OperateNums();
	// vars
	wxTextCtrl* res;
	wxTextCtrl* previous;
	int op_count{};
	double result{};
	std::string temp;
};

