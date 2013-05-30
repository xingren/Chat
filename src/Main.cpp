#include "Main.h"

bool Main::OnInit()
{
    MainFrame *frame = new MainFrame(_("chat"),wxPoint(50,50),wxSize(500,500));
 //   frame->Connect( ID_Quit, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &MainFrame::OnQuit );
  //  frame->Connect( ID_About, wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &MainFrame::OnAbout );



    frame->Show(true);
    SetTopWindow(frame);
    return true;
}

IMPLEMENT_APP(Main)

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_MENU(ID_Quit,MainFrame::OnQuit)
    EVT_MENU(ID_About,MainFrame::OnAbout)
    EVT_PAINT(MainFrame::OnPaint)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(NULL,-1,title,pos,size,wxDEFAULT_FRAME_STYLE | wxFULL_REPAINT_ON_RESIZE)
{
     wxMenuBar *menuBar = new wxMenuBar;

    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit\tAlt-X") );

    menuBar->Append(menuFile, _("&File") );

    SetMenuBar(menuBar);

    CreateStatusBar(2);

    SetStatusText( _("Welcome to wxWidgets!") );
     wxArrayString strings;
   strings.Add(wxT("First string"));
   strings.Add(wxT("Second string"));
    strings.Add(wxT("Third string"));
    strings.Add(wxT("Fourth string"));
    strings.Add(wxT("Fifth string"));
    strings.Add(wxT("Sixth string"));
    wxListBox* listBox = new wxListBox(this,ID_LISTBOX,wxDefaultPosition,wxSize(80,80),strings,wxLB_SINGLE);
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
