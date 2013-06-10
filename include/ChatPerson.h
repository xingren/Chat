#ifndef CHATPERSON_H
#define CHATPERSON_H

#include <wx/string.h>

class ChatPerson
{
public:
    ChatPerson();
    virtual ~ChatPerson();
public:
    wxString email;
    wxString chatText;
private:
};

#endif // CHATPERSON_H
