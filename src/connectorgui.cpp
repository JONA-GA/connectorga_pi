///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  5 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "connectorgui.h"

///////////////////////////////////////////////////////////////////////////

ConnectorCfgDlg::ConnectorCfgDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Data Sources") ), wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listCtrlDatasources = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VRULES );
	bSizer2->Add( m_listCtrlDatasources, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonAdd, 0, wxALL, 5 );
	
	m_buttonEdit = new wxButton( this, wxID_ANY, _("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonEdit, 0, wxALL, 5 );
	
	m_buttonRemove = new wxButton( this, wxID_ANY, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonRemove, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	sbSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerDlgButtons = new wxStdDialogButtonSizer();
	m_sdbSizerDlgButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsOK );
	m_sdbSizerDlgButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsCancel );
	m_sdbSizerDlgButtons->Realize();
	
	bSizer1->Add( m_sdbSizerDlgButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnAddClick ), NULL, this );
	m_buttonEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnEditClick ), NULL, this );
	m_buttonRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnRemoveClick ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnOkClick ), NULL, this );
}

ConnectorCfgDlg::~ConnectorCfgDlg()
{
	// Disconnect Events
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnAddClick ), NULL, this );
	m_buttonEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnEditClick ), NULL, this );
	m_buttonRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnRemoveClick ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnOkClick ), NULL, this );
	
}

ConnectorSourceDlg::ConnectorSourceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_radioBtnSerial = new wxRadioButton( this, wxID_ANY, _("Serial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnSerial->SetValue( true ); 
	bSizer6->Add( m_radioBtnSerial, 1, wxALL, 5 );
	
	m_radioBtnNet = new wxRadioButton( this, wxID_ANY, _("Net"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnNet->Enable( false );
	
	bSizer6->Add( m_radioBtnNet, 1, wxALL, 5 );
	
	
	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Properties") ), wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	sbSizer2->Add( m_staticText1, 0, wxALL, 5 );
	
	wxString m_choicePortChoices[] = { _("COM1"), _("COM2") };
	int m_choicePortNChoices = sizeof( m_choicePortChoices ) / sizeof( wxString );
	m_choicePort = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePortNChoices, m_choicePortChoices, 0 );
	m_choicePort->SetSelection( 0 );
	sbSizer2->Add( m_choicePort, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Baudrate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	sbSizer2->Add( m_staticText2, 0, wxALL, 5 );
	
	wxString m_choiceBaudRateChoices[] = { _("4800"), _("9600"), _("38400"), _("115200"), _("230400") };
	int m_choiceBaudRateNChoices = sizeof( m_choiceBaudRateChoices ) / sizeof( wxString );
	m_choiceBaudRate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBaudRateNChoices, m_choiceBaudRateChoices, 0 );
	m_choiceBaudRate->SetSelection( 0 );
	sbSizer2->Add( m_choiceBaudRate, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	sbSizer2->Add( m_staticText3, 0, wxALL, 5 );
	
	wxString m_choiceProtocolChoices[] = { _("NMEA 0183"), _("NMEA 2000"), _("SEATALK") };
	int m_choiceProtocolNChoices = sizeof( m_choiceProtocolChoices ) / sizeof( wxString );
	m_choiceProtocol = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceProtocolNChoices, m_choiceProtocolChoices, 0 );
	m_choiceProtocol->SetSelection( 0 );
	sbSizer2->Add( m_choiceProtocol, 0, wxALL, 5 );
	
	
	bSizer7->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Properties") ), wxVERTICAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->Enable( false );
	
	sbSizer3->Add( m_staticText4, 0, wxALL, 5 );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl1->Enable( false );
	
	sbSizer3->Add( m_textCtrl1, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->Enable( false );
	
	sbSizer3->Add( m_staticText5, 0, wxALL, 5 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl2->Enable( false );
	
	sbSizer3->Add( m_textCtrl2, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->Enable( false );
	
	sbSizer3->Add( m_staticText6, 0, wxALL, 5 );
	
	wxString m_choice1Choices[] = { _("NMEA"), _("NMEA2000"), _("NMEA2000 Translator") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	m_choice1->Enable( false );
	
	sbSizer3->Add( m_choice1, 0, wxALL, 5 );
	
	
	bSizer7->Add( sbSizer3, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_sdbSizerDlgButtons = new wxStdDialogButtonSizer();
	m_sdbSizerDlgButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsOK );
	m_sdbSizerDlgButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsCancel );
	m_sdbSizerDlgButtons->Realize();
	
	bSizer4->Add( m_sdbSizerDlgButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_radioBtnSerial->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnComSelected ), NULL, this );
	m_radioBtnNet->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetSelected ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnOkClick ), NULL, this );
}

ConnectorSourceDlg::~ConnectorSourceDlg()
{
	// Disconnect Events
	m_radioBtnSerial->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnComSelected ), NULL, this );
	m_radioBtnNet->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetSelected ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnOkClick ), NULL, this );
	
}

StatusDlg::StatusDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Data Sources") ), wxHORIZONTAL );
	
	wxString m_checkListDataSourcesChoices[] = { _("COM1"), _("COM2") };
	int m_checkListDataSourcesNChoices = sizeof( m_checkListDataSourcesChoices ) / sizeof( wxString );
	m_checkListDataSources = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_checkListDataSourcesNChoices, m_checkListDataSourcesChoices, wxLB_ALWAYS_SB|wxLB_MULTIPLE );
	sbSizer4->Add( m_checkListDataSources, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer8->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Messages") ), wxVERTICAL );
	
	m_textCtrlMessages = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer5->Add( m_textCtrlMessages, 1, wxALL|wxEXPAND, 5 );
	
	m_toggleBtnShowMsgs = new wxToggleButton( this, wxID_ANY, _("Capture stream"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_toggleBtnShowMsgs, 0, wxALL, 5 );
	
	
	bSizer8->Add( sbSizer5, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerDlgButtons = new wxStdDialogButtonSizer();
	m_sdbSizerDlgButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsOK );
	m_sdbSizerDlgButtons->Realize();
	
	bSizer8->Add( m_sdbSizerDlgButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer8 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_checkListDataSources->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( StatusDlg::OnCheckListBox ), NULL, this );
	m_checkListDataSources->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( StatusDlg::OnCheckListBoxToggled ), NULL, this );
}

StatusDlg::~StatusDlg()
{
	// Disconnect Events
	m_checkListDataSources->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( StatusDlg::OnCheckListBox ), NULL, this );
	m_checkListDataSources->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( StatusDlg::OnCheckListBoxToggled ), NULL, this );
	
}
