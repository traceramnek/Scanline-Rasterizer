//
//  Vertex.h
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/17/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include <iostream>
#include <stdio.h>

class Vertex{
private:
    float x, y;
public:
    //constructors
    Vertex();
    Vertex(float xVal, float yVal);
    
    float getXPos(); // return x Coor
    float getYPos(); // return y Coor
    void setXPos(float scrnX); // set x Coor
    void setYPos(float scrnY); // set y Coor
    void printVertex();
};

#endif /* Vertex_h */

