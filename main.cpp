#include <string>
#include <array>
#include <iostream>

using namespace std;

class Dish {
  private:
    string description;

  public:
    Dish() {}

    Dish(string description) {
      this->description = description;
    }

    string get_description() {
      return this->description;
    }
};

class Stack {
  private:
    Dish stack[50];
    int index;

  public:
    Stack() {
      index = -1;
    }

    void push(Dish d) {
      if (index == 49) {
        cout << "The stack is full, cannot add another dish.\n";
      }
      else {
        index++;
        stack[index] = d;
      }
    } 

    Dish pop() {
      if (index == -1) {
        Dish blank_dish;
        cout << "The stack is empty, there is nothing to pop.\n";
        return blank_dish;
      }
      else {
        Dish popped_dish = stack[index];
        index--;
        return popped_dish;
      }
    }

    Dish peek() {
      if (index == -1) {
        Dish blank_dish;
        cout << "The stack is empty, there is nothing to peek at.\n";
        return blank_dish;
      }
      else {
        Dish peeked_dish = stack[index];
        return peeked_dish;
      }
    }

    int size() {
      return index + 1;
    }
};

int main() {

}