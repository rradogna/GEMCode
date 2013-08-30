#include "TCanvas.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TBenchmark.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TF1.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TTree.h"
#include "TH1.h"
#include <TMath.h>

using namespace std;
/*void markers(int lineWidth=0)
{
   // Display the table of markers with their numbers.
   TMarker *marker = new TMarker();
   marker->SetMarkerSize(3);
   TText *text = new TText();
   text->SetTextFont(62);
   text->SetTextAlign(22);
   text->SetTextSize(0.1);
   char atext[] = "       ";
   Double_t x = 0;
   Double_t dx = 1/12.0;
   for (Int_t i=1;i<12;i++) {
      x += dx;
      sprintf(atext,"%d",i);
      marker->SetMarkerStyle(i+ 1000*lineWidth);
      marker->DrawMarker(x,.35);
      text->DrawText(x,.17,atext);
      sprintf(atext,"%d",i+19);
      marker->SetMarkerStyle(i+19 + 1000*lineWidth);
      marker->DrawMarker(x,.8);
      text->DrawText(x,.62,atext);
   }
   delete marker;
   delete text;

}*/
void Plot_GEM_MMT() {
  gROOT->ProcessLine(".L ./tdrstyle.C");
  setTDRStyle();
  Int_t r=1; 

TString lumist="4.9 fb^{-1}";
  TPaveText *ll = new TPaveText(0.15, 0.95, 0.95, 0.99, "NDC");
  ll->SetTextSize(0.03);
  ll->SetTextFont(42);
  ll->SetFillColor(0);
  ll->SetBorderSize(0);
  ll->SetMargin(0.01);
  ll->SetTextAlign(12); // align left
  TString text = "CMS Internal";
  ll->AddText(0.01,0.5,text);
  text = "Standard Model WH->#mu #mu #tau";
//  text = text + lumist;
  //  ll->SetTextAlign(32); // align right
  ll->AddText(0.65, 0.6, text);
//  TString text2 = "#sqrt{s} = 14 TeV";
//  ll->AddText(0.65,2,text2);
  ll->Draw("same");

   char  histoPtW[40], histoPtRecoW[40], histoEtaW[40], histoEtaRecoW[40], histo2DW[40], histo2DRecoW[40];
   char  histoPtT[40], histoPtRecoT[40], histoEtaT[40], histoEtaRecoT[40], histo2DT[40], histo2DRecoT[40];
   char  histoPtGlobalW[40], histoPtPFW[40],  histoPtISOW[40], histoEtaGlobalW[40], histoEtaPFW[40], histoEtaISOW[40];
   char  histoPtGlobalT[40], histoPtPFT[40],  histoPtISOT[40], histoEtaGlobalT[40], histoEtaPFT[40], histoEtaISOT[40];
// histo2DGlobal[40], histo2DPF[40], histoEtaISO[40], histo2DISO[40];
   char  histoISODBW[40], histoISODBT[40];
   char  histoPtW_1roi[40], histoPtT_1roi[40], histoPtW_2roi[40], histoPtT_2roi[40];
   char  histoPtW_1roi3p5[40], histoPtT_1roi3p5[40], histoPtW_2roi3p5[40], histoPtT_2roi3p5[40];
   char  histoPtRecoW_1roi[40], histoPtRecoT_1roi[40], histoPtRecoW_2roi[40], histoPtRecoT_2roi[40];
   char  histoPtPFW_1roi[40], histoPtPFT_1roi[40], histoPtPFW_2roi[40], histoPtPFT_2roi[40];
   char  histoPtGlobalW_1roi[40], histoPtGlobalT_1roi[40], histoPtGlobalW_2roi[40], histoPtGlobalT_2roi[40];
   char  histoPtISOW_1roi[40], histoPtISOT_1roi[40], histoPtISOW_2roi[40], histoPtISOT_2roi[40];

sprintf(histoPtW,"PtMuonW"); 
sprintf(histoPtRecoW,"PtMuonRecoW"); 
sprintf(histoPtGlobalW,"PtMuon_GlobalW"); 
sprintf(histoPtPFW,"PtMuon_PFW"); 
sprintf(histoPtISOW,"PtMuon_ISOW"); 
sprintf(histoEtaW,"AbsEtaMuonW"); 
sprintf(histoEtaRecoW,"AbsEtaMuonRecoW"); 
sprintf(histoEtaGlobalW,"AbsEtaMuon_GlobalW");
sprintf(histoEtaPFW,"AbsEtaMuon_PFW");
sprintf(histoEtaISOW,"AbsEtaMuon_ISOW");
sprintf(histo2DW,"MuonEta_vs_PtW");
sprintf(histo2DRecoW,"MuonRecoEta_vs_PtW");
//sprintf(histo2DGlobal,"MuonEta_vs_Pt_Global");
//sprintf(histo2DGlobal,"MuonPt_vs_IsoxPt");
//sprintf(histo2DPF,"MuonEta_vs_Pt_PF");
//sprintf(histo2DISO,"MuonEta_vs_Pt_ISO");

sprintf(histoPtT,"PtMuonT");
sprintf(histoPtRecoT,"PtMuonRecoT");
sprintf(histoPtGlobalT,"PtMuon_GlobalT");
sprintf(histoPtPFT,"PtMuon_PFT"); 
sprintf(histoPtISOT,"PtMuon_ISOT"); 
sprintf(histoEtaT,"AbsEtaMuonT");
sprintf(histoEtaRecoT,"AbsEtaMuonRecoT");
sprintf(histoEtaGlobalT,"AbsEtaMuon_GlobalT");
sprintf(histoEtaPFT,"AbsEtaMuon_PFT");
sprintf(histoEtaISOT,"AbsEtaMuon_ISOT");
sprintf(histo2DT,"MuonEta_vs_PtT");
sprintf(histo2DRecoT,"MuonRecoEta_vs_PtT");
//sprintf(histo2DGlobal,"MuonEta_vs_Pt_Global");
//sprintf(histo2DGlobal,"MuonPt_vs_IsoxPt");
//sprintf(histo2DPF,"MuonEta_vs_Pt_PF");
//sprintf(histo2DISO,"MuonEta_vs_Pt_ISO");


//sprintf(histoISO,"RelIso");
sprintf(histoISODBW,"RelIsoDBW");
sprintf(histoISODBT,"RelIsoDBT");

sprintf(histoPtW_1roi,"PtMuonW_1roi");
sprintf(histoPtT_1roi,"PtMuonT_1roi");
sprintf(histoPtW_2roi,"PtMuonW_2roi");
sprintf(histoPtT_2roi,"PtMuonT_2roi");
sprintf(histoPtW_1roi3p5,"PtMuonW_1roi3p5");
sprintf(histoPtT_1roi3p5,"PtMuonT_1roi3p5");
sprintf(histoPtW_2roi3p5,"PtMuonW_2roi3p5");
sprintf(histoPtT_2roi3p5,"PtMuonT_2roi3p5");

sprintf(histoPtRecoW_1roi,"PtMuonRecoW_1roi"); 
sprintf(histoPtRecoT_1roi,"PtMuonRecoT_1roi"); 
sprintf(histoPtRecoW_2roi,"PtMuonRecoW_2roi"); 
sprintf(histoPtRecoT_2roi,"PtMuonRecoT_2roi"); 
sprintf(histoPtGlobalW_1roi,"PtMuon_GlobalW_1roi");
sprintf(histoPtGlobalT_1roi,"PtMuon_GlobalT_1roi");
sprintf(histoPtGlobalW_2roi,"PtMuon_GlobalW_2roi");
sprintf(histoPtGlobalT_2roi,"PtMuon_GlobalT_2roi");
sprintf(histoPtPFW_1roi,"PtMuon_PFW_1roi");
sprintf(histoPtPFT_1roi,"PtMuon_PFT_1roi");
sprintf(histoPtPFW_2roi,"PtMuon_PFW_2roi");
sprintf(histoPtPFT_2roi,"PtMuon_PFT_2roi");

sprintf(histoPtISOW_1roi,"PtMuon_ISOW_1roi");
sprintf(histoPtISOT_1roi,"PtMuon_ISOT_1roi");
sprintf(histoPtISOW_2roi,"PtMuon_ISOW_2roi");
sprintf(histoPtISOT_2roi,"PtMuon_ISOT_2roi");

// gPad->SetLogy();
  
//// 8 TeV
  TFile *fWH125_8TeV = new TFile("./WH125/histo_file_WH1250_MMT.root");
  TH1F *WH125PtW_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtW);
  TH1F *WH125PtRecoW_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtRecoW);
  TH1F *WH125PtGlobalW_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtGlobalW);
  TH1F *WH125PtPFW_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtPFW);
  TH1F *WH125PtISOW_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtISOW);

  TH1F *WH125EtaW_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaW);
  TH1F *WH125EtaRecoW_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaRecoW);
  TH1F *WH125EtaGlobalW_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaGlobalW);
  TH1F *WH125EtaPFW_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaPFW);
  TH1F *WH125EtaISOW_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaISOW);
  
  TH2F *WH125EtaPt2DW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DW);
  TH2F *WH125EtaPt2DRecoW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DRecoW);
//  TH2F *WH125EtaPt2DGlobalW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DGlobalW);
//  TH2F *WH125EtaPt2DPFW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DPFW);
//  TH2F *WH125EtaPt2DISOW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DISOW);

//  TH1F *WH125ISO_8TeV = (TH1F*)fWH125_8TeV->Get(histoISO);
  TH1F *WH125ISODBW_8TeV = (TH1F*)fWH125_8TeV->Get(histoISODBW);

  TH1F *WH125PtT_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtT);
  TH1F *WH125PtRecoT_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtRecoT);
  TH1F *WH125PtGlobalT_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtGlobalT);
  TH1F *WH125PtPFT_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtPFT);
  TH1F *WH125PtISOT_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtISOT);

  TH1F *WH125EtaT_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaT);
  TH1F *WH125EtaRecoT_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaRecoT);
  TH1F *WH125EtaGlobalT_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaGlobalT);
  TH1F *WH125EtaPFT_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaPFT);
  TH1F *WH125EtaISOT_8TeV = (TH1F*)fWH125_8TeV->Get(histoEtaISOT);

  TH2F *WH125EtaPt2DT_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DT);
  TH2F *WH125EtaPt2DRecoT_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DRecoT);
//  TH2F *WH125EtaPt2DGlobalW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DGlobalW);
//  TH2F *WH125EtaPt2DPFW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DPFW);
//  TH2F *WH125EtaPt2DISOW_8TeV = (TH2F*)fWH125_8TeV->Get(histo2DISOW);

//  TH1F *WH125ISO_8TeV = (TH1F*)fWH125_8TeV->Get(histoISO);
//  TH1F *WH125ISODB_8TeV = (TH1F*)fWH125_8TeV->Get(histoISODB);
  TH1F *WH125ISODBT_8TeV = (TH1F*)fWH125_8TeV->Get(histoISODBT);

  TH1F *WH125PtW_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtW_1roi);
  TH1F *WH125PtT_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtT_1roi);
  TH1F *WH125PtW_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtW_2roi);
  TH1F *WH125PtT_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtT_2roi);
  TH1F *WH125PtW_1roi3p5_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtW_1roi3p5);
  TH1F *WH125PtT_1roi3p5_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtT_1roi3p5);
  TH1F *WH125PtW_2roi3p5_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtW_2roi3p5);
  TH1F *WH125PtT_2roi3p5_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtT_2roi3p5);

  TH1F *WH125PtRecoW_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtRecoW_1roi);
  TH1F *WH125PtRecoT_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtRecoT_1roi);
  TH1F *WH125PtRecoW_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtRecoW_2roi);
  TH1F *WH125PtRecoT_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtRecoT_2roi);
  TH1F *WH125PtGlobalW_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtGlobalW_1roi);
  TH1F *WH125PtGlobalT_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtGlobalT_1roi);
  TH1F *WH125PtGlobalW_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtGlobalW_2roi);
  TH1F *WH125PtGlobalT_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtGlobalT_2roi);
  TH1F *WH125PtPFW_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtPFW_1roi);
  TH1F *WH125PtPFT_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtPFT_1roi);
  TH1F *WH125PtPFW_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtPFW_2roi);
  TH1F *WH125PtPFT_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtPFT_2roi);

  TH1F *WH125PtISOW_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtISOW_1roi);
  TH1F *WH125PtISOT_1roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtISOT_1roi);
  TH1F *WH125PtISOW_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtISOW_2roi);
  TH1F *WH125PtISOT_2roi_8TeV = (TH1F*)fWH125_8TeV->Get(histoPtISOT_2roi);

///// PU50bx25
  TFile *fWH125_14TeV = new TFile("./WH125_14TeV_PU50bx25/histo_file_WH1250_MMT.root");
  TH1F *WH125PtW_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtW);
  TH1F *WH125PtRecoW_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtRecoW);
  TH1F *WH125PtGlobalW_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtGlobalW);
  TH1F *WH125PtPFW_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtPFW);
  TH1F *WH125PtISOW_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtISOW);

  TH1F *WH125EtaW_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaW);
  TH1F *WH125EtaRecoW_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaRecoW);
  TH1F *WH125EtaGlobalW_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaGlobalW);
  TH1F *WH125EtaPFW_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaPFW);
  TH1F *WH125EtaISOW_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaISOW);

  TH2F *WH125EtaPt2DW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DW);
  TH2F *WH125EtaPt2DRecoW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DRecoW);
//  TH2F *WH125EtaPt2DGlobalW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DGlobalW);
//  TH2F *WH125EtaPt2DPFW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DPFW);
//  TH2F *WH125EtaPt2DISOW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DISOW);

//  TH1F *WH125ISO_14TeV = (TH1F*)fWH125_14TeV->Get(histoISO);
  TH1F *WH125ISODBW_14TeV = (TH1F*)fWH125_14TeV->Get(histoISODBW);

  TH1F *WH125PtT_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtT);
  TH1F *WH125PtRecoT_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtRecoT);
  TH1F *WH125PtGlobalT_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtGlobalT);
  TH1F *WH125PtPFT_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtPFT);
  TH1F *WH125PtISOT_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtISOT);

  TH1F *WH125EtaT_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaT);
  TH1F *WH125EtaRecoT_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaRecoT);
  TH1F *WH125EtaGlobalT_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaGlobalT);
  TH1F *WH125EtaPFT_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaPFT);
  TH1F *WH125EtaISOT_14TeV = (TH1F*)fWH125_14TeV->Get(histoEtaISOT);

  TH2F *WH125EtaPt2DT_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DT);
  TH2F *WH125EtaPt2DRecoT_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DRecoT);
//  TH2F *WH125EtaPt2DGlobalW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DGlobalW);
//  TH2F *WH125EtaPt2DPFW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DPFW);
//  TH2F *WH125EtaPt2DISOW_14TeV = (TH2F*)fWH125_14TeV->Get(histo2DISOW);

//  TH1F *WH125ISO_14TeV = (TH1F*)fWH125_14TeV->Get(histoISO);
  TH1F *WH125ISODBT_14TeV = (TH1F*)fWH125_14TeV->Get(histoISODBT);

  TH1F *WH125PtW_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtW_1roi);
  TH1F *WH125PtT_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtT_1roi);
  TH1F *WH125PtW_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtW_2roi);
  TH1F *WH125PtT_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtT_2roi);
  TH1F *WH125PtW_1roi3p5_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtW_1roi3p5);
  TH1F *WH125PtT_1roi3p5_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtT_1roi3p5);
  TH1F *WH125PtW_2roi3p5_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtW_2roi3p5);
  TH1F *WH125PtT_2roi3p5_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtT_2roi3p5);

  TH1F *WH125PtRecoW_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtRecoW_1roi);
  TH1F *WH125PtRecoT_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtRecoT_1roi);
  TH1F *WH125PtRecoW_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtRecoW_2roi);
  TH1F *WH125PtRecoT_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtRecoT_2roi);
  TH1F *WH125PtGlobalW_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtGlobalW_1roi);
  TH1F *WH125PtGlobalT_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtGlobalT_1roi);
  TH1F *WH125PtGlobalW_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtGlobalW_2roi);
  TH1F *WH125PtGlobalT_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtGlobalT_2roi);
  TH1F *WH125PtPFW_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtPFW_1roi);
  TH1F *WH125PtPFT_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtPFT_1roi);
  TH1F *WH125PtPFW_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtPFW_2roi);
  TH1F *WH125PtPFT_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtPFT_2roi);

  TH1F *WH125PtISOW_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtISOW_1roi);
  TH1F *WH125PtISOT_1roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtISOT_1roi);
  TH1F *WH125PtISOW_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtISOW_2roi);
  TH1F *WH125PtISOT_2roi_14TeV = (TH1F*)fWH125_14TeV->Get(histoPtISOT_2roi);


  WH125PtW_8TeV->SetFillColor(4);
  WH125PtW_8TeV->SetFillStyle(3001);
  WH125PtRecoW_8TeV->SetFillColor(2);
  WH125PtRecoW_8TeV->SetFillStyle(3001);

  WH125PtT_8TeV->SetFillColor(4);
  WH125PtT_8TeV->SetFillStyle(3001);
  WH125PtRecoT_8TeV->SetFillColor(2);
  WH125PtRecoT_8TeV->SetFillStyle(3001);

  WH125PtGlobalW_8TeV->SetFillColor(1);
  WH125PtGlobalW_8TeV->SetFillStyle(3001);
  WH125PtPFW_8TeV->SetFillColor(3);
  WH125PtPFW_8TeV->SetFillStyle(3001);
  WH125PtISOW_8TeV->SetFillColor(5);
  WH125PtISOW_8TeV->SetFillStyle(3001);

  WH125PtGlobalT_8TeV->SetFillColor(1);
  WH125PtGlobalT_8TeV->SetFillStyle(3001);
  WH125PtPFT_8TeV->SetFillColor(3);
  WH125PtPFT_8TeV->SetFillStyle(3001);
  WH125PtISOT_8TeV->SetFillColor(5);
  WH125PtISOT_8TeV->SetFillStyle(3001);

  WH125PtW_1roi_8TeV->SetFillColor(4);
  WH125PtW_1roi_8TeV->SetFillStyle(3001);
  WH125PtT_1roi_8TeV->SetFillColor(4);
  WH125PtT_1roi_8TeV->SetFillStyle(3001);
  WH125PtW_2roi_8TeV->SetFillColor(4);
  WH125PtW_2roi_8TeV->SetFillStyle(3001);
  WH125PtT_2roi_8TeV->SetFillColor(4);
  WH125PtT_2roi_8TeV->SetFillStyle(3001);


  WH125PtRecoW_1roi_8TeV->SetFillColor(2);
  WH125PtRecoW_1roi_8TeV->SetFillStyle(3001);
  WH125PtRecoT_1roi_8TeV->SetFillColor(2);
  WH125PtRecoT_1roi_8TeV->SetFillStyle(3001);
  WH125PtRecoW_2roi_8TeV->SetFillColor(2);
  WH125PtRecoW_2roi_8TeV->SetFillStyle(3001);
  WH125PtRecoT_2roi_8TeV->SetFillColor(2);
  WH125PtRecoT_2roi_8TeV->SetFillStyle(3001);
  WH125PtGlobalW_1roi_8TeV->SetFillColor(1);
  WH125PtGlobalW_1roi_8TeV->SetFillStyle(3001);
  WH125PtGlobalT_1roi_8TeV->SetFillColor(1);
  WH125PtGlobalT_1roi_8TeV->SetFillStyle(3001);
  WH125PtGlobalW_2roi_8TeV->SetFillColor(1);
  WH125PtGlobalW_2roi_8TeV->SetFillStyle(3001);
  WH125PtGlobalT_2roi_8TeV->SetFillColor(1);
  WH125PtGlobalT_2roi_8TeV->SetFillStyle(3001);
  WH125PtPFW_1roi_8TeV->SetFillColor(3);
  WH125PtPFW_1roi_8TeV->SetFillStyle(3001);
  WH125PtPFT_1roi_8TeV->SetFillColor(3);
  WH125PtPFT_1roi_8TeV->SetFillStyle(3001);
  WH125PtPFW_2roi_8TeV->SetFillColor(3);
  WH125PtPFW_2roi_8TeV->SetFillStyle(3001);
  WH125PtPFT_2roi_8TeV->SetFillColor(3);
  WH125PtPFT_2roi_8TeV->SetFillStyle(3001);

  WH125PtISOW_1roi_8TeV->SetFillColor(5);
  WH125PtISOW_1roi_8TeV->SetFillStyle(3001);
  WH125PtISOT_1roi_8TeV->SetFillColor(5);
  WH125PtISOT_1roi_8TeV->SetFillStyle(3001);
  WH125PtISOW_2roi_8TeV->SetFillColor(5);
  WH125PtISOW_2roi_8TeV->SetFillStyle(3001);
  WH125PtISOT_2roi_8TeV->SetFillColor(5);
  WH125PtISOT_2roi_8TeV->SetFillStyle(3001);


WH125ISODBW_8TeV->SetFillColor(3);
WH125ISODBW_8TeV->SetFillStyle(3001);
WH125ISODBT_8TeV->SetFillColor(5);
WH125ISODBT_8TeV->SetFillStyle(3001);
WH125ISODBW_14TeV->SetFillColor(3);
WH125ISODBW_14TeV->SetFillStyle(3001);
WH125ISODBT_14TeV->SetFillColor(5);
WH125ISODBT_14TeV->SetFillStyle(3001);


  WH125EtaW_8TeV->SetFillColor(4);
  WH125EtaW_8TeV->SetFillStyle(3001);
  WH125EtaRecoW_8TeV->SetFillColor(2);
  WH125EtaRecoW_8TeV->SetFillStyle(3001);

  WH125EtaT_8TeV->SetFillColor(4);
  WH125EtaT_8TeV->SetFillStyle(3001);
  WH125EtaRecoT_8TeV->SetFillColor(2);
  WH125EtaRecoT_8TeV->SetFillStyle(3001);

  WH125EtaGlobalW_8TeV->SetFillColor(1);
  WH125EtaGlobalW_8TeV->SetFillStyle(3001);
  WH125EtaPFW_8TeV->SetFillColor(3);
  WH125EtaPFW_8TeV->SetFillStyle(3001);
  WH125EtaISOW_8TeV->SetFillColor(5);
  WH125EtaISOW_8TeV->SetFillStyle(3001);

  WH125EtaGlobalT_8TeV->SetFillColor(1);
  WH125EtaGlobalT_8TeV->SetFillStyle(3001);
  WH125EtaPFT_8TeV->SetFillColor(3);
  WH125EtaPFT_8TeV->SetFillStyle(3001);
  WH125EtaISOT_8TeV->SetFillColor(5);
  WH125EtaISOT_8TeV->SetFillStyle(3001);

  WH125PtW_14TeV->SetFillColor(4);
  WH125PtW_14TeV->SetFillStyle(3001);
  WH125PtRecoW_14TeV->SetFillColor(2);
  WH125PtRecoW_14TeV->SetFillStyle(3001);

  WH125PtT_14TeV->SetFillColor(4);
  WH125PtT_14TeV->SetFillStyle(3001);
  WH125PtRecoT_14TeV->SetFillColor(2);
  WH125PtRecoT_14TeV->SetFillStyle(3001);

  WH125PtGlobalW_14TeV->SetFillColor(1);
  WH125PtGlobalW_14TeV->SetFillStyle(3001);
  WH125PtPFW_14TeV->SetFillColor(3);
  WH125PtPFW_14TeV->SetFillStyle(3001);
  WH125PtISOW_14TeV->SetFillColor(5);
  WH125PtISOW_14TeV->SetFillStyle(3001);

  WH125PtGlobalT_14TeV->SetFillColor(1);
  WH125PtGlobalT_14TeV->SetFillStyle(3001);
  WH125PtPFT_14TeV->SetFillColor(3);
  WH125PtPFT_14TeV->SetFillStyle(3001);
  WH125PtISOT_14TeV->SetFillColor(5);
  WH125PtISOT_14TeV->SetFillStyle(3001);


  WH125EtaW_14TeV->SetFillColor(4);
  WH125EtaW_14TeV->SetFillStyle(3001);
  WH125EtaRecoW_14TeV->SetFillColor(2);
  WH125EtaRecoW_14TeV->SetFillStyle(3001);

  WH125EtaT_14TeV->SetFillColor(4);
  WH125EtaT_14TeV->SetFillStyle(3001);
  WH125EtaRecoT_14TeV->SetFillColor(2);
  WH125EtaRecoT_14TeV->SetFillStyle(3001);

  WH125EtaGlobalW_14TeV->SetFillColor(1);
  WH125EtaGlobalW_14TeV->SetFillStyle(3001);
  WH125EtaPFW_14TeV->SetFillColor(3);
  WH125EtaPFW_14TeV->SetFillStyle(3001);
  WH125EtaISOW_14TeV->SetFillColor(5);
  WH125EtaISOW_14TeV->SetFillStyle(3001);

  WH125EtaGlobalT_14TeV->SetFillColor(1);
  WH125EtaGlobalT_14TeV->SetFillStyle(3001);
  WH125EtaPFT_14TeV->SetFillColor(3);
  WH125EtaPFT_14TeV->SetFillStyle(3001);
  WH125EtaISOT_14TeV->SetFillColor(5);
  WH125EtaISOT_14TeV->SetFillStyle(3001);

  WH125PtW_1roi_14TeV->SetFillColor(4);
  WH125PtW_1roi_14TeV->SetFillStyle(3001);
  WH125PtT_1roi_14TeV->SetFillColor(4);
  WH125PtT_1roi_14TeV->SetFillStyle(3001);
  WH125PtW_2roi_14TeV->SetFillColor(4);
  WH125PtW_2roi_14TeV->SetFillStyle(3001);
  WH125PtT_2roi_14TeV->SetFillColor(4);
  WH125PtT_2roi_14TeV->SetFillStyle(3001);
  WH125PtRecoW_1roi_14TeV->SetFillColor(2);
  WH125PtRecoW_1roi_14TeV->SetFillStyle(3001);
  WH125PtRecoT_1roi_14TeV->SetFillColor(2);
  WH125PtRecoT_1roi_14TeV->SetFillStyle(3001);
  WH125PtRecoW_2roi_14TeV->SetFillColor(2);
  WH125PtRecoW_2roi_14TeV->SetFillStyle(3001);
  WH125PtRecoT_2roi_14TeV->SetFillColor(2);
  WH125PtRecoT_2roi_14TeV->SetFillStyle(3001);
  WH125PtGlobalW_1roi_14TeV->SetFillColor(1);
  WH125PtGlobalW_1roi_14TeV->SetFillStyle(3001);
  WH125PtGlobalT_1roi_14TeV->SetFillColor(1);
  WH125PtGlobalT_1roi_14TeV->SetFillStyle(3001);
  WH125PtGlobalW_2roi_14TeV->SetFillColor(1);
  WH125PtGlobalW_2roi_14TeV->SetFillStyle(3001);
  WH125PtGlobalT_2roi_14TeV->SetFillColor(1);
  WH125PtGlobalT_2roi_14TeV->SetFillStyle(3001);
  WH125PtPFW_1roi_14TeV->SetFillColor(3);
  WH125PtPFW_1roi_14TeV->SetFillStyle(3001);
  WH125PtPFT_1roi_14TeV->SetFillColor(3);
  WH125PtPFT_1roi_14TeV->SetFillStyle(3001);
  WH125PtPFW_2roi_14TeV->SetFillColor(3);
  WH125PtPFW_2roi_14TeV->SetFillStyle(3001);
  WH125PtPFT_2roi_14TeV->SetFillColor(3);
  WH125PtPFT_2roi_14TeV->SetFillStyle(3001);

  WH125PtISOW_1roi_14TeV->SetFillColor(5);
  WH125PtISOW_1roi_14TeV->SetFillStyle(3001);
  WH125PtISOT_1roi_14TeV->SetFillColor(5);
  WH125PtISOT_1roi_14TeV->SetFillStyle(3001);
  WH125PtISOW_2roi_14TeV->SetFillColor(5);
  WH125PtISOW_2roi_14TeV->SetFillStyle(3001);
  WH125PtISOT_2roi_14TeV->SetFillColor(5);
  WH125PtISOT_2roi_14TeV->SetFillStyle(3001);

//////Isolation
TCanvas *CanvISO_8 = new TCanvas("CanvISO_8"," ");
 CanvISO_8->Divide(2,1);
 CanvISO_8->cd(1);
 //WH125ISO_8TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)");
 WH125ISODBW_8TeV->Draw("HIST ");
// WH125ISO_8TeV->Draw("sameHIST ");
TLegend* legendISO_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendISO_8TeV->SetTextSize(0.025);
legendISO_8TeV->SetFillColor(0);
legendISO_8TeV->AddEntry(WH125ISODBW_8TeV, "Leading Muon RelIso_DB @8TeV","f");
//legendISO_8TeV->AddEntry(WH125ISO_8TeV, "Muon RelIso @8TeV","f");
legendISO_8TeV->Draw("same");
 CanvISO_8->cd(2);
 //WH125ISO_8TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)");
 WH125ISODBT_8TeV->Draw("HIST ");
// WH125ISO_8TeV->Draw("sameHIST ");
TLegend* legendISO_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendISO_8TeV->SetTextSize(0.025);
legendISO_8TeV->SetFillColor(0);
legendISO_8TeV->AddEntry(WH125ISODBT_8TeV, "SubLeading Muon RelIso_DB @8TeV","f");
//legendISO_8TeV->AddEntry(WH125ISO_8TeV, "Muon RelIso @8TeV","f");
legendISO_8TeV->Draw("same");


TCanvas *CanvISO_14 = new TCanvas("CanvISO_14"," ");
 CanvISO_14->Divide(2,1);
 CanvISO_14->cd(1);
 //WH125ISO_14TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)");
 WH125ISODBW_14TeV->Draw("HIST ");
// WH125ISO_14TeV->Draw("sameHIST ");
TLegend* legendISO_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendISO_14TeV->SetTextSize(0.025);
legendISO_14TeV->SetFillColor(0);
legendISO_14TeV->AddEntry(WH125ISODBW_14TeV, "Leading Muon RelIso_DB @PU50bx25","f");
//legendISO_14TeV->AddEntry(WH125ISO_14TeV, "Muon RelIso @PU50bx25","f");
legendISO_14TeV->Draw("same");
 CanvISO_14->cd(2);
 //WH125ISO_14TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)");
 WH125ISODBT_14TeV->Draw("HIST ");
// WH125ISO_14TeV->Draw("sameHIST ");
TLegend* legendISO_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendISO_14TeV->SetTextSize(0.025);
legendISO_14TeV->SetFillColor(0);
legendISO_14TeV->AddEntry(WH125ISODBT_14TeV, "SubLeading Muon RelIso_DB @PU50bx25","f");
//legendISO_14TeV->AddEntry(WH125ISO_14TeV, "Muon RelIso @PU50bx25","f");
legendISO_14TeV->Draw("same");

std::cout<<"Iso DB"<<std::endl;
Double_t iso=0, eff_iso=0;

for(Int_t i=0;i<67;i++){
eff_iso=WH125ISODBW_14TeV->Integral(0,i)/WH125PtRecoW_14TeV->Integral(0,300);
iso=0.05*i-0.3;
std::cout<<"eff iso W  ad "<<i<<" ovvero iso "<<iso<<" : "<< eff_iso<<std::endl;
}
for(Int_t i=0;i<67;i++){
eff_iso=WH125ISODBT_14TeV->Integral(0,i)/WH125PtRecoT_14TeV->Integral(0,300);
iso=0.05*i-0.3;
std::cout<<"eff iso T ad "<<i<<" ovvero iso "<<iso<<" : "<< eff_iso<<std::endl;
}


 TCanvas *Canv_8ptW = new TCanvas("Canv_8ptW"," ");
 Canv_8ptW->cd();
 WH125PtW_8TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)"); 
 WH125PtW_8TeV->Draw("HIST ");
 WH125PtRecoW_8TeV->Draw("sameHIST ");
 WH125PtPFW_8TeV->Draw("sameHIST ");
 WH125PtGlobalW_8TeV->Draw("sameHIST ");
 WH125PtISOW_8TeV->Draw("sameHIST ");

 TCanvas *Canv_8ptT = new TCanvas("Canv_8ptT"," ");
 Canv_8ptT->cd();
 WH125PtT_8TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)"); 
 WH125PtT_8TeV->Draw("HIST ");
 WH125PtRecoT_8TeV->Draw("sameHIST ");
 WH125PtPFT_8TeV->Draw("sameHIST ");
 WH125PtGlobalT_8TeV->Draw("sameHIST ");
 WH125PtISOT_8TeV->Draw("sameHIST ");

 
TCanvas *Canv_8etaW = new TCanvas("Canv_8etaW"," ");
Canv_8etaW->cd();
 WH125EtaW_8TeV->GetXaxis()->SetTitle("|#eta_{#mu}|"); 
 WH125EtaW_8TeV->Draw("HIST");
 WH125EtaRecoW_8TeV->Draw("sameHIST");
 WH125EtaPFW_8TeV->Draw("sameHIST");
 WH125EtaGlobalW_8TeV->Draw("sameHIST");
 WH125EtaISOW_8TeV->Draw("sameHIST");

TCanvas *Canv_8etaT = new TCanvas("Canv_8etaT"," ");
Canv_8etaT->cd();
 WH125EtaT_8TeV->GetXaxis()->SetTitle("|#eta_{#mu}|");
 WH125EtaT_8TeV->Draw("HIST");
 WH125EtaRecoT_8TeV->Draw("sameHIST");
 WH125EtaPFT_8TeV->Draw("sameHIST ");
 WH125EtaGlobalT_8TeV->Draw("sameHIST ");
 WH125EtaISOT_8TeV->Draw("sameHIST ");

 TCanvas *Canv_1roi_8ptW = new TCanvas("Canv_1roi_8ptW"," ");
 Canv_1roi_8ptW->cd();
 WH125PtW_1roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon");
 WH125PtW_1roi_8TeV->GetYaxis()->SetTitle("#Events 1Muon in eta r.o.i.");
 WH125PtW_1roi_8TeV->Draw("HIST ");
 WH125PtRecoW_1roi_8TeV->Draw("sameHIST ");
 WH125PtPFW_1roi_8TeV->Draw("sameHIST ");
 WH125PtGlobalW_1roi_8TeV->Draw("sameHIST ");
 WH125PtISOW_1roi_8TeV->Draw("sameHIST ");

 TCanvas *Canv_1roi_8ptT = new TCanvas("Canv_1roi_8ptT"," ");
 Canv_1roi_8ptT->cd();
 WH125PtT_1roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon");
 WH125PtT_1roi_8TeV->GetYaxis()->SetTitle("#Events 1Muon in eta r.o.i.");
 WH125PtT_1roi_8TeV->Draw("HIST ");
 WH125PtRecoT_1roi_8TeV->Draw("sameHIST ");
 WH125PtPFT_1roi_8TeV->Draw("sameHIST ");
 WH125PtGlobalT_1roi_8TeV->Draw("sameHIST ");
 WH125PtISOT_1roi_8TeV->Draw("sameHIST ");


 TCanvas *Canv_2roi_8ptW = new TCanvas("Canv_2roi_8ptW"," ");
 Canv_2roi_8ptW->cd();
 WH125PtW_2roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon");
 WH125PtW_2roi_8TeV->GetYaxis()->SetTitle("#Events 2Muons in eta r.o.i.");
 WH125PtW_2roi_8TeV->Draw("HIST ");
 WH125PtRecoW_2roi_8TeV->Draw("sameHIST ");
 WH125PtPFW_2roi_8TeV->Draw("sameHIST ");
 WH125PtGlobalW_2roi_8TeV->Draw("sameHIST ");
 WH125PtISOW_2roi_8TeV->Draw("sameHIST ");

 TCanvas *Canv_2roi_8ptT = new TCanvas("Canv_2roi_8ptT"," ");
 Canv_2roi_8ptT->cd();
 WH125PtT_2roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon");
 WH125PtT_2roi_8TeV->GetYaxis()->SetTitle("#Events 2Muons in eta r.o.i.");
 WH125PtT_2roi_8TeV->Draw("HIST ");
 WH125PtRecoT_2roi_8TeV->Draw("sameHIST ");
 WH125PtPFT_2roi_8TeV->Draw("sameHIST ");
 WH125PtGlobalT_2roi_8TeV->Draw("sameHIST ");
 WH125PtISOT_2roi_8TeV->Draw("sameHIST ");

TLegend* legendPtW_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtW_8TeV->SetTextSize(0.025);
legendPtW_8TeV->SetFillColor(0);
legendPtW_8TeV->AddEntry(WH125PtW_8TeV, "Muon from W Pt @8TeV (Gen)","f");
legendPtW_8TeV->AddEntry(WH125PtRecoW_8TeV, "Leading Muon Pt @8TeV (Reco)","f");
legendPtW_8TeV->AddEntry(WH125PtPFW_8TeV, "Leading Muon Pt @8TeV (PF_Muon)","f");
legendPtW_8TeV->AddEntry(WH125PtGlobalW_8TeV, "Leading Muon Pt @8TeV (Global_Muon) ","f");
legendPtW_8TeV->AddEntry(WH125PtISOW_8TeV, "Leading Muon Pt @8TeV (ISO_Muon)","f");
Canv_8ptW->cd();
legendPtW_8TeV->Draw("same");

TLegend* legendPtT_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtT_8TeV->SetTextSize(0.025);
legendPtT_8TeV->SetFillColor(0);
legendPtT_8TeV->AddEntry(WH125PtT_8TeV, "Muon from Tau Pt @8TeV (Gen)","f");
legendPtT_8TeV->AddEntry(WH125PtRecoT_8TeV, "SubLeading Muon Pt @8TeV (Reco)","f");
legendPtT_8TeV->AddEntry(WH125PtPFT_8TeV, "SubLeading Muon Pt @8TeV (PF_Muon)","f");
legendPtT_8TeV->AddEntry(WH125PtGlobalT_8TeV, "SubLeading Muon Pt @8TeV (Global_Muon) ","f");
legendPtT_8TeV->AddEntry(WH125PtISOT_8TeV, "SubLeading Muon Pt @8TeV (ISO_Muon)","f");
Canv_8ptT->cd();
legendPtT_8TeV->Draw("same");

TLegend* legendEtaW_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendEtaW_8TeV->SetTextSize(0.025);
legendEtaW_8TeV->SetFillColor(0);
legendEtaW_8TeV->AddEntry(WH125EtaW_8TeV, "Muon from W Eta @8TeV (Gen)","f");
legendEtaW_8TeV->AddEntry(WH125EtaRecoW_8TeV, "Leading Muon Eta @8TeV (Reco)","f");
legendEtaW_8TeV->AddEntry(WH125EtaPFW_8TeV, "Leading Muon Eta @8TeV (PF_Muon)","f");
legendEtaW_8TeV->AddEntry(WH125EtaGlobalW_8TeV, "Leading Muon Eta @8TeV (Global_Muon) ","f");
legendEtaW_8TeV->AddEntry(WH125EtaISOW_8TeV, "Leading Muon Eta @8TeV (ISO_Muon)","f");
Canv_8etaW->cd();
legendEtaW_8TeV->Draw("same");

TLegend* legendEtaT_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendEtaT_8TeV->SetTextSize(0.025);
legendEtaT_8TeV->SetFillColor(0);
legendEtaT_8TeV->AddEntry(WH125EtaT_8TeV, "Muon from Tau Eta @8TeV (Gen)","f");
legendEtaT_8TeV->AddEntry(WH125EtaRecoT_8TeV, "SubLeading Muon Eta @8TeV (Reco)","f");
legendEtaT_8TeV->AddEntry(WH125EtaPFT_8TeV, "SubLeading Muon Eta @8TeV (PF_Muon)","f");
legendEtaT_8TeV->AddEntry(WH125EtaGlobalT_8TeV, "SubLeading Muon Eta @8TeV (Global_Muon) ","f");
legendEtaT_8TeV->AddEntry(WH125EtaISOT_8TeV, "SubLeading Muon Eta @8TeV (ISO_Muon)","f");
Canv_8etaT->cd();
legendEtaT_8TeV->Draw("same");

TLegend* legendPtT_1roi_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtT_1roi_8TeV->SetTextSize(0.025);
legendPtT_1roi_8TeV->SetFillColor(0);
legendPtT_1roi_8TeV->AddEntry(WH125PtT_1roi_8TeV, "Muon from Tau Pt @8TeV (Gen)","f");
legendPtT_1roi_8TeV->AddEntry(WH125PtRecoT_1roi_8TeV, "SubLeading Muon Pt @8TeV (Reco)","f");
legendPtT_1roi_8TeV->AddEntry(WH125PtPFT_1roi_8TeV, "SubLeading Muon Pt @8TeV (PF_Muon)","f");
legendPtT_1roi_8TeV->AddEntry(WH125PtGlobalT_1roi_8TeV, "SubLeading Muon Pt @8TeV (Global_Muon) ","f");
legendPtT_1roi_8TeV->AddEntry(WH125PtISOT_1roi_8TeV, "SubLeading Muon Pt @8TeV (ISO_Muon)","f");
Canv_1roi_8ptT->cd();
legendPtT_1roi_8TeV->Draw("same");

TLegend* legendPtW_1roi_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtW_1roi_8TeV->SetTextSize(0.025);
legendPtW_1roi_8TeV->SetFillColor(0);
legendPtW_1roi_8TeV->AddEntry(WH125PtW_1roi_8TeV, "Muon from W Pt @8TeV (Gen)","f");
legendPtW_1roi_8TeV->AddEntry(WH125PtRecoW_1roi_8TeV, "Leading Muon Pt @8TeV (Reco)","f");
legendPtW_1roi_8TeV->AddEntry(WH125PtPFW_1roi_8TeV, "Leading Muon Pt @8TeV (PF_Muon)","f");
legendPtW_1roi_8TeV->AddEntry(WH125PtGlobalW_1roi_8TeV, "Leading Muon Pt @8TeV (Global_Muon) ","f");
legendPtW_1roi_8TeV->AddEntry(WH125PtISOW_1roi_8TeV, "Leading Muon Pt @8TeV (ISO_Muon)","f");
Canv_1roi_8ptW->cd();
legendPtW_1roi_8TeV->Draw("same");

TLegend* legendPtT_2roi_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtT_2roi_8TeV->SetTextSize(0.025);
legendPtT_2roi_8TeV->SetFillColor(0);
legendPtT_2roi_8TeV->AddEntry(WH125PtT_2roi_8TeV, "Muon from Tau Pt @8TeV (Gen)","f");
legendPtT_2roi_8TeV->AddEntry(WH125PtRecoT_2roi_8TeV, "SubLeading Muon Pt @8TeV (Reco)","f");
legendPtT_2roi_8TeV->AddEntry(WH125PtPFT_2roi_8TeV, "SubLeading Muon Pt @8TeV (PF_Muon)","f");
legendPtT_2roi_8TeV->AddEntry(WH125PtGlobalT_2roi_8TeV, "SubLeading Muon Pt @8TeV (Global_Muon) ","f");
legendPtT_2roi_8TeV->AddEntry(WH125PtISOT_2roi_8TeV, "SubLeading Muon Pt @8TeV (ISO_Muon)","f");
Canv_2roi_8ptT->cd();
legendPtT_2roi_8TeV->Draw("same");

TLegend* legendPtW_2roi_8TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtW_2roi_8TeV->SetTextSize(0.025);
legendPtW_2roi_8TeV->SetFillColor(0);
legendPtW_2roi_8TeV->AddEntry(WH125PtW_2roi_8TeV, "Muon from W Pt @8TeV (Gen)","f");
legendPtW_2roi_8TeV->AddEntry(WH125PtRecoW_2roi_8TeV, "Leading Muon Pt @8TeV (Reco)","f");
legendPtW_2roi_8TeV->AddEntry(WH125PtPFW_2roi_8TeV, "Leading Muon Pt @8TeV (PF_Muon)","f");
legendPtW_2roi_8TeV->AddEntry(WH125PtGlobalW_2roi_8TeV, "Leading Muon Pt @8TeV (Global_Muon) ","f");
legendPtW_2roi_8TeV->AddEntry(WH125PtISOW_2roi_8TeV, "Leading Muon Pt @8TeV (ISO_Muon)","f");
Canv_2roi_8ptW->cd();
legendPtW_2roi_8TeV->Draw("same");



////// Plot PU50bx25
 TCanvas *Canv_14ptW = new TCanvas("Canv_14ptW"," ");
 Canv_14ptW->cd();
 WH125PtW_14TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)");
 WH125PtW_14TeV->Draw("HIST ");
 WH125PtRecoW_14TeV->Draw("sameHIST ");
 WH125PtPFW_14TeV->Draw("sameHIST ");
 WH125PtGlobalW_14TeV->Draw("sameHIST ");
 WH125PtISOW_14TeV->Draw("sameHIST ");

 TCanvas *Canv_14ptT = new TCanvas("Canv_14ptT"," ");
 Canv_14ptT->cd();
 WH125PtT_14TeV->GetXaxis()->SetTitle("P_{T #mu} (GeV)");
 WH125PtT_14TeV->Draw("HIST ");
 WH125PtRecoT_14TeV->Draw("sameHIST ");
 WH125PtPFT_14TeV->Draw("sameHIST ");
 WH125PtGlobalT_14TeV->Draw("sameHIST ");
 WH125PtISOT_14TeV->Draw("sameHIST ");

TCanvas *Canv_14etaW = new TCanvas("Canv_14etaW"," ");
Canv_14etaW->cd();
 WH125EtaW_14TeV->GetXaxis()->SetTitle("|#eta_{#mu}|");
 WH125EtaW_14TeV->Draw("HIST");
 WH125EtaRecoW_14TeV->Draw("sameHIST");
 WH125EtaPFW_14TeV->Draw("sameHIST");
 WH125EtaGlobalW_14TeV->Draw("sameHIST");
 WH125EtaISOW_14TeV->Draw("sameHIST");

TCanvas *Canv_14etaT = new TCanvas("Canv_14etaT"," ");
Canv_14etaT->cd();
 WH125EtaT_14TeV->GetXaxis()->SetTitle("|#eta_{#mu}|");
 WH125EtaT_14TeV->Draw("HIST");
 WH125EtaRecoT_14TeV->Draw("sameHIST");
 WH125EtaPFT_14TeV->Draw("sameHIST");
 WH125EtaGlobalT_14TeV->Draw("sameHIST");
 WH125EtaISOT_14TeV->Draw("sameHIST");

 TCanvas *Canv_1roi_14ptW = new TCanvas("Canv_1roi_14ptW"," ");
 Canv_1roi_14ptW->cd();
 WH125PtW_1roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon");
 WH125PtW_1roi_14TeV->GetYaxis()->SetTitle("#Events 1Muon in eta r.o.i.");
 WH125PtW_1roi_14TeV->Draw("HIST ");
 WH125PtRecoW_1roi_14TeV->Draw("sameHIST ");
 WH125PtPFW_1roi_14TeV->Draw("sameHIST ");
 WH125PtGlobalW_1roi_14TeV->Draw("sameHIST ");
 WH125PtISOW_1roi_14TeV->Draw("sameHIST ");

 TCanvas *Canv_1roi_14ptT = new TCanvas("Canv_1roi_14ptT"," ");
 Canv_1roi_14ptT->cd();
 WH125PtT_1roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon");
 WH125PtT_1roi_14TeV->GetYaxis()->SetTitle("#Events 1Muon in eta r.o.i.");
 WH125PtT_1roi_14TeV->Draw("HIST ");
 WH125PtRecoT_1roi_14TeV->Draw("sameHIST ");
 WH125PtPFT_1roi_14TeV->Draw("sameHIST ");
 WH125PtGlobalT_1roi_14TeV->Draw("sameHIST ");
 WH125PtISOT_1roi_14TeV->Draw("sameHIST ");

 TCanvas *Canv_2roi_14ptW = new TCanvas("Canv_2roi_14ptW"," ");
 Canv_2roi_14ptW->cd();
 WH125PtW_2roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon");
 WH125PtW_2roi_14TeV->GetYaxis()->SetTitle("#Events 2Muons in eta r.o.i.");
 WH125PtW_2roi_14TeV->Draw("HIST ");
 WH125PtRecoW_2roi_14TeV->Draw("sameHIST ");
 WH125PtPFW_1roi_14TeV->Draw("sameHIST ");
 WH125PtGlobalW_1roi_14TeV->Draw("sameHIST ");
 WH125PtISOW_1roi_14TeV->Draw("sameHIST ");

 TCanvas *Canv_2roi_14ptT = new TCanvas("Canv_2roi_14ptT"," ");
 Canv_2roi_14ptT->cd();
 WH125PtT_2roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon");
 WH125PtT_2roi_14TeV->GetYaxis()->SetTitle("#Events 2Muons in eta r.o.i.");
 WH125PtT_2roi_14TeV->Draw("HIST ");
 WH125PtRecoT_2roi_14TeV->Draw("sameHIST ");
 WH125PtPFT_1roi_14TeV->Draw("sameHIST ");
 WH125PtGlobalT_1roi_14TeV->Draw("sameHIST ");
 WH125PtISOT_1roi_14TeV->Draw("sameHIST ");

TLegend* legendPtW_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtW_14TeV->SetTextSize(0.025);
legendPtW_14TeV->SetFillColor(0);
legendPtW_14TeV->AddEntry(WH125PtW_14TeV, "Muon from W Pt @PU50bx25 (Gen)","f");
legendPtW_14TeV->AddEntry(WH125PtRecoW_14TeV, "Leading Muon Pt @PU50bx25 (Reco)","f");
legendPtW_14TeV->AddEntry(WH125PtPFW_14TeV, "Leading Muon Pt @PU50bx25 (PF_Muon)","f");
legendPtW_14TeV->AddEntry(WH125PtGlobalW_14TeV, "Leading Muon Pt @PU50bx25 (Global_Muon) ","f");
legendPtW_14TeV->AddEntry(WH125PtISOW_14TeV, "Leading Muon Pt @PU50bx25 (ISO_Muon)","f");
Canv_14ptW->cd();
legendPtW_14TeV->Draw("same");

TLegend* legendPtT_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtT_14TeV->SetTextSize(0.025);
legendPtT_14TeV->SetFillColor(0);
legendPtT_14TeV->AddEntry(WH125PtT_14TeV, "Muon from Tau Pt @PU50bx25 (Gen)","f");
legendPtT_14TeV->AddEntry(WH125PtRecoT_14TeV, "SubLeading Muon Pt @PU50bx25 (Reco)","f");
legendPtT_14TeV->AddEntry(WH125PtPFT_14TeV, "SubLeading Muon Pt @PU50bx25 (PF_Muon)","f");
legendPtT_14TeV->AddEntry(WH125PtGlobalT_14TeV, "SubLeading Muon Pt @PU50bx25 (Global_Muon) ","f");
legendPtT_14TeV->AddEntry(WH125PtISOT_14TeV, "SubLeading Muon Pt @PU50bx25 (ISO_Muon)","f");
Canv_14ptT->cd();
legendPtT_14TeV->Draw("same");

TLegend* legendEtaW_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendEtaW_14TeV->SetTextSize(0.025);
legendEtaW_14TeV->SetFillColor(0);
legendEtaW_14TeV->AddEntry(WH125EtaW_14TeV, "Muon from W Eta @PU50bx25 (Gen)","f");
legendEtaW_14TeV->AddEntry(WH125EtaRecoW_14TeV, "Leading Muon Eta @PU50bx25 (Reco)","f");
legendEtaW_14TeV->AddEntry(WH125EtaPFW_14TeV, "Leading Muon Eta @PU50bx25 (PF_Muon)","f");
legendEtaW_14TeV->AddEntry(WH125EtaGlobalW_14TeV, "Leading Muon Eta @PU50bx25 (Global_Muon) ","f");
legendEtaW_14TeV->AddEntry(WH125EtaISOW_14TeV, "Leading Muon Eta @PU50bx25 (ISO_Muon)","f");
Canv_14etaW->cd();
legendEtaW_14TeV->Draw("same");

TLegend* legendEtaT_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendEtaT_14TeV->SetTextSize(0.025);
legendEtaT_14TeV->SetFillColor(0);
legendEtaT_14TeV->AddEntry(WH125EtaT_14TeV, "Muon from Tau Eta @PU50bx25 (Gen)","f");
legendEtaT_14TeV->AddEntry(WH125EtaRecoT_14TeV, "SubLeading Muon Eta @PU50bx25 (Reco)","f");
legendEtaT_14TeV->AddEntry(WH125EtaPFT_14TeV, "SubLeading Muon Eta @PU50bx25 (PF_Muon)","f");
legendEtaT_14TeV->AddEntry(WH125EtaGlobalT_14TeV, "SubLeading Muon Eta @PU50bx25 (Global_Muon) ","f");
legendEtaT_14TeV->AddEntry(WH125EtaISOT_14TeV, "SubLeading Muon Eta @PU50bx25 (ISO_Muon)","f");
Canv_14etaT->cd();
legendEtaT_14TeV->Draw("same");

TLegend* legendPtT_1roi_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtT_1roi_14TeV->SetTextSize(0.025);
legendPtT_1roi_14TeV->SetFillColor(0);
legendPtT_1roi_14TeV->AddEntry(WH125PtT_1roi_14TeV, "Muon from Tau Pt @PU50bx25 (Gen)","f");
legendPtT_1roi_14TeV->AddEntry(WH125PtRecoT_1roi_14TeV, "SubLeading Muon Pt @PU50bx25 (Reco)","f");
legendPtT_1roi_14TeV->AddEntry(WH125PtPFT_1roi_14TeV, "SubLeading Muon Pt @PU50bx25 (PF_Muon)","f");
legendPtT_1roi_14TeV->AddEntry(WH125PtGlobalT_1roi_14TeV, "SubLeading Muon Pt @PU50bx25 (Global_Muon) ","f");
legendPtT_1roi_14TeV->AddEntry(WH125PtISOT_1roi_14TeV, "SubLeading Muon Pt @PU50bx25 (ISO_Muon)","f");
Canv_1roi_14ptT->cd();
legendPtT_1roi_14TeV->Draw("same");

TLegend* legendPtW_1roi_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtW_1roi_14TeV->SetTextSize(0.025);
legendPtW_1roi_14TeV->SetFillColor(0);
legendPtW_1roi_14TeV->AddEntry(WH125PtW_1roi_14TeV, "Muon from W Pt @PU50bx25 (Gen)","f");
legendPtW_1roi_14TeV->AddEntry(WH125PtRecoW_1roi_14TeV, "Leading Muon Pt @PU50bx25 (Reco)","f");
legendPtW_1roi_14TeV->AddEntry(WH125PtPFW_1roi_14TeV, "Leading Muon Pt @PU50bx25 (PF_Muon)","f");
legendPtW_1roi_14TeV->AddEntry(WH125PtGlobalW_1roi_14TeV, "Leading Muon Pt @PU50bx25 (Global_Muon) ","f");
legendPtW_1roi_14TeV->AddEntry(WH125PtISOW_1roi_14TeV, "Leading Muon Pt @PU50bx25 (ISO_Muon)","f");
Canv_1roi_14ptW->cd();
legendPtW_1roi_14TeV->Draw("same");

TLegend* legendPtT_2roi_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtT_2roi_14TeV->SetTextSize(0.025);
legendPtT_2roi_14TeV->SetFillColor(0);
legendPtT_2roi_14TeV->AddEntry(WH125PtT_2roi_14TeV, "Muon from Tau Pt @PU50bx25 (Gen)","f");
legendPtT_2roi_14TeV->AddEntry(WH125PtRecoT_2roi_14TeV, "SubLeading Muon Pt @PU50bx25 (Reco)","f");
legendPtT_2roi_14TeV->AddEntry(WH125PtPFT_2roi_14TeV, "SubLeading Muon Pt @PU50bx25 (PF_Muon)","f");
legendPtT_2roi_14TeV->AddEntry(WH125PtGlobalT_2roi_14TeV, "SubLeading Muon Pt @PU50bx25 (Global_Muon) ","f");
legendPtT_2roi_14TeV->AddEntry(WH125PtISOT_2roi_14TeV, "SubLeading Muon Pt @PU50bx25 (ISO_Muon)","f");
Canv_2roi_14ptT->cd();
legendPtT_2roi_14TeV->Draw("same");

TLegend* legendPtW_2roi_14TeV = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendPtW_2roi_14TeV->SetTextSize(0.025);
legendPtW_2roi_14TeV->SetFillColor(0);
legendPtW_2roi_14TeV->AddEntry(WH125PtW_2roi_14TeV, "Muon from W Pt @PU50bx25 (Gen)","f");
legendPtW_2roi_14TeV->AddEntry(WH125PtRecoW_2roi_14TeV, "Leading Muon Pt @PU50bx25 (Reco)","f");
legendPtW_2roi_14TeV->AddEntry(WH125PtPFW_2roi_14TeV, "Leading Muon Pt @PU50bx25 (PF_Muon)","f");
legendPtW_2roi_14TeV->AddEntry(WH125PtGlobalW_2roi_14TeV, "Leading Muon Pt @PU50bx25 (Global_Muon) ","f");
legendPtW_2roi_14TeV->AddEntry(WH125PtISOW_2roi_14TeV, "Leading Muon Pt @PU50bx25 (ISO_Muon)","f");
Canv_2roi_14ptW->cd();
legendPtW_2roi_14TeV->Draw("same");


////// scatter

TCanvas *Canv2_8TeV = new TCanvas("Canv2_8TeV"," ");
Canv2_8TeV->Divide(2,1);
Canv2_8TeV->cd(1);
 WH125EtaPt2DW_8TeV->GetXaxis()->SetTitle("|#eta_{#mu}| Leading Muon @ 8TeV");
 WH125EtaPt2DW_8TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon @ 8TeV");
 gStyle->SetPalette(1);
WH125EtaPt2DW_8TeV->Draw("COLZ");
Canv2_8TeV->cd(2);
 WH125EtaPt2DT_8TeV->GetXaxis()->SetTitle("|#eta_{#mu}| SubLeading Muon @ 8TeV");
 WH125EtaPt2DT_8TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon @ 8TeV");
 gStyle->SetPalette(1);
WH125EtaPt2DT_8TeV->Draw("COLZ");

TCanvas *Canv2Reco_8TeV = new TCanvas("Canv2Reco_8TeV"," ");
Canv2Reco_8TeV->Divide(2,1);
Canv2Reco_8TeV->cd(1);
 WH125EtaPt2DRecoW_8TeV->GetXaxis()->SetTitle("|#eta_{#mu}| Leading Muon @ 8TeV");
 WH125EtaPt2DRecoW_8TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon @ 8TeV");
 gStyle->SetPalette(1);
WH125EtaPt2DRecoW_8TeV->SetMarkerColor(4);
WH125EtaPt2DRecoW_8TeV->SetMarkerStyle(20);
WH125EtaPt2DRecoW_8TeV->SetMarkerSize(0.5);
WH125EtaPt2DRecoW_8TeV->Draw("");
Canv2Reco_8TeV->cd(2);
 WH125EtaPt2DRecoT_8TeV->GetXaxis()->SetTitle("|#eta_{#mu}| SubLeading Muon @ 8TeV");
 WH125EtaPt2DRecoT_8TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon @ 8TeV");
 gStyle->SetPalette(1);
WH125EtaPt2DRecoT_8TeV->SetMarkerColor(4);
WH125EtaPt2DRecoT_8TeV->SetMarkerStyle(20);
WH125EtaPt2DRecoT_8TeV->SetMarkerSize(0.5);
WH125EtaPt2DRecoT_8TeV->Draw("");


TCanvas *Canv2_14TeV = new TCanvas("Canv2_14TeV"," ");
Canv2_14TeV->Divide(2,1);
Canv2_14TeV->cd(1);
 WH125EtaPt2DW_14TeV->GetXaxis()->SetTitle("|#eta_{#mu}| Leading Muon @ PU50bx25");
 WH125EtaPt2DW_14TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon @ PU50bx25");
 gStyle->SetPalette(1);
 WH125EtaPt2DW_14TeV->Draw("");
 Canv2_14TeV->cd(2);
 WH125EtaPt2DT_14TeV->GetXaxis()->SetTitle("|#eta_{#mu}| SubLeading Muon @ PU50bx25");
 WH125EtaPt2DT_14TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon @ PU50bx25");
 gStyle->SetPalette(1);
 WH125EtaPt2DT_14TeV->Draw("");

TCanvas *Canv2Reco_14TeV = new TCanvas("Canv2Reco_14TeV"," ");
Canv2Reco_14TeV->Divide(2,1);
Canv2Reco_14TeV->cd(1);
 WH125EtaPt2DRecoW_14TeV->GetXaxis()->SetTitle("|#eta_{#mu}| Leading Muon @ PU50bx25");
 WH125EtaPt2DRecoW_14TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] Leading Muon @ PU50bx25");
 gStyle->SetPalette(1);
WH125EtaPt2DRecoW_14TeV->SetMarkerColor(4);
WH125EtaPt2DRecoW_14TeV->SetMarkerStyle(20);
WH125EtaPt2DRecoW_14TeV->SetMarkerSize(0.5);
WH125EtaPt2DRecoW_14TeV->Draw("");
 //WH125EtaPt2DGlobal_14TeV->Draw("");
Canv2Reco_14TeV->cd(2);
 WH125EtaPt2DRecoT_14TeV->GetXaxis()->SetTitle("|#eta_{#mu}| SubLeading Muon @ PU50bx25");
 WH125EtaPt2DRecoT_14TeV->GetYaxis()->SetTitle("P_{T #mu} [GeV] SubLeading Muon @ PU50bx25");
 gStyle->SetPalette(1);
WH125EtaPt2DRecoT_14TeV->SetMarkerColor(4);
WH125EtaPt2DRecoT_14TeV->SetMarkerStyle(20);
WH125EtaPt2DRecoT_14TeV->SetMarkerSize(0.5);
WH125EtaPt2DRecoT_14TeV->Draw("");

/*std::cout<<" mu 1.6<|eta|<2.4: "<<WH125Eta->Integral(17,24)<<std::endl;
std::cout<<" mu 1.6<|eta|<2.4 nuovo integral : "<<WH125Eta1624->Integral()<<std::endl;
std::cout<<" mu 1.6<|eta|<2.4  entries: "<<WH125Eta1624->GetEntries()<<std::endl;
std::cout<<" mu 1.6<|eta|<2.4 da 2D : "<<WH125EtaPt2D->Integral(17,24,0,201)<<std::endl;

std::cout<<" mu tot integral: "<<WH125Eta->Integral(0,51)<<std::endl;
std::cout<<" mu tot entries: "<<WH125Eta->GetEntries()<<std::endl;
std::cout<<" mu tot da 2D : "<<WH125EtaPt2D->Integral(0,51,0,201)<<std::endl;
std::cout<<" mu tot da 2D : "<<WH125EtaPt2D->GetEntries()<<std::endl;

std::cout<<" frazione mu 1.6<|eta|<2.4/ mu totali before pt cut: "<<WH125Eta->Integral(17,24)/WH125Eta->Integral(0,51)<<std::endl;

std::cout<<" mu 1.6<|eta|<2.4 after pt > 24 da taglio in pt: "<<WH125EtaAfter->Integral(17,24)<<std::endl;
std::cout<<" mu 1.6<|eta|<2.4 after pt > 24 da taglio in eta: "<<WH125Pt1624->Integral(25,201)<<std::endl;
std::cout<<" mu 1.6<|eta|<2.4 da 2D pt> 24 : "<<WH125EtaPt2D->Integral(17,24,25,201)<<std::endl;
std::cout<<" mu tot after pt cut: "<<WH125EtaAfter->Integral()<<std::endl;
std::cout<<" mu tot after pt cut da pt plot: "<<WH125Pt->Integral(25,201)<<std::endl;
std::cout<<" mu tot da 2D pt> 24 : "<<WH125EtaPt2D->Integral(0,51,25,201)<<std::endl;
std::cout<<" frazione mu utili/ mu totali after pt > 24: "<<WH125EtaAfter->Integral(17,24)/WH125EtaAfter->Integral(0,51)<<std::endl;
std::cout<<" frazione mu utili/ mu totali after pt > 24: "<<WH125EtaPt2D->Integral(17,24,25,201)/WH125EtaPt2D->Integral(0,51,25,201)<<std::endl;
*/

/////// frazione muoni in 1.6 2.4

//static constant Int_t dim=200;
 Double_t xRecoW_1roi_8TeV[200], yRecoW_1roi_8TeV[200], exRecoW_1roi_8TeV[200], eyRecoW_1roi_8TeV[200];
 Double_t xRecoW_1roi_14TeV[200], yRecoW_1roi_14TeV[200], exRecoW_1roi_14TeV[200], eyRecoW_1roi_14TeV[200];
 Double_t xRecoT_1roi_8TeV[200], yRecoT_1roi_8TeV[200], exRecoT_1roi_8TeV[200], eyRecoT_1roi_8TeV[200];
 Double_t xRecoT_1roi_14TeV[200], yRecoT_1roi_14TeV[200], exRecoT_1roi_14TeV[200], eyRecoT_1roi_14TeV[200];
 Double_t xRecoW_2roi_8TeV[200], yRecoW_2roi_8TeV[200], exRecoW_2roi_8TeV[200], eyRecoW_2roi_8TeV[200];
 Double_t xRecoW_2roi_14TeV[200], yRecoW_2roi_14TeV[200], exRecoW_2roi_14TeV[200], eyRecoW_2roi_14TeV[200];
 Double_t xRecoT_2roi_8TeV[200], yRecoT_2roi_8TeV[200], exRecoT_2roi_8TeV[200], eyRecoT_2roi_8TeV[200];
 Double_t xRecoT_2roi_14TeV[200], yRecoT_2roi_14TeV[200], exRecoT_2roi_14TeV[200], eyRecoT_2roi_14TeV[200];

 Double_t xW_1roi_8TeV[200], yW_1roi_8TeV[200], exW_1roi_8TeV[200], eyW_1roi_8TeV[200];
 Double_t xW_1roi_14TeV[200], yW_1roi_14TeV[200], exW_1roi_14TeV[200], eyW_1roi_14TeV[200];
 Double_t xT_1roi_8TeV[200], yT_1roi_8TeV[200], exT_1roi_8TeV[200], eyT_1roi_8TeV[200];
 Double_t xT_1roi_14TeV[200], yT_1roi_14TeV[200], exT_1roi_14TeV[200], eyT_1roi_14TeV[200];
 Double_t xW_2roi_8TeV[200], yW_2roi_8TeV[200], exW_2roi_8TeV[200], eyW_2roi_8TeV[200];
 Double_t xW_2roi_14TeV[200], yW_2roi_14TeV[200], exW_2roi_14TeV[200], eyW_2roi_14TeV[200];
 Double_t xT_2roi_8TeV[200], yT_2roi_8TeV[200], exT_2roi_8TeV[200], eyT_2roi_8TeV[200];
 Double_t xT_2roi_14TeV[200], yT_2roi_14TeV[200], exT_2roi_14TeV[200], eyT_2roi_14TeV[200];

 Double_t xW_1roi3p5_8TeV[200], yW_1roi3p5_8TeV[200], exW_1roi3p5_8TeV[200], eyW_1roi3p5_8TeV[200];
 Double_t xW_1roi3p5_14TeV[200], yW_1roi3p5_14TeV[200], exW_1roi3p5_14TeV[200], eyW_1roi3p5_14TeV[200];
 Double_t xT_1roi3p5_8TeV[200], yT_1roi3p5_8TeV[200], exT_1roi3p5_8TeV[200], eyT_1roi3p5_8TeV[200];
 Double_t xT_1roi3p5_14TeV[200], yT_1roi3p5_14TeV[200], exT_1roi3p5_14TeV[200], eyT_1roi3p5_14TeV[200];
 Double_t xW_2roi3p5_8TeV[200], yW_2roi3p5_8TeV[200], exW_2roi3p5_8TeV[200], eyW_2roi3p5_8TeV[200];
 Double_t xW_2roi3p5_14TeV[200], yW_2roi3p5_14TeV[200], exW_2roi3p5_14TeV[200], eyW_2roi3p5_14TeV[200];
 Double_t xT_2roi3p5_8TeV[200], yT_2roi3p5_8TeV[200], exT_2roi3p5_8TeV[200], eyT_2roi3p5_8TeV[200];
 Double_t xT_2roi3p5_14TeV[200], yT_2roi3p5_14TeV[200], exT_2roi3p5_14TeV[200], eyT_2roi3p5_14TeV[200];

 Double_t xGlobalW_1roi_8TeV[200], yGlobalW_1roi_8TeV[200], exGlobalW_1roi_8TeV[200], eyGlobalW_1roi_8TeV[200];
 Double_t xGlobalW_1roi_14TeV[200], yGlobalW_1roi_14TeV[200], exGlobalW_1roi_14TeV[200], eyGlobalW_1roi_14TeV[200];
 Double_t xGlobalT_1roi_8TeV[200], yGlobalT_1roi_8TeV[200], exGlobalT_1roi_8TeV[200], eyGlobalT_1roi_8TeV[200];
 Double_t xGlobalT_1roi_14TeV[200], yGlobalT_1roi_14TeV[200], exGlobalT_1roi_14TeV[200], eyGlobalT_1roi_14TeV[200];
 Double_t xGlobalW_2roi_8TeV[200], yGlobalW_2roi_8TeV[200], exGlobalW_2roi_8TeV[200], eyGlobalW_2roi_8TeV[200];
 Double_t xGlobalW_2roi_14TeV[200], yGlobalW_2roi_14TeV[200], exGlobalW_2roi_14TeV[200], eyGlobalW_2roi_14TeV[200];
 Double_t xGlobalT_2roi_8TeV[200], yGlobalT_2roi_8TeV[200], exGlobalT_2roi_8TeV[200], eyGlobalT_2roi_8TeV[200];
 Double_t xGlobalT_2roi_14TeV[200], yGlobalT_2roi_14TeV[200], exGlobalT_2roi_14TeV[200], eyGlobalT_2roi_14TeV[200];

 Double_t xPFW_1roi_8TeV[200], yPFW_1roi_8TeV[200], exPFW_1roi_8TeV[200], eyPFW_1roi_8TeV[200];
 Double_t xPFW_1roi_14TeV[200], yPFW_1roi_14TeV[200], exPFW_1roi_14TeV[200], eyPFW_1roi_14TeV[200];
 Double_t xPFT_1roi_8TeV[200], yPFT_1roi_8TeV[200], exPFT_1roi_8TeV[200], eyPFT_1roi_8TeV[200];
 Double_t xPFT_1roi_14TeV[200], yPFT_1roi_14TeV[200], exPFT_1roi_14TeV[200], eyPFT_1roi_14TeV[200];
 Double_t xPFW_2roi_8TeV[200], yPFW_2roi_8TeV[200], exPFW_2roi_8TeV[200], eyPFW_2roi_8TeV[200];
 Double_t xPFW_2roi_14TeV[200], yPFW_2roi_14TeV[200], exPFW_2roi_14TeV[200], eyPFW_2roi_14TeV[200];
 Double_t xPFT_2roi_8TeV[200], yPFT_2roi_8TeV[200], exPFT_2roi_8TeV[200], eyPFT_2roi_8TeV[200];
 Double_t xPFT_2roi_14TeV[200], yPFT_2roi_14TeV[200], exPFT_2roi_14TeV[200], eyPFT_2roi_14TeV[200];

 Double_t xISOW_1roi_8TeV[200], yISOW_1roi_8TeV[200], exISOW_1roi_8TeV[200], eyISOW_1roi_8TeV[200];
 Double_t xISOW_1roi_14TeV[200], yISOW_1roi_14TeV[200], exISOW_1roi_14TeV[200], eyISOW_1roi_14TeV[200];
 Double_t xISOT_1roi_8TeV[200], yISOT_1roi_8TeV[200], exISOT_1roi_8TeV[200], eyISOT_1roi_8TeV[200];
 Double_t xISOT_1roi_14TeV[200], yISOT_1roi_14TeV[200], exISOT_1roi_14TeV[200], eyISOT_1roi_14TeV[200];
 Double_t xISOW_2roi_8TeV[200], yISOW_2roi_8TeV[200], exISOW_2roi_8TeV[200], eyISOW_2roi_8TeV[200];
 Double_t xISOW_2roi_14TeV[200], yISOW_2roi_14TeV[200], exISOW_2roi_14TeV[200], eyISOW_2roi_14TeV[200];
 Double_t xISOT_2roi_8TeV[200], yISOT_2roi_8TeV[200], exISOT_2roi_8TeV[200], eyISOT_2roi_8TeV[200];
 Double_t xISOT_2roi_14TeV[200], yISOT_2roi_14TeV[200], exISOT_2roi_14TeV[200], eyISOT_2roi_14TeV[200];

 Double_t y_ratio_3p52p4_1roiT[200], ey_ratio_3p52p4_1roiT[200];
 Double_t y_ratio_3p52p4_1roiW[200], ey_ratio_3p52p4_1roiW[200];
 Double_t y_ratio_3p52p4_2roiT[200], ey_ratio_3p52p4_2roiT[200];
 Double_t y_ratio_3p52p4_2roiW[200], ey_ratio_3p52p4_2roiW[200];


   Int_t n = 12;
   for (Int_t i=0;i<n;i++) {
     xRecoW_1roi_8TeV[i] = i*5;
     exRecoW_1roi_8TeV[i] = 0;
     yRecoW_1roi_8TeV[i] = WH125PtRecoW_1roi_8TeV->Integral(i*5,201)/WH125PtRecoW_8TeV->Integral(i*5,201);
     eyRecoW_1roi_8TeV[i] =TMath::Sqrt(yRecoW_1roi_8TeV[i]*(1-yRecoW_1roi_8TeV[i])/WH125PtRecoW_8TeV->Integral(i*5,201));
     xRecoT_1roi_8TeV[i] = i*5;
     exRecoT_1roi_8TeV[i] = 0;
     yRecoT_1roi_8TeV[i] = WH125PtRecoT_1roi_8TeV->Integral(i*5,201)/WH125PtRecoT_8TeV->Integral(i*5,201);
     eyRecoT_1roi_8TeV[i] =TMath::Sqrt(yRecoT_1roi_8TeV[i]*(1-yRecoT_1roi_8TeV[i])/WH125PtRecoT_8TeV->Integral(i*5,201));
     xRecoW_2roi_8TeV[i] = i*5;
     exRecoW_2roi_8TeV[i] = 0;
     yRecoW_2roi_8TeV[i] = WH125PtRecoW_2roi_8TeV->Integral(i*5,201)/WH125PtRecoW_8TeV->Integral(i*5,201);
     eyRecoW_2roi_8TeV[i] =TMath::Sqrt(yRecoW_2roi_8TeV[i]*(1-yRecoW_2roi_8TeV[i])/WH125PtRecoW_8TeV->Integral(i*5,201));
     xRecoT_2roi_8TeV[i] = i*5;
     exRecoT_2roi_8TeV[i] = 0;
     yRecoT_2roi_8TeV[i] = WH125PtRecoT_2roi_8TeV->Integral(i*5,201)/WH125PtRecoT_8TeV->Integral(i*5,201);
     eyRecoT_2roi_8TeV[i] =TMath::Sqrt(yRecoT_2roi_8TeV[i]*(1-yRecoT_2roi_8TeV[i])/WH125PtRecoT_8TeV->Integral(i*5,201));

     xGlobalW_1roi_8TeV[i] = i*5;
     exGlobalW_1roi_8TeV[i] = 0;
     yGlobalW_1roi_8TeV[i] = WH125PtGlobalW_1roi_8TeV->Integral(i*5,201)/WH125PtGlobalW_8TeV->Integral(i*5,201);
     eyGlobalW_1roi_8TeV[i] =TMath::Sqrt(yGlobalW_1roi_8TeV[i]*(1-yGlobalW_1roi_8TeV[i])/WH125PtGlobalW_8TeV->Integral(i*5,201));
     xGlobalT_1roi_8TeV[i] = i*5;
     exGlobalT_1roi_8TeV[i] = 0;
     yGlobalT_1roi_8TeV[i] = WH125PtGlobalT_1roi_8TeV->Integral(i*5,201)/WH125PtGlobalT_8TeV->Integral(i*5,201);
     eyGlobalT_1roi_8TeV[i] =TMath::Sqrt(yGlobalT_1roi_8TeV[i]*(1-yGlobalT_1roi_8TeV[i])/WH125PtGlobalT_8TeV->Integral(i*5,201));
     xGlobalW_2roi_8TeV[i] = i*5;
     exGlobalW_2roi_8TeV[i] = 0;
     yGlobalW_2roi_8TeV[i] = WH125PtGlobalW_2roi_8TeV->Integral(i*5,201)/WH125PtGlobalW_8TeV->Integral(i*5,201);
     eyGlobalW_2roi_8TeV[i] =TMath::Sqrt(yGlobalW_2roi_8TeV[i]*(1-yGlobalW_2roi_8TeV[i])/WH125PtGlobalW_8TeV->Integral(i*5,201));
     xGlobalT_2roi_8TeV[i] = i*5;
     exGlobalT_2roi_8TeV[i] = 0;
     yGlobalT_2roi_8TeV[i] = WH125PtGlobalT_2roi_8TeV->Integral(i*5,201)/WH125PtGlobalT_8TeV->Integral(i*5,201);
     eyGlobalT_2roi_8TeV[i] =TMath::Sqrt(yGlobalT_2roi_8TeV[i]*(1-yGlobalT_2roi_8TeV[i])/WH125PtGlobalT_8TeV->Integral(i*5,201));

     xPFW_1roi_8TeV[i] = i*5;
     exPFW_1roi_8TeV[i] = 0;
     yPFW_1roi_8TeV[i] = WH125PtPFW_1roi_8TeV->Integral(i*5,201)/WH125PtPFW_8TeV->Integral(i*5,201);
     eyPFW_1roi_8TeV[i] =TMath::Sqrt(yPFW_1roi_8TeV[i]*(1-yPFW_1roi_8TeV[i])/WH125PtPFW_8TeV->Integral(i*5,201));
     xPFT_1roi_8TeV[i] = i*5;
     exPFT_1roi_8TeV[i] = 0;
     yPFT_1roi_8TeV[i] = WH125PtPFT_1roi_8TeV->Integral(i*5,201)/WH125PtPFT_8TeV->Integral(i*5,201);
     eyPFT_1roi_8TeV[i] =TMath::Sqrt(yPFT_1roi_8TeV[i]*(1-yPFT_1roi_8TeV[i])/WH125PtPFT_8TeV->Integral(i*5,201));
     xPFW_2roi_8TeV[i] = i*5;
     exPFW_2roi_8TeV[i] = 0;
     yPFW_2roi_8TeV[i] = WH125PtPFW_2roi_8TeV->Integral(i*5,201)/WH125PtPFW_8TeV->Integral(i*5,201);
     eyPFW_2roi_8TeV[i] =TMath::Sqrt(yPFW_2roi_8TeV[i]*(1-yPFW_2roi_8TeV[i])/WH125PtPFW_8TeV->Integral(i*5,201));
     xPFT_2roi_8TeV[i] = i*5;
     exPFT_2roi_8TeV[i] = 0;
     yPFT_2roi_8TeV[i] = WH125PtPFT_2roi_8TeV->Integral(i*5,201)/WH125PtPFT_8TeV->Integral(i*5,201);
     eyPFT_2roi_8TeV[i] =TMath::Sqrt(yPFT_2roi_8TeV[i]*(1-yPFT_2roi_8TeV[i])/WH125PtPFT_8TeV->Integral(i*5,201));

     xISOW_1roi_8TeV[i] = i*5;
     exISOW_1roi_8TeV[i] = 0;
     yISOW_1roi_8TeV[i] = WH125PtISOW_1roi_8TeV->Integral(i*5,201)/WH125PtISOW_8TeV->Integral(i*5,201);
     eyISOW_1roi_8TeV[i] =TMath::Sqrt(yISOW_1roi_8TeV[i]*(1-yISOW_1roi_8TeV[i])/WH125PtISOW_8TeV->Integral(i*5,201));
     xISOT_1roi_8TeV[i] = i*5;
     exISOT_1roi_8TeV[i] = 0;
     yISOT_1roi_8TeV[i] = WH125PtISOT_1roi_8TeV->Integral(i*5,201)/WH125PtISOT_8TeV->Integral(i*5,201);
     eyISOT_1roi_8TeV[i] =TMath::Sqrt(yISOT_1roi_8TeV[i]*(1-yISOT_1roi_8TeV[i])/WH125PtISOT_8TeV->Integral(i*5,201));
     xISOW_2roi_8TeV[i] = i*5;
     exISOW_2roi_8TeV[i] = 0;
     yISOW_2roi_8TeV[i] = WH125PtISOW_2roi_8TeV->Integral(i*5,201)/WH125PtISOW_8TeV->Integral(i*5,201);
     eyISOW_2roi_8TeV[i] =TMath::Sqrt(yISOW_2roi_8TeV[i]*(1-yISOW_2roi_8TeV[i])/WH125PtISOW_8TeV->Integral(i*5,201));
     xISOT_2roi_8TeV[i] = i*5;
     exISOT_2roi_8TeV[i] = 0;
     yISOT_2roi_8TeV[i] = WH125PtISOT_2roi_8TeV->Integral(i*5,201)/WH125PtISOT_8TeV->Integral(i*5,201);
     eyISOT_2roi_8TeV[i] =TMath::Sqrt(yISOT_2roi_8TeV[i]*(1-yISOT_2roi_8TeV[i])/WH125PtISOT_8TeV->Integral(i*5,201));

     xW_1roi_8TeV[i] = i*5;
     exW_1roi_8TeV[i] = 0;
     yW_1roi_8TeV[i] = WH125PtW_1roi_8TeV->Integral(i*5,201)/WH125PtW_8TeV->Integral(i*5,201);
     eyW_1roi_8TeV[i] =TMath::Sqrt(yW_1roi_8TeV[i]*(1-yW_1roi_8TeV[i])/WH125PtW_8TeV->Integral(i*5,201));
     xT_1roi_8TeV[i] = i*5;
     exT_1roi_8TeV[i] = 0;
     yT_1roi_8TeV[i] = WH125PtT_1roi_8TeV->Integral(i*5,201)/WH125PtT_8TeV->Integral(i*5,201);
     eyT_1roi_8TeV[i] =TMath::Sqrt(yT_1roi_8TeV[i]*(1-yT_1roi_8TeV[i])/WH125PtT_8TeV->Integral(i*5,201));
     xW_2roi_8TeV[i] = i*5;
     exW_2roi_8TeV[i] = 0;
     yW_2roi_8TeV[i] = WH125PtW_2roi_8TeV->Integral(i*5,201)/WH125PtW_8TeV->Integral(i*5,201);
     eyW_2roi_8TeV[i] =TMath::Sqrt(yW_2roi_8TeV[i]*(1-yW_2roi_8TeV[i])/WH125PtW_8TeV->Integral(i*5,201));
     xT_2roi_8TeV[i] = i*5;
     exT_2roi_8TeV[i] = 0;
     yT_2roi_8TeV[i] = WH125PtT_2roi_8TeV->Integral(i*5,201)/WH125PtT_8TeV->Integral(i*5,201);
     eyT_2roi_8TeV[i] =TMath::Sqrt(yT_2roi_8TeV[i]*(1-yT_2roi_8TeV[i])/WH125PtT_8TeV->Integral(i*5,201));

     xW_1roi3p5_8TeV[i] = i*5;
     exW_1roi3p5_8TeV[i] = 0;
     yW_1roi3p5_8TeV[i] = WH125PtW_1roi3p5_8TeV->Integral(i*5,201)/WH125PtW_8TeV->Integral(i*5,201);
     eyW_1roi3p5_8TeV[i] =TMath::Sqrt(yW_1roi3p5_8TeV[i]*(1-yW_1roi3p5_8TeV[i])/WH125PtW_8TeV->Integral(i*5,201));
     xT_1roi3p5_8TeV[i] = i*5;
     exT_1roi3p5_8TeV[i] = 0;
     yT_1roi3p5_8TeV[i] = WH125PtT_1roi3p5_8TeV->Integral(i*5,201)/WH125PtT_8TeV->Integral(i*5,201);
     eyT_1roi3p5_8TeV[i] =TMath::Sqrt(yT_1roi3p5_8TeV[i]*(1-yT_1roi3p5_8TeV[i])/WH125PtT_8TeV->Integral(i*5,201));
     xW_2roi3p5_8TeV[i] = i*5;
     exW_2roi3p5_8TeV[i] = 0;
     yW_2roi3p5_8TeV[i] = WH125PtW_2roi3p5_8TeV->Integral(i*5,201)/WH125PtW_8TeV->Integral(i*5,201);
     eyW_2roi3p5_8TeV[i] =TMath::Sqrt(yW_2roi3p5_8TeV[i]*(1-yW_2roi3p5_8TeV[i])/WH125PtW_8TeV->Integral(i*5,201));
     xT_2roi3p5_8TeV[i] = i*5;
     exT_2roi3p5_8TeV[i] = 0;
     yT_2roi3p5_8TeV[i] = WH125PtT_2roi3p5_8TeV->Integral(i*5,201)/WH125PtT_8TeV->Integral(i*5,201);
     eyT_2roi3p5_8TeV[i] =TMath::Sqrt(yT_2roi3p5_8TeV[i]*(1-yT_2roi3p5_8TeV[i])/WH125PtT_8TeV->Integral(i*5,201));

     xRecoW_1roi_14TeV[i] = i*5;
     exRecoW_1roi_14TeV[i] = 0;
     yRecoW_1roi_14TeV[i] = WH125PtRecoW_1roi_14TeV->Integral(i*5,201)/WH125PtRecoW_14TeV->Integral(i*5,201);
     eyRecoW_1roi_14TeV[i] =TMath::Sqrt(yRecoW_1roi_14TeV[i]*(1-yRecoW_1roi_14TeV[i])/WH125PtRecoW_14TeV->Integral(i*5,201));
     xRecoT_1roi_14TeV[i] = i*5;
     exRecoT_1roi_14TeV[i] = 0;
     yRecoT_1roi_14TeV[i] = WH125PtRecoT_1roi_14TeV->Integral(i*5,201)/WH125PtRecoT_14TeV->Integral(i*5,201);
     eyRecoT_1roi_14TeV[i] =TMath::Sqrt(yRecoT_1roi_14TeV[i]*(1-yRecoT_1roi_14TeV[i])/WH125PtRecoT_14TeV->Integral(i*5,201));
     xRecoW_2roi_14TeV[i] = i*5;
     exRecoW_2roi_14TeV[i] = 0;
     yRecoW_2roi_14TeV[i] = WH125PtRecoW_2roi_14TeV->Integral(i*5,201)/WH125PtRecoW_14TeV->Integral(i*5,201);
     eyRecoW_2roi_14TeV[i] =TMath::Sqrt(yRecoW_2roi_14TeV[i]*(1-yRecoW_2roi_14TeV[i])/WH125PtRecoW_14TeV->Integral(i*5,201));
     xRecoT_2roi_14TeV[i] = i*5;
     exRecoT_2roi_14TeV[i] = 0;
     yRecoT_2roi_14TeV[i] = WH125PtRecoT_2roi_14TeV->Integral(i*5,201)/WH125PtRecoT_14TeV->Integral(i*5,201);
     eyRecoT_2roi_14TeV[i] =TMath::Sqrt(yRecoT_2roi_14TeV[i]*(1-yRecoT_2roi_14TeV[i])/WH125PtRecoT_14TeV->Integral(i*5,201));

     xGlobalW_1roi_14TeV[i] = i*5;
     exGlobalW_1roi_14TeV[i] = 0;
     yGlobalW_1roi_14TeV[i] = WH125PtGlobalW_1roi_14TeV->Integral(i*5,201)/WH125PtGlobalW_14TeV->Integral(i*5,201);
     eyGlobalW_1roi_14TeV[i] =TMath::Sqrt(yGlobalW_1roi_14TeV[i]*(1-yGlobalW_1roi_14TeV[i])/WH125PtGlobalW_14TeV->Integral(i*5,201));
     xGlobalT_1roi_14TeV[i] = i*5;
     exGlobalT_1roi_14TeV[i] = 0;
     yGlobalT_1roi_14TeV[i] = WH125PtGlobalT_1roi_14TeV->Integral(i*5,201)/WH125PtGlobalT_14TeV->Integral(i*5,201);
     eyGlobalT_1roi_14TeV[i] =TMath::Sqrt(yGlobalT_1roi_14TeV[i]*(1-yGlobalT_1roi_14TeV[i])/WH125PtGlobalT_14TeV->Integral(i*5,201));
     xGlobalW_2roi_14TeV[i] = i*5;
     exGlobalW_2roi_14TeV[i] = 0;
     yGlobalW_2roi_14TeV[i] = WH125PtGlobalW_2roi_14TeV->Integral(i*5,201)/WH125PtGlobalW_14TeV->Integral(i*5,201);
     eyGlobalW_2roi_14TeV[i] =TMath::Sqrt(yGlobalW_2roi_14TeV[i]*(1-yGlobalW_2roi_14TeV[i])/WH125PtGlobalW_14TeV->Integral(i*5,201));
     xGlobalT_2roi_14TeV[i] = i*5;
     exGlobalT_2roi_14TeV[i] = 0;
     yGlobalT_2roi_14TeV[i] = WH125PtGlobalT_2roi_14TeV->Integral(i*5,201)/WH125PtGlobalT_14TeV->Integral(i*5,201);
     eyGlobalT_2roi_14TeV[i] =TMath::Sqrt(yGlobalT_2roi_14TeV[i]*(1-yGlobalT_2roi_14TeV[i])/WH125PtGlobalT_14TeV->Integral(i*5,201));

     xPFW_1roi_14TeV[i] = i*5;
     exPFW_1roi_14TeV[i] = 0;
     yPFW_1roi_14TeV[i] = WH125PtPFW_1roi_14TeV->Integral(i*5,201)/WH125PtPFW_14TeV->Integral(i*5,201);
     eyPFW_1roi_14TeV[i] =TMath::Sqrt(yPFW_1roi_14TeV[i]*(1-yPFW_1roi_14TeV[i])/WH125PtPFW_14TeV->Integral(i*5,201));
     xPFT_1roi_14TeV[i] = i*5;
     exPFT_1roi_14TeV[i] = 0;
     yPFT_1roi_14TeV[i] = WH125PtPFT_1roi_14TeV->Integral(i*5,201)/WH125PtPFT_14TeV->Integral(i*5,201);
     eyPFT_1roi_14TeV[i] =TMath::Sqrt(yPFT_1roi_14TeV[i]*(1-yPFT_1roi_14TeV[i])/WH125PtPFT_14TeV->Integral(i*5,201));
     xPFW_2roi_14TeV[i] = i*5;
     exPFW_2roi_14TeV[i] = 0;
     yPFW_2roi_14TeV[i] = WH125PtPFW_2roi_14TeV->Integral(i*5,201)/WH125PtPFW_14TeV->Integral(i*5,201);
     eyPFW_2roi_14TeV[i] =TMath::Sqrt(yPFW_2roi_14TeV[i]*(1-yPFW_2roi_14TeV[i])/WH125PtPFW_14TeV->Integral(i*5,201));
     xPFT_2roi_14TeV[i] = i*5;
     exPFT_2roi_14TeV[i] = 0;
     yPFT_2roi_14TeV[i] = WH125PtPFT_2roi_14TeV->Integral(i*5,201)/WH125PtPFT_14TeV->Integral(i*5,201);
     eyPFT_2roi_14TeV[i] =TMath::Sqrt(yPFT_2roi_14TeV[i]*(1-yPFT_2roi_14TeV[i])/WH125PtPFT_14TeV->Integral(i*5,201));

     xISOW_1roi_14TeV[i] = i*5;
     exISOW_1roi_14TeV[i] = 0;
     yISOW_1roi_14TeV[i] = WH125PtISOW_1roi_14TeV->Integral(i*5,201)/WH125PtISOW_14TeV->Integral(i*5,201);
     eyISOW_1roi_14TeV[i] =TMath::Sqrt(yISOW_1roi_14TeV[i]*(1-yISOW_1roi_14TeV[i])/WH125PtISOW_14TeV->Integral(i*5,201));
     xISOT_1roi_14TeV[i] = i*5;
     exISOT_1roi_14TeV[i] = 0;
     yISOT_1roi_14TeV[i] = WH125PtISOT_1roi_14TeV->Integral(i*5,201)/WH125PtISOT_14TeV->Integral(i*5,201);
     eyISOT_1roi_14TeV[i] =TMath::Sqrt(yISOT_1roi_14TeV[i]*(1-yISOT_1roi_14TeV[i])/WH125PtISOT_14TeV->Integral(i*5,201));
     xISOW_2roi_14TeV[i] = i*5;
     exISOW_2roi_14TeV[i] = 0;
     yISOW_2roi_14TeV[i] = WH125PtISOW_2roi_14TeV->Integral(i*5,201)/WH125PtISOW_14TeV->Integral(i*5,201);
     eyISOW_2roi_14TeV[i] =TMath::Sqrt(yISOW_2roi_14TeV[i]*(1-yISOW_2roi_14TeV[i])/WH125PtISOW_14TeV->Integral(i*5,201));
     xISOT_2roi_14TeV[i] = i*5;
     exISOT_2roi_14TeV[i] = 0;
     yISOT_2roi_14TeV[i] = WH125PtISOT_2roi_14TeV->Integral(i*5,201)/WH125PtISOT_14TeV->Integral(i*5,201);
     eyISOT_2roi_14TeV[i] =TMath::Sqrt(yISOT_2roi_14TeV[i]*(1-yISOT_2roi_14TeV[i])/WH125PtISOT_14TeV->Integral(i*5,201));


     xW_1roi_14TeV[i] = i*5;
     exW_1roi_14TeV[i] = 0;
     yW_1roi_14TeV[i] = WH125PtW_1roi_14TeV->Integral(i*5,201)/WH125PtW_14TeV->Integral(i*5,201);
     eyW_1roi_14TeV[i] =TMath::Sqrt(yW_1roi_14TeV[i]*(1-yW_1roi_14TeV[i])/WH125PtW_14TeV->Integral(i*5,201));
     xT_1roi_14TeV[i] = i*5;
     exT_1roi_14TeV[i] = 0;
     yT_1roi_14TeV[i] = WH125PtT_1roi_14TeV->Integral(i*5,201)/WH125PtT_14TeV->Integral(i*5,201);
     eyT_1roi_14TeV[i] =TMath::Sqrt(yT_1roi_14TeV[i]*(1-yT_1roi_14TeV[i])/WH125PtT_14TeV->Integral(i*5,201));
     xW_2roi_14TeV[i] = i*5;
     exW_2roi_14TeV[i] = 0;
     yW_2roi_14TeV[i] = WH125PtW_2roi_14TeV->Integral(i*5,201)/WH125PtW_14TeV->Integral(i*5,201);
     eyW_2roi_14TeV[i] =TMath::Sqrt(yW_2roi_14TeV[i]*(1-yW_2roi_14TeV[i])/WH125PtW_14TeV->Integral(i*5,201));
     xT_2roi_14TeV[i] = i*5;
     exT_2roi_14TeV[i] = 0;
     yT_2roi_14TeV[i] = WH125PtT_2roi_14TeV->Integral(i*5,201)/WH125PtT_14TeV->Integral(i*5,201);
     eyT_2roi_14TeV[i] =TMath::Sqrt(yT_2roi_14TeV[i]*(1-yT_2roi_14TeV[i])/WH125PtT_14TeV->Integral(i*5,201));

     xW_1roi3p5_14TeV[i] = i*5;
     exW_1roi3p5_14TeV[i] = 0;
     yW_1roi3p5_14TeV[i] = WH125PtW_1roi3p5_14TeV->Integral(i*5,201)/WH125PtW_14TeV->Integral(i*5,201);
     eyW_1roi3p5_14TeV[i] =TMath::Sqrt(yW_1roi3p5_14TeV[i]*(1-yW_1roi3p5_14TeV[i])/WH125PtW_14TeV->Integral(i*5,201));
     xT_1roi3p5_14TeV[i] = i*5;
     exT_1roi3p5_14TeV[i] = 0;
     yT_1roi3p5_14TeV[i] = WH125PtT_1roi3p5_14TeV->Integral(i*5,201)/WH125PtT_14TeV->Integral(i*5,201);
     eyT_1roi3p5_14TeV[i] =TMath::Sqrt(yT_1roi3p5_14TeV[i]*(1-yT_1roi3p5_14TeV[i])/WH125PtT_14TeV->Integral(i*5,201));
     xW_2roi3p5_14TeV[i] = i*5;
     exW_2roi3p5_14TeV[i] = 0;
     yW_2roi3p5_14TeV[i] = WH125PtW_2roi3p5_14TeV->Integral(i*5,201)/WH125PtW_14TeV->Integral(i*5,201);
     eyW_2roi3p5_14TeV[i] =TMath::Sqrt(yW_2roi3p5_14TeV[i]*(1-yW_2roi3p5_14TeV[i])/WH125PtW_14TeV->Integral(i*5,201));
     xT_2roi3p5_14TeV[i] = i*5;
     exT_2roi3p5_14TeV[i] = 0;
     yT_2roi3p5_14TeV[i] = WH125PtT_2roi3p5_14TeV->Integral(i*5,201)/WH125PtT_14TeV->Integral(i*5,201);
     eyT_2roi3p5_14TeV[i] =TMath::Sqrt(yT_2roi3p5_14TeV[i]*(1-yT_2roi3p5_14TeV[i])/WH125PtT_14TeV->Integral(i*5,201));

   y_ratio_3p52p4_2roiW[i]=(yW_2roi3p5_14TeV[i]-yW_2roi_14TeV[i])/yW_2roi_14TeV[i];
  ey_ratio_3p52p4_2roiW[i]=(yW_2roi3p5_14TeV[i]/yW_2roi_14TeV[i])*TMath::Sqrt((eyW_2roi3p5_14TeV[i]/yW_2roi3p5_14TeV[i])*(eyW_2roi3p5_14TeV[i]/yW_2roi3p5_14TeV[i])+(eyW_2r
oi_14TeV[i]/yW_2roi_14TeV[i])*(eyW_2roi_14TeV[i]/yW_2roi3p5_14TeV[i]));
   y_ratio_3p52p4_2roiT[i]=(yT_2roi3p5_14TeV[i]-yT_2roi_14TeV[i])/yT_2roi_14TeV[i];
  ey_ratio_3p52p4_2roiT[i]=(yT_2roi3p5_14TeV[i]/yT_2roi_14TeV[i])*TMath::Sqrt((eyT_2roi3p5_14TeV[i]/yT_2roi3p5_14TeV[i])*(eyT_2roi3p5_14TeV[i]/yT_2roi3p5_14TeV[i])+(eyT_2r
oi_14TeV[i]/yT_2roi_14TeV[i])*(eyT_2roi_14TeV[i]/yT_2roi3p5_14TeV[i]));
   y_ratio_3p52p4_1roiW[i]=(yW_1roi3p5_14TeV[i]-yW_1roi_14TeV[i])/yW_1roi_14TeV[i];
  ey_ratio_3p52p4_1roiW[i]=(yW_1roi3p5_14TeV[i]/yW_1roi_14TeV[i])*TMath::Sqrt((eyW_1roi3p5_14TeV[i]/yW_1roi3p5_14TeV[i])*(eyW_1roi3p5_14TeV[i]/yW_1roi3p5_14TeV[i])+(eyW_1r
oi_14TeV[i]/yW_1roi_14TeV[i])*(eyW_1roi_14TeV[i]/yW_1roi3p5_14TeV[i]));
   y_ratio_3p52p4_1roiT[i]=(yT_1roi3p5_14TeV[i]-yT_1roi_14TeV[i])/yT_1roi_14TeV[i];
  ey_ratio_3p52p4_1roiT[i]=(yT_1roi3p5_14TeV[i]/yT_1roi_14TeV[i])*TMath::Sqrt((eyT_1roi3p5_14TeV[i]/yT_1roi3p5_14TeV[i])*(eyT_1roi3p5_14TeV[i]/yT_1roi3p5_14TeV[i])+(eyT_1r
oi_14TeV[i]/yT_1roi_14TeV[i])*(eyT_1roi_14TeV[i]/yT_1roi3p5_14TeV[i]));

   }
   grRecoW_1roi_8TeV = new TGraphErrors(n,xRecoW_1roi_8TeV,yRecoW_1roi_8TeV,exRecoW_1roi_8TeV,eyRecoW_1roi_8TeV);
   grRecoT_1roi_8TeV = new TGraphErrors(n,xRecoT_1roi_8TeV,yRecoT_1roi_8TeV,exRecoT_1roi_8TeV,eyRecoT_1roi_8TeV);
   grRecoW_1roi_14TeV = new TGraphErrors(n,xRecoW_1roi_14TeV,yRecoW_1roi_14TeV,exRecoW_1roi_14TeV,eyRecoW_1roi_14TeV);
   grRecoT_1roi_14TeV = new TGraphErrors(n,xRecoT_1roi_14TeV,yRecoT_1roi_14TeV,exRecoT_1roi_14TeV,eyRecoT_1roi_14TeV);
   grRecoW_2roi_8TeV = new TGraphErrors(n,xRecoW_2roi_8TeV,yRecoW_2roi_8TeV,exRecoW_2roi_8TeV,eyRecoW_2roi_8TeV);
   grRecoT_2roi_8TeV = new TGraphErrors(n,xRecoT_2roi_8TeV,yRecoT_2roi_8TeV,exRecoT_2roi_8TeV,eyRecoT_2roi_8TeV);
   grRecoW_2roi_14TeV = new TGraphErrors(n,xRecoW_2roi_14TeV,yRecoW_2roi_14TeV,exRecoW_2roi_14TeV,eyRecoW_2roi_14TeV);
   grRecoT_2roi_14TeV = new TGraphErrors(n,xRecoT_2roi_14TeV,yRecoT_2roi_14TeV,exRecoT_2roi_14TeV,eyRecoT_2roi_14TeV);

   grGlobalW_1roi_8TeV = new TGraphErrors(n,xGlobalW_1roi_8TeV,yGlobalW_1roi_8TeV,exGlobalW_1roi_8TeV,eyGlobalW_1roi_8TeV);
   grGlobalT_1roi_8TeV = new TGraphErrors(n,xGlobalT_1roi_8TeV,yGlobalT_1roi_8TeV,exGlobalT_1roi_8TeV,eyGlobalT_1roi_8TeV);
   grGlobalW_1roi_14TeV = new TGraphErrors(n,xGlobalW_1roi_14TeV,yGlobalW_1roi_14TeV,exGlobalW_1roi_14TeV,eyGlobalW_1roi_14TeV);
   grGlobalT_1roi_14TeV = new TGraphErrors(n,xGlobalT_1roi_14TeV,yGlobalT_1roi_14TeV,exGlobalT_1roi_14TeV,eyGlobalT_1roi_14TeV);
   grGlobalW_2roi_8TeV = new TGraphErrors(n,xGlobalW_2roi_8TeV,yGlobalW_2roi_8TeV,exGlobalW_2roi_8TeV,eyGlobalW_2roi_8TeV);
   grGlobalT_2roi_8TeV = new TGraphErrors(n,xGlobalT_2roi_8TeV,yGlobalT_2roi_8TeV,exGlobalT_2roi_8TeV,eyGlobalT_2roi_8TeV);
   grGlobalW_2roi_14TeV = new TGraphErrors(n,xGlobalW_2roi_14TeV,yGlobalW_2roi_14TeV,exGlobalW_2roi_14TeV,eyGlobalW_2roi_14TeV);
   grGlobalT_2roi_14TeV = new TGraphErrors(n,xGlobalT_2roi_14TeV,yGlobalT_2roi_14TeV,exGlobalT_2roi_14TeV,eyGlobalT_2roi_14TeV);

   grPFW_1roi_8TeV = new TGraphErrors(n,xPFW_1roi_8TeV,yPFW_1roi_8TeV,exPFW_1roi_8TeV,eyPFW_1roi_8TeV);
   grPFT_1roi_8TeV = new TGraphErrors(n,xPFT_1roi_8TeV,yPFT_1roi_8TeV,exPFT_1roi_8TeV,eyPFT_1roi_8TeV);
   grPFW_1roi_14TeV = new TGraphErrors(n,xPFW_1roi_14TeV,yPFW_1roi_14TeV,exPFW_1roi_14TeV,eyPFW_1roi_14TeV);
   grPFT_1roi_14TeV = new TGraphErrors(n,xPFT_1roi_14TeV,yPFT_1roi_14TeV,exPFT_1roi_14TeV,eyPFT_1roi_14TeV);
   grPFW_2roi_8TeV = new TGraphErrors(n,xPFW_2roi_8TeV,yPFW_2roi_8TeV,exPFW_2roi_8TeV,eyPFW_2roi_8TeV);
   grPFT_2roi_8TeV = new TGraphErrors(n,xPFT_2roi_8TeV,yPFT_2roi_8TeV,exPFT_2roi_8TeV,eyPFT_2roi_8TeV);
   grPFW_2roi_14TeV = new TGraphErrors(n,xPFW_2roi_14TeV,yPFW_2roi_14TeV,exPFW_2roi_14TeV,eyPFW_2roi_14TeV);
   grPFT_2roi_14TeV = new TGraphErrors(n,xPFT_2roi_14TeV,yPFT_2roi_14TeV,exPFT_2roi_14TeV,eyPFT_2roi_14TeV);

   grISOW_1roi_8TeV = new TGraphErrors(n,xISOW_1roi_8TeV,yISOW_1roi_8TeV,exISOW_1roi_8TeV,eyISOW_1roi_8TeV);
   grISOT_1roi_8TeV = new TGraphErrors(n,xISOT_1roi_8TeV,yISOT_1roi_8TeV,exISOT_1roi_8TeV,eyISOT_1roi_8TeV);
   grISOW_1roi_14TeV = new TGraphErrors(n,xISOW_1roi_14TeV,yISOW_1roi_14TeV,exISOW_1roi_14TeV,eyISOW_1roi_14TeV);
   grISOT_1roi_14TeV = new TGraphErrors(n,xISOT_1roi_14TeV,yISOT_1roi_14TeV,exISOT_1roi_14TeV,eyISOT_1roi_14TeV);
   grISOW_2roi_8TeV = new TGraphErrors(n,xISOW_2roi_8TeV,yISOW_2roi_8TeV,exISOW_2roi_8TeV,eyISOW_2roi_8TeV);
   grISOT_2roi_8TeV = new TGraphErrors(n,xISOT_2roi_8TeV,yISOT_2roi_8TeV,exISOT_2roi_8TeV,eyISOT_2roi_8TeV);
   grISOW_2roi_14TeV = new TGraphErrors(n,xISOW_2roi_14TeV,yISOW_2roi_14TeV,exISOW_2roi_14TeV,eyISOW_2roi_14TeV);
   grISOT_2roi_14TeV = new TGraphErrors(n,xISOT_2roi_14TeV,yISOT_2roi_14TeV,exISOT_2roi_14TeV,eyISOT_2roi_14TeV);


   grW_1roi_8TeV = new TGraphErrors(n,xW_1roi_8TeV,yW_1roi_8TeV,exW_1roi_8TeV,eyW_1roi_8TeV);
   grT_1roi_8TeV = new TGraphErrors(n,xT_1roi_8TeV,yT_1roi_8TeV,exT_1roi_8TeV,eyT_1roi_8TeV);
   grW_1roi_14TeV = new TGraphErrors(n,xW_1roi_14TeV,yW_1roi_14TeV,exW_1roi_14TeV,eyW_1roi_14TeV);
   grT_1roi_14TeV = new TGraphErrors(n,xT_1roi_14TeV,yT_1roi_14TeV,exT_1roi_14TeV,eyT_1roi_14TeV);
   grW_2roi_8TeV = new TGraphErrors(n,xW_2roi_8TeV,yW_2roi_8TeV,exW_2roi_8TeV,eyW_2roi_8TeV);
   grT_2roi_8TeV = new TGraphErrors(n,xT_2roi_8TeV,yT_2roi_8TeV,exT_2roi_8TeV,eyT_2roi_8TeV);
   grW_2roi_14TeV = new TGraphErrors(n,xW_2roi_14TeV,yW_2roi_14TeV,exW_2roi_14TeV,eyW_2roi_14TeV);
   grT_2roi_14TeV = new TGraphErrors(n,xT_2roi_14TeV,yT_2roi_14TeV,exT_2roi_14TeV,eyT_2roi_14TeV);

   grW_1roi3p5_8TeV = new TGraphErrors(n,xW_1roi3p5_8TeV,yW_1roi3p5_8TeV,exW_1roi3p5_8TeV,eyW_1roi3p5_8TeV);
   grT_1roi3p5_8TeV = new TGraphErrors(n,xT_1roi3p5_8TeV,yT_1roi3p5_8TeV,exT_1roi3p5_8TeV,eyT_1roi3p5_8TeV);
   grW_1roi3p5_14TeV = new TGraphErrors(n,xW_1roi3p5_14TeV,yW_1roi3p5_14TeV,exW_1roi3p5_14TeV,eyW_1roi3p5_14TeV);
   grT_1roi3p5_14TeV = new TGraphErrors(n,xT_1roi3p5_14TeV,yT_1roi3p5_14TeV,exT_1roi3p5_14TeV,eyT_1roi3p5_14TeV);
   grW_2roi3p5_8TeV = new TGraphErrors(n,xW_2roi3p5_8TeV,yW_2roi3p5_8TeV,exW_2roi3p5_8TeV,eyW_2roi3p5_8TeV);
   grT_2roi3p5_8TeV = new TGraphErrors(n,xT_2roi3p5_8TeV,yT_2roi3p5_8TeV,exT_2roi3p5_8TeV,eyT_2roi3p5_8TeV);
   grW_2roi3p5_14TeV = new TGraphErrors(n,xW_2roi3p5_14TeV,yW_2roi3p5_14TeV,exW_2roi3p5_14TeV,eyW_2roi3p5_14TeV);
   grT_2roi3p5_14TeV = new TGraphErrors(n,xT_2roi3p5_14TeV,yT_2roi3p5_14TeV,exT_2roi3p5_14TeV,eyT_2roi3p5_14TeV);
gr_ratio_3p52p4_2roiW = new TGraphErrors(n,xW_2roi3p5_14TeV,y_ratio_3p52p4_2roiW,exW_2roi3p5_14TeV,ey_ratio_3p52p4_2roiW);
gr_ratio_3p52p4_2roiT = new TGraphErrors(n,xT_2roi3p5_14TeV,y_ratio_3p52p4_2roiT,exT_2roi3p5_14TeV,ey_ratio_3p52p4_2roiT);
gr_ratio_3p52p4_1roiW = new TGraphErrors(n,xW_1roi3p5_14TeV,y_ratio_3p52p4_1roiW,exW_1roi3p5_14TeV,ey_ratio_3p52p4_1roiW);
gr_ratio_3p52p4_1roiT = new TGraphErrors(n,xT_1roi3p5_14TeV,y_ratio_3p52p4_1roiT,exT_1roi3p5_14TeV,ey_ratio_3p52p4_1roiT);

/*   grGlobal_8TeV = new TGraphErrors(n,xGlobal_8TeV,yGlobal_8TeV,exGlobal_8TeV,eyGlobal_8TeV);
   grGlobal_14TeV = new TGraphErrors(n,xGlobal_14TeV,yGlobal_14TeV,exGlobal_14TeV,eyGlobal_14TeV);
   grPF_8TeV = new TGraphErrors(n,xPF_8TeV,yPF_8TeV,exPF_8TeV,eyPF_8TeV);
   grPF_14TeV = new TGraphErrors(n,xPF_14TeV,yPF_14TeV,exPF_14TeV,eyPF_14TeV);
   grISO_8TeV = new TGraphErrors(n,xISO_8TeV,yISO_8TeV,exISO_8TeV,eyISO_8TeV);
   grISO_14TeV = new TGraphErrors(n,xISO_14TeV,yISO_14TeV,exISO_14TeV,eyISO_14TeV);
*/
/*TCanvas *Canv3Giacomelli = new TCanvas("Canv3Giacomelli"," ", 750, 900);
//TCanvas *Canv3Giacomelli = new TCanvas("Canv3Giacomelli"," ");
//Canv3Giacomelli->cd();
Canv3Giacomelli->Divide(2,1);
Canv3Giacomelli->cd(1);

Canv3Giacomelli->SetGridy();
  TPad *pad2 = new TPad("pad2", "foo", 0, 0,   1, 0.3);
  TPad *pad1 = new TPad("pad1", "foo", 0, 0.2, 1, 1);
  pad2->SetBottomMargin(0.3);
//  pad1->SetTopMargin(0.01);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  pad1->SetGridy();

   grW_1roi3p5_8TeV->SetMarkerColor(4);
   grW_1roi3p5_14TeV->SetMarkerColor(4);
   grW_1roi_8TeV->SetMarkerColor(4);
   grW_1roi_14TeV->SetMarkerColor(4);
   //grW_1roi3p5_8TeV->SetMarkeStyle(24);
   //grW_1roi_8TeV->SetMarkerStyle(24);
   grW_1roi3p5_14TeV->GetYaxis()->SetTitle("|#eta_{#mu}| in roi / total #mu (1Muon in eta r.o.i.)");
   grW_1roi3p5_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) L muon");
   grW_1roi3p5_14TeV->GetYaxis()->SetTitleOffset(1.5);
   grW_1roi3p5_14TeV->GetYaxis()->SetLabelSize(0.8*grW_1roi3p5_14TeV->GetYaxis()->GetLabelSize());

   grW_1roi3p5_14TeV->SetMarkerSize(1.5);
   grW_1roi3p5_8TeV->SetMarkerSize(1.5);
   grW_1roi_14TeV->SetMarkerSize(1.5);
   grW_1roi_8TeV->SetMarkerSize(1.5);
   grW_1roi_14TeV->SetMarkerStyle(4);
   grW_1roi_8TeV->SetMarkerStyle(4);
//  grW_1roi3p5_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.4);
//gr_ratio_3p52p4_1roiT->Draw("ACP");
//gr_ratio_3p52p4_2roiW->Draw("ACP");
//gr_ratio_3p52p4_2roiW->Draw("CP");
//gr_ratio_3p52p4_2roiT->Draw("CP");
   grW_1roi3p5_14TeV->Draw("ACP");
   grW_1roi3p5_14TeV->SetMaximum(0.25);
   grW_1roi3p5_14TeV->SetMinimum(0.05);
   grW_1roi_14TeV->Draw("CP");
//   grW_1roi_8TeV->Draw("CP");
//   grW_1roi3p5_8TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
//legend->AddEntry(grW_1roi3p5_8TeV, "8TeV 1.6<|#eta_{#mu from W}|<3.5","p");
legend->AddEntry(grW_1roi3p5_14TeV, "14TeV 1.6<|#eta_{#mu from W}|<3.5","p");
//legend->AddEntry(grW_1roi_8TeV, "8TeV 1.6<|#eta_{#mu from W}|<2.4","p");
legend->AddEntry(grW_1roi_14TeV, "14TeV 1.6<|#eta_{#mu from W}|<2.4","p");
legend->Draw("same");
  ll->Draw("same");
 pad2->cd();
  pad2->SetGridy();
gr_ratio_3p52p4_1roiW->GetYaxis()->SetTitle("Rel. Improvement");
gr_ratio_3p52p4_1roiW->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) L muon");
//   grW_1roi3p5_14TeV->Draw("ACP");
gr_ratio_3p52p4_1roiW->Draw("ACP");
TAxis* yaxis=gr_ratio_3p52p4_1roiW->GetYaxis();
//  yaxis->SetTitle("Ratio f_3p5-f_2p4/f_2p4");
  yaxis->SetLabelSize(2.0*yaxis->GetLabelSize());
  yaxis->SetTitleSize(2.0*yaxis->GetTitleSize());
  yaxis->SetTitleOffset(0.7);

  TAxis* xaxis=gr_ratio_3p52p4_1roiW->GetXaxis();
  xaxis->SetLabelSize(2.4*xaxis->GetLabelSize());
  xaxis->SetTitleSize(2.5*xaxis->GetTitleSize());

Canv3Giacomelli->cd(2);
Canv3Giacomelli->SetGridy();
  TPad *pad2 = new TPad("pad2", "foo", 0, 0,   1, 0.3);
  TPad *pad1 = new TPad("pad1", "foo", 0, 0.2, 1, 1);
  pad2->SetBottomMargin(0.3);
//  pad1->SetTopMargin(0.01);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  pad1->SetGridy();

   grT_1roi3p5_8TeV->SetMarkerColor(4);
   grT_1roi3p5_14TeV->SetMarkerColor(4);
   grT_1roi_8TeV->SetMarkerColor(4);
   grT_1roi_14TeV->SetMarkerColor(4);
   //grT_1roi3p5_8TeV->SetMarkeStyle(24);
   //grT_1roi_8TeV->SetMarkerStyle(24);
   grT_1roi3p5_14TeV->GetYaxis()->SetTitle("|#eta_{#mu}| in roi / total #mu (1Muon in eta r.o.i.)");
   grT_1roi3p5_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) SL muon");
   grT_1roi3p5_14TeV->GetYaxis()->SetTitleOffset(1.5);
   grT_1roi3p5_14TeV->GetYaxis()->SetLabelSize(0.8*grT_1roi3p5_14TeV->GetYaxis()->GetLabelSize());

   grT_1roi3p5_14TeV->SetMarkerSize(1.5);
   grT_1roi3p5_8TeV->SetMarkerSize(1.5);
   grT_1roi_14TeV->SetMarkerSize(1.5);
   grT_1roi_8TeV->SetMarkerSize(1.5);
   grT_1roi_14TeV->SetMarkerStyle(4);
   grT_1roi_8TeV->SetMarkerStyle(4);
//  grT_1roi3p5_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.4);
//gr_ratio_3p52p4_1roiT->Draw("ACP");
//gr_ratio_3p52p4_2roiT->Draw("ACP");
//gr_ratio_3p52p4_2roiT->Draw("CP");
//gr_ratio_3p52p4_2roiT->Draw("CP");
   grT_1roi3p5_14TeV->Draw("ACP");
   grT_1roi3p5_14TeV->SetMaximum(0.25);
   grT_1roi3p5_14TeV->SetMinimum(0.05);
   grT_1roi_14TeV->Draw("CP");
//   grT_1roi_8TeV->Draw("CP");
//   grT_1roi3p5_8TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
//legend->AddEntry(grT_1roi3p5_8TeV, "8TeV 1.6<|#eta_{#mu from T}|<3.5","p");
legend->AddEntry(grT_1roi3p5_14TeV, "14TeV 1.6<|#eta_{#mu from Tau}|<3.5","p");
//legend->AddEntry(grT_1roi_8TeV, "8TeV 1.6<|#eta_{#mu from T}|<2.4","p");
legend->AddEntry(grT_1roi_14TeV, "14TeV 1.6<|#eta_{#mu from Tau}|<2.4","p");
legend->Draw("same");
  ll->Draw("same");
  pad2->cd();
  pad2->SetGridy();
gr_ratio_3p52p4_1roiT->GetYaxis()->SetTitle("Rel. Improvement");
gr_ratio_3p52p4_1roiT->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) SL muon");
//   grT_1roi3p5_14TeV->Draw("ACP");
gr_ratio_3p52p4_1roiT->Draw("ACP");
  TAxis* yaxis=gr_ratio_3p52p4_1roiT->GetYaxis();
//  yaxis->SetTitle("Ratio f_3p5-f_2p4/f_2p4");
  yaxis->SetLabelSize(2.0*yaxis->GetLabelSize());
  yaxis->SetTitleSize(2.0*yaxis->GetTitleSize());
  yaxis->SetTitleOffset(0.7);
  TAxis* xaxis=gr_ratio_3p52p4_1roiT->GetXaxis();
  xaxis->SetLabelSize(2.4*xaxis->GetLabelSize());
  xaxis->SetTitleSize(2.5*xaxis->GetTitleSize());
*/
///////////////////////////
/*TCanvas *Canv3Giacomelli2 = new TCanvas("Canv3Giacomelli2"," ",750,900);
//Canv3Giacomelli2->Divide(2,1);
//Canv3Giacomelli2->cd(1);
Canv3Giacomelli->SetGridy();
  TPad *pad2 = new TPad("pad2", "foo", 0, 0,   1, 0.3);
  TPad *pad1 = new TPad("pad1", "foo", 0, 0.2, 1, 1);
  pad2->SetBottomMargin(0.3);
//  pad1->SetTopMargin(0.01);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  pad1->SetGridy();

   grW_2roi3p5_8TeV->SetMarkerColor(4);
   grW_2roi3p5_14TeV->SetMarkerColor(4);
   grW_2roi_8TeV->SetMarkerColor(4);
   grW_2roi_14TeV->SetMarkerColor(4);
   //grW_2roi3p5_8TeV->SetMarkeStyle(24);
   //grW_2roi_8TeV->SetMarkerStyle(24);
   grW_2roi3p5_14TeV->GetYaxis()->SetTitle("|#eta_{#mu}| in roi / total #mu (2Muons in eta r.o.i.)");
   grW_2roi3p5_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) L muon");
   grW_2roi3p5_14TeV->GetYaxis()->SetTitleOffset(1.5);
   grW_2roi3p5_14TeV->GetYaxis()->SetLabelSize(0.8*grW_2roi3p5_14TeV->GetYaxis()->GetLabelSize());

   grW_2roi3p5_14TeV->SetMarkerSize(1.5);
   grW_2roi3p5_8TeV->SetMarkerSize(1.5);
   grW_2roi_14TeV->SetMarkerSize(1.5);
   grW_2roi_8TeV->SetMarkerSize(1.5);
   grW_2roi_14TeV->SetMarkerStyle(4);
   grW_2roi_8TeV->SetMarkerStyle(4);
//  grW_2roi3p5_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.4);
//gr_ratio_3p52p4_2roiT->Draw("ACP");
//gr_ratio_3p52p4_2roiW->Draw("ACP");
//gr_ratio_3p52p4_2roiW->Draw("CP");
//gr_ratio_3p52p4_2roiT->Draw("CP");
   grW_2roi3p5_14TeV->Draw("ACP");
   grW_2roi3p5_14TeV->SetMaximum(0.4);
   grW_2roi3p5_14TeV->SetMinimum(0.0);
   grW_2roi_14TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
//legend->AddEntry(grW_2roi3p5_8TeV, "8TeV 1.6<|#eta_{#mu from W}|<3.5","p");
legend->AddEntry(grW_2roi3p5_14TeV, "14TeV 1.6<|#eta_{#mu from W}|<3.5","p");
//legend->AddEntry(grW_2roi_8TeV, "8TeV 1.6<|#eta_{#mu from W}|<2.4","p");
legend->AddEntry(grW_2roi_14TeV, "14TeV 1.6<|#eta_{#mu from W}|<2.4","p");
legend->Draw("same");
  ll->Draw("same");
 pad2->cd();
  pad2->SetGridy();
gr_ratio_3p52p4_2roiW->GetYaxis()->SetTitle("Rel. Improvement");
gr_ratio_3p52p4_2roiW->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) L muon");
//   grW_2roi3p5_14TeV->Draw("ACP");
gr_ratio_3p52p4_2roiW->Draw("ACP");
TAxis* yaxis=gr_ratio_3p52p4_2roiW->GetYaxis();
//  yaxis->SetTitle("Ratio f_3p5-f_2p4/f_2p4");
  yaxis->SetLabelSize(2.0*yaxis->GetLabelSize());
  yaxis->SetTitleSize(2.0*yaxis->GetTitleSize());
  yaxis->SetTitleOffset(0.7);

  TAxis* xaxis=gr_ratio_3p52p4_2roiW->GetXaxis();
  xaxis->SetLabelSize(2.4*xaxis->GetLabelSize());
  xaxis->SetTitleSize(2.5*xaxis->GetTitleSize());

Canv3Giacomelli2->cd(2);

Canv3Giacomelli2->SetGridy();
  TPad *pad2 = new TPad("pad2", "foo", 0, 0,   1, 0.3);
  TPad *pad1 = new TPad("pad1", "foo", 0, 0.2, 1, 1);
  pad2->SetBottomMargin(0.3);
//  pad1->SetTopMargin(0.01);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  pad1->SetGridy();

   grT_2roi3p5_8TeV->SetMarkerColor(4);
   grT_2roi3p5_14TeV->SetMarkerColor(4);
   grT_2roi_8TeV->SetMarkerColor(4);
   grT_2roi_14TeV->SetMarkerColor(4);
   //grT_2roi3p5_8TeV->SetMarkeStyle(24);
   //grT_2roi_8TeV->SetMarkerStyle(24);
   grT_2roi3p5_14TeV->GetYaxis()->SetTitle("|#eta_{#mu}| in roi / total #mu (2Muons in eta r.o.i.)");
   grT_2roi3p5_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) SL muon");
   grT_2roi3p5_14TeV->GetYaxis()->SetTitleOffset(1.5);
   grT_2roi3p5_14TeV->GetYaxis()->SetLabelSize(0.8*grT_2roi3p5_14TeV->GetYaxis()->GetLabelSize());

   grT_2roi3p5_14TeV->SetMarkerSize(1.5);
   grT_2roi3p5_8TeV->SetMarkerSize(1.5);
   grT_2roi_14TeV->SetMarkerSize(1.5);
   grT_2roi_8TeV->SetMarkerSize(1.5);
   grT_2roi_14TeV->SetMarkerStyle(4);
   grT_2roi_8TeV->SetMarkerStyle(4);
//  grT_2roi3p5_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.4);
//gr_ratio_3p52p4_2roiT->Draw("ACP");
//gr_ratio_3p52p4_2roiT->Draw("ACP");
//gr_ratio_3p52p4_2roiT->Draw("CP");
//gr_ratio_3p52p4_2roiT->Draw("CP");
   grT_2roi3p5_14TeV->Draw("ACP");
   grT_2roi3p5_14TeV->SetMaximum(0.4);
   grT_2roi3p5_14TeV->SetMinimum(0.0);
   grT_2roi_14TeV->Draw("CP");
//   grT_2roi_8TeV->Draw("CP");
//   grT_2roi3p5_8TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
//legend->AddEntry(grT_2roi3p5_8TeV, "8TeV 1.6<|#eta_{#mu from T}|<3.5","p");
legend->AddEntry(grT_2roi3p5_14TeV, "14TeV 1.6<|#eta_{#mu from Tau}|<3.5","p");
//legend->AddEntry(grT_2roi_8TeV, "8TeV 1.6<|#eta_{#mu from T}|<2.4","p");
legend->AddEntry(grT_2roi_14TeV, "14TeV 1.6<|#eta_{#mu from Tau}|<2.4","p");
legend->Draw("same");
  ll->Draw("same");
  pad2->cd();
  pad2->SetGridy();
gr_ratio_3p52p4_2roiT->GetYaxis()->SetTitle("Rel. Improvement");
gr_ratio_3p52p4_2roiT->GetXaxis()->SetTitle("P_{T #mu} Cut (GeV) SL muon");
//   grT_2roi3p5_14TeV->Draw("ACP");
gr_ratio_3p52p4_2roiT->Draw("ACP");
  TAxis* yaxis=gr_ratio_3p52p4_2roiT->GetYaxis();
//  yaxis->SetTitle("Ratio f_3p5-f_2p4/f_2p4");
  yaxis->SetLabelSize(2.0*yaxis->GetLabelSize());
  yaxis->SetTitleSize(2.0*yaxis->GetTitleSize());
  yaxis->SetTitleOffset(0.7);
  TAxis* xaxis=gr_ratio_3p52p4_2roiT->GetXaxis();
  xaxis->SetLabelSize(2.4*xaxis->GetLabelSize());
  xaxis->SetTitleSize(2.5*xaxis->GetTitleSize());
*/

TCanvas *Canv_frac8 = new TCanvas("Canv_frac8"," ");
Canv_frac8->Divide(2,1);
Canv_frac8->cd(1);
   grW_1roi_8TeV->SetMarkerSize(2);
   grRecoW_1roi_8TeV->SetMarkerSize(2);
   grGlobalW_1roi_8TeV->SetMarkerSize(2);
   grPFW_1roi_8TeV->SetMarkerSize(2);
   grISOW_1roi_8TeV->SetMarkerSize(2);

//   gr_8TeV->SetMarkerColor(4);
   grW_1roi_8TeV->SetMarkerColor(4);
   grRecoW_1roi_8TeV->SetMarkerColor(1);
   grGlobalW_1roi_8TeV->SetMarkerColor(2);
   grPFW_1roi_8TeV->SetMarkerColor(3);
   grISOW_1roi_8TeV->SetMarkerColor(6);
//   grISO_8TeV->SetMarkerColor(6);
   grRecoW_1roi_8TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (1Muon in eta r.o.i.)");
   grRecoW_1roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] Leading Muon");
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);
   grRecoW_1roi_8TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoW_1roi_8TeV->Draw("ACP");
   grW_1roi_8TeV->Draw("CP");
   grGlobalW_1roi_8TeV->Draw("CP");
   grPFW_1roi_8TeV->Draw("CP");
   grISOW_1roi_8TeV->Draw("CP");
//   grRecoW_1roi_8TeV->SetMaximum(0.3);
//   grRecoW_1roi_8TeV->SetMinimum(0.1);
/*   grReco_8TeV->Draw("CP");
   grISO_8TeV->Draw("CP");
*/
TLegend* legendW8_1roi = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendW8_1roi->SetTextSize(0.025);
legendW8_1roi->SetFillColor(0);
legendW8_1roi->AddEntry(grW_1roi_8TeV, " Muon from W 8TeV","p");
legendW8_1roi->AddEntry(grRecoW_1roi_8TeV, "Reco L Muon 8TeV","p");
legendW8_1roi->AddEntry(grGlobalW_1roi_8TeV, "Global L Muon 8TeV","p");
legendW8_1roi->AddEntry(grPFW_1roi_8TeV, "PF L Muon 8TeV","p");
legendW8_1roi->AddEntry(grISOW_1roi_8TeV, "ISO L Muon 8TeV","p");
//legend->AddEntry(grISO_8TeV, "ISO 8 TeV","p");

legendW8_1roi->Draw("same");
Canv_frac8->cd(2);
   grT_1roi_8TeV->SetMarkerSize(2);
   grRecoT_1roi_8TeV->SetMarkerSize(2);
   grGlobalT_1roi_8TeV->SetMarkerSize(2);
   grPFT_1roi_8TeV->SetMarkerSize(2);
   grISOT_1roi_8TeV->SetMarkerSize(2);

   grT_1roi_8TeV->SetMarkerColor(4);
   grRecoT_1roi_8TeV->SetMarkerColor(1);
   grGlobalT_1roi_8TeV->SetMarkerColor(2);
   grPFT_1roi_8TeV->SetMarkerColor(3);
   grISOT_1roi_8TeV->SetMarkerColor(6);
//   grISO_8TeV->SetMarkerColor(6);
   grRecoT_1roi_8TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (1Muon in eta r.o.i.)");
   grRecoT_1roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] SubLeading Muon");
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);
   grRecoT_1roi_8TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoT_1roi_8TeV->Draw("ACP");
   grT_1roi_8TeV->Draw("CP");
   grGlobalT_1roi_8TeV->Draw("CP");
   grPFT_1roi_8TeV->Draw("CP");
   grISOT_1roi_8TeV->Draw("CP");
/*   gr_8TeV->SetMaximum(0.3);
   gr_8TeV->SetMinimum(0.1);
   grReco_8TeV->Draw("CP");
   grISO_8TeV->Draw("CP");
*/
TLegend* legendT8_1roi = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendT8_1roi->SetTextSize(0.025);
legendT8_1roi->SetFillColor(0);
legendT8_1roi->AddEntry(grT_1roi_8TeV, " Muon from Tau 8TeV","p");
legendT8_1roi->AddEntry(grRecoT_1roi_8TeV, "Reco SL Muon 8TeV","p");
legendT8_1roi->AddEntry(grGlobalT_1roi_8TeV, "Global SL Muon 8TeV","p");
legendT8_1roi->AddEntry(grPFT_1roi_8TeV, "PF SL Muon 8TeV","p");
legendT8_1roi->AddEntry(grISOT_1roi_8TeV, "ISO SL Muon 8TeV","p");
//legend->AddEntry(grISO_8TeV, "ISO 8 TeV","p");
legendT8_1roi->Draw("same");

TCanvas *Canv_frac8_2roi = new TCanvas("Canv_frac8_2roi"," ");
Canv_frac8_2roi->Divide(2,1);
Canv_frac8_2roi->cd(1);
   grW_2roi_8TeV->SetMarkerSize(2);
   grRecoW_2roi_8TeV->SetMarkerSize(2);
   grGlobalW_2roi_8TeV->SetMarkerSize(2);
   grPFW_2roi_8TeV->SetMarkerSize(2);
   grISOW_2roi_8TeV->SetMarkerSize(2);

//   gr_8TeV->SetMarkerColor(4);
   grW_2roi_8TeV->SetMarkerColor(4);
   grRecoW_2roi_8TeV->SetMarkerColor(1);
   grGlobalW_2roi_8TeV->SetMarkerColor(2);
   grPFW_2roi_8TeV->SetMarkerColor(3);
   grISOW_2roi_8TeV->SetMarkerColor(6);
//   grISO_8TeV->SetMarkerColor(6);
   grRecoW_2roi_8TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (2Muons in eta r.o.i.)");
   grRecoW_2roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] Leading Muon");
   //GR_14tEV->SetMarkerStyle(21);
   grRecoW_2roi_8TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoW_2roi_8TeV->Draw("ACP");
   grW_2roi_8TeV->Draw("cp");
   grGlobalW_2roi_8TeV->Draw("CP");
   grPFW_2roi_8TeV->Draw("CP");
   grISOW_2roi_8TeV->Draw("CP");
/*   gr_8TeV->SetMaximum(0.3);
   gr_8TeV->SetMinimum(0.1);
   grReco_8TeV->Draw("CP");
   grISO_8TeV->Draw("CP");
*/
TLegend* legendW8_2roi = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendW8_2roi->SetTextSize(0.025);
legendW8_2roi->SetFillColor(0);
legendW8_2roi->AddEntry(grW_2roi_8TeV, " Muon from W 8TeV","p");
legendW8_2roi->AddEntry(grRecoW_2roi_8TeV, "Reco L Muon 8TeV","p");
legendW8_2roi->AddEntry(grGlobalW_2roi_8TeV, "Global L Muon 8TeV","p");
legendW8_2roi->AddEntry(grPFW_2roi_8TeV, "PF L Muon 8TeV","p");
legendW8_2roi->AddEntry(grISOW_2roi_8TeV, "ISO L Muon 8TeV","p");
//legend->AddEntry(grISO_8TeV, "ISO 8 TeV","p");
legendW8_2roi->Draw("same");
Canv_frac8_2roi->cd(2);
   grT_2roi_8TeV->SetMarkerSize(2);
   grRecoT_2roi_8TeV->SetMarkerSize(2);
   grGlobalT_2roi_8TeV->SetMarkerSize(2);
   grPFT_2roi_8TeV->SetMarkerSize(2);
   grISOT_2roi_8TeV->SetMarkerSize(2);

   grT_2roi_8TeV->SetMarkerColor(4);
   grRecoT_2roi_8TeV->SetMarkerColor(1);
   grGlobalT_2roi_8TeV->SetMarkerColor(2);
   grPFT_2roi_8TeV->SetMarkerColor(3);
   grISOT_2roi_8TeV->SetMarkerColor(6);
//   grISO_8TeV->SetMarkerColor(6);
   grRecoT_2roi_8TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (2Muons in eta r.o.i.)");
   grRecoT_2roi_8TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] SubLeading Muon");
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);
   grRecoT_2roi_8TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoT_2roi_8TeV->Draw("ACP");
   grT_2roi_8TeV->Draw("CP");
   grGlobalT_2roi_8TeV->Draw("CP");
   grPFT_2roi_8TeV->Draw("CP");
   grISOT_2roi_8TeV->Draw("CP");
/*   gr_8TeV->SetMaximum(0.3);
   gr_8TeV->SetMinimum(0.1);
   grReco_8TeV->Draw("CP");
   grISO_8TeV->Draw("CP");
*/
TLegend* legendT8_2roi = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendT8_2roi->SetTextSize(0.025);
legendT8_2roi->SetFillColor(0);
legendT8_2roi->AddEntry(grT_2roi_8TeV, "Muon from Tau 8TeV","p");
legendT8_2roi->AddEntry(grRecoT_2roi_8TeV, "Reco SL Muon 8TeV","p");
legendT8_2roi->AddEntry(grGlobalT_2roi_8TeV, "Global SL Muon 8TeV","p");
legendT8_2roi->AddEntry(grPFT_2roi_8TeV, "PF SL Muon 8TeV","p");
legendT8_2roi->AddEntry(grISOT_2roi_8TeV, "ISO SL Muon 8TeV","p");
//legend->AddEntry(grISO_8TeV, "ISO 8 TeV","p");

legendT8_2roi->Draw("same");


TCanvas *Canv_frac14 = new TCanvas("Canv_frac14"," ");
/*Canv_frac14->Divide(2,1);
Canv_frac14->cd(1);
*/   grW_1roi_14TeV->SetMarkerStyle(24);
   grRecoW_1roi_14TeV->SetMarkerStyle(24);
   grGlobalW_1roi_14TeV->SetMarkerStyle(24);
   grPFW_1roi_14TeV->SetMarkerStyle(24);
   grISOW_1roi_14TeV->SetMarkerStyle(24);

   grW_1roi_14TeV->SetMarkerSize(2);
   grRecoW_1roi_14TeV->SetMarkerSize(2);
   grGlobalW_1roi_14TeV->SetMarkerSize(2);
   grPFW_1roi_14TeV->SetMarkerSize(2);
   grISOW_1roi_14TeV->SetMarkerSize(2);


   grW_1roi_14TeV->SetMarkerColor(4);
   grRecoW_1roi_14TeV->SetMarkerColor(1);
   grGlobalW_1roi_14TeV->SetMarkerColor(2);
   grPFW_1roi_14TeV->SetMarkerColor(3);
   grISOW_1roi_14TeV->SetMarkerColor(6);
   grRecoW_1roi_14TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (1Muon in eta r.o.i.)");
   grRecoW_1roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] Leading Muon");
   grRecoW_1roi_14TeV->GetYaxis()->SetTitleOffset(1.5);
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);
   grRecoW_1roi_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoW_1roi_14TeV->Draw("ACP");
   grW_1roi_14TeV->Draw("CP");
   grGlobalW_1roi_14TeV->Draw("CP");
   grPFW_1roi_14TeV->Draw("CP");
   grISOW_1roi_14TeV->Draw("CP");
/*   grRecoW_2roi_8TeV->Draw("CP");
   grW_2roi_8TeV->Draw("CP");
   grGlobalW_2roi_8TeV->Draw("CP");
   grPFW_2roi_8TeV->Draw("CP");
   grISOW_2roi_8TeV->Draw("CP");
*/
TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
legend->AddEntry(grW_1roi_14TeV, "Muon from W 14TeV_PU50bx25","p");
legend->AddEntry(grRecoW_1roi_14TeV, "Reco L Muon 14TeV_PU50bx25","p");
legend->AddEntry(grGlobalW_1roi_14TeV, "Global L Muon 14TeV_PU50bx25","p");
legend->AddEntry(grPFW_1roi_14TeV, "PF L Muon 14TeV_PU50bx25","p");
legend->AddEntry(grISOW_1roi_14TeV, "ISO L Muon 14TeV_PU50bx25","p");
//legend->AddEntry(grISO_14TeV, "ISO 14 TeV","p");

legend->Draw("same");
legendW8_1roi->Draw("same");
  ll->Draw("same");
/*
Canv_frac14->cd(2);
   
   grT_1roi_14TeV->SetMarkerSize(2);
   grRecoT_1roi_14TeV->SetMarkerSize(2);
   grGlobalT_1roi_14TeV->SetMarkerSize(2);
   grPFT_1roi_14TeV->SetMarkerSize(2);
   grISOT_1roi_14TeV->SetMarkerSize(2);

   grT_1roi_14TeV->SetMarkerStyle(24);
   grRecoT_1roi_14TeV->SetMarkerStyle(24);
   grGlobalT_1roi_14TeV->SetMarkerStyle(24);
   grPFT_1roi_14TeV->SetMarkerStyle(24);
   grISOT_1roi_14TeV->SetMarkerStyle(24);
   grT_1roi_14TeV->SetMarkerColor(4);
   grRecoT_1roi_14TeV->SetMarkerColor(1);
   grGlobalT_1roi_14TeV->SetMarkerColor(2);
   grPFT_1roi_14TeV->SetMarkerColor(3);
   grISOT_1roi_14TeV->SetMarkerColor(6);
//   grISO_14TeV->SetMarkerColor(6);
   grRecoT_1roi_14TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (1Muon in eta r.o.i.)");
   grRecoT_1roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] SubLeading Muon");
   grRecoT_1roi_14TeV->GetYaxis()->SetTitleOffset(1.5);
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);
   grRecoT_1roi_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoT_1roi_14TeV->Draw("ACP");
   grT_1roi_14TeV->Draw("CP");
   grGlobalT_1roi_14TeV->Draw("CP");
   grPFT_1roi_14TeV->Draw("CP");
   grISOT_1roi_14TeV->Draw("CP");

   grRecoT_1roi_8TeV->Draw("CP");
   grT_1roi_8TeV->Draw("CP");
   grGlobalT_1roi_8TeV->Draw("CP");
   grPFT_1roi_8TeV->Draw("CP");
   grISOT_1roi_8TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
legend->AddEntry(grT_1roi_14TeV, " Muon from Tau @14TeV_PU50bx25","p");
legend->AddEntry(grRecoT_1roi_14TeV, "Reco SL Muon @14TeV_PU50bx25","p");
legend->AddEntry(grGlobalT_1roi_14TeV, "Global SL Muon 14TeV_PU50bx25","p");
legend->AddEntry(grPFT_1roi_14TeV, "PF SL Muon 14TeV_PU50bx25","p");
legend->AddEntry(grISOT_1roi_14TeV, "ISO SL Muon 14TeV_PU50bx25","p");
//legend->AddEntry(grISO_14TeV, "ISO 14 TeV","p");

legend->Draw("same");
legendT8_1roi->Draw("same");
  ll->Draw("same");
*/

TCanvas *Canv_frac14_2roi = new TCanvas("Canv_frac14_2roi"," ");
//Canv_frac14_2roi->Divide(2,1);
//Canv_frac14_2roi->cd(1);
/*   grW_2roi_14TeV->SetMarkerSize(2);
   grRecoW_2roi_14TeV->SetMarkerSize(2);
   grGlobalW_2roi_14TeV->SetMarkerSize(2);
   grPFW_2roi_14TeV->SetMarkerSize(2);
   grISOW_2roi_14TeV->SetMarkerSize(2);


   grW_2roi_14TeV->SetMarkerStyle(24);
   grRecoW_2roi_14TeV->SetMarkerStyle(24);
   grGlobalW_2roi_14TeV->SetMarkerStyle(24);
   grPFW_2roi_14TeV->SetMarkerStyle(24);
   grISOW_2roi_14TeV->SetMarkerStyle(24);
//   gr_14TeV->SetMarkerColor(4);
   grW_2roi_14TeV->SetMarkerColor(4);
   grRecoW_2roi_14TeV->SetMarkerColor(1);
   grGlobalW_2roi_14TeV->SetMarkerColor(2);
   grPFW_2roi_14TeV->SetMarkerColor(3);
   grISOW_2roi_14TeV->SetMarkerColor(6);
//   grISO_14TeV->SetMarkerColor(6);

   grRecoW_2roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] Leading Muon");
   grRecoW_2roi_14TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (2Muons in eta r.o.i.)");
   grRecoW_2roi_14TeV->GetYaxis()->SetTitleOffset(1.5);
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);
   grRecoW_2roi_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoW_2roi_14TeV->Draw("ACP");
   grW_2roi_14TeV->Draw("CP");
   grGlobalW_2roi_14TeV->Draw("CP");
   grPFW_2roi_14TeV->Draw("CP");
   grISOW_2roi_14TeV->Draw("CP");
   grRecoW_2roi_8TeV->Draw("CP");
   grW_2roi_8TeV->Draw("CP");
   grGlobalW_2roi_8TeV->Draw("CP");
   grPFW_2roi_8TeV->Draw("CP");
   grISOW_2roi_8TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
legend->AddEntry(grW_2roi_14TeV, "Muon from W 14TeV_PU50bx25","p");
legend->AddEntry(grRecoW_2roi_14TeV, "Reco L Muon 14TeV_PU50bx25","p");
legend->AddEntry(grGlobalW_2roi_14TeV, "Global L Muon 14TeV_PU50bx25","p");
legend->AddEntry(grPFW_2roi_14TeV, "PF L Muon 14TeV_PU50bx25","p");
legend->AddEntry(grISOW_2roi_14TeV, "ISO L Muon 14TeV_PU50bx25","p");
//legend->AddEntry(grISO_14TeV, "ISO 14 TeV","p");

legend->Draw("same");
legendW8_2roi->Draw("same");
  ll->Draw("same");
Canv_frac14_2roi->cd(2);
*/   grT_2roi_14TeV->SetMarkerSize(2);
   grRecoT_2roi_14TeV->SetMarkerSize(2);
   grGlobalT_2roi_14TeV->SetMarkerSize(2);
   grPFT_2roi_14TeV->SetMarkerSize(2);
   grISOT_2roi_14TeV->SetMarkerSize(2);

   grT_2roi_14TeV->SetMarkerStyle(24);
   grRecoT_2roi_14TeV->SetMarkerStyle(24);
   grGlobalT_2roi_14TeV->SetMarkerStyle(24);
   grPFT_2roi_14TeV->SetMarkerStyle(24);
   grISOT_2roi_14TeV->SetMarkerStyle(24);

   grT_2roi_14TeV->SetMarkerColor(4);
   grRecoT_2roi_14TeV->SetMarkerColor(1);
   grGlobalT_2roi_14TeV->SetMarkerColor(2);
   grPFT_2roi_14TeV->SetMarkerColor(3);
   grISOT_2roi_14TeV->SetMarkerColor(6);
//   grISO_14TeV->SetMarkerColor(6);
   grRecoT_2roi_14TeV->GetYaxis()->SetTitle("1.6<|#eta_{#mu}|<2.4 / total #mu (2Muons in eta r.o.i.)");
   grRecoT_2roi_14TeV->GetYaxis()->SetTitleOffset(1.5);
   grRecoT_2roi_14TeV->GetXaxis()->SetTitle("P_{T #mu} Cut [GeV] SubLeading Muon");
   //gr_14TeV->SetMarkerStyle(21);
  // gr_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.5);ƒ
   grRecoT_2roi_14TeV->GetYaxis()->TAxis::SetRangeUser(0,0.25);
   grRecoT_2roi_14TeV->Draw("ACP");
   grT_2roi_14TeV->Draw("CP");
   grGlobalT_2roi_14TeV->Draw("CP");
   grPFT_2roi_14TeV->Draw("CP");
   grISOT_2roi_14TeV->Draw("CP");
   grRecoT_2roi_8TeV->Draw("CP");
   grT_2roi_8TeV->Draw("CP");
   grGlobalT_2roi_8TeV->Draw("CP");
   grPFT_2roi_8TeV->Draw("CP");
   grISOT_2roi_8TeV->Draw("CP");

TLegend* legend = new TLegend( 0.67, 0.6, 0.87, 0.92);
legend->SetTextSize(0.025);
legend->SetFillColor(0);
legend->AddEntry(grT_2roi_14TeV, "Muon from Tau 14TeV_PU50bx25","p");
legend->AddEntry(grRecoT_2roi_14TeV, "Reco SL Muon 14TeV_PU50bx25","p");
legend->AddEntry(grGlobalT_2roi_14TeV, "Global SL Muon 14TeV_PU50bx25","p");
legend->AddEntry(grPFT_2roi_14TeV, "PF SL Muon 14TeV_PU50bx25","p");
legend->AddEntry(grISOT_2roi_14TeV, "ISO SL Muon 14TeV_PU50bx25","p");
//legend->AddEntry(grISO_14TeV, "ISO 14 TeV","p");

legend->Draw("same");
legendT8_2roi->Draw("same");
  ll->Draw("same");


/////// eff function
/*
/////////1 muone CSC variabili e GEM fissa 97.5%
TF1 *f_eff3csc = new TF1("f_eff3csc","x^3 ",0.5,1);
TF1 *f_eff3csc1GEM = new TF1("f_eff3csc1GEM","(x*0.975+x*(1-0.975)+0.975*(1-x))*(x^2) ",0.5,1);
TF1 *f_eff3csc2GEM = new TF1("f_eff3csc2GEM","(x*0.975+x*(1-0.975)+0.975*(1-x))*((x*0.975+x*(1-0.975)+0.975*(1-x))*x)",0.5,1);

TF1 *f_eff4csc = new TF1("f_eff4csc","x^4 + 3*((x^3)*(1-x))",0.5,1);
TF1 *f_eff4csc1GEM = new TF1("f_eff4csc1GEM","(x*0.975+x*(1-0.975)+0.975*(1-x))*(x^3 + 3*(x^2)*(1-x)) ",0.5,1);
TF1 *f_eff4csc2GEM = new TF1("f_eff4csc2GEM","(x*0.975+x*(1-0.975)+0.975*(1-x))*( (x*0.975+x*(1-0.975)+0.975*(1-x))*(x^2+2*x*(1-
x)) + (1-x)*(1-0.975)*x^2) ",0.5,1);
*/

/*
/////////1 muone CSC e GEM variabili tra 50% e 97.5% allo stesso modo
TF1 *f_eff3csc = new TF1("f_eff3csc","x^3 ",0.5,1);
TF1 *f_eff3csc1GEM = new TF1("f_eff3csc1GEM","(x^2+2*x*(1-x))*(x^2) ",0.5,1);
TF1 *f_eff3csc2GEM = new TF1("f_eff3csc2GEM","(x^2+2*x*(1-x))*((x^2+2*x*(1-x))*x)",0.5,1);

TF1 *f_eff4csc = new TF1("f_eff4csc","x^4 + 3*((x^3)*(1-x))",0.5,1);
TF1 *f_eff4csc1GEM = new TF1("f_eff4csc1GEM","(x^2+2*x*(1-x))*(x^3 + 3*(x^2)*(1-x)) ",0.5,1);
TF1 *f_eff4csc2GEM = new TF1("f_eff4csc2GEM","(x^2+2*x*(1-x))*((x^2+2*x*(1-x))*(x^2+2*x*(1-x))+((1-x)^2)*x^2) ",0.5,1);
*/

TF1 *f_eff3csc = new TF1("f_eff3csc","x^3 +x^6   ",0.5,1);
//TF1 *f_eff3csc1GEM = new TF1("f_eff3csc1GEM","(x^2+2*x*(1-x))*(x^2) ",0.5,1);
TF1 *f_eff3csc1GEM = new TF1("f_eff3csc1GEM","( (x*0.975+x*(1-0.975)+0.975*(1-x))*(x^2) )^2 + ( (x*0.975+x*(1-0.975)+0.975*(1-x))*(x^2) )*(1-( (x*0.975+x*(1-0.975)+0.975*(1-x))*(x^2) ))",0.5,1);
//TF1 *f_eff3csc2GEM = new TF1("f_eff3csc2GEM","(x^2+2*x*(1-x))*((x^2+2*x*(1-x))*x)",0.5,1);
TF1 *f_eff3csc2GEM = new TF1("f_eff3csc2GEM","( (x*0.975+x*(1-0.975)+0.975*(1-x))*((x*0.975+x*(1-0.975)+0.975*(1-x))*x) )^2",0.5,1);

TF1 *f_eff4csc = new TF1("f_eff4csc","( x^4 + 3*((x^3)*(1-x)) )^2",0.5,1);
//TF1 *f_eff4csc1GEM = new TF1("f_eff4csc1GEM","(x^2+2*x*(1-x))*(x^3 + 3*(x^2)*(1-x)) ",0.5,1);
TF1 *f_eff4csc1GEM = new TF1("f_eff4csc1GEM","( (x*0.975+x*(1-0.975)+0.975*(1-x))*(x^3 + 3*(x^2)*(1-x)) )^2 ",0.5,1);
//TF1 *f_eff4csc2GEM = new TF1("f_eff4csc2GEM","(x^2+2*x*(1-x))*((x^2+2*x*(1-x))*(x^2+2*x*(1-x))+((1-x)^2)*x^2) ",0.5,1);
TF1 *f_eff4csc2GEM = new TF1("f_eff4csc2GEM","( (x*0.975+x*(1-0.975)+0.975*(1-x))*( (x*0.975+x*(1-0.975)+0.975*(1-x))*(x^2+2*x*(1-x)) + (1-x)*(1-0.975)*x^2) )^2 ",0.5,1);

TF1 *f_sensL = new TF1("f_sensL"," 2.59/TMath::Sqrt(2.59+52.29)*TMath::Sqrt(x/19.5)  ",19.5,10000);
TCanvas *CanvFunction = new TCanvas("CanvFunction"," ");
f_sensL->SetLineWidth(3); 
f_sensL->SetLineColor(2);
f_sensL->GetYaxis()->SetTitle("Expected Significance");
f_sensL->GetXaxis()->SetTitle("Integrated Luminosity [fb^{-1}]");
//f_sensL->GetXaxis()->SetTextSize(0.03);
//f_sensL->GetXaxis()->SetTextFont(42);
gPad->SetLogx();
f_sensL->Draw();
  ll->Draw("same");


/*
Double_t eff_X=0.1;
Double_t ar=0.5;

std::cout<<"3CSC+1GEM "<<std::endl;
while(ar<1.01){
eff_X= (TMath::Power(ar,2)+2*ar*(1-ar))*(TMath::Power(ar,2));
std::cout<<"eff a "<<ar<<" : "<< eff_X<<std::endl;
ar+=0.05;
}
std::cout<<"3CSC+2GEM "<<std::endl;
ar=0.5;
while(ar<1.01){
eff_X= (TMath::Power(ar,2)+2*ar*(1-ar))*((TMath::Power(ar,2)+2*ar*(1-ar))*ar);
std::cout<<"eff a "<<ar<<" : "<< eff_X<<std::endl;
ar+=0.05;
}

std::cout<<"4CSC+1GEM "<<std::endl;
ar=0.5;
while(ar<1.01){
eff_X= (TMath::Power(ar,2)+2*ar*(1-ar))*(TMath::Power(ar,3)+3*(TMath::Power(ar,2))*(1-ar));
std::cout<<"eff a "<<ar<<" : "<< eff_X<<std::endl;
ar+=0.05;
}
std::cout<<"4CSC+2GEM "<<std::endl;
ar=0.5;
while(ar<1.01){
eff_X= (TMath::Power(ar,2)+2*ar*(1-ar))*((TMath::Power(ar,2)+2*ar*(1-ar))*(TMath::Power(ar,2)+2*ar*(1-ar))+ TMath::Power(ar,2)*TMath::Power(1-ar,2));
std::cout<<"eff a "<<ar<<" : "<< eff_X<<std::endl;
ar+=0.05;
}
*/

/*
TCanvas *CanvFunction = new TCanvas("CanvFunction"," ");
CanvFunction->Divide(2,1);
CanvFunction->cd(1);
f_eff4csc->SetLineWidth(3); 
f_eff4csc->SetLineColor(1);
f_eff4csc->GetYaxis()->SetTitle("#mu eff");
f_eff4csc->GetXaxis()->SetTitle("local trigger eff");
f_eff4csc->Draw();

f_eff4csc1GEM->SetLineWidth(3);
f_eff4csc1GEM->SetLineColor(2);
f_eff4csc1GEM->Draw("same");

f_eff4csc2GEM->SetLineWidth(3);
f_eff4csc2GEM->SetLineColor(3);
f_eff4csc2GEM->Draw("same");


TLegend* legendEff4csc = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendEff4csc->SetTextSize(0.025);
legendEff4csc->SetFillColor(0);
legendEff4csc->AddEntry(f_eff4csc, "4CSC","l");
legendEff4csc->AddEntry(f_eff4csc1GEM, "4CSC + 1GEM","l");
legendEff4csc->AddEntry(f_eff4csc2GEM, "4CSC + 2GEM","l");
legendEff4csc->Draw("same");


CanvFunction->cd(2);
f_eff3csc->SetLineWidth(3);
f_eff3csc->SetLineColor(1);
f_eff3csc->GetYaxis()->SetTitle("#mu eff");
f_eff3csc->GetXaxis()->SetTitle("local trigger eff");
f_eff3csc->Draw();


f_eff3csc1GEM->SetLineWidth(3);
f_eff3csc1GEM->SetLineColor(2);
//f_eff3csc1GEM->Draw("same");

f_eff3csc2GEM->SetLineWidth(3);
f_eff3csc2GEM->SetLineColor(3);
//f_eff3csc2GEM->Draw("same");


TLegend* legendEff3csc = new TLegend( 0.67, 0.6, 0.87, 0.92);
legendEff3csc->SetTextSize(0.025);
legendEff3csc->SetFillColor(0);
legendEff3csc->AddEntry(f_eff3csc, "3CSC","l");
legendEff3csc->AddEntry(f_eff3csc1GEM, "3CSC + 1GEM","l");
legendEff3csc->AddEntry(f_eff3csc2GEM, "3CSC + 2GEM","l");
legendEff3csc->Draw("same");


*/

/*
TLegend* legend = new TLegend( 0.77, 0.6, 0.87, 0.92);
//TLegend* legend = new TLegend( 0.65, 0.5, 0.87, 0.92);
//TLegend *legend = new TLegend(.77,.60,.98,.98);
legend->SetTextSize(0.035);
legend->SetFillColor(0);
//legend->AddEntry(WH115, "WH ","f");
//legend->AddEntry(ZH115, "ZH ","f");
//legend->AddEntry(ttH115, "ttH ","f");
//legend->AddEntry(DYee, "DYee","f");
legend->AddEntry(DiBoson, "WZ+ZZ","f");
legend->AddEntry(Fake, "Fake","f");
//legend->AddEntry(DYtt, "DYtt","f");
//legend->AddEntry(DYmumuee, "DYmumu+ee","f");
//legend->AddEntry(QCDmu, "QCD fake","f");
legend->AddEntry(D, "Data","p");
Canv->cd();
legend->Draw("same");

TString lumist="4.9 fb^{-1}";
  TPaveText *ll = new TPaveText(0.15, 0.95, 0.95, 0.99, "NDC");
  ll->SetTextSize(0.03);
  ll->SetTextFont(42);
  ll->SetFillColor(0);
  ll->SetBorderSize(0);
  ll->SetMargin(0.01);
  ll->SetTextAlign(12); // align left
  TString text = "CMS Preliminary";
  ll->AddText(0.01,0.5,text);
  text = "#sqrt{s} = 7 TeV  L = ";
  text = text + lumist;
  //  ll->SetTextAlign(32); // align right
  ll->AddText(0.65, 0.6, text);
  ll->Draw("same");

  //Canv->SaveAs("./PtTau1.pdf");

TCanvas *Canv1 = new TCanvas("Canv1"," ");
Canv1->cd();
//D->Draw("P0E1");
hMC->Draw("HISTOE1");
hMCfake->Draw("sameHISTOE1");
//MC_fake->Draw("sameHISTOE1");
hMC->Draw("sameHISTOE1");
ll->Draw("same");

TLegend* legend2 = new TLegend( 0.77, 0.6, 0.87, 0.92);
legend2->SetTextSize(0.035);
legend2->SetFillColor(0);
legend2->AddEntry(WW, "WW mc ","f");
legend2->AddEntry(W2J, "W2Jets mc ","f");
legend2->AddEntry(W1J, "W1Jets mc ","f");
legend2->AddEntry(TTJ, "TTJets mc ","f");
legend2->AddEntry(DYJ, "DYJets mc ","f");
legend2->AddEntry(WWfake, "WW fake ","f");
legend2->AddEntry(W2Jfake, "W2Jets fake ","f");
legend2->AddEntry(W1Jfake, "W1Jets fake ","f");
legend2->AddEntry(TTJfake, "TTJets fake ","f");
legend2->AddEntry(DYJfake, "DYJets fake ","f");
legend2->AddEntry(DYJfake, "MC fake ","p");
legend2->AddEntry(DYJ, "MC ","p");
legend2->Draw("same");
*/
}


