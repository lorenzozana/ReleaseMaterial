#include "release.h"

// double dim_x = 10.0;
// double dim_y = 10.0;
// double dim_z = 10.0; // detector direction of signal by calibration



int main(int argc, char **argv){
    char default_file[255] = "release.inp";
    char command_exe[255] = "./targetsim release.inp";
    Parse_Args( &argc, argv );
   
 

    if (strlen(input_gen_file) == 0)  {
      strcpy(input_gen_file,default_file);
      printf ("No input file specified. Using default input file %s \n",default_file);  
      Print_Usage();
    }
    // process input file
    std::string command; 
    std::string tmp;
    std::ifstream inputfile;
    inputfile.open(input_gen_file, std::ifstream::in);
    if( !inputfile ) {
      printf("%s cannot be opened\n", input_gen_file); 
      exit(1);
    }
    char c1;
    char delim = ';';
    TString valcommand;
    TString valc2;
    double factor;

    while( !inputfile.eof() ){ 
      std::getline(inputfile,command);
      valcommand = command;
      valc2 = valcommand(0,1);
      if (valc2.Contains("#")==false) {
	if (valcommand.Contains("en:")) {
	  valcommand.ReplaceAll("en:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains("keV")) factor = 0.001;
	  else if (valcommand.Contains("GeV")) factor = 1000.; // default is MeV
	  else if (valcommand.Contains("eV")) factor = 0.000001; // default is MeV
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("GeV","");
	  valcommand.ReplaceAll("MeV","");
	  valcommand.ReplaceAll("keV","");
	  valcommand.ReplaceAll("eV","");
	  fData.G_ener = factor*valcommand.Atof();
	  printf("Energy of decaying photon %.4f MeV\n",fData.G_ener);
	}
	if (valcommand.Contains("D_dim_x:")) {
	  valcommand.ReplaceAll("D_dim_x:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.D_dim_x = factor*valcommand.Atof();
	  printf("Detector dimension X: %.4f cm\n",fData.D_dim_x);	  
	}
	if (valcommand.Contains("D_dim_y:")) {
	  valcommand.ReplaceAll("D_dim_y:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.D_dim_y = factor*valcommand.Atof();
	  printf("Detector dimension Y: %.4f cm\n",fData.D_dim_y);	  
	}
	if (valcommand.Contains("D_dim_z:")) {
	  valcommand.ReplaceAll("D_dim_z:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.D_dim_z = factor*valcommand.Atof();
	  printf("Detector dimension Z: %.4f cm\n",fData.D_dim_z);	  
	}
	if (valcommand.Contains("D_dim_r:")) {
	  valcommand.ReplaceAll("D_dim_r:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.D_dim_r = factor*valcommand.Atof();
	  printf("Detector dimension Z: %.4f cm\n",fData.D_dim_r);	  
	}
	if (valcommand.Contains("G_dim_x:")) {
	  valcommand.ReplaceAll("G_dim_x:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_dim_x = factor*valcommand.Atof();
	  printf("Detector dimension X: %.4f cm\n",fData.G_dim_x);	  
	}
	if (valcommand.Contains("G_dim_y:")) {
	  valcommand.ReplaceAll("G_dim_y:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_dim_y = factor*valcommand.Atof();
	  printf("Detector dimension Y: %.4f cm\n",fData.G_dim_y);	  
	}
	if (valcommand.Contains("G_dim_z:")) {
	  valcommand.ReplaceAll("G_dim_z:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_dim_z = factor*valcommand.Atof();
	  printf("Detector dimension Z: %.4f cm\n",fData.G_dim_z);	  
	}
	if (valcommand.Contains("G_dim_r:")) {
	  valcommand.ReplaceAll("G_dim_r:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_dim_r = factor*valcommand.Atof();
	  printf("Detector dimension Z: %.4f cm\n",fData.G_dim_r);	  
	}
	if (valcommand.Contains("G_shift_x:")) {
	  valcommand.ReplaceAll("G_shift_x:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_shift_x = factor*valcommand.Atof();
	  printf("Activity volume shift X: %.4f cm\n",fData.G_shift_x);	  
	}
	if (valcommand.Contains("G_shift_y:")) {
	  valcommand.ReplaceAll("G_shift_y:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_shift_y = factor*valcommand.Atof();
	  printf("Activity volume shift Y: %.4f cm\n",fData.G_shift_y);	  
	}
	if (valcommand.Contains("G_shift_z:")) {
	  valcommand.ReplaceAll("G_shift_z:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.G_shift_z = factor*valcommand.Atof();
	  printf("Activity volume shift Z: %.4f cm\n",fData.G_shift_z);	  
	}
	if (valcommand.Contains("D_type:")) {
	  valcommand.ReplaceAll("D_type:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  fData.D_type = valcommand.Atoi();
	  printf("Detector type  %d\n",fData.D_type);
	}
	if (valcommand.Contains("D_coll:")) {
	  valcommand.ReplaceAll("D_coll:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  fData.D_coll = valcommand.Atoi();
	  printf("Detector collimator  %d\n",fData.D_coll);
	}
	if (valcommand.Contains("G_type:")) {
	  valcommand.ReplaceAll("G_type:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  fData.G_type = valcommand.Atoi();
	  printf("Generated volume type  %d\n",fData.G_type);
	}
	if (valcommand.Contains("G_nev:")) {
	  valcommand.ReplaceAll("G_nev:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  fData.G_nev = valcommand.Atoi();
	  printf("Generated number of events  %d\n",fData.G_nev);
	}
	if (valcommand.Contains("T_type:")) {
	  valcommand.ReplaceAll("T_type:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  fData.T_type = valcommand.Atoi();
	  printf("Target type  %d\n",fData.T_type);
	}
	if (valcommand.Contains("T_mat_tg:")) {
	  valcommand.ReplaceAll("T_mat_tg:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("\n","");
	  valcommand.ReplaceAll("\t","");
	  fData.T_mat_tg = valcommand.Strip();
	  printf("Target material %s\n",fData.T_mat_tg.Data());
	}
	if (valcommand.Contains("T_mat_out:")) {
	  valcommand.ReplaceAll("T_mat_out:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("\n","");
	  valcommand.ReplaceAll("\t","");
	  fData.T_mat_out = valcommand.Strip();
	  printf("Target material out %s\n",fData.T_mat_out.Data());
	}
	if (valcommand.Contains("T_dim_x:")) {
	  valcommand.ReplaceAll("T_dim_x:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.T_dim_x = factor*valcommand.Atof();
	  printf("Target dimension X: %.4f cm\n",fData.T_dim_x);	  
	}
	if (valcommand.Contains("T_dim_y:")) {
	  valcommand.ReplaceAll("T_dim_y:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.T_dim_y = factor*valcommand.Atof();
	  printf("Target dimension Y: %.4f cm\n",fData.T_dim_y);	  
	}
	if (valcommand.Contains("T_dim_z:")) {
	  valcommand.ReplaceAll("T_dim_z:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.T_dim_z = factor*valcommand.Atof();
	  printf("Target dimension Z: %.4f cm\n",fData.T_dim_z);	  
	}
	if (valcommand.Contains("T_dim_r:")) {
	  valcommand.ReplaceAll("T_dim_r:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.T_dim_r = factor*valcommand.Atof();
	  printf("Target dimension R: %.4f cm\n",fData.T_dim_r);	  
	}
	if (valcommand.Contains("W_dim_x:")) {
	  valcommand.ReplaceAll("W_dim_x:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.W_dim_x = factor*valcommand.Atof();
	  printf("Outside material dimension X: %.4f cm\n",fData.W_dim_x);	  
	}
	if (valcommand.Contains("W_dim_y:")) {
	  valcommand.ReplaceAll("W_dim_y:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.W_dim_y = factor*valcommand.Atof();
	  printf("Outside material dimension Y: %.4f cm\n",fData.W_dim_y);	  
	}
	if (valcommand.Contains("W_dim_z:")) {
	  valcommand.ReplaceAll("W_dim_z:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.W_dim_z = factor*valcommand.Atof();
	  printf("Outside material dimension Z: %.4f cm\n",fData.W_dim_z);	  
	}
	if (valcommand.Contains("W_dim_r:")) {
	  valcommand.ReplaceAll("W_dim_r:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" m")) factor = 100.;
	  else if (valcommand.Contains(" mm")) factor = 0.1;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" m","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("cm","");
	  valcommand.ReplaceAll("mm","");
	  fData.W_dim_r = factor*valcommand.Atof();
	  printf("Outside material dimension R: %.4f cm\n",fData.W_dim_r);	  
	}
	if (valcommand.Contains("T_input:")) {
	  valcommand.ReplaceAll("T_input:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("\n","");
	  valcommand.ReplaceAll("\t","");
	  fData.T_input = valcommand.Strip();
	  printf("Simulation input %s\n",fData.T_input.Data());
	}
	if (valcommand.Contains("G_file:")) {
	  valcommand.ReplaceAll("G_file:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("\n","");
	  valcommand.ReplaceAll("\t","");
	  fData.G_file = valcommand.Strip();
	  printf("Generated source file output %s\n",fData.G_file.Data());
	}
	if (valcommand.Contains("S_file:")) {
	  valcommand.ReplaceAll("S_file:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("\n","");
	  valcommand.ReplaceAll("\t","");
	  fData.S_file = valcommand.Strip();
	  printf("Simulated output file %s\n",fData.S_file.Data());
	}
	if (valcommand.Contains("O_file:")) {
	  valcommand.ReplaceAll("O_file:","");
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("\n","");
	  valcommand.ReplaceAll("\t","");
	  fData.O_file = valcommand.Strip();
	  printf("Final output file %s\n",fData.O_file.Data());
	}
	if (valcommand.Contains("act_density:")) {
	  valcommand.ReplaceAll("act_density:","");
	  valcommand.ReplaceAll(";","");
	  if (valcommand.Contains(" Bq/g")) factor = 27.027027;
	  else factor = 1;
	  valcommand.ReplaceAll(";","");
	  valcommand.ReplaceAll("Bq/g","");
	  valcommand.ReplaceAll(" ","");
	  valcommand.ReplaceAll("pCi/g","");
	  fData.act_density = factor*valcommand.Atof();
	  printf("Activity density: %.4f pCi/g\n",fData.act_density);	  
	}

      }
    }

    // Generate the isotropic source  (the shift is inside the generator

    if (fData.G_type == 1 ) { //box
      box(fData.G_nev,fData.G_dim_x,fData.G_dim_y,fData.G_dim_z,fData.G_ener,fData.G_file.Data());
    }
    else if (fData.G_type == 2 ) { //cylinder dim_r = radius, dim_z= length
      cylinder(fData.G_nev,fData.G_dim_r,fData.G_dim_z,fData.G_ener,fData.G_file.Data());
    } 
    else if (fData.G_type == 3 ) { // test x direction
      test_x(fData.G_nev,fData.G_ener,fData.G_file.Data());
    }
    else if (fData.G_type == 4 ) { // test y direction
      test_y(fData.G_nev,fData.G_ener,fData.G_file.Data());
    }
    else if (fData.G_type == 5 ) { // test z direction
      test_z(fData.G_nev,fData.G_ener,fData.G_file.Data());
    }

    else std::exit(0);


    
    std::ofstream outputfile;
    outputfile.open(fData.T_input.Data(), std::ofstream::out);
    if( !outputfile ) {
      printf("%s cannot be opened\n", fData.T_input.Data()); 
      exit(1);
    }
    outputfile << "/control/verbose 2" << std::endl;
    outputfile << "/run/verbose 1 " << std::endl;
    outputfile << "/tracking/verbose 0" << std::endl;
    outputfile << "/testhadr/TargetMat "<< fData.T_mat_tg.Data() << std::endl;
    outputfile << "/testhadr/WindowMat "<< fData.T_mat_out.Data() << std::endl;
    if (fData.T_type == 1) { // box
      outputfile <<  "/testhadr/Length_tg_x " << fData.T_dim_x << " cm" << std::endl;
      outputfile <<  "/testhadr/Length_tg_y " << fData.T_dim_y << " cm" << std::endl;
      outputfile <<  "/testhadr/Length_tg_z " << fData.T_dim_z << " cm" << std::endl;
      outputfile <<  "/testhadr/Length_wd_x " << fData.W_dim_x << " cm" << std::endl;
      outputfile <<  "/testhadr/Length_wd_y " << fData.W_dim_y << " cm" << std::endl;
      outputfile <<  "/testhadr/Length_wd_z " << fData.W_dim_z << " cm" << std::endl;
    }
    else if (fData.T_type == 2) { // cylinder
      outputfile << "/testhadr/TargetRadius " << fData.T_dim_r << " cm" << std::endl;
      outputfile << "/testhadr/TargetLength " << fData.T_dim_z << " cm" << std::endl;
      outputfile << "/testhadr/WindowThick_r " << fData.W_dim_r << " cm" << std::endl;
      outputfile << "/testhadr/WindowThick_z " << fData.W_dim_z << " cm" << std::endl;
    }
    outputfile << "/testhadr/VolumeType "<< fData.T_type << std::endl;
    outputfile << "/testhadr/NumberDivZ       1" << std::endl;
    outputfile << "/testhadr/PrintModulo      100000" << std::endl;
    outputfile << "/testhadr/Update" << std::endl;
    outputfile << "/testhadr/InChain          Full" << std::endl;
    outputfile << "/testhadr/Infile " << fData.G_file.Data() << std::endl;
    outputfile << "/testhadr/Physics          QGSP_BERT" << std::endl;
    outputfile << "/run/initialize" << std::endl;
    outputfile << "/testhadr/MaxEdep          10 GeV" << std::endl;
    outputfile << "/outputrec/FileName "<< fData.S_file.Data() << std::endl;
    outputfile << "/outputrec/Particle         1 22 " << std::endl;	    
    outputfile << "/gun/particle gamma" << std::endl;
    outputfile << "/run/beamOn " << fData.G_nev << std::endl;

    outputfile.close();
    
    sprintf(command_exe,"./targetsim %s",fData.T_input.Data()); 
    printf("Executing %s \n",command_exe);
    system(command_exe);

    // runnning the analysis
    analysis(fData.D_type,fData.S_file.Data(),fData.O_file.Data(),fData.G_nev);

    return 0;
}

void Parse_Args(int *argc, char **argv) {
#define REMOVE_ONE {(*argc)--;for(j=i;j<(*argc);j++)argv[j]=argv[j+1];i--;}
#define I_PLUS_PLUS if((i+1)<(*argc)){i++;}else{break;}
  int  i,j;
  for( i=1; i<(*argc); i++ )  
    {
      if( argv[i][0] == '-' ) {
	if(strcmp(argv[i],"-i")==0 || strcmp(argv[i],"-input")==0)
	  {
	    I_PLUS_PLUS;
	    strcpy(input_gen_file,argv[i]);
	    REMOVE_ONE;
	  }
	else if(strcmp(argv[i],"-help")==0||strcmp(argv[i],"-h")==0)  
	  {
	    Print_Usage();
	    exit(1);
	  }
	else
	  {
	    fprintf(stderr,"\nI did not understand the option : %s\n",argv[i]);
	    Print_Usage();
	    exit(1);
	  }
	/* KILL the option from list */
	REMOVE_ONE;
      }
    }


}


void Print_Usage() {
  printf (" Release : This Program Generates events \n");  
  printf (" Usage: ./Release -i inputfile \n");  
  printf ("     -i (or -input) inputfile    input file name with correct flags (example input.dat)  \n");  
  printf ("     -h (or -help) print this message \n");
  printf (" --- \n\n");
}



void  cylinder(int n_event, double radius, double length, double energy, const char name[100]) {
  
  printf("Writing Simulation input %s\n",name);
  int pdg = 22;

  TH2F * hrand =  new TH2F("hrand","hrand",100,-10.,10.,100,-10.,10.);
  TFile *fOut = new TFile(name,"RECREATE");
  TTree * tTree = new TTree("Full", "Full leaking Geant4 Monte Carlo");
  double in_px, in_py, in_pz, in_vx, in_vy, in_vz;
  int  in_pdg;
  tTree->Branch("in_px",&in_px, "in_px/D");
  tTree->Branch("in_py",&in_py, "in_py/D");
  tTree->Branch("in_pz",&in_pz, "in_pz/D");
  tTree->Branch("in_vx",&in_vx, "in_vx/D");
  tTree->Branch("in_vy",&in_vy, "in_vy/D");
  tTree->Branch("in_vz",&in_vz, "in_vz/D");
  tTree->Branch("energy",&energy, "energy/D");
  tTree->Branch("in_pdg",&in_pdg, "in_pdg/I");


  TRandom2 *frandom = new TRandom2(0);
  int nprint = n_event / 10;
  for (int i=0; i<n_event; i++) {
    if( (i%nprint) == 0 ){printf("Event %10d \n", i);}
    // hrand->Fill(frand->GetRandom(0.,TMath::Pi()));
    frandom->Sphere(in_px,in_py,in_pz,1.);
    in_px = in_px *energy;
    in_py = in_py *energy;
    in_pz = in_pz *energy;
    in_vz = length * (-0.5+frandom->Uniform(1.)) +fData.G_shift_z;
    in_vx = radius;
    in_vy = radius;
    while ( pow(in_vx,2)+pow(in_vy,2) > pow(radius,2)) {
      in_vx = radius * 2*(-0.5+frandom->Uniform(1.));
      in_vy = radius * 2*(-0.5+frandom->Uniform(1.));
    }
    in_vx = in_vx +  +fData.G_shift_x;
    in_vy = in_vy +  +fData.G_shift_y;
    hrand->Fill(in_vx,in_vy);
    in_pdg = 22;
    tTree->Fill();
    //    cout << in_px << " \t"<< in_py << " \t"<< in_pz << " \t"<< in_vx << " \t"<< in_vy << " \t"<< in_vz << " \t" << endl;
  }
  tTree->Write();
  hrand->Write();


}

void test_x(int n_event, double energy, const char name[100]) {

  printf("Writing Simulation input %s\n",name);
  TFile *fOut = new TFile(name,"RECREATE");
  TTree * tTree = new TTree("Full", "Full leaking Geant4 Monte Carlo");
  double in_px, in_py, in_pz, in_vx, in_vy, in_vz;
  int  in_pdg;
  tTree->Branch("in_px",&in_px, "in_px/D");
  tTree->Branch("in_py",&in_py, "in_py/D");
  tTree->Branch("in_pz",&in_pz, "in_pz/D");
  tTree->Branch("in_vx",&in_vx, "in_vx/D");
  tTree->Branch("in_vy",&in_vy, "in_vy/D");
  tTree->Branch("in_vz",&in_vz, "in_vz/D");
  tTree->Branch("energy",&energy, "energy/D");
  tTree->Branch("in_pdg",&in_pdg, "in_pdg/I");

  int nprint = n_event / 10;
  for (int i=0; i<n_event; i++) {
    if( (i%nprint) == 0 ){printf("Event %10d \n", i);}
    in_px = energy;
    in_py = 0.0;
    in_pz = 0.0;
    in_vx = fData.G_shift_x;
    in_vy = fData.G_shift_y;
    in_vz = fData.G_shift_z;
    in_pdg = 22;
    tTree->Fill();    
  }
  tTree->Write();

}

void test_y(int n_event, double energy, const char name[100]) {

  printf("Writing Simulation input %s\n",name);
  TFile *fOut = new TFile(name,"RECREATE");
  TTree * tTree = new TTree("Full", "Full leaking Geant4 Monte Carlo");
  double in_px, in_py, in_pz, in_vx, in_vy, in_vz;
  int  in_pdg;
  tTree->Branch("in_px",&in_px, "in_px/D");
  tTree->Branch("in_py",&in_py, "in_py/D");
  tTree->Branch("in_pz",&in_pz, "in_pz/D");
  tTree->Branch("in_vx",&in_vx, "in_vx/D");
  tTree->Branch("in_vy",&in_vy, "in_vy/D");
  tTree->Branch("in_vz",&in_vz, "in_vz/D");
  tTree->Branch("energy",&energy, "energy/D");
  tTree->Branch("in_pdg",&in_pdg, "in_pdg/I");

  int nprint = n_event / 10;
  for (int i=0; i<n_event; i++) {
    if( (i%nprint) == 0 ){printf("Event %10d \n", i);}
    in_px = 0.0;
    in_py = energy;
    in_pz = 0.0;
    in_vx = fData.G_shift_x;
    in_vy = fData.G_shift_y;
    in_vz = fData.G_shift_z;
    in_pdg = 22;
    tTree->Fill();    
  }
  tTree->Write();

}
void test_z(int n_event, double energy, const char name[100]) {

  printf("Writing Simulation input %s\n",name);
  TFile *fOut = new TFile(name,"RECREATE");
  TTree * tTree = new TTree("Full", "Full leaking Geant4 Monte Carlo");
  double in_px, in_py, in_pz, in_vx, in_vy, in_vz;
  int  in_pdg;
  tTree->Branch("in_px",&in_px, "in_px/D");
  tTree->Branch("in_py",&in_py, "in_py/D");
  tTree->Branch("in_pz",&in_pz, "in_pz/D");
  tTree->Branch("in_vx",&in_vx, "in_vx/D");
  tTree->Branch("in_vy",&in_vy, "in_vy/D");
  tTree->Branch("in_vz",&in_vz, "in_vz/D");
  tTree->Branch("energy",&energy, "energy/D");
  tTree->Branch("in_pdg",&in_pdg, "in_pdg/I");

  int nprint = n_event / 10;
  for (int i=0; i<n_event; i++) {
    if( (i%nprint) == 0 ){printf("Event %10d \n", i);}
    in_px = 0.0;
    in_py = 0.0;
    in_pz = energy;
    in_vx = fData.G_shift_x;
    in_vy = fData.G_shift_y;
    in_vz = fData.G_shift_z;
    in_pdg = 22;
    tTree->Fill();    
  }
  tTree->Write();

}


void  box(int n_event, double lx, double ly, double lz, double energy, const char name[100]) {
  
  printf("Writing Simulation input %s\n",name);
  int pdg = 22;

  TH2F * hrand =  new TH2F("hrand","hrand",100,-10.,10.,100,-10.,10.);
  TFile *fOut = new TFile(name,"RECREATE");
  TTree * tTree = new TTree("Full", "Full leaking Geant4 Monte Carlo");
  double in_px, in_py, in_pz, in_vx, in_vy, in_vz;
  int  in_pdg;
  tTree->Branch("in_px",&in_px, "in_px/D");
  tTree->Branch("in_py",&in_py, "in_py/D");
  tTree->Branch("in_pz",&in_pz, "in_pz/D");
  tTree->Branch("in_vx",&in_vx, "in_vx/D");
  tTree->Branch("in_vy",&in_vy, "in_vy/D");
  tTree->Branch("in_vz",&in_vz, "in_vz/D");
  tTree->Branch("energy",&energy, "energy/D");
  tTree->Branch("in_pdg",&in_pdg, "in_pdg/I");

  double theta, phi;
  TRandom2 *frandom = new TRandom2(0);
  int nprint = n_event / 10;
  for (int i=0; i<n_event; i++) {
    if( (i%nprint) == 0 ){printf("Event %10d \n", i);}
    // hrand->Fill(frand->GetRandom(0.,TMath::Pi()));
    //    frandom->Sphere(in_px,in_py,in_pz,1.);
    theta = acos(2.0*frandom->Uniform()-1.0);
    phi = 2.0*TMath::Pi()*frandom->Uniform();
    // in_px = in_px *energy;
    // in_py = in_py *energy;
    // in_pz = in_pz *energy;
    in_px = sin(theta)*cos(phi) *energy;
    in_py = sin(theta)*sin(phi) *energy;
    in_pz = cos(theta) *energy;
    in_vx = lx * (-0.5+frandom->Uniform(1.)) +fData.G_shift_x;
    in_vy = ly * (-0.5+frandom->Uniform(1.)) +fData.G_shift_y;
    in_vz = lz * (-0.5+frandom->Uniform(1.)) +fData.G_shift_z;
    hrand->Fill(in_vx,in_vy);
    in_pdg = 22;
    tTree->Fill();
    //    cout << in_px << " \t"<< in_py << " \t"<< in_pz << " \t"<< in_vx << " \t"<< in_vy << " \t"<< in_vz << " \t" << endl;
  }
  tTree->Write();
  hrand->Write();


}



void  FillHisto(TH3D *h3d,double leak_x,double leak_y,double leak_z,double mom_x, double mom_y, double mom_z, double weight) {

  // in this subroutine I will fill the volumes where it is possible that the detector is going to be.
  double at_x = leak_x;
  double at_y = leak_y;
  double at_z = leak_z;


  double mom = pow(pow(mom_x,2)+pow(mom_y,2)+pow(mom_z,2),0.5);
  
  double dir_x = 0.0;
  double dir_y = 0.0; 
  double dir_z = 0.0;
  int bat_x, bat_y, bat_z;
  if (mom > 0.0) {
    dir_x = mom_x / mom;
    dir_y = mom_y / mom;
    dir_z = mom_z / mom;
  }
  if (fData.D_type == 2 || fData.D_type == 3) { // cylinder type, I will still use D_dim_x and D_dim_y has both r direction
    fData.D_dim_x = fData.D_dim_r;
    fData.D_dim_y = fData.D_dim_r;
  }
  h3d->Fill(leak_x,leak_y,leak_z,weight/(fData.D_dim_z/h3d->GetZaxis()->GetBinWidth(1))); // the weight is so that is equal to the efficiency if it pass through the full detector (calibrated to record in the z direction)
  while ( TMath::Abs(at_x -leak_x) < fData.D_dim_x && TMath::Abs(at_y -leak_y) < fData.D_dim_y &&  TMath::Abs(at_z -leak_z) < fData.D_dim_z ) {
    bat_x = h3d->GetXaxis()->FindBin(at_x);
    bat_y = h3d->GetYaxis()->FindBin(at_y);
    bat_z = h3d->GetZaxis()->FindBin(at_z);
    
    at_x = at_x + dir_x * h3d->GetXaxis()->GetBinWidth(1); 
    at_y = at_y + dir_y * h3d->GetYaxis()->GetBinWidth(1); 
    at_z = at_z + dir_z * h3d->GetZaxis()->GetBinWidth(1); 

    if ( h3d->GetXaxis()->FindBin(at_x) != bat_x || h3d->GetYaxis()->FindBin(at_y) != bat_y || h3d->GetZaxis()->FindBin(at_z) != bat_z ) {
      h3d->Fill(at_x,at_y,at_z,weight/(fData.D_dim_z/h3d->GetZaxis()->GetBinWidth(1))); // the weight is so that is equal to the efficiency if it pass through the full detector (calibrated to record in the z direction)
    }
  } 


}

void get_detector(int tdet, TH3D *h3d, TH3D *h3loc, TH3D *Hnx, TH3D *Hny, TH3D *Hnz, TH3D *h3out, TH3D *h3dbox) {
  
  //tdet = 1 it is a box detector with z axis parallel to normal to surface
  //tdet = 2 it is a cylinder detector with z axis parallel to normal to surface
  //tdet = 3 it is a cylinder detector with z axis perpendicular to normal to surface (I use v3z) 
  
  // at now testing for box
  double integ = 0.0;
  double leak_x, leak_y, leak_z;
  double norm_x, norm_y, norm_z;
  double at_x, at_y, at_z;
  TVector3 norm;
  TVector3 v3z;
  TVector3 v3perp;
  TVector3 v3leak;
  TVector3 v3at;
  TVector3 v3at_norm;
  TVector3 v3at_perp;
  TVector3 v3at_z;
  int at_bin;
  double conversion_factor;
  int at_det = 0;
  
  for (int i =0 ; i< h3loc->GetNbinsX() ; i++) {
    for (int j = 0; j< h3loc->GetNbinsY() ; j++) {
      for (int k =0 ; k< h3loc->GetNbinsZ() ; k++) {
	if (h3loc->GetBinContent(i,j,k) >0.0) { // this bin shows the location where there are leaking photon
	  at_det++;
	  // the normal direction is the z direction of the detector
	  integ = 0.0; // reset the integral to 0.0
	  // in the detector one direction is fixed and is vertical, the other direction is the normal to the surface, the third direction is so fixed.
	  v3z.SetXYZ(0.,0.,1.); // vector parallel to the z axis (vertical here)
	  leak_x = h3loc->GetXaxis()->GetBinCenter(i);
	  leak_y = h3loc->GetYaxis()->GetBinCenter(j);
	  leak_z = h3loc->GetZaxis()->GetBinCenter(k);
	  norm_x = Hnx->GetBinContent(i,j,k);
	  norm_y = Hny->GetBinContent(i,j,k);
	  norm_z = Hnz->GetBinContent(i,j,k);
	  norm.SetXYZ(norm_x,norm_y,norm_z);
	  norm.SetMag(1.); // direction of calibration of detector normalized to 1. 
	  v3perp = norm.Cross(v3z); // now I have the third direction of the detector
	  if (v3perp.Mag() != 1.0 && v3perp.Mag()!=0.0 ) { // norm has a component in the y axis but is not in the y axis
	    v3perp.SetMag(1.); // now set the magnitude to 1 and it is normal to v3z and norm
	    v3z = v3perp.Cross(norm); // now is normal to norm and v3perp and can be used as part of 3 axis
	  }
	  else if (v3perp.Mag() == 0.0) { // this means that norm and v3z are in the same direction
	    v3z.SetXYZ(1.,0.,0.); // now it is parallel to the X axis
	    v3perp = norm.Cross(v3z); // now I have the third direction of the detector    
	  }
	  v3perp.SetMag(1.); // normalize to 1.
	  //	  cout << i << " " << j << " " << k << " " << v3z.X()  << " " << v3z.Y()  << " " << v3z.Z()  << " " << v3perp.X()  << " " << v3perp.Y()  << " " << v3perp.Z() << " " << norm.X()  << " " << norm.Y()  << " " << norm.Z() << endl;

	  //	  cout << "Angle=" << norm.Angle(v3z) << "\t vrperp size =" << v3perp.Mag() << endl;
	  at_x = leak_x ;
	  at_y = leak_y ;
	  at_z = leak_z ;
	  v3leak.SetXYZ(leak_x,leak_y,leak_z);
	  TH3D *h3at = (TH3D *)h3d->Clone("h3at");  // need a clone to set the bin count to 0 when already counted to avoid doublecounting the same bin
	  if (tdet ==1) { // box detector
	    conversion_factor = fData.D_dim_z/h3d->GetXaxis()->GetBinWidth(1); // This represents how many bins will be in the z direction (by definition the direction of operation). In this way the probability get normalized after integration (if just a single photon travels in the direction of perfect operation (z axis), the integral will be equal to this number)
	    if (conversion_factor == 0.0) std::cout << "Box detector z size= 0: Unphysical detector, the code will fail" << std::endl ; 
	    for (int ii=0 ; ii<fData.D_dim_z/h3d->GetXaxis()->GetBinWidth(1) ; ii++) {
	      for (int jj=0 ; jj<fData.D_dim_x/h3d->GetXaxis()->GetBinWidth(1) ; jj++) { // It is important to keep the binning of the acceptance histogram the same size in all 3 axis
		for (int kk=0 ; kk<fData.D_dim_y/h3d->GetXaxis()->GetBinWidth(1) ; kk++) {
		  v3at_norm = (double(ii)*h3d->GetXaxis()->GetBinWidth(1)) *norm; // shift in direction norm
		  v3at_perp =  (double(jj)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_x) *v3perp; // shift in direction perp
		  v3at_z = (double(kk)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_y) *v3z; // shift in direction z
		  v3at =  v3leak + v3at_norm; // adding norm shift to locaction (the TVector3 class just accept a single addition
		  v3at = v3at + v3at_perp; // adding perp shift to location
		  v3at = v3at + v3at_z; // adding z shift to location
		  at_bin = h3at->FindBin(v3at.X(),v3at.Y(),v3at.Z());
		  if (at_det==10 || at_det==100 || at_det==200) h3dbox->Fill(v3at.X(),v3at.Y(),v3at.Z(),h3at->GetBinContent(at_bin)); // show an example for detector number 10
		  integ = integ + h3at->GetBinContent(at_bin) / conversion_factor ;
		  h3at->SetBinContent(at_bin,0.0); // to avoid double counting
		}
	      }
	    }
	  }
	  if (tdet ==2) { // cylinder detector with z axis parallel to normal to surface
	    conversion_factor = fData.D_dim_z/h3d->GetXaxis()->GetBinWidth(1); // This represents how many bins will be in the z direction (by definition the direction of operation). In this way the probability get normalized after integration (if just a single photon travels in the direction of perfect operation (z axis), the integral will be equal to this number)
	    if (conversion_factor == 0.0) std::cout << "Box detector z size= 0: Unphysical detector, the code will fail" << std::endl ; 
	    for (int ii=0 ; ii<ceil(fData.D_dim_z/h3d->GetXaxis()->GetBinWidth(1)) ; ii++) {
	      for (int jj=0 ; jj<ceil(fData.D_dim_x/h3d->GetXaxis()->GetBinWidth(1)) ; jj++) { // It is important to keep the binning of the acceptance histogram the same size in all 3 axis (in this case dim_y = dim_x
		for (int kk=0 ; kk<ceil(fData.D_dim_y/h3d->GetXaxis()->GetBinWidth(1)) ; kk++) {
		  v3at_norm = (double(ii)*h3d->GetXaxis()->GetBinWidth(1)) *norm; // shift in direction norm
		  v3at_perp =  (double(jj)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_x) *v3perp; // shift in direction perp
		  v3at_z = (double(kk)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_y) *v3z; // shift in direction z
		  v3at = v3at_perp + v3at_z; // checking if radius (dim_x/2 = dim_y/2) is less than shift in the detector
		  if (v3at.Mag() < fData.D_dim_x) {
		    v3at =  v3leak + v3at_norm; // adding norm shift to locaction (the TVector3 class just accept a single addition
		    v3at = v3at + v3at_perp; // adding perp shift to location
		    v3at = v3at + v3at_z; // adding z shift to location
		    at_bin = h3at->FindBin(v3at.X(),v3at.Y(),v3at.Z());
		    if (at_det==10 || at_det==100 || at_det==200) h3dbox->Fill(v3at.X(),v3at.Y(),v3at.Z(),h3at->GetBinContent(at_bin));
		    integ = integ + h3at->GetBinContent(at_bin) / conversion_factor;
		    h3at->SetBinContent(at_bin,0.0); // to avoid double counting
		  }
		}
	      }
	    }
	  }
	  if (tdet ==3) { // cylinder detector with z axis perpendicular to normal to surface (I use v3z)
	    conversion_factor = fData.D_dim_x/h3d->GetXaxis()->GetBinWidth(1); // This represents how many bins will be in the x(or y) direction (by definition the direction of operation). In this way the probability get normalized after integration (if just a single photon travels in the direction of perfect operation (x or y axis), the integral will be equal to this number)
	    if (conversion_factor == 0.0) std::cout << "Cylinder detector x size= 0: Unphysical detector, the code will fail" << std::endl ; 
	    for (int ii=0 ; ii<fData.D_dim_z/h3d->GetXaxis()->GetBinWidth(1) ; ii++) {
	      for (int jj=0 ; jj<fData.D_dim_x/h3d->GetXaxis()->GetBinWidth(1) ; jj++) { // It is important to keep the binning of the acceptance histogram the same size in all 3 axis (in this case dim_y = dim_x
		for (int kk=0 ; kk<fData.D_dim_y/h3d->GetXaxis()->GetBinWidth(1) ; kk++) {
		  v3at_norm = (double(ii)*h3d->GetXaxis()->GetBinWidth(1)) *norm; // shift in direction norm
		  v3at_perp =  (double(jj)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_x) *v3perp; // shift in direction perp
		  v3at_z = (double(kk)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_y) *v3z; // shift in direction z
		  v3at = -0.5 * fData.D_dim_z * norm + v3at_perp + v3at_norm; // adding shift since center is not at leak surface
		  // v3at = v3at + v3at_perp;
		  // v3at = v3at + v3at_norm; // checking if radius (dim_z/2) is less than shift in the detector
		  if (v3at.Mag() < fData.D_dim_x) {
		    v3at =  v3leak + v3at_norm; // adding norm shift to locaction (the TVector3 class just accept a single addition
		    v3at = v3at + v3at_perp; // adding perp shift to location
		    v3at = v3at + v3at_z; // adding z shift to location
		    at_bin = h3at->FindBin(v3at.X(),v3at.Y(),v3at.Z());
		    if (at_det==10 || at_det==100 || at_det==200) h3dbox->Fill(v3at.X(),v3at.Y(),v3at.Z(),h3at->GetBinContent(at_bin));
		    integ = integ + h3at->GetBinContent(at_bin) / conversion_factor;
		    h3at->SetBinContent(at_bin,0.0); // to avoid double counting
		  }
		}
	      }
	    }
	  }

	  //	  cout << i << " " << j << " " << k << endl;
	  h3out->SetBinContent(i,j,k,integ); // Set the new value
	  h3at->Delete();
	}
	// now I need to loop in the 3 dimensions with full lenght in dim_z (parallel to norm  and +/- 0.5 length in dim_x and dim_y
	// then I store the integral value (I have constructed the histogram to give me this answer) in a new histogram.
	// since this method has a binning issue a fine binning should solve the problem (also if it will make it slower).
	
      }
    }
  }


 }


void get_detector_coll(int tdet, TH3D *h3d, TH3D *h3loc, TH3D *Hnx, TH3D *Hny, TH3D *Hnz, TH3D *h3out, TH3D *h3dbox) {
  
  //tdet = 1 it is a box detector with z axis parallel to normal to surface
  //tdet = 2 it is a cylinder detector with z axis parallel to normal to surface
  //tdet = 3 it is a cylinder detector with z axis perpendicular to normal to surface (I use v3z) .... not sure how to put a collimator here 
  // conversion factor since we consider just the first bin is 1.

  // at now testing for box
  double integ = 0.0;
  double leak_x, leak_y, leak_z;
  double norm_x, norm_y, norm_z;
  double at_x, at_y, at_z;
  TVector3 norm;
  TVector3 v3z;
  TVector3 v3perp;
  TVector3 v3leak;
  TVector3 v3at;
  TVector3 v3at_norm;
  TVector3 v3at_perp;
  TVector3 v3at_z;
  int at_bin;
  int at_det = 0;
  double test_r;
  
  for (int i =0 ; i< h3loc->GetNbinsX() ; i++) {
    for (int j = 0; j< h3loc->GetNbinsY() ; j++) {
      for (int k =0 ; k< h3loc->GetNbinsZ() ; k++) {
	if (h3loc->GetBinContent(i,j,k) >0.0) { // this bin shows the location where there are leaking photon
	  at_det++;
	  // the normal direction is the z direction of the detector
	  integ = 0.0; // reset the integral to 0.0
	  // in the detector one direction is fixed and is vertical, the other direction is the normal to the surface, the third direction is so fixed.
	  v3z.SetXYZ(0.,0.,1.); // vector parallel to the z axis (vertical here)
	  leak_x = h3loc->GetXaxis()->GetBinCenter(i);
	  leak_y = h3loc->GetYaxis()->GetBinCenter(j);
	  leak_z = h3loc->GetZaxis()->GetBinCenter(k);
	  norm_x = Hnx->GetBinContent(i,j,k);
	  norm_y = Hny->GetBinContent(i,j,k);
	  norm_z = Hnz->GetBinContent(i,j,k);
	  norm.SetXYZ(norm_x,norm_y,norm_z);
	  norm.SetMag(1.); // direction of calibration of detector normalized to 1. 
	  v3perp = norm.Cross(v3z); // now I have the third direction of the detector
	  if (v3perp.Mag() != 1.0 && v3perp.Mag()!=0.0 ) { // norm has a component in the y axis but is not in the y axis
	    v3perp.SetMag(1.); // now set the magnitude to 1 and it is normal to v3z and norm
	    v3z = v3perp.Cross(norm); // now is normal to norm and v3perp and can be used as part of 3 axis
	  }
	  else if (v3perp.Mag() == 0.0) { // this means that norm and v3z are in the same direction
	    v3z.SetXYZ(1.,0.,0.); // now it is parallel to the X axis
	    v3perp = norm.Cross(v3z); // now I have the third direction of the detector    
	  }
	  v3perp.SetMag(1.); // normalize to 1.
	  //	  cout << i << " " << j << " " << k << " " << v3z.X()  << " " << v3z.Y()  << " " << v3z.Z()  << " " << v3perp.X()  << " " << v3perp.Y()  << " " << v3perp.Z() << " " << norm.X()  << " " << norm.Y()  << " " << norm.Z() << endl;

	  //	  cout << "Angle=" << norm.Angle(v3z) << "\t vrperp size =" << v3perp.Mag() << endl;
	  at_x = leak_x ;
	  at_y = leak_y ;
	  at_z = leak_z ;
	  v3leak.SetXYZ(leak_x,leak_y,leak_z);
	  TH3D *h3at = (TH3D *)h3d->Clone("h3at");  // need a clone to set the bin count to 0 when already counted to avoid doublecounting the same bin
	  if (tdet ==1) { // box detector
	    for (int ii=0 ; ii<1 ; ii++) { // just the front bin in Dim_z direction that is parallel to norm
	      for (int jj=0 ; jj<fData.D_dim_x/h3d->GetXaxis()->GetBinWidth(1) ; jj++) { // It is important to keep the binning of the acceptance histogram the same size in all 3 axis
		for (int kk=0 ; kk<fData.D_dim_y/h3d->GetXaxis()->GetBinWidth(1) ; kk++) {
		  v3at_norm = (double(ii)*h3d->GetXaxis()->GetBinWidth(1)) *norm; // shift in direction norm
		  v3at_perp =  (double(jj)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_x) *v3perp; // shift in direction perp
		  v3at_z = (double(kk)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_y) *v3z; // shift in direction z
		  v3at =  v3leak + v3at_norm; // adding norm shift to locaction (the TVector3 class just accept a single addition
		  v3at = v3at + v3at_perp; // adding perp shift to location
		  v3at = v3at + v3at_z; // adding z shift to location
		  at_bin = h3at->FindBin(v3at.X(),v3at.Y(),v3at.Z());
		  if (at_det==10 || at_det==100 || at_det==200) h3dbox->Fill(v3at.X(),v3at.Y(),v3at.Z(),h3at->GetBinContent(at_bin)); // writing down detector number 10
		  integ = integ + h3at->GetBinContent(at_bin) ;
		  h3at->SetBinContent(at_bin,0.0); // to avoid double counting
		}
	      }
	    }
	  }
	  if (tdet ==2) { // cylinder detector with z axis parallel to normal to surface
	    for (int ii=0 ; ii<1 ; ii++) { // just the first bin in the direction
	      for (int jj=0 ; jj<2*fData.D_dim_x/h3d->GetXaxis()->GetBinWidth(1) ; jj++) { // It is important to keep the binning of the acceptance histogram the same size in all 3 axis (in this case dim_y = dim_x
		for (int kk=0 ; kk<2*fData.D_dim_y/h3d->GetXaxis()->GetBinWidth(1) ; kk++) {
		  v3at_norm = (double(ii)*h3d->GetXaxis()->GetBinWidth(1)) *norm; // shift in direction norm
		  v3at_perp =  (double(jj)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_x) *v3perp; // shift in direction perp
		  v3at_z = (double(kk)*h3d->GetXaxis()->GetBinWidth(1)-0.5*fData.D_dim_y) *v3z; // shift in direction z
		  v3at = v3at_perp + v3at_z; // checking if radius (dim_x = dim_y) is less than shift in the detector
		  test_r = v3at.Mag();
		  if (at_det==10 || at_det==100 || at_det==200) {
		    std::cout << at_det << " " << test_r << " " << fData.D_dim_x << v3at.X() << " " << v3at.Y()<< " " << v3at.Z() << std::endl;
		  }
		  if (v3at.Mag() < fData.D_dim_x) {
		    test_r = v3at.Mag();
		    v3at =  v3leak + v3at_norm; // adding norm shift to locaction (the TVector3 class just accept a single addition
		    v3at = v3at + v3at_perp; // adding perp shift to location
		    v3at = v3at + v3at_z; // adding z shift to location
		    at_bin = h3at->FindBin(v3at.X(),v3at.Y(),v3at.Z());
		    if (at_det==10 || at_det==100 || at_det==200) {
		      h3dbox->Fill(v3at.X(),v3at.Y(),v3at.Z(),h3at->GetBinContent(at_bin));
		      std::cout <<"Passed " <<  at_det << " " << test_r << " " << fData.D_dim_x << v3at.X() << " " << v3at.Y()<< " " << v3at.Z() << std::endl;
		    }
		    integ = integ + h3at->GetBinContent(at_bin);
		    h3at->SetBinContent(at_bin,0.0); // to avoid double counting
		  }
		}
	      }
	    }
	  }
	  if (tdet ==3) { // cylinder detector with z axis perpendicular to normal to surface (I use v3z)
	    std::cout << "SORRY, I HAVE NO IDEA HOW TO PUT A COLLIMATOR IN THIS CASE !!!!!!!!!!!!!!" << std::endl;
	  }

	  //	  cout << i << " " << j << " " << k << endl;
	  h3out->SetBinContent(i,j,k,integ); // Set the new value
	  h3at->Delete();
	}
	// now I need to loop in the 3 dimensions with full lenght in dim_z (parallel to norm  and +/- 0.5 length in dim_x and dim_y
	// then I store the integral value (I have constructed the histogram to give me this answer) in a new histogram.
	// since this method has a binning issue a fine binning should solve the problem (also if it will make it slower).
	
      }
    }
  }


 }


void analysis(int tdet, const char name_in[100],const char name_out[100],double n_event) {
  //tdet = 1 it is a box detector with z axis parallel to normal to surface
  //tdet = 2 it is a cylinder detector with z axis parallel to normal to surface
  //tdet = 3 it is a cylinder detector with z axis perpendicular to normal to surface (I use v3z) 


  TFile *_file0 = TFile::Open(name_in);
  TTree *T = (TTree *)_file0->Get("Full");
  TTree *Prop = (TTree *)_file0->Get("T");

  double mom_x, mom_y, mom_z, vert_x, vert_y, vert_z, ener;
  double leak_x, leak_y, leak_z, theta, ener_vert;
  double norm_x, norm_y, norm_z;
  double density;
  int  part_id, event_n;
  T->SetBranchAddress("mom_x",&mom_x);
  T->SetBranchAddress("mom_y",&mom_y);
  T->SetBranchAddress("mom_z",&mom_z);
  T->SetBranchAddress("vert_x",&vert_x);
  T->SetBranchAddress("vert_y",&vert_y);
  T->SetBranchAddress("vert_z",&vert_z);
  T->SetBranchAddress("leak_x",&leak_x);
  T->SetBranchAddress("leak_y",&leak_y);
  T->SetBranchAddress("leak_z",&leak_z);
  T->SetBranchAddress("norm_x",&norm_x);
  T->SetBranchAddress("norm_y",&norm_y);
  T->SetBranchAddress("norm_z",&norm_z);
  T->SetBranchAddress("part_id",&part_id);
  T->SetBranchAddress("ener",&ener);
  T->SetBranchAddress("ener_vert",&ener_vert);
  Prop->SetBranchAddress("density",&density);
  Prop->GetEntry(0); // now density is loaded

  double at_en = 150;
  double weight = 0.0;
  TGraph *efficiency = new TGraph("efficiency.txt"); // in KeV
  // efficiency->SetParameters(800.,300.);

  int bin_histo_x = int(fData.W_dim_x)*2 +40; // ensuring good enough resolution in x y z
  int bin_histo_y = int(fData.W_dim_y)*2 +40;
  int bin_histo_z = int(fData.W_dim_z)*2 +40;

  // TH1D *Htheta = new TH1D("Htheta","Htheta",1000,-3.14,3.14);
  // double theta1, theta2;
  TH3D *Hnx =  new TH3D("Hnx","Norm X",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // cm size bins
  TH3D *Hny =  new TH3D("Hny","Norm Y",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // cm size bins
  TH3D *Hnz =  new TH3D("Hnz","Norm Z",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // cm size bins
  int in;
  double in_v, in_w;

  TH2D *Hxy = new TH2D("Hxy","Histogram XY",100,-0.5,0.5,100,-0.5,0.5);
  TH3D *Hxyz = new TH3D("Hxyz","Histogram XYZ",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // mm size bins
  TH3D *H3dout = new TH3D("H3dout","Histogram XYZ",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // mm size bins
  TH3D *H3dloc = new TH3D("H3dloc","Histogram XYZ",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // mm size bins
  TH3D *H3dbox = new TH3D("H3dbox","Histogram XYZ",bin_histo_x,-fData.W_dim_x/2-10,fData.W_dim_x/2+10,bin_histo_y,-fData.W_dim_y/2-10,fData.W_dim_y/2+10,bin_histo_z,-fData.W_dim_z/2-10,fData.W_dim_z/2+10); // mm size bins

  for (int i=0; i<T->GetEntries(); i++) {
    T->GetEntry(i);
    weight = efficiency->Eval(ener*1000)/n_event;
    if (ener == 200.0) {
      Hxy->Fill(vert_x,vert_y);
    }
    H3dloc->Fill(leak_x,leak_y,leak_z,weight);
    FillHisto(Hxyz,leak_x,leak_y,leak_z,mom_x,mom_y,mom_z,weight);
    in = Hnx->FindBin(leak_x,leak_y,leak_z); // this bin is the same in all these histograms since they have the same dimensions
    in_v =  Hnx->GetBinContent(in);
    in_w = Hnx->GetBinError(in);
    in_v = (in_v *in_w + norm_x) / (in_w + 1.); // this creates an average of norm_x in the bin
    in_w = in_w + 1.; // increase the number of points
    Hnx->SetBinContent(in,in_v);
    Hnx->SetBinError(in,in_w);
    in_v =  Hny->GetBinContent(in);
    in_w = Hny->GetBinError(in);
    //    cout << in_v << " " << in_w << " " << norm_y << " " ;
    in_v = (in_v *in_w + norm_y) / (in_w + 1.); // this creates an average of norm_y in the bin
    in_w = in_w + 1.; // increase the number of points
    //    cout << in_v << " " << in_w << endl;
    Hny->SetBinContent(in,in_v);
    Hny->SetBinError(in,in_w);
    in_v =  Hnz->GetBinContent(in);
    in_w = Hnz->GetBinError(in);
    in_v = (in_v *in_w + norm_z) / (in_w + 1.); // this creates an average of norm_z in the bin
    in_w = in_w + 1.; // increase the number of points
    Hnz->SetBinContent(in,in_v);
    Hnz->SetBinError(in,in_w);
    //    cout << leak_x << " " << leak_y << " " << leak_z << " " << norm_x << " "  << norm_y << " "  << norm_z << endl; 

    //    Hxyz->Fill(leak_x,leak_y,leak_z,weight);
      //      printf("leak_x= %.1f leak_y=%.1f leak_z = %.1f \n",leak_x,leak_y,leak_z);
    // if (TMath::Abs(leak_z) < 20.0 && leak_x !=0. && norm_x!=0.) {
    // 	theta1 = TMath::ATan(leak_y/leak_x);
    // 	theta2 = TMath::ATan(norm_y/norm_x);
    // 	Htheta->Fill(theta1-theta2);
    // }
  }
  //  efficiency->Draw();
  // Htheta->Write();
  if (fData.D_coll == 0) get_detector(tdet,Hxyz,H3dloc,Hnx,Hny,Hnz,H3dout,H3dbox);
  else get_detector_coll(tdet,Hxyz,H3dloc,Hnx,Hny,Hnz,H3dout,H3dbox);
  TFile *fout = new TFile(name_out,"RECREATE");
  efficiency->Write();
  Hxy->Write();
  Hxyz->Write();
  H3dloc->Write();
  Hnx->Write();
  Hny->Write();
  Hnz->Write();
  H3dout->Write();
  H3dbox->Write();

  double volume;
  double gen_weight;
  double total_activity = 0.0;
  if (fData.T_type == 1) {// box
    volume = fData.G_dim_x * fData.G_dim_y * fData.G_dim_z;
    gen_weight = density * volume; // density in g/cm3 , volume in cm3
    total_activity = fData.act_density * gen_weight * 0.037; // act_density is in pCi/g, total activity in Bq  
  }
  else if (fData.T_type == 2) {// Cylinder
    volume = TMath::Pi() * fData.G_dim_x * fData.G_dim_x * fData.G_dim_z;
    gen_weight = density * volume; // density in g/cm3 , volume in cm3
    total_activity = fData.act_density * gen_weight * 0.037; // act_density is in pCi/g, total activity in Bq  
  }
  std::cout << "volume =" << volume << "cm3 \t weight =" << gen_weight << "g \t total activity=" << total_activity << "Bq " << std::endl;
  TH3D *H3dactivity = (TH3D *)H3dout->Clone("Activity3D");  // need a clone to multiply by the total activity
  H3dactivity->SetTitle("Activity, events/s in detector");
  H3dactivity->Scale(total_activity);
  H3dactivity->Write();
  // fout->Close();
}

