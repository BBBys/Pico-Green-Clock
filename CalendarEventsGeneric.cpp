/* Events to scroll on clock display at specific dates of the year. */
/* Must be customized by user and software rebuilt. */
struct event CalendarEvent[MAX_EVENTS] =
{
  /*           "----------------- MAX 50 characters --------------" */
  { 0, JAN, 0, "> > > Debug"},  // if a valid date is put here, it will allow displaying useful 
								//debugging variables in "process_scroll_queue()" function.
  /// { 1, JAN, JINGLE_FETE, "> > > Calendar event January 1st"},  // JINGLE_FETE is available 
																	//when "PASSIVE_PIEZO_SUPPORT" 
																	// is defined.
  { 0, JAN, 0, "> > > Calendar event January 1st"},
  { 0, FEB, 0, "> > > Calendar event February 1st"},
  { 0, MAR, 0, "> > > Calendar event March 1st"},
  { 0, APR, 0, "> > > Calendar event April 1st"},
  { 17, MAY, 0, "Karin hat Geburtstag"},
  { 0, JUN, 0, "> > > Calendar event June 1st"},
  { 19, JUL, 0, "Clemens hat Geburtstag"},
  { 5, AUG, 0, "Johannes hat Geburtstag"},
  { 0, SEP, 0, "> > > Calendar event September 1st"},
  { 0, OCT, 0, "> > > Calendar event October 1st"},
  { 0, NOV, 0, "> > > Calendar event November 1st"},
  { 0, DEC, 0, "> > > Calendar event December 1st"},

  { 0, JAN, 0, "> > > Happy New Year !!"},
  { 0, MAR, 0, "> > > John's Birthday !!!"},
  /// { 1, MAR, JINGLE_BIRTHDAY, "> > > John's Birthday !!!"},  // JINGLE_BIRTHDAY is available when "PASSIVE_PIEZO_SUPPORT" is defined.
  {0, FEB, 0, "> > > Valentine's Day."},
  {0, DEC, 0, "> > > Merry Christmas !!"},
};


