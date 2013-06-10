#include "../include/ChatTabUI.h"
#include "../include/Main.h"

ChatTabUI::ChatTabUI(wxNotebook* parentUI)
{

    this->parentUI = parentUI;
}

void ChatTabUI::CreateTabUI(wxString& chatText,wxObject* mainFrame)
{

    panel = new wxPanel(parentUI);
    closeBtn = new wxButton(panel,wxID_CANCEL,_("关闭"));
    sendBtn = new wxButton(panel,wxID_OK,_("发送"));
    topSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    textctrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,
                              wxSize(parentUI->GetClientSize().GetWidth(),parentUI->GetClientSize().GetHeight()*0.55),wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY |wxTE_AUTO_URL);
    textctrl->AppendText(chatText);



    sendTextctrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,
                                  wxSize(parentUI->GetClientSize().GetWidth(),parentUI->GetClientSize().GetHeight()*0.1),wxTE_MULTILINE | wxTE_RICH | wxTE_AUTO_URL);
    topSizer->Add(textctrl,0,wxEXPAND | wxALL,10);
    topSizer->Add(sendTextctrl,0,wxEXPAND | wxALL,10);
    buttonSizer->AddSpacer(parentUI->GetClientSize().GetWidth()*0.5);
    buttonSizer->Add(closeBtn,0,wxEXPAND | wxALL,10);
    buttonSizer->Add(sendBtn,0,wxEXPAND | wxALL,10);
    //topSizer.Add(uttonSizer,0,wxALIGN_CENTER,0);

    ((MainFrame*)mainFrame)->Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnCloseBtnClk);
    ((MainFrame*)mainFrame)->Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnSendBtnClk);
    topSizer->Add(buttonSizer);
    panel->SetSizer(topSizer);
}

void ChatTabUI::AppendChatText(wxString& text)
{
    textctrl->AppendText(text);
}

wxString ChatTabUI::GetSendText()
{
    wxString text = sendTextctrl->GetValue();
    sendTextctrl->SetValue("");
    return text;
}
