import FWCore.ParameterSet.Config as cms
import os
import sys
# set up process
process = cms.Process("MakeNpKNU")

### VarParcing
from FWCore.ParameterSet.VarParsing import VarParsing
options = dict()
varOptions = VarParsing('analysis')
varOptions.register("isMC", True, VarParsing.multiplicity.singleton, VarParsing.varType.bool, "isMC" )

varOptions.register('isMiniAOD',True,VarParsing.multiplicity.singleton,VarParsing.varType.bool," whether we are running on miniAOD or not")
varOptions.register('runVID',True,VarParsing.multiplicity.singleton,VarParsing.varType.bool," ")
varOptions.register('runEnergyCorrections',True,VarParsing.multiplicity.singleton,VarParsing.varType.bool," ")
varOptions.register('applyEnergyCorrections',False,VarParsing.multiplicity.singleton,VarParsing.varType.bool," ")
varOptions.register('applyVIDOnCorrectedEgamma',False,VarParsing.multiplicity.singleton,VarParsing.varType.bool," ")
varOptions.register('applyEPCombBug',False,VarParsing.multiplicity.singleton,VarParsing.varType.bool," ")
varOptions.register('era','2018-Prompt',VarParsing.multiplicity.singleton,VarParsing.varType.string," ")
varOptions.register('unscheduled',False,VarParsing.multiplicity.singleton,VarParsing.varType.bool," ")
varOptions.register('nrThreads',1,VarParsing.multiplicity.singleton,VarParsing.varType.int," ")
varOptions.parseArguments()

### Message Logger
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.destinations = ['cout', 'cerr']
process.MessageLogger.cerr.FwkReport = cms.untracked.PSet(
    reportEvery = cms.untracked.int32(500),
    limit = cms.untracked.int32(10000000)
)
# SetOption -- Display summary at the end, enable unscheduled execution
process.options = cms.untracked.PSet(
        numberOfStreams = cms.untracked.uint32(varOptions.nrThreads),
        numberOfThreads = cms.untracked.uint32(varOptions.nrThreads),
        allowUnscheduled = cms.untracked.bool(True),
        wantSummary = cms.untracked.bool(True),
        SkipEvent = cms.untracked.vstring('ProductNotFound')
)


def getGlobalTagName(isMC,era):
    if era=='2018-Prompt':
        if isMC: return '102X_upgrade2018_realistic_v15'
        else: return '102X_dataRun2_Prompt_v11'
    elif era=='2017-Nov17ReReco':
        if isMC: return '94X_mc2017_realistic_v10'
        else: return '94X_dataRun2_ReReco_EOY17_v2'
    elif era=='2016-Legacy':
        if isMC: return '94X_mcRun2_asymptotic_v3'
        else: return '94X_dataRun2_v10'
    elif era=='2017-UL':
        if isMC: return '106X_mc2017_realistic_v6'
        else: return '106X_dataRun2_v20'
    else:
        raise RuntimeError('Error in runPostRecoEgammaTools, era {} not currently implimented. Allowed eras are 2018-Prompt 2017-Nov17ReReco 2016-Legacy 2017-UL'.format(era))

### Standard modules Loading
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Geometry.CaloEventSetup.CaloTowerConstituents_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

#configurable options ============================================
#runOnData=False
DEBUG=False
# ================================================================
## DEBUG Tracer
if (DEBUG):
        process.Tracer = cms.Service("Tracer")

#from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
from Configuration.AlCa.GlobalTag import GlobalTag

if (varOptions.isMC):
        process.GlobalTag.globaltag = '102X_upgrade2018_realistic_v20' #RunIIAutumn18
        inputFileName = '/store/mc/RunIIAutumn18MiniAOD/WprimeToENu_M_200_TuneCP5_13TeV_pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/280000/B6E79D04-C71C-C143-85D1-EB65CE044758.root'
        ntFileName = "ntNpKNUmc.root"
        histFileName = 'histFileMC.root'
else:
        process.GlobalTag.globaltag = '101X_dataRun2_Prompt_v11' #2018Data 
        inputFileName = '/store/data/Run2016B/SingleMuon/MINIAOD/03Feb2017_ver2-v2/100000/FEF25E85-82EC-E611-A8F0-0CC47A4D7670.root'
        #inputFileName = 'root://cms-xrd-global.cern.ch//store/data/Run2016B/SingleMuon/MINIAOD/PromptReco-v2/000/273/158/00000/A8816A41-1E1A-E611-907B-02163E0128EB.root'
        #inputFileName = 'root://cms-xrdr.sdfarm.kr:1094//store/data/Run2016B/SingleMuon/MINIAOD/03Feb2017_ver2-v2/100000/FEF25E85-82EC-E611-A8F0-0CC47A4D7670.root'
        #inputFileName = 'file:/hcp/data/data01/ycyang/store/data/Run2016G/SingleMuon/MINIAOD/23Sep2016-v1/1110000/A2C0F697-B19C-E611-A4D8-F04DA275BFF2.root'
        ntFileName = 'ntNpKNUdata.root'
        histFileName = 'histFileData.root'

print "### isMC ", varOptions.isMC
print "### GlobalTag:", process.GlobalTag.globaltag
print "### inFileName:", inputFileName
print "### ntFileName:", ntFileName
print "### histFileName:", histFileName

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(inputFileName))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
process.TFileService = cms.Service("TFileService",
        closeFileFast = cms.untracked.bool(True),
        fileName = cms.string(ntFileName) )

## --EGamma ID Sequence ------------------------------------------------------
# https://github.com/cms-egamma/EgammaPostRecoTools/blob/master/python/EgammaPostRecoTools.py
#CMSSW_10_2_X/src/EgammaUser/EgammaPostRecoTools/test/runEgammaPostRecoTools.py
#from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
from EgammaUser.EgammaPostRecoTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process,
                       applyEnergyCorrections=varOptions.applyEnergyCorrections,
                       applyVIDOnCorrectedEgamma=varOptions.applyVIDOnCorrectedEgamma,
                       isMiniAOD=varOptions.isMiniAOD,
                       era=varOptions.era,
                       runVID=varOptions.runVID,
                       runEnergyCorrections=varOptions.runEnergyCorrections,
                       applyEPCombBug=varOptions.applyEPCombBug)
## ----------------------------------------------------------------------------
#start MakeNpKNU
from MakeNpKNU.ProdNpKNU.ProdNpElectron_cfi import *
process.ProdNpElectron = ProdNpElectron.clone()
process.ProdNpElectron.DoMakeHist = cms.untracked.bool(False)

from MakeNpKNU.ProdNpKNU.ProdNpMuon_cfi import *
process.ProdNpMuon = ProdNpMuon.clone()
process.ProdNpMuon.DoMakeHist = cms.untracked.bool(False)

from MakeNpKNU.ProdNpKNU.ProdNpJet_cfi import *
process.ProdNpJet = ProdNpJet.clone()

from MakeNpKNU.ProdNpKNU.ProdNpMET_cfi import *
process.ProdNpMET = ProdNpMET.clone()
process.ProdNpMET.DoMakeHist = cms.untracked.bool(False)

from MakeNpKNU.ProdNpKNU.ProdNpGenerator_cfi import *
process.ProdNpGenerator = ProdNpGenerator.clone()

from MakeNpKNU.ProdNpKNU.ProdNpMisc_cfi import *
process.ProdNpMisc = ProdNpMisc.clone()
#process.ProdNpMisc.triggerIdentifiers = cms.vstring(['HLT_Ele*','HLT_Mu*','HLT_TkMu*','HLT_Pho*'])
process.ProdNpMisc.DoMakeHist = cms.untracked.bool(False)


process.MakeNpKNU = cms.EDAnalyzer('MakeNpKNU',
#     electronToken     = cms.InputTag('ProdNpElectron','Electron'),
#     muonToken         = cms.InputTag('ProdNpMuon','Muon'),
#     photonToken       = cms.InputTag('ProdNpPhoton','Photon'),
#     jetToken          = cms.InputTag('ProdNpJet','Jet'),
#     metToken          = cms.InputTag('ProdNpMET','MET'),
#     vertexToken       = cms.InputTag('ProdNpMisc','Vertex'),
#     triggerToken      = cms.InputTag('ProdNpMisc','Trigger'),
#     triggerObjectToken= cms.InputTag('ProdNpMisc','TriggerObject'),
#     pileupToken       = cms.InputTag('ProdNpMisc','Pileup'),
     genParticleToken  = cms.InputTag('ProdNpGenerator','GenParticle'),
     genInfoToken      = cms.InputTag('ProdNpGenerator','GenInfo'),
     HistFileName      = cms.string(histFileName),
)

#DEBUG
#print "Process=",process, process.__dict__.keys()
#------------------------------------------------------

process.p = cms.Path(
#process.egammaPostRecoSeq
#* process.ProdNpElectron
#* process.ProdNpMuon
#* process.ProdNpMET
* process.ProdNpGenerator
#* process.ProdNpMisc
* process.MakeNpKNU
)
