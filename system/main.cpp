//
//  main.cpp
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "systemc.h"
#include "testbench.h"
#include "change_case.h"
#include "filter.h"
#include "m_bus.h"
#include "arbiter.h"


int sc_main(int argc, char *argv[]){
    sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);
    
    
    sc_signal<char> t_d;
    sc_signal<char> t_c;
    sc_signal<char> t_f;
    sc_signal<int> t_a;
    sc_clock clk("clk");
    sc_buffer<char> uart("uart");
    
    
    driver d1("d1");
    monitor m1("m1");
    change_case c1("c1");
    filter f1("f1");
    arbiter a1("a1");
    m_bus b1("b1");
    
    
    d1.d_char(t_d);
    c1.c_in(t_d);
    c1.c_out(t_c);
    f1.f_in(t_d);
    f1.f_out(t_f);
    a1.clk(clk);
    a1.a_out(t_a);

    b1.c_m_in(t_c);
    b1.f_m_in(t_f);
    b1.a_m_in(t_a);
    b1.m_out(uart);
    
    m1.m_char(uart);
    
    sc_start(5000, SC_NS);

    
    return 0;
}









