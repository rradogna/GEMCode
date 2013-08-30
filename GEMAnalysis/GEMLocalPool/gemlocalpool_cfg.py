import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/cmshome/radogna/GEM_Geometry/CMSSW_6_1_2_SLHC6_patch1/src/out_local_reco.root'
    )
)

process.demo = cms.EDAnalyzer('GEMLocalPool'
)

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string('muonHistos.root')
                                   )

process.p = cms.Path(process.demo)
