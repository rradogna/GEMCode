// -*- C++ -*-
//
// Package:    GEMLocalPool
// Class:      GEMLocalPool
// 
/**\class GEMLocalPool GEMLocalPool.cc GEMAnalysis/GEMLocalPool/src/GEMLocalPool.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  
//         Created:  Mon Jul  8 19:27:59 CEST 2013
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
//
// class declaration
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

//
#include <DataFormats/GEMRecHit/interface/GEMRecHit.h>
#include "DataFormats/GEMRecHit/interface/GEMRecHitCollection.h"
#include <DataFormats/MuonDetId/interface/GEMDetId.h>

#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"

#include "Geometry/GEMGeometry/interface/GEMGeometry.h"
#include <Geometry/GEMGeometry/interface/GEMEtaPartition.h>
#include "Geometry/GEMGeometry/interface/GEMEtaPartitionSpecs.h"
#include <Geometry/Records/interface/MuonGeometryRecord.h>
#include <Geometry/CommonDetUnit/interface/GeomDet.h>
#include <Geometry/CommonTopologies/interface/RectangularStripTopology.h>
#include <Geometry/CommonTopologies/interface/TrapezoidalStripTopology.h>

class GEMLocalPool : public edm::EDAnalyzer {
   public:
      explicit GEMLocalPool(const edm::ParameterSet&);
      ~GEMLocalPool();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      std::map<std::string,TH1F*> histContainer_; 
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      //virtual void endRun(edm::Run const&, edm::EventSetup const&);
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      // ----------member data ---------------------------

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GEMLocalPool::GEMLocalPool(const edm::ParameterSet& iConfig):
histContainer_()
{
   //now do what ever initialization is needed
}


GEMLocalPool::~GEMLocalPool()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
GEMLocalPool::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

  edm::Handle<GEMRecHitCollection> gemRecHits_;
  iEvent.getByLabel("gemRecHits","",gemRecHits_);

  edm::Handle<edm::PSimHitContainer> GEMHits;
  iEvent.getByLabel(edm::InputTag("g4SimHits","MuonGEMHits"), GEMHits);
  
  std::cout<<"n of RecHits: "<<gemRecHits_->size()<<std::endl;
  std::cout<<"n of SemHits: "<<GEMHits->size()<<std::endl;


for (GEMRecHitCollection::const_iterator recHit = gemRecHits_->begin(); recHit != gemRecHits_->end(); ++recHit)
  {
    float x_reco = recHit->localPosition().x();
    float err_x_reco = recHit->localPositionError().xx();
    float y_reco = recHit->localPosition().y();
    unsigned int detId = (unsigned int) (*recHit).gemId();
    //gem_recHit_.bx = recHit->BunchX();
    //gem_recHit_.clusterSize = recHit->clusterSize();
    //gem_recHit_.firstClusterStrip = recHit->firstClusterStrip();

    //GEMDetId id((*recHit).gemId());
 std::cout<<" x: "<<x_reco<<" +- "<<err_x_reco<<std::endl;
 std::cout<<" y: "<<y_reco<<std::endl;
  for (edm::PSimHitContainer::const_iterator itHit = GEMHits->begin(); itHit != GEMHits->end(); ++itHit)
  {
  std::cout<<"sim detId "<<itHit->detUnitId()<<std::endl;  
  std::cout<<"rec detId "<<detId<<std::endl;  
  if (itHit->detUnitId() == detId){ 
 
    if (std::abs(itHit->particleType())==13){
    float x_sim = itHit->localPosition().x();
    //float err_x_sim = itHit->localPositionError().xx();
    float y_sim = itHit->localPosition().y();
    float dX = x_sim - x_reco;
    float pull = dX/std::sqrt(err_x_reco);
 std::cout<<"++++++++++++++++"<<std::endl;
 std::cout<<" x_reco: "<<x_reco<<" +- "<<err_x_reco<<std::endl;
 std::cout<<" x_sim: "<<x_sim<<std::endl;
 std::cout<<" y_reco: "<<y_reco<<std::endl;
 std::cout<<" y_sim: "<<y_sim<<std::endl;
 std::cout<<" dX: "<<dX<<std::endl;
 std::cout<<" pull: "<<pull<<std::endl;
 histContainer_["N_eventi"]->Fill(1);
 histContainer_["DeltaX"]->Fill(dX);
 histContainer_["DeltaX_over_err"]->Fill(pull);

     }
     }

   }
  }
}


// ------------ method called once each job just before starting event loop  ------------
void 
GEMLocalPool::beginJob()
{
edm::Service<TFileService> fs;
 histContainer_["N_eventi"]=fs->make<TH1F>("N_eventi", "count",    2,   0., 2.);
 histContainer_["DeltaX"]=fs->make<TH1F>("DeltaX", "xmc - x_rec",    50,   -2., 2.);
 histContainer_["DeltaX_over_err"]=fs->make<TH1F>("DeltaX_over_err", "xmc - x_rec / sigma_err",    500,   -15., 15.);
}


// ------------ method called once each job just after ending the event loop  ------------
void 
GEMLocalPool::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
GEMLocalPool::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/


// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
GEMLocalPool::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/


// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GEMLocalPool::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GEMLocalPool);
