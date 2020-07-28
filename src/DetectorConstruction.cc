//
//  DetectorConstruction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"
#include <G4NistManager.hh>
#include <G4Box.hh>
#include <G4Tubs.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SDManager.hh>
#include <G4VisAttributes.hh>
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

using namespace std;

#define Mat(x) (G4NistManager::Instance()->FindOrBuildMaterial(x))


World::World(double size_x, double size_y, double size_z,  G4Material *mater_): mater(mater_), sizex(size_x), sizey(size_y), sizez(size_z)
{

solid = new G4Box("world", sizex, sizey, sizez);
logic = new G4LogicalVolume( solid, mater, "World", 0, 0, 0);
physic = new G4PVPlacement(0, G4ThreeVector(), logic, "World",
  0, false, 0);
}

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{

  world = new World(15*cm, 15*cm, 15*cm, Mat("G4_AIR"));
  
  
  
    G4Box *solidDet = new G4Box("solidDet", 6*cm, 6*cm, 3.5*mm);
   G4LogicalVolume *logicDet = new G4LogicalVolume(solidDet, Mat("G4_POLYSTYRENE"), "logicDet");
  G4PVPlacement *physiDet = new G4PVPlacement(0, G4ThreeVector(0,0,0), logicDet,
      "sens_det0", world->getLogic(), false, 0);


  
  SensitiveDetector *detector = new SensitiveDetector("SensDet");
  
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  SDman->AddNewDetector(detector);
    
  logicDet->SetSensitiveDetector(detector);
  
  world->getLogic()->SetVisAttributes (G4VisAttributes::Invisible);
    
  return world->getPhysic();
}
