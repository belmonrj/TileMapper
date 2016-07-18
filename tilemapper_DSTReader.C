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

  for ( int i = 0; i < 8; ++i )
    {

      TString drawstring1 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring1 += i*2;
      drawstring1 += "].energy>>hs1_";
      drawstring1 += i+1;
      drawstring1 += "(100,0,400)";
      cout << "draw string is " << drawstring1 << endl;

      c1->cd(i+1);
      tree->Draw(drawstring1,"","");

      TString drawstring2 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring2 += i*2;
      drawstring2 += "].energy>>hs2_";
      drawstring2 += i+1;
      drawstring2 += "(100,0,400)";
      cout << "draw string is " << drawstring2 << endl;

      c2->cd(i+1);
      tree->Draw(drawstring2,"Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL","");

      TString drawstring3 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring3 += i*2;
      drawstring3 += "].energy>>hs3_";
      drawstring3 += i+1;
      drawstring3 += "(100,0,400)";
      cout << "draw string is " << drawstring3 << endl;

      c3->cd(i+1);
      tree->Draw(drawstring3,"Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL && abs(TOWER_CALIB_C2[3].energy)<200","");

      TString drawstring4 = "TOWER_CALIB_TILE_MAPPER[";
      drawstring4 += i*2;
      drawstring4 += "].energy>>hs4_";
      drawstring4 += i+1;
      drawstring4 += "(100,0,400)";
      cout << "draw string is " << drawstring4 << endl;

      c4->cd(i+1);
      tree->Draw(drawstring4,"Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL && abs(TOWER_CALIB_C2[3].energy)>200","");

    }

  c1->Print(Form("mapper_run%d_step1.png",run));
  c2->Print(Form("mapper_run%d_step2.png",run));
  c3->Print(Form("mapper_run%d_step3.png",run));
  c3->Print(Form("mapper_run%d_step4.png",run));

  delete c1;
  delete c2;
  delete c3;
  delete c4;

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


