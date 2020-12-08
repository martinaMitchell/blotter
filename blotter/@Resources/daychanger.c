
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include "calendarmaker.c"
extern int errno ;

int main(){

return(0);}
int dayChanger(){
	char p[35][15]={
		"days\\m17.txt", "days\\m16.txt", "days\\m15.txt", "days\\m14.txt", "days\\m13.txt", "days\\m12.txt", "days\\m11.txt",
		"days\\m10.txt", "days\\m9.txt", "days\\m8.txt", "days\\m7.txt", "days\\m6.txt", "days\\m5.txt", "days\\m4.txt",
		"days\\m3.txt", "days\\m2.txt", "days\\m1.txt",
		"days\\today.txt",
		"days\\p1.txt", "days\\p2.txt", "days\\p3.txt",
		"days\\p4.txt", "days\\p5.txt","days\\p6.txt", "days\\p7.txt", "days\\p8.txt","days\\p9.txt", "days\\p10.txt",  
		"days\\p11.txt","days\\p12.txt", "days\\p13.txt", "days\\p14.txt", "days\\p15.txt", "days\\p16.txt", "days\\p17.txt"	  
	};
	const int numberOfDays = 35;

	// shuffle all the days back into the past by 1
	int i=1;
	remove(p[i-1]);
	while(i<numberOfDays){

		int x= rename(p[i], p[i-1]);
		i++;
	}

	// then on the newest day, make a new file containing a string representing the date
	// on the furthest future day on the calendar is

	char week[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday"};

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	struct datestruct myd;
	myd.weekday = tm.tm_wday;
	myd.year=tm.tm_year + 1900;
	myd.month=tm.tm_mon;
	myd.monthday=tm.tm_mday;

	for(int i = 0; i<17; i++){
		myd = getNext(myd);
	}

	FILE *f = fopen(p[numberOfDays-1], "w");
	fprintf(f, "  %s ",week[myd.weekday]);
	fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
	fprintf(f,"_______________________________________________\n");
	fclose(f);

   return(0);
}
