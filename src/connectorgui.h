///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  5 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CONNECTORGUI_H__
#define __CONNECTORGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/tglbtn.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ConnectorCfgDlg
///////////////////////////////////////////////////////////////////////////////
class ConnectorCfgDlg : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* m_listCtrlDatasources;
		wxButton* m_buttonAdd;
		wxButton* m_buttonEdit;
		wxButton* m_buttonRemove;
		wxStdDialogButtonSizer* m_sdbSizerDlgButtons;
		wxButton* m_sdbSizerDlgButtonsOK;
		wxButton* m_sdbSizerDlgButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConnectorCfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connector Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 464,359 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ConnectorCfgDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ConnectorSourceDlg
///////////////////////////////////////////////////////////////////////////////
class ConnectorSourceDlg : public wxDialog 
{
	private:
	
	protected:
		wxRadioButton* m_radioBtnSerial;
		wxRadioButton* m_radioBtnNet;
		wxStaticText* m_staticText1;
		wxChoice* m_choicePort;
		wxStaticText* m_staticText2;
		wxChoice* m_choiceBaudRate;
		wxStaticText* m_staticText3;
		wxChoice* m_choiceProtocol;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textCtrl2;
		wxStaticText* m_staticText6;
		wxChoice* m_choice1;
		wxStdDialogButtonSizer* m_sdbSizerDlgButtons;
		wxButton* m_sdbSizerDlgButtonsOK;
		wxButton* m_sdbSizerDlgButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnComSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNetSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConnectorSourceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data source properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~ConnectorSourceDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class StatusDlg
///////////////////////////////////////////////////////////////////////////////
class StatusDlg : public wxDialog 
{
	private:
	
	protected:
		wxCheckListBox* m_checkListDataSources;
		wxTextCtrl* m_textCtrlMessages;
		wxToggleButton* m_toggleBtnShowMsgs;
		wxStdDialogButtonSizer* m_sdbSizerDlgButtons;
		wxButton* m_sdbSizerDlgButtonsOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCheckListBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckListBoxToggled( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		StatusDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connector Status"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 448,489 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~StatusDlg();
	
};

#endif //__CONNECTORGUI_H__
