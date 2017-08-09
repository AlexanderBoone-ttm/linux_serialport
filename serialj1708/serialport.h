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
    volatile unsigned int flag_packet_end;
    volatile unsigned int flag_idle;
    volatile unsigned int count_times;// 100us, 10 times
    unsigned char endp[3];

    int fd;
    pthread_t _readport;
    pthread_t _idle_time;

    int open_port(void);
    void close_port(void);

    //void write_port(int fd, const char* msg,int len);

    static void* read_thread(void* i);
    void* readport();
    void readbytesPort(unsigned char* buf_in, int len);

    static void* idle_get(void* i);
    void* idle_timer();


};

#endif // SERIALPORT_H
