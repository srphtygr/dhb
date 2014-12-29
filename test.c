#include <stdio.h>
sum(x,y) {
  return(x+y);
}

main() {
  int x=4, y=7;

  printf("%d + %d = %d\n",x,y,sum(x,y));
  return 0;
}
