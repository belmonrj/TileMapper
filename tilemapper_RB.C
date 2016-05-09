#include "TString.h"
#include <iostream>

//int dotilemapper(TString);
int dotilemapper(TString, int, int);

ofstream fout("mpv.txt");

void tilemapper_RB()
{

  // dotilemapper("data/beam_00002353-0000.root",1,0); // 2353 976 180  1 0
  // dotilemapper("data/beam_00002354-0000.root",0,0); // 2354 1076 180 0 0
  // dotilemapper("data/beam_00002355-0000.root",2,0); // 2355 690 180  2 0
  // dotilemapper("data/beam_00002356-0000.root",3,0); // 2356 410 180  3 0
  // dotilemapper("data/beam_00002357-0000.root",4,0); // 2357 215 180  4 0
  // dotilemapper("data/beam_00002358-0000.root",4,1); // 2358 215 100  4 1
  // dotilemapper("data/beam_00002359-0000.root",3,1); // 2359 410 100  3 1
  // dotilemapper("data/beam_00002361-0000.root",2,1); // 2361 690 100  2 1
  // dotilemapper("data/beam_00002362-0000.root",1,1); // 2362 976 100  1 1
  // dotilemapper("data/beam_00002363-0000.root",0,1); // 2363 1076 100 0 1
  // dotilemapper("data/beam_00002364-0000.root",0,1); // 2364 1056 167 0 1
  // dotilemapper("data/beam_00002366-0000.root",1,1); // 2366 1016 167 1 1
  // dotilemapper("data/beam_00002367-0000.root",2,1); // 2367 976 167  2 1
  // dotilemapper("data/beam_00002368-0000.root",3,1); // 2368 936 167  3 1
  // dotilemapper("data/beam_00002369-0000.root",4,1); // 2369 896 167  4 1
  // dotilemapper("data/beam_00002370-0000.root",4,0); // 2370 896 209  4 0
  // dotilemapper("data/beam_00002371-0000.root",3,0); // 2371 936 209  3 0
  // dotilemapper("data/beam_00002373-0000.root",2,0); // 2373 976 209  2 0
  // dotilemapper("data/beam_00002374-0000.root",1,0); // 2374 1016 209 1 0
  // dotilemapper("data/beam_00002375-0000.root",0,0); // 2375 1056 209 0 0

  dotilemapper("data/beam_00002669-0000.root",1,0); // 2669  976 180  7268
  dotilemapper("data/beam_00002670-0000.root",0,1); // 2670 1056 167  10981
  dotilemapper("data/beam_00002671-0000.root",1,1); // 2671 1016 167  11060
  dotilemapper("data/beam_00002672-0000.root",2,1); // 2672  976 167  11060
  dotilemapper("data/beam_00002673-0000.root",3,1); // 2673  936 167  11139
  dotilemapper("data/beam_00002674-0000.root",4,1); // 2674  896 167  14694
  dotilemapper("data/beam_00002675-0000.root",1,0); // 2675  976 180  10349
  dotilemapper("data/beam_00002676-0000.root",0,0); // 2676 1076 180  10902
  dotilemapper("data/beam_00002677-0000.root",2,0); // 2677  690 180  7979
  dotilemapper("data/beam_00002678-0000.root",2,0); // 2678  690 180  10823
  dotilemapper("data/beam_00002679-0000.root",3,0); // 2679  410 180  11060
  dotilemapper("data/beam_00002680-0000.root",4,0); // 2680  215 180  10902
  dotilemapper("data/beam_00002681-0000.root",4,0); // 2681  896 209  10981
  dotilemapper("data/beam_00002682-0000.root",3,0); // 2682  936 209  11534
  dotilemapper("data/beam_00002683-0000.root",2,0); // 2683  976 209  11060
  dotilemapper("data/beam_00002684-0000.root",1,0); // 2684 1016 209  10981
  dotilemapper("data/beam_00002685-0000.root",0,0); // 2685 1056 209  10981
  dotilemapper("data/beam_00002686-0000.root",0,1); // 2686 1076 100  10981
  dotilemapper("data/beam_00002687-0000.root",1,1); // 2687  976 100  10981
  dotilemapper("data/beam_00002688-0000.root",9,1); // 2688  770 100  11139
  dotilemapper("data/beam_00002689-0000.root",2,1); // 2689  690 100  11613
  dotilemapper("data/beam_00002690-0000.root",3,1); // 2690  410 100  11139
  dotilemapper("data/beam_00002691-0000.root",4,1); // 2691  215 100  11060

}

int dotilemapper ( TString filename, int xbin, int ybin )
{

  fout << xbin << " " << ybin << " ";

  gROOT->SetStyle("Modern");
  gStyle->SetOptFit(111);

  TFile *f = TFile::Open(filename);
  //TCanvas *c1 = new TCanvas("c1","Tiletester high gain",640,480);
  TCanvas *c1 = new TCanvas("c1","Tiletester high gain",1280,960);
  c1->Divide(4,2);
  //  c1->Divide(2,2);

  TTree *W = (TTree *)f->Get("W");

  TString outfilename = "output/tilemapper_";
  outfilename += gSystem->BaseName( filename );

  TFile *foutput = new TFile(outfilename,"recreate");
  foutput->cd();

  TString adc;
  TString name;
  int tower_number = 1;
  for (int i = 176; i < 192; i+=2 ) {
    name = "TH";
    name += tower_number;

    adc = "TMath::Abs(peak[";
    adc += i;
    adc += "]-pedestal[";
    adc += i;
    adc += "])";

    W->SetAlias(name,adc);
    cout << name << " " << adc << endl;
    tower_number++;
  }

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
  for (int i = 0; i < 8; i++ ) {
    hname = "tt";
    hname += i;

    drawstring = "TH";
    drawstring += i+1;
    drawstring += ">>";
    drawstring += hname;
    drawstring += "(100,0.0,500.0)";

    cutstring = "TH";
    cutstring += i+1;
    cutstring += ">6.0";

    // cutstring += " && TH1>50 && TH8>100";

    cout << i+1 << " Draw(" << drawstring << "," << cutstring << ")" << endl;

    c1->cd(ican++);
    // W->Draw(drawstring,cutstring);
    // W->Fit("landau",drawstring,cutstring);
    W->Fit("flandau",drawstring,cutstring);
    // W->Fit("okayfun",drawstring,cutstring);
    // float mean = flandau->GetParameter(1);
    float mean = flandau->GetMaximumX();
    // float mean = okayfun->GetMaximumX();
    cout << "the mean is " << mean << endl;
    fout << mean << " ";
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
