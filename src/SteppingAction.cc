//
//  SteppingAction.cpp
//  
//
//  Created by Дарья Землянская on 24.07.2020.
//

#include "SteppingAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

#include "G4Step.hh"
#include "G4ParticleTypes.hh"
#include "G4RunManager.hh"

using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(RunAction* RA, EventAction* EA)
:G4UserSteppingAction(),fRunaction(RA), fEventaction(EA)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{

    
 G4VPhysicalVolume* volume
 = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  
    G4int trackID = aStep->GetTrack()->GetTrackID();
    G4double Edep = aStep->GetTotalEnergyDeposit();

}
