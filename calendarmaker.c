//makes a new calendar
#include <stdio.h>
#include <errno.h>

extern int errno ;

// compile with gcc -Wall -shared -fPIC -o power.so -I/usr/include/lua5.1 -llua5.1 calendarmaker.c
int luaopen_daychanger(lua_State *L){
	lua_register(L,"newcalendar",dayChanger);
return 0;}
int luaopen_newcalendar(lua_State *L){
	lua_register(L,"newcalendar",newCalendar);
return(0);}

int newCalendar(){   

	char p[35][15]={
		"days\\m17.txt", "days\\m16.txt", "days\\m15.txt", "days\\m14.txt", "days\\m13.txt", "days\\m12.txt", "days\\m11.txt",
		"days\\m10.txt", "days\\m9.txt", "days\\m8.txt", "days\\m7.txt", "days\\m6.txt", "days\\m5.txt", "days\\m4.txt",
		"days\\m3.txt", "days\\m2.txt", "days\\m1.txt",
		"days\\today.txt",
		"days\\p1.txt", "days\\p2.txt", "days\\p3.txt",
		"days\\p4.txt", "days\\p5.txt","days\\p6.txt", "days\\p7.txt", "days\\p8.txt","days\\p9.txt", "days\\p10.txt",  
		"days\\p11.txt","days\\p12.txt", "days\\p13.txt", "days\\p14.txt", "days\\p15.txt", "days\\p16.txt", "days\\p17.txt"	  
	};
	char week[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday"};
	int numberOfDays = 18;

	struct datestruct myd = todaysDate();


	int check; 
    	char* dirname = "days"; 
    	check = mkdir(dirname,0777); 
	if (!check){


//today!
		FILE *f = fopen(p[17], "w");
		fprintf(f, "  %s ",week[myd.weekday]);
		fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
		fprintf(f,"_______________________________________________\n");
		fclose(f);

// the past!
		for(int i=16; i>-1; i--){
			myd = getPrev(myd);
			FILE *f = fopen(p[i], "w");
			fprintf(f, "  %s ",week[myd.weekday]);
			fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
			fprintf(f, "_______________________________________________\n");
			fclose(f);
		}

	// the future!
		myd = todaysDate();
		for(int i=18; i<35; i++){
			myd = getNext(myd);
			FILE *f = fopen(p[i], "w");

			fprintf(f, "  %s ",week[myd.weekday]);
			fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
			fprintf(f, "_______________________________________________\n");
			fclose(f);
		}
	}
	return(0);
}

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
	struct datestruct today = todaysDate();
	struct datestruct center = dateFromFile("days\\today.txt");
	while(today.year != center.year || today.month != center.month || today.monthday != center.monthday){

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

	// read in the date from header of the next-farthest into the future file
	struct datestruct myd = dateFromFile(p[numberOfDays-2]);

	// get the next day into the future
	myd = getNext(myd);

	// and write a file for it
	FILE *f = fopen(p[numberOfDays-1], "w");
	fprintf(f, "  %s ",week[myd.weekday]);
	fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
	fprintf(f,"_______________________________________________\n");
	fclose(f);
		
	}
   	return(0);
}










