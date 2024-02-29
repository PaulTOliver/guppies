/***************************************************************
 * Name:      Guppies1_0Main.h
 * Purpose:   Defines Application Frame
 * Author:    Paul T. Oliver (nino.trullen@gmail.com)
 * Created:   2012-11-13
 * Copyright: Paul T. Oliver ()
 * License:
 **************************************************************/

#ifndef GUPPIES1_0MAIN_H
#define GUPPIES1_0MAIN_H

//(*Headers(Guppies1_0Dialog)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/hyperlink.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/clrpicker.h>
//*)

class Guppies1_0Dialog: public wxDialog
{
    public:

        Guppies1_0Dialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Guppies1_0Dialog();

    private:

        //(*Handlers(Guppies1_0Dialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnBeginNewSimulation(wxCommandEvent& event);
        void OnCheckBox2Click(wxCommandEvent& event);
        void OnFilePickerCtrl2FileChanged(wxFileDirPickerEvent& event);
        void OnFilePickerCtrl3FileChanged(wxFileDirPickerEvent& event);
        //*)

        //(*Identifiers(Guppies1_0Dialog)
        static const long ID_STATICBITMAP1;
        static const long ID_STATICLINE3;
        static const long ID_STATICTEXT37;
        static const long ID_STATICTEXT39;
        static const long ID_HYPERLINKCTRL1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT38;
        static const long ID_PANEL4;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICLINE2;
        static const long ID_BUTTON1;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT31;
        static const long ID_STATICTEXT32;
        static const long ID_STATICTEXT33;
        static const long ID_CHOICE1;
        static const long ID_CHOICE2;
        static const long ID_TEXTCTRL18;
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT34;
        static const long ID_STATICTEXT36;
        static const long ID_TEXTCTRL22;
        static const long ID_TEXTCTRL23;
        static const long ID_TEXTCTRL24;
        static const long ID_STATICTEXT28;
        static const long ID_STATICTEXT30;
        static const long ID_STATICTEXT29;
        static const long ID_TEXTCTRL19;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL21;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT22;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT24;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT26;
        static const long ID_STATICTEXT27;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_COLOURPICKERCTRL2;
        static const long ID_COLOURPICKERCTRL3;
        static const long ID_COLOURPICKERCTRL4;
        static const long ID_COLOURPICKERCTRL5;
        static const long ID_COLOURPICKERCTRL6;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT17;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL9;
        static const long ID_TEXTCTRL10;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL13;
        static const long ID_CHECKBOX3;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT21;
        static const long ID_TEXTCTRL14;
        static const long ID_TEXTCTRL15;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL17;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_FILEPICKERCTRL3;
        static const long ID_BUTTON5;
        static const long ID_BUTTON2;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(Guppies1_0Dialog)
        wxStaticText* StaticText10;
        wxStaticText* StaticText22;
        wxStaticText* StaticText9;
        wxStaticText* StaticText20;
        wxTextCtrl* TextCtrl4;
        wxButton* Button4;
        wxStaticText* StaticText29;
        wxNotebook* Notebook1;
        wxStaticText* StaticText37;
        wxFilePickerCtrl* FilePickerCtrl1;
        wxStaticText* StaticText13;
        wxStaticText* StaticText33;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxStaticText* StaticText14;
        wxStaticText* StaticText30;
        wxButton* Button1;
        wxTextCtrl* TextCtrl16;
        wxStaticText* StaticText26;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl6;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText19;
        wxStaticText* StaticText32;
        wxStaticText* StaticText8;
        wxStaticText* StaticText38;
        wxStaticText* StaticText11;
        wxCheckBox* CheckBox3;
        wxStaticText* StaticText18;
        wxTextCtrl* TextCtrl19;
        wxCheckBox* CheckBox2;
        wxPanel* Panel1;
        wxStaticText* StaticText31;
        wxStaticText* StaticText1;
        wxStaticText* StaticText27;
        wxColourPickerCtrl* ColourPickerCtrl1;
        wxStaticText* StaticText3;
        wxHyperlinkCtrl* HyperlinkCtrl1;
        wxButton* Button2;
        wxPanel* Panel3;
        wxStaticText* StaticText21;
        wxCheckBox* CheckBox1;
        wxTextCtrl* TextCtrl18;
        wxStaticText* StaticText39;
        wxStaticLine* StaticLine2;
        wxColourPickerCtrl* ColourPickerCtrl6;
        wxColourPickerCtrl* ColourPickerCtrl3;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxButton* Button5;
        wxTextCtrl* TextCtrl17;
        wxTextCtrl* TextCtrl24;
        wxTextCtrl* TextCtrl14;
        wxButton* Button3;
        wxTextCtrl* TextCtrl15;
        wxStaticText* StaticText5;
        wxStaticText* StaticText34;
        wxStaticText* StaticText7;
        wxTextCtrl* TextCtrl13;
        wxColourPickerCtrl* ColourPickerCtrl4;
        wxTextCtrl* TextCtrl21;
        wxTextCtrl* TextCtrl20;
        wxTextCtrl* TextCtrl22;
        wxStaticLine* StaticLine3;
        wxTextCtrl* TextCtrl8;
        wxStaticLine* StaticLine1;
        wxTextCtrl* TextCtrl2;
        wxColourPickerCtrl* ColourPickerCtrl2;
        wxTextCtrl* TextCtrl7;
        wxStaticText* StaticText28;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText15;
        wxStaticText* StaticText12;
        wxTextCtrl* TextCtrl9;
        wxStaticText* StaticText35;
        wxPanel* Panel2;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl23;
        wxColourPickerCtrl* ColourPickerCtrl5;
        wxStaticText* StaticText25;
        wxStaticText* StaticText17;
        wxStaticText* StaticText4;
        wxStaticText* StaticText36;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl10;
        wxTextCtrl* TextCtrl12;
        wxChoice* Choice1;
        wxFilePickerCtrl* FilePickerCtrl2;
        wxTextCtrl* TextCtrl11;
        wxStaticText* StaticText16;
        wxChoice* Choice2;
        wxFilePickerCtrl* FilePickerCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GUPPIES1_0MAIN_H
