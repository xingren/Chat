#ifndef ChatListItem_H
#define ChatListItem_H

#include <wx/string.h>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>

#include "../include/ChatPerson.h"
class ChatListItem:public wxEvtHandler
{
    public:
    static long ID;
        int id;
        bool sel;//是否已经打开tab
        bool online;//是否在线
        int index;//在noteBook的第几个tab
        wxNotebook* parent;
		wxPanel* panel;
        wxBoxSizer* topSizer;
        wxBoxSizer* buttonSizer;
        wxTextCtrl* textctrl;
        wxTextCtrl* sendTextctrl;
        wxButton* closeBtn;
        wxButton* sendBtn;
        ChatPerson chatData;
    public:
        ChatListItem(wxNotebook *parent);
        void CreateTabUI(int index);
        virtual ~ChatListItem();
        wxString chatText;
    public:
        void OnSendBtnClk(wxCommandEvent& event);
        void OnCloseBtnClk(wxCommandEvent& event);
        ChatListItem& operator=(const ChatListItem&);
    protected:

    private:
        DECLARE_EVENT_TABLE();


};

#endif // ChatListItem_H
