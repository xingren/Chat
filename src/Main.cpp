#include "../include/Main.h"

#include <unistd.h>
#include <sys/wait.h>

pid_t wait(__WAIT_STATUS status);

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
    item1.chatData.chatText = "fisrt say haha\n";
    AddChatPerson(0,item1);
    ChatListItem item2(noteBook);
    item2.chatData.email = "second";
    item2.chatData.chatText = "second say oh no\n";
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

    //ChatListItem* ptr =(ChatListItem*) m_item_list->GetItemData(event.GetIndex());
    wxListItem item = event.GetItem();

    if(m_item_list->GetItem(item))
    {

    }
    else
    {

    }
    ChatListItem* ptr = (ChatListItem*)item.GetData();
    if(ptr == NULL)
    {
       // wxMessageBox("ptr == NULL");
        m_item_list->DeleteItem(event.GetIndex());
        return;
    }
    int index = noteBook->GetSelection();
    wxString str = "current select page: ";
    str << index;
    SetStatusText(str);
    if(!ptr->sel)//没有打开tab
    {
        ptr->sel = true;

        ptr->ui.CreateTabUI(ptr->chatData.chatText,this);
        int pageCount = noteBook->GetPageCount();
        ptr->tabCount = pageCount;
		tab_item_map.insert(std::pair<wxPanel*,int>(ptr->ui.panel,item.GetId()));

        wxString str = "page count";
        str << pageCount;
        SetStatusText(str);
        str = event.GetItem().GetText();
        noteBook->AddPage(ptr->ui.panel,str,false);

        noteBook->ChangeSelection(pageCount);

    }
    else//已经打开了tab
    {
        noteBook->SetSelection(ptr->tabCount);
    }

}

void MainFrame::AddChatPerson(int index,ChatListItem& tab) //tab
{
    wxListItem item;
    ChatListItem* ptr = new ChatListItem(noteBook);
    ptr->CopyWithoutUI(tab);//item的data部分必须保证在DeleteItem之前不会被销毁

    //int a = 0;

    item.SetData(ptr);
    item.SetText(tab.chatData.email);
    item.SetId(index);
    item.SetMask(wxLIST_MASK_DATA | wxLIST_MASK_TEXT | wxLIST_MASK_IMAGE | wxLIST_MASK_STATE);
    m_item_list->InsertItem(item);
    //m_item_list->InsertItem(index,"abcdef");
    //m_item_list->SetItem(item);
}


void MainFrame::OnSendBtnClk(wxCommandEvent& event)
{

   // wxMessageBox("send button");

    wxPanel* panel = (wxPanel*)noteBook->GetCurrentPage();
    if(panel == NULL)
        return;
    std::map<wxPanel*,int>::iterator iter = tab_item_map.find(panel);
    if(iter != tab_item_map.end())
    {
        wxListItem item;
        item.SetId(iter->second);
		item.SetMask(wxLIST_MASK_DATA);
		m_item_list->GetItem(item);

        ChatListItem* ptr = (ChatListItem*)item.GetData();

        wxString text = ptr->ui.GetSendText();
        text = "me: " + text + "\n";
        ptr->AppendChatText(text);
		ptr->ui.AppendChatText(text);
        //将消息发送给对方
    }

}

void MainFrame::OnCloseBtnClk(wxCommandEvent& event)
{
 //   wxMessageBox("delete button");
	wxPanel* panel = (wxPanel*)noteBook->GetCurrentPage();
    if(panel == NULL)
        return;
    std::map<wxPanel*,int>::iterator iter = tab_item_map.find(panel);
    if(iter != tab_item_map.end())
    {
		int index = noteBook->GetSelection();
        noteBook->DeletePage(index);
        wxListItem item;

		item.m_itemId = iter->second;
		item.m_mask = wxLIST_MASK_DATA;

		if(m_item_list->GetItem(item))
		{}
		else
		{
			wxMessageBox("error get item in Close");
			return ;
		}

        ChatListItem* ptr = (ChatListItem*)item.GetData();

        ptr->sel = false;
        tab_item_map.erase(iter);
    }

}
void MainFrame::OnCaptureImageBtnClk(wxCommandEvent& event)
{
    wxPanel* panel= (wxPanel*)noteBook->GetCurrentPage();
    if(panel == NULL)
        return;

    std::map<wxPanel*,int>::iterator iter = tab_item_map.find(panel);
    if(iter != tab_item_map.end())
    {
        wxListItem item;
        item.SetId(iter->second);
        item.SetMask(wxLIST_MASK_DATA);

        wxString path="/home/rui/.Client/cap.png";

        if(m_item_list->GetItem(item))
        {
            ChatListItem* ptr = (ChatListItem*) item.GetData();



//#ifdef  __linux__
            pid_t pid = fork();
            if(pid < 0)
            {
                wxMessageBox("创建新进程失败");
                return ;
            }
            if(pid == 0)
            {
               // char *str = path.c_str();
               char str[1000];
               strcpy(str,path.mb_str());
                execlp("import","import",str,(char*)0);
                exit(1);
            }
            int status;
            if(wait(&status) == -1)
            {
                wxMessageBox("等待子进程结束时出错");
                return ;
            }
            if(WIFEXITED(status))
            {
                ptr->ui.AppendImageToSendTextctrl(path);
            }
//#elif defined _WIN32



//#endif
        }
    }
}
