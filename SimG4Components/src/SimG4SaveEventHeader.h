#ifndef SIMG4COMPONENTS_SIMG4SAVEEVENTHEADER_H
#define SIMG4COMPONENTS_SIMG4SAVEEVENTHEADER_H

// Gaudi
#include "GaudiAlg/GaudiTool.h"

// FCCSW
#include "k4FWCore/DataHandle.h"
#include "SimG4Interface/ISimG4SaveOutputTool.h"

class IGeoSvc;

namespace edm4hep {
  class EventHeaderCollection;
}

/** @class SimG4SaveEventHeader SimG4Components/src/SimG4SaveEventHeader.h SimG4SaveEventHeader.h
 *
 *  The tool saves the event information in the EDM4hep event header.
 *
 *  @author J. Smiesko
 */

class SimG4SaveEventHeader : public GaudiTool, virtual public ISimG4SaveOutputTool {
  public:
    explicit SimG4SaveEventHeader(const std::string& aType,
                                  const std::string& aName,
                                  const IInterface* aParent);
  virtual ~SimG4SaveEventHeader() = default;

  /**  Save the event header
   *   Creates event header containing global inforamtion about the event.
   *   @param[in] aEvent The Geant Event containing data to save.
   *   @return status code
   */
  StatusCode saveOutput(const G4Event& aEvent) override final;

private:
  /// Handle for EventHeader collection to create
  DataHandle<edm4hep::EventHeaderCollection> m_eventHeaders{"EventHeaders", Gaudi::DataHandle::Writer, this};

  // Count number of events
  size_t m_eventNumber;
};

#endif /* SIMG4COMPONENTS_SIMG4SAVEEVENTHEADER_H */
