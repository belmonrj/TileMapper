void mpv_plotter()
{

  ifstream mpv;
  mpv.open("mpv.txt");

  int xbin[20];
  int ybin[20];
  float mpv1[20];
  float mpv2[20];
  float mpv3[20];
  float mpv4[20];
  float mpv5[20];
  float mpv6[20];
  float mpv7[20];
  float mpv8[20];
  float pos[20];

  TH2F *th2f_mpv1 = new TH2F("th2f_mpv1","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv2 = new TH2F("th2f_mpv2","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv3 = new TH2F("th2f_mpv3","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv4 = new TH2F("th2f_mpv4","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv5 = new TH2F("th2f_mpv5","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv6 = new TH2F("th2f_mpv6","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv7 = new TH2F("th2f_mpv7","",5,-0.5,4.5,2,-0.5,1.5);
  TH2F *th2f_mpv8 = new TH2F("th2f_mpv8","",5,-0.5,4.5,2,-0.5,1.5);

  for ( int i = 0; i < 20; ++i)
    {
      //mpv >> mpv1[i] >> mpv2[i] >> mpv3[i] >> mpv4[i] >> mpv5[i] >> mpv6[i] >> mpv7[i] >> mpv8[i];
      mpv >> xbin[i] >> ybin[i] >> mpv1[i] >> mpv2[i] >> mpv3[i] >> mpv4[i] >> mpv5[i] >> mpv6[i] >> mpv7[i] >> mpv8[i];
      pos[i]=i+1;

      if ( mpv1[i] < 0 ) mpv1[i] = 0; //Fit was failing and giving negative MPVs, so I just set to zero
      if ( mpv2[i] < 0 ) mpv2[i] = 0;
      if ( mpv3[i] < 0 ) mpv3[i] = 0;
      if ( mpv4[i] < 0 ) mpv4[i] = 0;
      if ( mpv5[i] < 0 ) mpv5[i] = 0;
      if ( mpv6[i] < 0 ) mpv6[i] = 0;
      if ( mpv7[i] < 0 ) mpv7[i] = 0;
      if ( mpv8[i] < 0 ) mpv8[i] = 0;

      th2f_mpv1->SetBinContent(xbin[i],ybin[i],mpv1[i]);
      th2f_mpv2->SetBinContent(xbin[i],ybin[i],mpv2[i]);
      th2f_mpv3->SetBinContent(xbin[i],ybin[i],mpv3[i]);
      th2f_mpv4->SetBinContent(xbin[i],ybin[i],mpv4[i]);
      th2f_mpv5->SetBinContent(xbin[i],ybin[i],mpv5[i]);
      th2f_mpv6->SetBinContent(xbin[i],ybin[i],mpv6[i]);
      th2f_mpv7->SetBinContent(xbin[i],ybin[i],mpv7[i]);
      th2f_mpv8->SetBinContent(xbin[i],ybin[i],mpv8[i]);

    }

  TGraph *TG1 = new TGraph(20,pos,mpv1);
  TGraph *TG2 = new TGraph(20,pos,mpv2);
  TGraph *TG3 = new TGraph(20,pos,mpv3);
  TGraph *TG4 = new TGraph(20,pos,mpv4);
  TGraph *TG5 = new TGraph(20,pos,mpv5);
  TGraph *TG6 = new TGraph(20,pos,mpv6);
  TGraph *TG7 = new TGraph(20,pos,mpv7);
  TGraph *TG8 = new TGraph(20,pos,mpv8);

  // ---

  TCanvas *c1 = new TCanvas("c1","",1200,800);
  c1->Divide(2,2);

  TG1->SetMarkerStyle(kFullCircle);
  TG1->SetMarkerColor(kRed);
  TG2->SetMarkerStyle(kFullCircle);
  TG2->SetMarkerColor(kBlue);
  TG3->SetMarkerStyle(kFullSquare);
  TG3->SetMarkerColor(kRed);
  TG4->SetMarkerStyle(kFullSquare);
  TG4->SetMarkerColor(kBlue);

  c1->cd(1);
  TG1->Draw("ap");
  c1->cd(2);
  TG2->Draw("ap");
  c1->cd(3);
  TG3->Draw("ap");
  c1->cd(4);
  TG4->Draw("ap");

  c1->Print("MPV_Plots_1_4.png");

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

  c1->Print("MPV_Plots_5_8.png");

  // ---

  c1->Clear();
  delete c1;
  c1 = new TCanvas("c1","",800,600);

  th2f_mpv1->Draw("colz");
  c1->Print("map_2dbins_mpv1.png");

  th2f_mpv2->Draw("colz");
  c1->Print("map_2dbins_mpv2.png");

  th2f_mpv3->Draw("colz");
  c1->Print("map_2dbins_mpv3.png");

  th2f_mpv4->Draw("colz");
  c1->Print("map_2dbins_mpv4.png");

  th2f_mpv5->Draw("colz");
  c1->Print("map_2dbins_mpv5.png");

  th2f_mpv6->Draw("colz");
  c1->Print("map_2dbins_mpv6.png");

  th2f_mpv7->Draw("colz");
  c1->Print("map_2dbins_mpv7.png");

  th2f_mpv8->Draw("colz");
  c1->Print("map_2dbins_mpv8.png");

}
