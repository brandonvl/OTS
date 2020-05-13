#include "MainFrame.h"

MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, [=](wxCommandEvent&) 
    { 
        wxLogMessage("Hello world from wxWidgets!");
    }, ID_Hello);

    Bind(wxEVT_MENU, [=](wxCommandEvent&) 
    { 
        wxMessageBox("This is a wxWidgets Hello World example",
            "About Hello World", wxOK | wxICON_INFORMATION); 
    }, wxID_ABOUT);

    Bind(wxEVT_MENU, [=](wxCommandEvent&) 
    { 
        Close(true); 
    }, wxID_EXIT);
}