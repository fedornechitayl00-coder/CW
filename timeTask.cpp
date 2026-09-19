#include "Time.h"
#include "Schedule.h"
   

int main() {
	//Time t1(12, 23, 41);
	//Time t2(22, 13, 8, false);

	//t1.tickTime();
	//t2.untickTime();
	//t1.showTime();
	//t2.showTime();

	//std::cout << "\n___________________\n";

	//t1 += 17;
	//t1 += 442.0f;
	//t2 -= 32l;
	//t2 += 9993.0f;

	//t1.showTime();
	//t2.showTime();

	Schedule s1;
	std::cin >> s1;

	s1.generateSchedule();
		
	//Time startTime;
	//int lessonDuration;
	//int shortBreak;
	//int longBreak;
	//int longBreakAfter;
	//int totalLessons;
}