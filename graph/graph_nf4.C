#include "TGraph.h"
#include "TMath.h"
#include "tdrstyle.C"
#include "TLatex.h"

void graph_nf4(){

  gStyle->SetOptStat(0);
  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadBorderMode(1);
  gStyle->SetPadColor(0);
  gStyle->SetFrameBorderMode(0);

   const int midx = 32;
   const double lM = 0.2;
   const double hM = 6.4;
   double Mass[midx];
   double Reordering[midx];
   double mcBest_Fit[midx];
   double mc_STDMean[midx];
   double PDF4LHC15_mc_ord[midx];   double PDF4LHC15_mc_ord_M[midx];  //Re-ordering
   double PDF4LHC15_mc_std[midx];   double PDF4LHC15_mc_std_M[midx];  //Standard deviation
   double AlphaS_mc[midx];          double AlphaS_mc_M[midx];
   double PDFAsComb_mc_ord[midx];   double PDFAsComb_mc_ord_M[midx];  //PDF+AlphaS uncertainty
   double PDFAsComb_mc_std[midx];   double PDFAsComb_mc_std_M[midx];  //PDF+AlphaS uncertainty
   double BestFit100[midx];
   double STDMean100[midx];
   double PDF4LHC15_he_100[midx];   double PDF4LHC15_he_100_M[midx];  //Standard deviation
   double AlphaS_100[midx];         double AlphaS_100_M[midx];
   double PDFAsComb_100[midx];      double PDFAsComb_100_M[midx];  //PDF+AlphaS uncertainty
   double Best_Fit30[midx];
   double STDMean_30[midx];
   double PDF4LHC15_he_30[midx];   double PDF4LHC15_he_30_M[midx];   //Standard deviation
   double AlphaS_30[midx];         double AlphaS_30_M[midx];
   double PDFAsComb_30[midx];      double PDFAsComb_30_M[midx];  //PDF+AlphaS uncertainty


   AlphaS_100[0] = 0.0061393  ; 
   AlphaS_30[0] = 0.0061393  ; 
   AlphaS_mc[0] = 0.0061393  ; 
   BestFit100[0] = 0.911868  ; 
   Best_Fit30[0] = 0.911872  ; 
   mcBest_Fit[0] = 0.910162  ; 
   mc_STDMean[0] =  0.910123  ; 
   PDF4LHC15_he_100[0] = 0.0154104  ;  //Standard deviation
   PDF4LHC15_he_30[0] = 0.0140759  ;  //Standard deviation
   PDF4LHC15_mc_ord[0] = 0.0379048  ; //Re-ordering 
   PDF4LHC15_mc_std[0] = 0.015897  ; //Standard deviation 
   Reordering[0] = 0.867573  ; 
   STDMean100[0] = 0.911943  ; 
   STDMean_30[0] = 0.911983  ; 
 
   AlphaS_100[1] = 0.00365508  ; 
   AlphaS_30[1] = 0.00365508  ; 
   AlphaS_mc[1] = 0.00365508  ; 
   BestFit100[1] = 0.952157  ; 
   Best_Fit30[1] = 0.952164  ; 
   mcBest_Fit[1] = 0.951227  ; 
   mc_STDMean[1] =  0.951184  ; 
   PDF4LHC15_he_100[1] = 0.0167539  ;  //Standard deviation
   PDF4LHC15_he_30[1] = 0.0157946  ;  //Standard deviation
   PDF4LHC15_mc_ord[1] = 0.03978  ; //Re-ordering 
   PDF4LHC15_mc_std[1] = 0.0164895  ; //Standard deviation 
   Reordering[1] = 0.917599  ; 
   STDMean100[1] = 0.952189  ; 
   STDMean_30[1] = 0.952256  ; 
 
   AlphaS_100[2] = 0.00158293  ; 
   AlphaS_30[2] = 0.00158293  ; 
   AlphaS_mc[2] = 0.00158293  ; 
   BestFit100[2] = 0.976985  ; 
   Best_Fit30[2] = 0.976991  ; 
   mcBest_Fit[2] = 0.976564  ; 
   mc_STDMean[2] =  0.976543  ; 
   PDF4LHC15_he_100[2] = 0.0197256  ;  //Standard deviation
   PDF4LHC15_he_30[2] = 0.0189449  ;  //Standard deviation
   PDF4LHC15_mc_ord[2] = 0.0417791  ; //Re-ordering 
   PDF4LHC15_mc_std[2] = 0.0190262  ; //Standard deviation 
   Reordering[2] = 0.948074  ; 
   STDMean100[2] = 0.976971  ; 
   STDMean_30[2] = 0.977095  ; 
 
   AlphaS_100[3] = -0.000169858  ; 
   AlphaS_30[3] = -0.000169858  ; 
   AlphaS_mc[3] = -0.000169858  ; 
   BestFit100[3] = 0.997798  ; 
   Best_Fit30[3] = 0.997802  ; 
   mcBest_Fit[3] = 0.997613  ; 
   mc_STDMean[3] =  0.997604  ; 
   PDF4LHC15_he_100[3] = 0.0235379  ;  //Standard deviation
   PDF4LHC15_he_30[3] = 0.0225851  ;  //Standard deviation
   PDF4LHC15_mc_ord[3] = 0.0411058  ; //Re-ordering 
   PDF4LHC15_mc_std[3] = 0.0225567  ; //Standard deviation 
   Reordering[3] = 0.971452  ; 
   STDMean100[3] = 0.997763  ; 
   STDMean_30[3] = 0.997924  ; 

   AlphaS_100[4] = -0.00185627  ; 
   AlphaS_30[4] = -0.00185627  ; 
   AlphaS_mc[4] = -0.00185627  ; 
   BestFit100[4] = 1.01467  ; 
   Best_Fit30[4] = 1.01467  ; 
   mcBest_Fit[4] = 1.01469  ; 
   mc_STDMean[4] =  1.0147  ; 
   PDF4LHC15_he_100[4] = 0.0277836  ;  //Standard deviation
   PDF4LHC15_he_30[4] = 0.0265131  ;  //Standard deviation
   PDF4LHC15_mc_ord[4] = 0.0407158  ; //Re-ordering 
   PDF4LHC15_mc_std[4] = 0.0267604  ; //Standard deviation 
   Reordering[4] = 0.991741  ; 
   STDMean100[4] = 1.01463  ; 
   STDMean_30[4] = 1.01487  ; 

   AlphaS_100[5] = -0.00328465  ; 
   AlphaS_30[5] = -0.00328465  ; 
   AlphaS_mc[5] = -0.00328465  ; 
   BestFit100[5] = 1.02802  ; 
   Best_Fit30[5] = 1.02802  ; 
   mcBest_Fit[5] = 1.02822  ; 
   mc_STDMean[5] =  1.02824  ; 
   PDF4LHC15_he_100[5] = 0.0318631  ;  //Standard deviation
   PDF4LHC15_he_30[5] = 0.0300943  ;  //Standard deviation
   PDF4LHC15_mc_ord[5] = 0.0397858  ; //Re-ordering 
   PDF4LHC15_mc_std[5] = 0.0308111  ; //Standard deviation 
   Reordering[5] = 1.00619  ; 
   STDMean100[5] = 1.028  ; 
   STDMean_30[5] = 1.02828  ; 

   AlphaS_100[6] = -0.0046502  ; 
   AlphaS_30[6] = -0.0046502  ; 
   AlphaS_mc[6] = -0.0046502  ; 
   BestFit100[6] = 1.04228  ; 
   Best_Fit30[6] = 1.04228  ; 
   mcBest_Fit[6] = 1.04261  ; 
   mc_STDMean[6] =  1.04264  ; 
   PDF4LHC15_he_100[6] = 0.0361021  ;  //Standard deviation
   PDF4LHC15_he_30[6] = 0.0339122  ;  //Standard deviation
   PDF4LHC15_mc_ord[6] = 0.0392956  ; //Re-ordering 
   PDF4LHC15_mc_std[6] = 0.0349261  ; //Standard deviation 
   Reordering[6] = 1.02173  ; 
   STDMean100[6] = 1.0423  ; 
   STDMean_30[6] = 1.04263  ; 

   AlphaS_100[7] = -0.0058624  ; 
   AlphaS_30[7] = -0.0058624  ; 
   AlphaS_mc[7] = -0.0058624  ; 
   BestFit100[7] = 1.05496  ; 
   Best_Fit30[7] = 1.05496  ; 
   mcBest_Fit[7] = 1.0552  ; 
   mc_STDMean[7] =  1.05525  ; 
   PDF4LHC15_he_100[7] = 0.0401692  ;  //Standard deviation
   PDF4LHC15_he_30[7] = 0.0376597  ;  //Standard deviation
   PDF4LHC15_mc_ord[7] = 0.03738  ; //Re-ordering 
   PDF4LHC15_mc_std[7] = 0.0388164  ; //Standard deviation 
   Reordering[7] = 1.03625  ; 
   STDMean100[7] = 1.05502  ; 
   STDMean_30[7] = 1.05537  ; 

   AlphaS_100[8] = -0.00700266  ; 
   AlphaS_30[8] = -0.00700266  ; 
   AlphaS_mc[8] = -0.00700266  ; 
   BestFit100[8] = 1.0651  ; 
   Best_Fit30[8] = 1.0651  ; 
   mcBest_Fit[8] = 1.06521  ; 
   mc_STDMean[8] =  1.06529  ; 
   PDF4LHC15_he_100[8] = 0.0441937  ;  //Standard deviation
   PDF4LHC15_he_30[8] = 0.0413568  ;  //Standard deviation
   PDF4LHC15_mc_ord[8] = 0.0377437  ; //Re-ordering 
   PDF4LHC15_mc_std[8] = 0.0427716  ; //Standard deviation 
   Reordering[8] = 1.04624  ; 
   STDMean100[8] = 1.06523  ; 
   STDMean_30[8] = 1.06557  ; 

   AlphaS_100[9] = -0.00835684  ; 
   AlphaS_30[9] = -0.00835684  ; 
   AlphaS_mc[9] = -0.00835684  ; 
   BestFit100[9] = 1.07107  ; 
   Best_Fit30[9] = 1.07107  ; 
   mcBest_Fit[9] = 1.07096  ; 
   mc_STDMean[9] =  1.07103  ; 
   PDF4LHC15_he_100[9] = 0.0484822  ;  //Standard deviation
   PDF4LHC15_he_30[9] = 0.0449279  ;  //Standard deviation
   PDF4LHC15_mc_ord[9] = 0.0451513  ; //Re-ordering 
   PDF4LHC15_mc_std[9] = 0.0475434  ; //Standard deviation 
   Reordering[9] = 1.05355  ; 
   STDMean100[9] = 1.07131  ; 
   STDMean_30[9] = 1.07152  ; 

   AlphaS_100[10] = -0.00908999  ; 
   AlphaS_30[10] = -0.00908999  ; 
   AlphaS_mc[10] = -0.00908999  ; 
   BestFit100[10] = 1.08232  ; 
   Best_Fit30[10] = 1.08232  ; 
   mcBest_Fit[10] = 1.0818  ; 
   mc_STDMean[10] =  1.08187  ; 
   PDF4LHC15_he_100[10] = 0.0516246  ;  //Standard deviation
   PDF4LHC15_he_30[10] = 0.0481085  ;  //Standard deviation
   PDF4LHC15_mc_ord[10] = 0.0449072  ; //Re-ordering 
   PDF4LHC15_mc_std[10] = 0.0510274  ; //Standard deviation 
   Reordering[10] = 1.06849  ; 
   STDMean100[10] = 1.08263  ; 
   STDMean_30[10] = 1.08278  ; 

   AlphaS_100[11] = -0.010168  ; 
   AlphaS_30[11] = -0.010168  ; 
   AlphaS_mc[11] = -0.010168  ; 
   BestFit100[11] = 1.08601  ; 
   Best_Fit30[11] = 1.08602  ; 
   mcBest_Fit[11] = 1.08499  ; 
   mc_STDMean[11] =  1.08508  ; 
   PDF4LHC15_he_100[11] = 0.0555496  ;  //Standard deviation
   PDF4LHC15_he_30[11] = 0.050939  ;  //Standard deviation
   PDF4LHC15_mc_ord[11] = 0.0466641  ; //Re-ordering 
   PDF4LHC15_mc_std[11] = 0.055392  ; //Standard deviation 
   Reordering[11] = 1.06984  ; 
   STDMean100[11] = 1.08646  ; 
   STDMean_30[11] = 1.08638  ; 

   AlphaS_100[12] = -0.0112154  ; 
   AlphaS_30[12] = -0.0112154  ; 
   AlphaS_mc[12] = -0.0112154  ; 
   BestFit100[12] = 1.08807  ; 
   Best_Fit30[12] = 1.08808  ; 
   mcBest_Fit[12] = 1.08668  ; 
   mc_STDMean[12] =  1.08677  ; 
   PDF4LHC15_he_100[12] = 0.0604259  ;  //Standard deviation
   PDF4LHC15_he_30[12] = 0.0533608  ;  //Standard deviation
   PDF4LHC15_mc_ord[12] = 0.0584736  ; //Re-ordering 
   PDF4LHC15_mc_std[12] = 0.061562  ; //Standard deviation 
   Reordering[12] = 1.07402  ; 
   STDMean100[12] = 1.08872  ; 
   STDMean_30[12] = 1.08834  ; 

   AlphaS_100[13] = -0.0115851  ; 
   AlphaS_30[13] = -0.0115851  ; 
   AlphaS_mc[13] = -0.0115851  ; 
   BestFit100[13] = 1.08935  ; 
   Best_Fit30[13] = 1.08936  ; 
   mcBest_Fit[13] = 1.08763  ; 
   mc_STDMean[13] =  1.08771  ; 
   PDF4LHC15_he_100[13] = 0.0646164  ;  //Standard deviation
   PDF4LHC15_he_30[13] = 0.0546469  ;  //Standard deviation
   PDF4LHC15_mc_ord[13] = 0.0628274  ; //Re-ordering 
   PDF4LHC15_mc_std[13] = 0.0665744  ; //Standard deviation 
   Reordering[13] = 1.0759  ; 
   STDMean100[13] = 1.09015  ; 
   STDMean_30[13] = 1.08949  ; 

   AlphaS_100[14] = -0.012493  ; 
   AlphaS_30[14] = -0.012493  ; 
   AlphaS_mc[14] = -0.012493  ; 
   BestFit100[14] = 1.08538  ; 
   Best_Fit30[14] = 1.08539  ; 
   mcBest_Fit[14] = 1.0834  ; 
   mc_STDMean[14] =  1.08343  ; 
   PDF4LHC15_he_100[14] = 0.0717033  ;  //Standard deviation
   PDF4LHC15_he_30[14] = 0.0572725  ;  //Standard deviation
   PDF4LHC15_mc_ord[14] = 0.0772035  ; //Re-ordering 
   PDF4LHC15_mc_std[14] = 0.0747954  ; //Standard deviation 
   Reordering[14] = 1.07422  ; 
   STDMean100[14] = 1.0864  ; 
   STDMean_30[14] = 1.0854  ; 

   AlphaS_100[15] = -0.0125573  ; 
   AlphaS_30[15] = -0.0125573  ; 
   AlphaS_mc[15] = -0.0125573  ; 
   BestFit100[15] = 1.07138  ; 
   Best_Fit30[15] = 1.07139  ; 
   mcBest_Fit[15] = 1.06968  ; 
   mc_STDMean[15] =  1.06962  ; 
   PDF4LHC15_he_100[15] = 0.0803583  ;  //Standard deviation
   PDF4LHC15_he_30[15] = 0.057765  ;  //Standard deviation
   PDF4LHC15_mc_ord[15] = 0.0906432  ; //Re-ordering 
   PDF4LHC15_mc_std[15] = 0.0843829  ; //Standard deviation 
   Reordering[15] = 1.05806  ; 
   STDMean100[15] = 1.07263  ; 
   STDMean_30[15] = 1.07124  ; 

   AlphaS_100[16] = -0.0124142  ; 
   AlphaS_30[16] = -0.0124142  ; 
   AlphaS_mc[16] = -0.0124142  ; 
   BestFit100[16] = 1.06158  ; 
   Best_Fit30[16] = 1.06159  ; 
   mcBest_Fit[16] = 1.06017  ; 
   mc_STDMean[16] =  1.06  ; 
   PDF4LHC15_he_100[16] = 0.0888716  ;  //Standard deviation
   PDF4LHC15_he_30[16] = 0.0583716  ;  //Standard deviation
   PDF4LHC15_mc_ord[16] = 0.101462  ; //Re-ordering 
   PDF4LHC15_mc_std[16] = 0.0934001  ; //Standard deviation 
   Reordering[16] = 1.04937  ; 
   STDMean100[16] = 1.06303  ; 
   STDMean_30[16] = 1.0614  ; 

   AlphaS_100[17] = -0.0125979  ; 
   AlphaS_30[17] = -0.0125979  ; 
   AlphaS_mc[17] = -0.0125979  ; 
   BestFit100[17] = 1.03195  ; 
   Best_Fit30[17] = 1.03195  ; 
   mcBest_Fit[17] = 1.03125  ; 
   mc_STDMean[17] =  1.03097  ; 
   PDF4LHC15_he_100[17] = 0.106281  ;  //Standard deviation
   PDF4LHC15_he_30[17] = 0.0632835  ;  //Standard deviation
   PDF4LHC15_mc_ord[17] = 0.122681  ; //Re-ordering 
   PDF4LHC15_mc_std[17] = 0.110638  ; //Standard deviation 
   Reordering[17] = 1.01107  ; 
   STDMean100[17] = 1.03371  ; 
   STDMean_30[17] = 1.03149  ; 

   AlphaS_100[18] = -0.0117245  ; 
   AlphaS_30[18] = -0.0117245  ; 
   AlphaS_mc[18] = -0.0117245  ; 
   BestFit100[18] = 1.01468  ; 
   Best_Fit30[18] = 1.01469  ; 
   mcBest_Fit[18] = 1.01464  ; 
   mc_STDMean[18] =  1.0143  ; 
   PDF4LHC15_he_100[18] = 0.113688  ;  //Standard deviation
   PDF4LHC15_he_30[18] = 0.0638471  ;  //Standard deviation
   PDF4LHC15_mc_ord[18] = 0.132675  ; //Re-ordering 
   PDF4LHC15_mc_std[18] = 0.11852  ; //Standard deviation 
   Reordering[18] = 0.999184  ; 
   STDMean100[18] = 1.01655  ; 
   STDMean_30[18] = 1.01425  ; 

   AlphaS_100[19] = -0.0115182  ; 
   AlphaS_30[19] = -0.0115182  ; 
   AlphaS_mc[19] = -0.0115182  ; 
   BestFit100[19] = 0.977983  ; 
   Best_Fit30[19] = 0.977985  ; 
   mcBest_Fit[19] = 0.979271  ; 
   mc_STDMean[19] =  0.978867  ; 
   PDF4LHC15_he_100[19] = 0.135282  ;  //Standard deviation
   PDF4LHC15_he_30[19] = 0.0725738  ;  //Standard deviation
   PDF4LHC15_mc_ord[19] = 0.163708  ; //Re-ordering 
   PDF4LHC15_mc_std[19] = 0.139727  ; //Standard deviation 
   Reordering[19] = 0.957983  ; 
   STDMean100[19] = 0.980176  ; 
   STDMean_30[19] = 0.977486  ; 

   AlphaS_100[20] = -0.0105323  ; 
   AlphaS_30[20] = -0.0105323  ; 
   AlphaS_mc[20] = -0.0105323  ; 
   BestFit100[20] = 0.950416  ; 
   Best_Fit30[20] = 0.950421  ; 
   mcBest_Fit[20] = 0.952622  ; 
   mc_STDMean[20] =  0.952225  ; 
   PDF4LHC15_he_100[20] = 0.148194  ;  //Standard deviation
   PDF4LHC15_he_30[20] = 0.0767585  ;  //Standard deviation
   PDF4LHC15_mc_ord[20] = 0.175846  ; //Re-ordering 
   PDF4LHC15_mc_std[20] = 0.152371  ; //Standard deviation 
   Reordering[20] = 0.925982  ; 
   STDMean100[20] = 0.952759  ; 
   STDMean_30[20] = 0.949942  ; 

   AlphaS_100[21] = -0.00972877  ; 
   AlphaS_30[21] = -0.00972877  ; 
   AlphaS_mc[21] = -0.00972877  ; 
   BestFit100[21] = 0.922507  ; 
   Best_Fit30[21] = 0.922515  ; 
   mcBest_Fit[21] = 0.925847  ; 
   mc_STDMean[21] =  0.925461  ; 
   PDF4LHC15_he_100[21] = 0.158479  ;  //Standard deviation
   PDF4LHC15_he_30[21] = 0.0819155  ;  //Standard deviation
   PDF4LHC15_mc_ord[21] = 0.190353  ; //Re-ordering 
   PDF4LHC15_mc_std[21] = 0.162487  ; //Standard deviation 
   Reordering[21] = 0.896263  ; 
   STDMean100[21] = 0.924934  ; 
   STDMean_30[21] = 0.922151  ; 

   AlphaS_100[22] = -0.00869887  ; 
   AlphaS_30[22] = -0.00869887  ; 
   AlphaS_mc[22] = -0.00869887  ; 
   BestFit100[22] = 0.89194  ; 
   Best_Fit30[22] = 0.891947  ; 
   mcBest_Fit[22] = 0.896255  ; 
   mc_STDMean[22] =  0.895994  ; 
   PDF4LHC15_he_100[22] = 0.167709  ;  //Standard deviation
   PDF4LHC15_he_30[22] = 0.0894968  ;  //Standard deviation
   PDF4LHC15_mc_ord[22] = 0.201878  ; //Re-ordering 
   PDF4LHC15_mc_std[22] = 0.171453  ; //Standard deviation 
   Reordering[22] = 0.866291  ; 
   STDMean100[22] = 0.89443  ; 
   STDMean_30[22] = 0.891643  ; 

   AlphaS_100[23] = -0.00815002  ; 
   AlphaS_30[23] = -0.00815002  ; 
   AlphaS_mc[23] = -0.00815002  ; 
   BestFit100[23] = 0.863242  ; 
   Best_Fit30[23] = 0.863252  ; 
   mcBest_Fit[23] = 0.868416  ; 
   mc_STDMean[23] =  0.868254  ; 
   PDF4LHC15_he_100[23] = 0.178087  ;  //Standard deviation
   PDF4LHC15_he_30[23] = 0.0947997  ;  //Standard deviation
   PDF4LHC15_mc_ord[23] = 0.224541  ; //Re-ordering 
   PDF4LHC15_mc_std[23] = 0.181891  ; //Standard deviation 
   Reordering[23] = 0.840127  ; 
   STDMean100[23] = 0.865845  ; 
   STDMean_30[23] = 0.863055  ; 

   AlphaS_100[24] = -0.00694492  ; 
   AlphaS_30[24] = -0.00694492  ; 
   AlphaS_mc[24] = -0.00694492  ; 
   BestFit100[24] = 0.852959  ; 
   Best_Fit30[24] = 0.852971  ; 
   mcBest_Fit[24] = 0.858535  ; 
   mc_STDMean[24] =  0.858451  ; 
   PDF4LHC15_he_100[24] = 0.171414  ;  //Standard deviation
   PDF4LHC15_he_30[24] = 0.0915478  ;  //Standard deviation
   PDF4LHC15_mc_ord[24] = 0.211399  ; //Re-ordering 
   PDF4LHC15_mc_std[24] = 0.174985  ; //Standard deviation 
   Reordering[24] = 0.831233  ; 
   STDMean100[24] = 0.855353  ; 
   STDMean_30[24] = 0.852955  ; 

   AlphaS_100[25] = -0.0065  ; 
   AlphaS_30[25] = -0.0065  ; 
   AlphaS_mc[25] = -0.0065  ; 
   BestFit100[25] = 0.839  ; 
   Best_Fit30[25] = 0.839  ; 
   mcBest_Fit[25] = 0.845  ; 
   mc_STDMean[25] =  0.845  ; 
   PDF4LHC15_he_100[25] = 0.1712095  ;  //Standard deviation
   PDF4LHC15_he_30[25] = 0.0934  ;  //Standard deviation
   PDF4LHC15_mc_ord[25] = 0.2115  ; //Re-ordering 
   PDF4LHC15_mc_std[25] = 0.175  ; //Standard deviation 
   Reordering[25] = 0.82  ; 
   STDMean100[25] = 0.8415385  ; 
   STDMean_30[25] = 0.84  ; 

   AlphaS_100[26] = -0.00611267  ; 
   AlphaS_30[26] = -0.00611267  ; 
   AlphaS_mc[26] = -0.00611267  ; 
   BestFit100[26] = 0.825477  ; 
   Best_Fit30[26] = 0.825486  ; 
   mcBest_Fit[26] = 0.831645  ; 
   mc_STDMean[26] =  0.831819  ; 
   PDF4LHC15_he_100[26] = 0.171005  ;  //Standard deviation
   PDF4LHC15_he_30[26] = 0.0956603  ;  //Standard deviation
   PDF4LHC15_mc_ord[26] = 0.21185  ; //Re-ordering 
   PDF4LHC15_mc_std[26] = 0.175013  ; //Standard deviation 
   Reordering[26] = 0.805956  ; 
   STDMean100[26] = 0.827724  ; 
   STDMean_30[26] = 0.825664  ; 

   AlphaS_100[27] = -0.00535798  ; 
   AlphaS_30[27] = -0.00535798  ; 
   AlphaS_mc[27] = -0.00535798  ; 
   BestFit100[27] = 0.829204  ; 
   Best_Fit30[27] = 0.829213  ; 
   mcBest_Fit[27] = 0.835257  ; 
   mc_STDMean[27] =  0.8356  ; 
   PDF4LHC15_he_100[27] = 0.161698  ;  //Standard deviation
   PDF4LHC15_he_30[27] = 0.0905223  ;  //Standard deviation
   PDF4LHC15_mc_ord[27] = 0.20592  ; //Re-ordering 
   PDF4LHC15_mc_std[27] = 0.165446  ; //Standard deviation 
   Reordering[27] = 0.816993  ; 
   STDMean100[27] = 0.831289  ; 
   STDMean_30[27] = 0.829556  ; 

   AlphaS_100[28] = -0.00517733  ; 
   AlphaS_30[28] = -0.00517733  ; 
   AlphaS_mc[28] = -0.00517733  ; 
   BestFit100[28] = 0.829982  ; 
   Best_Fit30[28] = 0.829989  ; 
   mcBest_Fit[28] = 0.835733  ; 
   mc_STDMean[28] =  0.835986  ; 
   PDF4LHC15_he_100[28] = 0.152789  ;  //Standard deviation
   PDF4LHC15_he_30[28] = 0.0880314  ;  //Standard deviation
   PDF4LHC15_mc_ord[28] = 0.195075  ; //Re-ordering 
   PDF4LHC15_mc_std[28] = 0.157057  ; //Standard deviation 
   Reordering[28] = 0.821872  ; 
   STDMean100[28] = 0.831882  ; 
   STDMean_30[28] = 0.83034  ; 

   AlphaS_100[29] = -0.00449259  ; 
   AlphaS_30[29] = -0.00449259  ; 
   AlphaS_mc[29] = -0.00449259  ; 
   BestFit100[29] = 0.832847  ; 
   Best_Fit30[29] = 0.832856  ; 
   mcBest_Fit[29] = 0.838404  ; 
   mc_STDMean[29] =  0.838738  ; 
   PDF4LHC15_he_100[29] = 0.146662  ;  //Standard deviation
   PDF4LHC15_he_30[29] = 0.0852699  ;  //Standard deviation
   PDF4LHC15_mc_ord[29] = 0.191596  ; //Re-ordering 
   PDF4LHC15_mc_std[29] = 0.150569  ; //Standard deviation 
   Reordering[29] = 0.828248  ; 
   STDMean100[29] = 0.834655  ; 
   STDMean_30[29] = 0.833214  ; 

   AlphaS_100[30] = -0.00406681  ;
   AlphaS_30[30] = -0.00406681  ;
   AlphaS_mc[30] = -0.00406681  ;
   BestFit100[30] = 0.846819  ;
   Best_Fit30[30] = 0.846826  ;
   mcBest_Fit[30] = 0.851678  ;
   mc_STDMean[30] =  0.851935  ;
   PDF4LHC15_he_100[30] = 0.130964  ;  //Standard deviation
   PDF4LHC15_he_30[30] = 0.0769568  ;  //Standard deviation
   PDF4LHC15_mc_ord[30] = 0.165363  ; //Re-ordering
   PDF4LHC15_mc_std[30] = 0.135339  ; //Standard deviation
   Reordering[30] = 0.842785  ;
   STDMean100[30] = 0.848345  ;
   STDMean_30[30] = 0.847234  ;

   mcBest_Fit[31] = 0.864951  ;
   Reordering[31] = 0.85592  ;
   mc_STDMean[31] =  0.865402  ;
   PDF4LHC15_mc_ord[31] = 0.143385  ; //Re-ordering
   PDF4LHC15_mc_std[31] = 0.120129  ; //Standard deviation
   AlphaS_mc[31] = -0.0033883  ;
   BestFit100[31] = 0.860428  ;
   STDMean100[31] = 0.86173  ;
   PDF4LHC15_he_100[31] = 0.116694  ;  //Standard deviation
   AlphaS_100[31] = -0.0033883  ;
   Best_Fit30[31] = 0.860435  ;
   STDMean_30[31] = 0.861001  ;
   PDF4LHC15_he_30[31] = 0.0684261  ;  //Standard deviation
   AlphaS_30[31] = -0.0033883  ;


   for(int i=0; i<midx; i++){
       Mass[i] = (200 + (200 * i)) *0.001 ;
//       cout << " Wprime Mass = " << Mass[i] << " TeV/c2 --------------------" << endl;
       mcBest_Fit[i] = TMath::Abs(mcBest_Fit[i])  ;  Reordering[i] = TMath::Abs(Reordering[i])  ;  
       mc_STDMean[i] = TMath::Abs(mc_STDMean[i])  ;
       BestFit100[i] = TMath::Abs(BestFit100[i])  ;  STDMean100[i] = TMath::Abs(STDMean100[i])  ;
       Best_Fit30[i] = TMath::Abs(Best_Fit30[i])  ;  STDMean_30[i] = TMath::Abs(STDMean_30[i])  ;

       PDF4LHC15_mc_ord[i]   =  100 *  TMath::Abs(PDF4LHC15_mc_ord[i]) ;   
       PDF4LHC15_mc_ord_M[i] = -1 *  TMath::Abs(PDF4LHC15_mc_ord[i]) ;  //Re-ordering
       PDF4LHC15_mc_std[i]   =  100 *  TMath::Abs(PDF4LHC15_mc_std[i]) ;   
       PDF4LHC15_mc_std_M[i] = -1 *  TMath::Abs(PDF4LHC15_mc_std[i]) ;  //Standard deviation
       AlphaS_mc[i]          =  100 *  TMath::Abs(AlphaS_mc[i]       ) ;   
       AlphaS_mc_M[i]        = -1 *  TMath::Abs(AlphaS_mc[i]       ) ;
       PDF4LHC15_he_100[i]   =  100 *  TMath::Abs(PDF4LHC15_he_100[i]) ;   
       PDF4LHC15_he_100_M[i] = -1 *  TMath::Abs(PDF4LHC15_he_100[i]) ;   //Standard deviation
       AlphaS_100[i]         =  100 *  TMath::Abs(AlphaS_100[i]      ) ;   
       AlphaS_100_M[i]       = -1 *  TMath::Abs(AlphaS_100[i]      ) ;
       PDF4LHC15_he_30[i]    =  100 *  TMath::Abs(PDF4LHC15_he_30[i] ) ;   
       PDF4LHC15_he_30_M[i]  = -1 *  TMath::Abs(PDF4LHC15_he_30[i] ) ;   //Standard deviation
       AlphaS_30[i]          =  100 *  TMath::Abs(AlphaS_30[i]       ) ;   
       AlphaS_30_M[i]        = -1 *  TMath::Abs(AlphaS_30[i]       ) ;

       PDFAsComb_mc_ord[i]   = TMath::Sqrt((PDF4LHC15_mc_ord[i]*PDF4LHC15_mc_ord[i])+(AlphaS_mc[i]*AlphaS_mc[i]))  ;   
       PDFAsComb_mc_ord_M[i] = PDFAsComb_mc_ord[i]* -1   ;
       PDFAsComb_mc_std[i]   = TMath::Sqrt((PDF4LHC15_mc_std[i]*PDF4LHC15_mc_std[i])+(AlphaS_mc[i]*AlphaS_mc[i]))  ;   
       PDFAsComb_mc_std_M[i] = PDFAsComb_mc_std[i]* -1   ;
       PDFAsComb_100[i]      = TMath::Sqrt((PDF4LHC15_he_100[i]*PDF4LHC15_he_100[i])+(AlphaS_100[i]*AlphaS_100[i]));   
       PDFAsComb_100_M[i]    = PDFAsComb_100[i]* -1 ;
       PDFAsComb_30[i]       = TMath::Sqrt((PDF4LHC15_he_30[i]*PDF4LHC15_he_30[i])+(AlphaS_30[i]*AlphaS_30[i]))    ;   
       PDFAsComb_30_M[i]     = PDFAsComb_30[i]* -1   ;

       //cout << "-----Cross Checking Mean value-----------" << endl;
      // cout << "MC 100      bestfit = " << mcBest_Fit[i] << " 1st stdMean = " << mc_STDMean[i] << " 2nd reOrder = " << Reordering[i] << endl;
      // cout << "Hessian 100 bestfit = " << BestFit100[i] << " stdMean = " << STDMean100[i] << endl;
      // cout << "Hessian 30  bestfit = " << Best_Fit30[i] << " stdMean = " << STDMean_30[i] << endl;
      // cout << "-----Cross Checking Unceratinties-----------" << endl;
       //cout << "PDFAsComb_mc_ord  pdf = " << PDF4LHC15_mc_ord[i] << " as = " << AlphaS_mc[i] << " Combined = " << PDFAsComb_mc_ord[i] << endl;
       //cout << "PDFAsComb_mc_std  pdf = " << PDF4LHC15_mc_std[i] << " as = " << AlphaS_mc[i] << " Combined = " << PDFAsComb_mc_std[i] << endl;
       //cout << "PDFAsComb_100     pdf = " << PDF4LHC15_he_100[i] << " as = " << AlphaS_100[i]<< " Combined = " << PDFAsComb_100[i]    << endl;
       //cout << "PDFAsComb_30      pdf = " << PDF4LHC15_he_30[i]  << " as = " << AlphaS_30[i] << " Combined = " << PDFAsComb_30[i]     << endl;
       //cout << " " << endl;
       cout << " Mass[" << i << "] = " << Mass[i] << "; " << "  PDFerrUp[" << i << "] = " <<  PDFAsComb_mc_std[i] << " ; " << "  PDFerrDown[" << i << "] = " << PDFAsComb_mc_std_M[i] << " ;" <<endl;
//       cout << "PDFAsComb_mc_std  pdf = " <<  PDFAsComb_mc_std[i] << endl;
//       cout << "PDFAsComb_100     pdf = " <<  PDFAsComb_100[i]    << endl;
//       cout << "PDFAsComb_30      pdf = " <<  PDFAsComb_30[i]     << endl;
//       cout << " " << endl;
   }

       TGraph* gr_mcBest_Fit = new TGraph(midx, Mass, mcBest_Fit ) ;
       TGraph* gr_Reordering = new TGraph(midx, Mass, Reordering ) ;
       TGraph* gr_mc_STDMean = new TGraph(midx, Mass, mc_STDMean ) ;
       TGraph* gr_BestFit100 = new TGraph(midx, Mass, BestFit100 ) ;  
       TGraph* gr_Best_Fit30 = new TGraph(midx, Mass, Best_Fit30 ) ;
       TGraph* gr_STDMean100 = new TGraph(midx, Mass, STDMean100 ) ;  
       TGraph* gr_STDMean_30 = new TGraph(midx, Mass, STDMean_30 ) ;

       TGraph* gr_PDF4LHC15_mc_ord   = new TGraph(midx, Mass, PDF4LHC15_mc_ord  ) ;  
       TGraph* gr_PDF4LHC15_mc_ord_M = new TGraph(midx, Mass, PDF4LHC15_mc_ord_M ) ;
       TGraph* gr_PDF4LHC15_mc_std   = new TGraph(midx, Mass, PDF4LHC15_mc_std  ) ;  
       TGraph* gr_PDF4LHC15_mc_std_M = new TGraph(midx, Mass, PDF4LHC15_mc_std_M ) ;
       TGraph* gr_AlphaS_mc          = new TGraph(midx, Mass, AlphaS_mc         ) ;  
       TGraph* gr_AlphaS_mc_M        = new TGraph(midx, Mass, AlphaS_mc_M        ) ;
       TGraph* gr_PDF4LHC15_he_100   = new TGraph(midx, Mass, PDF4LHC15_he_100  ) ;  
       TGraph* gr_PDF4LHC15_he_100_M = new TGraph(midx, Mass, PDF4LHC15_he_100_M ) ;
       TGraph* gr_AlphaS_100         = new TGraph(midx, Mass, AlphaS_100        ) ;  
       TGraph* gr_AlphaS_100_M       = new TGraph(midx, Mass, AlphaS_100_M       ) ;
       TGraph* gr_PDF4LHC15_he_30    = new TGraph(midx, Mass, PDF4LHC15_he_30   ) ;  
       TGraph* gr_PDF4LHC15_he_30_M  = new TGraph(midx, Mass, PDF4LHC15_he_30_M  ) ;
       TGraph* gr_AlphaS_30          = new TGraph(midx, Mass, AlphaS_30         ) ;  
       TGraph* gr_AlphaS_30_M        = new TGraph(midx, Mass, AlphaS_30_M        ) ;

       TGraph* gr_PDFAsComb_mc_ord    = new TGraph(midx, Mass, PDFAsComb_mc_ord    ) ;
       TGraph* gr_PDFAsComb_mc_ord_M  = new TGraph(midx, Mass, PDFAsComb_mc_ord_M  ) ;
       TGraph* gr_PDFAsComb_mc_std    = new TGraph(midx, Mass, PDFAsComb_mc_std    ) ;
       TGraph* gr_PDFAsComb_mc_std_M  = new TGraph(midx, Mass, PDFAsComb_mc_std_M  ) ;
       TGraph* gr_PDFAsComb_100   = new TGraph(midx, Mass, PDFAsComb_100   ) ;
       TGraph* gr_PDFAsComb_100_M = new TGraph(midx, Mass, PDFAsComb_100_M ) ;
       TGraph* gr_PDFAsComb_30    = new TGraph(midx, Mass, PDFAsComb_30    ) ;
       TGraph* gr_PDFAsComb_30_M  = new TGraph(midx, Mass, PDFAsComb_30_M  ) ;

  //setTDRStyle();
 
  TH2D *null0 = new TH2D("null0", "null0", 2, lM , hM , 2, 0.0, 2.0);
  null0->SetStats(kFALSE);
  null0->SetLineColor(0);
  null0->GetYaxis()->SetTitle("Weighting value(R = #sigma^{P}/#sigma^{ref})");
  null0->SetTitleSize(0.010);
  null0->SetTitleFont(42);
  null0->SetTitle("Best-Fit value (Mean)");
  null0->GetXaxis()->SetTitle("M_{W'} (TeV/c^{2})");
  null0->GetXaxis()->SetTitleSize(0.05);
  null0->GetXaxis()->SetTickLength(-0.015);
  null0->GetXaxis()->SetLabelOffset(0.01);
  null0->GetXaxis()->SetTitleFont(42);
  null0->GetXaxis()->SetLabelSize(0.04);
  null0->GetXaxis()->SetTitleOffset(1);
  null0->GetYaxis()->SetTitleSize(0.05);
  null0->GetYaxis()->SetTickLength(-0.015);
  null0->GetYaxis()->SetLabelOffset(0.01);
  null0->GetYaxis()->SetTitleFont(42);
  null0->GetYaxis()->SetLabelSize(0.04);
  null0->GetYaxis()->SetTitleOffset(1.1);

  int W = 1200;      
  int H = 1200;      
  int H_ref = 1200;  
  int W_ref = 1200;  
  float T = 0.08*H_ref;
  float B = 0.12*H_ref;
  float L = 0.12*W_ref;
  float R = 0.04*W_ref;

  TCanvas* c0 = new TCanvas("c0", "", 800, 800);
  c0->SetFillColor(0);
  c0->SetLeftMargin(L/W);
  c0->SetRightMargin(R/W);
  c0->SetTopMargin(T/H);
  c0->SetBottomMargin(B/H);
  //null0->GetXaxis()->SetMoreLabels();
  //null0->GetXaxis()->SetNoExponent(kTRUE);
  null0->Draw();

  gr_Reordering->SetMarkerColor(kBlue)  ; gr_Reordering->SetMarkerStyle(24) ; gr_Reordering->SetMarkerSize(2) ;
  gr_mc_STDMean->SetMarkerColor(kGreen) ; gr_mc_STDMean->SetMarkerStyle(25) ; gr_mc_STDMean->SetMarkerSize(2) ;
  gr_BestFit100->SetMarkerColor(kOrange) ; gr_BestFit100->SetMarkerStyle(26) ; gr_BestFit100->SetMarkerSize(2) ;
  gr_Best_Fit30->SetMarkerColor(kViolet) ; gr_Best_Fit30->SetMarkerStyle(28) ; gr_Best_Fit30->SetMarkerSize(2) ;

  gr_Reordering->Draw("samep");
  gr_mc_STDMean->Draw("samep");
  gr_BestFit100->Draw("samep");
  gr_Best_Fit30->Draw("samep");

  c0->SetGrid();
  TLegend *lgd0 = new TLegend(0.15,0.15,0.38,0.48);
  lgd0->SetFillStyle(0);
  lgd0->SetBorderSize(0);
  lgd0->SetTextSize(0.03);
  lgd0->SetTextFont(42);
  //lgd0->SetHeader("Mean value");
  lgd0->AddEntry(gr_Reordering, "PDF4LHC15_mc(Re-ordering #bar{R})","P" );
  lgd0->AddEntry(gr_mc_STDMean, "PDF4LHC15_mc(Standard deviation <R>)","P" );
  lgd0->AddEntry(gr_BestFit100, "PDF4LHC15_100(BestFit R^{0})","P" );
  lgd0->AddEntry(gr_Best_Fit30, "PDF4LHC15_30(BestFit R^{0})","P" );
  lgd0->Draw();

  TLatex* t0 = new TLatex();
  t0->SetNDC();
  t0->SetTextColor(1);
  t0->SetTextSize(0.030);
  //t0->DrawLatex(0.12,0.90,"#color[1]{#scale[1.2]{CMS Preliminary}}");
  t0->DrawLatex(0.13,0.85,"MC sets: #bar{R} = #frac{R^{(84th)}+R^{(16th)}}{2}");
  t0->DrawLatex(0.13,0.78,"MC sets: <R> = 1/N #sum_{k=1}^{N^{mem}} R^{k}");
  t0->DrawLatex(0.13,0.70,"Hessian sets: R^{0} BestFit");

  //Re ordering)

  TCanvas* c1 = new TCanvas("c1", "", 800, 800);
  c1->SetFillColor(0);
  c1->SetLeftMargin(L/W);
  c1->SetRightMargin(R/W);
  c1->SetTopMargin(T/H);
  c1->SetBottomMargin(B/H);

  TH2D *null1 = new TH2D("null1", "null1", 2, lM , hM , 2, -30, 30);
  null1->SetStats(kFALSE);
  null1->SetLineColor(0);
  null1->GetYaxis()->SetTitle("Uncertainty(%)");
  null1->SetTitleSize(0.010);
  null1->SetTitle("PDF4LHC15_mc (Re-ordering method)");
  null1->GetXaxis()->SetTitle("M_{W'} (TeV/c^{2})");
  null1->GetXaxis()->SetTitleSize(0.05);
  null1->GetXaxis()->SetTickLength(-0.015);
  null1->GetXaxis()->SetLabelOffset(0.01);
  null1->GetXaxis()->SetTitleFont(42);
  null1->GetXaxis()->SetLabelSize(0.04);
  null1->GetXaxis()->SetTitleOffset(1);
  null1->GetYaxis()->SetTitleSize(0.05);
  null1->GetYaxis()->SetTickLength(-0.015);
  null1->GetYaxis()->SetLabelOffset(0.01);
  null1->GetYaxis()->SetTitleFont(42);
  null1->GetYaxis()->SetLabelSize(0.04);
  null1->GetYaxis()->SetTitleOffset(1.1);
  null1->Draw();

  //writeExtraText = true;

    gr_PDF4LHC15_mc_ord->SetLineStyle(1) ;     gr_PDF4LHC15_mc_ord->SetLineColor(kAzure+9 ) ;
  gr_PDF4LHC15_mc_ord_M->SetLineStyle(1) ;   gr_PDF4LHC15_mc_ord_M->SetLineColor(kAzure+9 ) ;
           gr_AlphaS_mc->SetLineStyle(8) ;            gr_AlphaS_mc->SetLineColor(kYellow-3) ;
         gr_AlphaS_mc_M->SetLineStyle(8) ;          gr_AlphaS_mc_M->SetLineColor(kYellow-3) ;
    gr_PDFAsComb_mc_ord->SetLineStyle(7) ;     gr_PDFAsComb_mc_ord->SetLineColor(kAzure-1 ) ;
  gr_PDFAsComb_mc_ord_M->SetLineStyle(7) ;   gr_PDFAsComb_mc_ord_M->SetLineColor(kAzure-1 ) ;

   gr_PDF4LHC15_mc_ord->SetLineWidth(2) ;
 gr_PDF4LHC15_mc_ord_M->SetLineWidth(2) ;
          gr_AlphaS_mc->SetLineWidth(2) ;
        gr_AlphaS_mc_M->SetLineWidth(2) ;
   gr_PDFAsComb_mc_ord->SetLineWidth(4) ;
 gr_PDFAsComb_mc_ord_M->SetLineWidth(4) ;

   gr_PDFAsComb_mc_ord->SetMarkerStyle(7) ;
 gr_PDFAsComb_mc_ord_M->SetMarkerStyle(7) ;

    gr_PDF4LHC15_mc_ord->Draw("same");      gr_AlphaS_mc->Draw("same");
  gr_PDF4LHC15_mc_ord_M->Draw("same");    gr_AlphaS_mc_M->Draw("same");

    gr_PDFAsComb_mc_ord->Draw("samelp");
  gr_PDFAsComb_mc_ord_M->Draw("samelp");

  c1->SetGrid();
  TLegend *lgd1 = new TLegend(0.15,0.15,0.35,0.35);
  lgd1->SetFillStyle(0);
  lgd1->SetBorderSize(0);
  lgd1->SetTextSize(0.03);
  lgd1->SetTextFont(42);
  lgd1->SetHeader("PDF4LHC15_mc(Re-ordering method)");
  lgd1->AddEntry( gr_PDF4LHC15_mc_ord, "PDF Uncertainties" , "L" ) ;
  lgd1->AddEntry(        gr_AlphaS_mc, "#alpha_{S} Uncertainties" , "L" ) ;
  lgd1->AddEntry( gr_PDFAsComb_mc_ord, "Combined PDF+#alpha_{S} Uncertainties" , "LP" ) ;
  lgd1->Draw();

  TLatex* t1 = new TLatex();
  t1->SetNDC();
  t1->SetTextColor(1);
  t1->SetTextSize(0.030);
  //t1->DrawLatex(0.18,0.84,"#color[1]{#scale[1.2]{CMS Preliminary}}");
  t1->DrawLatex(0.13,0.85,"#color[1]{#scale[1.2]{#splitline{PDF4LHC15_nnlo_mc @ 68% C.L.}{WprimeToLNu}}}");

  TCanvas* c2 = new TCanvas("c2", "", 800, 800);
  c2->SetFillColor(0);
  c2->SetLeftMargin(L/W);
  c2->SetRightMargin(R/W);
  c2->SetTopMargin(T/H);
  c2->SetBottomMargin(B/H);

  TH2D *null2 = new TH2D("null2", "null2", 2, lM , hM , 2, -30, 30);
  null2->SetStats(kFALSE);
  null2->SetLineColor(0);
  null2->GetYaxis()->SetTitle("Uncertainty (%)");
  null2->SetTitleSize(0.010);
  null2->SetTitle("PDF4LHC15_mc (Standard deviation)");
  null2->GetXaxis()->SetTitle("M_{W'} (TeV/c^{2})");
  null2->GetXaxis()->SetTitleSize(0.05);
  null2->GetXaxis()->SetTickLength(-0.015);
  null2->GetXaxis()->SetLabelOffset(0.01);
  null2->GetXaxis()->SetTitleFont(42);
  null2->GetXaxis()->SetLabelSize(0.04);
  null2->GetXaxis()->SetTitleOffset(1);
  null2->GetYaxis()->SetTitleSize(0.05);
  null2->GetYaxis()->SetTickLength(-0.015);
  null2->GetYaxis()->SetLabelOffset(0.01);
  null2->GetYaxis()->SetTitleFont(42);
  null2->GetYaxis()->SetLabelSize(0.04);
  null2->GetYaxis()->SetTitleOffset(1.1);
  null2->Draw();

    gr_PDF4LHC15_mc_std->SetLineStyle(1) ;     gr_PDF4LHC15_mc_std->SetLineColor(kSpring+2) ;
  gr_PDF4LHC15_mc_std_M->SetLineStyle(1) ;   gr_PDF4LHC15_mc_std_M->SetLineColor(kSpring+2) ;
           gr_AlphaS_mc->SetLineStyle(8) ;            gr_AlphaS_mc->SetLineColor(kYellow-3) ;
         gr_AlphaS_mc_M->SetLineStyle(8) ;          gr_AlphaS_mc_M->SetLineColor(kYellow-3) ;
    gr_PDFAsComb_mc_std->SetLineStyle(7) ;     gr_PDFAsComb_mc_std->SetLineColor(kTeal+9  ) ;
  gr_PDFAsComb_mc_std_M->SetLineStyle(7) ;   gr_PDFAsComb_mc_std_M->SetLineColor(kTeal+9  ) ;

   gr_PDF4LHC15_mc_std->SetLineWidth(2) ;
 gr_PDF4LHC15_mc_std_M->SetLineWidth(2) ;
          gr_AlphaS_mc->SetLineWidth(2) ;
        gr_AlphaS_mc_M->SetLineWidth(2) ;
   gr_PDFAsComb_mc_std->SetLineWidth(4) ;
 gr_PDFAsComb_mc_std_M->SetLineWidth(4) ;

   gr_PDFAsComb_mc_std->SetMarkerStyle(7) ;
 gr_PDFAsComb_mc_std_M->SetMarkerStyle(7) ;

   gr_PDF4LHC15_mc_std->Draw("same") ;
 gr_PDF4LHC15_mc_std_M->Draw("same") ;
          gr_AlphaS_mc->Draw("same") ;
        gr_AlphaS_mc_M->Draw("same") ;
   gr_PDFAsComb_mc_std->Draw("samelp") ;
 gr_PDFAsComb_mc_std_M->Draw("samelp") ;

  c2->SetGrid();

  TLegend *lgd2 = new TLegend(0.15,0.15,0.38,0.38);
  lgd2->SetFillStyle(0);
  lgd2->SetBorderSize(0);
  lgd2->SetTextSize(0.03);
  lgd2->SetHeader("PDF4LHC15_mc (Standard deviation)");
  lgd2->AddEntry( gr_PDF4LHC15_mc_std, "PDF Uncertainties" , "L" ) ;
  lgd2->AddEntry(        gr_AlphaS_mc, "#alpha_{S} Uncertainties" , "L" ) ;
  lgd2->AddEntry( gr_PDFAsComb_mc_std, "Combined PDF+#alpha_{S} Uncertainties" , "LP" ) ;
  lgd2->Draw();

  TLatex*   t2 = new TLatex();
  t2->SetNDC();
  t2->SetTextColor(14);
  t2->SetTextSize(0.030);
//  t2->DrawLatex(0.18,0.84,"#color[1]{#scale[1.2]{CMS Preliminary}}");
  t2->DrawLatex(0.13,0.85,"#color[1]{#scale[1.2]{#splitline{PDF4LHC15_nnlo_mc @ 68% C.L.}{WprimeToLNu}}}");

  TCanvas* c3 = new TCanvas("c3","",800,800);
  c3->SetFillColor(0);
  c3->SetLeftMargin(L/W);
  c3->SetRightMargin(R/W);
  c3->SetTopMargin(T/H);
  c3->SetBottomMargin(B/H);

  TH2D *null3 = new TH2D("null3", "null3", 2, lM , hM , 2, -30, 30);
  null3->SetStats(kFALSE);
  null3->SetLineColor(0);
  null3->GetYaxis()->SetTitle("Uncertainty (%)");
  null3->SetTitleSize(0.010);
  null3->SetTitle("PDF4LHC15_100_hessian (Standard deviation)");
  null3->GetXaxis()->SetTitle("M_{W'} (TeV/c^{2})");
  null3->GetXaxis()->SetTitleSize(0.05);
  null3->GetXaxis()->SetTickLength(-0.015);
  null3->GetXaxis()->SetLabelOffset(0.01);
  null3->GetXaxis()->SetTitleFont(42);
  null3->GetXaxis()->SetLabelSize(0.04);
  null3->GetXaxis()->SetTitleOffset(1);
  null3->GetYaxis()->SetTitleSize(0.05);
  null3->GetYaxis()->SetTickLength(-0.015);
  null3->GetYaxis()->SetLabelOffset(0.01);
  null3->GetYaxis()->SetTitleFont(42);
  null3->GetYaxis()->SetLabelSize(0.04);
  null3->GetYaxis()->SetTitleOffset(1.1);
  null3->Draw();

    gr_PDF4LHC15_he_100->SetLineStyle(1) ;     gr_PDF4LHC15_he_100->SetLineColor(kOrange-3) ;
  gr_PDF4LHC15_he_100_M->SetLineStyle(1) ;   gr_PDF4LHC15_he_100_M->SetLineColor(kOrange-3) ;
          gr_AlphaS_100->SetLineStyle(8) ;           gr_AlphaS_100->SetLineColor(kYellow-3) ;
        gr_AlphaS_100_M->SetLineStyle(8) ;         gr_AlphaS_100_M->SetLineColor(kYellow-3) ;
       gr_PDFAsComb_100->SetLineStyle(7) ;        gr_PDFAsComb_100->SetLineColor(kOrange+4) ;
     gr_PDFAsComb_100_M->SetLineStyle(7) ;      gr_PDFAsComb_100_M->SetLineColor(kOrange+4) ;

   gr_PDF4LHC15_he_100->SetLineWidth(2) ;
 gr_PDF4LHC15_he_100_M->SetLineWidth(2) ;
         gr_AlphaS_100->SetLineWidth(2) ;
       gr_AlphaS_100_M->SetLineWidth(2) ;
      gr_PDFAsComb_100->SetLineWidth(4) ;
    gr_PDFAsComb_100_M->SetLineWidth(4) ;

      gr_PDFAsComb_100->SetMarkerStyle(7) ;
    gr_PDFAsComb_100_M->SetMarkerStyle(7) ;

   gr_PDF4LHC15_he_100->Draw("same") ;
 gr_PDF4LHC15_he_100_M->Draw("same") ;
         gr_AlphaS_100->Draw("same") ;
       gr_AlphaS_100_M->Draw("same") ;
      gr_PDFAsComb_100->Draw("samelp") ;
    gr_PDFAsComb_100_M->Draw("samelp") ;

  c3->SetGrid();
  TLegend *lgd3 = new TLegend(0.18,0.18,0.35,0.35);
  lgd3->SetFillStyle(0);
  lgd3->SetBorderSize(0);
  lgd3->SetTextSize(0.03);
  lgd3->SetHeader("PDF4LHC15_100 (Standard deviation)");
  lgd3->AddEntry(gr_PDF4LHC15_he_100, "PDF Uncertainties" , "L" ) ;
  lgd3->AddEntry(      gr_AlphaS_100, "#alpha_{S} Uncertainties" , "L" ) ;
  lgd3->AddEntry(   gr_PDFAsComb_100, "Combined PDF+#alpha_{S} Uncertainties" , "LP" ) ;
  lgd3->Draw();

  TLatex*   t3 = new TLatex();
  t3->SetNDC();
  t3->SetTextColor(14);
  t3->SetTextSize(0.030);
//  t3->DrawLatex(0.18,0.84,"#color[1]{#scale[1.2]{CMS Preliminary}}");
  t3->DrawLatex(0.13,0.85,"#color[1]{#scale[1.2]{#splitline{PDF4LHC15_nnlo_100_hessian @ 68% C.L.}{WprimeToNLu}}}");

  TCanvas* c4 = new TCanvas("c4","",800, 800);
  c4->SetFillColor(0);
  c4->SetLeftMargin(L/W);
  c4->SetRightMargin(R/W);
  c4->SetTopMargin(T/H);
  c4->SetBottomMargin(B/H);

  TH2D *null4 = new TH2D("null4", "null4", 2, lM , hM , 2, -30, 30);
  null4->SetStats(kFALSE);
  null4->SetLineColor(0);
  null4->GetYaxis()->SetTitle("Uncertainty (%)");
  null4->SetTitleSize(0.010);
  null4->SetTitle("PDF4LHC15_30_Hessian set (Standard deviation)");
  null4->GetXaxis()->SetTitle("M_{W'} (TeV/c^{2})");
  null4->GetXaxis()->SetTitleSize(0.05);
  null4->GetXaxis()->SetTickLength(-0.015);
  null4->GetXaxis()->SetLabelOffset(0.01);
  null4->GetXaxis()->SetTitleFont(42);
  null4->GetXaxis()->SetLabelSize(0.04);
  null4->GetXaxis()->SetTitleOffset(1);
  null4->GetYaxis()->SetTitleSize(0.05);
  null4->GetYaxis()->SetTickLength(-0.015);
  null4->GetYaxis()->SetLabelOffset(0.01);
  null4->GetYaxis()->SetTitleFont(42);
  null4->GetYaxis()->SetLabelSize(0.04);
  null4->GetYaxis()->SetTitleOffset(1.1);
  null4->Draw();

    gr_PDF4LHC15_he_30->SetLineStyle(1) ;     gr_PDF4LHC15_he_30->SetLineColor(kViolet-9) ;
  gr_PDF4LHC15_he_30_M->SetLineStyle(1) ;   gr_PDF4LHC15_he_30_M->SetLineColor(kViolet-9) ;
          gr_AlphaS_30->SetLineStyle(8) ;           gr_AlphaS_30->SetLineColor(kYellow-3) ;
        gr_AlphaS_30_M->SetLineStyle(8) ;         gr_AlphaS_30_M->SetLineColor(kYellow-3) ;
       gr_PDFAsComb_30->SetLineStyle(7) ;        gr_PDFAsComb_30->SetLineColor(kViolet-1) ;
     gr_PDFAsComb_30_M->SetLineStyle(7) ;      gr_PDFAsComb_30_M->SetLineColor(kViolet-1) ;

   gr_PDF4LHC15_he_30->SetLineWidth(2) ;
 gr_PDF4LHC15_he_30_M->SetLineWidth(2) ;
         gr_AlphaS_30->SetLineWidth(2) ;
       gr_AlphaS_30_M->SetLineWidth(2) ;
      gr_PDFAsComb_30->SetLineWidth(4) ;
    gr_PDFAsComb_30_M->SetLineWidth(4) ;
      gr_PDFAsComb_30->SetMarkerStyle(7) ;
    gr_PDFAsComb_30_M->SetMarkerStyle(7) ;

   gr_PDF4LHC15_he_30->Draw("same") ;
 gr_PDF4LHC15_he_30_M->Draw("same") ;
         gr_AlphaS_30->Draw("same") ;
       gr_AlphaS_30_M->Draw("same") ;
      gr_PDFAsComb_30->Draw("samelp") ;
    gr_PDFAsComb_30_M->Draw("samelp") ;

  c4->SetGrid();
  TLegend *lgd4 = new TLegend(0.18,0.18,0.35,0.35);
  lgd4->SetFillStyle(0);
  lgd4->SetBorderSize(0);
  lgd4->SetTextSize(0.03);
  lgd4->SetHeader("PDF4LHC15_30 (Standard deviation)");
  lgd4->AddEntry(gr_PDF4LHC15_he_30, "PDF Uncertainties" , "L" ) ;
  lgd4->AddEntry(      gr_AlphaS_30, "#alpha_{S} Uncertainties" , "L" ) ;
  lgd4->AddEntry(   gr_PDFAsComb_30, "Combined PDF+#alpha_{S} Uncertainties" , "LP" ) ;
  lgd4->Draw();

  TLatex*   t4 = new TLatex();
  t4->SetNDC();
  t4->SetTextColor(14);
  t4->SetTextSize(0.030);
//  t4->DrawLatex(0.18,0.84,"#color[1]{#scale[1.2]{CMS Preliminary}}");
  t4->DrawLatex(0.13,0.85,"#color[1]{#scale[1.2]{#splitline{PDF4LHC15_nnlo_30_hessian @ 68% C.L.}{WprimeToLNu}}}");

}
