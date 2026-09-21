#include "Bus.h"
#include "Time.h"

Bus::Bus()
{
    startTime = Time(5, 0, 0);
    endTime = Time(23, 0, 0);
    routeDuration = 0;
    restDuration = 0;
}

Bus::Bus(Time startTime, Time endTime, int routeDuration, int restDuration)
{
    this->startTime = startTime;
    this->endTime = endTime;
    this->routeDuration = routeDuration;
    this->restDuration = restDuration;
}

void Bus::generateBus() const
{
    std::cout << *this;
}

Time Bus::getStartTime() const
{
    return startTime;
}

void Bus::setStartTime(const Time& stTime)
{
    if (stTime > Time(5, 0, 0) && stTime < Time(23, 0, 0)) {
        this->startTime = stTime; 
    }
    else {
        std::cout << "Curfew";   //комендантский час 
    }
}

Time Bus::getEndTime() const
{
    return endTime;
}

void Bus::setEndTime(const Time& endTime)
{
    if (endTime > startTime && endTime <= Time(23, 0, 0)) { this->endTime = endTime; }
    else { std::cout << "Curfew"; }  
}

int Bus::getRouteDuration() const
{
    return routeDuration;
}

void Bus::setRouteDuration(int routeDuration)
{
    if(routeDuration > 0) this->routeDuration = routeDuration;
}

int Bus::getRestDuration() const
{
    return restDuration;
}

void Bus::setRestDuration(int restDuration)
{
    if (restDuration > 0) this->restDuration = restDuration;
}

std::ostream& operator<<(std::ostream& out, const Bus& obj)
{
    out << "____________________________________Bus____________________________________\n";

    Time current_time = obj.getStartTime();
    while (current_time < obj.getEndTime()) {
        out << "\n" << current_time << " --  "
            <<  current_time + obj.getRouteDuration();
        current_time += obj.getRouteDuration() + obj.getRestDuration();
    }
    return out;
}

std::istream& operator>>(std::istream& in, Bus& obj)
{
    std::cout << "Enter time when bus start it`s route: ";
    int h, m;
    in >> h >> m;
    Time st = Time(h, m, 0);
    obj.setStartTime(st);

    std::cout << "Enter time when bus end it`s route: ";
    in >> h >> m;
    Time et = Time(h, m, 0);
    obj.setEndTime(et);

    std::cout << "Enter time duration of 1 route(in minutes): ";
    int routeD;
    in >> routeD;
    obj.setRouteDuration(routeD);

    std::cout << "Enter how much time driver will have for a rest: ";
    int restD;
    in >> restD;
    obj.setRestDuration(restD);

    return in;
}
