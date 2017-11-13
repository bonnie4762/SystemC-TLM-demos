//
//  main.cpp
//  lab2_ram
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "systemc.h"
#include "ram.h"
#include <string>
using namespace std;
#include <iomanip>

#define SIZE 2048

int sc_main (int argc, char * argv[]) {
    sc_signal<sc_uint<8>> t_data;
    sc_signal<sc_uint<32>> t_addr;
    sc_signal<bool> t_ce;
    sc_signal<bool> t_we;
    
    
    sc_clock clk;
    

    ram r1("r1", SIZE);
    
    
    r1.clk(clk);
    r1.data(t_data);
    r1.addr(t_addr);
    r1.ce(t_ce);
    r1.we(t_we);

    
    // test initialization
    sc_start(100, SC_NS);

    
    
    t_ce.write(true);
    t_we.write(false);
    
    

    
    const char filename1[] = "/Users/bonnie/Desktop/system design language/lab2/files/T1.txt";
    ifstream file1(filename1);
    sc_uint<32> addr;
    string data;
    cout<<"test report: ram initialization"<<endl;
    cout<<setw(15)<<"Address_of_mismatch"<<setw(15)<<"File_data"<<setw(15)<<"Memory_data"<<endl;
    while(!file1.eof()){
        file1>>addr>>data;
        t_addr.write(addr);
        sc_start(2, SC_NS);
        string ram_data = t_data.read().to_string(SC_HEX_SM, false);
        
        unsigned int data_i;
        unsigned int ram_data_i;
        sscanf(data.c_str(), "%x", &data_i);
        sscanf(ram_data.c_str(),"%x", &ram_data_i);
         
        if(ram_data_i!=data_i)
            cout<<setw(15)<<addr<<setw(15)<<data<<setw(15)<<ram_data<<endl;
        
        
    }
    file1.close();
    
    // test read and write operations
    
    
    //t_ce.write(false);
    t_we.write(true);
    const char filename2[] = "/Users/bonnie/Desktop/system design language/lab2/files/T2.txt";
    ifstream file2(filename2);
    while(!file2.eof()){
        file2>>addr>>data;
        t_addr.write(addr);
        t_data.write(("0x"+data).c_str());
        sc_start(2, SC_NS);
    }
    
    t_we.write(false);
    file2.clear();
    file2.seekg(0, ios::beg);
    cout<<"test report: ram read and write"<<endl;
    cout<<setw(15)<<"Address_of_mismatch"<<setw(15)<<"File_data"<<setw(15)<<"Memory_data"<<endl;
    while(!file2.eof()){
        file2>>addr>>data;
        t_addr.write(addr);
        sc_start(2, SC_NS);
        string ram_data = t_data.read().to_string(SC_HEX_SM, false);
        
         unsigned int data_i;
         unsigned int ram_data_i;
         sscanf(data.c_str(), "%x", &data_i);
         sscanf(ram_data.c_str(),"%x", &ram_data_i);
         
        
        if(ram_data_i!=data_i)
            cout<<setw(15)<<addr<<setw(15)<<data<<setw(15)<<ram_data<<endl;
    }
    
    file2.close();

    
    

    

    
    
    return 0;
}

