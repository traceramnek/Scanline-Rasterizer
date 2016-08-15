//
//  Vertex.cpp
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/9/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Vertex.h"

using namespace std;
// default constructor
Vertex::Vertex(){
    this->x = 1;
    this->y = 1;
}
//constructor
Vertex::Vertex(float xVal, float yVal){
    this->x = xVal;
    this->y = yVal;
}

float Vertex::getXPos() {  return x;  } // return x Coor

float Vertex::getYPos() {  return y;  } // return y Coor

void Vertex::setXPos(float scrnX){ // set x Coor
    this->x = scrnX;
}
void Vertex::setYPos(float scrnY){ // set y Coor
    this->y = scrnY;
}

//prints a vertex
void Vertex::printVertex(){
    cout << "(" << x << "," << y << ")" << endl;
}