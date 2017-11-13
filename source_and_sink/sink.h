// file name = sink.h
#ifndef sink_h
#define sink_h

#include"systemc.h"
#include"channel.h"
class sink : public sc_module
{
   public:
     sc_fifo_in<char> in;

     SC_HAS_PROCESS(sink);

    sink(sc_module_name name) : sc_module(name)
     {
      SC_THREAD(sink_p);
     }

     void sink_p();
};



#endif
