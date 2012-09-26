#include "connector_pi.h"
#include "data_source.h"

extern	ArrayOfDataSources m_DataSources ;

IntConnectorCfgDlg::IntConnectorCfgDlg( wxWindow* parent )
:
ConnectorCfgDlg( parent )
{
 // Populate wxListCtrlDatasources  
		// add column   
        wxListItem col0;
        col0.SetId(0);
        col0.SetText( _("Id") );
        col0.SetWidth(30);
        m_listCtrlDatasources->InsertColumn(0, col0);
        
        // Add second column
        wxListItem col1;
        col1.SetId(1);
        col1.SetText( _("Source") );
		col1.SetWidth(130);
        m_listCtrlDatasources->InsertColumn(1, col1);
        
        // Add third column     
        wxListItem col2;
        col2.SetId(2);
        col2.SetText( _("Protocol") );
		col2.SetWidth(180);
        m_listCtrlDatasources->InsertColumn(2, col2);
		ShowDataSources();
}
void IntConnectorCfgDlg::ShowDataSources()
{		
		if (m_DataSources.GetCount()> 0)
		{
			DataSource d ;
			wxString s ;
			wxListItem it; 
			m_listCtrlDatasources->DeleteAllItems();
			for (unsigned int i=0;i<m_DataSources.GetCount();i++)
			{
				d = m_DataSources.Item(i);
				s.Printf(wxT("%d"),d.Id);
				it.SetId(i);
				it.SetColumn(0);
				it.SetText(s);
				m_listCtrlDatasources->InsertItem(it);
				m_listCtrlDatasources->SetItem(i,1,d.port);
				if(d.protocol== 0) s=wxT("NMEA0183");
				if(d.protocol== 1) s=wxT("NMEA2000");
				if(d.protocol== 2) s=wxT("SEATALK");
				m_listCtrlDatasources->SetItem(i,2,s);
			}
			
		}
		m_pConnectorSourceDialog= NULL ;	
}

IntConnectorCfgDlg::~IntConnectorCfgDlg( void )
{
	delete m_pConnectorSourceDialog;
}

void IntConnectorCfgDlg::OnAddClick( wxCommandEvent& event )
{
		
		
	DataSource d;
	  if(NULL == m_pConnectorSourceDialog)
	  {
		m_pConnectorSourceDialog= new IntConnectorSourceDlg (this );
		m_pConnectorSourceDialog->Move(wxPoint(0, 0));
		m_pConnectorSourceDialog->SetWorkDatasource(&d);
		
	  }
		int ret ;
		int i;
		
		ret = m_pConnectorSourceDialog->ShowModal();
	 if(ret == wxID_OK+1)
    {
		i=m_DataSources.GetCount();
		d.Id= i+1;
		m_DataSources.Add(d,1);
		ShowDataSources();
        
    }
	delete m_pConnectorSourceDialog;
	m_pConnectorSourceDialog= NULL ;	
}

void IntConnectorCfgDlg::OnEditClick( wxCommandEvent& event )
{
	DataSource d;
	if(NULL == m_pConnectorSourceDialog)
	  {
		m_pConnectorSourceDialog= new IntConnectorSourceDlg (this );
		m_pConnectorSourceDialog->Move(wxPoint(0, 0));
		m_pConnectorSourceDialog->SetWorkDatasource(&d);
		
	  }
		unsigned int tst=0;
	 if(m_pConnectorSourceDialog->ShowModal() == wxID_OK)
    {
      if (tst==0) tst=2;
        
    }
	delete m_pConnectorSourceDialog;
	m_pConnectorSourceDialog= NULL ;
}

void IntConnectorCfgDlg::OnRemoveClick( wxCommandEvent& event )
{
	DataSource d;
	int i;
	long ind;
	wxListItem it;
	i=m_listCtrlDatasources->GetSelectedItemCount();
	if (i>0)
	{
		ind=m_listCtrlDatasources->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		it.SetId(ind);
		m_listCtrlDatasources->GetItem(it);
		m_DataSources.RemoveAt(it.GetId());
		m_listCtrlDatasources->DeleteItem(it);
		}
}

void IntConnectorCfgDlg::OnCancelClick( wxCommandEvent& event )
{
// TODO: Implement OnCancelClick
this->Destroy();
}

void IntConnectorCfgDlg::OnOkClick( wxCommandEvent& event )
{
// TODO: Implement OnOkClick
this->Destroy();
}
