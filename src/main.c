// Ситник Станислав
// Этот файл содержит функции для определения предыдущего и следующего дня
// по заданным году, месяцу и числу

#include <stdio.h>

// Функция для определения, является ли год високосным

int isVisYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

//Функция для определения количества дней в месяце

int daysMonth(int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        return isVisYear(year) ? 29 : 28;
    } else {
        return 0; 
    }
}

//Функция для определения предыдущего дня.

void previousDay(int year, int month, int day, int *prevYear, int *prevMonth, int *prevDay) {
    if (day > 1) {
        *prevYear = year;
        *prevMonth = month;
        *prevDay = day - 1;
    } else {
        if (month > 1) {
            *prevMonth = month - 1;
            *prevYear = year;
            *prevDay = daysMonth(year, *prevMonth);
        } else {
            *prevMonth = 12;
            *prevYear = year - 1;
            *prevDay = daysMonth(*prevYear, *prevMonth);
        }
    }
}

