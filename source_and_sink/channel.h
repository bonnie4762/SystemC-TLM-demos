//
//  channel.h
//  scLab
//
//  Created by bonnie on 26/09/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef channel_h
#define channel_h

#include "systemc.h"


class w_if : virtual public sc_interface
{
public:
    virtual void write(char c) = 0;
};

class r_if : virtual public sc_interface
{
public:
    virtual char read() = 0;
};


class channel : public sc_module, public w_if, public r_if
{

public:
    channel(sc_module_name name): sc_module(name){
        data = new char[100];
        w=r=n=0;
    }
    void write(char c);
    char read();
    
private:
    char *data;
    int w, r, n;
};

#endif

