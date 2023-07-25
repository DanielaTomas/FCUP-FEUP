#include <stdexcept>
#include <iostream>
//1.1 e 1.2
/*
class date {
private:
  int day, month, year;
public:
  date(int m, int y) {
      try {
          if (m < 0 || m > 12 || y < 0)
              throw std::logic_error("invalid date");
          std::cout << days_in_month(m,y) << std::endl;
      }
      catch(std::logic_error& e) {
          std::cout << "Error: " << e.what() << std::endl;
      }
     days_in_month(m,y);
  }
  int get_day() const { return day; }
  int get_month() const { return month; }
  int get_year() const { return year; }
  int days_in_month(int m, int y) {
        int r;
        switch (m) {
            case 2:
                // February, test for leap year
                if ( y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0)) {
                    r = 29;
                } else {
                    r = 28;
                }
                break;
            case 1: case 3: case 5:
            case 7: case 8: case 10:
            case 12:
                r = 31; // Months with 31 days
                break;
            default:
                r = 30; // All others have 30 days
                break;
        }
        return r;
    }
};
*/

//1.3
class invalid_date : std::logic_error {
public:
    invalid_date() : logic_error("invalid date") { }
};
class date {
private:
    int day, month, year;
public:
    date(int m, int y) {
        if (m < 0 || m > 12 || y < 0)
            throw invalid_date();
        month = m;
        year = y;
        day = days_in_month(m,y);
        std::cout << day << std::endl;
    }
    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year; }
    void set_day(int d) {
        throw invalid_date();
        day = d;};
    void set_month(int m){
        throw invalid_date();
        month = m;};
    void set_year(int y){
        throw invalid_date();
        year = y;};
    int days_in_month(int m, int y) {
        int r;
        switch (m) {
            case 2:
                // February, test for leap year
                if ( y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0)) {
                    r = 29;
                } else {
                    r = 28;
                }
                break;
            case 1: case 3: case 5:
            case 7: case 8: case 10:
            case 12:
                r = 31; // Months with 31 days
                break;
            default:
                r = 30; // All others have 30 days
                break;
        }
        return r;
    }
};

int main() {
      date(11, 2002);
      date(10, 2006);
      date(34, 12);
    return 0;
}
