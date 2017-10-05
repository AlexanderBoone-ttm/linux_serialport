#include <stdlib.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <iostream>
#include <unistd.h>

#include "serialport.h"

#include <time.h>
using namespace std;



void sleep_ms(unsigned int ms);


int main(int argc,char** argv)
{

  string fn;
  for(int i=1; i<argc; ++i){
      fn += argv[i];
  }

  cout << fn << endl;


  cout << "sample open serial port ... "<< endl;
  Serialport sp;
  sp.fname = fn;
  sp.begin();

  //AC,80,BE,80,96,4D,53,53
  //AC 80 5B 90 E9, posicion pedal acelerador
  //AC,80,60,8C,E8, nivel de combustible

  //unsigned char buffer_out[3] = {0x80,0x60,0x8C};//,0x96,0x4D,0x53};//0x53};
  //char buffer_in[3];

//  write_port(fd, buffer_out, sizeof(buffer_out));
//  int bytes_read;
//  bytes_read = read(fd, buffer_in, 3); //stores data into byte_in. */

//  printf("%d bytes read \n",bytes_read);
//  cout<<buffer_in[0]<<endl;
//  cout<<buffer_in[1]<<endl;
//  cout<<buffer_in[2]<<endl;


  //test write  MSS+C+ trama can (12 bytes) + Checksum
  unsigned char buffer_out[17] = {'M','S','S','C',0x98,0xDA,0x10,0xF2,0x03,0x22,0xF4,0x0C,0x00,0x00,0x00,0x00,0x00};

  unsigned char cs=0;
  for(int i=0;i<16;i++){
      cs+=buffer_out[i];
  }
  cs= ~(cs);
  cs+=1;
  buffer_out[16] = cs;

  while(true){

      sp.write_port(buffer_out,sizeof(buffer_out));

      sleep(1);
  }

  sp.fileout.close();
  return 0;
}


void sleep_ms(unsigned int ms){
    struct timespec tim,tim2;
    tim.tv_nsec=1000000L;
    tim.tv_sec=0;

    for(unsigned int i=0;i<ms;i++){
        nanosleep(&tim,&tim2);
    }
}




