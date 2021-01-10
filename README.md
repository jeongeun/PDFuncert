# PDF+alphaS uncertainties
Calculate the PDF+alphaS uncertainties

PDF4LHC main homepage = [https://www.hep.ucl.ac.uk/pdf4lhc/](https://www.hep.ucl.ac.uk/pdf4lhc/)

LHAPDF6 main homepage = [https://lhapdf.hepforge.org/](https://lhapdf.hepforge.org/)

CMS twiki = [https://twiki.cern.ch/twiki/bin/viewauth/CMS/PDFatCMS](https://twiki.cern.ch/twiki/bin/viewauth/CMS/PDFatCMS)

CMS Run3 recommandation = [Katerina's presentation 20200518](https://indico.cern.ch/event/916118/contributions/3866961/attachments/2039823/3415889/GEN_18_May_20.pdf)

### (step 1) addNewPDF4LHCRun.cc

Use GenInfo (pdgid1, pdgid2, x1, x2, Q) as inputs to LHAPDF to get PDF values(xfx) for PDF4LHC15 PDF sets.


`./addNewPDF4LHCRun.exe [ntuple.root] >& step1.log  --> ntuple_pdf.root created (containing PDFs for every PDF sets)`

### (step 2) pdf4lhc15Uncert.cc 

Calculate the PDF uncertainties and alphaS uncertainties and Combine them.


`./pdf4lhc15Uncert.exe [ntuple_pdf.root] >& step2.log`

### How to run 

`./compile.sh # complie .cc to .exe files`

`./runall.sh  # running all step (1)+(2) at once`



