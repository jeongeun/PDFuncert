import FWCore.ParameterSet.Config as cms

ProdNpMuon = cms.EDProducer('ProdNpMuon',
        muons = cms.InputTag("slimmedMuons"),
	MinPtCut = cms.untracked.double(5.0),
	vertexToken = cms.InputTag("offlineSlimmedPrimaryVertices"),
        PFCandidates = cms.InputTag("packedPFCandidates"),
)

