//
//  SteppingAction.hpp
//  
//
//  Created by Дарья Землянская on 24.07.2020.
//

#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class DetectorConstruction;
class EventAction;
class RunAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(RunAction*, EventAction* );
  ~SteppingAction();

   virtual void UserSteppingAction(const G4Step*);
    
private:
    RunAction*            fRunaction;
    EventAction*          fEventaction;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
