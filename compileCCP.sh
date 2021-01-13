## set environment
#DIR_LHAPDF="/cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/lhapdf/6.2.1"
DIR_LHAPDF="/x3/cms/jelee/pdftutorial"
#DIR_LHAPDFb="/x3/cms/jelee/pdftutorial"
DIR_NpKNU="./ProdNpKNU/src"

export PATH=$DIR_LHAPDF/bin:$PATH
export LD_LIBRARY_PATH=$DIR_LHAPDF/lib:$DIR_NpKNU:$LD_LIBRARY_PATH

## compile
echo "g++ `root-config --cflags` `root-config --libs` addNewPDFRun3.cc -I$DIR_NpKNU -L$DIR_NpKNU -lNpKNU -I$DIR_LHAPDF/include -L$DIR_LHAPDF/lib -lLHAPDF -o test.exe"
g++ `root-config --cflags` `root-config --libs` addNewPDFRun3.cc -I$DIR_NpKNU -L$DIR_NpKNU -lNpKNU -I$DIR_LHAPDF/include -L$DIR_LHAPDF/lib -lLHAPDF -o test_addpdf.exe

g++ `root-config --cflags` `root-config --libs` pdf4lhc15UncertRun3.cc -I$DIR_NpKNU -L$DIR_NpKNU -lNpKNU -I$DIR_LHAPDF/include -L$DIR_LHAPDF/lib -lLHAPDF -o test_pdfuncert.exe
