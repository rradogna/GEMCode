import FWCore.ParameterSet.Config as cms


GEMCSCAnalyzer = cms.EDAnalyzer("GEMCSCAnalyzer",
    verbose = cms.untracked.int32(0),
    simInputLabel = cms.untracked.string("g4SimHits"),
    minPt = cms.untracked.double(4.5),
    ntupleTrackChamberDelta = cms.untracked.bool(True),
    ntupleTrackEff = cms.untracked.bool(True),
    simTrackMatching = cms.PSet(
        # SimHit matching:
        verboseSimHit = cms.untracked.int32(0),
        simMuOnlyCSC = cms.untracked.bool(True),
        simMuOnlyGEM = cms.untracked.bool(True),
        discardEleHitsCSC = cms.untracked.bool(True),
        discardEleHitsGEM = cms.untracked.bool(True),
        simInputLabel = cms.untracked.string('g4SimHits'),
        # GEM digi matching:
        verboseGEMDigi = cms.untracked.int32(0),
        gemDigiInput = cms.untracked.InputTag("simMuonGEMDigis"),
        gemPadDigiInput = cms.untracked.InputTag("simMuonGEMCSCPadDigis"),
        gemCoPadDigiInput = cms.untracked.InputTag("simMuonGEMCSCPadDigis", "Coincidence"),
        minBXGEM = cms.untracked.int32(-1),
        maxBXGEM = cms.untracked.int32(1),
        matchDeltaStripGEM = cms.untracked.int32(1),
        # CSC digi matching:
        verboseCSCDigi = cms.untracked.int32(0),
        cscComparatorDigiInput = cms.untracked.InputTag("simMuonCSCDigis", "MuonCSCComparatorDigi"),
        cscWireDigiInput = cms.untracked.InputTag("simMuonCSCDigis", "MuonCSCWireDigi"),
        minBXCSCComp = cms.untracked.int32(3),
        maxBXCSCComp = cms.untracked.int32(9),
        minBXCSCWire = cms.untracked.int32(3),
        maxBXCSCWire = cms.untracked.int32(8),
        matchDeltaStripCSC = cms.untracked.int32(1),
        matchDeltaWireGroupCSC = cms.untracked.int32(1),
        # CSC trigger stubs
        verboseCSCStub = cms.untracked.int32(0),
        cscCLCTInput = cms.untracked.InputTag("simCscTriggerPrimitiveDigis"),
        cscALCTInput = cms.untracked.InputTag("simCscTriggerPrimitiveDigis"),
        cscLCTInput = cms.untracked.InputTag("simCscTriggerPrimitiveDigis"),
        minBXCLCT = cms.untracked.int32(3),
        maxBXCLCT = cms.untracked.int32(9),
        minBXALCT = cms.untracked.int32(3),
        maxBXALCT = cms.untracked.int32(8),
        minBXLCT = cms.untracked.int32(3),
        maxBXLCT = cms.untracked.int32(8)
        
    )
)
