typedef struct adt{
  int hours;
  int minutes;
  int seconds;
}TIME;
TIME  parseTime(char* timeStr)
{
  char* token;
  char* delimiter = ":";
  int values[3], count;
  TIME moment;
  count=0;
  while( (token = strtok(timeStr, delimiter)) != NULL)
  {
    values[count++] = atoi(token);
    timeStr = NULL;
  }
  moment.hours    = values[0];
  moment.minutes  = values[1];
  moment.seconds  = values[2];
  return moment;
}
