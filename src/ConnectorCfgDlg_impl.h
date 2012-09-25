#ifndef __IntConnectorCfgDlg__
#define __IntConnectorCfgDlg__

/**
@file
Subclass of ConnectorCfgDlg, which is generated by wxFormBuilder.
*/

#include "connectorgui.h"
#include "ConnectorSourceDlg_impl.h"
//// end generated include

/** Implementing ConnectorCfgDlg */
class IntConnectorCfgDlg : public ConnectorCfgDlg
{
	protected:
		// Handlers for ConnectorCfgDlg events.
		void OnAddClick( wxCommandEvent& event );
		void OnEditClick( wxCommandEvent& event );
		void OnRemoveClick( wxCommandEvent& event );
		void OnCancelClick( wxCommandEvent& event );
		void OnOkClick( wxCommandEvent& event );
	public:
		/** Constructor */
		IntConnectorCfgDlg( wxWindow* parent );
		~IntConnectorCfgDlg( void );
	//// end generated class members
	IntConnectorSourceDlg	*m_pConnectorSourceDialog;
};

#endif // __IntConnectorCfgDlg__
