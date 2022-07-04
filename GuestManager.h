#ifndef _GUEST_MANAGER_
#define _GUEST_MANAGER_
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <memory>

enum class RoomType{
    Standard,
    Comfort
};
enum class GuestType{
    Family,
    Businessman,
    Rockstar
};

class Guest{
    protected:
        enum GuestType guest_type;
        enum RoomType room_type;
        int booked_days;
        int busy_days;
    public:
        Guest();
        Guest(enum GuestType,enum RoomType, int StayDuration);
        enum GuestType GetGuestType();
        enum RoomType GetRoomType();
        const int GetBookedDays();
        virtual int GetRoomBusyDays();
        virtual int GetAdditionalIncome();
        ~Guest();


};
class Family:public Guest{
    
};

class Rockstar:public Guest{
    public:
    virtual int GetRoomBusyDays() override;
};

class Businessman:public Guest{
    protected:
    int AddedIncome;
    public:
    virtual int GetAdditionalIncome() override;
    Businessman(enum GuestType,enum RoomType, int stayDuration, int additionalIncome);
};

class GuestManager{
    public:
        GuestManager(int num_standard, int cost_standard, int num_comfort, int cost_comfort);
        bool AddGuest(enum GuestType, enum RoomType, int stayDuration, int AdditionalIncome = 0);
        bool IsAvailable(enum RoomType, int inDays = 0);
        int IncomingProfit() const;
        float EarningEfficiency();
        bool operator<(const GuestManager& m);
    protected:
    int standard_rooms;
    int price_standard;
    int comfort_rooms;
    int price_comfort;
    int standard_days_paid;
    int comfort_days_paid;
    int days_in;
    float max_per_day_income;
    float current_per_day_income;
    int standard_occupied;
    int comfort_occupied;
    int add_income;
    int daily_bonus;

};
#endif
