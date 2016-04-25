#include "TString.h"
#include <iostream>

int dotilemapper(TString);

ofstream mpv("mpv.txt");

void tilemapper_RB()
{

  dotilemapper("data/beam_00002353-0000.root"); // test position all 8 tiles (one appears to be disconnected/off)
  dotilemapper("data/beam_00002354-0000.root");
  dotilemapper("data/beam_00002355-0000.root");
  dotilemapper("data/beam_00002357-0000.root");
  dotilemapper("data/beam_00002358-0000.root");
  dotilemapper("data/beam_00002359-0000.root");
  dotilemapper("data/beam_00002361-0000.root");
  dotilemapper("data/beam_00002363-0000.root");
  dotilemapper("data/beam_00002364-0000.root");
  dotilemapper("data/beam_00002365-0000.root");
  dotilemapper("data/beam_00002366-0000.root");
  dotilemapper("data/beam_00002367-0000.root");
  dotilemapper("data/beam_00002368-0000.root");
  dotilemapper("data/beam_00002369-0000.root");
  dotilemapper("data/beam_00002370-0000.root");
  dotilemapper("data/beam_00002371-0000.root");
  dotilemapper("data/beam_00002372-0000.root");
  dotilemapper("data/beam_00002374-0000.root");
  dotilemapper("data/beam_00002375-0000.root");
  
}

int dotilemapper( TString filename )
{

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

  TFile *fout = new TFile(outfilename,"recreate");
  fout->cd();

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

    //    cutstring += " && TH1>50 && TH8>100";

    cout << i+1 << " Draw(" << drawstring << "," << cutstring << ")" << endl;

    c1->cd(ican++);
    //    W->Draw(drawstring,cutstring);
    //W->Fit("landau",drawstring,cutstring);
    W->Fit("flandau",drawstring,cutstring);
    float mean = flandau->GetParameter(1);
    cout << "the mean is " << mean << endl;
    mpv << mean << " ";
  }
  mpv<<endl;

  TString pdffilename = "output/tilemapper_";
  pdffilename += gSystem->BaseName( filename );
  pdffilename.ReplaceAll(".root",".pdf");
  c1->Print(pdffilename,"pdf Portrait");
  pdffilename.ReplaceAll(".pdf",".png");
  c1->Print(pdffilename,"png Portrait");

  fout->Write();
  fout->Close();
  delete fout;

}
