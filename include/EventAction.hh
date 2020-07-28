//
//  EventAction.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include <G4VSensitiveDetector.hh>
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include <vector>
#include <map>


class G4VProcess;
class RunAction;
class EventAction : public G4UserEventAction
{
public:
  EventAction(RunAction*, PrimaryGeneratorAction*);
  ~EventAction();

public:
  virtual void  BeginOfEventAction(const G4Event*);
  virtual void    EndOfEventAction(const G4Event*);
    
    
private:
    RunAction*    fRunAction;
    PrimaryGeneratorAction* primary;
    G4double      fEdepPrimary, fEdepSecondary;

};





#endif
