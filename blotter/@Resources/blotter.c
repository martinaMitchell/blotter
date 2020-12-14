#include "d8.c"
#include "calendarmaker.c"

int main(){
	//check to see if we need to make a new calendar
	int check; 
    	char* dirname = "days"; 
    	check = mkdir(dirname,0777); 
	if (!check){newCalendar();}

	//iscurrent();

	struct datestruct today = todaysDate();
	struct datestruct center = dateFromFile("days\\today.txt");
	//printf("today; %i, %i, %i\n", today.year, today.month, today.monthday);
	//printf("center; %i, %i, %i\n", center.year, center.month, center.monthday);
	while(today.year != center.year || today.month != center.month || today.monthday != center.monthday){
		dayChanger();
	}
	return 0;
}