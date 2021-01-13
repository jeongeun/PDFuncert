#include <iostream>
#include <vector>
#include "LHAPDF/LHAPDF.h"
#include "./ProdNpKNU/src/NpKNU.hh"
#include <math.h>
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TClonesArray.h"

using namespace std;
using namespace LHAPDF;
std::vector<std::pair<std::string, int> > pdfInfoVec; //pdfsetname, number of subset
std::vector<npknu::PDFxfx> pdfXFXvec;

void GetXFX(int nset, std::string pdfsetname, int subset); 

int main(int argc, char** argv){

   TChain* inChain = new TChain("MakeNpKNU/NpKNU");
   //add ntuple to inChain   
   inChain->Add(argv[1]);
   //Creating TClonesArray Objects (same as ntuple format with npknu class)   
   TClonesArray* evtTCA     = new TClonesArray("npknu::Evt")    ; inChain->SetBranchAddress("evt"     , &evtTCA    );
   TClonesArray* electronTCA   = new TClonesArray("npknu::Electron")   ;  inChain->SetBranchAddress("electron"   , &electronTCA    );
   TClonesArray* muonTCA       = new TClonesArray("npknu::Muon")       ; inChain->SetBranchAddress("muon"       , &muonTCA        );
   TClonesArray* metTCA        = new TClonesArray("npknu::MET")        ;  inChain->SetBranchAddress("met"        , &metTCA         );
   TClonesArray* pileupTCA     = new TClonesArray("npknu::Trigger")    ;  inChain->SetBranchAddress("trigger"    , &pileupTCA      );
   TClonesArray* triggerTCA    = new TClonesArray("npknu::Pileup")     ;  inChain->SetBranchAddress("pileup"     , &triggerTCA     );
   TClonesArray* vertexTCA     = new TClonesArray("npknu::Vertex")     ;  inChain->SetBranchAddress("vertex"     , &vertexTCA      );
   TClonesArray* genInfoTCA    = new TClonesArray("npknu::GenInfo")    ;  inChain->SetBranchAddress("genInfo"    , &genInfoTCA     );
   TClonesArray* genParticleTCA= new TClonesArray("npknu::GenParticle");  inChain->SetBranchAddress("genParticle", &genParticleTCA );
   //recreate ntuple that pdf values were included
   TString outFileName(basename(argv[1]));
   outFileName.ReplaceAll(".root","_addpdf.root"); 
   TFile* outFile = new TFile(outFileName,"recreate");
   TTree* outTree = new TTree("tree","addPDF");

   outTree->Branch("evt"        , &evtTCA         );
   outTree->Branch("electron"   , &electronTCA    );
   outTree->Branch("muon"       , &muonTCA        );
   outTree->Branch("met"        , &metTCA         );
   outTree->Branch("trigger"    , &pileupTCA      );
   outTree->Branch("pileup"     , &triggerTCA     );
   outTree->Branch("vertex"     , &vertexTCA      );
   outTree->Branch("genParticle", &genParticleTCA );
   outTree->Branch("genInfo"    , &genInfoTCA     );

//   int NumEvents = (int)inChain->GetEntries();
  int NumEvents = 3; 
  for(int eventLoop=0; eventLoop<NumEvents; eventLoop++) {
          inChain->GetEntry(eventLoop);
          npknu::GenInfo* genInfoPtr = (npknu::GenInfo*)genInfoTCA->At(0);
          npknu::PDFxfx xpdf(*genInfoPtr);
          pdfXFXvec.push_back(xpdf);
          outTree->Fill();
    }
    cout << "### NumEvents " << NumEvents << " " << pdfXFXvec.size() << endl;
	//setPaths("/cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/lhapdf/6.2.1-gnimlf2/share/LHAPDF");
        LHAPDF::setPDFPath("/x3/cms/jelee/pdftutorial/share/LHAPDF");

	//for(int member=0; member<53; member++) LHAPDF::mkPDF("CT10nlo", member);
        //for(int subset=0; subset<1   ; subset++)  GetXFX(1, "cteq6ll"  , subset );//Reference pdfset
        for(int subset=0; subset<101; subset++) GetXFX(1, "NNPDF31_nnlo_as_0118_nf_4", subset); //best-fit aS 0.118
        for(int subset=0; subset<103; subset++) GetXFX(2, "PDF4LHC15_nnlo_mc_pdfas"  , subset); //best 0.118,101=0.1165,102=0.1195
   int pdfIndex = 0;
   for(std::vector<std::pair<std::string, int> >::iterator it=pdfInfoVec.begin(); it!=pdfInfoVec.end(); it++) {
     cout <<"### PDFsetIndex " << pdfIndex++ << " " << it->first << " " << it->second << endl;
   }

   TClonesArray* xfxTCA = new TClonesArray("npknu::PDFxfx");
   TBranch* xfxBr = outTree->Branch("xfx",&xfxTCA);
   for(int i=0; i<outTree->GetEntries(); i++) {
           xfxTCA->Clear();
           npknu::PDFxfx xfxObj = pdfXFXvec.at(i);
           new ((*xfxTCA)[xfxTCA->GetEntries()]) npknu::PDFxfx(xfxObj);
           xfxBr->Fill();
    }

    outFile->Write();

return 0;
}

void GetXFX(int nset, std::string pdfsetname, int subset) {
   cout << "Extracting xfx for " << pdfsetname << " " << subset << endl;
   std::pair<std::string, int> pdfInfo(pdfsetname, subset);
   pdfInfoVec.push_back(pdfInfo);

   LHAPDF::setVerbosity(LHAPDF::SILENT);
   LHAPDF::PDF* pdf = LHAPDF::mkPDF(pdfsetname,subset);
     cout << "pdfXFXvec size = " << pdfXFXvec.size() << endl;
   for(std::vector<npknu::PDFxfx>::iterator it=pdfXFXvec.begin(); it!=pdfXFXvec.end(); it++) {
      std::pair<double, double> xfxPair;
      cout << "--------------------------------------------------" << endl;
      cout << "nset " << nset << " id1 " << it->pdg1 << " x1 " << it->x1 << " Q " << it->scalePDF << " xpdf1 " << it->xpdf1 << endl;
      cout << "nset " << nset << " id2 " << it->pdg2 << " x2 " << it->x2 << " Q " << it->scalePDF << " xpdf2 " << it->xpdf2 << endl;
      xfxPair.first  = pdf->xfxQ(it->pdg1, it->x1, it->scalePDF);
      xfxPair.second = pdf->xfxQ(it->pdg2, it->x2, it->scalePDF);
      cout << "### output ###" << endl;
      cout << "pdf " << pdfsetname << " " << subset << " xfx1 = " << xfxPair.first << endl;
      cout << "pdf " << pdfsetname << " " << subset << " xfx2 = " << xfxPair.second << endl;
      cout << "xfxVec size = " << it->xfxVec.size() << endl;
      cout << "--------------------------------------------------" << endl;
      it->xfxVec.push_back(std::make_pair(it->xfxVec.size(), xfxPair));
   }
}
 
