#include "data_source.h"
#include "AsyncSerial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void received(const char *data, unsigned int len);

class DataSourceImpl
{
public:
    CallbackAsyncSerial serial;
    wxString receivedData;
};

/**
 * Implementation details of DataSource class.
 */
DataSource::DataSource():pimpl(new DataSourceImpl)

{
	this->speed=9600 ;
	this->protocol=1;
	this->status=0;
}
DataSource::DataSource(wxString devname, unsigned int baudrate)
        : pimpl(new DataSourceImpl)
{
    open(devname,baudrate);
}

void DataSource::open(wxString devname, unsigned int baudrate)
{
    try {
		wxCharBuffer buf = devname.ToUTF8() ;
        pimpl->serial.open(buf.data(),baudrate,boost::asio::serial_port_base::parity(
                boost::asio::serial_port_base::parity::even),
	boost::asio::serial_port_base::character_size(8),
	boost::asio::serial_port_base::flow_control(
                boost::asio::serial_port_base::flow_control::none),
	boost::asio::serial_port_base::stop_bits(
                boost::asio::serial_port_base::stop_bits::one));
    } catch(boost::system::system_error&)
    {
        //Errors during open
    }
    pimpl->serial.setCallback(bind(&DataSource::readCallback,this, _1, _2));
}

void DataSource::close()
{
    pimpl->serial.clearCallback();
    try {
        pimpl->serial.close();
    } catch(boost::system::system_error&)
    {
        //Errors during port close
    }
    pimpl->receivedData.clear();//Clear eventual data remaining in read buffer
}

bool DataSource::isOpen()
{
    return pimpl->serial.isOpen();
}

bool DataSource::errorStatus()
{
    return pimpl->serial.errorStatus();
}

void DataSource::write(wxString data)
{
	wxCharBuffer buf = data.ToUTF8() ;
    pimpl->serial.writeString(buf.data());
}

DataSource::~DataSource()
{
    pimpl->serial.clearCallback();
    try {
        pimpl->serial.close();
    } catch(...)
    {
        //Don't throw from a destructor
    }
}

void DataSource::readCallback(const char *data, size_t size)
{
    received(data,size);
}