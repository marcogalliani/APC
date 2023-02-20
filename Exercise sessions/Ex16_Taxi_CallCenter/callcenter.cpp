//
// Created by Federica Filippini on 09/12/2020.
//

#include "callcenter.h"

void CallCenter::RegisterTaxi (const std::string& license_id)
{
    Taxi new_taxi(license_id);
    taxis.insert(std::pair<std::string, Taxi>(license_id, new_taxi));
}

Taxi CallCenter::CallAtRailStation(const Place &Destination) {
    if(not station_available_taxis.empty()){
     Taxi first_taxi = *station_available_taxis.begin();
     station_available_taxis.erase(first_taxi);
     taxis.at(first_taxi.CGetLicenseId()).SetRide(station,Destination);
     return taxis.at(first_taxi.CGetLicenseId());
    }
    else
        return Call(station, Destination);
}


