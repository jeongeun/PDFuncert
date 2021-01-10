import FWCore.ParameterSet.Config as cms

ProdNpElectron = cms.EDProducer('ProdNpElectron',
   electronToken        = cms.InputTag("slimmedElectrons"),
   conversionToken      = cms.InputTag("reducedEgamma:reducedConversions"),
   beamSpotToken        = cms.InputTag("offlineBeamSpot"),
   ebReducedRecHitToken = cms.InputTag("reducedEgamma:reducedEBRecHits"),
   eeReducedRecHitToken = cms.InputTag("reducedEgamma:reducedEERecHits"),
   esReducedRecHitToken = cms.InputTag("reducedEgamma:reducedESRecHits"),
   vertexToken          = cms.InputTag("offlineSlimmedPrimaryVertices"),
   rhoToken             = cms.InputTag("fixedGridRhoFastjetAll"),
   MinPtCut = cms.untracked.double(5.0),
   genParticles = cms.InputTag('prunedGenParticles'),
   #nrSatCrysMap          = cms.InputTag("heepIDVarValueMaps","eleNrSaturateIn5x5"),
   #trkIsolMap            = cms.InputTag("heepIDVarValueMaps","eleTrkPtIso"),
   #HEEP70Id              = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV70"),
   #HEEP70IdBitmap        = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV70Bitmap"),

   #particleFlowEGammaGSFixed = cms.InputTag("particleFlowEGammaGSFixed", "dupECALClusters"),
   #ecalMultiAndGSGlobalRecHitEB = cms.InputTag("ecalMultiAndGSGlobalRecHitEB","hitsNotReplaced"),
   #mvaMediumIdMap   =  cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring15-25ns-Trig-V1-wp90"),
   #mvaTightIdMap    =  cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring15-25ns-Trig-V1-wp80"),
   #mvaValuesMap     =  cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
   #mvaCategoriesMap =  cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
   #cutBasedIdTokenTight  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-tight"),
   #cutBasedIdTokenMedium = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-medium"),
   #cutBasedIdTokenLoose  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-loose"),
   #cutBasedIdTokenVeto   = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-veto"),
   ##cutBasedIdTokenTight  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-tight"),
   ##cutBasedIdTokenMedium = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-medium"),
   ##cutBasedIdTokenLoose  = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-loose"),
   ##cutBasedIdTokenVeto   = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-veto"),
   #HEEP60IdToken        = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV60"),
   #HEEP60IdFullInfoMap  = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV60"),
)
