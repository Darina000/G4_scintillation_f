//
//  SensitiveDetector.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef SENSITIVEDETECTOR
#define SENSITIVEDETECTOR

#include<G4VSensitiveDetector.hh>


#include "DetectorConstruction.hh"
#include <vector>

class G4Step;
class G4TouchableHistory;

struct TrackingData{
    G4ThreeVector position;
    double time = 0;
};


class SensitiveDetector: public G4VSensitiveDetector
{

public:
    
  SensitiveDetector(G4String name);
  ~SensitiveDetector();
  G4bool ProcessHits(G4Step *step, G4TouchableHistory *hist);
    
  void EndOfEvent(G4HCofThisEvent*);
private:
     int eventID = 0;

    TrackingData empty;
};

#endif
