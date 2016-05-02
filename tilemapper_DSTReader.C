TChain* GetChainFromRunList(const char*);

void AnalysisWithChain();

void AnalysisWithTree();
void DoAnalysisWithTree(TString,int);



void tilemapper_DSTReader()
{

  AnalysisWithTree();

}


void AnalysisWithTree()
{

  ifstream fin("runs_groups12.txt");
  int run;
  TString filename;
  while ( fin >> run )
    {
      filename = "JinData/beam_0000";
      filename += run;
      filename += "-0000_DSTReader.root";
      TFile* file = TFile::Open(filename);
      DoAnalysisWithTree(file,run);
    }

}



void DoAnalysisWithTree(TFile* file, int run)
{

  TCanvas* c1 = new TCanvas("c1","");

  TTree* tree = (TTree*)file->Get("T");

  tree->SetAlias("Average_HODO_HORIZONTAL","Sum$(TOWER_CALIB_HODO_HORIZONTAL.towerid * (abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) * abs(TOWER_CALIB_HODO_HORIZONTAL.energy))/Sum$((abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) * abs(TOWER_CALIB_HODO_HORIZONTAL.energy))");
  tree->SetAlias("Average_HODO_VERTICAL","Sum$(TOWER_CALIB_HODO_VERTICAL.towerid * (abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) * abs(TOWER_CALIB_HODO_VERTICAL.energy))/Sum$((abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) * abs(TOWER_CALIB_HODO_VERTICAL.energy))");
  tree->SetAlias("Valid_HODO_HORIZONTAL","Sum$(abs(TOWER_CALIB_HODO_HORIZONTAL.energy)>30) > 0");
  tree->SetAlias("Valid_HODO_VERTICAL","Sum$(abs(TOWER_CALIB_HODO_VERTICAL.energy)>30) > 0");

  tree->Draw("TOWER_CALIB_TILE_MAPPER[4].energy>>h1(100,0,400)","","");
  c1->Print(Form("mapper_run%d_step1.png",run));
  tree->Draw("TOWER_CALIB_TILE_MAPPER[4].energy>>h2(100,0,400)","Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL","");
  c1->Print(Form("mapper_run%d_step2.png",run));
  tree->Draw("TOWER_CALIB_TILE_MAPPER[4].energy>>h3(100,0,400)","Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL && abs(TOWER_CALIB_C2[3].energy)>200","");
  c1->Print(Form("mapper_run%d_step3.png",run));

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

// void storage()
// {
//   T->Draw("TOWER_CALIB_TILE_MAPPER[4].energy>>h1(100,0,400)","Valid_HODO_VERTICAL && Valid_HODO_HORIZONTAL && abs(TOWER_CALIB_C2[3].energy)>200","")
// }


