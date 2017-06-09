//
//  testplugin.cpp
//  voronoi_gen
//
//  Created by Amit Shah on 2016-09-14.
//  Copyright © 2016 Amit Shah. All rights reserved.
//

#include "testplugin.h"


const double x_min=-1,x_max=1;
const double y_min=-1,y_max=1;
const double z_min=-1,z_max=1;
const double cvol=(x_max-x_min)*(y_max-y_min)*(x_max-x_min);

// Set up the number of blocks that the container is divided into
const int n_x=6,n_y=6,n_z=6;

// Set the number of particles that are going to be randomly introduced
const int particles=10;

// This function returns a random double between 0 and 1
double rnd() {return double(rand())/RAND_MAX;}



double ReturnDouble(){
    
    
        int i;
        double x,y,z;
        
        // Create a container with the geometry given above, and make it
        // non-periodic in each of the three coordinates. Allocate space for
        // eight particles within each computational block
        voro::container con(x_min,x_max,y_min,y_max,z_min,z_max,n_x,n_y,n_z,false,false,false,8);
    
        // Randomly add particles into the container
        for(i=0;i<particles;i++) {
            x=x_min+rnd()*(x_max-x_min);
            y=y_min+rnd()*(y_max-y_min);
            z=z_min+rnd()*(z_max-z_min);
            con.put(i,x,y,z);
        }
        
        // Sum up the volumes, and check that this matches the container volume
        //double vvol=con.sum_cell_volumes();
        con.compute_all_cells();
    
        //return vvol;
        return 0;
}

//double ** GetFaces2(){
//    int i;
//    double x,y,z;
//    double ** faces;
//    // Create a container with the geometry given above, and make it
//    // non-periodic in each of the three coordinates. Allocate space for
//    // eight particles within each computational block
//    voro::container con(x_min,x_max,y_min,y_max,z_min,z_max,n_x,n_y,n_z,
//                  false,false,false,8);
//    
//    // Randomly add particles into the container
//    for(i=0;i<particles;i++) {
//        x=x_min+rnd()*(x_max-x_min);
//        y=y_min+rnd()*(y_max-y_min);
//        z=z_min+rnd()*(z_max-z_min);
//        con.put(i,x,y,z);
//    }
//    
//    // Sum up the volumes, and check that this matches the container volume
//    double vvol=con.sum_cell_volumes();
//    
//    // Output the particle positions in gnuplot format
//    //con.draw_particles("random_points_p.gnu");
//    
//    // Output the Voronoi cells in gnuplot format
//    voro::voronoicell vc;
//    voro::c_loop_all vl(con);
//    //refer to interface example :)
//    std::vector<int> v;
//    if(vl.start()) do{
//        con.compute_cell(vc,vl);
//        faces = new double*[vc.number_of_faces()-1];
//        
//        vc.face_vertices(v);
//        printf("\r\ncomputing cell:\t");
//        
//        
//        //Amit: Refer to Common.cc line 62:
//        // 	void voro_print_face_vertices(std::vector<int> &v,FILE *fp) {
//        //TODO:Validate this method
//        int j,k=0,l;
//        if(v.size()>0) {
//            l=v[k++];
//            if(l<=1) {
//                if(l==1){
//                    printf("(%g,%g,%g)",vc.pts[v[k]-1]*0.5,vc.pts[v[k]]*0.5,vc.pts[v[k]+1]*0.5); k++;
//                }
//                else printf("()");
//            } else {
//                j=k+l;
//                printf("(%g,%g,%g)",vc.pts[v[k]-1]*0.5,vc.pts[v[k]]*0.5,vc.pts[v[k]+1]*0.5); k++;
//                while(k<j){
//                    printf("(%g,%g,%g)",vc.pts[v[k]-1]*0.5,vc.pts[v[k]]*0.5,vc.pts[v[k]+1]*0.5);
//                    k++;
//                }
//                printf(")");
//            }
//            while((unsigned int) k<v.size()) {
//                l=v[k++];
//                if(l<=1) {
//                    if(l==1){printf("(%g,%g,%g)",vc.pts[v[k]-1]*0.5,vc.pts[v[k]]*0.5,vc.pts[v[k]+1]*0.5); k++;}
//                    else printf(" ()");
//                } else {
//                    j=k+l;
//                    printf("(%g,%g,%g)",vc.pts[v[k]-1]*0.5,vc.pts[v[k]]*0.5,vc.pts[v[k]+1]*0.5); k++;
//                    while(k<j){ printf("(%g,%g,%g)",vc.pts[v[k]-1]*0.5,vc.pts[v[k]]*0.5,vc.pts[v[k]+1]*0.5); k++;}
//                    printf(")");
//                }
//            }
//        }
//        //}
//    }while(vl.inc());
//    
//    return faces;
//    
//}


void ReturnIntegerArray
(
 /*[out]*/ int** ppIntegerArrayReceiver,
 /*[out]*/ int* iSizeReceiver
 )
{
    *iSizeReceiver = 10;
    *ppIntegerArrayReceiver = new int[10]();//(int*)::malloc(sizeof(int) * 10);
    
    for (int i = 0; i < 10; i++)
    {
        (*ppIntegerArrayReceiver)[i] = i*15;
    }
}


void GetFaces
(
 /*[out]*/ double*** vertices,
 /*[out]*/ double** edgeArrayCount
 )
{
    std::vector<double> facesVec = std::vector<double>();
    facesVec.push_back(1.0);
    facesVec.push_back(2.0);
    facesVec.push_back(3.0);
    (*edgeArrayCount) = new double[facesVec.size()];
    //std::vector<double>::iterator it;  // declare an iterator to a vector of strings
    
    // now start at from the beginning
    // and keep iterating over the element till you find
    // nth element...or reach the end of vector.
//    int ii=0;
//    for(it=facesVec.begin() ; it < facesVec.end(); it++,ii++ ) {
//        (*edgeArrayCount)[ii] = (*it);
//    }
    std::copy(facesVec.begin(), facesVec.end(), (*edgeArrayCount));
   
    int faces = 100;
    //(*edgeArrayCount) = new double[faces]();
    
    (*vertices) = new double*[faces]();
    
    for (int i = 0; i < faces; i++)
    {
        (*vertices)[i] = new double[3]();
        (*vertices)[i][0] = i*1.0;
        (*vertices)[i][1] = i*1.1;
        (*vertices)[i][2] = i*1.2;
    }
    
    return;
    
    
}



int * test(int * data, int& size)
{
//    int * arr=new int[5];
//    arr[0]=1;
//    arr[1]=2;
//    arr[2]=3;
//    arr[3]=4;
//    arr[4]=5;
    
    
    size = 100;
    int *arPtr = new int[size];
    for(int n = 0; n < size; n++){
            arPtr[n] = n*10;
    }
    data = arPtr;
    return arPtr;
}

int ReleaseMemory(int* pArray)
{
    delete[] pArray;
    return 0;
}



int GenerateCells( int ** cellsPtr, double ** verticesPtr, int * cellSize, int * verticeSize) {
    
    int i;
    double x,y,z;
    
    // Create a container with the geometry given above, and make it
    // non-periodic in each of the three coordinates. Allocate space for
    // eight particles within each computational block
    voro::container con(x_min,x_max,y_min,y_max,z_min,z_max,n_x,n_y,n_z,
                  false,false,false,8);
    
    // Randomly add particles into the container
    for(i=0;i<particles;i++) {
        x=x_min+rnd()*(x_max-x_min);
        y=y_min+rnd()*(y_max-y_min);
        z=z_min+rnd()*(z_max-z_min);
        con.put(i,x,y,z);
    }
    
    // Sum up the volumes, and check that this matches the container volume
    double vvol=con.sum_cell_volumes();
    
    printf("Container volume : %g\n"
           "Voronoi volume   : %g\n"
           "Difference       : %g\n",cvol,vvol,vvol-cvol);
    
    // Output the particle positions in gnuplot format
    //con.draw_particles("random_points_p.gnu");
    
    // Output the Voronoi cells in gnuplot format
    voro::voronoicell vc;
    voro::c_loop_all vl(con);
    //refer to interface example :)
    std::vector<double> vertices = std::vector<double>();
    std::vector<int> cells = std::vector<int>();
    
    std::vector<int> v;
    
    if(vl.start()) do{
        con.compute_cell(vc,vl);
        vc.face_vertices(v);
        //find the displacement vector
        double * pp = con.p[vl.ijk]+con.ps*vl.q;
        printf("\nSIZE:%lu\n", v.size());
        
        
        //Amit: Refer to Common.cc line 62:
        //  void voro_print_face_vertices(std::vector<int> &v,FILE *fp) {
        //TODO:Validate this method
        int j,k=0,l,counter=0;
        if(v.size()>0) {
            
            //container.hh line 604
            //printf("%d",p[vl.ijk]+con.ps*vl.q);
            
            l=v[k++];
            if(l<=1) {
                if(l==1){
                    printf("new Vector3(%gf,%gf,%gf),\r\n",*pp+vc.pts[v[k]-1]*0.5,pp[1]+vc.pts[v[k]]*0.5,pp[2]+vc.pts[v[k]+1]*0.5);
                    
                    vertices.push_back(*pp+vc.pts[v[k]-1]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]+1]*0.5);
                    counter++;
                    k++;
                }
                else{
                    printf("()");
                }
            } else {
                j=k+l;
                printf("new Vector3(%gf,%gf,%gf),\r\n",*pp+vc.pts[v[k]-1]*0.5,pp[1]+vc.pts[v[k]]*0.5,pp[2]+vc.pts[v[k]+1]*0.5);
                vertices.push_back(*pp+vc.pts[v[k]-1]*0.5);
                vertices.push_back(*pp+vc.pts[v[k]]*0.5);
                vertices.push_back(*pp+vc.pts[v[k]+1]*0.5);
                counter++;
                k++;
                
                while(k<j){
                    printf("new Vector3(%gf,%gf,%gf),\r\n",*pp+vc.pts[v[k]-1]*0.5,pp[1]+vc.pts[v[k]]*0.5,pp[2]+vc.pts[v[k]+1]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]-1]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]+1]*0.5);
                    counter++;
                    k++;
                }
                //printf(")");
            }
            
            while((unsigned int) k<v.size()) {
                
                l=v[k++];
                if(l<=1) {
                    if(l==1){
                        printf("new Vector3(%gf,%gf,%gf),\r\n",*pp+vc.pts[v[k]-1]*0.5,pp[1]+vc.pts[v[k]]*0.5,pp[2]+vc.pts[v[k]+1]*0.5);
                        vertices.push_back(*pp+vc.pts[v[k]-1]*0.5);
                        vertices.push_back(*pp+vc.pts[v[k]]*0.5);
                        vertices.push_back(*pp+vc.pts[v[k]+1]*0.5);
                        counter++;
                        k++;
                    }
                    else{
                        printf(" ()");
                    }
                } else {
                    j=k+l;
                    printf("new Vector3(%gf,%gf,%gf),\r\n",*pp+vc.pts[v[k]-1]*0.5,pp[1]+vc.pts[v[k]]*0.5,pp[2]+vc.pts[v[k]+1]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]-1]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]]*0.5);
                    vertices.push_back(*pp+vc.pts[v[k]+1]*0.5);
                    counter++;
                    k++;
                    
                    while(k<j){
                        printf("new Vector3(%gf,%gf,%gf),\r\n",*pp+vc.pts[v[k]-1]*0.5,pp[1]+vc.pts[v[k]]*0.5,pp[2]+vc.pts[v[k]+1]*0.5);
                        vertices.push_back(*pp+vc.pts[v[k]-1]*0.5);
                        vertices.push_back(*pp+vc.pts[v[k]]*0.5);
                        vertices.push_back(*pp+vc.pts[v[k]+1]*0.5);
                        counter++;
                        k++;
                    }
                    
                }
            }
        }
        //}
        cells.push_back(counter++);
    }while(vl.inc());
    
    
    printf("done");
    con.draw_cells_gnuplot("random_points_v.gnu");
    con.print_custom("order=%o, vertices=%p","vertices.test");
    
    con.print_custom(
                     "ID=%i, pos=(%x,%y,%z), vertices=%w, edges=%g, faces=%s, face_verts=%t"
                     ,"face.test");
    printf("\n%lu,%lu\n", vertices.size(), cells.size());
    (*cellSize) = cells.size();
    (*verticeSize) = vertices.size();
    (*cellsPtr) = new int[cells.size()];
    (*verticesPtr) = new double[vertices.size()];
    std::copy(cells.begin(), cells.end(), (*cellsPtr));
    std::copy(vertices.begin(), vertices.end(), (*verticesPtr));
    return 1;
}



