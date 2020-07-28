//
//  SensitiveDetector.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//
#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include"SensitiveDetector.hh"
#include"PhysicsList.hh"
#include "TH1.h"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4VProcess.hh"
#include "G4ios.hh"
#include "globals.hh"
#include "EventAction.hh"
#include <G4Track.hh>

#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4ios.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include "TH1.h"
#include <time.h>
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4Event.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
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


G4double edep;
G4double edep_step;


SensitiveDetector::SensitiveDetector(G4String name): G4VSensitiveDetector(name){
}

G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *history )
{
    G4double eDep  = aStep->GetTotalEnergyDeposit();
    G4int trackID  = aStep->GetTrack()->GetTrackID();
    G4int parentID = aStep->GetTrack()->GetParentID();
    G4ThreeVector Momentum = aStep->GetPostStepPoint()->GetMomentum();
    
    if ( trackID > 1 )
    {
       
    //cout << Momentum  << endl;
    cout << "trackID" << " " << trackID  << endl;
    cout << "parentID" << " " << parentID << endl;
        
    }

     
return true;
    
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent* event)
{
       G4AnalysisManager* analysisManager =  G4AnalysisManager::Instance();
       G4int value = rand();
    
}



SensitiveDetector::~SensitiveDetector()
{
}
