#include <iostream>

struct TimeFormat
{
	int secPerMin;
	int minPerHour;
	int hourPerDay;
};

class Time
{
	public:
		Time( int );
		~Time ( void );
		void convertToFormat(void);
		void changeFormat(struct TimeFormat format);
		void printTimeLine(void);

	private:
		struct TimeFormat format;
		int _h;
		int _m;
		int _s;
		int _total;
};

Time::Time(int t) : _total(t)
{
	this->format.hourPerDay = 24;
	this->format.minPerHour = 60;
	this->format.secPerMin = 60;
}

Time::~Time() {}

void 
Time::convertToFormat(void)
{
	int totalMinutes;

	totalMinutes = _total / format.secPerMin;
	_s = _total % format.secPerMin;
	_m = totalMinutes % format.minPerHour;
	_h = (totalMinutes / format.minPerHour) % format.hourPerDay;
}

void 
Time::changeFormat(struct TimeFormat format)
{
	this->format = format;
}

void 
Time::printTimeLine(void)
{
	std::cout << _h << " " << _m << " " << _s << std::endl;
}

int main(void)
{	
	struct TimeFormat tf;
	int totalSec;

	std::cin >> tf.hourPerDay >> tf.minPerHour >> tf.secPerMin;
	std::cin >> totalSec;
	
	Time time(totalSec);
	time.changeFormat(tf);
	time.convertToFormat();
	time.printTimeLine();
	return (0);
}