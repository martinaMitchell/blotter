
#include <stdio.h>
#include <time.h>
#include <errno.h>
extern int errno ;
struct datestruct{
	int weekday;	//day of the week
	int monthday;	//day of the month
	int month;	//the month
	int year;	// year
};

struct datestruct getNext(struct datestruct d);
struct datestruct getPrev(struct datestruct d);
int dayChanger();
int newCalendar();

int main(){
	 //check to see if we need to make a new calendar
	int check; 
    	char* dirname = "days"; 
    	check = mkdir(dirname,0777); 
  
    // check if directory is created or not 
    if (!check){ 
        newCalendar();
    }

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
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	struct datestruct myd;
	myd.weekday = tm.tm_wday;
	myd.year=tm.tm_year + 1900;
	myd.month=tm.tm_mon;
	myd.monthday=tm.tm_mday;


//today!
	FILE *f = fopen(p[17], "w");
	fprintf(f, "  %s ",week[myd.weekday]);
	fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
	fprintf(f,"_______________________________________________\n");
	fclose(f);

// the past!
	int j=1;
	for(int i=16; i>-1; i--){
		myd = getPrev(myd);
		FILE *f = fopen(p[i], "w");
		fprintf(f, "  %s ",week[myd.weekday]);
		fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
		fprintf(f, "_______________________________________________\n");
		fclose(f);

	}

// the future!
	myd.weekday = tm.tm_wday;
	myd.year=tm.tm_year + 1900;
	myd.month=tm.tm_mon;
	myd.monthday=tm.tm_mday;

	j=1;
	for(int i=18; i<35; i++){
		myd = getNext(myd);
		FILE *f = fopen(p[i], "w");

		fprintf(f, "  %s ",week[myd.weekday]);
		fprintf(f, "%i-%i-%i\n", myd.year, myd.month + 1, myd.monthday);
		fprintf(f, "_______________________________________________\n");
		fclose(f);

	}


return(0);
}


struct datestruct getNext(struct datestruct myd){
	struct datestruct n;
	n.weekday=(myd.weekday +1) % 7;
	n.month= myd.month;
	n.year=myd.year;
	n.monthday = myd.monthday+1;

	if(myd.month == 11 && myd.monthday==31){// happy new year
		n.month = 0;
		n.monthday = 0;
		n.year=myd.year+1;
	}else{
		// happy new month
		if((myd.month == 0||myd.month ==2||myd.month ==4||myd.month ==6||myd.month ==7||
				myd.month == 9) && n.monthday == 32){
			n.month = myd.month+1; 
			n.monthday = 0;

		}else if((myd.month== 3|| myd.month== 5||myd.month== 8||myd.month== 10 )&&myd.monthday == 29){
			n.month = myd.month+1; 
			n.monthday = 0;
		}else if(myd.month== 1 && ((myd.year%4!=0 && myd.monthday == 28)||(myd.year%4==0 && myd.monthday == 29) )){
			n.month = 2;
			n.monthday = 0;
		}else{ //year and month stay the same, it's just a happy new day
			n.monthday = myd.monthday+1;
		}
		

	}
	return n;
}

struct datestruct getPrev(struct datestruct myd){

	int len[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	struct datestruct n;
	n.month= myd.month;
	n.year=myd.year;
	n.monthday = myd.monthday-1;
	n.weekday=myd.weekday-1;
	if(n.weekday==-1){n.weekday = 6;}

	if(n.monthday == -1 && n.month == 0){
		n.month=11;
		n.monthday = len[n.month];
		n.year--;
	}if(n.monthday == -1){
		n.month--;
		n.monthday = len[n.month];
		if(n.month==1 && n.year%4==0){n.monthday = 29;}
	}





	return n;
}



