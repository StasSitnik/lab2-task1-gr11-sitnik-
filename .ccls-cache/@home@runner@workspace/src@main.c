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

//Функция для определения следующего дня.

void nextDay(int year, int month, int day, int *nextYear, int *nextMonth, int *nextDay) {
    if (day < daysMonth(year, month)) {
        *nextYear = year;
        *nextMonth = month;
        *nextDay = day + 1;
    } else {
        if (month < 12) {
            *nextMonth = month + 1;
            *nextYear = year;
            *nextDay = 1;
        } else {
            *nextMonth = 1;
            *nextYear = year + 1;
            *nextDay = 1;
        }
    }
}

int main() {
    int year, month, day;
    int prevYear, prevMonth, prevDay;
    int nextYear, nextMonth, nextDay;

    printf("Введите год, месяц и день: ");
    scanf("%d %d %d", &year, &month, &day);

    previousDay(year, month, day, &prevYear, &prevMonth, &prevDay);
    printf("Предыдущий день: %d-%02d-%02d\n", prevYear, prevMonth, prevDay);

    nextDay(year, month, day, &nextYear, &nextMonth, &nextDay);
    printf("Следующий день: %d-%02d-%02d\n", nextYear, nextMonth, nextDay);

    return 0;
}