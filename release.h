#include "string.h"
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "TFile.h"
#include "TTree.h"
#include "TF1.h"
#include "TGraph.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TMath.h"
#include "TVector3.h"
#include "TH2F.h"
#include "TRandom2.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "TString.h"

struct inputdata {

// Detector dimensions
  double D_dim_x;   // 
  double D_dim_r;   //  radius
  double D_dim_y;  // 
  double D_dim_z; // detector direction of signal by calibration
  int    D_type ; // detector type ( 1: box ;  2: cylinder (axis // to normal of surface) ; 3: cylinder (axis // to surface)
  int    D_coll ; // detector collimator ( 1: yes ; 0: no) a collimator that cleans the side of the detector from background



// Generated dimension isotropic source

  double G_shift_x; // shift from center of activated volume
  double G_shift_y; // shift from center of activated volume
  double G_shift_z; // shift from center of activated volume
  double G_dim_r;   // radius
  double G_dim_x;   // lx
  double G_dim_y;  // ly
  double G_dim_z; // lz
  int    G_type ; // detector type ( 1: box ; 2: cylinder )
  double G_ener; // Generated energy (MeV)
  int    G_nev; // number of generated events

  int    T_type ; // Target volume type ( 1: box ; 2: cylinder)
  TString T_mat_tg; // Material target decaying
  TString T_mat_out;// Material outside target decaying  
  double T_dim_r;   // radius
  double T_dim_x;   // lx
  double T_dim_y;  // ly
  double T_dim_z; // lz
  double W_dim_r;   // radius
  double W_dim_x;   // lx
  double W_dim_y;  // ly
  double W_dim_z; // lz
  TString T_input; // input file simulation with parameters

  TString G_file; // Generated event file name
  TString S_file; // Simulated file
  TString O_file; // Output file
  double act_density; // Activity density in pCi/g
};


char input_gen_file[50];
void Print_Usage();
void Parse_Args(int *argc, char **argv);
void cylinder(int n_event, double radius, double length, double energy, const char name[100]);
void box(int n_event, double lx, double ly, double lz, double energy, const char name[100]);
void test_x(int n_event, double energy, const char name[100]);
void test_y(int n_event, double energy, const char name[100]);
void test_z(int n_event, double energy, const char name[100]);
void  FillHisto(TH3D *h3d,double leak_x,double leak_y,double leak_z,double mom_x, double mom_y, double mom_z, double weight);
void get_detector(int tdet, TH3D *h3d, TH3D *h3loc, TH3D *Hnx, TH3D *Hny, TH3D *Hnz, TH3D *h3out, TH3D *h3dbox);
void get_detector_coll(int tdet, TH3D *h3d, TH3D *h3loc, TH3D *Hnx, TH3D *Hny, TH3D *Hnz, TH3D *h3out, TH3D *h3dbox);
void analysis(int tdet, const char name_in[100],const char name_out[100],double n_event);
inputdata fData;
