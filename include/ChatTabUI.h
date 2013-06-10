#ifndef ChatTabUI_H
#define ChatTabUI_H



#include <wx/string.h>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>


class ChatListItem;

class ChatTabUI
{
public:
    wxNotebook* parentUI;
    wxPanel* panel;
    wxBoxSizer* topSizer;
    wxBoxSizer* buttonSizer;
    wxTextCtrl* textctrl;
    wxTextCtrl* sendTextctrl;
    wxButton* closeBtn;
    wxButton* sendBtn;
public:
    ChatTabUI(wxNotebook* parentUI);
    void CreateTabUI(wxString&,wxObject* mainFrame);
    void AppendChatText(wxString&);
    wxString GetSendText();
public:


};



#endif //ChatTabUI_H
