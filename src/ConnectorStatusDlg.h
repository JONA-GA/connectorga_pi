#ifndef __ConnectorStatusDlg__
#define __ConnectorStatusDlg__

/**
@file
Subclass of StatusDlg, which is generated by wxFormBuilder.
*/

#include "connectorgui.h"

//// end generated include

/** Implementing StatusDlg */
class ConnectorStatusDlg : public StatusDlg
{
	protected:
		// Handlers for StatusDlg events.
		void OnCheckListBox( wxCommandEvent& event );
		void OnCheckListBoxToggled( wxCommandEvent& event );
	public:
		/** Constructor */
		ConnectorStatusDlg( wxWindow* parent );
	//// end generated class members
	
};

#endif // __ConnectorStatusDlg__