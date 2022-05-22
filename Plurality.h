#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class Plurality {
private:
  T *items;
  int count;
public:
  Plurality(T* arr, int count) {
    try {
      items = new T[count];
      for (size_t i = 0; i < count; i++) 
        items[i] = arr[i];
    } catch(const std::exception& e) {
      cout << e.what() << '\n';
    }
    
    this->count = count;
  }

  int get_count() { return count; }
  void print() {
    for (size_t i = 0; i < count; i++)
      cout << items[i] << " ";
    cout << "\n";
  }

  T& operator[] (const int index) {
      return items[index];
  }

  friend Plurality<T> operator*(const Plurality<T> &pl1, const Plurality<T> &pl2) {
    int k = 0; int c = 0;
    for (size_t i = 0; i < pl1.count; i++)
      for (size_t j = 0; j < pl2.count; j++)
        pl1.items[i] == pl2.items[j] ? c++ : 0;
    T* res = new T[c];

    for (size_t i = 0; i < pl1.count; i++)
      for (size_t j = 0; j < pl2.count; j++)
        if (pl1.items[i] == pl2.items[j]) {
          res[k++] = pl1.items[i];
        }
    Plurality<T> newP(res, c);
    return newP;
  }

  friend Plurality<T> operator+(const Plurality<T> &pl1, const Plurality<T> &pl2) {
    int k = 0; int c = 0;
    bool check = false;

    for (size_t i = 0; i < pl2.count; i++) {
      for (size_t j = 0; j < pl1.count; j++)
        if (pl2.items[i] == pl1.items[j]) check = true; 
      !check ? c++ : 0;
      check = false;
    }
    T* res = new T[pl1.count + c];

    for (size_t i = 0; i < pl2.count; i++) {
      for (size_t j = 0; j < pl1.count; j++)
        if (pl2.items[i] == pl1.items[j]) check = true;
      if (!check) res[k++] = pl2.items[i];
      check = false;
    }

    for (size_t i = c, p = 0; i < c + pl1.count; i++, p++)
      res[i] = pl1.items[p];
  
    Plurality<T> newP(res, pl1.count + c);
    return newP;
  }

  friend bool operator<(const Plurality &pl1, const Plurality &pl2) {
    return pl1.count < pl2.count;
  }
};

template <>
class Plurality<char *> {
private:
  char** items;
  int count;
public:
  Plurality(char** arr, int count) {
    items = new char*[count];
    for (size_t i = 0; i < count; i++) {
      items[i] = arr[i];
    }
    this->count = count;
  }

  int get_count() { return count; }
  void print() {
    for (size_t i = 0; i < count; i++)
      cout << items[i] << " ";
    cout << "\n";
  }

  char*& operator[] (const int index) {
      return items[index];
  }

  friend Plurality operator*(const Plurality &pl1, const Plurality &pl2) {
    int k = 0; int c = 0;
    for (size_t i = 0; i < pl1.count; i++)
      for (size_t j = 0; j < pl2.count; j++)
        strcmp(pl1.items[i], pl2.items[j]) == 0 ? c++ : 0;
    
    char* res[c];

    for (size_t i = 0; i < pl1.count; i++)
      for (size_t j = 0; j < pl2.count; j++)
        if (strcmp(pl1.items[i], pl2.items[j]) == 0) {
          res[k++] = pl1.items[i];
        }
    Plurality<char*> newP(res, c);
    return newP;
  }

  friend Plurality operator+(const Plurality &pl1, const Plurality &pl2) {
    int k = 0; int c = 0;
    bool check = false;

    for (size_t i = 0; i < pl2.count; i++) {
      for (size_t j = 0; j < pl1.count; j++)
        if (strcmp(pl1.items[j], pl2.items[i]) == 0) check = true; 
      !check ? c++ : 0;
      check = false;
    }
    
    char* res[pl1.count + c];

    for (size_t i = 0; i < pl2.count; i++) {
      for (size_t j = 0; j < pl1.count; j++)
        if (strcmp(pl1.items[j], pl2.items[i]) == 0) check = true;
      if (!check) res[k++] = pl2.items[i];
      check = false;
    }

    for (size_t i = c, p = 0; i < c + pl1.count; i++, p++)
      res[i] = pl1.items[p];
  
    Plurality<char*> newP(res, pl1.count + c);
    return newP;
  }

  friend bool operator<(const Plurality &pl1, const Plurality &pl2) {
    return pl1.count < pl2.count;
  }
};