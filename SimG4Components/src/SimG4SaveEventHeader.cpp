#include "SimG4SaveEventHeader.h"

// datamodel
#include "edm4hep/EventHeaderCollection.h"

DECLARE_COMPONENT(SimG4SaveEventHeader)

SimG4SaveEventHeader::SimG4SaveEventHeader(const std::string& aType,
                                           const std::string& aName,
                                           const IInterface* aParent)
    : GaudiTool(aType, aName, aParent) {
  declareInterface<ISimG4SaveOutputTool>(this);
  declareProperty("EventHeaders", m_eventHeaders, "Handle to the event header collection");

  m_eventNumber = 0;
}


StatusCode SimG4SaveEventHeader::saveOutput(const G4Event& aEvent) {
  edm4hep::EventHeaderCollection* eventHeaderColl = m_eventHeaders.createAndPut();
  auto eventHeader = eventHeaderColl->create();
  eventHeader.setRunNumber(0);
  eventHeader.setEventNumber(++m_eventNumber);
  // auto header = new edm4hep::EventHeader(25, 64, 654, 1.);
  // m_eventHeader.put(header);

  // header->setEventNumber(341234);

  return StatusCode::SUCCESS;
}
