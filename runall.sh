#!/bin/bash

masses="200 400 600 800 1000 1200 1400 1600 1800 2000 2200 2400 2600 2800 3000 3200 3400 3600 3800 4000 4200 4400 4600 4800 5000 5400 5600 5800 6000 6200 6400"

for m in $masses
do
    echo "Running ./addNewPDF4LHCRun2.exe ../ntuples/wprime_${m}_102X_upgrade2018.root >& addPDF_${m}.out"
    ./addNewPDF4LHCRun2.exe ../ntuples/wprime_${m}_102X_upgrade2018.root >& addPDF_${m}.out 
    
    echo "Running ./pdf4lhc15Uncert.exe ${m} wprime_${m}_102X_upgrade2018_pdf_nf4.root >& result_${m}.out"
    ./pdf4lhc15Uncert.exe ${m} ./wprime_${m}_102X_upgrade2018_addpdf.root >& result_${m}.out

done
