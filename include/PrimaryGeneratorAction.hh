//
//  PrimaryGeneratorAction.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class DetectorConstruction;
class G4ParticleGun;
class G4Event;

class DetectorConstruction;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction(DetectorConstruction*);
  ~PrimaryGeneratorAction();

  public:
    virtual void GeneratePrimaries(G4Event*);
    G4ParticleGun* GetParticleGun() {return fParticleGun;};

  private:
    G4ParticleGun*        fParticleGun;
    DetectorConstruction* fDetector;
};


#endif
