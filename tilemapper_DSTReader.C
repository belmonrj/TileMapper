TChain* GetChainFromRunList(const char*);

void AnalysisWithTree();
void DoAnalysisWithTree(TString,int);


void AnalysisWithChain();



void tilemapper_DSTReader()
{

  AnalysisWithTree();

}


void AnalysisWithTree()
{

  //ifstream fin("runs_groups12.txt");
  ifstream fin("runs_group3.txt");
  int run;
  TString filename;
  while ( fin >> run )
    {
      filename = "JinData/beam_0000";
      filename += run;
      filename += "-0000_DSTReader.root";
      TFile* file = TFile::Open(filename);
      DoAnalysisWithTree(file,run);
      break;  // testing
    }

}



void DoAnalysisWithTree(TFile* file, int run)
{

  TF1* flandau = new TF1("flandau","landau",0,400);

  TCanvas *c1 = new TCanvas("c1","",1280,960);
  c1->Divide(4,2);

  TCanvas *c2 = new TCanvas("c2","",1280,960);
  c2->Divide(4,2);

  TCanvas *c3 = new TCanvas("c3","",1280,960);
  c3->Divide(4,2);

  TCanvas *c4 = new TCanvas("c4","",1280,960);
  c4->Divide(4,2);


  TTree* tree = (TTree*)file->Get("T");

  tree->SetAlias("Average_HODO_HORIZONTAL","Sum$(TOWER_CALIB_HODO_HORIZONTAL.towerid * (abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) * abs(TOWER_CALIB_HODO_HORIZONTAL.energy))/Sum$((abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) * abs(TOWER_CALIB_HODO_HORIZONTAL.energy))");
  tree->SetAlias("Average_HODO_VERTICAL","Sum$(TOWER_CALIB_HODO_VERTICAL.towerid * (abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) * abs(TOWER_CALIB_HODO_VERTICAL.energy))/Sum$((abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) * abs(TOWER_CALIB_HODO_VERTICAL.energy))");
  tree->SetAlias("Valid_HODO_HORIZONTAL","Sum$(abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) > 0");
  tree->SetAlias("Valid_HODO_VERTICAL","Sum$(abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) > 0");

  ofstream fout((const char*)Form("DataRunByRun/mapper_run%d.dat",run));

  for ( int i = 0; i < 8; ++i )
    {

      TString drawstring1 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring1 += i*2;
      drawstring1 += "].energy>>hs1_";
      drawstring1 += i+1;
      drawstring1 += "(100,0,400)";

      c1->cd(i+1);
      tree->Fit("flandau",drawstring1,"","","");

      TString drawstring2 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring2 += i*2;
      drawstring2 += "].energy>>hs2_";
      drawstring2 += i+1;
      drawstring2 += "(100,0,400)";

      c2->cd(i+1);
      tree->Fit("flandau",drawstring2,"Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL","","");
      fout << run << " " << 9999 << " " << 9999 << " " << flandau->GetParameter(1) << " " << flandau->GetParError(1) << endl;

      TString drawstring3 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring3 += i*2;
      drawstring3 += "].energy>>hs3_";
      drawstring3 += i+1;
      drawstring3 += "(100,0,400)";

      c3->cd(i+1);
      tree->Fit("flandau",drawstring3,"Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL && abs(TOWER_CALIB_C2[3].energy)<200","","");

      TString drawstring4 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring4 += i*2;
      drawstring4 += "].energy>>hs4_";
      drawstring4 += i+1;
      drawstring4 += "(100,0,400)";

      c4->cd(i+1);
      tree->Fit("flandau",drawstring4,"Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL && abs(TOWER_CALIB_C2[3].energy)>200","","");

    }

  c1->Print(Form("FigsRunByRun/mapper_run%d_step1.png",run));
  c2->Print(Form("FigsRunByRun/mapper_run%d_step2.png",run));
  c3->Print(Form("FigsRunByRun/mapper_run%d_step3.png",run));
  c4->Print(Form("FigsRunByRun/mapper_run%d_step4.png",run));
  c1->Print(Form("FigsRunByRun/mapper_run%d_step1.pdf",run));
  c2->Print(Form("FigsRunByRun/mapper_run%d_step2.pdf",run));
  c3->Print(Form("FigsRunByRun/mapper_run%d_step3.pdf",run));
  c4->Print(Form("FigsRunByRun/mapper_run%d_step4.pdf",run));

  delete c1;
  delete c2;
  delete c3;
  delete c4;

  // --- let's try to have a look at the hodoscope positions

  TCanvas* c5 = new TCanvas("c5","",800,800);
  TH2D* th2d_hodo_fine = new TH2D("th2d_hodo_fine","",40,-0.5,7.5,40,-0.5,7.5);
  TH2D* th2d_hodo_coarse = new TH2D("th2d_hodo_coarse","",8,-0.5,7.5,8,-0.5,7.5);
  th2d_hodo_fine->GetXaxis()->SetTitle("Horizontal Hodoscope");
  th2d_hodo_fine->GetYaxis()->SetTitle("Vertical Hodoscope");
  th2d_hodo_coarse->GetXaxis()->SetTitle("Horizontal Hodoscope");
  th2d_hodo_coarse->GetYaxis()->SetTitle("Vertical Hodoscope");
  tree->Draw("Average_HODO_HORIZONTAL:Average_HODO_VERTICAL>>th2d_hodo_fine","Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL","colz");
  c5->Print(Form("FigsRunByRun/hodoscope_fine_run%d.png",run));
  c5->Print(Form("FigsRunByRun/hodoscope_fine_run%d.pdf",run));
  tree->Draw("Average_HODO_HORIZONTAL:Average_HODO_VERTICAL>>th2d_hodo_coarse","Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL","colz");
  c5->Print(Form("FigsRunByRun/hodoscope_coarse_run%d.png",run));
  c5->Print(Form("FigsRunByRun/hodoscope_coarse_run%d.pdf",run));
  delete c5;

  // --- now lets try to look at the distributions for each hodoscope position

  TCanvas* c6 = new TCanvas("c6","",1280,960);
  c6->Divide(4,2);

  for ( int indexHorizontal = 0; indexHorizontal < 8; ++indexHorizontal)
    {
      for ( int indexVertical = 0; indexVertical < 8; ++indexVertical )
        {
          for ( int indexTile = 0; indexTile < 8; ++indexTile )
            {
              TString drawstring = "TOWER_CALIB_TILE_MAPPER[";
              drawstring += indexTile*2;
              drawstring += "].energy>>hs_";
              drawstring += indexTile+1;
              drawstring += "(100,0,400)";
              cout << "drawstring is " << drawstring << endl;

              TString cutstring = "Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL";
              cutstring += " && abs(Average_HODO_HORIZONTAL-";
              cutstring += indexHorizontal;
              cutstring += ")<0.5";
              cutstring += " && abs(Average_HODO_VERTICAL-";
              cutstring += indexVertical;
              cutstring += ")<0.5";
              cout << "cutstring is " << cutstring << endl;

              c6->cd(indexTile+1);
              tree->Fit("flandau",drawstring,cutstring,"","");
              fout << run << " " << indexHorizontal << " " << indexVertical << " " << flandau->GetParameter(1) << " " << flandau->GetParError(1) << endl;
            }
          c6->Print(Form("FigsRunByRun/HodoscopeGridFigs/mapper_run%d_H%dV%d.png",run,indexHorizontal,indexVertical));
          c6->Print(Form("FigsRunByRun/HodoscopeGridFigs/mapper_run%d_H%dV%d.pdf",run,indexHorizontal,indexVertical));
        }
    }
  fout.close();

  delete c6;

}



void AnalysisWithChain()
{

  TCanvas* c1 = new TCanvas("c1","");

  TChain* chain = GetChainFromRunList("runs_groups12.txt");
  chain->SetAlias("Valid_HODO_HORIZONTAL","Sum$(abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) > 0");
  chain->SetAlias("Valid_HODO_VERTICAL","Sum$(abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) > 0");

  chain->Draw("TOWER_CALIB_TILE_MAPPER[4].energy>>h1(100,0,400)","Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL","");

  c1->Print("groups12.png");

}



TChain* GetChainFromRunList(const char* listname)
{

  ifstream fin(listname);
  int run;
  TString filename;
  TChain* chain = new TChain("T");
  cout << "chain address is " << chain << endl;
  while ( fin >> run )
    {
      filename = "JinData/beam_0000";
      filename += run;
      filename += "-0000_DSTReader.root";
      chain->Add(filename);
    }

  return chain;

}


