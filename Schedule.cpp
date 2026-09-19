#include "Schedule.h"
#include <ctime>


Schedule::Schedule()
{
	startTime = Time(8, 0, 0);
	int lessonDuration = 45;
	int shortBreak = 5;
	int longBreak = 30;
	int longBreakAfter = 4;
	int totalLessons = 8;

}

Schedule::Schedule(Time start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons)
{
	this->startTime = start;
	lessonDuration = lessonDur;
	shortBreak = shortBr;
	longBreak = longBr;
	longBreakAfter = longAfter;
	totalLessons = lessons;
}

void Schedule::generateSchedule() const
{
	std::cout << *this;
}

Time Schedule::getStartTime() const
{
	return startTime;
}

void Schedule::setStartTime(Time& stTime)
{
	this->startTime =stTime;
}

int Schedule::getLessonDuration() const
{
	return lessonDuration;
}

void Schedule::setLessonDuration(int lessDuration)
{
	lessonDuration = lessDuration;
}

int Schedule::getShortBreak() const
{
	return shortBreak;
}

void Schedule::setShortBreak(int SBreak)
{
	this->shortBreak = SBreak;
}

int Schedule::getLongBreak() const
{
	return longBreak;
}

void Schedule::setLongBreak(int lBreak)
{
	longBreak = lBreak;
}

int Schedule::getLongBreakAfter() const
{
	return longBreakAfter;
}

void Schedule::setLongBreakAfter(int LBreakAfter)
{
	longBreakAfter = LBreakAfter;
}

int Schedule::getTotalLessons() const
{
	return totalLessons;
}

void Schedule::setTotalLessons(int TTLessons)
{
	totalLessons = TTLessons;
}

std::ostream& operator<<(std::ostream& out, const Schedule& obj)
{
	out << "____________________________________Schedule____________________________________\n";
		
	Time current_time = obj.getStartTime();
	for (int i = 1; i <= obj.getTotalLessons(); ++i) {
		Time ending_time = current_time + obj.lessonDuration;
		out << "\n" << i << ". " << current_time << " --  "
			<< ending_time << "\nbreak - ";
		if (i == obj.totalLessons) std::cout << "you can be free\n";
		else if (i == obj.longBreakAfter) {
			out << obj.longBreak; current_time = ending_time + obj.getLongBreak(); 
		}
		else {
			out << obj.shortBreak; current_time = ending_time + obj.getShortBreak(); 
		}	
	}
	return out;
}

std::istream& operator>>(std::istream& in, Schedule& obj)
{
	std::cout << "Enter start time: ";
	int hours, minutes;
	in >> hours >> minutes;
	obj.startTime = Time(hours, minutes, 0);

	std::cout << "Enter lesson duration (minutes): ";
	in >> obj.lessonDuration;
	std::cout << "Enter short break (minutes): ";
	in >> obj.shortBreak;
	std::cout << "Enter long break (minutes): ";
	in >> obj.longBreak;
	std::cout << "After which lesson is the long break? ";
	in >> obj.longBreakAfter;
	std::cout << "Enter total lessons: ";
	in >> obj.totalLessons;

	return in;
}
