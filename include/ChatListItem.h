#ifndef ChatListItem_H
#define ChatListItem_H

#include <wx/string.h>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>


#include "../include/ChatPerson.h"
#include "../include/ChatTabUI.h"



class ChatListItem
{
public:
    static long ID;
    int id;
    int SEND_BTN_ID;
    bool sel;//是否已经打开tab
    bool online;//是否在线
    int tabCount;//在noteBook的第几个tab


    ChatTabUI ui; //tabUI
    ChatPerson chatData;//聊天信息
public:
    ChatListItem(wxNotebook *parent);
    virtual ~ChatListItem();
    void AppendChatText(wxString& text);
    void CopyWithoutUI(ChatListItem& item);

};

#endif // ChatListItem_H
