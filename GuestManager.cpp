#include <iostream>
#include "GuestManager.h"

std::vector<std::shared_ptr<Guest>> guests;
Guest::Guest(){
    }
Guest::Guest(enum GuestType g,enum RoomType r, int StayDuration){
    guest_type = g;
    room_type = r;
    booked_days = StayDuration;
}

enum GuestType Guest::GetGuestType(){
    return guest_type;
}
enum RoomType Guest::GetRoomType(){
    return room_type;
}
const int Guest::GetBookedDays(){
    return booked_days;
}
int Guest::GetRoomBusyDays(){
    return booked_days;
}
int Guest::GetAdditionalIncome(){
    return 0;
}

Guest::~Guest(){
    
}

int Rockstar::GetRoomBusyDays(){
    return booked_days + 10;
}
int Businessman::GetAdditionalIncome(){
    return AddedIncome;
}

GuestManager::GuestManager(int num_standard, int cost_standard, int num_comfort, int cost_comfort){
    standard_rooms = num_standard;
    price_standard = cost_standard;
    comfort_rooms = num_comfort;
    price_comfort = cost_comfort;
}

bool GuestManager::AddGuest(enum GuestType g,enum RoomType r, int stayDuration, int AdditionalIncome){
    bool valid;
  if(standard_rooms > 0 and r == RoomType::Standard){
      standard_rooms = standard_rooms - 1;
      standard_days_paid += stayDuration;
      days_in = stayDuration;
      standard_occupied++;
      if(g == GuestType::Rockstar){
          days_in = stayDuration + 10;
      }
      if(g == GuestType::Businessman){
          daily_bonus = AdditionalIncome;
          add_income = AdditionalIncome*stayDuration;
      }
      
      valid = true;
  }
  else if(standard_rooms == 0 and r == RoomType::Standard){
      valid = false;
  }
  if(comfort_rooms > 0 and r == RoomType::Comfort){
      comfort_rooms = comfort_rooms - 1;
      comfort_days_paid += stayDuration;
      days_in = stayDuration;
      comfort_occupied++;
      if(g == GuestType::Rockstar){
          days_in = stayDuration + 10;
      }
      valid = true;
      if(g == GuestType::Businessman){
          daily_bonus = AdditionalIncome;
          add_income = AdditionalIncome * stayDuration;
      }
  }
  else if(comfort_rooms == 0 and r == RoomType::Comfort){
      valid = false;
  }
    for(int i = 0; i < guests.size(); i++){
    std::shared_ptr<Guest> pGuest = std::make_shared<Guest>();
    guests.push_back(pGuest);
    }
  return valid;
}
bool GuestManager::IsAvailable(enum RoomType r, int inDays){
    bool valid;
    if(r == RoomType::Standard && standard_rooms > 0){
        valid = true;
    }
    else if(r == RoomType::Standard && standard_rooms == 0){
        valid = false;
    }
    else if(r == RoomType::Comfort && comfort_rooms > 0){
        valid = true;
    }
    else if(r == RoomType::Comfort && comfort_rooms == 0){
        valid = false;
    }
    if(r == RoomType::Standard && standard_rooms == 0 && inDays >= days_in){
        valid = true;
    }
    else if(r == RoomType::Standard && standard_rooms == 0 && inDays < days_in){
        valid = false;
    }
    else if(r == RoomType::Comfort && comfort_rooms == 0 && inDays >= days_in){
        valid = true;
    }
    else if(r == RoomType::Comfort && comfort_rooms == 0 && inDays < days_in){
        valid = false;
    }
    return valid;
}

int GuestManager::IncomingProfit() const{
    return comfort_days_paid*price_comfort + standard_days_paid*price_standard + add_income;
}

float GuestManager::EarningEfficiency(){
    max_per_day_income = (standard_rooms*price_standard) + (comfort_rooms*price_comfort);
    current_per_day_income = (price_standard*standard_occupied) + (price_comfort*comfort_occupied) + daily_bonus;
    return current_per_day_income / max_per_day_income;
}
bool GuestManager::operator<(const GuestManager& m){
    if(m.IncomingProfit() > this->IncomingProfit()){ 
        return true;
    }
    else{
        return false;
    }
}

