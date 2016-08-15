//
//  Edge.cpp
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/9/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "Equation.h"

using namespace std;

Edge::Edge(){
    //base constructor just set srt and end point to any vertex
    this->startPoint = Vertex();
    this->endPoint = Vertex();
}

Edge::Edge(Vertex srt, Vertex end){
    // sets start point to srt and end point to end
    this->startPoint = srt;
    this->endPoint = end;
    this->eqtn = Equation(srt, end);
}
//prints an edge
void Edge::printEdge(){
    cout << "(" << startPoint.getXPos() << " , " << startPoint.getYPos() << ")" <<
    "(" << endPoint.getXPos() << " , " << endPoint.getYPos()<< ")" << endl;
}