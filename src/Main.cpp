#include "../include/Main.h"


bool Main::OnInit()
{
    mainFrame = new MainFrame(_("chat"),wxPoint(50,50),wxSize(700,700));
//   frame->Connect( ID_Quit, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &MainFrame::OnQuit );
    //  frame->Connect( ID_About, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &MainFrame::OnAbout );


    mainFrame->Show(true);
    SetTopWindow(mainFrame);
    return true;
}

IMPLEMENT_APP(Main)

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_MENU(ID_Quit,MainFrame::OnQuit)
    EVT_MENU(ID_About,MainFrame::OnAbout)
    EVT_PAINT(MainFrame::OnPaint)
    EVT_LIST_ITEM_ACTIVATED(ID_LISTCTRL,MainFrame::OnItemSelect)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    :wxFrame(NULL,-1,title,pos,size,wxDEFAULT_FRAME_STYLE | wxFULL_REPAINT_ON_RESIZE),window_size(size)
{
    memset(beOpen,0,sizeof(beOpen));
    wxMenuBar *menuBar = new wxMenuBar;

    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit\tAlt-X") );

    menuBar->Append(menuFile, _("&File") );

    SetMenuBar(menuBar);

    CreateStatusBar(2);

    SetStatusText( _("Welcome to wxWidgets!") );
    mainPanel = new wxPanel(this,wxID_ANY);
    noteBook = new wxNotebook(mainPanel,ID_NOTEBOOK,wxDefaultPosition,wxSize(window_size.GetWidth(),window_size.GetHeight()*0.8));

    mainSizer = new wxBoxSizer(wxHORIZONTAL);
    m_item_list = new wxListCtrl(mainPanel, ID_LISTCTRL, wxPoint(0,0), wxSize(100,window_size.GetHeight()), wxLC_LIST|wxLC_SINGLE_SEL);

    mainSizer->Add(m_item_list,0, wxEXPAND | wxALL, 10);
    mainSizer->Add(noteBook,0,wxEXPAND | wxALL, 10);

    mainPanel->SetSizer(mainSizer);

    ChatListItem item1(noteBook);
    item1.chatData.email = "first";
    item1.chatData.chatText = "fisrt say haha";
    AddChatPerson(0,item1);
    ChatListItem item2(noteBook);
    item2.chatData.email = "second";
    item2.chatData.chatText = "second say oh no";
    AddChatPerson(1,item2);
    //wxListCtrl* listctrl = new wxListCtrl(this,ID_LISTBOX,wxDefaultPosition,wxSize(80,80),strings,wxLB_SINGLE);
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("wxWidgets Hello World example."),
                  _("About Hello World"),
                  wxOK|wxICON_INFORMATION, this );
}

void MainFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(*wxRED_BRUSH);
    wxSize sz = GetClientSize();
    wxCoord w = 100, h = 50;
    int x = wxMax(0, (sz.x)/2);
    int y = wxMax(0, (sz.y)/2);
    wxRect rectToDraw(x, y, w, h);
    if (IsExposed(rectToDraw))
        dc.DrawRectangle(rectToDraw);
}

void MainFrame::OnItemSelect(wxListEvent& event)
{

    ChatListItem* ptr =(ChatListItem*) m_item_list->GetItemData(event.GetIndex());

    if(ptr == NULL)
    {
        m_item_list->DeleteItem(event.GetIndex());
        return;
    }

    if(!ptr->sel)
    {
        ptr->sel = true;
        ptr->CreateTabUI(noteBook->GetPageCount());
        wxString str = event.GetItem().GetText();
        noteBook->AddPage(ptr->panel,str,false);
        noteBook->ChangeSelection(noteBook->GetPageCount()-1);
    }

}

void MainFrame::AddChatPerson(int index,ChatListItem& tab) //tab
{
    wxListItem item;
    ChatListItem* ptr = new ChatListItem(noteBook);
    *ptr = tab;//item的data部分必须保证在DeleteItem之前不会被销毁
    item.SetData(ptr);
    item.SetText(tab.chatData.email);
    item.SetId(index);
    m_item_list->InsertItem(item);
    //m_item_list->InsertItem(index,"abcdef");
}
