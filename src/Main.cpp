#include "Main.h"

bool Main::OnInit()
{
    MainFrame *frame = new MainFrame(_("chat"),wxPoint(50,50),wxSize(500,500));
    frame->Connect( ID_Quit, wxEVT_COMMAND_MENU_SELECTED,
                    (wxObjectEventFunction) &MainFrame::OnQuit );
    frame->Connect( ID_About, wxEVT_COMMAND_MENU_SELECTED,
                    (wxObjectEventFunction) &MainFrame::OnAbout );
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}

IMPLEMENT_APP(Main)

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(NULL,-1,title,pos,size)
{
     wxMenuBar *menuBar = new wxMenuBar;

    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit") );

    menuBar->Append(menuFile, _("&File") );

    SetMenuBar(menuBar);

    CreateStatusBar();

    SetStatusText( _("Welcome to wxWidgets!") );
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
