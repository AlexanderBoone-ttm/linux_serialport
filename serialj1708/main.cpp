#include <stdlib.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <iostream>
#include <unistd.h>

#include "serialport.h"

using namespace std;


int main(int argc,char** argv)
{

  cout << "sample open serial port ... "<< endl;
  Serialport sp;
  sp.begin();

  char buffer_out[3] = {'a','b','c'};
  //char buffer_in[3];

//  write_port(fd, buffer_out, sizeof(buffer_out));
//  int bytes_read;
//  bytes_read = read(fd, buffer_in, 3); //stores data into byte_in. */

//  printf("%d bytes read \n",bytes_read);
//  cout<<buffer_in[0]<<endl;
//  cout<<buffer_in[1]<<endl;
//  cout<<buffer_in[2]<<endl;

  while(true){

      //sp.write_port(buffer_out,sizeof(buffer_out));
     // sleep(1);
  }

  return 0;
}






