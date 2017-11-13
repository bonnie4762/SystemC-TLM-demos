// file name = sink.cpp

#include"sink.h"
#include<cctype>
void sink :: sink_p()
     {
       char c;
       cout << endl << endl;
	
       while (true) 
       {
         c = in->read();
	     c=(char)toupper(c);
         cout << c << flush;
       }
     }
