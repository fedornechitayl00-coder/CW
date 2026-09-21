#pragma once
#include "Time.h"

class Bus
{
	Time startTime;
	Time endTime;
	int routeDuration;
	int restDuration;

public:
	Bus();
	Bus(Time startTime, Time endTime, int routeDuration, int restDuration);

	void generateBus() const;

    Time getStartTime() const;
    void setStartTime(const Time& stTime);
    Time getEndTime() const;
    void setEndTime(const Time& endTime);
    int getRouteDuration() const;
    void setRouteDuration(int routeDuration);
	int getRestDuration() const;
	void setRestDuration(int restDuration);

	friend std::ostream& operator << (std::ostream& out, const Bus& obj);
	friend std::istream& operator >> (std::istream& in, Bus& obj);
};

