#include "ConnectorSourceDlg_impl.h"


wxArrayString *EnumerateSerialPorts(void);


IntConnectorSourceDlg::IntConnectorSourceDlg( wxWindow* parent )
:
ConnectorSourceDlg( parent )
{
	wxArrayString *pAvailablePorts;
	
	pAvailablePorts = EnumerateSerialPorts();
	m_choicePort->Clear();
	for (unsigned int iPortIndex=0 ; iPortIndex < pAvailablePorts->GetCount() ; iPortIndex++)
            m_choicePort->Append( pAvailablePorts->Item(iPortIndex) );
	m_choicePort->SetSelection(0);
      delete pAvailablePorts;
}

void IntConnectorSourceDlg::OnComSelected( wxCommandEvent& event )
{
// TODO: Implement OnComSelected
}

void IntConnectorSourceDlg::OnNetSelected( wxCommandEvent& event )
{
// TODO: Implement OnNetSelected
}

void IntConnectorSourceDlg::OnCancelClick( wxCommandEvent& event )
{
	this->Destroy();
}

void IntConnectorSourceDlg::OnOkClick( wxCommandEvent& event )
{
	this->Destroy();
}

wxArrayString *EnumerateSerialPorts(void)
{
      wxArrayString *preturn = new wxArrayString;

#ifdef __WXGTK__

      //    Looking for user privilege openable devices in /dev

      wxString sdev;

      for(int idev=0 ; idev < 8 ; idev++)
      {
            sdev.Printf(_T("/dev/ttyS%1d"), idev);

            int fd = open(sdev.mb_str(), O_RDWR|O_NDELAY|O_NOCTTY);
            if(fd > 0)
            {
                  /*  add to the output array  */
                  preturn->Add(wxString(sdev));
                  close(fd);
            }
      }

      for(int idev=0 ; idev < 8 ; idev++)
      {
            sdev.Printf(_T("/dev/ttyUSB%1d"), idev);

            int fd = open(sdev.mb_str(), O_RDWR|O_NDELAY|O_NOCTTY);
            if(fd > 0)
            {
                  /*  add to the output array  */
                  preturn->Add(wxString(sdev));
                  close(fd);
            }
      }

      //    Looking for BlueTooth GPS devices
      for(int idev=0 ; idev < 8 ; idev++)
      {
             sdev.Printf(_T("/dev/rfcomm%1d"), idev);

             int fd = open(sdev.mb_str(), O_RDWR|O_NDELAY|O_NOCTTY);
             if(fd > 0)
             {
                    /*  add to the output array  */
                    preturn->Add(wxString(sdev));
                    close(fd);
             }
      }



      //    A Fallback position, in case udev has failed or something.....
      if(preturn->IsEmpty())
      {
            preturn->Add( _T("/dev/ttyS0"));
            preturn->Add( _T("/dev/ttyS1"));
            preturn->Add( _T("/dev/ttyUSB0"));
            preturn->Add( _T("/dev/ttyUSB1"));
      }


#endif




#ifdef PROBE_PORTS__WITH_HELPER

/*
*     For modern Linux/(Posix??) systems, we may use
*     the system files /proc/tty/driver/serial
*     and /proc/tty/driver/usbserial to identify
*     available serial ports.
*     A complicating factor is that most (all??) linux
*     systems require root privileges to access these files.
*     We will use a helper program method here, despite implied vulnerability.
*/

char buf[256]; // enough to hold one line from serial devices list
char left_digit;
char right_digit;
int port_num;
FILE *f;

      pid_t pID = vfork();

      if (pID == 0)                // child
      {
//    Temporarily gain root privileges
            seteuid(file_user_id);

//  Execute the helper program
            execlp("ocpnhelper", "ocpnhelper", "-SB", NULL);

//  Return to user privileges
            seteuid(user_user_id);

            wxLogMessage(_T("Warning: ocpnhelper failed...."));
            _exit(0); // If exec fails then exit forked process.
       }


       wait(NULL);                  // for the child to quit

//    Read and parse the files

/*
      * see if we have any traditional ttySx ports available
*/
      f = fopen("/var/tmp/serial", "r");

      if (f != NULL)
      {
            wxLogMessage(_T("Parsing copy of /proc/tty/driver/serial..."));

            /* read in each line of the file */
            while(fgets(buf, sizeof(buf), f) != NULL)
            {
                  wxString sm(buf, wxConvUTF8);
                  sm.Prepend(_T("   "));
                  sm.Replace(_T("\n"), _T(" "));
                  wxLogMessage(sm);

                  /* if the line doesn't start with a number get the next line */
                  if (buf[0] < '0' || buf[0] > '9')
                        continue;

      /*
                  * convert digits to an int
      */
                  left_digit = buf[0];
                  right_digit = buf[1];
                  if (right_digit < '0' || right_digit > '9')
                        port_num = left_digit - '0';
                  else
                        port_num = (left_digit - '0') * 10 + right_digit - '0';

                  /* skip if "unknown" in the string */
                  if (strstr(buf, "unknown") != NULL)
                        continue;

                  /* upper limit of 15 */
                  if (port_num > 15)
                        continue;

                  /* create string from port_num  */

                  wxString s;
                  s.Printf(_T("/dev/ttyS%d"), port_num);

                  /*  add to the output array  */
                  preturn->Add(wxString(s));

            }

            fclose(f);
      }


/*
      * Same for USB ports
*/
      f = fopen("/var/tmp/usbserial", "r");

      if (f != NULL)
      {
            wxLogMessage(_T("Parsing copy of /proc/tty/driver/usbserial..."));

            /* read in each line of the file */
            while(fgets(buf, sizeof(buf), f) != NULL)
            {

                  wxString sm(buf, wxConvUTF8);
                  sm.Prepend(_T("   "));
                  sm.Replace(_T("\n"), _T(" "));
                  wxLogMessage(sm);

                  /* if the line doesn't start with a number get the next line */
                  if (buf[0] < '0' || buf[0] > '9')
                        continue;

      /*
                  * convert digits to an int
      */
                  left_digit = buf[0];
                  right_digit = buf[1];
                  if (right_digit < '0' || right_digit > '9')
                        port_num = left_digit - '0';
                  else
                        port_num = (left_digit - '0') * 10 + right_digit - '0';

                  /* skip if "unknown" in the string */
                  if (strstr(buf, "unknown") != NULL)
                        continue;

                  /* upper limit of 15 */
                  if (port_num > 15)
                        continue;

                  /* create string from port_num  */

                  wxString s;
                  s.Printf(_T("/dev/ttyUSB%d"), port_num);

                  /*  add to the output array  */
                  preturn->Add(wxString(s));

            }

            fclose(f);
      }


      //    As a fallback, in case seteuid doesn't work....
      //    provide some defaults
      //    This is currently the case for GTK+, which
      //    refuses to run suid.  sigh...

      if(preturn->IsEmpty())
      {
            preturn->Add( _T("/dev/ttyS0"));
            preturn->Add( _T("/dev/ttyS1"));
            preturn->Add( _T("/dev/ttyUSB0"));
            preturn->Add( _T("/dev/ttyUSB1"));
      }

//    Clean up the temporary files created by helper.
      pid_t cpID = vfork();

      if (cpID == 0)                // child
      {
//    Temporarily gain root privileges
            seteuid(file_user_id);

//  Execute the helper program
            execlp("ocpnhelper", "ocpnhelper", "-U", NULL);

//  Return to user privileges
            seteuid(user_user_id);
            _exit(0); // If exec fails then exit forked process.
      }

#endif      // __WXGTK__

#ifdef __WXOSX__
#include "macutils.h"
      char* paPortNames[MAX_SERIAL_PORTS] ;
      int iPortNameCount ;

      memset(paPortNames,0x00,sizeof(paPortNames)) ;
      iPortNameCount = FindSerialPortNames(&paPortNames[0],MAX_SERIAL_PORTS) ;
      for (int iPortIndex=0 ; iPortIndex<iPortNameCount ; iPortIndex++)
      {
            wxString sm(paPortNames[iPortIndex], wxConvUTF8);
            preturn->Add(sm);
            free(paPortNames[iPortIndex]) ;
      }
#endif      //__WXOSX__


#ifdef __WXMSW__
/*************************************************************************
 * Windows provides no system level enumeration of available serial ports
 * There are several ways of doing this.
 *
 *************************************************************************/

#include <windows.h>



      //    Method 1:  Use GetDefaultCommConfig()
      // Try first {g_nCOMPortCheck} possible COM ports, check for a default configuration
      for (int i=1; i<g_nCOMPortCheck; i++)
      {
            wxString s;
            s.Printf(_T("COM%d"), i);

            COMMCONFIG cc;
            DWORD dwSize = sizeof(COMMCONFIG);
            if (GetDefaultCommConfig(s.fn_str(), &cc, &dwSize))
                  preturn->Add(wxString(s));
      }


#if 0
      // Method 2:  Use FileOpen()
      // Try all 255 possible COM ports, check to see if it can be opened, or if
      // not, that an expected error is returned.

      BOOL bFound;
      for (int j=1; j<256; j++)
{
      char s[20];
      sprintf(s, "\\\\.\\COM%d", j);

          // Open the port tentatively
      BOOL bSuccess = FALSE;
      HANDLE hComm = ::CreateFile(s, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);

            //  Check for the error returns that indicate a port is there, but not currently useable
      if (hComm == INVALID_HANDLE_VALUE)
      {
            DWORD dwError = GetLastError();

            if (dwError == ERROR_ACCESS_DENIED ||
                dwError == ERROR_GEN_FAILURE ||
                dwError == ERROR_SHARING_VIOLATION ||
                dwError == ERROR_SEM_TIMEOUT)
                  bFound = TRUE;
      }
      else
      {
            bFound = TRUE;
            CloseHandle(hComm);
      }

      if (bFound)
            preturn->Add(wxString(s));
}
#endif

//    Search for Garmin device driver on Windows platforms

      HDEVINFO hdeviceinfo = INVALID_HANDLE_VALUE;


      hdeviceinfo = SetupDiGetClassDevs( (GUID *) &GARMIN_DETECT_GUID,
                                                      NULL, NULL,
                                                      DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);

      if (hdeviceinfo != INVALID_HANDLE_VALUE)
      {
            wxLogMessage(_T("EnumerateSerialPorts() Found Garmin USB Driver."));
            preturn->Add(_T("GARMIN"));         // Add generic Garmin selectable device
            g_bGarminPersistance = true;        // And record the existance
      }

#if 0
    SP_DEVICE_INTERFACE_DATA deviceinterface;
    deviceinterface.cbSize = sizeof(deviceinterface);

    if (SetupDiEnumDeviceInterfaces(hdeviceinfo,
                                                      NULL,
                                                      (GUID *) &GARMIN_DETECT_GUID,
                                                      0,
                                                      &deviceinterface))
      {
            wxLogMessage(_T("Found Garmin Device."));

            preturn->Add(_T("GARMIN"));         // Add generic Garmin selectable device
            g_bGarminPersistance = true;        // And record the existance

      }
#endif

#endif      //__WXMSW__

      return preturn;
}
