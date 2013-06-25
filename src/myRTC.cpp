#include "../include/myRTC.h"


myRTC::myRTC( wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size,
        long style, const wxValidator& validator, const wxString& name)
		:wxRichTextCtrl(parent,id,value,pos,size,style,validator,name)
{
}


myRTC::~myRTC(void)
{
}

void myRTC::AppendRTC(wxRichTextCtrl* rtc)
{
	wxRichTextBuffer& buffer = this->GetBuffer();

	//buffer.InsertNewlineWithUndo(chatRTC->GetLastPosition(),sendRTC,wxRICHTEXT_INSERT_INTERACTIVE);
	wxRichTextObjectList& objectList = buffer.GetChildren();
	wxRichTextObjectList& __objectList = rtc->GetBuffer().GetChildren();

	wxRichTextObjectList::compatibility_iterator node = __objectList.GetFirst();

	while(node)
	{
	    wxRichTextObject* child = node->GetData();

        wxRichTextObject* newChild = child->Clone();

        newChild->SetParent(&buffer);
		objectList.Append(newChild);
		node = node->GetNext();

	}

    this->GetBuffer().Invalidate();
    #if wxRICHTEXT_BUFFERED_PAINTING
	this->RecreateBuffer();
	#endif
    this->Refresh();
	this->Update();//make the Last Position right
	buffer.UpdateRanges();//不执行这一句的话，chatRTC的文本范围不正确
	wxTextPos pos = this->GetLastPosition();
	wxTextPos chatPos = rtc->GetLastPosition();
	this->ShowPosition(chatPos + pos);
}
