TChain* GetChainFromRunList(const char*);



void tilemapper_DSTReader()
{

  TChain* chain = GetChainFromRunList("group1.txt");

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
