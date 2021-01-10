import FWCore.ParameterSet.Config as cms

ProdNpMisc = cms.EDProducer('ProdNpMisc',
	DoPileup = cms.untracked.bool(True),
        pileupToken = cms.InputTag("slimmedAddPileupInfo"),
	DoVertex = cms.untracked.bool(True),
        vertexToken = cms.InputTag("offlineSlimmedPrimaryVertices"),
	DoTrigger = cms.untracked.bool(True),
        triggerBitsToken = cms.InputTag("TriggerResults","","HLT"),
        #triggerObjectsToken = cms.InputTag("selectedPatTrigger"), # old
        triggerObjectsToken = cms.InputTag("slimmedPatTrigger"),
        #filterLabelsToken = cms.InputTag("slimmedPatTrigger::filterLabels"),
        triggerPrescalesToken = cms.InputTag("patTrigger"),
        triggerPaths = cms.vstring(['HLT_Ele*','HLT_Pho*','HLT_Mu*','HLT_TkMu*']),
        PrintTriggerResult = cms.untracked.bool(False),
)

