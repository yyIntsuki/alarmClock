#include <stdio.h>

// define functions to call
int update_time();
int format_time();
void sleep(); /* simulates real-time delay */
void alarm();

// main function
int main()
{
    // define time variables
    int present_time, time_for_alarm, newtime, time_formatted = 0;

    // inputs & scans
    printf("Please input the current time(HHMMSS): \n");
    scanf("%d", &present_time);

    printf("\nPlease input the time you wish to be alarmed(HHMMSS): \n");
    scanf("%d", &time_for_alarm);

    // displays start section of what happens
    printf("\n---\nRunning the clock...\n---\n");

    // as long as present_time is less than time_for_alarm, keep looping
    for (int i = 0; present_time != time_for_alarm; i++)
    {
        // runs format_time with present_time as parameter, note that this runs before update_time so that we get our first value for present_time
        time_formatted = format_time(present_time);

        // runs update_time with present_time as parameter, and update the present_time with the new_time we return from update_time function
        present_time = update_time(present_time);

        // second delay simulation
        sleep(1); /* sets delay before each loop (unit: second), comment this line if you do not wish the program to simulate delay of a second */
    }

    // when present_time is equal to time_for_alarm, call the alarm() function
    if (present_time == time_for_alarm)
    {
        // calls alarm() function
        alarm();
    }

    // successful execution
    return 0;
}

// handles time updates
int update_time(int time)
{
    // split integer of time into hour, minute and second
    int hour = time / 10000;
    int second = time % 100;
    int minute = (time - hour * 10000 - second) / 100;

    // increases second once each time function is called
    second++;

    /* logic behind increment of hour, minute and second
       note that this logic doesn't have error handling, 
       so if user were to input something that doesn't exist in time ranges,
       or if the time crosses into the next day, there may be unwanted results */
    if (second == 60)
    {
        minute += 1;
        second = 0;
    }
    if (minute == 60)
    {
        hour += 1;
        minute = 0;
    }
    if (hour == 24)
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    // define and combine the time integer we will return
    int new_time = hour * 10000 + minute * 100 + second;
    return new_time;
}

// handles time formatting
int format_time(int time)
{
    // split integer of time into hour, minute and second
    int hour = time / 10000;
    int second = time % 100;
    int minute = (time - hour * 10000 - second) / 100;

    /* prints out each variable above in a formatted way
       note that using %02d keeps the 2 digit appearance even if the integer is less than 10 */
    printf("%02d:%02d:%02d \n", hour, minute, second);
}

// alarm function
void alarm()
{
    // prints alarm message
    printf("ALARM\n\n");
}