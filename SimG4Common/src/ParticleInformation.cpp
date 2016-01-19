#include "SimG4Common/ParticleInformation.h"

namespace sim {
ParticleInformation::ParticleInformation(const MCParticle& aMCpart): m_mcParticle(aMCpart) {}

ParticleInformation::~ParticleInformation() {}

void ParticleInformation::Print() const {}

const MCParticle& ParticleInformation::mcParticle() const {
  return m_mcParticle;
}
void ParticleInformation::setEndMomentum(const CLHEP::Hep3Vector& aMom) {
  m_endMomentum = aMom;
}
const CLHEP::Hep3Vector& ParticleInformation::endMomentum() const {
  return m_endMomentum;
}
void ParticleInformation::setVertexPosition(const CLHEP::Hep3Vector& aPos) {
  m_vertexPosition = aPos;
}
const CLHEP::Hep3Vector& ParticleInformation::vertexPosition() const {
  return m_vertexPosition;
}
void ParticleInformation::setEndStatus(int aStat) {
  m_endStatus = aStat;
}
const int ParticleInformation::endStatus() const {
  return m_endStatus;
}
}
