#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <wx/wx.h>
enum prot { NMEA0183,NMEA2000,SEATALK} ;

class DataSource {

public:
	DataSource();
	~DataSource();
	unsigned int Id;
	wxString name;
	unsigned int speed ;
	unsigned int protocol;
	wxString port ;
	int status ;
	
};

#endif // DATASOURCE_H
