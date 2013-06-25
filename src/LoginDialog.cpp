#include "../include/LoginDialog.h"
#include <wx/wx.h>

LoginDialog::LoginDialog(void* net ,wxWindow* parent,
	wxWindowID id,
	const wxString& caption,
	const wxPoint& pos,
	const wxSize& size,
	long style):wxDialog(parent,id,caption,pos,size,style)
{
	this->net = net;
	CreateControlers();
}

void LoginDialog::CreateControlers()
{
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxButton* loginBtn = new wxButton(this,wxID_OK,_("µÇÂ½"));
	wxButton* cancelBtn = new wxButton(this,wxID_CANCEL,_("È¡Ïû"));
	wxTextCtrl* emailText = new wxTextCtrl(this,ID_EMAIL);
	wxTextCtrl* passwordText = new wxTextCtrl(this,ID_PASSWORD,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_PASSWORD);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	
	topSizer->Add(emailText,0,wxFIXED,5);
	topSizer->Add(passwordText,0,wxFIXED,5);
	topSizer->Add(buttonSizer,wxFIXED);
	buttonSizer->AddSpacer(this->GetClientRect().GetWidth()/2);
	buttonSizer->Add(loginBtn,0,wxFIXED,5);
	buttonSizer->Add(cancelBtn,0,wxFIXED,5);
	this->SetSizer(topSizer);
	this->Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LoginDialog::OnLoginBtnClk);
}

void LoginDialog::OnLoginBtnClk(wxCommandEvent& event)
{
	//do login
	EndModal(wxID_OK);
}