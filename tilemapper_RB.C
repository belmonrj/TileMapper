#include "TString.h"
#include <iostream>

//int dotilemapper(TString);
//int dotilemapper(TString, int, int);
int dotilemapper(TString, int, int, float, float);


ofstream fout("mpv.txt");


void tilemapper_RB()
{

  // --- outer tile scan
  dotilemapper("JinData/beam_00003801-0000_DSTReader.root",0,0,0,0);

}



int dotilemapper ( TString filename, int xbin, int ybin, float x, float y )
{

  fout << xbin << " " << ybin << " ";
  fout << x << " " << y << " ";

  gROOT->SetStyle("Modern");
  gStyle->SetOptFit(111);

  TFile *f = TFile::Open(filename);
  // TCanvas *c1 = new TCanvas("c1","Tiletester high gain",640,480);
  TCanvas *c1 = new TCanvas("c1","Tiletester high gain",1280,960);
  c1->Divide(4,2);
  // c1->Divide(2,2);

  // TTree *W = (TTree *)f->Get("W");
  TTree* tree = (TTree*)f->Get("T");
  tree->SetAlias("Average_HODO_HORIZONTAL","Sum$(TOWER_CALIB_HODO_HORIZONTAL.towerid * (abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) * abs(TOWER_CALIB_HODO_HORIZONTAL.energy))/Sum$((abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) * abs(TOWER_CALIB_HODO_HORIZONTAL.energy))");
  tree->SetAlias("Average_HODO_VERTICAL","Sum$(TOWER_CALIB_HODO_VERTICAL.towerid * (abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) * abs(TOWER_CALIB_HODO_VERTICAL.energy))/Sum$((abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) * abs(TOWER_CALIB_HODO_VERTICAL.energy))");
  tree->SetAlias("Valid_HODO_HORIZONTAL","Sum$(abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) > 0");
  tree->SetAlias("Valid_HODO_VERTICAL","Sum$(abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) > 0");

  TString outfilename = "output/tilemapper_";
  outfilename += gSystem->BaseName( filename );

  TFile *foutput = new TFile(outfilename,"recreate");
  foutput->cd();

  TString adc;
  TString name;
  //  int tower_number = 1;
  // for (int i = 176; i < 192; i+=2 ) {
  //   name = "TH";
  //   name += tower_number;

  //   adc = "TMath::Abs(peak[";
  //   adc += i;
  //   adc += "]-pedestal[";
  //   adc += i;
  //   adc += "])";

  //   W->SetAlias(name,adc);
  //   cout << name << " " << adc << endl;
  //   tower_number++;
  // }

  TF1 *flandau = new TF1("flandau","landau",0,500);

  TF1 *okayfun = new TF1("okayfun","landau(0) + gaus(3)",0,500);
  okayfun->SetParameter(0,4000);
  okayfun->SetParameter(1,100);
  okayfun->SetParameter(2,10);
  okayfun->SetParameter(3,4000);
  okayfun->SetParameter(4,100);
  okayfun->SetParameter(5,10);

  okayfun->SetParLimits(0,1e0,1e5);
  okayfun->SetParLimits(1,0,500);
  okayfun->SetParLimits(2,0,500);
  okayfun->SetParLimits(3,1e0,1e5);
  okayfun->SetParLimits(4,0,500);
  okayfun->SetParLimits(5,0,500);



  TString drawstring;
  TString cutstring;
  TString hname;
  int ican = 1;
  for (int i = 0; i < 8; i++ )
    {
      // hname = "tt";
      // hname += i;

      // drawstring = "TH";
      // drawstring += i+1;
      // drawstring += ">>";
      // drawstring += hname;
      // drawstring += "(100,0.0,500.0)";

      // cutstring = "TH";
      // cutstring += i+1;
      // cutstring += ">6.0";

      drawstring = "TOWER_CALIB_TILE_MAPPER[";
      drawstring += i*2;
      drawstring += "].energy>>hs2_";
      drawstring += i+1;
      drawstring += "(100,0,500)";

      // cutstring += " && TH1>50 && TH8>100";
      // cutstring = "Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL";
      cutstring = "TOWER_CALIB_TILE_MAPPER[";
      cutstring += i*2;
      cutstring += "].energy>6.0";

      cutstring += " && Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL";

      cout << i+1 << " Draw(" << drawstring << "," << cutstring << ")" << endl;

      c1->cd(ican++);
      // W->Draw(drawstring,cutstring);
      // W->Fit("landau",drawstring,cutstring);
      //W->Fit("flandau",drawstring,cutstring);
      tree->Fit("flandau",drawstring,cutstring);
      // W->Fit("okayfun",drawstring,cutstring);
      // float mean = flandau->GetParameter(1);
      float mean = flandau->GetMaximumX();
      float emean = flandau->GetParError(1);
      // float mean = okayfun->GetMaximumX();
      cout << "the mean is " << mean << " +- " << emean << endl;
      fout << mean << " " << emean << " ";
    }
  fout<<endl;

  TString pdffilename = "output/tilemapper_";
  pdffilename += gSystem->BaseName( filename );
  pdffilename.ReplaceAll(".root",".pdf");
  c1->Print(pdffilename,"pdf Portrait");
  pdffilename.ReplaceAll(".pdf",".png");
  c1->Print(pdffilename,"png Portrait");

  foutput->Write();
  foutput->Close();
  delete foutput;

  return 0; // this used to have a return value...

}
