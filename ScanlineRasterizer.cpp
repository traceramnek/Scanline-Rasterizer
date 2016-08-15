//
//  ScanlineRasterizer.cpp
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/9/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ScanlineRasterizer.h"
#include "Vertex.h"
#include "Edge.h"
#include "Equation.h"
#include <math.h>

using namespace std;

ifstream fin; // used to read in from file

/*
 Initializes nx, ny and frame buffer
 */
ScanlineRasterizer::ScanlineRasterizer(int nwx, int nwy){
    //initalize nx and ny with args passed from command line
    this->nx = nwx;
    this->ny = nwy;
    
    //get array of size ny where each entry is another array of size nx
    frameBuffer = new char *[ny];
    for (int i = 0; i < ny; i++){
        frameBuffer[i] = new char[nx];
    }
    
    
    //inittalize all values in frame buffer to BG color '-'
    for (int i = 0; i < ny; i++)
    {
        for (int j = 0; j < nx;j++)
        {
            frameBuffer[i][j] = '-';
        }
    }
    

}
/*
 Takes a filename and rasterizes the polygon onto the screen
 */
void ScanlineRasterizer::rasterize(const string& filename){
    
    //2D vector that stores intersections
    vector<vector<float>> intersections1(ny,vector<float>());
    
    float xCor, yCor;// variables to red in x and Y coor
    fin.open(filename.c_str());// open file
    
    if(fin.fail()){ // file isn't opened for some reason
        cout << "*** Error: File Not Found or File Cannot Be Opened ***" << endl;
        // end the program
        exit(1);
    }
    
    //Read in all vertices
    while(!fin.eof()){// while not at end of file
        Vertex temp;
        fin>> xCor; //read in X
        fin >> yCor; // read in Y
    
        // viewport new Vertex and add on end of Vector
        temp = Vertex(xCor,yCor);
        viewport(temp);
        vertices.push_back(temp);
    }

    //Assemble edges from each pair fo vertices
    for (int i = 0; i < vertices.size(); i+=2){
        if(i != vertices.size()-1){
            edges.push_back(Edge(vertices.at(i), vertices.at(i+1)));
        }
        else{
            //edge between last vertex and first
            edges.push_back(Edge(vertices.at(i), vertices.at(0)));
        }
    }

    //find intersections and sort them and round them
    findIntersections(intersections1);
    sortInSects(intersections1);
    roundInters(intersections1);
    //set member variable to local so it can be used in print
    intersections = intersections1;
    
    fin.close(); // close the file
    
}
/*
 Finds all intersections with each edge and stores them
 */
void ScanlineRasterizer::findIntersections(vector<vector<float>> &intersections){
    int xInter = 0; // x intersect
    int edLrg = 0, edSml =0; // edge start point and end point
    int temp;
    // go thorugh all y values
    for(int i = 0; i <= ny-1; i ++){
         // go through all edges for each y value
        for(int e = 0; e < edges.size(); e++){
            
            edLrg = edges[e].startPoint.getXPos();
            edSml = edges[e].endPoint.getXPos();
            
            if(edSml > edLrg) { // swap them if edSml is bigger then edLrg
                temp = edLrg;
                edLrg = edSml;
                edSml = temp;
            }
            
            // find x intersection
            xInter = edges[e].eqtn.solveXImp(i);
            //check if Xinter is a valid interesection
            if((xInter > edSml && xInter < edLrg) && (xInter >= 0 && xInter < nx)){
                //add x intercept if it is a valid intersection
                intersections[i].push_back(xInter);
            }
        }
    }
    
}

/*
 Applies the viewport transformation to each vertex
*/
void ScanlineRasterizer::viewport(Vertex &vrt){
    float scrX = vrt.getXPos(); // vertex's X coor
    float scrY = vrt.getYPos(); // vertex's Y coor
    
    //actual viewport trnasformations
    scrX = scrX *(nx/2.0) + ((nx-1)/2.0);
    scrY = scrY *(ny/2.0) + ((ny-1)/2.0);
    
    //set vertex's coordinates to new screen coodinates
    vrt.setXPos(scrX);
    vrt.setYPos(scrY);
}
/*
 Sorts intersections in ascending order
 */
void ScanlineRasterizer::sortInSects(vector<vector<float>> &intersections){
    for(int y = 0; y < ny; y ++){
        // For each y-value(scanline) sort the intersections by x-value in ascending order
        sort(intersections[y].begin(), intersections[y].end());
    }
}

/*
 Prints out all intersections: Used for testing
*/
void ScanlineRasterizer::printInters(vector<vector<float>> intersections){
    
    for( int y = 0; y < intersections.size(); y++){
        
        if(intersections[y].size() > 0){
            cout << " There are " << intersections[y].size() << " intersections at y = " << y << endl;
            for(int i = 0; i < intersections[y].size(); i++){
                cout << intersections[y][i] << endl;
            }
        }
    }
}

void ScanlineRasterizer::roundInters(vector<vector<float>> intersections){
    for(int y = 0; y < ny; y++){
        for( int x = 0; x < intersections[y].size(); x++){
            if(x == 0){
                intersections[y][x] = floorf(intersections[y][0]);
            }
            else if(x == intersections[y].size()-1){
                intersections[y][x] = ceilf(intersections[y][x]);
            }
        }
    }
    
}

void ScanlineRasterizer::print(){

    // adjust frame buffer according to intersections
    for(int y = 0; y < ny; y++){
        for( int x = 0; x < intersections[y].size(); x+=2){
            //fill all pixels between this x and the next x-intersection
            for (int i = intersections[y][x]; i < intersections[y][x+1]; i++){
                frameBuffer[y][i] = '*';
            }
        }
    }
    
    // print out the frame buffer eg. Fill the colors
    for(int i = 0; i < ny; i++){
        for( int j = 0; j < nx; j++){
            cout << frameBuffer[i][j];
        }
        cout<< endl;
    }
    
}

