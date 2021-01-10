#include "NpKNU.hh"
#include <algorithm>

std::vector<std::pair<std::string, int> > errorMSGvec;

ClassImp(npknu::Evt)
ClassImp(npknu::GenInfo)
ClassImp(npknu::PDFxfx)
ClassImp(npknu::Cut)
ClassImp(npknu::P4)
ClassImp(npknu::GenParticle)
ClassImp(npknu::Photon)
ClassImp(npknu::Pileup)
ClassImp(npknu::Vertex)
ClassImp(npknu::Electron)
ClassImp(npknu::Trigger)
ClassImp(npknu::TriggerObject)
ClassImp(npknu::Muon)
ClassImp(npknu::MET)
ClassImp(npknu::Jet)
ClassImp(npknu::PUReweight)


namespace npknu { 

std::ostream& operator<<(std::ostream& os, const Evt& evt) {
   os << "Evt(Run,Lumi,Event): " << evt.run << " " << evt.lumi << " " << evt.event << " " << evt.isRealData ; 
	return os;
}
//std::ostream& operator<<(std::ostream& os, const Evt* evt) {
//   os << "Evt(Run,Lumi,Event): " << evt->run << " " << evt->lumi << " " << evt->event << " " << evt->isRealData ; 
//	return os;
//}

std::ostream& operator<<(std::ostream& os, const P4& obj) {
   os << "P4(pt,eta,phi,energy): " << obj.pt << " " << obj.eta << " " << obj.phi << " " << obj.energy ; 
	return os;
}
//std::ostream& operator<<(std::ostream& os, const P4* obj) {
//   os << "P4(pt,eta,phi,energy): " << obj->pt << " " << obj->eta << " " << obj->phi << " " << obj->energy ; 
//	return os;
//}


int CompareWild(const char *string, const char *wild) {
   const char *cp = NULL, *mp = NULL;
   while((*string) && (*wild != '*')) {
      if ((*wild != *string) && (*wild != '?')) { return 0; }
      wild++;
      string++;
   }
   while(*string) {
      if(*wild == '*') {
         if (!*++wild) {  return 1; }
         mp = wild;
         cp = string+1;
      } else if ((*wild == *string) || (*wild == '?')) {
         wild++;
         string++;
      } else {
         wild = mp;
         string = cp++;
      }
   }

   while(*wild == '*') { wild++; }
   return !*wild;
}

void RebinTH1F(TH1F* h1_in, TH1F* h1_out) {
        for(int i=0; i<h1_in->GetNbinsX(); i++) {
                for(int j=0; j<h1_out->GetNbinsX(); j++) {
                        double xMin = h1_out->GetBinCenter(j+1) - h1_out->GetBinWidth(j+1) / 2.0;
                        double xMax = h1_out->GetBinCenter(j+1) + h1_out->GetBinWidth(j+1) / 2.0;
                        if(h1_in->GetBinCenter(i+1) >= xMin && h1_in->GetBinCenter(i+1) < xMax) {
                                h1_out->SetBinContent(j+1, h1_out->GetBinContent(j+1) + h1_in->GetBinContent(i+1));
                        }
                }
        }
}


TString AddStringToFileName(TString _orig, TString _addString) {
	TString orig(_orig);
	TString addString(_addString);
	     if(orig.EndsWith(".pdf")) { addString += ".pdf"; orig.ReplaceAll(".pdf",""); }
	else if(orig.EndsWith(".gif")) { addString += ".gif"; orig.ReplaceAll(".gif",""); }
	else if(orig.EndsWith(".jpg")) { addString += ".jpg"; orig.ReplaceAll(".jpg",""); }
	else if(orig.EndsWith(".eps")) { addString += ".eps"; orig.ReplaceAll(".eps",""); }
	else { std::cout << "Error in npknu::AddStringToFileName: Not Found Filename extension in pdf/gif/jpg/eps Orig: " << orig << " addString: " << addString << std::endl; }
	return (orig + addString);
}

//////////////////////////////
//      Object ID 
//////////////////////////////
int GetElectronIdTCA(TClonesArray* inTCA, TClonesArray* outTCA, int idIndex, double minPt, double maxAEta, bool doMCTruth) {
	int num = 0;
	if(outTCA != NULL) outTCA->Clear();
	for(int i=0; i<inTCA->GetEntries(); i++) {
   	Electron* ptr = (Electron*)inTCA->At(i);
   	if( (! ptr->isGap()) and ptr->pt > minPt and std::abs(ptr->scEta()) < maxAEta) {
			if(doMCTruth and ptr->matchToTruth != 1) continue;
			     if(idIndex == 4 and ptr->isHEEP() )	{ num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Electron(*ptr); }
			else if(idIndex == 3 and ptr->isTight() )	{ num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Electron(*ptr); }
			else if(idIndex == 2 and ptr->isMedium())	{ num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Electron(*ptr); }
			else if(idIndex == 1 and ptr->isLoose() )	{ num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Electron(*ptr); }
			else if(idIndex == 0 and ptr->isVeto()  )	{ num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Electron(*ptr); }
		}
	}
	return num;
}

void PrintElectronTCA(TClonesArray* electronTCA) {
	for(int i=0; i<electronTCA->GetEntries(); i++) {
   	Electron* ptr = (Electron*)electronTCA->At(i);
   	std::cout << "ElectronIndex " << i << " ";
		ptr->PrintObj();  
	}
}

int GetPhotonIdTCA(TClonesArray* inTCA, TClonesArray* outTCA, int idIndex, double minPt, double maxAEta, bool doMCTruth) {
	int num=0;
	if(outTCA != NULL) outTCA->Clear();
	for(int i=0; i<inTCA->GetEntries(); i++) {
   	Photon* ptr = (Photon*)inTCA->At(i);
		if(doMCTruth and ptr->matchToTruth != 1) continue;
   	if(ptr->pt > minPt and ptr->scAEta() < maxAEta and ptr->passEleVeto) {
   		     if(idIndex == 2 and ptr->isTight()  ) { num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Photon(*ptr); }
   		else if(idIndex == 1 and ptr->isMedium() ) { num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Photon(*ptr); }
   		else if(idIndex == 0 and ptr->isLoose()  ) { num++; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Photon(*ptr); }
		}
	}
	return num;
}
int GetMuonCutTCA(TClonesArray* inTCA, TClonesArray* outTCA, double minPt, double minAEta, double maxAEta) {
	int num = 0;
	if(outTCA != NULL) outTCA->Clear();
	for(int i=0; i<inTCA->GetEntries(); i++) {
   	Muon* ptr = (Muon*)inTCA->At(i);
  	   if(ptr->pt > minPt and std::abs(ptr->eta)>=minAEta and std::abs(ptr->eta) < maxAEta) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
	}
	return num;
}


int GetMuonIdTCA(TClonesArray* inTCA, TClonesArray* outTCA, int idIndex, double minPt, double minAEta, double maxAEta) {
	int num = 0;
	if(outTCA != NULL) outTCA->Clear();
	for(int i=0; i<inTCA->GetEntries(); i++) {
   	Muon* ptr = (Muon*)inTCA->At(i);
		if(ptr->pt > minPt and std::abs(ptr->eta)>=minAEta and std::abs(ptr->eta) < maxAEta) {
	   	if((idIndex == 0) and (ptr->isLooseMuon    )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); } 
	   	if((idIndex == 1) and (ptr->isSoftMuonPV   )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
	   	if((idIndex == 2) and (ptr->isTightMuonPV  )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
	   	if((idIndex == 3) and (ptr->isHighPtMuonPV )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
	   	if((idIndex == 4) and (ptr->isSoftMuonGV   )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
	   	if((idIndex == 5) and (ptr->isTightMuonGV  )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
	   	if((idIndex == 6) and (ptr->isHighPtMuonGV )) { num++ ; if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Muon(*ptr); }
		}
	}
	return num;
}

// copied from NpKNU.cc.orig

/*
int ElectronIdTCA(TClonesArray* inTCA, TClonesArray* outTCA, int type) {
   std::vector<npknu::Electron> outVec;
   for(int i=0; i<inTCA->GetEntries(); i++) {
      npknu::Electron* ptr = (npknu::Electron*)inTCA->At(i);
      if(type == 1 && !ptr->vidIsPassVeto  ) continue   ;
      if(type == 2 && !ptr->vidIsPassLoose ) continue   ;
      if(type == 3 && !ptr->vidIsPassMedium) continue   ;
      if(type == 4 && !ptr->vidIsPassTight ) continue   ;
      if(type == 5 && !ptr->mvaWP80IdMap   ) continue   ;
      if(type == 6 && !ptr->mvaWP90IdMap   ) continue   ;
      outVec.push_back(*ptr);
   }
   outTCA->Clear("C");
   std::sort(outVec.begin(), outVec.end(), [ ](const npknu::Electron& lhs, const npknu::Electron& rhs) { return lhs.pt > rhs.pt ; });
   for(std::vector<npknu::Electron>::iterator it=outVec.begin(); it!=outVec.end(); it++) {
      new ((*outTCA)[(int)outTCA->GetEntries()]) npknu::Electron(*it);
   }
   outVec.clear();
        return (int)outTCA->GetEntries();
}

int PhotonIdTCA(TClonesArray* inTCA, TClonesArray* outTCA, int type) {
   std::vector<npknu::Photon> outVec;
   for(int i=0; i<inTCA->GetEntries(); i++) {
      npknu::Photon* ptr = (npknu::Photon*)inTCA->At(i);
                if(type == 1 && ptr->vidIsPassLoose ) { outVec.push_back(*ptr); }
                if(type == 2 && ptr->vidIsPassMedium) { outVec.push_back(*ptr); }
                if(type == 3 && ptr->vidIsPassTight ) { outVec.push_back(*ptr); }
                if(type == 4 && ptr->mva90Id        ) { outVec.push_back(*ptr); }
                if(type == 5 && ptr->mva80Id        ) { outVec.push_back(*ptr); }
        }
   outTCA->Clear("C");
   std::sort(outVec.begin(), outVec.end(), [ ](const npknu::Photon& lhs, const npknu::Photon& rhs) { return lhs.pt > rhs.pt ; });
   for(std::vector<npknu::Photon>::iterator it=outVec.begin(); it!=outVec.end(); it++) {
      new ((*outTCA)[(int)outTCA->GetEntries()]) npknu::Photon(*it);
   }
   outVec.clear();
        return outTCA->GetEntries();
}

int ElectronSelection(TClonesArray* inTCA, TClonesArray* outTCA, double pt1Cut, double pt2Cut, int type) {
   std::vector<npknu::Electron> outVec;
        double ptMin = std::min(pt1Cut, pt2Cut);
        double ptMax = std::max(pt1Cut, pt2Cut);
   int nPassHighPt = 0;
   for(int i=0; i<inTCA->GetEntries(); i++) {
      npknu::Electron* ptr = (npknu::Electron*)inTCA->At(i);
      if(ptr->isGap()) continue          ;
      if(ptr->scAEta() > 2.5 ) continue  ;
                if(ptr->pt < pt2Cut) continue;
      if(type == 1 && !ptr->vidIsPassVeto  ) continue   ;
      if(type == 2 && !ptr->vidIsPassLoose ) continue   ;
      if(type == 3 && !ptr->vidIsPassMedium) continue   ;
      if(type == 4 && !ptr->vidIsPassTight ) continue   ;
      if(type == 5 && !ptr->mvaWP80IdMap   ) continue   ;
      if(type == 6 && !ptr->mvaWP90IdMap   ) continue   ;
      if(ptr->pt > ptMin) { outVec.push_back(*ptr); }
      if(ptr->pt > ptMax) { nPassHighPt++ ; }
   }
        if(outTCA == NULL) {
                int numPassEle = outVec.size();
                outVec.clear();
                return numPassEle;
        }
   if(nPassHighPt == 0) outVec.clear();
   outTCA->Clear("C");
   std::sort(outVec.begin(), outVec.end(), [ ](const npknu::Electron& lhs, const npknu::Electron& rhs) { return lhs.pt > rhs.pt ; });
   for(std::vector<npknu::Electron>::iterator it=outVec.begin(); it!=outVec.end(); it++) {
      new ((*outTCA)[(int)outTCA->GetEntries()]) npknu::Electron(*it);
   }
   outVec.clear();
        return (int)outTCA->GetEntries();
}

int NumVetoEleSelection(TClonesArray* inTCA, TClonesArray* outTCA, double ptCut, npknu::Electron* ele1Ptr, npknu::Electron* ele2Ptr) {
   outTCA->Clear("C");
   int numMatch1= 0;
   int numMatch2= 0;
        int numVEle = 0;
   for(int i=0; i<inTCA->GetEntries(); i++) {
      npknu::Electron* ptr = (npknu::Electron*)inTCA->At(i);
                if(ele1Ptr->DeltaR(ptr) < 0.00001) { numMatch1++; continue; }
                if(ele2Ptr->DeltaR(ptr) < 0.00001) { numMatch2++; continue; }
      if(ptr->isGap()) continue          ;
      if(ptr->scAEta() > 2.5 ) continue  ;
      if(ptr->pt < ptCut) continue       ;
      if(ptr->vidIsPassLoose) {
                new ((*outTCA)[(int)outTCA->GetEntries()]) npknu::Electron(*ptr);
         numVEle++;
      }
   }
        if(numMatch1 != 1 || numMatch2 != 1) {
                cout << "### Error NumVetoEleSelection match1 " << numMatch1 << " match2 " << numMatch2 << endl;
        }
   return numVEle;
}
*/






///////////////////////////
//       Pre-Selection
///////////////////////////

bool GetElectronPreselection(TClonesArray* inTCA, double minPt,double minAEta, double maxAEta){
      //  if(outTCA != NULL) outTCA->Clear();
        for(int i=0; i<inTCA->GetEntries(); i++) {
        Electron* ptr = (Electron*)inTCA->At(i);
           if(ptr->pt > minPt and std::abs(ptr->eta)>=minAEta and std::abs(ptr->eta) < maxAEta) {
             return true;
           }
        }
      return false;
}


bool GetMuonPreselection(TClonesArray* inTCA, double minPt,double minAEta, double maxAEta){
      //  if(outTCA != NULL) outTCA->Clear();
        for(int i=0; i<inTCA->GetEntries(); i++) {
        Muon* ptr = (Muon*)inTCA->At(i);
           if(ptr->pt > minPt and std::abs(ptr->eta)>=minAEta and std::abs(ptr->eta) < maxAEta) {
             return true;
           }
        }
      return false;
}

bool GetMuonVeto2nd(TClonesArray* inTCA, double minPt){
  //      if(outTCA != NULL) outTCA->Clear();
        if (inTCA->GetEntries() == 1 ) {return false;}
        if (inTCA->GetEntries() > 1 ) {
           for(int i=1; i<inTCA->GetEntries(); i++) {
           Muon* ptr = (Muon*)inTCA->At(i);
              if(ptr->pt > minPt) {                                                              
                return true;
              }
           }
        }
      return false;
}

//////////////////////////////
//      HLT Trigger 
//////////////////////////////

int GetPassTriggerTCA(TClonesArray* triggerTCA, TClonesArray* outTCA) {
	int num=0;
	if(outTCA != NULL) outTCA->Clear();
   for(int i=0; i<triggerTCA->GetEntries(); i++) {
   	Trigger* ptr = (Trigger*)triggerTCA->At(i);
     	if(ptr->Pass()) {
			num++;
			if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Trigger(*ptr);
		}
	}
	return num;
}


int GetPassTriggerTCA(TClonesArray* triggerTCA, TClonesArray* outTCA, std::string name) {
	int num=0;
	if(outTCA!=NULL) outTCA->Clear();
	//std::cout << "Debug " << name <<  " " << triggerTCA->GetEntries() << std::endl;
   for(int i=0; i<triggerTCA->GetEntries(); i++) {
   	Trigger* ptr = (Trigger*)triggerTCA->At(i);
     	if(ptr->Pass(name)) {
			num++;
			if(outTCA!=NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Trigger(*ptr);
		}
	}
	return num;
}

int GetPassTriggerTCA(TClonesArray* triggerTCA, TClonesArray* outTCA, std::vector<std::string> nameVec) {
	int num=0;
	if(outTCA!=NULL) outTCA->Clear();
	//std::cout << "Debug " << name <<  " " << triggerTCA->GetEntries() << std::endl;
   for(int i=0; i<triggerTCA->GetEntries(); i++) {
   	Trigger* ptr = (Trigger*)triggerTCA->At(i);
     	if(ptr->Pass(nameVec)) {
			num++;
			new ((*outTCA)[(int)outTCA->GetEntries()]) Trigger(*ptr);
		}
	}
	return num;
}

int GetPassTriggerObjTCA(TClonesArray* triggerObjectTCA, TClonesArray* outTCA, std::string name) {
	int num=0;
	if(outTCA!=NULL) outTCA->Clear();
	for(int i=0; i<triggerObjectTCA->GetEntries(); i++) {
		TriggerObject* objPtr = (TriggerObject*) triggerObjectTCA->At(i);
		objPtr->PrintObj();
		if(objPtr->hasPATH(name)) {
			num++;
			if(outTCA!=NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) TriggerObject(*objPtr);
		}
	}
	return num;
}


bool isPassTriggerTCA(TClonesArray* triggerTCA, TClonesArray* outTCA, std::vector<std::string> nameVec) {
	if(outTCA!=NULL) outTCA->Clear();
	//std::cout << "Debug " << name <<  " " << triggerTCA->GetEntries() << std::endl;
   for(int i=0; i<triggerTCA->GetEntries(); i++) {
   	Trigger* ptr = (Trigger*)triggerTCA->At(i);
     	if(ptr->Pass(nameVec)) {
			new ((*outTCA)[(int)outTCA->GetEntries()]) Trigger(*ptr);
			return true;
		}
	}
	return false;
}

bool isPassTriggerObjTCA(TClonesArray* triggerObjectTCA, TClonesArray* outTCA, std::string name) {
	if(outTCA!=NULL) outTCA->Clear();
	for(int i=0; i<triggerObjectTCA->GetEntries(); i++) {
		TriggerObject* objPtr = (TriggerObject*) triggerObjectTCA->At(i);
		objPtr->PrintObj();
		if(objPtr->hasPATH(name)) {
			if(outTCA!=NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) TriggerObject(*objPtr);
			return true;
		}
	}
	return false;
}

///////////////////////
//      Vertex
///////////////////////
int GetGoodVertex(TClonesArray* inTCA, TClonesArray* outTCA) {
	if(outTCA) outTCA->Clear();
	int numGV = 0;
	for(int i=0; i<inTCA->GetEntries(); i++) {
		Vertex* ptr = (Vertex*) inTCA->At(i);
		if(ptr->isGoodVertex()) {
			numGV++;
			if(outTCA) new ((*outTCA)[(int)outTCA->GetEntries()]) Vertex(*ptr);
		}
	}
	return numGV;
}

///////////////////////////
//       Pileup
///////////////////////////
double GetPileupTrue(TClonesArray* inTCA) {
   for(int i=0; i<inTCA->GetEntries(); i++) {
      Pileup* ptr = (Pileup*)inTCA->At(i);
      if(ptr->BunchCrossing == 0) return ptr->TrueNumInteractions;
   }
   std::cout << "### Error Not Found pileup->BunchCrossing == 0; return -999" << std::endl;
   return -999.0;
}


int GetPileupPU(TClonesArray* inTCA) {
   for(int i=0; i<inTCA->GetEntries(); i++) {
      Pileup* ptr = (Pileup*)inTCA->At(i);
      if(ptr->BunchCrossing == 0) return ptr->PU_NumInteractions;
   }
   //std::cout << "### Error Not Found pileup->BunchCrossing == 0; return -999" << std::endl;
   return -999;
}



int GetElectronMVATCA(TClonesArray* inTCA, TClonesArray* outTCA, unsigned int idBit, double minPt, double maxAEta, bool doMCTruth) {
	int num = 0;
	if(outTCA != NULL) outTCA->Clear();
	for(int i=0; i<inTCA->GetEntries(); i++) {
   	Electron* ptr = (Electron*)inTCA->At(i);
   	if( (! ptr->isGap()) and ptr->pt > minPt and std::abs(ptr->scEta()) < maxAEta) {
			if(doMCTruth and ptr->matchToTruth != 1) continue;
			bool isFill=false;
			if(((idBit & 1) == 1) and ptr->mvaIsPassTight)	isFill = true;
			if(((idBit & 2) == 2) and ptr->mvaIsPassMedium)	isFill = true;
			if(isFill) {
				num++;
				if(outTCA != NULL) new ((*outTCA)[(int)outTCA->GetEntries()]) Electron(*ptr);
			}
		}
	}
	return num;
}


int NumElectronMVATCA(TClonesArray* inTCA, unsigned int idBit, double minPt, double maxAEta, bool doMCTruth) {
	return GetElectronMVATCA(inTCA, NULL, idBit, minPt, maxAEta, doMCTruth);
}

int NumElectronIdTCA(TClonesArray* inTCA, int idIndex, double minPt, double maxAEta, bool doMCTruth) { 
	return GetElectronIdTCA(inTCA, NULL, idIndex, minPt, maxAEta, doMCTruth); 
}
int NumPhotonIdTCA(TClonesArray* inTCA, int idIndex, double minPt, double maxAEta, bool doMCTruth) { 
	return GetPhotonIdTCA(inTCA, NULL, idIndex, minPt, maxAEta, doMCTruth);
}
int NumMuonIdTCA(TClonesArray* inTCA, int idIndex, double minPt, double maxAEta) {
	return GetMuonIdTCA(inTCA, NULL, idIndex, minPt, maxAEta); 
}
int NumGoodVertex(TClonesArray* inTCA) {
	return GetGoodVertex(inTCA, NULL);
}
int NumPassTriggerTCA(TClonesArray* triggerTCA) {
	return GetPassTriggerTCA(triggerTCA, NULL);
}
int NumPassTriggerTCA(TClonesArray* triggerTCA, std::string name) {
	return GetPassTriggerTCA(triggerTCA, NULL, name);
}
int NumPassTriggerTCA(TClonesArray* triggerTCA, std::vector<std::string> nameVec = std::vector<std::string>()) {
	return GetPassTriggerTCA(triggerTCA, NULL, nameVec);
}
int NumPassTriggerObjTCA(TClonesArray* triggerObjectTCA, std::string name) {
	return GetPassTriggerObjTCA(triggerObjectTCA, NULL, name);
}



void PrintBit(unsigned int bit) {
	for(unsigned int i=0; i<20; i++) {
		if(i==0) std::cout << "npknu::PrintBit int " << bit << " to bit " ;
		std::cout << ( (unsigned int)(bit & (1<<i)) == (unsigned int)(1<<i) ) << " " ;
	}
	std::cout << std::endl;
}

int GetDirEvents(TString fileNames, TString treename) {
	TChain* inChain = new TChain(treename);
	inChain->Add(fileNames);
	int numFile = inChain->GetListOfFiles()->GetEntries();
	int numEvents = (int)inChain->GetEntries() ;
   std::cout << "TreeName " << inChain->GetName() << " " << numFile << " files " << numEvents << " events in " << fileNames << std::endl;
	delete inChain;
	return numEvents;
}

double DiLepMass(TClonesArray* lepTCA) {
	if(lepTCA->GetEntries() < 2) return -9.0;
	P4* ptr1 = (P4*)lepTCA->At(0);
	P4* ptr2 = (P4*)lepTCA->At(1);
	return ptr1->GetM(ptr2);
}




void PrintCMD(int argc, char** argv) {
	std::cout << "#CMD: ";
	for(int i=0; i<argc; i++) {
		std::cout << argv[i] << " " ;
	}
	std::cout << std::endl << std::endl;
}


double P4::deltaPhi(const P4* ptr) {
   double dPhi = TMath::Abs(phi - ptr->phi);
   dPhi = ( dPhi > TMath::Pi() ) ? TMath::TwoPi() - dPhi : dPhi;
   return dPhi;
}
double P4::deltaPhi(double PHI) {
   double dPhi = TMath::Abs(phi - PHI);
   dPhi = ( dPhi > TMath::Pi() ) ? TMath::TwoPi() - dPhi : dPhi;
   return dPhi;
}

double P4::etRatio(const P4* ptr) {
   double etRatio = (ptr->pt == 0.0) ? 0.0 : (pt / ptr->pt );
   return etRatio;
}
double P4::etRatio(const P4 obj) {
   double etRatio = (obj.pt == 0.0) ? 0.0 : (pt / obj.pt );
   return etRatio;
}
double P4::etRatio(double PT) {
   double etRatio = (PT == 0.0) ? 0.0 : (pt / PT );
   return etRatio;
}

double P4::deltaR(const P4* ptr) {
   double dEta = eta - ptr->eta;
   double dPhi = TMath::Abs(phi - ptr->phi);
   dPhi = ( dPhi > TMath::Pi() ) ? TMath::TwoPi() - dPhi : dPhi;
   return TMath::Sqrt(dEta*dEta + dPhi*dPhi);
}
double P4::deltaR(const P4 obj) {
   double dEta = eta - obj.eta;
   double dPhi = TMath::Abs(phi - obj.phi);
   dPhi = ( dPhi > TMath::Pi() ) ? TMath::TwoPi() - dPhi : dPhi;
   return TMath::Sqrt(dEta*dEta + dPhi*dPhi);
}

TLorentzVector P4::P4Vector() {
   TLorentzVector p4;
   p4.SetPtEtaPhiE(pt, eta, phi, energy);
   return p4;
}

TLorentzVector P4::P4TVector() {
   TLorentzVector p4 = P4Vector();
   TLorentzVector p4T;
   p4T.SetPtEtaPhiE(p4.Pt(), 0.0, p4.Phi(), p4.Pt());
   return p4T;
}

double P4::GetMt(const P4* ptr) {
   TLorentzVector thisTVec = P4TVector();
   TLorentzVector otherTVec; otherTVec.SetPtEtaPhiE(ptr->pt, 0.0, ptr->phi, ptr->pt);
   return ((thisTVec + otherTVec).M()) ;
}
double P4::GetMt(double PT, double PHI) {
   TLorentzVector thisTVec = P4TVector();
   TLorentzVector otherTVec; otherTVec.SetPtEtaPhiE(PT, 0.0, PHI, PT);
   return ((thisTVec + otherTVec).M()) ;
}

double P4::GetM(const P4 ptr) {
   TLorentzVector thisVec = P4Vector();
   TLorentzVector otherVec; otherVec.SetPtEtaPhiE(ptr.pt, ptr.eta, ptr.phi, ptr.energy);
   return ((thisVec + otherVec).M()) ;
}
double P4::GetM(const P4* ptr) { return GetM(*ptr); };


double MinDeltaR(TClonesArray* inTCA) {
   double dR = 9999;
   for(int i=0; i<inTCA->GetEntries(); i++) {
      npknu::P4* ptr = (npknu::P4*)inTCA->At(i);
      for(int j=i+1; j<inTCA->GetEntries(); j++) {
         npknu::P4* ptrS = (npknu::P4*)inTCA->At(j);
         double thisDR = ptr->deltaR(ptrS);
         if(thisDR < dR) dR = thisDR;
      }
   }
   return dR;
}

double MCWeight(TClonesArray* genInfoTCA) {
   npknu::GenInfo* ptr = (npknu::GenInfo*)genInfoTCA->At(0);
   if(ptr->weight < 0.0) return -1.0;
   return 1.0;
}
//bool PassingTrigger(int id, TClonesArray* inTCA) {
//   for(int i=0; i<inTCA->GetEntries(); i++) {
//      npknu::Trigger* ptr = (npknu::Trigger*)inTCA->At(i);
//      if(ptr->Pass(id)) {
//         return true;
//      }
//   }
//   return false;
//}






void P4::PrintP4() { std::cout << "   P4 pt eta phi energy : " << pt << " " << eta << " " << phi << " " << energy << std::endl; };


} // end namespace npknu

void WelcomeNpKNU() { std::cout << "Welcome to npknu " << std::endl; }



//float EffAreaElectron_Spring15_25ns(double scEta) {
//   // see RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_25ns.txt
//   // see https://indico.cern.ch/event/369235/contribution/4/attachments/734635/1007867/Rami_EffAreas.pdf
//   double AscEta = std::abs(scEta);
//   if(AscEta > 0.0000 and  AscEta < 1.0000) return  0.1752 ;
//   if(AscEta > 1.0000 and  AscEta < 1.4790) return  0.1862 ;
//   if(AscEta > 1.4790 and  AscEta < 2.0000) return  0.1411 ;
//   if(AscEta > 2.0000 and  AscEta < 2.2000) return  0.1534 ;
//   if(AscEta > 2.2000 and  AscEta < 2.3000) return  0.1903 ;
//   if(AscEta > 2.3000 and  AscEta < 2.4000) return  0.2243 ;
//   if(AscEta > 2.4000 )                     return  0.2687 ;
//	std::cout << "Error in npknu::EffAreaElectron_Spring15_25ns  with scEta " << scEta << " " << std::endl;
//   return 999999.0;
//}
//
//float EffAreaElectron_Spring15_50ns(double scEta) {
//   // see RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_50ns.txt
//   // https://indico.cern.ch/event/369235/contribution/4/attachments/734635/1007867/Rami_EffAreas.pdf
//   double AscEta = std::abs(scEta);
//   if(AscEta > 0.0000 and AscEta < 0.8000) return 0.0973 ;
//   if(AscEta > 0.8000 and AscEta < 1.3000) return 0.0954 ;
//   if(AscEta > 1.3000 and AscEta < 2.0000) return 0.0632 ;
//   if(AscEta > 2.0000 and AscEta < 2.2000) return 0.0727 ;
//   if(AscEta > 2.2000 )                    return 0.1337 ;
//	std::cout << "Error in npknu::EffAreaElectron_Spring15_50ns with scEta " << scEta << " " << std::endl;
//   return 999999.0;
//}
//
//
//
//float EffAreaPhotonCha(double scEta, bool is50ns) {
//	// https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonIdentificationRun2
//	// Effective areas for the SPRING15, conditions: bx50 ns 
//	// Effective areas for the SPRING15, conditions: bx25 ns
//	double AscEta = std::abs(scEta);
//	if(AscEta > 0.0   and AscEta < 1.0   ) return ((is50ns) ? 0.0157 : 0.0 ) ;
//	if(AscEta > 1.0   and AscEta < 1.479 ) return ((is50ns) ? 0.0143 : 0.0 ) ;
//	if(AscEta > 1.479 and AscEta < 2.0   ) return ((is50ns) ? 0.0115 : 0.0 ) ;
//	if(AscEta > 2.0   and AscEta < 2.2   ) return ((is50ns) ? 0.0094 : 0.0 ) ;
//	if(AscEta > 2.2   and AscEta < 2.3   ) return ((is50ns) ? 0.0095 : 0.0 ) ;
//	if(AscEta > 2.3   and AscEta < 2.4   ) return ((is50ns) ? 0.0068 : 0.0 ) ;
//	if(AscEta > 2.4   )                    return ((is50ns) ? 0.0053 : 0.0 ) ;
//	std::cout << "Error in npknu::EffAreaPhotonCHA scEta " << scEta << " " << std::endl;
//	return 999999.0;
//}
//
//float EffAreaPhotonNeu(double scEta, bool is50ns) {
//	// https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonIdentificationRun2
//	// Effective areas for the SPRING15, conditions: bx50 ns 
//	// Effective areas for the SPRING15, conditions: bx25 ns
//	double AscEta = std::abs(scEta);
//	if(AscEta > 0.0   and AscEta < 1.0   ) return ((is50ns) ? 0.0143 : 0.0599 ) ;
//	if(AscEta > 1.0   and AscEta < 1.479 ) return ((is50ns) ? 0.0210 : 0.0819 ) ;
//	if(AscEta > 1.479 and AscEta < 2.0   ) return ((is50ns) ? 0.0147 : 0.0696 ) ;
//	if(AscEta > 2.0   and AscEta < 2.2   ) return ((is50ns) ? 0.0082 : 0.0360 ) ;
//	if(AscEta > 2.2   and AscEta < 2.3   ) return ((is50ns) ? 0.0124 : 0.0360 ) ;
//	if(AscEta > 2.3   and AscEta < 2.4   ) return ((is50ns) ? 0.0186 : 0.0462 ) ;
//	if(AscEta > 2.4   )                    return ((is50ns) ? 0.0320 : 0.0656 ) ;
//	std::cout << "Error in npknu::EffAreaPhotonNeu with scEta " << scEta << " " << std::endl;
//	return 999999.0;
//}
//
//float EffAreaPhotonPho(double scEta, bool is50ns) {
//	// https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonIdentificationRun2
//	// Effective areas for the SPRING15, conditions: bx50 ns 
//	// Effective areas for the SPRING15, conditions: bx25 ns
//	double AscEta = std::abs(scEta);
//	if(AscEta > 0.0   and AscEta < 1.0   ) return ((is50ns) ? 0.0725 : 0.1271 ) ;
//	if(AscEta > 1.0   and AscEta < 1.479 ) return ((is50ns) ? 0.0604 : 0.1101 ) ;
//	if(AscEta > 1.479 and AscEta < 2.0   ) return ((is50ns) ? 0.0320 : 0.0756 ) ;
//	if(AscEta > 2.0   and AscEta < 2.2   ) return ((is50ns) ? 0.0512 : 0.1175 ) ;
//	if(AscEta > 2.2   and AscEta < 2.3   ) return ((is50ns) ? 0.0766 : 0.1498 ) ;
//	if(AscEta > 2.3   and AscEta < 2.4   ) return ((is50ns) ? 0.0949 : 0.1857 ) ;
//	if(AscEta > 2.4   )                    return ((is50ns) ? 0.1160 : 0.2183 ) ;
//	std::cout << "Error in npknu::EffAreaPhotonPho with scEta " << scEta << " " << std::endl;
//	return 999999.0;
//}
