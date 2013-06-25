#pragma once
#include <wx/richtext/richtextctrl.h>
class myRTC :
	public wxRichTextCtrl
{
public:
	myRTC(wxWindow* parent, wxWindowID id = -1, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxRE_MULTILINE, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);;
	~myRTC(void);
	void AppendRTC(wxRichTextCtrl* rtc);
};

