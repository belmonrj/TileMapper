void mpv_plotter()
{
  TCanvas *c1 = new TCanvas();
  ifstream mpv;
  mpv.open("mpv.txt");
  float mpv1[19];
  float mpv2[19];
  float mpv3[19];
  float mpv4[19];
  float mpv5[19];
  float mpv6[19];
  float mpv7[19];
  float mpv8[19];
  float pos[19];

  for (int i = 0;i<19;i++)
    {
      mpv>>mpv1[i]>>mpv2[i]>>mpv3[i]>>mpv4[i]>>mpv5[i]>>mpv6[i]>>mpv7[i]>>mpv8[i];
      pos[i]=i+1;
      if(mpv1[i]<0)mpv1[i]=0; //Fit was failing and giving negative MPVs, so I just set to zero
      if(mpv2[i]<0)mpv2[i]=0;
      if(mpv3[i]<0)mpv3[i]=0;
      if(mpv4[i]<0)mpv4[i]=0;
      if(mpv5[i]<0)mpv5[i]=0;
      if(mpv6[i]<0)mpv6[i]=0;
      if(mpv7[i]<0)mpv7[i]=0;
      if(mpv8[i]<0)mpv8[i]=0;
    }
  TGraph *TG1 = new TGraph(19,pos,mpv1);
  TGraph *TG2 = new TGraph(19,pos,mpv2);
  TGraph *TG3 = new TGraph(19,pos,mpv3);
  TGraph *TG4 = new TGraph(19,pos,mpv4);
  TGraph *TG5 = new TGraph(19,pos,mpv5);
  TGraph *TG6 = new TGraph(19,pos,mpv6);
  TGraph *TG7 = new TGraph(19,pos,mpv7);
  TGraph *TG8 = new TGraph(19,pos,mpv8);

  TG1->SetMarkerStyle(kFullCircle);
  TG1->SetMarkerColor(kRed);
  TG2->SetMarkerStyle(kFullCircle);
  TG2->SetMarkerColor(kBlue);
  TG3->SetMarkerStyle(kFullSquare);
  TG3->SetMarkerColor(kRed);
  TG4->SetMarkerStyle(kFullSquare);
  TG4->SetMarkerColor(kBlue);

  c1->Divide(2,2);
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

}
