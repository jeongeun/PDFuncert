# PDF+aS uncertainties
Calculate the PDF+alphaS uncertainties

(1) addNewPDF4LHCRun.cc : 
Use GenInfo (pdgid1, pdgid2, x1, x2, Q) as inputs to get PDFs for PDF4LHC15 PDF sets.


./addNewPDF4LHCRun.exe [ntuple.root] >& step1.log  --> ntuple_pdf.root created (containing PDFs for every PDF sets)

(2) pdf4lhc15Uncert.cc  : 
Calculate the PDF uncertainties and alphaS uncertainties and Combine them.


./pdf4lhc15Uncert.exe [ntuple_pdf.root] >& step2.log

How to run :

./compile.sh # complie .cc to .exe files

./runall.sh  # running all step (1)+(2) at once



