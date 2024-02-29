/***************************************************************
 * Name:      Guppies1_0App.cpp
 * Purpose:   Code for Application Class
 * Author:    Paul T. Oliver (nino.trullen@gmail.com)
 * Created:   2012-11-13
 * Copyright: Paul T. Oliver ()
 * License:
 **************************************************************/

#include "Guppies1_0App.h"

//(*AppHeaders
#include "Guppies1_0Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Guppies1_0App);

bool Guppies1_0App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Guppies1_0Dialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
