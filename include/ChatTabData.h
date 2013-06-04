#ifndef CHATTABDATA_H
#define CHATTABDATA_H

#include <wx/string.h>

class ChatTabData
{
    public:
        bool sel;
        long ID_CHAT_TEXT_CTRL;
        long ID_SEND_CTRL;
        long ID_SEND_TEXT_CTRL;
    public:
        static long ID;
        ChatTabData();
        virtual ~ChatTabData();
        wxString chatText;
    protected:
    private:


};

#endif // CHATTABDATA_H
