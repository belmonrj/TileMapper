void john();
void john_data();
void john_data(int);
void edward();


void simple_geo()
{

  //john();
  john_data();
  //edward();

}


void john_data()
{

  john_data(1);
  john_data(2);
  john_data(3);
  john_data(4);
  john_data(5);
  john_data(6);
  john_data(7);
  john_data(8);

}


void john_data(int whichtile)
{

  if ( whichtile < 1 || whichtile > 8 )
    {
      cout << "Invalid tyle selection" << endl;
      return;
    }

  bool innertile = whichtile > 4;

  //TCanvas *c1 = new TCanvas("c1","",950,360);
  //TCanvas *c1 = new TCanvas("c1","",1900,720);
  TCanvas *c1 = new TCanvas("c1","",1900,520);
  c1->Range(350,-10,1300,250);

  cout << 1900/float(1300-350) << " " << 520/260.0 << endl;



  float xouterhcal[5] = {365,387,1236,1219,365};
  float youterhcal[5] = {0,241,171,0,0};
  TPolyLine *tpl_outerhcal = new TPolyLine(5,xouterhcal,youterhcal,"F");
  tpl_outerhcal->SetLineColor(kBlack);
  if ( innertile ) tpl_outerhcal->SetLineColor(kGray);
  tpl_outerhcal->Draw("l");

  float outerangle = atan2(387-365,241);
  cout << "outerangle is " << outerangle*180.0/3.14159 << endl;

  float xinnerhcal[5] = {365,376,590,580,365};
  float yinnerhcal[5] = {0,127,114,0,0};
  TPolyLine *tpl_innerhcal = new TPolyLine(5,xinnerhcal,yinnerhcal,"F");
  tpl_innerhcal->SetLineColor(kGray);
  if ( innertile ) tpl_innerhcal->SetLineColor(kBlack);
  tpl_innerhcal->Draw("l");
  if ( !innertile ) tpl_outerhcal->Draw("l");

  float innerangle = atan2(376-365,127);
  cout << "innerangle is " << innerangle*180.0/3.14159 << endl;

  TMarker *tm_outersipm = new TMarker(368,36,kFullCircle);
  tm_outersipm->SetMarkerColor(kBlack);
  if ( innertile ) tm_outersipm->SetMarkerColor(kGray);
  tm_outersipm->Draw();
  TMarker *tm_innersipm = new TMarker(368,31,kFullCircle);
  tm_innersipm->SetMarkerColor(kGray);
  if ( innertile ) tm_innersipm->SetMarkerColor(kBlack);
  tm_innersipm->Draw();
  if ( !innertile ) tm_outersipm->Draw();


  ifstream fin("mpv.txt");

  int temp_int;
  float temp_float;
  float scan1x;
  float scan1y;
  float mpv_array[8];
  float empv_array[8];
  float mpv_value;
  TMarker *tm_scan1[20];
  TLatex tex;
  for ( int i = 0; i < 20; ++i )
    {
      fin>>temp_int>>temp_int;
      fin>>scan1x>>scan1y;
      for ( int j = 0; j < 8; ++j ) fin>>mpv_array[j]>>empv_array[j];
      mpv_value = mpv_array[whichtile-1];
      scan1x = 1076 - scan1x + 365;
      scan1y = 252 - scan1y;
      tm_scan1[i] = new TMarker(scan1x,scan1y,kFullCircle);
      tm_scan1[i]->SetMarkerColor(kBlue);
      tm_scan1[i]->Draw();
      tex.SetTextSize(0.06);
      tex.DrawLatex(scan1x,scan1y,Form("%.1f",mpv_value));
    }

  c1->Print(Form("figs/data_survey_tile%d.png",whichtile));
  c1->Print(Form("figs/data_survey_tile%d.pdf",whichtile));

  delete c1;

}



void john()
{

  //TCanvas *c1 = new TCanvas("c1","",950,360);
  //TCanvas *c1 = new TCanvas("c1","",1900,720);
  TCanvas *c1 = new TCanvas("c1","",1900,520);
  c1->Range(350,-10,1300,250);

  cout << 1900/float(1300-350) << " " << 520/260.0 << endl;



  float xouterhcal[5] = {365,387,1236,1219,365};
  float youterhcal[5] = {0,241,171,0,0};
  TPolyLine *tpl_outerhcal = new TPolyLine(5,xouterhcal,youterhcal,"F");
  tpl_outerhcal->SetLineColor(kBlack);
  tpl_outerhcal->Draw("l");

  float outerangle = atan2(387-365,241);
  cout << "outerangle is " << outerangle*180.0/3.14159 << endl;

  float xinnerhcal[5] = {365,376,590,580,365};
  float yinnerhcal[5] = {0,127,114,0,0};
  TPolyLine *tpl_innerhcal = new TPolyLine(5,xinnerhcal,yinnerhcal,"F");
  tpl_innerhcal->SetLineColor(kBlack);
  tpl_innerhcal->Draw("l");

  float innerangle = atan2(376-365,127);
  cout << "innerangle is " << innerangle*180.0/3.14159 << endl;

  TMarker *tm_outersipm = new TMarker(368,36,kFullCircle);
  tm_outersipm->Draw();
  TMarker *tm_innersipm = new TMarker(368,31,kFullCircle);
  tm_innersipm->Draw();


  float scan1x[10] = {1076,
		       976,
		       690,
		       410,
		       215,
		       215,
		       410,
		       690,
		       976,
		      1076};

  float scan1y[10] = {180,
		      180,
		      180,
		      180,
		      180,
		      100,
		      100,
		      100,
		      100,
		      100};

  TMarker *tm_scan1[10];
  for ( int i = 0; i < 10; ++i )
    {
      scan1x[i] = 1076 - scan1x[i] + 365;
      scan1y[i] = 252 - scan1y[i];
      tm_scan1[i] = new TMarker(scan1x[i],scan1y[i],kFullCircle);
      tm_scan1[i]->SetMarkerColor(kBlue);
      tm_scan1[i]->Draw();
    }

  float scan2x[10] = {1056,
		      1016,
		       976,
		       936,
		       896,
		       896,
		       936,
		       976,
		      1016,
		      1056};

  float scan2y[10] = {167,
		      167,
		      167,
		      167,
		      167,
		      209,
		      209,
		      209,
		      209,
		      209};

  TMarker *tm_scan2[10];
  for ( int i = 0; i < 10; ++i )
    {
      scan2x[i] = 1076 - scan2x[i] + 365;
      scan2y[i] = 252 - scan2y[i];
      cout << scan2x[i] << " " << scan2y[i] << endl;
      tm_scan2[i] = new TMarker(scan2x[i],scan2y[i],kFullCircle);
      tm_scan2[i]->SetMarkerColor(kRed);
      tm_scan2[i]->Draw();
    }

  c1->Print("survey_diagram.png");

  delete c1;

}



void edward()
{

  TCanvas *c1 = new TCanvas("c1","",1900,568);
  c1->Range(-10,-10,860,250);

  cout << 1900/870.0 << " " << 568/260.0 << endl;

  float xouterhcal[5] = {0,0,848,848,0};
  float youterhcal[5] = {0,241,165,0,0};
  TPolyLine *tpl_outerhcal = new TPolyLine(5,xouterhcal,youterhcal,"F");
  tpl_outerhcal->SetLineColor(kBlack);
  tpl_outerhcal->Draw("l");

  // float outerangle = atan2(387-365,241);
  // cout << "outerangle is " << outerangle*180.0/3.14159 << endl;

  float xinnerhcal[5] = {0,95,343,254,0};
  float yinnerhcal[5] = {0,127,111,0,0};
  TPolyLine *tpl_innerhcal = new TPolyLine(5,xinnerhcal,yinnerhcal,"F");
  tpl_innerhcal->SetLineColor(kBlack);
  tpl_innerhcal->Draw("l");

  float scan1x[13]={0};
  float scan1y[13]={0};

  // --- corners
  scan1x[0] = xouterhcal[0] + 20;
  scan1y[0] = youterhcal[0] + 20;
  scan1x[1] = xouterhcal[1] + 20;
  scan1y[1] = youterhcal[1] - 20;
  scan1x[2] = xouterhcal[2] - 20;
  scan1y[2] = youterhcal[2] - 20;
  scan1x[3] = xouterhcal[3] - 20;
  scan1y[3] = youterhcal[3] + 20;

  // --- center
  scan1x[4] = xouterhcal[3]/2.0;
  scan1y[4] = 20;
  scan1x[5] = xouterhcal[3]/2.0;
  scan1y[5] = (youterhcal[1]+youterhcal[2])/2.0 - 20;

  // --- left edge center
  scan1x[6] = 20;
  scan1y[6] = youterhcal[1]/2.0;
  // --- right edge center
  // scan1x[7] = xouterhcal[3] - 20;
  // scan1y[7] = youterhcal[2]/2.0;

  scan1x[7] = scan1x[0] + 20;
  scan1y[7] = scan1y[0];
  scan1x[8] = scan1x[1] + 20;
  scan1y[8] = scan1y[1];
  scan1x[9] = scan1x[6] + 20;
  scan1y[9] = scan1y[6];

  scan1x[10] = scan1x[0] + 40;
  scan1y[10] = scan1y[0];
  scan1x[11] = scan1x[1] + 40;
  scan1y[11] = scan1y[1];
  scan1x[12] = scan1x[6] + 40;
  scan1y[12] = scan1y[6];

  TMarker *tm_scan1[13];
  TLatex texpoint;
  for ( int i = 0; i < 13; ++i )
    {
      tm_scan1[i] = new TMarker(scan1x[i],scan1y[i],kFullCircle);
      tm_scan1[i]->SetMarkerColor(kBlue);
      if ( i < 7 || i > 9 ) tm_scan1[i]->Draw();
      //if ( i > 6 ) cout << scan1x[i] << " " << scan1y[i] << endl;
      // --- coordinate change to motion table
      float Scan1x = 1076 - scan1x[i];
      float Scan1y = 252 - scan1y[i];
      if ( i == 2 || i == 3 ) texpoint.DrawLatex(scan1x[i]-40,scan1y[i]-10,Form("%d,%d",(int)Scan1x,(int)Scan1y));
      else if ( i < 2 || i == 6 ) texpoint.DrawLatex(scan1x[i],scan1y[i]+5,Form("%d,%d",(int)Scan1x,(int)Scan1y));
      else if ( i < 7 ) texpoint.DrawLatex(scan1x[i],scan1y[i]-10,Form("%d,%d",(int)Scan1x,(int)Scan1y));
      else if ( i > 9 ) texpoint.DrawLatex(scan1x[i],scan1y[i]-10,Form("%d,%d",(int)Scan1x,(int)Scan1y));
    }

  c1->Print("survey_diagram_Edward.png");

}
