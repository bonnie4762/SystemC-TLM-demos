//
//  testbench.cpp
//  scLab
//
//  Created by bonnie on 01/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "testbench.h"

//these are the two processes to generate stimuli for OR gate

void driver::drivea(){
    d_a.write(~d_a);
    next_trigger(5, SC_NS);
}

void driver::driveb(){
    d_b.write(~d_b);
    next_trigger(10, SC_NS);
}

void monitor::prc_monitor(){
    cout<<"AT"<<sc_simulation_time()<<"input is: ";
    cout<<m_a<<","<<m_b<<" output is: "<<m_c<<endl;
}
