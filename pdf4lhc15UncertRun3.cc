#include <Riostream.h>
#include <iostream>
#include <vector>
#include <string>
#include <TMath.h>
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "./ProdNpKNU/src/NpKNU.hh"

using namespace std;
void Sort_ascend(double *weight, int size)
{
   int i=0, j=0;
   double temp=0.0;

   for(i=0; i<size-1; i++){
       for(j=i+1; j<size; j++){
          if(weight[i]>weight[j])
            {
               temp = weight[i];
               weight[i]=weight[j];
               weight[j]=temp;
            }
        }
   }         
}
double NNPDF31(double *weight, int m);            //double AlphaS(double *weight, int upper, int lower); //CMC  
double PDF4LHC15_mc_PDF(double *weight, int m);   
double PDF4LHC15_mc_AlphaS(double *weight, int upper, int lower, int m); //CMC  


int main(int argc, char** argv) {
   int MassIndex = 0;
   MassIndex = atoi(argv[1]); cout << MassIndex ;
   MassIndex = (MassIndex/1000) - 1 ; cout << "GeV Mass Index " << MassIndex << endl;
   TChain* inChain = new TChain("tree");
   inChain->Add(argv[2]);
   //Define TClonesArray
   TClonesArray* evtTCA        = new TClonesArray("npknu::Evt")        ;  inChain->SetBranchAddress("evt"        , &evtTCA         );
   //TClonesArray* electronTCA   = new TClonesArray("npknu::Electron")   ;  inChain->SetBranchAddress("electron"   , &electronTCA    );
   //TClonesArray* muonTCA       = new TClonesArray("npknu::Muon")       ;  inChain->SetBranchAddress("muon"       , &muonTCA        );
   //TClonesArray* metTCA        = new TClonesArray("npknu::MET")        ;  inChain->SetBranchAddress("met"        , &metTCA         );
// //TClonesArray* photonTCA     = new TClonesArray("npknu::Photon")     ;  inChain->SetBranchAddress("photon"     , &photonTCA      );
   //TClonesArray* pileupTCA     = new TClonesArray("npknu::Trigger")    ;  inChain->SetBranchAddress("trigger"    , &pileupTCA      );
   //TClonesArray* triggerTCA    = new TClonesArray("npknu::Pileup")     ;  inChain->SetBranchAddress("pileup"     , &triggerTCA     );
   //TClonesArray* vertexTCA     = new TClonesArray("npknu::Vertex")     ;  inChain->SetBranchAddress("vertex"     , &vertexTCA      );
   //TClonesArray* genParticleTCA= new TClonesArray("npknu::GenParticle");  inChain->SetBranchAddress("genParticle", &genParticleTCA );
   TClonesArray* genInfoTCA    = new TClonesArray("npknu::GenInfo")    ;  inChain->SetBranchAddress("genInfo"    , &genInfoTCA     );
   TClonesArray* xfxTCA        = new TClonesArray("npknu::PDFxfx")     ;  inChain->SetBranchAddress("xfx"        , &xfxTCA         );
 
  int TotalNumEvents = (int)inChain->GetEntries();
        cout << "TotalNumEvents " << TotalNumEvents << endl;

   const int NumPDFs = 204;
   double sumWeight[NumPDFs];
   cout << "NumPDFs " << NumPDFs << endl;
   for(int i=0; i<NumPDFs; i++) sumWeight[i] = 0.0;
   for(int eventLoop=0; eventLoop<TotalNumEvents; eventLoop++) 
     {
      inChain->GetEntry(eventLoop);
      npknu::PDFxfx* xfxPtr = (npknu::PDFxfx*)xfxTCA->At(0);
      for(int pdfLoop=0; pdfLoop<NumPDFs; pdfLoop++) 
         {
         sumWeight[pdfLoop] += xfxPtr->Weight(pdfLoop);
         cout << "=> sumweight(pdf:"<<pdfLoop<<")="<<xfxPtr->Weight(pdfLoop)<< endl;
         }
     }//cout <<"=> End eventLoop"<<endl;

    const int Num_nnpdf31 =100;
    const int Num_mc =100;

    sumWeight[0]   = sumWeight[0] / (double)TotalNumEvents;  //NNPDF31_nnlo_hessian_pdfas 0-100
    for(int q=1; q<101; q++){
       sumWeight[q] = sumWeight[q] / (double)TotalNumEvents; 
       Sort_ascend(sumWeight, Num_nnpdf31);
      }
    sumWeight[101] = sumWeight[101] / (double)TotalNumEvents;//PDF4LHC15_nnlo_mc_pdfas (0.118) 101-201
    for(int i=102; i<202; i++){ 
	sumWeight[i] = sumWeight[i] / (double)TotalNumEvents; 
        Sort_ascend(sumWeight, Num_mc);//Reordering in ascending
       }
    sumWeight[202] = sumWeight[202] / (double)TotalNumEvents;//PDF4LHC15_nnlo_mc_pdfas (0.1165) 202
    sumWeight[203] = sumWeight[203] / (double)TotalNumEvents;//PDF4LHC15_nnlo_mc_pdfas (0.1195) 203

    cout << " Total PDF Weight " << endl ;
    for(int w=0; w <NumPDFs; w++) {
    if(w == 0) cout << "--NNPDF31_hessian set--" << endl;
    cout << w << "	(" << sumWeight[w] << ") " << endl; 
    if(w == 100) cout << "--PDF4LHC15_nnlo_mc  set--" << endl;
    if(w == 201 ) cout << "--AlphaS low(0.1165) up(0.1195)--" << endl;
    if(w == 83 || w == 15 || w == 184 || w == 116 ) cout << "vv nnlo_mc set 68% CL vv" << endl; 
    }
    cout << " ============================================ " << endl;

   PDF4LHC15_mc_PDF(sumWeight, MassIndex);  
   PDF4LHC15_mc_AlphaS(sumWeight, 203, 202, MassIndex); //CMC 0.1195, 0.1165 i
   
   return 0;
}

double NNPDF31(double *weight , int m){
   double Bestfit =0.0;  double Mean_std = 0.0;  double Mean_order = 0.0;
   double Weight84th = 0.0 ; double Weight16th = 0.0 ;
   double Sum  = 0.0;   double Sum2=0.0;
   
   Bestfit = weight[0];                         cout << "@   Best-Fit[" << m << "] = " << Bestfit    << "  ; " <<endl;
   Weight84th = weight[84];     Weight16th = weight[16];
   Mean_order = (Weight84th + Weight16th)/2.0 ; cout << "@ Reordering[" << m << "] = " << Mean_order << "  ; " <<endl;
   double PDF_ord = (Weight84th - Weight16th)/2.0 ; //Re-ordering

   std::vector<int> index; for(int i=0; i<100; i++) index.push_back(i+1);
   std::vector<double> weightVec;
   for(std::vector<int>::iterator it=index.begin(); it!=index.end(); it++) { weightVec.push_back(weight[*it]); }
   for(std::vector<double>::iterator it=weightVec.begin(); it!=weightVec.end(); it++)  Sum += *it;
   Mean_std = (Sum) / weightVec.size() ;     cout << "@ mc_STDMean[" << m << "] =  " << Mean_std << "  ; " <<endl;
   for(std::vector<double>::iterator it=weightVec.begin(); it!=weightVec.end(); it++)  Sum2 += ((*it - Mean_std)*(*it - Mean_std));
   double PDF_std = TMath::Sqrt((Sum2)/99.0); //Standard deviation
   cout << "@NNPDF31_ord[" << m << "] = " << PDF_ord << "  ; //Re-ordering " << endl;
   cout << "@NNPDF31_std[" << m << "] = " << PDF_std << "  ; //Standard deviation " << endl;
   return 0.0;
}

/////double AlphaS(double *weight, int upper, int lower ){
/////   double C = 6.0 / 5.0 ;//0.0012/0.001 delta alphas=0.0012 fixing
/////   double AlphaS = C * (weight[upper] - weight[lower])/2.0 ;
/////   cout << "@     AlphaS[] = " << AlphaS << "  ; " << endl; 
/////   return 0.0;
/////}
/////

double PDF4LHC15_mc_PDF(double *weight , int m){
   double Bestfit =0.0;  double Mean_std = 0.0;  double Mean_order = 0.0;
   double Weight84th = 0.0 ; double Weight16th = 0.0 ;
   double Sum  = 0.0;   double Sum2=0.0;
   
   Bestfit = weight[101];                         cout << "@   mcBest_Fit[" << m << "] = " << Bestfit    << "  ; " <<endl;
   Weight84th = weight[185];     Weight16th = weight[117];
   Mean_order = (Weight84th + Weight16th)/2.0 ; cout << "@   Reordering[" << m << "] = " << Mean_order << "  ; " <<endl;
   double PDF_ord = (Weight84th - Weight16th)/2.0 ; //Re-ordering

   std::vector<int> index; for(int i=0; i<100; i++) index.push_back(i+1);
   std::vector<double> weightVec_mc;
   for(std::vector<int>::iterator it=index.begin(); it!=index.end(); it++) { weightVec_mc.push_back(weight[*it+101]); }//PDF4LHC mc index=101
   for(std::vector<double>::iterator it=weightVec_mc.begin(); it!=weightVec_mc.end(); it++)  Sum += *it;
   Mean_std = (Sum) / weightVec_mc.size() ;     cout << "@   mc_STDMean[" << m << "] =  " << Mean_std << "  ; " <<endl;
   for(std::vector<double>::iterator it=weightVec_mc.begin(); it!=weightVec_mc.end(); it++)  Sum2 += ((*it - Mean_std)*(*it - Mean_std));
   double PDF_std = TMath::Sqrt((Sum2)/99.0); //Standard deviation
   cout << "@   PDF4LHC15_mc_ord[" << m << "] = " << PDF_ord << "  ; //Re-ordering " << endl;
   cout << "@   PDF4LHC15_mc_std[" << m << "] = " << PDF_std << "  ; //Standard deviation " << endl;
   return 0.0;
}

 

double PDF4LHC15_mc_AlphaS(double *weight, int upper, int lower , int m){
   double AlphaS = (weight[upper] - weight[lower])/2.0 ;
   cout << "@   AlphaS_mc[" << m << "] = " << AlphaS << "  ; " << endl; 
   return 0.0;
}
