#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include"utilities.h"
int main(int argc, char** argv)
{

  if(argc <= 1)
  {
    fprintf(stderr, "Usage: ./remind <time of notification as hh:mm:ss>\n");
    return 1;
  }
  struct tm *start, *end;
  int month_now, day_now, year_now;
  int count = 0;
  TIME temp;
  time_t starttime, endtime;
  time(&starttime);
  start = localtime( &starttime );

  month_now = start->tm_mon;
  day_now   = start->tm_mday;
  year_now  = start->tm_year;
  end       = (struct tm *)malloc(sizeof(struct tm));
  end->tm_mday   = day_now;
  end->tm_mon    = month_now;
  end->tm_year   = year_now;
  temp            = parseTime(argv[1]);
  end->tm_hour   = temp.hours;
  end->tm_min    = temp.minutes;
  end->tm_sec    = temp.seconds;
  endtime        = mktime(end);
  int interval    = (int)difftime(endtime, starttime);
  if(interval < 0 )
  {
    fprintf(stderr, "Error: Enter a moment in the future\n");
    return 1;
  }

  while(count < interval)
  {
    count++;
    sleep(1);
  }
  system("notify-send \"Reminder: You have something else to do \"");
  return 0;
}
