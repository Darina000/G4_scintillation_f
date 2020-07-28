//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file electromagnetic/TestEm18/src/TrackingAction.cc
/// \brief Implementation of the TrackingAction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "TrackingAction.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "G4PhysicalConstants.hh"
#include "G4Track.hh"
#include "RunAction.hh"

#include "StackingAction.hh"
#include "SensitiveDetector.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

#include "G4Event.hh"
#include "G4VProcess.hh"

#include "G4ParticleTypes.hh"
#include "G4ios.hh"

#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include"PhysicsList.hh"
#include "TH1.h"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "globals.hh"

#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include <time.h>
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4Event.hh"
#include "G4VHitsCollection.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>
#include "G4RunManager.hh"
#include "G4Run.hh"
#include <G4ParticleGunMessenger.hh>
#include <G4ParticleGun.hh>

#include "Analysis.hh"

#include "G4EmCalculator.hh"

#include "Randomize.hh"
#include <iomanip>


using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TrackingAction::TrackingAction(RunAction* runaction)
:G4UserTrackingAction(), fRunAction(runaction)
{ 
   fEkin1 = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
    
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if (track->GetTrackID() == 1 ) fEkin1 = track->GetKineticEnergy();
    
    
    if ((track->GetTrackID() > 1 )&& (track->GetDefinition()  == G4Electron::ElectronDefinition()) ){
               cout << "................" << G4endl;
   // cout << "pre" << endl;
    G4double z = (track->GetPosition()).z();
    //G4double y = (track->GetPosition()).y();
    //G4double x = (track->GetPosition()).x();
        if (z > -3.5*mm && z< 3.5*mm){
    analysisManager->FillNtupleDColumn(0, z);
    analysisManager -> AddNtupleRow();
  //  cout << x << " " << ": = x" << endl;
  //  cout << y << " " << ": = y" << endl;
    cout << z << " " << ": = z" << endl;
        }
        
    }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TrackingAction::PostUserTrackingAction(const G4Track* track)
{
  //energy balance of primary particle
    //
  if (track->GetTrackID() == 1) {
  G4double Ekin2 = track->GetKineticEnergy();
  }
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

