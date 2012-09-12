/******************************************************************************
 * $Id: connector_pi.h,v 1.0 2011/02/26 01:54:37 nohal Exp $
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

#ifndef _CONNECTORPI_H_
#define _CONNECTORPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/fileconf.h>

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    1

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    6

#include "ocpn_plugin.h"
#include "data_source.h"
#include <wx/dynarray.h>

WX_DECLARE_OBJARRAY(DataSource, ArrayOfDataSources);
#include "ConnectorCfgDlg_impl.h"
#include "ConnectorSourceDlg_impl.h"
#include "StatusDlg_impl.h"
//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define CONNECTOR_TOOL_POSITION    -1          // Request default positioning of toolbar tool

class connector_pi : public opencpn_plugin_16
{
public:
      connector_pi(void *ppimgr);
	   ~connector_pi(void);
	   
//    The required PlugIn Methods
      int Init(void);
      bool DeInit(void);

      int GetAPIVersionMajor();
      int GetAPIVersionMinor();
      int GetPlugInVersionMajor();
      int GetPlugInVersionMinor();
      wxBitmap *GetPlugInBitmap();
      wxString GetCommonName();
      wxString GetShortDescription();
      wxString GetLongDescription();

//    The required override PlugIn Methods
      int GetToolbarToolCount(void);
      void ShowPreferencesDialog( wxWindow* parent );

      void OnToolbarToolCallback(int id);

//    Optional plugin overrides
      void SetColorScheme(PI_ColorScheme cs);

//    Other public methods
      void SetConnectorDialogX    (int x){ m_connector_dialog_x = x;};
      void SetConnectorDialogY    (int x){ m_connector_dialog_y = x;}

      void OnConnectorDialogClose();

private:
      wxFileConfig     *m_pconfig;
      wxWindow         *m_parent_window;
      bool              LoadConfig(void);
      bool              SaveConfig(void);

      ConnectorCfgDlg      *m_pConnectorDialog;
	  
      int               m_connector_dialog_x, m_connector_dialog_y;
      int               m_display_width, m_display_height;
      int               m_iViewType;
      bool              m_bShowAtCursor;
      int               m_iOpacity;

      int               m_leftclick_tool_id;

      wxString          m_connector_dir;
};

#endif
