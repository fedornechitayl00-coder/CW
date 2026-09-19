#pragma once
#include "Time.h"

class Schedule {
private:
    Time startTime;
    int lessonDuration;
    int shortBreak;
    int longBreak;
    int longBreakAfter;
    int totalLessons;

public:
    Schedule();
    Schedule(Time start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons);

    void generateSchedule()const;

    Time getStartTime() const;
    void setStartTime(Time& stTime);
    int getLessonDuration() const;
    void setLessonDuration(int lessDuration);
    int getShortBreak() const;
    void setShortBreak(int SBreak);
    int getLongBreak() const;
    void setLongBreak(int lBreak);
    int getLongBreakAfter() const;
    void setLongBreakAfter(int LBreakAfter);
    int getTotalLessons() const;
    void setTotalLessons(int TTLessons);
    
    friend std::ostream& operator << (std::ostream& out, const Schedule& obj);
    friend std::istream& operator >> (std::istream& in, Schedule& obj);
};


