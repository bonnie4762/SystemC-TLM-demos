//
//  ram.cpp
//  lab2_ram
//
//  Created by bonnie on 04/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "ram.h"
#include <fstream>
#include <string>
#include <iostream>
#include "systemc.h"
using namespace std;

void ram::init(){
    const char filename[] = "/Users/bonnie/Desktop/system design language/lab2/files/T1.txt";
    ifstream file(filename);
    sc_uint<32> addr;
    string data;
    while(!file.eof()){
        file>>addr>>data;
        data = "0x"+data;
        if(addr >= size)
            SC_REPORT_ERROR(0, "address out of range!");
        else
            memory[addr] = data.c_str();
    }
    file.close();
    /*
    int i;
    for(i=0; i<size;i++){
        cout<<i<<","<<memory[i].to_string(SC_HEX_SM, false)<<endl;
    }
     */
    

}


void ram::ram_p(){
    // detect out-of-range addr
    if(addr.read()>=size)
        SC_REPORT_ERROR(0, "address out of range!");
    
    else if(we){
        //write operation.
        if(ce)
            memory[addr.read()] = data.read();
            
    }
    else{
        //read operation.
        if(ce){
            data.write(memory[addr.read()]);
        }
        else
            data.write("0xFF");
    }
    
}
