//
//  main.cpp
//  scLab
//
//  Created by bonnie on 02/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//


#include "testbench.h"
#include "or_gate.h"
#include "systemc.h"

int sc_main(int argc, char *argv[]){
    
    sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);
    
    
    sc_signal<sc_bit> t_a, t_b, t_c; // signals used to connect all the modules
    
    or_gate g1("g1");
    driver d1("d1");
    monitor m1("m1");
    
    g1.a(t_a);
    g1.b(t_b);
    g1.c(t_c);
    
    d1.d_a(t_a);
    d1.d_b(t_b);
    
    m1.m_a(t_a);
    m1.m_b(t_b);
    m1.m_c(t_c);
    
    
    
    
    /* module instantiation using pointers

     or_gate *g1;
     g1 = new or_gate("g1");
     driver *d1;
     d1 = new driver("d1");
     monitor *m1;
     m1 = new monitor("m1");
     */
    
    /*
     g1->a(t_a);
     g1->b(t_b); // name binding
     g1->c(t_c);
     
     d1->d_a(t_a);
     d1->d_b(t_b);
     
     m1->m_a(t_a);
     m1->m_b(t_b);
     m1->m_c(t_c);
     */
    
    /*
     
     (*g1)(t_a, t_b, t_c);
     (*d1)(t_a, t_b);      // positional binding
     (*m1)(t_a, t_b, t_c);
     
     */
    
    
    sc_start(100, SC_NS); // starts the simulation and run for 20ns
    
    return 0; // return on success
}
 
