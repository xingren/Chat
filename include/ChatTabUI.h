#ifndef ChatTabUI_H
#define ChatTabUI_H



#include <wx/string.h>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include "../include/myRTC.h"

class ChatListItem;

class ChatTabUI
{
public:
    wxNotebook* parentUI;
    wxPanel* panel;
    wxBoxSizer* topSizer;
    wxBoxSizer* buttonSizer;
    myRTC* chatRTC;
    myRTC* sendRTC;
    wxButton* closeBtn;
    wxButton* sendBtn;
public:
    ChatTabUI(wxNotebook* parentUI);
    void CreateTabUI(wxString&,wxObject* mainFrame);
    void AppendChatText(wxString&);
    wxString GetSendText();
    void AppendImageToSendTextctrl(wxString& path);
public:


};



#endif //ChatTabUI_H
