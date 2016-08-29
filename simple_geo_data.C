void john_data();
void john_data(int);
void john_data_rrs();
void john_data_rrs(int);


void rotatereflectshift(float&, float&, float, float, float, float float);


void simple_geo_data()
{

  john_data();
  john_data_rrs();

}


void rotatereflectshift(float& x, float& y, float theta, float xoff, float yoff, float xscale, float yscale)
{
  float xprime = x*cos(theta) - y*sin(theta);
  float yprime = x*sin(theta) + y*cos(theta);
  x = xprime;
  y = -yprime;
  x -= xoff;
  y -= yoff;
  x /= xscale;
  y /= yscale;
}


void john_data_rrs()
{

  john_data_rrs(1);
  john_data_rrs(2);
  john_data_rrs(3);
  john_data_rrs(4);
  john_data_rrs(5);
  john_data_rrs(6);
  john_data_rrs(7);
  john_data_rrs(8);

}


void john_data_rrs(int whichtile)
{

  bool flag = false;

  if ( whichtile < 1 || whichtile > 8 )
    {
      cout << "Invalid tyle selection" << endl;
      return;
    }

  bool innertile = whichtile > 4;

  TCanvas *c1 = new TCanvas("c1","",1900,520);
  c1->Range(-5,-1,90,30);
  if ( innertile )
    {
      if ( c1 ) delete c1;
      c1 = new TCanvas("c1","",800,520);
      c1->Range(-5,-1,50,30);
    }

  TFile* file_led = TFile::Open("DataLED/20160113-1238_VMIN_SIPM1_meanHistSub.root");
  if ( innertile ) file_led = TFile::Open("DataLED/20160106-1320_VMIN_SIPM1_meanHistSub.root");
  TH2D* th2d_led = (TH2D*)file_led->Get("meanHistSub");
  th2d_led->Draw("col");
  if ( innertile )
    {
      th2d_led->GetYaxis()->SetLimits(0,140);
      th2d_led->GetXaxis()->SetLimits(0,240);
    }
  else
    {
      th2d_led->GetYaxis()->SetLimits(0,250);
      th2d_led->GetXaxis()->SetLimits(0,870);
    }
  th2d_led->GetYaxis()->SetTitle("Y position (mm)");
  th2d_led->GetXaxis()->SetTitle("X position (mm)");
  if ( !innertile ) th2d_led->GetYaxis()->SetTitleOffset(0.5);

  float xoff = 343;
  float yoff = -280; // minus because of reflection
  float xscale = 1.02;
  float yscale = 1.0;
  if ( innertile )
    {
      xoff = 345;
      yoff = -172;
      xscale = 1.05;
      yscale = 1.0;
    }

  cout << 1900/float(1300-350) << " " << 520/260.0 << endl;

  float xouterhcal_0 = 365;
  float xouterhcal_1 = 387;
  float xouterhcal_2 = 1236;
  //float xouterhcal_3 = 1219;
  float xouterhcal_3 = 1221;
  float xouterhcal_4 = 365;

  float youterhcal_0 = 0;
  //float youterhcal_1 = 241;
  float youterhcal_1 = 247;
  float youterhcal_2 = 171;
  float youterhcal_3 = 0;
  float youterhcal_4 = 0;

  float outerangle = atan2(xouterhcal_1-xouterhcal_0,youterhcal_1-youterhcal_0);
  cout << "outerangle is " << outerangle*180.0/3.14159 << endl;

  rotatereflectshift(xouterhcal_0,youterhcal_0,outerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xouterhcal_1,youterhcal_1,outerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xouterhcal_2,youterhcal_2,outerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xouterhcal_3,youterhcal_3,outerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xouterhcal_4,youterhcal_4,outerangle,xoff,yoff,xscale,yscale);

  float xouterhcal[5] = {xouterhcal_0,
                         xouterhcal_1,
                         xouterhcal_2,
                         xouterhcal_3,
                         xouterhcal_4};
  float youterhcal[5] = {youterhcal_0,
                         youterhcal_1,
                         youterhcal_2,
                         youterhcal_3,
                         youterhcal_4};

  cout << xouterhcal_0 << endl;
  cout << youterhcal_0 << endl;
  cout << xouterhcal_1 << endl;
  cout << youterhcal_1 << endl;



  float xinnerhcal_0 = 365;
  float xinnerhcal_1 = 376;
  float xinnerhcal_2 = 590;
  float xinnerhcal_3 = 580;
  float xinnerhcal_4 = 365;

  float yinnerhcal_0 = 0;
  //float yinnerhcal_1 = 127;
  float yinnerhcal_1 = 131;
  float yinnerhcal_2 = 114;
  float yinnerhcal_3 = 0;
  float yinnerhcal_4 = 0;

  float innerangle = atan2(xinnerhcal_1-xinnerhcal_0,yinnerhcal_1-yinnerhcal_0);
  cout << "innerangle is " << innerangle*180.0/3.14159 << endl;

  rotatereflectshift(xinnerhcal_0,yinnerhcal_0,innerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xinnerhcal_1,yinnerhcal_1,innerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xinnerhcal_2,yinnerhcal_2,innerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xinnerhcal_3,yinnerhcal_3,innerangle,xoff,yoff,xscale,yscale);
  rotatereflectshift(xinnerhcal_4,yinnerhcal_4,innerangle,xoff,yoff,xscale,yscale);

  float xinnerhcal[5] = {xinnerhcal_0,
                         xinnerhcal_1,
                         xinnerhcal_2,
                         xinnerhcal_3,
                         xinnerhcal_4};
  float yinnerhcal[5] = {yinnerhcal_0,
                         yinnerhcal_1,
                         yinnerhcal_2,
                         yinnerhcal_3,
                         yinnerhcal_4};

  if ( flag )
  {
  TPolyLine *tpl_outerhcal = new TPolyLine(5,xouterhcal,youterhcal,"F");
  tpl_outerhcal->SetLineColor(kBlack);
  if ( innertile ) tpl_outerhcal->SetLineColor(kGray);
  tpl_outerhcal->Draw("l");

  TPolyLine *tpl_innerhcal = new TPolyLine(5,xinnerhcal,yinnerhcal,"F");
  tpl_innerhcal->SetLineColor(kGray);
  if ( innertile ) tpl_innerhcal->SetLineColor(kBlack);
  tpl_innerhcal->Draw("l");
  if ( !innertile ) tpl_outerhcal->Draw("l");

  float outersipm_x = 368;
  float outersipm_y = 36;
  rotatereflectshift(outersipm_x,outersipm_y,outerangle,xoff,yoff,xscale,yscale);
  TMarker *tm_outersipm = new TMarker(outersipm_x,outersipm_y,kFullCircle);
  tm_outersipm->SetMarkerColor(kBlack);
  if ( innertile ) tm_outersipm->SetMarkerColor(kGray);
  tm_outersipm->Draw();
  float outersipm_x = 368;
  float outersipm_y = 31;
  rotatereflectshift(outersipm_x,outersipm_y,outerangle,xoff,yoff,xscale,yscale);
  TMarker *tm_innersipm = new TMarker(outersipm_x,outersipm_y,kFullCircle);
  tm_innersipm->SetMarkerColor(kGray);
  if ( innertile ) tm_innersipm->SetMarkerColor(kBlack);
  tm_innersipm->Draw();
  if ( !innertile ) tm_outersipm->Draw();
  }

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
      if ( innertile ) rotatereflectshift(scan1x,scan1y,innerangle,xoff,yoff,xscale,yscale);
      else rotatereflectshift(scan1x,scan1y,outerangle,xoff,yoff,xscale,yscale);
      tex.SetTextSize(0.06);
      float led_value = 0;
      int xbin = th2d_led->GetXaxis()->FindBin(scan1x);
      int ybin = th2d_led->GetXaxis()->FindBin(scan1y);
      led_value = th2d_led->GetBinContent(xbin,ybin);
      float showme = mpv_value/led_value/2.0;
      if ( innertile ) showme *= 2.0;
      if ( ( !innertile && i != 0 && i != 5 ) || ( innertile && i > 9 ) )
        {
          tm_scan1[i] = new TMarker(scan1x,scan1y,kFullCircle);
          tm_scan1[i]->SetMarkerColor(kBlack);
          tm_scan1[i]->Draw();
          tex.DrawLatex(scan1x,scan1y,Form("%.2f",showme));
        }
    }

  c1->Print(Form("figs/data_rrs_survey_tile%d.png",whichtile));
  c1->Print(Form("figs/data_rrs_survey_tile%d.pdf",whichtile));

  delete c1;

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

  float xouterhcal_0 = 365;
  float xouterhcal_1 = 387;
  float xouterhcal_2 = 1236;
  float xouterhcal_3 = 1219;
  float xouterhcal_4 = 365;

  float youterhcal_0 = 0;
  float youterhcal_1 = 241;
  float youterhcal_2 = 171;
  float youterhcal_3 = 0;
  float youterhcal_4 = 0;

  float xouterhcal[5] = {xouterhcal_0,
                         xouterhcal_1,
                         xouterhcal_2,
                         xouterhcal_3,
                         xouterhcal_4};
  float youterhcal[5] = {youterhcal_0,
                         youterhcal_1,
                         youterhcal_2,
                         youterhcal_3,
                         youterhcal_4};
  TPolyLine *tpl_outerhcal = new TPolyLine(5,xouterhcal,youterhcal,"F");
  tpl_outerhcal->SetLineColor(kBlack);
  if ( innertile ) tpl_outerhcal->SetLineColor(kGray);
  tpl_outerhcal->Draw("l");

  float outerangle = atan2(xouterhcal_1-xouterhcal_0,youterhcal_1-youterhcal_0);
  cout << "outerangle is " << outerangle*180.0/3.14159 << endl;

  float xinnerhcal_0 = 365;
  float xinnerhcal_1 = 376;
  float xinnerhcal_2 = 590;
  float xinnerhcal_3 = 580;
  float xinnerhcal_4 = 365;

  float yinnerhcal_0 = 0;
  float yinnerhcal_1 = 127;
  float yinnerhcal_2 = 114;
  float yinnerhcal_3 = 0;
  float yinnerhcal_4 = 0;

  float xinnerhcal[5] = {xinnerhcal_0,
                         xinnerhcal_1,
                         xinnerhcal_2,
                         xinnerhcal_3,
                         xinnerhcal_4};
  float yinnerhcal[5] = {yinnerhcal_0,
                         yinnerhcal_1,
                         yinnerhcal_2,
                         yinnerhcal_3,
                         yinnerhcal_4};
  TPolyLine *tpl_innerhcal = new TPolyLine(5,xinnerhcal,yinnerhcal,"F");
  tpl_innerhcal->SetLineColor(kGray);
  if ( innertile ) tpl_innerhcal->SetLineColor(kBlack);
  tpl_innerhcal->Draw("l");
  if ( !innertile ) tpl_outerhcal->Draw("l");

  float innerangle = atan2(xinnerhcal_1-xinnerhcal_0,yinnerhcal_1-yinnerhcal_0);
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


