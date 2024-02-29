/***************************************************************
 * Name:      Guppies1_0Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paul T. Oliver (nino.trullen@gmail.com)
 * Created:   2012-11-13
 * Copyright: Paul T. Oliver ()
 * License:
 **************************************************************/

#include "Guppies1_0Main.h"
#include <wx/msgdlg.h>
#include <wx/textfile.h>

//(*InternalHeaders(Guppies1_0Dialog)
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Guppies1_0Dialog)
const long Guppies1_0Dialog::ID_STATICBITMAP1 = wxNewId();
const long Guppies1_0Dialog::ID_STATICLINE3 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT37 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT39 = wxNewId();
const long Guppies1_0Dialog::ID_HYPERLINKCTRL1 = wxNewId();
const long Guppies1_0Dialog::ID_BUTTON4 = wxNewId();
const long Guppies1_0Dialog::ID_BUTTON3 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT38 = wxNewId();
const long Guppies1_0Dialog::ID_PANEL4 = wxNewId();
const long Guppies1_0Dialog::ID_FILEPICKERCTRL1 = wxNewId();
const long Guppies1_0Dialog::ID_STATICLINE1 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT1 = wxNewId();
const long Guppies1_0Dialog::ID_STATICLINE2 = wxNewId();
const long Guppies1_0Dialog::ID_BUTTON1 = wxNewId();
const long Guppies1_0Dialog::ID_PANEL2 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT31 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT32 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT33 = wxNewId();
const long Guppies1_0Dialog::ID_CHOICE1 = wxNewId();
const long Guppies1_0Dialog::ID_CHOICE2 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL18 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT35 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT34 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT36 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL22 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL23 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL24 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT28 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT30 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT29 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL19 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL20 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL21 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT2 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL1 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT3 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT4 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT5 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT6 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT7 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT8 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT9 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT10 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL2 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL3 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL4 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL5 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL6 = wxNewId();
const long Guppies1_0Dialog::ID_CHECKBOX1 = wxNewId();
const long Guppies1_0Dialog::ID_CHECKBOX2 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL8 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT22 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT23 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT24 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT25 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT26 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT27 = wxNewId();
const long Guppies1_0Dialog::ID_COLOURPICKERCTRL1 = wxNewId();
const long Guppies1_0Dialog::ID_COLOURPICKERCTRL2 = wxNewId();
const long Guppies1_0Dialog::ID_COLOURPICKERCTRL3 = wxNewId();
const long Guppies1_0Dialog::ID_COLOURPICKERCTRL4 = wxNewId();
const long Guppies1_0Dialog::ID_COLOURPICKERCTRL5 = wxNewId();
const long Guppies1_0Dialog::ID_COLOURPICKERCTRL6 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT11 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT12 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT13 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT14 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT15 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT16 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT17 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL7 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL9 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL10 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL11 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL12 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL13 = wxNewId();
const long Guppies1_0Dialog::ID_CHECKBOX3 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT18 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT19 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT20 = wxNewId();
const long Guppies1_0Dialog::ID_STATICTEXT21 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL14 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL15 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL16 = wxNewId();
const long Guppies1_0Dialog::ID_TEXTCTRL17 = wxNewId();
const long Guppies1_0Dialog::ID_FILEPICKERCTRL2 = wxNewId();
const long Guppies1_0Dialog::ID_FILEPICKERCTRL3 = wxNewId();
const long Guppies1_0Dialog::ID_BUTTON5 = wxNewId();
const long Guppies1_0Dialog::ID_BUTTON2 = wxNewId();
const long Guppies1_0Dialog::ID_PANEL3 = wxNewId();
const long Guppies1_0Dialog::ID_NOTEBOOK1 = wxNewId();
const long Guppies1_0Dialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Guppies1_0Dialog,wxDialog)
    //(*EventTable(Guppies1_0Dialog)
    //*)
END_EVENT_TABLE()

Guppies1_0Dialog::Guppies1_0Dialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Guppies1_0Dialog)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer21;
    wxBoxSizer* BoxSizer13;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxBoxSizer* BoxSizer23;
    wxStaticBoxSizer* StaticBoxSizer9;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer16;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer18;
    wxBoxSizer* BoxSizer28;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxBoxSizer* BoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer27;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer24;
    wxBoxSizer* BoxSizer26;
    wxBoxSizer* BoxSizer9;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer22;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxBoxSizer* BoxSizer25;

    Create(parent, wxID_ANY, _("Neural Guppies - 0.1 beta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
    BoxSizer27 = new wxBoxSizer(wxVERTICAL);
    StaticBitmap1 = new wxStaticBitmap(Panel4, ID_STATICBITMAP1, wxBitmap(wxImage(_T("gfx\\logo.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    BoxSizer27->Add(StaticBitmap1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine3 = new wxStaticLine(Panel4, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    BoxSizer27->Add(StaticLine3, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText37 = new wxStaticText(Panel4, ID_STATICTEXT37, _("\nVersion -0.1 beta 20121220\n\nBy: Paul T. Oliver"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT37"));
    wxFont StaticText37Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("DejaVu Sans Mono"),wxFONTENCODING_DEFAULT);
    StaticText37->SetFont(StaticText37Font);
    BoxSizer27->Add(StaticText37, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticText39 = new wxStaticText(Panel4, ID_STATICTEXT39, _("paul.t.oliver.design@gmail.com"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    BoxSizer27->Add(StaticText39, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    HyperlinkCtrl1 = new wxHyperlinkCtrl(Panel4, ID_HYPERLINKCTRL1, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
    BoxSizer27->Add(HyperlinkCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer28 = new wxBoxSizer(wxHORIZONTAL);
    Button4 = new wxButton(Panel4, ID_BUTTON4, _("Load simulation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    wxFont Button4Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("DejaVu Sans Mono"),wxFONTENCODING_DEFAULT);
    Button4->SetFont(Button4Font);
    BoxSizer28->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel4, ID_BUTTON3, _("New simulation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("DejaVu Sans Mono"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    BoxSizer28->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer27->Add(BoxSizer28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText38 = new wxStaticText(Panel4, ID_STATICTEXT38, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT38"));
    BoxSizer27->Add(StaticText38, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(BoxSizer27);
    BoxSizer27->Fit(Panel4);
    BoxSizer27->SetSizeHints(Panel4);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(29,47), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    FilePickerCtrl1 = new wxFilePickerCtrl(Panel2, ID_FILEPICKERCTRL1, wxEmptyString, _("Load simulation"), _T("*.sim"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FilePickerCtrl1->Disable();
    BoxSizer4->Add(FilePickerCtrl1, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel2, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer3->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("No simulation loaded."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 3, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    StaticLine2 = new wxStaticLine(Panel2, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer3->Add(StaticLine2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel2, ID_BUTTON1, _("Resume simulation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->Disable();
    BoxSizer5->Add(Button1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel2);
    BoxSizer3->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxPoint(96,8), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer20 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Neural network parameters"));
    BoxSizer21 = new wxBoxSizer(wxVERTICAL);
    StaticText31 = new wxStaticText(Panel3, ID_STATICTEXT31, _("Network structure"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    BoxSizer21->Add(StaticText31, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText32 = new wxStaticText(Panel3, ID_STATICTEXT32, _("Node structure"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    BoxSizer21->Add(StaticText32, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(Panel3, ID_STATICTEXT33, _("Nodes per hidden layer"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    BoxSizer21->Add(StaticText33, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer8->Add(BoxSizer21, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer22 = new wxBoxSizer(wxVERTICAL);
    Choice1 = new wxChoice(Panel3, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("Single MLP")) );
    Choice1->Append(_("Dual MLP"));
    Choice1->Append(_("Simple RN"));
    Choice1->Append(_("Fully RN"));
    BoxSizer22->Add(Choice1, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Choice2 = new wxChoice(Panel3, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->SetSelection( Choice2->Append(_("Neuron")) );
    Choice2->Append(_("Memory cell"));
    BoxSizer22->Add(Choice2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    TextCtrl18 = new wxTextCtrl(Panel3, ID_TEXTCTRL18, _("80"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    BoxSizer22->Add(TextCtrl18, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticBoxSizer8->Add(BoxSizer22, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer20->Add(StaticBoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Population parameters"));
    BoxSizer25 = new wxBoxSizer(wxVERTICAL);
    StaticText35 = new wxStaticText(Panel3, ID_STATICTEXT35, _("Sub-population size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    BoxSizer25->Add(StaticText35, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText34 = new wxStaticText(Panel3, ID_STATICTEXT34, _("Sub-population quantity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    BoxSizer25->Add(StaticText34, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText36 = new wxStaticText(Panel3, ID_STATICTEXT36, _("Elites per generation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    BoxSizer25->Add(StaticText36, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer10->Add(BoxSizer25, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer26 = new wxBoxSizer(wxVERTICAL);
    TextCtrl22 = new wxTextCtrl(Panel3, ID_TEXTCTRL22, _("20"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    BoxSizer26->Add(TextCtrl22, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl23 = new wxTextCtrl(Panel3, ID_TEXTCTRL23, _("20"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    BoxSizer26->Add(TextCtrl23, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl24 = new wxTextCtrl(Panel3, ID_TEXTCTRL24, _("40"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    BoxSizer26->Add(TextCtrl24, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer10->Add(BoxSizer26, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer20->Add(StaticBoxSizer10, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Fitness bonuses"));
    BoxSizer23 = new wxBoxSizer(wxVERTICAL);
    StaticText28 = new wxStaticText(Panel3, ID_STATICTEXT28, _("Per pellet"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    BoxSizer23->Add(StaticText28, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText30 = new wxStaticText(Panel3, ID_STATICTEXT30, _("Per guppy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    BoxSizer23->Add(StaticText30, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText29 = new wxStaticText(Panel3, ID_STATICTEXT29, _("Per corpse (max)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    BoxSizer23->Add(StaticText29, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer9->Add(BoxSizer23, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer24 = new wxBoxSizer(wxVERTICAL);
    TextCtrl19 = new wxTextCtrl(Panel3, ID_TEXTCTRL19, _("9000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    BoxSizer24->Add(TextCtrl19, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl20 = new wxTextCtrl(Panel3, ID_TEXTCTRL20, _("36000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    BoxSizer24->Add(TextCtrl20, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl21 = new wxTextCtrl(Panel3, ID_TEXTCTRL21, _("36000"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    BoxSizer24->Add(TextCtrl21, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer9->Add(BoxSizer24, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer20->Add(StaticBoxSizer9, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer20, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Dish parameters"));
    BoxSizer15 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT2, _("Dish radius"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetHelpText(_("Size of the circular dish that guppies live in"));
    BoxSizer15->Add(StaticText2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer15, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer16 = new wxBoxSizer(wxVERTICAL);
    TextCtrl1 = new wxTextCtrl(Panel3, ID_TEXTCTRL1, _("40"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer16->Add(TextCtrl1, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer16, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Entity parameters"));
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(Panel3, ID_STATICTEXT3, _("Zapper random force"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer8->Add(StaticText3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel3, ID_STATICTEXT4, _("Zapper random torque"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer8->Add(StaticText4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("Zapper quantity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer8->Add(StaticText5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel3, ID_STATICTEXT6, _("Pellet quantity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer8->Add(StaticText6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("Pellet creation delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer8->Add(StaticText7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("Start scarce"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    BoxSizer8->Add(StaticText8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("Corpse decay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer8->Add(StaticText9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT10, _("Corpse decay rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer8->Add(StaticText10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    TextCtrl2 = new wxTextCtrl(Panel3, ID_TEXTCTRL2, _("50"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer9->Add(TextCtrl2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(Panel3, ID_TEXTCTRL3, _("150"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer9->Add(TextCtrl3, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(Panel3, ID_TEXTCTRL4, _("20"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    BoxSizer9->Add(TextCtrl4, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(Panel3, ID_TEXTCTRL5, _("400"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    BoxSizer9->Add(TextCtrl5, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl6 = new wxTextCtrl(Panel3, ID_TEXTCTRL6, _("150"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    BoxSizer9->Add(TextCtrl6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox1 = new wxCheckBox(Panel3, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    BoxSizer9->Add(CheckBox1, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox2 = new wxCheckBox(Panel3, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(true);
    BoxSizer9->Add(CheckBox2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl8 = new wxTextCtrl(Panel3, ID_TEXTCTRL8, _("3600"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    BoxSizer9->Add(TextCtrl8, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(BoxSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Colors"));
    BoxSizer17 = new wxBoxSizer(wxVERTICAL);
    StaticText22 = new wxStaticText(Panel3, ID_STATICTEXT22, _("Background"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    BoxSizer17->Add(StaticText22, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(Panel3, ID_STATICTEXT23, _("Dish fill (fog)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    BoxSizer17->Add(StaticText23, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText24 = new wxStaticText(Panel3, ID_STATICTEXT24, _("Zappers"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    BoxSizer17->Add(StaticText24, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(Panel3, ID_STATICTEXT25, _("Pellets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    BoxSizer17->Add(StaticText25, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText26 = new wxStaticText(Panel3, ID_STATICTEXT26, _("Corpses"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    BoxSizer17->Add(StaticText26, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText27 = new wxStaticText(Panel3, ID_STATICTEXT27, _("Guppies"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    BoxSizer17->Add(StaticText27, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(BoxSizer17, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18 = new wxBoxSizer(wxVERTICAL);
    ColourPickerCtrl1 = new wxColourPickerCtrl(Panel3, ID_COLOURPICKERCTRL1, wxColour(15,15,15), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    BoxSizer18->Add(ColourPickerCtrl1, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl2 = new wxColourPickerCtrl(Panel3, ID_COLOURPICKERCTRL2, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL2"));
    BoxSizer18->Add(ColourPickerCtrl2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl3 = new wxColourPickerCtrl(Panel3, ID_COLOURPICKERCTRL3, wxColour(0,0,255), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL3"));
    BoxSizer18->Add(ColourPickerCtrl3, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl4 = new wxColourPickerCtrl(Panel3, ID_COLOURPICKERCTRL4, wxColour(0,255,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL4"));
    BoxSizer18->Add(ColourPickerCtrl4, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl5 = new wxColourPickerCtrl(Panel3, ID_COLOURPICKERCTRL5, wxColour(255,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL5"));
    BoxSizer18->Add(ColourPickerCtrl5, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl6 = new wxColourPickerCtrl(Panel3, ID_COLOURPICKERCTRL6, wxColour(255,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL6"));
    BoxSizer18->Add(ColourPickerCtrl6, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(BoxSizer18, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Guppy parameters"));
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    StaticText11 = new wxStaticText(Panel3, ID_STATICTEXT11, _("Activation delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BoxSizer11->Add(StaticText11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(Panel3, ID_STATICTEXT12, _("Thrust force"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer11->Add(StaticText12, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel3, ID_STATICTEXT13, _("Thrust radius"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer11->Add(StaticText13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(Panel3, ID_STATICTEXT14, _("Initial energy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    BoxSizer11->Add(StaticText14, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel3, ID_STATICTEXT15, _("Max energy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    BoxSizer11->Add(StaticText15, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel3, ID_STATICTEXT16, _("Aging rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    BoxSizer11->Add(StaticText16, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel3, ID_STATICTEXT17, _("Leave corpse"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    BoxSizer11->Add(StaticText17, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(BoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12 = new wxBoxSizer(wxVERTICAL);
    TextCtrl7 = new wxTextCtrl(Panel3, ID_TEXTCTRL7, _("120"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    BoxSizer12->Add(TextCtrl7, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl9 = new wxTextCtrl(Panel3, ID_TEXTCTRL9, _("5"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    BoxSizer12->Add(TextCtrl9, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl10 = new wxTextCtrl(Panel3, ID_TEXTCTRL10, _("0.05"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    BoxSizer12->Add(TextCtrl10, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl11 = new wxTextCtrl(Panel3, ID_TEXTCTRL11, _("60"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    BoxSizer12->Add(TextCtrl11, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl12 = new wxTextCtrl(Panel3, ID_TEXTCTRL12, _("180"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    BoxSizer12->Add(TextCtrl12, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl13 = new wxTextCtrl(Panel3, ID_TEXTCTRL13, _("600"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    BoxSizer12->Add(TextCtrl13, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox3 = new wxCheckBox(Panel3, ID_CHECKBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(true);
    BoxSizer12->Add(CheckBox3, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(BoxSizer12, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Energy transfers"));
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    StaticText18 = new wxStaticText(Panel3, ID_STATICTEXT18, _("From zappers"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    BoxSizer13->Add(StaticText18, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(Panel3, ID_STATICTEXT19, _("From pellets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    BoxSizer13->Add(StaticText19, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(Panel3, ID_STATICTEXT20, _("From other guppies"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    BoxSizer13->Add(StaticText20, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText21 = new wxStaticText(Panel3, ID_STATICTEXT21, _("From corpses (max)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    BoxSizer13->Add(StaticText21, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(BoxSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    TextCtrl14 = new wxTextCtrl(Panel3, ID_TEXTCTRL14, _("-20"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    BoxSizer14->Add(TextCtrl14, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl15 = new wxTextCtrl(Panel3, ID_TEXTCTRL15, _("15"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    BoxSizer14->Add(TextCtrl15, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl16 = new wxTextCtrl(Panel3, ID_TEXTCTRL16, _("60"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    BoxSizer14->Add(TextCtrl16, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl17 = new wxTextCtrl(Panel3, ID_TEXTCTRL17, _("60"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    BoxSizer14->Add(TextCtrl17, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(BoxSizer14, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Load parameters"));
    FilePickerCtrl2 = new wxFilePickerCtrl(Panel3, ID_FILEPICKERCTRL2, _T("prms/"), _("Load parameters"), _T("*.prms"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    StaticBoxSizer6->Add(FilePickerCtrl2, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Save parameters"));
    FilePickerCtrl3 = new wxFilePickerCtrl(Panel3, ID_FILEPICKERCTRL3, _T("prms/"), _("Save parameters"), _T("*.prms"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE, wxDefaultValidator, _T("ID_FILEPICKERCTRL3"));
    StaticBoxSizer7->Add(FilePickerCtrl3, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(Panel3, ID_BUTTON5, _("Save as default"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer7->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(StaticBoxSizer7, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    Button2 = new wxButton(Panel3, ID_BUTTON2, _("Begin new simulation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer19->Add(Button2, 1, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(BoxSizer19, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer6->Add(BoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel3);
    BoxSizer6->SetSizeHints(Panel3);
    Notebook1->AddPage(Panel4, _("Welcome"), false);
    Notebook1->AddPage(Panel2, _("Load simulation"), false);
    Notebook1->AddPage(Panel3, _("New simulation"), false);
    BoxSizer2->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Guppies1_0Dialog::OnButton4Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Guppies1_0Dialog::OnButton3Click);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Guppies1_0Dialog::OnCheckBox2Click);
    Connect(ID_FILEPICKERCTRL2,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&Guppies1_0Dialog::OnFilePickerCtrl2FileChanged);
    Connect(ID_FILEPICKERCTRL3,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&Guppies1_0Dialog::OnFilePickerCtrl3FileChanged);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Guppies1_0Dialog::OnBeginNewSimulation);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&Guppies1_0Dialog::OnNotebook1PageChanged);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&Guppies1_0Dialog::OnInit);
    //*)

    SetIcon(wxICON(aaaa));
}

Guppies1_0Dialog::~Guppies1_0Dialog()
{
    //(*Destroy(Guppies1_0Dialog)
    //*)
}

void Guppies1_0Dialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Guppies1_0Dialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Guppies1_0Dialog::OnNotebook1PageChanged(wxNotebookEvent& event)
{
}

void Guppies1_0Dialog::OnInit(wxInitDialogEvent& event)
{
}

void Guppies1_0Dialog::OnButton4Click(wxCommandEvent& event)
{
    Notebook1->SetSelection(1);
}

void Guppies1_0Dialog::OnButton3Click(wxCommandEvent& event)
{
    Notebook1->SetSelection(2);
}

void Guppies1_0Dialog::OnCheckBox2Click(wxCommandEvent& event)
{
    if (CheckBox2->IsChecked())
    {
        TextCtrl8->Enable();
    }
    else
    {
        TextCtrl8->Disable();
    }
}


// APLICATION STARTUP POINT ////////////////////////////////////////////////////
#include "Simulation/GuppiesInclude.hpp"

void Guppies1_0Dialog::OnBeginNewSimulation(wxCommandEvent& event)
{
    Params params;

    // Neural network parameters
    switch(Choice1->GetCurrentSelection())
    {
    case 0:
        params.netClass = SINGLE_MLP;
        break;
    case 1:
        params.netClass = DUAL_MLP;
        break;
    case 2:
        params.netClass = SIMPLE_RN;
        break;
    case 3:
        params.netClass = FULLY_RN;
        break;
    }

    switch (Choice2->GetCurrentSelection())
    {
    case 0:
        params.nodeClass = NEURON;
        break;
    case 1:
        params.nodeClass = MEMORY_CELL;
        break;
    }

    unsigned npHiddenLayer = strtoul(TextCtrl18->GetLineText(0).mb_str(), nullptr, 0);
    params.npHiddenLayer = npHiddenLayer;

    // Population parameters
    unsigned popSize = strtoul(TextCtrl22->GetLineText(0).mb_str(), nullptr, 0);
    params.popSize = popSize;

    unsigned popQtty = strtoul(TextCtrl23->GetLineText(0).mb_str(), nullptr, 0);
    params.popQtty = popQtty;

    unsigned elites = strtoul(TextCtrl24->GetLineText(0).mb_str(), nullptr, 0);
    params.elites = elites;

    // Fitness bonuses
    int forPellet = strtol(TextCtrl19->GetLineText(0).mb_str(), nullptr, 0);
    params.forPellet = forPellet;

    int forGuppie = strtol(TextCtrl20->GetLineText(0).mb_str(), nullptr, 0);
    params.forGuppie = forGuppie;

    int forCorpse = strtol(TextCtrl21->GetLineText(0).mb_str(), nullptr, 0);
    params.forCorpse = forCorpse;

    // World (dish) parameters
    float worldRad = strtof(TextCtrl1->GetLineText(0).mb_str(), nullptr);
    params.worldRad = worldRad;

    // Entity parameters
    float zapperForce = strtof(TextCtrl2->GetLineText(0).mb_str(), nullptr);
    params.zapperForce = zapperForce;

    float zapperTorque = strtof(TextCtrl3->GetLineText(0).mb_str(), nullptr);
    params.zapperTorque = zapperTorque;

    unsigned zapperQtty = strtoul(TextCtrl4->GetLineText(0).mb_str(), nullptr, 0);
    params.zapperQtty = zapperQtty;

    unsigned pelletQtty = strtoul(TextCtrl5->GetLineText(0).mb_str(), nullptr, 0);
    params.pelletQtty = pelletQtty;

    unsigned pelletCreationDelay = strtoul(TextCtrl6->GetLineText(0).mb_str(), nullptr, 0);
    params.pelletCreationDelay = pelletCreationDelay;

    params.startScarce = CheckBox1->IsChecked();
    params.corpseDecay = CheckBox2->IsChecked();

    unsigned corpseDecayTime = strtoul(TextCtrl8->GetLineText(0).mb_str(), nullptr, 0);
    params.corpseDecayTime = corpseDecayTime;

    // Colors
    params.clearColor.r = ColourPickerCtrl1->GetColour().Red();
    params.clearColor.g = ColourPickerCtrl1->GetColour().Green();
    params.clearColor.b = ColourPickerCtrl1->GetColour().Blue();

    params.worldColor.r = ColourPickerCtrl2->GetColour().Red();
    params.worldColor.g = ColourPickerCtrl2->GetColour().Green();
    params.worldColor.b = ColourPickerCtrl2->GetColour().Blue();

    params.zapperColor.r = ColourPickerCtrl3->GetColour().Red();
    params.zapperColor.g = ColourPickerCtrl3->GetColour().Green();
    params.zapperColor.b = ColourPickerCtrl3->GetColour().Blue();

    params.pelletColor.r = ColourPickerCtrl4->GetColour().Red();
    params.pelletColor.g = ColourPickerCtrl4->GetColour().Green();
    params.pelletColor.b = ColourPickerCtrl4->GetColour().Blue();

    params.corpseColor.r = ColourPickerCtrl5->GetColour().Red();
    params.corpseColor.g = ColourPickerCtrl5->GetColour().Green();
    params.corpseColor.b = ColourPickerCtrl5->GetColour().Blue();

    params.guppieColorI.r = ColourPickerCtrl6->GetColour().Red();
    params.guppieColorI.g = ColourPickerCtrl6->GetColour().Green();
    params.guppieColorI.b = ColourPickerCtrl6->GetColour().Blue();

    // Guppie parameters
    unsigned activationDelay = strtoul(TextCtrl7->GetLineText(0).mb_str(), nullptr, 0);
    params.activationDelay = activationDelay;

    float thrustForce = strtof(TextCtrl9->GetLineText(0).mb_str(), nullptr);
    params.thrustForce = thrustForce;

    float thrustRadius = strtof(TextCtrl10->GetLineText(0).mb_str(), nullptr);
    params.thrustRadius = thrustRadius;

    float initEnergy = strtof(TextCtrl11->GetLineText(0).mb_str(), nullptr);
    params.initEnergy = initEnergy;

    float maxEnergy = strtof(TextCtrl12->GetLineText(0).mb_str(), nullptr);
    params.maxEnergy = maxEnergy;

    float agingRate = strtof(TextCtrl13->GetLineText(0).mb_str(), nullptr);
    params.agingRate = agingRate;

    params.leaveCorpse = CheckBox3->IsChecked();

    // Energy transfers
    float etFromZapper = strtof(TextCtrl14->GetLineText(0).mb_str(), nullptr);
    params.etFromZapper = etFromZapper;

    float etFromPellet = strtof(TextCtrl15->GetLineText(0).mb_str(), nullptr);
    params.etFromPellet = etFromPellet;

    float etFromGuppie = strtof(TextCtrl16->GetLineText(0).mb_str(), nullptr);
    params.etFromGuppie = etFromGuppie;

    float etFromCorpse = strtof(TextCtrl17->GetLineText(0).mb_str(), nullptr);
    params.etFromCorpse = etFromCorpse;

    // BEGIN SIMULATION ======================================================//
    Close();

    SimFitness simulation;
    simulation.createNew(params);
    simulation.execute();
}

void Guppies1_0Dialog::OnFilePickerCtrl2FileChanged(wxFileDirPickerEvent& event)
{
}

void Guppies1_0Dialog::OnFilePickerCtrl3FileChanged(wxFileDirPickerEvent& event)
{
    wxTextFile file(FilePickerCtrl3->GetPath());
    file.Create();

    file.AddLine("[BEGIN PARAMS]");

    file.AddLine(wxString::Format(("%i"), (int)Choice1->GetCurrentSelection()));
    file.AddLine(wxString::Format(("%i"), (int)Choice2->GetCurrentSelection()));

    file.AddLine(TextCtrl18->GetLineText(0));

    file.AddLine(TextCtrl22->GetLineText(0));
    file.AddLine(TextCtrl23->GetLineText(0));
    file.AddLine(TextCtrl24->GetLineText(0));

    file.AddLine(TextCtrl19->GetLineText(0));
    file.AddLine(TextCtrl20->GetLineText(0));
    file.AddLine(TextCtrl21->GetLineText(0));

    file.AddLine(TextCtrl1->GetLineText(0));

    file.AddLine(TextCtrl2->GetLineText(0));
    file.AddLine(TextCtrl3->GetLineText(0));
    file.AddLine(TextCtrl4->GetLineText(0));
    file.AddLine(TextCtrl5->GetLineText(0));
    file.AddLine(TextCtrl6->GetLineText(0));

    file.AddLine(wxString::Format(("%i"), (int)CheckBox1->IsChecked()));
    file.AddLine(wxString::Format(("%i"), (int)CheckBox2->IsChecked()));

    file.AddLine(TextCtrl8->GetLineText(0));

    file.AddLine(ColourPickerCtrl1->GetColour().GetAsString());
    file.AddLine(ColourPickerCtrl2->GetColour().GetAsString());
    file.AddLine(ColourPickerCtrl3->GetColour().GetAsString());
    file.AddLine(ColourPickerCtrl4->GetColour().GetAsString());
    file.AddLine(ColourPickerCtrl5->GetColour().GetAsString());
    file.AddLine(ColourPickerCtrl6->GetColour().GetAsString());

    file.AddLine(TextCtrl7->GetLineText(0));
    file.AddLine(TextCtrl9->GetLineText(0));
    file.AddLine(TextCtrl10->GetLineText(0));
    file.AddLine(TextCtrl11->GetLineText(0));
    file.AddLine(TextCtrl12->GetLineText(0));
    file.AddLine(TextCtrl13->GetLineText(0));

    file.AddLine(wxString::Format(("%i"), (int)CheckBox3->IsChecked()));

    file.AddLine(TextCtrl14->GetLineText(0));
    file.AddLine(TextCtrl15->GetLineText(0));
    file.AddLine(TextCtrl16->GetLineText(0));
    file.AddLine(TextCtrl17->GetLineText(0));

    file.AddLine("[END PARAMS]");

    file.Write();
    file.Close();
}
