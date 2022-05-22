#include <iostream>
#include <time.h>
#include <string.h>
#include "Plurality.h"
#define rnd rand() % 5 + 5

using namespace std;

char* random_line(const int len) {
  static const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char* res = new char[len+1];
  for (int i = 0; i < len; ++i)
    res[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
  res[len] = '\0';
  return res;
}

int get_len(char* len) {
  int length = 0;
  while (len[length] != '\0')
    length++;
  return length;
}

template <typename T>
int get_difference(T* array, int count) {
  T min = array[0], max = array[0];
  for (size_t i = 0; i < count; i++) {
    max = array[i] > max ? array[i] : max;
    min = array[i] < min ? array[i] : min;
  }
  return max - min;
}

template <>
int get_difference(char** array, int count) {
  int min = get_len(array[0]), max = get_len(array[0]);
  for (size_t i = 0; i < count; i++) {
    max = get_len(array[i]) > max ? get_len(array[i]) : max;
    min = get_len(array[i]) < min ? get_len(array[i]) : min;
  }
  return max - min;
}

enum types {INTEGER = 1, CHAR, FLOAT, DOUBLE, CHARS};
enum actions {};

int main() {
  srand(time(NULL));
  int task, act, type;
  bool is_exit = false;
  cout << "Select task (1 - difference, 2 - plurality): "; cin >> task;
  if (task == 1) {
    while (!is_exit) {
      cout << "Select type (1 - int, 2 - char, 3 - float, 4 - double, 5 - char*): "; cin >> type;
      system("cls");
      if (type == INTEGER) { 
        int count = rnd, array[rnd];
        for (size_t i = 0; i < count; i++)
          array[i] = rnd;
        cout << get_difference<int>(array, count) << endl;
      } 
      else if (type == CHAR) { 
        int count = rnd;
        char array[rnd];
        for (size_t i = 0; i < count; i++)
          array[i] = rnd;
        cout << get_difference<char>(array, count) << endl;
      } 
      else if (type == FLOAT) { 
        int count = rnd;
        float array[rnd];
        for (size_t i = 0; i < count; i++)
          array[i] = rnd;
        cout << get_difference<float>(array, count) << endl;
      } 
      else if (type == DOUBLE) { 
        int count = rnd;
        double array[rnd];
        for (size_t i = 0; i < count; i++)
          array[i] = rnd;
        cout << get_difference<double>(array, count) << endl;
      } 
      else if (type == CHARS) { 
        int count = rnd;
        char* array[rnd];
        for (size_t i = 0; i < count; i++)
          array[i] = (char*)random_line(rnd);
        cout << get_difference<char*>(array, count) << endl;
      }
    }
  } else if (task == 2) {
    while (!is_exit) {
      cout << "Select type (1 - int, 2 - char, 3 - float, 4 - double, 5 - char*): "; cin >> type;
      system("cls");
      if (type == INTEGER) { 
        int count1, count2;
        cout << "Enter count in first array: "; cin >> count1;
        int array1[count1];
        try {
          for (size_t i = 0; i < count1; i++)
            cin >> array1[i];
          cout << "Enter count in second array: "; cin >> count2;
          int array2[count2];
          for (size_t i = 0; i < count2; i++)
            cin >> array2[i];
          Plurality<int> pl1(array1, count1), pl2(array2, count2);
          pl1.print(), pl2.print();
          cout << "Select action (1 - *, 2 - +, 3 - <): "; cin >> act;
          if (act == 1) (pl1 * pl2).print();
          else if (act == 2) (pl1 + pl2).print();
          else if (act == 3) cout << (pl1 < pl2) << endl;
        } catch (const std::exception& e) {
          cout << e.what() << '\n';
        }
      } 
      else if (type == CHAR) { 
        int count1, count2;
        cout << "Enter count in first array: "; cin >> count1;
        char array1[count1];
        for (size_t i = 0; i < count1; i++)
          cin >> array1[i];
        cout << "Enter count in second array: "; cin >> count2;
        char array2[count2];
        for (size_t i = 0; i < count2; i++)
          cin >> array2[i];
        Plurality<char> pl1(array1, count1), pl2(array2, count2);
        pl1.print(), pl2.print();
        cout << "Select action (1 - *, 2 - +, 3 - <): "; cin >> act;
        if (act == 1) (pl1 * pl2).print();
        else if (act == 2) (pl1 + pl2).print();
        else if (act == 3) cout << (pl1 < pl2) << endl;
      } 
      else if (type == FLOAT) { 
        int count1, count2;
        cout << "Enter count in first array: "; cin >> count1;
        float array1[count1];
        for (size_t i = 0; i < count1; i++)
          cin >> array1[i];
        cout << "Enter count in second array: "; cin >> count2;
        float array2[count2];
        for (size_t i = 0; i < count2; i++)
          cin >> array2[i];
        Plurality<float> pl1(array1, count1), pl2(array2, count2);
        pl1.print(), pl2.print();
        cout << "Select action (1 - *, 2 - +, 3 - <): "; cin >> act;
        if (act == 1) (pl1 * pl2).print();
        else if (act == 2) (pl1 + pl2).print();
        else if (act == 3) cout << (pl1 < pl2) << endl;
      }
      else if (type == DOUBLE) { 
        int count1, count2;
        cout << "Enter count in first array: "; cin >> count1;
        double array1[count1];
        for (size_t i = 0; i < count1; i++)
          cin >> array1[i];
        cout << "Enter count in second array: "; cin >> count2;
        double array2[count2];
        for (size_t i = 0; i < count2; i++)
          cin >> array2[i];
        Plurality<double> pl1(array1, count1), pl2(array2, count2);
        pl1.print(), pl2.print();
        cout << "Select action (1 - *, 2 - +, 3 - <): "; cin >> act;
        if (act == 1) (pl1 * pl2).print();
        else if (act == 2) (pl1 + pl2).print();
        else if (act == 3) cout << (pl1 < pl2) << endl;
      } 
      else if (type == CHARS) { 
        int count1, count2;
        cout << "Enter count in first array: "; cin >> count1;
        char* array1[count1];
        string s;
        for (size_t i = 0; i < count1; i++) {
          cin >> s;
          array1[i] = new char[s.length()];
          strcpy(array1[i], s.c_str());
        }
        cout << "Enter count in second array: "; cin >> count2;
        char* array2[count2];
        for (size_t i = 0; i < count2; i++) {
          cin >> s;
          array2[i] = new char[s.length()];
          strcpy(array2[i], s.c_str());
        }
        Plurality<char*> pl1(array1, count1), pl2(array2, count2);
        pl1.print(), pl2.print();
        cout << "Select action (1 - *, 2 - +, 3 - <): "; cin >> act;
        if (act == 1) (pl1 * pl2).print();
        else if (act == 2) (pl1 + pl2).print();
        else if (act == 3) cout << (pl1 < pl2) << endl;
      }
    }
  }
  return 0;
}