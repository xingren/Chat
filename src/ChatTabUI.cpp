#include "ChatTabUI.h"
#include "Main.h"
#include <wx/image.h>


//#include "../capture.xpm"

ChatTabUI::ChatTabUI(wxNotebook* parentUI)
{
    wxImage::AddHandler(new wxPNGHandler);
    wxImage::AddHandler(new wxJPEGHandler);
    this->parentUI = parentUI;
}

void ChatTabUI::CreateTabUI(wxString& chatText,wxObject* mainFrame)
{

    panel = new wxPanel(parentUI);
    closeBtn = new wxButton(panel,wxID_CANCEL,_("关闭"));
    sendBtn = new wxButton(panel,wxID_OK,_("发送"));
    topSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    chatTextctrl = new wxRichTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,
                              wxSize(parentUI->GetClientSize().GetWidth(),parentUI->GetClientSize().GetHeight()*0.55),wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY |wxTE_AUTO_URL);
    chatTextctrl->AppendText(chatText);
    sendchatTextctrl = new wxRichTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,
                                  wxSize(parentUI->GetClientSize().GetWidth(),parentUI->GetClientSize().GetHeight()*0.1),wxTE_MULTILINE | wxTE_RICH | wxTE_AUTO_URL);
    topSizer->Add(chatTextctrl,0,wxEXPAND | wxALL,10);
    topSizer->Add(sendchatTextctrl,0,wxEXPAND | wxALL,10);
    wxGridSizer* toolsSizer = new wxGridSizer(3,3,10);
    wxBitmap icon(_("capture.png"),wxBITMAP_TYPE_PNG);

    wxBitmapButton* captureBtn =new wxBitmapButton(panel,ID_CAPTURE_IMAGE,icon,wxDefaultPosition,wxSize(20,20),wxBU_AUTODRAW);
    toolsSizer->Add(captureBtn,0,wxALIGN_CENTER,0);

    buttonSizer->Add(toolsSizer,0,wxALL,10);
    buttonSizer->Add(closeBtn,0, wxALL,10);
    buttonSizer->Add(sendBtn,0, wxALL,10);
    //topSizer.Add(uttonSizer,0,wxALIGN_CENTER,0);
    ((MainFrame*)mainFrame)->Connect(ID_CAPTURE_IMAGE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnCaptureImageBtnClk);
    ((MainFrame*)mainFrame)->Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnCloseBtnClk);
    ((MainFrame*)mainFrame)->Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnSendBtnClk);
    topSizer->Add(buttonSizer);
    panel->SetSizer(topSizer);
}

void ChatTabUI::AppendChatText(wxString& text)
{
    chatTextctrl->AppendText(text);
}

wxString ChatTabUI::GetSendText()
{
    wxString text = sendchatTextctrl->GetValue();
    sendchatTextctrl->SetValue("");
    return text;
}
void ChatTabUI::AppendImageToSendTextctrl(wxString& path)
{
    wxImage image(path,wxBITMAP_TYPE_PNG);
    if(image.Ok())
    {
        sendchatTextctrl->WriteImage(image);
    }
}
