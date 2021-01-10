# PDF+alphaS uncertainties
Calculate the PDF+alphaS uncertainties

PDF4LHC main homepage = [https://www.hep.ucl.ac.uk/pdf4lhc/](https://www.hep.ucl.ac.uk/pdf4lhc/)

LHAPDF6 main homepage = [https://lhapdf.hepforge.org/](https://lhapdf.hepforge.org/)

CMS twiki = [https://twiki.cern.ch/twiki/bin/viewauth/CMS/PDFatCMS](https://twiki.cern.ch/twiki/bin/viewauth/CMS/PDFatCMS)

CMS Run3 recommandation = [Katerina's presentation 20200518](https://indico.cern.ch/event/916118/contributions/3866961/attachments/2039823/3415889/GEN_18_May_20.pdf)

### (step 0) Make ntuple (MINIAODSIM)

MakeNpKNU : Make ntuples from MINIAODSIM signal files using condor

`cd ProdNpKNU/src`

`make`

`source runCondor`


### (step 1) Extracting GenInfo from ntuple and adding PDFs (xfx) into remade ntuple : addNewPDF4LHCRun.cc

Use GenInfo (pdgid1, pdgid2, x1, x2, Q) as inputs to LHAPDF to get PDF values(xfx) for PDF4LHC15 PDF sets.


`./addNewPDF4LHCRun.exe [ntuple.root] >& addpdf.log` 
--> [ntuple_addpdf.root] newly created (it additionally contains the calculated PDFs(xfxs) for every PDF sets)

### (step 2) Calculate PDF+alphaS uncertainties :  pdf4lhc15Uncert.cc 

Calculate the PDF uncertainties and alphaS uncertainties and Combine them.


`./pdf4lhc15Uncert.exe [ntuple_addpdf.root] >& uncert.out`

### Run at once (Step1+Step2)

`./compile.sh # complie .cc to .exe files`

`./runall.sh  # running step (1)+(2) at once for every signal mass points`



