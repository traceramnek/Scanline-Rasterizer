//
//  ScanlineRasterizer.h
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/9/16.
//  Copyright (c) 2016 Kwan Holloway. All rights reserved.
//

#ifndef ScanlineRaster_ScanlineRasterizer_h
#define ScanlineRaster_ScanlineRasterizer_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "Vertex.h"
#include "Edge.h"
#include "Equation.h"

using namespace std;


class ScanlineRasterizer{
public:
    int nx; // new x, passed as arg
    int ny; // new y, passed as arg
    
    
    //iterators
    vector<Vertex>::const_iterator iterV;
    // 2D array of chars for frame buffer
    char ** frameBuffer;
    
    //vector<vector<char>> frameBuffer;
    //2D vector that stores intersections
    vector<vector<float>> intersections;
    // vector representing the vertices that will be read in
    vector<Vertex> vertices;
    //vector holding all edges
    vector<Edge> edges;
    ScanlineRasterizer(int nx, int ny);
    void rasterize(const string& filename);//given a filename, read in its vertices and rasterize into frame buffer member variable
    
    void viewport(Vertex &vrt);// Takes a vertex in canonical and returns the screen position
    void findIntersections(vector<vector<float>> &intersections); // find intersectoins with edge and store in array
    void sortInSects(vector<vector<float>> &intersections); // sorts intersections in ascending order
    void printInters(vector<vector<float>> intersections); // prints intersections: for testing
    void roundInters(vector<vector<float>> intersections); // rounds each point accordingly
    void print();//print the contents of the frame buffer
    
    
};

#endif
