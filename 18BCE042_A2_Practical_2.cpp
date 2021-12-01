#include<stdio.h>
char lookAhead;
int error = 0;

void parseError(){
  error = 1;
  printf("Unmatched");
}

void match(char ch)
{
  if(lookAhead == ch){
    lookAhead = getchar();
  }
  else parseError();
}

void T(){
  if(lookAhead == '+'){
    match('+');
    match('l');
    T();
  }
  else if(lookAhead=='r'){
    match('r');
  } else parseError();
}

void S(){
  match('l');
  T();
}

int main()
{
  lookAhead = getchar();
  S();
  if(lookAhead == '$' && error ==0){
    printf("Matched");
  }
  return 0;
}


/*
S -> l T
T -> + l T | r
*/
