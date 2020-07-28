//
//  global.hpp
//  from
//
//  Created by Дарья Землянская on 19.07.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"
#include "G4VPhysicsConstructor.hh"




class PhysicsList: public G4VUserPhysicsList
{
public:
PhysicsList();
~PhysicsList();

protected:
void ConstructParticle();
void ConstructProcess();
void SetCuts();



};

#endif
