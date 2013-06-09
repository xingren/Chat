#include "../include/ChatListItem.h"


long ChatListItem::ID = 8888;

ChatListItem::ChatListItem(wxNotebook* parent)
{
    //ctor
    sel = false;
    this->parent = parent;
    id = ID++;
}
ChatListItem::~ChatListItem()
{
    //dtor
}
BEGIN_EVENT_TABLE(ChatListItem,wxEvtHandler)
	EVT_BUTTON(wxID_CANCEL,ChatListItem::OnCloseBtnClk)
	EVT_BUTTON(wxID_OK,ChatListItem::OnSendBtnClk)
END_EVENT_TABLE()


void ChatListItem::CreateTabUI(int index)
{
    sel = true;
	this->index = index;
    panel = new wxPanel(parent,wxID_ANY);
    closeBtn = new wxButton(panel,wxID_CANCEL,_("关闭"));
	sendBtn = new wxButton(panel,wxID_OK,_("发送"));
	topSizer = new wxBoxSizer(wxVERTICAL);
    buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    textctrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,
    wxSize(parent->GetClientSize().GetWidth(),parent->GetClientSize().GetHeight()*0.55),wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY |wxTE_AUTO_URL);
    textctrl->AppendText(chatData.chatText);

    

    sendTextctrl = new wxTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,
    wxSize(parent->GetClientSize().GetWidth(),parent->GetClientSize().GetHeight()*0.1),wxTE_MULTILINE | wxTE_RICH | wxTE_AUTO_URL);
    topSizer->Add(textctrl,0,wxEXPAND | wxALL,10);
    topSizer->Add(sendTextctrl,0,wxEXPAND | wxALL,10);
    buttonSizer->AddSpacer(parent->GetClientSize().GetWidth()*0.5);
    buttonSizer->Add(closeBtn,0,wxEXPAND | wxALL,10);
    buttonSizer->Add(sendBtn,0,wxEXPAND | wxALL,10);
    //topSizer.Add(uttonSizer,0,wxALIGN_CENTER,0);

 //   panel->Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ChatListItem::OnCloseBtnClk);
  //  panel->Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ChatListItem::OnSendBtnClk);

    topSizer->Add(buttonSizer);
    panel->SetSizer(topSizer);
}

void ChatListItem::OnSendBtnClk(wxCommandEvent& event)
{
    wxMessageBox("send button");
}

void ChatListItem::OnCloseBtnClk(wxCommandEvent& event)
{
    wxMessageBox("delete button");
    assert(parent != NULL);
    parent->DeletePage(index);
	//parent->RemovePage(index);
	sel = false;
}
ChatListItem& ChatListItem::operator=(const ChatListItem& a)
{
    sel = a.sel;
    online = a.online;
    id = a.id;
    return *this;
}
