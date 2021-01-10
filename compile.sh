## set environment
export LHAPDF_DIR=/hcp/data/data02/jelee/LHAPDF
export NpKNU_DIR=/hcp/data/data02/jelee/Wprime13TeV/Run2Legacy19/CMSSW_10_2_20/src/MakeNpKNU/ProdNpKNU/src
export PATH=$LHAPDF_DIR/bin:$PATH
export LD_LIBRARY_PATH=$LHAPDF_DIR/lib:$NpKNU_DIR:$LD_LIBRARY_PATH

## compile
g++ `root-config --cflags` `root-config --libs` addNewPDF4LHCRun2.cc -I$NpKNU_DIR -L$NpKNU_DIR -lNpKNU -I$LHAPDF_DIR/include -L$LHAPDF_DIR/lib -lLHAPDF -o addNewPDF4LHCRun2.exe

g++ `root-config --cflags` `root-config --libs` pdf4lhc15Uncert.cc -I$NpKNU_DIR -L$NpKNU_DIR -lNpKNU -I$LHAPDF_DIR/include -L$LHAPDF_DIR/lib -lLHAPDF -o pdf4lhc15Uncert.exe
