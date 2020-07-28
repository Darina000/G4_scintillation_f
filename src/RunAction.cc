//
//  RunAction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"

#include "Analysis.hh"
#include "EventAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4EmCalculator.hh"
#include "Randomize.hh"
#include <iomanip>


RunAction::RunAction(DetectorConstruction* det, PrimaryGeneratorAction* kin)
 : G4UserRunAction(),fDetector(det), fPrimary(kin)
{
    auto analysisManager =  G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    
    
    //analysisManager->CreateH1("1","Edep in absorber", 100, 0., 800*MeV);
   
}

RunAction::~RunAction()
{
    delete  G4AnalysisManager::Instance();
}

void RunAction::TrackLength (G4double step)
{
  fTrackLength += step; fNbSteps++;
  if (step<fStepMin) fStepMin = step;
  if (step>fStepMax) fStepMax = step;
}

void RunAction::BeginOfRunAction(const G4Run* run)
{
     auto analysisManager =  G4AnalysisManager::Instance();
    analysisManager->OpenFile("from");
    
   // tupleId->analysisManager = analysisManager;
    int TId = analysisManager->CreateNtuple("LT", "Detector");
    analysisManager->CreateNtupleDColumn("Z");
    analysisManager->CreateNtupleDColumn("energy");
    analysisManager->FinishNtuple();
    
    
}

void RunAction::EndOfRunAction(const G4Run* run){
    // Save histograms
     auto analysisManager =  G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
    
    
    

}

