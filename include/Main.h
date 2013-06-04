#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/vector.h>
#include "../include/ChatListItem.h"
#include <wx/list.h>
class Main:public wxApp
{
    public:
        virtual bool OnInit();
        wxFrame* mainFrame;
    protected:
    private:
};

class MainFrame:public wxFrame
{
    public:
       wxSize window_size;
    public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        void AddChatPerson(int,ChatListItem&);
    public://事件处理回调函数
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnItemSelect(wxListEvent& event);
        DECLARE_EVENT_TABLE()
    protected:
        wxListCtrl* m_item_list;
        wxNotebook* noteBook;
        wxBoxSizer* mainSizer;
        wxPanel* mainPanel;
        bool beOpen[1000];
//        wxVector<ChatListItem> chatTab;
 //       wxList<ChatListItem> online;
  //      wxList<ChatListItem> offline;
};

enum
{
    ID_Quit=1,
    ID_About,
    ID_LISTCTRL,
    ID_NOTEBOOK,
    ID_CANCLE
};


#endif // MAIN_H
