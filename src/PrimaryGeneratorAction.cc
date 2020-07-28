//
//  PrimaryGeneratorAction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

#include<G4Event.hh>
#include "EventAction.hh"
#include<G4ParticleGun.hh>
#include<G4ParticleTable.hh>
#include<G4ParticleDefinition.hh>
#include<globals.hh>
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4RunManager.hh"
#include "G4IonTable.hh"
#include "G4ChargedGeantino.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

int Event_Number;

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction* det)
:G4VUserPrimaryGeneratorAction(),fParticleGun(0),fDetector(det)
{
fParticleGun  = new G4ParticleGun(1);

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete  fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    Event_Number = anEvent->GetEventID();
    G4ParticleTable* particleTable1 = G4ParticleTable::GetParticleTable();
    
    G4ParticleDefinition* particle
             = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
    
    fParticleGun->SetParticleDefinition(particle);
        fParticleGun->SetParticleEnergy(0.4*MeV);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    
    
    fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,-10*cm));
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
