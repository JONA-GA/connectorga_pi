#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <wx/wx.h>
#include <boost/shared_ptr.hpp>

enum prot { NMEA0183,NMEA2000,SEATALK} ;

class DataSourceImpl;

class DataSource {

public:

	unsigned int Id;
	wxString name;
	unsigned int speed ;
	unsigned int protocol;
	wxString port ;
	int status ;
	
	/**
     * Default constructor
     */
	DataSource();
	
	DataSource(wxString devname, unsigned int baudrate);
	
    /**
     * Opens a serial port
     * \param devname port name, like "/dev/ttyUSB0" or "COM4"
     * \param baudrate port baud rate, example 115200
     * Format is 8N1, flow control is disabled.
     */
    void open(wxString devname, unsigned int baudrate);

    /**
     * Closes a serial port.
     */
    void close();

    /**
     * \return true if the port is open
     */
    bool isOpen();

    /**
     * \return true if any error
     */
    bool errorStatus();

    /**
     * Write a string to the serial port
     */
    void write(wxString data);

    /**
     * Destructor
     */
    ~DataSource();
	
	
	
	private:
    /**
     * Called when data is received
     */
    void readCallback(const char *data, size_t size);

    boost::shared_ptr<DataSourceImpl> pimpl; ///< Pimpl idiom
	
};



#endif // DATASOURCE_H
