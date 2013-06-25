#ifndef LoginDialog_H
#define LoginDialog_H

#include <wx/dialog.h>

class LoginDialog :
	public wxDialog
{
public:
	//LoginDialog(void* net);
	LoginDialog(void* ,wxWindow* parent,
	wxWindowID id = wxID_ANY,
	const wxString& caption = _("µÇÂ½"),
	const wxPoint& pos = wxDefaultPosition,
	const wxSize& size = wxDefaultSize,
	long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU);

	//~LoginDialog(void);

	void CreateControlers();
	void OnLoginBtnClk(wxCommandEvent& event);

public:
	wxString email,password;
	void* net;
};

enum
{
	ID_EMAIL = wxID_HIGHEST + 1,
	ID_PASSWORD
};

#endif
