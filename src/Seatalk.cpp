#include "AsyncSerial.h"
#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "connector_pi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wx/string.h>
#include "cnmea0183/nmea0183.h"
using namespace std;
using namespace boost;


wxString recu ;
CallbackAsyncSerial serial;
 unsigned long vent ;
CNMEA0183 cm_nmea;

void stk(char tre[255])
{
	float t;
	SENTENCE snt ;
	wxString unit;
	wxString tk;
	
switch (tre[0])
{
		case 0x27 :
			t =  (float)((tre[3]*256 +(unsigned char) tre[2])-100)/10 ;
			cm_nmea.Mtw.Empty();
			cm_nmea.Mtw.Temperature= t;
			unit = wxT("C");
			cm_nmea.Mtw.UnitOfMeasurement = unit;
			tk = wxT("EC");
			cm_nmea.TalkerID= tk ;
			cm_nmea.Mtw.Write(snt);
			PushNMEABuffer(snt.Sentence);
			break;
		case 0x10 : // ApW direction
			vent =  (unsigned long)((tre[2]*256 +(unsigned char) tre[3]))/2 ;
		break;
		case 0x11 : // ApW direction
		//(XX & 0x7F) + Y/10 Knots
			t =  (float)((tre[2]& 0x7F) +((unsigned char) tre[3]/10)) ;
			cm_nmea.Mwv.Empty();
			cm_nmea.Mwv.WindAngle= vent;
			unit = wxT("R");
			cm_nmea.Mwv.Reference = unit;
			cm_nmea.Mwv.WindSpeed= t;
			if ((tre[2]& 0x80) ==0)cm_nmea.Mwv.WindSpeedUnits= wxT("K");
			cm_nmea.Mwv.IsDataValid = NTrue;
			tk = wxT("EC");
			cm_nmea.TalkerID= tk ;
			cm_nmea.Mwv.Write(snt);
			PushNMEABuffer(snt.Sentence);
		break;
		default:
		break;
			
		
} // end switch
}
void seatalk(unsigned char d, bool cde)   
{
	static unsigned int cpt;
	static int len ;
	static char tr[255];
	int i;
	static bool b=false ;
	char hex[]="0123456789ABCDEF";
	
	if (cde)
	{ 
		cpt = 255;
		tr[0]= d;
		b= true ;
	}else
	{
	if (b){
		if (cpt == 254)	{
			len = (d & 0x0f)+2;
			cpt = len;
			}
		tr[(len -cpt)+1]= d ;
		}	
	}
	if ( !--cpt and b ){
		recu += wxString::FromAscii('\r' );
		recu += wxString::FromAscii('\n' );
		for (i=0;i<=len;i++){
				recu += wxString::FromAscii(hex[tr[i] >>  4]); /* Convert Data to hex */
				recu += wxString::FromAscii(hex[tr[i] & 0x0f]);
				recu += wxString::FromAscii( ' ');
		}
		stk(tr);
		b=false; //debug
	} ; // commande complete
}
	
	/* Function to get parity of number n. It returns 1
   if n has odd parity, and returns 0 if n has even
   parity */
	
bool getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n      = n & (n - 1);
    }
    return !parity;
}

// 
// callback receive data

void received(const char *data, unsigned int len)
{
	vector< unsigned char > v(data,data+len);
	
    for(unsigned int i=0;i<v.size();i++)
    {
      if ((v[i]== 0xff) & (v[i+1]== 0x00) ) /*  erreur parity impaire */
	  { 
		  if ( getParity(v[i+2]) )
		  { // even cde
				seatalk(v[i+2],1);
			  }else 
				  { //odd data
				seatalk(v[i+2],0);
					  }
		  i++;
		  i++;
		  }else //pas d'erreur parity paire
		{
		if ( getParity(v[i])) 
		  { // even data
				seatalk(v[i],0);
			  }else 
				  { //odd cde
					seatalk(v[i],1);
					  }
		}
    }
}

void St_init( DataSource d )
{
	
	
	CallbackAsyncSerial serial((const char*)d.port.mb_str(),4800,
	boost::asio::serial_port_base::parity(
                boost::asio::serial_port_base::parity::even),
	boost::asio::serial_port_base::character_size(8),
	boost::asio::serial_port_base::flow_control(
                boost::asio::serial_port_base::flow_control::none),
	boost::asio::serial_port_base::stop_bits(
                boost::asio::serial_port_base::stop_bits::one));
			
	serial.setCallback(received);	
	sleep(1); //bad workaround to avoid false start
	
	
	if(serial.errorStatus() || serial.isOpen()==false)
		{
			//a =boost::system::error_code&.category().name();
			wxString s = wxString::FromAscii("*** erreur ou port fermé \n") ;
			//m_textCtrl1->AppendText(s);
			serial.open("/dev/ttyS0",4800,
			boost::asio::serial_port_base::parity(
                boost::asio::serial_port_base::parity::even),
			boost::asio::serial_port_base::character_size(8),
			boost::asio::serial_port_base::flow_control(
                boost::asio::serial_port_base::flow_control::none),
			boost::asio::serial_port_base::stop_bits(
                boost::asio::serial_port_base::stop_bits::one));
			serial.setCallback(received);
			}
		
}

