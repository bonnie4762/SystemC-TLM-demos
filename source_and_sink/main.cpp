//
//  main.cpp
//  scLab
//
//  Created by bonnie on 26/09/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//


#include "sink.h"
#include "source.h"
#include "systemc.h"
#include "channel.h"

int sc_main(int argc, char *argv[]){
    
    sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);
    
    
    //channel c1("c1");
    sc_fifo<char> c1("c1");
    sink sink1("sink1");
    source source1("source1");
    
    sink1.in(c1);
    source1.out(c1);
    
    sc_start(100, SC_NS);
    
    return 0;
    
    
}
