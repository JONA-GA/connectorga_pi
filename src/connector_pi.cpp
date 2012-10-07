/******************************************************************************
 * $Id: connector_pi.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
 *
 * Project:  OpenCPN
 * Purpose:  Connector Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Pavel Kalian   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */


#include <wx/wxprec.h>

#ifndef  WX_PRECOMP
  #include <wx/wx.h>
#endif //precompiled headers

#include "connector_pi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ArrayOfDataSources  m_DataSources;

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new connector_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    Connector PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------
#include "DataSourcesArray.h"

connector_pi::connector_pi(void *ppimgr)
      :opencpn_plugin_18(ppimgr)
{

      // Create the PlugIn icons
      con_initialize_images();
}
connector_pi::~connector_pi(void)
{
	  delete _img_connector_pi;
      delete _img_connector;
}
int connector_pi::Init(void)
{
    
      
      AddLocaleCatalog( _T("opencpn-connector_pi") );
		
      // Set some default private member parameters
      m_connector_dialog_x = 0;
      m_connector_dialog_y = 0;

      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
      LoadConfig();

      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_connector, _img_connector, wxITEM_NORMAL,
            _("Connector"), _T(""), NULL,
             CONNECTOR_TOOL_POSITION, 0, this);

      m_pConnectorDialog = NULL;
/*
 * 
 * 
 * 
 */
 if (m_DataSources.GetCount() > 0)
 {
		unsigned int i;
		DataSource* p;
		for (i=0;i<m_DataSources.GetCount();i++){
			p = m_DataSources.Item(i);
		if( p->protocol==2) St_init(p);
		}
 }
      return (WANTS_CURSOR_LATLON       |
              WANTS_TOOLBAR_CALLBACK    |
              INSTALLS_TOOLBAR_TOOL     |
              WANTS_PREFERENCES         |
             // WANTS_NMEA_SENTENCES      |
			 // WANTS_NMEA_EVENTS 	    |
              WANTS_CONFIG
           );
}

bool connector_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pConnectorDialog)
      {
            wxPoint p = m_pConnectorDialog->GetPosition();
            SetConnectorDialogX(p.x);
            SetConnectorDialogY(p.y);

            m_pConnectorDialog->Close();
            delete m_pConnectorDialog;
            m_pConnectorDialog = NULL;
      }
      SaveConfig();
      return true;
}

int connector_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int connector_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int connector_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int connector_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *connector_pi::GetPlugInBitmap()
{
      return _img_connector_pi;
}

wxString connector_pi::GetCommonName()
{
      return _("Connector");
}


wxString connector_pi::GetShortDescription()
{
      return _("Connector PlugIn for OpenCPN");
}

wxString connector_pi::GetLongDescription()
{
      return _("Connects various datasources\n\
To the NMEA pipeline in OpenCPN.");
}


int connector_pi::GetToolbarToolCount(void)
{
      return 1;
}

void connector_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pConnectorDialog)
            return;

      //DimeDialog
}

void connector_pi::OnToolbarToolCallback(int id)
{
      if(NULL == m_pConnectorDialog)
      {
            m_pConnectorDialog = new IntConnectorCfgDlg(m_parent_window );
			m_pConnectorDialog->LinkToPlugin(this);
            m_pConnectorDialog->Move(wxPoint(m_connector_dialog_x, m_connector_dialog_y));
      }

     
	  if(m_pConnectorDialog->ShowModal() == wxID_OK)
    {
      
        
    }
	delete m_pConnectorDialog;
	m_pConnectorDialog= NULL ;	
}

bool connector_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Plugins/Connector" ) );
            pConf->Read ( _T( "ViewType" ),  &m_iViewType, 1 );
            pConf->Read ( _T( "ShowAtCursor" ),  &m_bShowAtCursor, 1 );
            pConf->Read ( _T( "Opacity" ),  &m_iOpacity, 255 );

            m_connector_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_connector_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );

            if((m_connector_dialog_x < 0) || (m_connector_dialog_x > m_display_width))
                  m_connector_dialog_x = 5;
            if((m_connector_dialog_y < 0) || (m_connector_dialog_y > m_display_height))
                  m_connector_dialog_y = 5;
			pConf->SetPath ( _T( "/Plugins/Connector/DataSources" ) );
			int cnt;
            pConf->Read ( _T ( "DataSources" ), &cnt,0);
			if (cnt> 0)
		{
			DataSource * m_ds ;
			wxString s ;
			for ( int i=0;i<cnt;i++)
			{
				m_ds =new(DataSource) ;
				s.Printf(wxT("%d"),i+1);
				m_ds->Id = (unsigned int)pConf->Read ( _T ( "Id") + s  ,0l);
				m_ds->port=pConf->Read ( _T ( "Port" + s) );
				m_ds->protocol= (unsigned int)pConf->Read ( _T ( "Proto" + s),0l );
				m_ds->speed= (unsigned int)pConf->Read ( _T ( "Speed" + s),0l);
				m_DataSources.Add( m_ds,1);
			}
		}	  
				  
				  
            pConf->SetPath ( _T ( "/Directories" ) );
            wxString def;
            def = ::wxGetCwd() + _T("/plugins");
            pConf->Read ( _T ( "ConnectorDataLocation" ), &m_connector_dir, def);
         
			return true;
      }
      else
            return false;
}

bool connector_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Plugins/Connector" ) );
            pConf->Write ( _T ( "ViewType" ), m_iViewType );
            pConf->Write ( _T ( "ShowAtCursor" ), m_bShowAtCursor );
            pConf->Write ( _T ( "Opacity" ), m_iOpacity );

            pConf->Write ( _T ( "DialogPosX" ),   m_connector_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_connector_dialog_y );
			 pConf->DeleteGroup ( _T ( "/Plugins/Connector/DataSources" ) );
			 pConf->SetPath ( _T ( "/Plugins/Connector/DataSources" ) );
			 int cnt=m_DataSources.GetCount();
            pConf->Write ( _T ( "DataSources" ), cnt);
			if (m_DataSources.GetCount()> 0)
		{
			DataSource * d ;
			wxString s ;
			for (unsigned int i=0;i<m_DataSources.GetCount();i++)
			{
				d = m_DataSources.Item(i);
				s.Printf(wxT("%d"),d->Id);
				pConf->Write ( _T ( "Id") + s , (int)d->Id );
				pConf->Write ( _T ( "Port" + s),  d->port );
				pConf->Write ( _T ( "Proto" + s), (int) d->protocol );
				pConf->Write ( _T ( "Speed" + s), (int) d->speed );
			}
		}
			pConf->SetPath ( _T ( "/Directories" ) );
            pConf->Write ( _T ( "ConnectorDataLocation" ), m_connector_dir );

            return true;
      }
      else
            return false;
}

void connector_pi::ShowPreferencesDialog( wxWindow* parent )
{
      IntConnectorCfgDlg *dialog = new IntConnectorCfgDlg( parent);
      dialog->Fit(); 
      wxColour cl;
      GetGlobalColor(_T("DILG1"), &cl);
      dialog->SetBackgroundColour(cl);

      if(dialog->ShowModal() == wxID_OK)
      {

            SaveConfig();
      }
}

void connector_pi::St_init( DataSource* d )
{
	
d->open(d->port,d->speed);		
		
}

