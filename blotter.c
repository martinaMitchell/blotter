#include "d8.c"
#include "calendarmaker.c"

int main(){
	//check to see if we need to make a new calendar
	newCalendar();


	//iscurrent();

	struct datestruct today = todaysDate();
	struct datestruct center = dateFromFile("days\\today.txt");
	while(today.year != center.year || today.month != center.month || today.monthday != center.monthday){
		dayChanger();
	}
	return 0;
}

//shopping list;
// bread
// jelly
// bagels