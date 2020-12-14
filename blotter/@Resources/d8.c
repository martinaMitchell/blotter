#include <time.h>
#include <string.h>
#include <stdio.h>

struct datestruct{
	int weekday;	//day of the week
	int monthday;	//day of the month
	int month;	//the month
	int year;	// year
};


struct datestruct getNext(struct datestruct myd){

	struct datestruct n;
	n.weekday=(myd.weekday +1) % 7;
	n.year=myd.year;

	
	if(myd.month >= 11){
		n.month = 11;
	 	if(myd.monthday>=31){// happy new year
			n.month = 0;
			n.monthday = 1;
			n.year+=1;}else{n.monthday = myd.monthday+1;}
		return n;
	}else if(myd.month == 10){ 
		if(myd.monthday>=30){
			n.month = 11; 
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 9){
		if(myd.monthday>=31){
			n.month = 10;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 8){
		if(myd.monthday>=30){
			n.month = 9;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 7){//august to september
		if(myd.monthday>=31){
			n.month = 8;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 6){//july to august
		if(myd.monthday>=31){
			n.month = 7;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 5){//june
		if(myd.monthday>=30){
			n.month = 6;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 4){ //may
		if(myd.monthday>=31){
			n.month = 5;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 3){ //april
		if(myd.monthday>=30){
			n.month = 4;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 2){ //march
		if(myd.monthday>=31){
			n.month = 3;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 1){//february
		if(myd.monthday>=28){
			n.month = 2;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}else if(myd.month == 0){//january
		if(myd.monthday>=31){
			n.month = 1;
			n.monthday = 1;
		}else{n.monthday = myd.monthday+1;}
	}


	//printf("%i", n.month);


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

struct datestruct todaysDate(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	struct datestruct myd;
	myd.weekday = tm.tm_wday;
	myd.year=tm.tm_year + 1900;
	myd.month=tm.tm_mon;
	myd.monthday=tm.tm_mday;

	return myd;

}

struct datestruct dateFromFile(const char *filename){
	FILE *fp = fopen(filename, "r");
	char buff[60];
	fgets( buff, 255, fp);

	//parse into a date


	struct datestruct myd;

	char* word;
	word=(char*)strtok(buff, " ");
	if(strcmp(word, "Sunday")==0){myd.weekday=0;}  
	if(strcmp(word, "Monday")==0){myd.weekday=1;}
	if(strcmp(word, "Tuesday")==0){myd.weekday=2;}
	if(strcmp(word, "Wednesday")==0){myd.weekday=3;}
	if(strcmp(word, "Thursday")==0){myd.weekday=4;}
	if(strcmp(word, "Friday")==0){myd.weekday=5;}
	if(strcmp(word, "Saturday")==0){myd.weekday=6;}

	myd.year=atoi((char*)strtok(NULL, "-"));
	myd.month=atoi((char*)strtok(NULL, "-"));
	myd.month--;
	myd.monthday =atoi((char*)strtok(NULL, "-"));

	fclose(fp); 
	return myd;
}
//void main(){return;}

