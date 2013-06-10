#include "../include/ChatListItem.h"


long ChatListItem::ID = 8888;

ChatListItem::ChatListItem(wxNotebook* parentUI):ui(parentUI)
{
    //ctor
    sel = false;
    id = ID++;
}
ChatListItem::~ChatListItem()
{
    //dtor
}


void ChatListItem::AppendChatText(wxString text)
{
    chatData.chatText.Append(text);
}

void ChatListItem::CopyWithoutUI(ChatListItem& item)
{
    sel = item.sel;
    online = item.online;
    id = item.id;
    chatData = item.chatData;
}
