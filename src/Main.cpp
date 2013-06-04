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

    m_item_list->InsertItem(0,_("first"));
    m_item_list->InsertItem(1,_("second"));



    chatTab.push_back(ChatTabData());
    chatTab.push_back(ChatTabData());

    mainSizer->Add(m_item_list,0, wxEXPAND | wxALL, 10);
    mainSizer->Add(noteBook,0,wxEXPAND | wxALL, 10);


    mainPanel->SetSizer(mainSizer);
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
    ChatTabData tab = chatTab.at(event.GetIndex());

    if(!tab.sel)
    {
        tab.sel = true;
        wxListItem item = event.GetItem();
        wxString str = item.GetText();
        wxPanel* panel = new wxPanel(noteBook,wxID_ANY);
        wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        wxTextCtrl* textctrl = new wxTextCtrl(panel,tab.ID_CHAT_TEXT_CTRL,wxEmptyString,wxDefaultPosition,
        wxSize(window_size.GetWidth(),window_size.GetHeight()*0.55),wxTE_MULTILINE | wxTE_RICH | wxTE_READONLY |wxTE_AUTO_URL);
        wxTextCtrl* sendTextctrl = new wxTextCtrl(panel,tab.ID_CHAT_TEXT_CTRL,wxEmptyString,wxDefaultPosition,
        wxSize(window_size.GetWidth(),window_size.GetHeight()*0.1),wxTE_MULTILINE | wxTE_RICH | wxTE_AUTO_URL);
        topSizer->Add(textctrl,0,wxEXPAND | wxALL,10);
        topSizer->Add(sendTextctrl,0,wxEXPAND | wxALL,10);
        buttonSizer->AddSpacer(noteBook->GetClientSize().GetWidth()*0.5);
        buttonSizer->Add(new wxButton(panel,wxID_CANCEL,_("关闭")),0,wxEXPAND | wxALL,10);
        buttonSizer->Add(new wxButton(panel,tab.ID_SEND_CTRL,_("发送")),0,wxEXPAND | wxALL,10);
        wxGetApp()->mainFrame->Conne
        //topSizer.Add(uttonSizer,0,wxALIGN_CENTER,0);
        topSizer->Add(buttonSizer);
        panel->SetSizer(topSizer);
        noteBook->AddPage(panel,str,false);
        noteBook->ChangeSelection(noteBook->GetPageCount()-1);
    }
}
