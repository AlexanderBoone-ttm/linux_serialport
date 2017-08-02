#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <pthread.h>
#include <fstream>
#include <string>

class Serialport
{
public:
    Serialport();

    void begin();
    void write_port(const char* msg, int len);

    std::string fname;
    std::ofstream fileout;

private:
    int fd;
    pthread_t _readport;

    int open_port(void);
    void close_port(void);

    //void write_port(int fd, const char* msg,int len);

    static void* read_thread(void* i);
    void* readport();
    void readbytesPort(unsigned char* buf_in, int len);


};

#endif // SERIALPORT_H
