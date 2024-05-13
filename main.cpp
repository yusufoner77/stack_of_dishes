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

class DishStack {
  private:
    Dish stack[50];
    int index;

  public:
    DishStack() {
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

    // One Credit Add-on: Clear Method
    void clear() {
      index = -1;
    }
};

// 2 Credit Add-on: Real World Example of a Stack
/*
A real world example of a stack are the back and forward buttons on a web browser. This is accomplished by maintaining two separate stacks. The "back" stack is used to track links
to previously visited pages, and the "forward" stack tracks links to the pages we've left but may want to revisit.

As we navigate through pages on the web, if we click on a link we will be pushing our current page to the top of the "back" stack before going to the next page.

Pressing the back button will store our current page at the top of the forward stack, and the top page from the back stack is popped off and loaded in as the new current window.
Pressing the forward button will push our current page to the top of the back stack, and the top page from the forward stack is popped off and loaded in as the new current window.

Source: https://www.enjoyalgorithms.com/blog/application-of-stack-data-structure-in-programming
*/

int main() {
  DishStack stack;
  Dish one_dish = Dish("A dish with one fish pattern on it");
  Dish two_dish = Dish("A dish with two fish patterns on it");
  Dish red_dish = Dish("A dish with a red fish pattern on it");
  Dish blue_dish = Dish("A dish with a blue fish pattern on it");

  // The variable stack_size should equal zero.
  int stack_size = stack.size();
  cout << stack_size << endl;

  stack.push(one_dish);
  stack.push(two_dish);
  stack.push(red_dish);
  stack.push(blue_dish);

  // The variable size_after_pushes should equal four.
  int size_after_pushes = stack.size();
  cout << size_after_pushes << endl;

  // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
  Dish peeked_dish = stack.peek();
  cout << peeked_dish.get_description() << endl;

  // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
  Dish popped_dish = stack.pop();
  cout << popped_dish.get_description() << endl;

  // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
  Dish another_popped_dish = stack.pop();
  cout << another_popped_dish.get_description() << endl;

  // The variable final_size should equal two.
  int final_size = stack.size();
  cout << final_size << endl;

  // This should trigger an error message that the stack is full
  for (int i = 0; i < 49; i ++) {
    stack.push(one_dish);
  }

  // This should trigger an error message that you can't pop an empty stack
  for (int i = 0; i < 51; i++) {
    stack.pop();
  }
}