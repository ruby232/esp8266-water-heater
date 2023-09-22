struct time_interval {
  int on_hour;
  int on_minute;
  int off_hour;
  int off_minute;
  struct time_interval *next;
};