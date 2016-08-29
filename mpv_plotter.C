void mpv_plotter()
{

  ifstream mpv;
  mpv.open("mpv.txt");

  int xbin[20];
  int ybin[20];
  float x[20];
  float y[20];
  float mpv1[20];
  float mpv2[20];
  float mpv3[20];
  float mpv4[20];
  float mpv5[20];
  float mpv6[20];
  float mpv7[20];
  float mpv8[20];
  float empv1[20];
  float empv2[20];
  float empv3[20];
  float empv4[20];
  float empv5[20];
  float empv6[20];
  float empv7[20];
  float empv8[20];
  float pos[20];

  TH2F *th2f_inner_mpv1 = new TH2F("th2f_inner_mpv1","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv2 = new TH2F("th2f_inner_mpv2","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv3 = new TH2F("th2f_inner_mpv3","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv4 = new TH2F("th2f_inner_mpv4","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv5 = new TH2F("th2f_inner_mpv5","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv6 = new TH2F("th2f_inner_mpv6","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv7 = new TH2F("th2f_inner_mpv7","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_inner_mpv8 = new TH2F("th2f_inner_mpv8","",5,-0.5,4.5,2,-0.5,1.5);

  TH2F *th2f_outer_mpv1 = new TH2F("th2f_outer_mpv1","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv2 = new TH2F("th2f_outer_mpv2","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv3 = new TH2F("th2f_outer_mpv3","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv4 = new TH2F("th2f_outer_mpv4","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv5 = new TH2F("th2f_outer_mpv5","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv6 = new TH2F("th2f_outer_mpv6","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv7 = new TH2F("th2f_outer_mpv7","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_outer_mpv8 = new TH2F("th2f_outer_mpv8","",5,-0.5,4.5,2,-0.5,1.5);

  for ( int i = 0; i < 20; ++i)
    {
      mpv >> xbin[i] >> ybin[i] >> x[i] >> y[i]
          >>  mpv1[i]
          >> empv1[i]
          >>  mpv2[i]
          >> empv2[i]
          >>  mpv3[i]
          >> empv3[i]
          >>  mpv4[i]
          >> empv4[i]
          >>  mpv5[i]
          >> empv5[i]
          >>  mpv6[i]
          >> empv6[i]
          >>  mpv7[i]
          >> empv7[i]
          >>  mpv8[i]
          >> empv8[i];

      pos[i]=i+1;

      if ( mpv1[i] < 0 ) mpv1[i] = 0; //Fit was failing and giving negative MPVs, so I just set to zero
      if ( mpv2[i] < 0 ) mpv2[i] = 0;
      if ( mpv3[i] < 0 ) mpv3[i] = 0;
      if ( mpv4[i] < 0 ) mpv4[i] = 0;
      if ( mpv5[i] < 0 ) mpv5[i] = 0;
      if ( mpv6[i] < 0 ) mpv6[i] = 0;
      if ( mpv7[i] < 0 ) mpv7[i] = 0;
      if ( mpv8[i] < 0 ) mpv8[i] = 0;

      if ( empv1[i] > 50 ) mpv1[i] = 0; //Fit was failing and giving negative MPVs, so I just set to zero
      if ( empv2[i] > 50 ) mpv2[i] = 0;
      if ( empv3[i] > 50 ) mpv3[i] = 0;
      if ( empv4[i] > 50 ) mpv4[i] = 0;
      if ( empv5[i] > 50 ) mpv5[i] = 0;
      if ( empv6[i] > 50 ) mpv6[i] = 0;
      if ( empv7[i] > 50 ) mpv7[i] = 0;
      if ( empv8[i] > 50 ) mpv8[i] = 0;

      if ( i < 10 )
        {
          th2f_outer_mpv1->SetBinContent(xbin[i]+1,ybin[i]+1,mpv1[i]);
          th2f_outer_mpv2->SetBinContent(xbin[i]+1,ybin[i]+1,mpv2[i]);
          th2f_outer_mpv3->SetBinContent(xbin[i]+1,ybin[i]+1,mpv3[i]);
          th2f_outer_mpv4->SetBinContent(xbin[i]+1,ybin[i]+1,mpv4[i]);
          th2f_outer_mpv5->SetBinContent(xbin[i]+1,ybin[i]+1,mpv5[i]);
          th2f_outer_mpv6->SetBinContent(xbin[i]+1,ybin[i]+1,mpv6[i]);
          th2f_outer_mpv7->SetBinContent(xbin[i]+1,ybin[i]+1,mpv7[i]);
          th2f_outer_mpv8->SetBinContent(xbin[i]+1,ybin[i]+1,mpv8[i]);
        }
      if ( i > 9 )
        {
          th2f_inner_mpv1->SetBinContent(xbin[i]+1,ybin[i]+1,mpv1[i]);
          th2f_inner_mpv2->SetBinContent(xbin[i]+1,ybin[i]+1,mpv2[i]);
          th2f_inner_mpv3->SetBinContent(xbin[i]+1,ybin[i]+1,mpv3[i]);
          th2f_inner_mpv4->SetBinContent(xbin[i]+1,ybin[i]+1,mpv4[i]);
          th2f_inner_mpv5->SetBinContent(xbin[i]+1,ybin[i]+1,mpv5[i]);
          th2f_inner_mpv6->SetBinContent(xbin[i]+1,ybin[i]+1,mpv6[i]);
          th2f_inner_mpv7->SetBinContent(xbin[i]+1,ybin[i]+1,mpv7[i]);
          th2f_inner_mpv8->SetBinContent(xbin[i]+1,ybin[i]+1,mpv8[i]);
        }



      cout << "xbin is " << xbin[i] << " and ybin is " << ybin[i] << " and mpv1 is " << mpv1[i] << endl;

    }

  mpv1[0] = 0;
  mpv2[0] = 0;
  mpv3[0] = 0;
  mpv4[0] = 0;
  mpv1[5] = 0;
  mpv2[5] = 0;
  mpv3[5] = 0;
  mpv4[5] = 0;

  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          cout << "for i = " << i << " and j = " << j
               << " the bin content is "
               << th2f_outer_mpv1->GetBinContent(i+1,j+1)
               << " the xbin is "
               << th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1)
               << " the ybin is "
               << th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1)
               << endl;
        }
    }

  const float outersipmx = 1073;
  const float outersipmy = 216;
  const float innersipmx = 1073;
  const float innersipmy = 221;

  float innerdistance[20];
  float outerdistance[20];

  for ( int i = 0; i < 20; ++i )
    {
      float outer_deltax = x[i] - outersipmx;
      float outer_deltay = y[i] - outersipmy;
      float inner_deltax = x[i] - innersipmx;
      float inner_deltay = y[i] - innersipmy;
      cout << i << " ";
      cout << x[i] << " ";
      cout << y[i] << " ";
      cout << outer_deltax << " ";
      cout << outer_deltay << " ";
      outerdistance[i] = sqrt ( outer_deltax * outer_deltax + outer_deltay * outer_deltay );
      innerdistance[i] = sqrt ( inner_deltax * inner_deltax + inner_deltay * inner_deltay );
      cout << outerdistance[i] << endl;
    }
  double MINIMUM = 1.0;
  double MAXIMUM = 260.0;


  TGraphErrors *TG1_outer = new TGraphErrors(20,outerdistance,mpv1,0,empv1);
  TGraphErrors *TG2_outer = new TGraphErrors(20,outerdistance,mpv2,0,empv2);
  TGraphErrors *TG3_outer = new TGraphErrors(20,outerdistance,mpv3,0,empv3);
  TGraphErrors *TG4_outer = new TGraphErrors(20,outerdistance,mpv4,0,empv4);
  TGraphErrors *TG5_outer = new TGraphErrors(20,outerdistance,mpv5,0,empv5);
  TGraphErrors *TG6_outer = new TGraphErrors(20,outerdistance,mpv6,0,empv6);
  TGraphErrors *TG7_outer = new TGraphErrors(20,outerdistance,mpv7,0,empv7);
  TGraphErrors *TG8_outer = new TGraphErrors(20,outerdistance,mpv8,0,empv8);

  TGraphErrors *TG1_inner = new TGraphErrors(20,innerdistance,mpv1,0,empv1);
  TGraphErrors *TG2_inner = new TGraphErrors(20,innerdistance,mpv2,0,empv2);
  TGraphErrors *TG3_inner = new TGraphErrors(20,innerdistance,mpv3,0,empv3);
  TGraphErrors *TG4_inner = new TGraphErrors(20,innerdistance,mpv4,0,empv4);
  TGraphErrors *TG5_inner = new TGraphErrors(20,innerdistance,mpv5,0,empv5);
  TGraphErrors *TG6_inner = new TGraphErrors(20,innerdistance,mpv6,0,empv6);
  TGraphErrors *TG7_inner = new TGraphErrors(20,innerdistance,mpv7,0,empv7);
  TGraphErrors *TG8_inner = new TGraphErrors(20,innerdistance,mpv8,0,empv8);




  // ---

  TCanvas *c1 = new TCanvas("c1","",1200,800);
  c1->Divide(2,2);

  TG1_outer->SetMarkerStyle(kFullCircle);
  TG1_outer->SetMarkerColor(kRed);
  TG2_outer->SetMarkerStyle(kFullCircle);
  TG2_outer->SetMarkerColor(kBlue);
  TG3_outer->SetMarkerStyle(kFullSquare);
  TG3_outer->SetMarkerColor(kRed);
  TG4_outer->SetMarkerStyle(kFullSquare);
  TG4_outer->SetMarkerColor(kBlue);

  TG1_outer->SetMinimum(MINIMUM);
  TG2_outer->SetMinimum(MINIMUM);
  TG3_outer->SetMinimum(MINIMUM);
  TG4_outer->SetMinimum(MINIMUM);
  TG1_outer->SetMaximum(MAXIMUM);
  TG2_outer->SetMaximum(MAXIMUM);
  TG3_outer->SetMaximum(MAXIMUM);
  TG4_outer->SetMaximum(MAXIMUM);

  TG1_outer->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG2_outer->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG3_outer->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG4_outer->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG1_outer->GetYaxis()->SetTitle("ADC");
  TG2_outer->GetYaxis()->SetTitle("ADC");
  TG3_outer->GetYaxis()->SetTitle("ADC");
  TG4_outer->GetYaxis()->SetTitle("ADC");

  TG1_outer->SetMarkerColor(kBlack);
  TG2_outer->SetMarkerColor(kBlack);
  TG3_outer->SetMarkerColor(kBlack);
  TG4_outer->SetMarkerColor(kBlack);
  TG1_outer->SetMarkerStyle(kOpenCircle);
  TG2_outer->SetMarkerStyle(kOpenSquare);
  TG3_outer->SetMarkerStyle(kOpenTriangleUp);
  TG4_outer->SetMarkerStyle(kOpenTriangleDown);

  c1->cd(1);
  TG1_outer->Draw("ap");
  c1->cd(2);
  TG2_outer->Draw("ap");
  c1->cd(3);
  TG3_outer->Draw("ap");
  c1->cd(4);
  TG4_outer->Draw("ap");

  c1->Print("figs/MPV_DistancePlots_1_4.png");
  c1->Print("figs/MPV_DistancePlots_1_4.pdf");


  TG5_inner->SetMinimum(MINIMUM);
  TG6_inner->SetMinimum(MINIMUM);
  TG7_inner->SetMinimum(MINIMUM);
  TG8_inner->SetMinimum(MINIMUM);
  TG5_inner->SetMaximum(MAXIMUM);
  TG6_inner->SetMaximum(MAXIMUM);
  TG7_inner->SetMaximum(MAXIMUM);
  TG8_inner->SetMaximum(MAXIMUM);

  TG5_inner->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG6_inner->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG7_inner->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG8_inner->GetXaxis()->SetTitle("Distance to SiPM (mm)");
  TG5_inner->GetYaxis()->SetTitle("ADC");
  TG6_inner->GetYaxis()->SetTitle("ADC");
  TG7_inner->GetYaxis()->SetTitle("ADC");
  TG8_inner->GetYaxis()->SetTitle("ADC");

  TG5_inner->SetMarkerStyle(kFullCircle);
  TG5_inner->SetMarkerColor(kRed);
  TG6_inner->SetMarkerStyle(kFullCircle);
  TG6_inner->SetMarkerColor(kBlue);
  TG7_inner->SetMarkerStyle(kFullSquare);
  TG7_inner->SetMarkerColor(kRed);
  TG8_inner->SetMarkerStyle(kFullSquare);
  TG8_inner->SetMarkerColor(kBlue);

  TG5_inner->GetXaxis()->SetLimits(0,220);
  TG6_inner->GetXaxis()->SetLimits(0,220);
  TG7_inner->GetXaxis()->SetLimits(0,220);
  TG8_inner->GetXaxis()->SetLimits(0,220);

  TG5_inner->SetMarkerColor(kBlack);
  TG6_inner->SetMarkerColor(kBlack);
  TG7_inner->SetMarkerColor(kBlack);
  TG8_inner->SetMarkerColor(kBlack);
  TG5_inner->SetMarkerStyle(kOpenCircle);
  TG6_inner->SetMarkerStyle(kOpenSquare);
  TG7_inner->SetMarkerStyle(kOpenTriangleUp);
  TG8_inner->SetMarkerStyle(kOpenTriangleDown);

  c1->cd(1);
  TG5_inner->Draw("ap");
  c1->cd(2);
  TG6_inner->Draw("ap");
  c1->cd(3);
  TG7_inner->Draw("ap");
  c1->cd(4);
  TG8_inner->Draw("ap");

  c1->Print("figs/MPV_DistancePlots_5_8.png");
  c1->Print("figs/MPV_DistancePlots_5_8.pdf");


  //return;  // just stop here for now to test the distance plots

  TCanvas* c2 = new TCanvas("c2","");
  c2->cd();
  TG5_inner->SetMarkerColor(kBlack);
  TG6_inner->SetMarkerColor(kBlack);
  TG7_inner->SetMarkerColor(kBlack);
  TG8_inner->SetMarkerColor(kBlack);
  TG5_inner->SetMarkerStyle(kOpenCircle);
  TG6_inner->SetMarkerStyle(kOpenSquare);
  TG7_inner->SetMarkerStyle(kOpenTriangleUp);
  TG8_inner->SetMarkerStyle(kOpenTriangleDown);
  TG5_inner->Draw("ap");
  TG6_inner->Draw("p");
  TG7_inner->Draw("p");
  TG8_inner->Draw("p");
  TLegend* leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->AddEntry(TG5_inner,"Tile 5","p");
  leg->AddEntry(TG6_inner,"Tile 6","p");
  leg->AddEntry(TG7_inner,"Tile 7","p");
  leg->AddEntry(TG8_inner,"Tile 8","p");
  leg->SetTextSize(0.045);
  leg->Draw();
  c2->Print("figs/MPV_DistancePlots_s58.png");
  c2->Print("figs/MPV_DistancePlots_s58.pdf");

  TG1_outer->SetMarkerColor(kBlack);
  TG2_outer->SetMarkerColor(kBlack);
  TG3_outer->SetMarkerColor(kBlack);
  TG4_outer->SetMarkerColor(kBlack);
  TG1_outer->SetMarkerStyle(kOpenCircle);
  TG2_outer->SetMarkerStyle(kOpenSquare);
  TG3_outer->SetMarkerStyle(kOpenTriangleUp);
  TG4_outer->SetMarkerStyle(kOpenTriangleDown);
  TG1_outer->Draw("ap");
  TG2_outer->Draw("p");
  TG3_outer->Draw("p");
  TG4_outer->Draw("p");
  delete leg;
  leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->AddEntry(TG1_outer,"Tile 1","p");
  leg->AddEntry(TG2_outer,"Tile 2","p");
  leg->AddEntry(TG3_outer,"Tile 3","p");
  leg->AddEntry(TG4_outer,"Tile 4","p");
  leg->SetTextSize(0.045);
  leg->Draw();
  c2->Print("figs/MPV_DistancePlots_s14.png");
  c2->Print("figs/MPV_DistancePlots_s14.pdf");

  c1->cd();

  return; // just stop here for now...

  TGraph *TG1 = new TGraph(20,pos,mpv1);
  TGraph *TG2 = new TGraph(20,pos,mpv2);
  TGraph *TG3 = new TGraph(20,pos,mpv3);
  TGraph *TG4 = new TGraph(20,pos,mpv4);
  TGraph *TG5 = new TGraph(20,pos,mpv5);
  TGraph *TG6 = new TGraph(20,pos,mpv6);
  TGraph *TG7 = new TGraph(20,pos,mpv7);
  TGraph *TG8 = new TGraph(20,pos,mpv8);

  TG1->SetMarkerStyle(kFullCircle);
  TG1->SetMarkerColor(kRed);
  TG2->SetMarkerStyle(kFullCircle);
  TG2->SetMarkerColor(kBlue);
  TG3->SetMarkerStyle(kFullSquare);
  TG3->SetMarkerColor(kRed);
  TG4->SetMarkerStyle(kFullSquare);
  TG4->SetMarkerColor(kBlue);

  TG1->GetXaxis()->SetLimits(-0.5,20.5);
  TG2->GetXaxis()->SetLimits(-0.5,20.5);
  TG3->GetXaxis()->SetLimits(-0.5,20.5);
  TG4->GetXaxis()->SetLimits(-0.5,20.5);

  TG1->SetMinimum(MINIMUM);
  TG2->SetMinimum(MINIMUM);
  TG3->SetMinimum(MINIMUM);
  TG4->SetMinimum(MINIMUM);
  TG1->SetMaximum(MAXIMUM);
  TG2->SetMaximum(MAXIMUM);
  TG3->SetMaximum(MAXIMUM);
  TG4->SetMaximum(MAXIMUM);

  TG1->GetXaxis()->SetTitle("Scan Number");
  TG2->GetXaxis()->SetTitle("Scan Number");
  TG3->GetXaxis()->SetTitle("Scan Number");
  TG4->GetXaxis()->SetTitle("Scan Number");
  TG1->GetYaxis()->SetTitle("ADC");
  TG2->GetYaxis()->SetTitle("ADC");
  TG3->GetYaxis()->SetTitle("ADC");
  TG4->GetYaxis()->SetTitle("ADC");

  c1->cd(1);
  TG1->Draw("ap");
  c1->cd(2);
  TG2->Draw("ap");
  c1->cd(3);
  TG3->Draw("ap");
  c1->cd(4);
  TG4->Draw("ap");

  c1->Print("figs/MPV_Plots_1_4.png");
  c1->Print("figs/MPV_Plots_1_4.pdf");

  TG5->GetXaxis()->SetLimits(-0.5,20.5);
  TG6->GetXaxis()->SetLimits(-0.5,20.5);
  TG7->GetXaxis()->SetLimits(-0.5,20.5);
  TG8->GetXaxis()->SetLimits(-0.5,20.5);

  TG5->SetMinimum(MINIMUM);
  TG6->SetMinimum(MINIMUM);
  TG7->SetMinimum(MINIMUM);
  TG8->SetMinimum(MINIMUM);

  TG5->SetMaximum(MAXIMUM);
  TG6->SetMaximum(MAXIMUM);
  TG7->SetMaximum(MAXIMUM);
  TG8->SetMaximum(MAXIMUM);

  TG5->GetXaxis()->SetTitle("Scan Number");
  TG6->GetXaxis()->SetTitle("Scan Number");
  TG7->GetXaxis()->SetTitle("Scan Number");
  TG8->GetXaxis()->SetTitle("Scan Number");
  TG5->GetYaxis()->SetTitle("ADC");
  TG6->GetYaxis()->SetTitle("ADC");
  TG7->GetYaxis()->SetTitle("ADC");
  TG8->GetYaxis()->SetTitle("ADC");

  TG5->SetMarkerStyle(kFullCircle);
  TG5->SetMarkerColor(kRed);
  TG6->SetMarkerStyle(kFullCircle);
  TG6->SetMarkerColor(kBlue);
  TG7->SetMarkerStyle(kFullSquare);
  TG7->SetMarkerColor(kRed);
  TG8->SetMarkerStyle(kFullSquare);
  TG8->SetMarkerColor(kBlue);

  c1->cd(1);
  TG5->Draw("ap");
  c1->cd(2);
  TG6->Draw("ap");
  c1->cd(3);
  TG7->Draw("ap");
  c1->cd(4);
  TG8->Draw("ap");

  c1->Print("figs/MPV_Plots_5_8.png");
  c1->Print("figs/MPV_Plots_5_8.pdf");

  // ---

  return;

  c1->Clear();
  delete c1;
  c1 = new TCanvas("c1","",1500,500);
  //c1->SetLogz();

  TLatex tex;
  TLatex texnote;
  th2f_outer_mpv1->Draw("colz");
  th2f_outer_mpv1->SetMinimum(MINIMUM);
  th2f_outer_mpv1->SetMaximum(MAXIMUM);
  th2f_outer_mpv1->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv1->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv1->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv1->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv1.png");
  c1->Print("figs/map_outer_2dbins_mpv1.pdf");

  th2f_outer_mpv2->Draw("colz");
  th2f_outer_mpv2->SetMinimum(MINIMUM);
  th2f_outer_mpv2->SetMaximum(MAXIMUM);
  th2f_outer_mpv2->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv2->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv2->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv2->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv2.png");
  c1->Print("figs/map_outer_2dbins_mpv2.pdf");

  th2f_outer_mpv3->Draw("colz");
  th2f_outer_mpv3->SetMinimum(MINIMUM);
  th2f_outer_mpv3->SetMaximum(MAXIMUM);
  th2f_outer_mpv3->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv3->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv3->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv3->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv3.png");
  c1->Print("figs/map_outer_2dbins_mpv3.pdf");

  th2f_outer_mpv4->Draw("colz");
  th2f_outer_mpv4->SetMinimum(MINIMUM);
  th2f_outer_mpv4->SetMaximum(MAXIMUM);
  th2f_outer_mpv4->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv4->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv4->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv4->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv4.png");
  c1->Print("figs/map_outer_2dbins_mpv4.pdf");

  th2f_outer_mpv5->Draw("colz");
  th2f_outer_mpv5->SetMinimum(MINIMUM);
  th2f_outer_mpv5->SetMaximum(MAXIMUM);
  th2f_outer_mpv5->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv5->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv5->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv5->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv5.png");
  c1->Print("figs/map_outer_2dbins_mpv5.pdf");

  th2f_outer_mpv6->Draw("colz");
  th2f_outer_mpv6->SetMinimum(MINIMUM);
  th2f_outer_mpv6->SetMaximum(MAXIMUM);
  th2f_outer_mpv6->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv6->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv6->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv6->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv6.png");
  c1->Print("figs/map_outer_2dbins_mpv6.pdf");

  th2f_outer_mpv7->Draw("colz");
  th2f_outer_mpv7->SetMinimum(MINIMUM);
  th2f_outer_mpv7->SetMaximum(MAXIMUM);
  th2f_outer_mpv7->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv7->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv7->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv7->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv7.png");
  c1->Print("figs/map_outer_2dbins_mpv7.pdf");

  th2f_outer_mpv8->Draw("colz");
  th2f_outer_mpv8->SetMinimum(MINIMUM);
  th2f_outer_mpv8->SetMaximum(MAXIMUM);
  th2f_outer_mpv8->GetXaxis()->SetNdivisions(5,true);
  th2f_outer_mpv8->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_outer_mpv8->GetBinContent(i+1,j+1);
          double econt = th2f_outer_mpv8->GetBinError(i+1,j+1);
          double x = th2f_outer_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_outer_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_outer_2dbins_mpv8.png");
  c1->Print("figs/map_outer_2dbins_mpv8.pdf");

  // ---

  th2f_inner_mpv1->Draw("colz");
  th2f_inner_mpv1->SetMinimum(MINIMUM);
  th2f_inner_mpv1->SetMaximum(MAXIMUM);
  th2f_inner_mpv1->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv1->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv1->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv1->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv1.png");
  c1->Print("figs/map_inner_2dbins_mpv1.pdf");

  th2f_inner_mpv2->Draw("colz");
  th2f_inner_mpv2->SetMinimum(MINIMUM);
  th2f_inner_mpv2->SetMaximum(MAXIMUM);
  th2f_inner_mpv2->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv2->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv2->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv2->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv2.png");
  c1->Print("figs/map_inner_2dbins_mpv2.pdf");

  th2f_inner_mpv3->Draw("colz");
  th2f_inner_mpv3->SetMinimum(MINIMUM);
  th2f_inner_mpv3->SetMaximum(MAXIMUM);
  th2f_inner_mpv3->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv3->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv3->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv3->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv3.png");
  c1->Print("figs/map_inner_2dbins_mpv3.pdf");

  th2f_inner_mpv4->Draw("colz");
  th2f_inner_mpv4->SetMinimum(MINIMUM);
  th2f_inner_mpv4->SetMaximum(MAXIMUM);
  th2f_inner_mpv4->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv4->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv4->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv4->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv4.png");
  c1->Print("figs/map_inner_2dbins_mpv4.pdf");

  th2f_inner_mpv5->Draw("colz");
  th2f_inner_mpv5->SetMinimum(MINIMUM);
  th2f_inner_mpv5->SetMaximum(MAXIMUM);
  th2f_inner_mpv5->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv5->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv5->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv5->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv5.png");
  c1->Print("figs/map_inner_2dbins_mpv5.pdf");

  th2f_inner_mpv6->Draw("colz");
  th2f_inner_mpv6->SetMinimum(MINIMUM);
  th2f_inner_mpv6->SetMaximum(MAXIMUM);
  th2f_inner_mpv6->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv6->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv6->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv6->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv6.png");
  c1->Print("figs/map_inner_2dbins_mpv6.pdf");

  th2f_inner_mpv7->Draw("colz");
  th2f_inner_mpv7->SetMinimum(MINIMUM);
  th2f_inner_mpv7->SetMaximum(MAXIMUM);
  th2f_inner_mpv7->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv7->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv7->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv7->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv7.png");
  c1->Print("figs/map_inner_2dbins_mpv7.pdf");

  th2f_inner_mpv8->Draw("colz");
  th2f_inner_mpv8->SetMinimum(MINIMUM);
  th2f_inner_mpv8->SetMaximum(MAXIMUM);
  th2f_inner_mpv8->GetXaxis()->SetNdivisions(5,true);
  th2f_inner_mpv8->GetYaxis()->SetNdivisions(2,true);
  texnote.DrawLatex(-1.0,-0.1,"SiPM");
  texnote.DrawLatex(-1.0,-0.2,"approx");
  texnote.DrawLatex(-1.0,-0.3,"location");
  for ( int i = 0; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          double cont = th2f_inner_mpv8->GetBinContent(i+1,j+1);
          double econt = th2f_inner_mpv8->GetBinError(i+1,j+1);
          double x = th2f_inner_mpv1->GetXaxis()->GetBinCenter(i+1);
          double y = th2f_inner_mpv1->GetXaxis()->GetBinCenter(j+1);
          tex.DrawLatex(x-0.25,y,Form("%f",cont));
          tex.DrawLatex(x-0.25,y-0.1,Form("#pm%f",econt));
        }
    }
  c1->Print("figs/map_inner_2dbins_mpv8.png");
  c1->Print("figs/map_inner_2dbins_mpv8.pdf");

}
