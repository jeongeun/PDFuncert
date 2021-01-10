#include "TGraph.h"
#include "TMath.h"
#include "tdrstyle.C"
#include "TLatex.h"

void graph_hes(){

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


 AlphaS_100[0] = 0.00669325  ; 
 AlphaS_30[0] = 0.00669325  ; 
 AlphaS_mc[0] = 0.00669325  ; 
 BestFit100[0] = 0.980438  ; 
 Best_Fit30[0] = 0.980442  ; 
 mcBest_Fit[0] = 0.978755  ; 
 mc_STDMean[0] =  0.978706  ; 
 PDF4LHC15_he_100[0] = 0.0163954  ;  //Standard deviation
 PDF4LHC15_he_30[0] = 0.014836  ;  //Standard deviation
 PDF4LHC15_mc_ord[0] = 0.0404978  ; //Re-ordering 
 PDF4LHC15_mc_std[0] = 0.0169027  ; //Standard deviation 
 Reordering[0] = 0.932431  ; 
 STDMean100[0] = 0.980511  ; 
 STDMean_30[0] = 0.980576  ; 
 AlphaS_100[1] = 0.0038837  ; 
 AlphaS_30[1] = 0.0038837  ; 
 AlphaS_mc[1] = 0.0038837  ; 
 BestFit100[1] = 0.977411  ; 
 Best_Fit30[1] = 0.977418  ; 
 mcBest_Fit[1] = 0.97649  ; 
 mc_STDMean[1] =  0.97644  ; 
 PDF4LHC15_he_100[1] = 0.0169219  ;  //Standard deviation
 PDF4LHC15_he_30[1] = 0.0158943  ;  //Standard deviation
 PDF4LHC15_mc_ord[1] = 0.0405926  ; //Re-ordering 
 PDF4LHC15_mc_std[1] = 0.0167088  ; //Standard deviation 
 Reordering[1] = 0.941813  ; 
 STDMean100[1] = 0.977442  ; 
 STDMean_30[1] = 0.977509  ; 
 AlphaS_100[2] = 0.00171697  ; 
 AlphaS_30[2] = 0.00171697  ; 
 AlphaS_mc[2] = 0.00171697  ; 
 BestFit100[2] = 0.974509  ; 
 Best_Fit30[2] = 0.974515  ; 
 mcBest_Fit[2] = 0.974095  ; 
 mc_STDMean[2] =  0.97407  ; 
 PDF4LHC15_he_100[2] = 0.0193771  ;  //Standard deviation
 PDF4LHC15_he_30[2] = 0.0185826  ;  //Standard deviation
 PDF4LHC15_mc_ord[2] = 0.0411  ; //Re-ordering 
 PDF4LHC15_mc_std[2] = 0.0187078  ; //Standard deviation 
 Reordering[2] = 0.945498  ; 
 STDMean100[2] = 0.974491  ; 
 STDMean_30[2] = 0.974614  ; 
 AlphaS_100[3] = -1.19587e-05  ; 
 AlphaS_30[3] = -1.19587e-05  ; 
 AlphaS_mc[3] = -1.19587e-05  ; 
 BestFit100[3] = 0.974826  ; 
 Best_Fit30[3] = 0.97483  ; 
 mcBest_Fit[3] = 0.974651  ; 
 mc_STDMean[3] =  0.974639  ; 
 PDF4LHC15_he_100[3] = 0.0226691  ;  //Standard deviation
 PDF4LHC15_he_30[3] = 0.0217301  ;  //Standard deviation
 PDF4LHC15_mc_ord[3] = 0.0394126  ; //Re-ordering 
 PDF4LHC15_mc_std[3] = 0.021713  ; //Standard deviation 
 Reordering[3] = 0.948942  ; 
 STDMean100[3] = 0.974789  ; 
 STDMean_30[3] = 0.974944  ; 
  AlphaS_100[4] = -0.00164702  ; 
  AlphaS_30[4] = -0.00164702  ; 
  AlphaS_mc[4] = -0.00164702  ; 
  BestFit100[4] = 0.974602  ; 
  Best_Fit30[4] = 0.974604  ; 
  mcBest_Fit[4] = 0.974623  ; 
  mc_STDMean[4] =  0.974635  ; 
  PDF4LHC15_he_100[4] = 0.0263789  ;  //Standard deviation
  PDF4LHC15_he_30[4] = 0.0251519  ;  //Standard deviation
  PDF4LHC15_mc_ord[4] = 0.0386291  ; //Re-ordering 
  PDF4LHC15_mc_std[4] = 0.0254059  ; //Standard deviation 
  Reordering[4] = 0.952184  ; 
  STDMean100[4] = 0.974565  ; 
  STDMean_30[4] = 0.974784  ; 
  AlphaS_100[5] = -0.00293462  ; 
  AlphaS_30[5] = -0.00293462  ; 
  AlphaS_mc[5] = -0.00293462  ; 
  BestFit100[5] = 0.974922  ; 
  Best_Fit30[5] = 0.974923  ; 
  mcBest_Fit[5] = 0.975095  ; 
  mc_STDMean[5] =  0.975119  ; 
  PDF4LHC15_he_100[5] = 0.0298585  ;  //Standard deviation
  PDF4LHC15_he_30[5] = 0.0282073  ;  //Standard deviation
  PDF4LHC15_mc_ord[5] = 0.0365583  ; //Re-ordering 
  PDF4LHC15_mc_std[5] = 0.0288325  ; //Standard deviation 
  Reordering[5] = 0.954001  ; 
  STDMean100[5] = 0.9749  ; 
  STDMean_30[5] = 0.975161  ; 
  AlphaS_100[6] = -0.00412653  ; 
  AlphaS_30[6] = -0.00412653  ; 
  AlphaS_mc[6] = -0.00412653  ; 
  BestFit100[6] = 0.97779  ; 
  Best_Fit30[6] = 0.977791  ; 
  mcBest_Fit[6] = 0.978072  ; 
  mc_STDMean[6] =  0.978109  ; 
  PDF4LHC15_he_100[6] = 0.0335927  ;  //Standard deviation
  PDF4LHC15_he_30[6] = 0.0316038  ;  //Standard deviation
  PDF4LHC15_mc_ord[6] = 0.036005  ; //Re-ordering 
  PDF4LHC15_mc_std[6] = 0.0325414  ; //Standard deviation 
  Reordering[6] = 0.959056  ; 
  STDMean100[6] = 0.977798  ; 
  STDMean_30[6] = 0.978081  ; 
  AlphaS_100[7] = -0.00527003  ; 
  AlphaS_30[7] = -0.00527003  ; 
  AlphaS_mc[7] = -0.00527003  ; 
  BestFit100[7] = 0.978252  ; 
  Best_Fit30[7] = 0.978256  ; 
  mcBest_Fit[7] = 0.978457  ; 
  mc_STDMean[7] =  0.9785  ; 
  PDF4LHC15_he_100[7] = 0.0368739  ;  //Standard deviation
  PDF4LHC15_he_30[7] = 0.0345781  ;  //Standard deviation
  PDF4LHC15_mc_ord[7] = 0.0337732  ; //Re-ordering 
  PDF4LHC15_mc_std[7] = 0.0355609  ; //Standard deviation 
  Reordering[7] = 0.960089  ; 
  STDMean100[7] = 0.978305  ; 
  STDMean_30[7] = 0.978617  ; 
  AlphaS_100[8] = -0.00620095  ; 
  AlphaS_30[8] = -0.00620095  ; 
  AlphaS_mc[8] = -0.00620095  ; 
  BestFit100[8] = 0.979966  ; 
  Best_Fit30[8] = 0.979971  ; 
  mcBest_Fit[8] = 0.980036  ; 
  mc_STDMean[8] =  0.980104  ; 
  PDF4LHC15_he_100[8] = 0.0401401  ;  //Standard deviation
  PDF4LHC15_he_30[8] = 0.0376167  ;  //Standard deviation
  PDF4LHC15_mc_ord[8] = 0.032653  ; //Re-ordering 
  PDF4LHC15_mc_std[8] = 0.0387382  ; //Standard deviation 
  Reordering[8] = 0.961878  ; 
  STDMean100[8] = 0.980072  ; 
  STDMean_30[8] = 0.980386  ; 
  AlphaS_100[9] = -0.00737541  ; 
  AlphaS_30[9] = -0.00737541  ; 
  AlphaS_mc[9] = -0.00737541  ; 
  BestFit100[9] = 0.978803  ; 
  Best_Fit30[9] = 0.978809  ; 
  mcBest_Fit[9] = 0.978657  ; 
  mc_STDMean[9] =  0.978712  ; 
  PDF4LHC15_he_100[9] = 0.0436343  ;  //Standard deviation
  PDF4LHC15_he_30[9] = 0.0405713  ;  //Standard deviation
  PDF4LHC15_mc_ord[9] = 0.0390647  ; //Re-ordering 
  PDF4LHC15_mc_std[9] = 0.0426579  ; //Standard deviation 
  Reordering[9] = 0.962075  ; 
  STDMean100[9] = 0.979012  ; 
  STDMean_30[9] = 0.979189  ; 
  AlphaS_100[10] = -0.00819423  ; 
  AlphaS_30[10] = -0.00819423  ; 
  AlphaS_mc[10] = -0.00819423  ; 
  BestFit100[10] = 0.979501  ; 
  Best_Fit30[10] = 0.979507  ; 
  mcBest_Fit[10] = 0.979063  ; 
  mc_STDMean[10] =  0.979116  ; 
  PDF4LHC15_he_100[10] = 0.0458573  ;  //Standard deviation
  PDF4LHC15_he_30[10] = 0.0424348  ;  //Standard deviation
  PDF4LHC15_mc_ord[10] = 0.0392031  ; //Re-ordering 
  PDF4LHC15_mc_std[10] = 0.0449585  ; //Standard deviation 
  Reordering[10] = 0.962324  ; 
  STDMean100[10] = 0.979784  ; 
  STDMean_30[10] = 0.979967  ; 
  AlphaS_100[11] = -0.00898606  ; 
  AlphaS_30[11] = -0.00898606  ; 
  AlphaS_mc[11] = -0.00898606  ; 
  BestFit100[11] = 0.981355  ; 
  Best_Fit30[11] = 0.981363  ; 
  mcBest_Fit[11] = 0.980411  ; 
  mc_STDMean[11] =  0.980486  ; 
  PDF4LHC15_he_100[11] = 0.0496304  ;  //Standard deviation
  PDF4LHC15_he_30[11] = 0.0453577  ;  //Standard deviation
  PDF4LHC15_mc_ord[11] = 0.045696  ; //Re-ordering 
  PDF4LHC15_mc_std[11] = 0.0496328  ; //Standard deviation 
  Reordering[11] = 0.966578  ; 
  STDMean100[11] = 0.981777  ; 
  STDMean_30[11] = 0.981638  ; 
  AlphaS_100[12] = -0.0097199  ; 
  AlphaS_30[12] = -0.0097199  ; 
  AlphaS_mc[12] = -0.0097199  ; 
  BestFit100[12] = 0.978992  ; 
  Best_Fit30[12] = 0.979004  ; 
  mcBest_Fit[12] = 0.977706  ; 
  mc_STDMean[12] =  0.977782  ; 
  PDF4LHC15_he_100[12] = 0.0531044  ;  //Standard deviation
  PDF4LHC15_he_30[12] = 0.0470366  ;  //Standard deviation
  PDF4LHC15_mc_ord[12] = 0.0502916  ; //Re-ordering 
  PDF4LHC15_mc_std[12] = 0.0538947  ; //Standard deviation 
  Reordering[12] = 0.964707  ; 
  STDMean100[12] = 0.979556  ; 
  STDMean_30[12] = 0.979196  ; 
  AlphaS_100[13] = -0.0099353  ; 
  AlphaS_30[13] = -0.0099353  ; 
  AlphaS_mc[13] = -0.0099353  ; 
  BestFit100[13] = 0.976936  ; 
  Best_Fit30[13] = 0.976949  ; 
  mcBest_Fit[13] = 0.975379  ; 
  mc_STDMean[13] =  0.975453  ; 
  PDF4LHC15_he_100[13] = 0.0563676  ;  //Standard deviation
  PDF4LHC15_he_30[13] = 0.0478075  ;  //Standard deviation
  PDF4LHC15_mc_ord[13] = 0.0531165  ; //Re-ordering 
  PDF4LHC15_mc_std[13] = 0.0577342  ; //Standard deviation 
  Reordering[13] = 0.962594  ; 
  STDMean100[13] = 0.97763  ; 
  STDMean_30[13] = 0.977011  ; 
  AlphaS_100[14] = -0.0108643  ; 
  AlphaS_30[14] = -0.0108643  ; 
  AlphaS_mc[14] = -0.0108643  ; 
  BestFit100[14] = 0.968592  ; 
  Best_Fit30[14] = 0.968602  ; 
  mcBest_Fit[14] = 0.966792  ; 
  mc_STDMean[14] =  0.966787  ; 
  PDF4LHC15_he_100[14] = 0.0623244  ;  //Standard deviation
  PDF4LHC15_he_30[14] = 0.0495094  ;  //Standard deviation
  PDF4LHC15_mc_ord[14] = 0.0655793  ; //Re-ordering 
  PDF4LHC15_mc_std[14] = 0.0646169  ; //Standard deviation 
  Reordering[14] = 0.95255  ; 
  STDMean100[14] = 0.969475  ; 
  STDMean_30[14] = 0.968626  ; 
  AlphaS_100[15] = -0.0108959  ; 
  AlphaS_30[15] = -0.0108959  ; 
  AlphaS_mc[15] = -0.0108959  ; 
  BestFit100[15] = 0.958377  ; 
  Best_Fit30[15] = 0.958385  ; 
  mcBest_Fit[15] = 0.956877  ; 
  mc_STDMean[15] =  0.956798  ; 
  PDF4LHC15_he_100[15] = 0.0704463  ;  //Standard deviation
  PDF4LHC15_he_30[15] = 0.0501419  ;  //Standard deviation
  PDF4LHC15_mc_ord[15] = 0.0843267  ; //Re-ordering 
  PDF4LHC15_mc_std[15] = 0.0738395  ; //Standard deviation 
  Reordering[15] = 0.94298  ; 
  STDMean100[15] = 0.959509  ; 
  STDMean_30[15] = 0.95817  ; 
  AlphaS_100[16] = -0.0103461  ; 
  AlphaS_30[16] = -0.0103461  ; 
  AlphaS_mc[16] = -0.0103461  ; 
  BestFit100[16] = 0.951191  ; 
  Best_Fit30[16] = 0.951197  ; 
  mcBest_Fit[16] = 0.94972  ; 
  mc_STDMean[16] =  0.94959  ; 
  PDF4LHC15_he_100[16] = 0.0757121  ;  //Standard deviation
  PDF4LHC15_he_30[16] = 0.050118  ;  //Standard deviation
  PDF4LHC15_mc_ord[16] = 0.0848401  ; //Re-ordering 
  PDF4LHC15_mc_std[16] = 0.0790975  ; //Standard deviation 
  Reordering[16] = 0.936195  ; 
  STDMean100[16] = 0.952425  ; 
  STDMean_30[16] = 0.950848  ; 
  AlphaS_100[17] = -0.0104165  ; 
  AlphaS_30[17] = -0.0104165  ; 
  AlphaS_mc[17] = -0.0104165  ; 
  BestFit100[17] = 0.930519  ; 
  Best_Fit30[17] = 0.930523  ; 
  mcBest_Fit[17] = 0.929696  ; 
  mc_STDMean[17] =  0.929463  ; 
  PDF4LHC15_he_100[17] = 0.0893241  ;  //Standard deviation
  PDF4LHC15_he_30[17] = 0.0534648  ;  //Standard deviation
  PDF4LHC15_mc_ord[17] = 0.101842  ; //Re-ordering 
  PDF4LHC15_mc_std[17] = 0.0926719  ; //Standard deviation 
  Reordering[17] = 0.908716  ; 
  STDMean100[17] = 0.931999  ; 
  STDMean_30[17] = 0.930032  ; 
  AlphaS_100[18] = -0.00990883  ; 
  AlphaS_30[18] = -0.00990883  ; 
  AlphaS_mc[18] = -0.00990883  ; 
  BestFit100[18] = 0.915663  ; 
  Best_Fit30[18] = 0.915665  ; 
  mcBest_Fit[18] = 0.915533  ; 
  mc_STDMean[18] =  0.915193  ; 
  PDF4LHC15_he_100[18] = 0.0963444  ;  //Standard deviation
  PDF4LHC15_he_30[18] = 0.0543051  ;  //Standard deviation
  PDF4LHC15_mc_ord[18] = 0.109142  ; //Re-ordering 
  PDF4LHC15_mc_std[18] = 0.099673  ; //Standard deviation 
  Reordering[18] = 0.891703  ; 
  STDMean100[18] = 0.917233  ; 
  STDMean_30[18] = 0.915299  ; 
  AlphaS_100[19] = -0.00928125  ; 
  AlphaS_30[19] = -0.00928125  ; 
  AlphaS_mc[19] = -0.00928125  ; 
  BestFit100[19] = 0.894136  ; 
  Best_Fit30[19] = 0.894139  ; 
  mcBest_Fit[19] = 0.894919  ; 
  mc_STDMean[19] =  0.894594  ; 
  PDF4LHC15_he_100[19] = 0.111198  ;  //Standard deviation
  PDF4LHC15_he_30[19] = 0.0598027  ;  //Standard deviation
  PDF4LHC15_mc_ord[19] = 0.133632  ; //Re-ordering 
  PDF4LHC15_mc_std[19] = 0.114334  ; //Standard deviation 
  Reordering[19] = 0.872131  ; 
  STDMean100[19] = 0.895952  ; 
  STDMean_30[19] = 0.893538  ; 
  AlphaS_100[20] = -0.00853357  ; 
  AlphaS_30[20] = -0.00853357  ; 
  AlphaS_mc[20] = -0.00853357  ; 
  BestFit100[20] = 0.872664  ; 
  Best_Fit30[20] = 0.872668  ; 
  mcBest_Fit[20] = 0.87417  ; 
  mc_STDMean[20] =  0.873778  ; 
  PDF4LHC15_he_100[20] = 0.122429  ;  //Standard deviation
  PDF4LHC15_he_30[20] = 0.0632018  ;  //Standard deviation
  PDF4LHC15_mc_ord[20] = 0.144056  ; //Re-ordering 
  PDF4LHC15_mc_std[20] = 0.125285  ; //Standard deviation 
  Reordering[20] = 0.843124  ; 
  STDMean100[20] = 0.874601  ; 
  STDMean_30[20] = 0.872166  ; 
  AlphaS_100[21] = -0.00753643  ; 
  AlphaS_30[21] = -0.00753643  ; 
  AlphaS_mc[21] = -0.00753643  ; 
  BestFit100[21] = 0.857318  ; 
  Best_Fit30[21] = 0.857325  ; 
  mcBest_Fit[21] = 0.859665  ; 
  mc_STDMean[21] =  0.859368  ; 
  PDF4LHC15_he_100[21] = 0.128642  ;  //Standard deviation
  PDF4LHC15_he_30[21] = 0.0660316  ;  //Standard deviation
  PDF4LHC15_mc_ord[21] = 0.153005  ; //Re-ordering 
  PDF4LHC15_mc_std[21] = 0.131192  ; //Standard deviation 
  Reordering[21] = 0.827621  ; 
  STDMean100[21] = 0.8593  ; 
  STDMean_30[21] = 0.856871  ; 
  AlphaS_100[22] = -0.00683713  ; 
  AlphaS_30[22] = -0.00683713  ; 
  AlphaS_mc[22] = -0.00683713  ; 
  BestFit100[22] = 0.839557  ; 
  Best_Fit30[22] = 0.839563  ; 
  mcBest_Fit[22] = 0.842761  ; 
  mc_STDMean[22] =  0.84249  ; 
  PDF4LHC15_he_100[22] = 0.136622  ;  //Standard deviation
  PDF4LHC15_he_30[22] = 0.0722238  ;  //Standard deviation
  PDF4LHC15_mc_ord[22] = 0.170493  ; //Re-ordering 
  PDF4LHC15_mc_std[22] = 0.139389  ; //Standard deviation 
  Reordering[22] = 0.81056  ; 
  STDMean100[22] = 0.841628  ; 
  STDMean_30[22] = 0.839168  ; 
  AlphaS_100[23] = -0.00622413  ; 
  AlphaS_30[23] = -0.00622413  ; 
  AlphaS_mc[23] = -0.00622413  ; 
  BestFit100[23] = 0.819625  ; 
  Best_Fit30[23] = 0.819634  ; 
  mcBest_Fit[23] = 0.823494  ; 
  mc_STDMean[23] =  0.823328  ; 
  PDF4LHC15_he_100[23] = 0.14228  ;  //Standard deviation
  PDF4LHC15_he_30[23] = 0.0756864  ;  //Standard deviation
  PDF4LHC15_mc_ord[23] = 0.178032  ; //Re-ordering 
  PDF4LHC15_mc_std[23] = 0.144609  ; //Standard deviation 
  Reordering[23] = 0.790646  ; 
  STDMean100[23] = 0.821706  ; 
  STDMean_30[23] = 0.819365  ; 
  AlphaS_100[24] = -0.00620267  ; 
  AlphaS_30[24] = -0.00620267  ; 
  AlphaS_mc[24] = -0.00620267  ; 
  BestFit100[24] = 0.817074  ; 
  Best_Fit30[24] = 0.817086  ; 
  mcBest_Fit[24] = 0.821585  ; 
  mc_STDMean[24] =  0.821621  ; 
  PDF4LHC15_he_100[24] = 0.146628  ;  //Standard deviation
  PDF4LHC15_he_30[24] = 0.0768194  ;  //Standard deviation
  PDF4LHC15_mc_ord[24] = 0.213337  ; //Re-ordering 
  PDF4LHC15_mc_std[24] = 0.151259  ; //Standard deviation 
  Reordering[24] = 0.797562  ; 
  STDMean100[24] = 0.819276  ; 
  STDMean_30[24] = 0.81692  ; 
  AlphaS_100[25] = -0.00520267  ; 
  AlphaS_30[25] = -0.00520267  ; 
  AlphaS_mc[25] = -0.00520267  ; 
  BestFit100[25] = 0.81074  ; 
  Best_Fit30[25] = 0.81086  ; 
  mcBest_Fit[25] = 0.81585  ; 
  mc_STDMean[25] =  0.81621  ; 
  PDF4LHC15_he_100[25] = 0.14  ;  //Standard deviation
  PDF4LHC15_he_30[25] = 0.07568194  ;  //Standard deviation
  PDF4LHC15_mc_ord[25] = 0.193337  ; //Re-ordering 
  PDF4LHC15_mc_std[25] = 0.141259  ; //Standard deviation 
  Reordering[25] = 0.7897562  ; 
  STDMean100[25] = 0.81276  ; 
  STDMean_30[25] = 0.812  ; 
 AlphaS_100[26] = -0.00442445  ; 
 AlphaS_30[26] = -0.00442445  ; 
 AlphaS_mc[26] = -0.00442445  ; 
 BestFit100[26] = 0.805952  ; 
 Best_Fit30[26] = 0.805961  ; 
 mcBest_Fit[26] = 0.810513  ; 
 mc_STDMean[26] =  0.810694  ; 
 PDF4LHC15_he_100[26] = 0.135154  ;  //Standard deviation
 PDF4LHC15_he_30[26] = 0.0749842  ;  //Standard deviation
 PDF4LHC15_mc_ord[26] = 0.176862  ; //Re-ordering 
 PDF4LHC15_mc_std[26] = 0.138239  ; //Standard deviation 
 Reordering[26] = 0.783365  ; 
 STDMean100[26] = 0.80777  ; 
 STDMean_30[26] = 0.806028  ; 
 AlphaS_100[27] = -0.00385917  ; 
 AlphaS_30[27] = -0.00385917  ; 
 AlphaS_mc[27] = -0.00385917  ; 
 BestFit100[27] = 0.809852  ; 
 Best_Fit30[27] = 0.80986  ; 
 mcBest_Fit[27] = 0.814419  ; 
 mc_STDMean[27] =  0.814587  ; 
 PDF4LHC15_he_100[27] = 0.127718  ;  //Standard deviation
 PDF4LHC15_he_30[27] = 0.0717245  ;  //Standard deviation
 PDF4LHC15_mc_ord[27] = 0.166024  ; //Re-ordering 
 PDF4LHC15_mc_std[27] = 0.130359  ; //Standard deviation 
 Reordering[27] = 0.787286  ; 
 STDMean100[27] = 0.811496  ; 
 STDMean_30[27] = 0.810142  ; 
 AlphaS_100[28] = -0.00344082  ; 
 AlphaS_30[28] = -0.00344082  ; 
 AlphaS_mc[28] = -0.00344082  ; 
 BestFit100[28] = 0.81786  ; 
 Best_Fit30[28] = 0.817867  ; 
 mcBest_Fit[28] = 0.821986  ; 
 mc_STDMean[28] =  0.822238  ; 
 PDF4LHC15_he_100[28] = 0.117327  ;  //Standard deviation
 PDF4LHC15_he_30[28] = 0.0676228  ;  //Standard deviation
 PDF4LHC15_mc_ord[28] = 0.156615  ; //Re-ordering 
 PDF4LHC15_mc_std[28] = 0.120338  ; //Standard deviation 
 Reordering[28] = 0.80478  ; 
 STDMean100[28] = 0.819336  ; 
 STDMean_30[28] = 0.818087  ; 
 AlphaS_100[29] = -0.00281412  ; 
 AlphaS_30[29] = -0.00281412  ; 
 AlphaS_mc[29] = -0.00281412  ; 
 BestFit100[29] = 0.82397  ; 
 Best_Fit30[29] = 0.823978  ; 
 mcBest_Fit[29] = 0.827937  ; 
 mc_STDMean[29] =  0.828268  ; 
 PDF4LHC15_he_100[29] = 0.11151  ;  //Standard deviation
 PDF4LHC15_he_30[29] = 0.0648572  ;  //Standard deviation
 PDF4LHC15_mc_ord[29] = 0.153338  ; //Re-ordering 
 PDF4LHC15_mc_std[29] = 0.114166  ; //Standard deviation 
 Reordering[29] = 0.814859  ; 
 STDMean100[29] = 0.825361  ; 
 STDMean_30[29] = 0.824203  ; 

 mcBest_Fit[30] = 0.841432  ;
 Reordering[30] = 0.826505  ;
 mc_STDMean[30] =  0.841695  ;
 PDF4LHC15_mc_ord[30] = 0.134215  ; //Re-ordering
 PDF4LHC15_mc_std[30] = 0.102777  ; //Standard deviation
 AlphaS_mc[30] = -0.002618  ;
 BestFit100[30] = 0.837904  ;
 STDMean100[30] = 0.83908  ;
 PDF4LHC15_he_100[30] = 0.0999672  ;  //Standard deviation
 AlphaS_100[30] = -0.002618  ;
 Best_Fit30[30] = 0.837912  ;
 STDMean_30[30] = 0.838214  ;
 PDF4LHC15_he_30[30] = 0.0591354  ;  //Standard deviation
 AlphaS_30[30] = -0.002618  ;
 mcBest_Fit[31] = 0.854652  ;
 Reordering[31] = 0.837958  ;
 mc_STDMean[31] =  0.854922  ;
 PDF4LHC15_mc_ord[31] = 0.116378  ; //Re-ordering
 PDF4LHC15_mc_std[31] = 0.0912005  ; //Standard deviation
 AlphaS_mc[31] = -0.00194391  ;
 BestFit100[31] = 0.851535  ;
 STDMean100[31] = 0.852532  ;
 PDF4LHC15_he_100[31] = 0.0888448  ;  //Standard deviation
 AlphaS_100[31] = -0.00194391  ;
 Best_Fit30[31] = 0.851542  ;
 STDMean_30[31] = 0.851921  ;
 PDF4LHC15_he_30[31] = 0.0528539  ;  //Standard deviation
 AlphaS_30[31] = -0.00194391  ;



  for(int i=0; i<midx; i++){
       Mass[i] = (200 + (200 * i)) *0.001 ;
       cout << " Wprime Mass = " << Mass[i] << " TeV/c2 --------------------" << endl;
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

       cout << "-----Cross Checking Mean value-----------" << endl;
      // cout << "MC 100      bestfit = " << mcBest_Fit[i] << " 1st stdMean = " << mc_STDMean[i] << " 2nd reOrder = " << Reordering[i] << endl;
      // cout << "Hessian 100 bestfit = " << BestFit100[i] << " stdMean = " << STDMean100[i] << endl;
      // cout << "Hessian 30  bestfit = " << Best_Fit30[i] << " stdMean = " << STDMean_30[i] << endl;
      // cout << "-----Cross Checking Unceratinties-----------" << endl;
       cout << "PDFAsComb_mc_ord  pdf = " << PDF4LHC15_mc_ord[i] << " as = " << AlphaS_mc[i] << " Combined = " << PDFAsComb_mc_ord[i] << endl;
       cout << "PDFAsComb_mc_std  pdf = " << PDF4LHC15_mc_std[i] << " as = " << AlphaS_mc[i] << " Combined = " << PDFAsComb_mc_std[i] << endl;
       cout << "PDFAsComb_100     pdf = " << PDF4LHC15_he_100[i] << " as = " << AlphaS_100[i]<< " Combined = " << PDFAsComb_100[i]    << endl;
       cout << "PDFAsComb_30      pdf = " << PDF4LHC15_he_30[i]  << " as = " << AlphaS_30[i] << " Combined = " << PDFAsComb_30[i]     << endl;
       cout << " " << endl;
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

  gr_Reordering->SetMarkerColor(kBlue)  ; gr_Reordering->SetMarkerStyle(20) ; gr_Reordering->SetMarkerSize(2) ;
  gr_mc_STDMean->SetMarkerColor(kGreen) ; gr_mc_STDMean->SetMarkerStyle(24) ; gr_mc_STDMean->SetMarkerSize(2) ;
  gr_BestFit100->SetMarkerColor(kOrange) ; gr_BestFit100->SetMarkerStyle(21) ; gr_BestFit100->SetMarkerSize(2) ;
  gr_Best_Fit30->SetMarkerColor(kViolet) ; gr_Best_Fit30->SetMarkerStyle(22) ; gr_Best_Fit30->SetMarkerSize(2) ;

  gr_Reordering->Draw("same");
  gr_mc_STDMean->Draw("samep");
  gr_BestFit100->Draw("samep");
  gr_Best_Fit30->Draw("samep");

  c0->SetGrid();
  TLegend *lgd0 = new TLegend(0.15,0.15,0.38,0.38);
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
  t0->DrawLatex(0.13,0.85,"MC sets: #bar{R} = #frac{R^{(84th)}+R^{(16th)}}{2} ");
  t0->DrawLatex(0.13,0.80,"MC sets: <R> =1/N #sum_{k=1}^{N^{mem}} R^{k}");
  t0->DrawLatex(0.13,0.75,"Hessian sets: R^{0} BestFit");

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
