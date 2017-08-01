#include <stdlib.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#include <iostream>
using namespace std;

#define SERIAL_DEVICE "/dev/ttyACM0"


int open_port(void);
int configure_port(int fd);


int main(int argc,char** argv)
{ 
  int fd;
  cout << "sample open serial port ... "<< endl;
  fd = open_port();
  configure_port(fd);



  while(true){

  }
  close(fd);

  return 0;
}


int open_port(void) {
  
  int fd; /* File descriptor for the port */
  fd = open(SERIAL_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */

    perror("open_port: Unable to open port - ");
  }else{
    cout<<"open port success!\n"<<endl;	
    fcntl(fd, F_SETFL, 0);
  }
  
  return (fd);
}


int configure_port(int fd)      // configure the port
{
	struct termios port_settings;      // structure to store the port settings in

	cfsetispeed(&port_settings, B9600);    // set baud rates
	cfsetospeed(&port_settings, B9600);

	port_settings.c_cflag &= ~PARENB;    // set no parity, stop bits, data bits
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;
	
	tcsetattr(fd, TCSANOW, &port_settings);    // apply the settings to the port
	return(fd);

} //configure_port
