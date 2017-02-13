void plot(){

  gStyle->SetTitleH(0.1);
  gStyle->SetTitleSize(0.05,"xy");
  gStyle->SetLabelSize(0.05,"xy");

  TTree *tree = new TTree("Tracking","Tracking");

  std::vector<std::string> file(5);

  file[0]="tracking5_firstns.log";
  file[1]="tracking5_first10ns.log";
  file[2]="tracking5_lastns.log";
  file[3]="tracking5_last10ns.log";
  file[4]="tracking5.log";

  // to draw the Bydt
  //    tree->ReadFile(Form("%s",file.at(4).c_str()),"t/D:x:y:z:ds:Bx:By:Bz:Bydt");
  //    tree->Draw("Bydt>>h(200)");
  //    return;

  TH2D *h1[5]; // x
  TH2D *h2[5]; // y
  TH2D *h3[5]; // z
  TH2D *b1[5]; // Bx
  TH2D *b2[5]; // By
  TH2D *b3[5]; // Bz

  for(int i=0;i<5;i++){

    tree->Clear();

    tree->ReadFile(Form("%s",file.at(i).c_str()),"t/D:x:y:z:ds:Bx:By:Bz:Bydt");

    TCanvas *c1 = new TCanvas("c1","c1",2000,1600);
    c1->Divide(2,3);

    c1->cd(1);
    c1->cd(1)->SetLogz();
    tree->Draw(Form("x:t>>h1_%d",i),"Entry$%10==0","l");
    h1[i] = (TH2D*)gPad->GetPrimitive(Form("h1_%d",i));
    h1[i]->GetXaxis()->SetTitle("t [ns]");
    h1[i]->GetYaxis()->SetTitle("x [mm]");

    c1->cd(3);
    c1->cd(3)->SetLogz();
    tree->Draw(Form("y:t>>h2_%d",i),"Entry$%10==0","l");
    h2[i] = (TH2D*)gPad->GetPrimitive(Form("h2_%d",i));
    h2[i]->GetXaxis()->SetTitle("t [ns]");
    h2[i]->GetYaxis()->SetTitle("y [mm]");

    c1->cd(5);
    c1->cd(5)->SetLogz();
    tree->Draw(Form("z:t>>h3_%d",i),"Entry$%10==0","l");
    h3[i] = (TH2D*)gPad->GetPrimitive(Form("h3_%d",i));
    h3[i]->GetXaxis()->SetTitle("t [ns]");
    h3[i]->GetYaxis()->SetTitle("z [mm]");

    c1->cd(2);
    c1->cd(2)->SetLogz();
    tree->Draw(Form("Bx:t>>b1_%d",i),"Entry$%10==0","l");
    b1[i] = (TH2D*)gPad->GetPrimitive(Form("b1_%d",i));
    b1[i]->GetXaxis()->SetTitle("t [ns]");
    b1[i]->GetYaxis()->SetTitle("B_{x} [T]");

    c1->cd(4);
    c1->cd(4)->SetLogz();
    tree->Draw(Form("By:t>>b2_%d",i),"Entry$%10==0","l");
    b2[i] = (TH2D*)gPad->GetPrimitive(Form("b2_%d",i));
    b2[i]->GetXaxis()->SetTitle("t [ns]");
    b2[i]->GetYaxis()->SetTitle("B_{y} [T]");

    c1->cd(6);
    c1->cd(6)->SetLogz();
    tree->Draw(Form("Bz:t>>b3_%d",i),"Entry$%10==0","l");
    b3[i]= (TH2D*)gPad->GetPrimitive(Form("b3_%d",i));
    b3[i]->GetXaxis()->SetTitle("t [ns]");
    b3[i]->GetYaxis()->SetTitle("B_{z} [T]");

    c1->Print(Form("%s.png",file.at(i).c_str()));
    c1->Delete();
  }

}
