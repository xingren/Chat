#include "../include/ChatTabData.h"


long ChatTabData::ID = 8888;

ChatTabData::ChatTabData()
{
    //ctor
    ID_CHAT_TEXT_CTRL = ID++;
    ID_SEND_TEXT_CTRL = ID++;
    ID_SEND_CTRL = ID++;

    sel = false;
}
ChatTabData::~ChatTabData()
{
    //dtor
}
