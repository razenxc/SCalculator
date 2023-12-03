#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	previous = new wxTextCtrl(panel, id_previousbar, "", wxPoint(0, 0), wxSize(200, -1), wxTE_READONLY);
	previous->Disable();

	res = new wxTextCtrl(panel, id_resultbar, "", wxPoint(0, 20), wxSize(200, -1), wxTE_READONLY);
	wxFont font(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	res->SetFont(font);

	wxButton* a = new wxButton(panel, wxID_ANY, "", wxPoint(0, 45), wxSize(50, 50));
	wxButton* b = new wxButton(panel, wxID_ANY, "", wxPoint(50, 45), wxSize(50, 50));
	wxButton* clear = new wxButton(panel, wxID_ANY, "C", wxPoint(100, 45), wxSize(50, 50));
	wxButton* backspace = new wxButton(panel, wxID_ANY, "<", wxPoint(150, 45), wxSize(50, 50));

	wxButton* seven = new wxButton(panel, id_seven, "7", wxPoint(0, 95), wxSize(50, 50));
	wxButton* eight = new wxButton(panel, id_eight, "8", wxPoint(50, 95), wxSize(50, 50));
	wxButton* nine = new wxButton(panel, id_nine, "9", wxPoint(100, 95), wxSize(50, 50));
	wxButton* divide = new wxButton(panel, id_divide, "/", wxPoint(150, 95), wxSize(50, 50));

	wxButton* four = new wxButton(panel, id_four, "4", wxPoint(0, 145), wxSize(50, 50));
	wxButton* five = new wxButton(panel, id_five, "5", wxPoint(50, 145), wxSize(50, 50));
	wxButton* six = new wxButton(panel, id_six, "6", wxPoint(100, 145), wxSize(50, 50));
	wxButton* multiply = new wxButton(panel, id_multiply, "*", wxPoint(150, 145), wxSize(50, 50));

	wxButton* one = new wxButton(panel, id_one, "1", wxPoint(0, 195), wxSize(50, 50));
	wxButton* two = new wxButton(panel, id_two, "2", wxPoint(50, 195), wxSize(50, 50));
	wxButton* three = new wxButton(panel, id_three, "3", wxPoint(100, 195), wxSize(50, 50));
	wxButton* minus = new wxButton(panel, id_minus, "-", wxPoint(150, 195), wxSize(50, 50));

	wxButton* zero = new wxButton(panel, id_zero, "0", wxPoint(0, 245), wxSize(50, 50));
	wxButton* dot = new wxButton(panel, id_dot, ".", wxPoint(50, 245), wxSize(50, 50));
	wxButton* result = new wxButton(panel, id_result, "=", wxPoint(100, 245), wxSize(50, 50));
	result->SetBackgroundColour(wxColor(79, 189, 160));
	wxButton* plus = new wxButton(panel, id_plus, "+", wxPoint(150, 245), wxSize(50, 50));

	panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);
}

void MainFrame::OnButtonClick(wxCommandEvent& event)
{
	int bid = event.GetId();
	wxButton* button = dynamic_cast<wxButton*>(FindWindow(bid));
	if (button)
	{
		wxString label = button->GetLabel();
		if (label == '<' || label == '.' && temp.empty())
		{
			event.Skip();
			return;
		}
		else if (label == 'C')
		{
			previous->Clear();
			res->Clear();
			temp.clear();
			op_count = 0;
			result = 0.0;
		}
		else if (label == '+' || label == '-' || label == '*' || label == '/')
		{
			if (temp.empty())
			{
				event.Skip();
				return;
			}
			else if (op_count == 1)
			{
				if (temp.back() == '+' || temp.back() == '-' || temp.back() == '*' || temp.back() == '/')
				{
					event.Skip();
					return;
				}
				previous->Clear();
				previous->AppendText(temp);
				result = OperateNums();
				res->Clear();
				res->AppendText(wxString::Format(wxT("%f"), result));
				res->AppendText(label);
				temp.clear();
				temp += std::to_string(result) + label;
				op_count++;
			} 
			else
			{
				op_count++;
				res->AppendText(label);
				temp += label;
			}
		}
		else if (label == '=')
		{
			if (temp.empty() 
				|| temp.back() == '+' || temp.back() == '-' || temp.back() == '*' || temp.back() == '/'
				|| temp.front() == '+' || temp.front() == '-' && temp.empty() || temp.front() == '*' || temp.front() == '/')
			{
				event.Skip();
				return;
			}

			previous->Clear();
			previous->AppendText(temp + '=');
			result = OperateNums();
			res->Clear();
			res->AppendText(wxString::Format(wxT("%f"), result));
			temp.clear();
			temp += std::to_string(result);
		}
		else
		{
			res->AppendText(label);
			temp += label;
		}
	}
}

double MainFrame::OperateNums()
{
	char op{};
	std::string first, second;
	for (int a{}; a < temp.length(); a++)
	{
		if (op_count == 0)
			second += temp[a];
		if (temp[a] == '+' || temp[a] == '-' || temp[a] == '*' || temp[a] == '/')
		{
			if (a != 0 && temp[0] == '-' || temp[0] != '-')
			{
				op = temp[a];
				op_count = 0;
			}
		}
		if (op_count == 1)
			first += temp[a];
	}

	switch (op)
	{
	case '+':
		result = std::stod(first) + std::stod(second);
		break;
	case '-':
		result = std::stod(first) - std::stod(second);
		break;
	case '*':
		result = std::stod(first) * std::stod(second);
		break;
	case '/':
		if (second != "0")
			result = std::stod(first) / std::stod(second);
		else
			result = 0;
		break;
	}
	return result;
}
