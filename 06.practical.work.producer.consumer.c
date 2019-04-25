#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10


typedef struct {
  char type; // 0=fried chicken, 1=French fries , 2=Accessory
  int amount; // pieces or weight
  char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void printLog();

void produce(item *i){
  while ((first + 1) % BUFFER_SIZE == last){
    //do nothing -- no free buffer item
    printf("No free buffer item!\n");
  }
  memcpy(&buffer[first], i, sizeof(item));
  first = (first + 1) % BUFFER_SIZE;
  printLog();
}

item* consume(){
  item* i = malloc(sizeof(item));
  while (first == last){
    // do nothing -- nothing to consume
    printf("Nothing to consume!\n");
  }
  memcpy(i, &buffer[last], sizeof(item));
  last = (last + 1) % BUFFER_SIZE;
  printLog();
  return i;
}

item* create(char type, int amount, char unit){
  item* newItem = malloc(sizeof(item));
  newItem->type = type;
  newItem->amount = amount;
  newItem->unit = unit;
  return newItem;
}

void printLog() {
  printf("first = %d  last = %d\n", first, last);
  return;
}

int main() {
  item* chicken = create('1',50, '1');
  item* paper = create('2',30,'0');
  produce(chicken);
  produce(paper);
  consume();
  return 0;
}


