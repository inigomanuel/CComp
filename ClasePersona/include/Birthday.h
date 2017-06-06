#ifndef BIRTHDAY_H
#define BIRTHDAY_H

class Birthday
{
    private:
        int year,month,day;
    public:
        Birthday();
        Birthday(int year1,int month1,int day1);
        ~Birthday();
        int getYear();
        int getMonth();
        int getDay();
};

#endif // BIRTHDAY_H
