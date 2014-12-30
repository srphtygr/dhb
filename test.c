#include <stdio.h>

printgrid(grid)
  char grid[15][25];
{
  int x,y;
  for(y=1;y<=12;y++)
    {
    for(x=0;x<=19;x++)
      printf("%c",grid[y][x]);
    printf("\n");
    }
  return 0;
}

xplor(grid)
   char grid[15][25];
{
  grid[1][2]='@';
  return 0;
}

main() {
  int x=1,y=1;
  FILE * fp;
  char grid[15][25];

  if (!(fp=fopen("m","r")))
    perror("Error opening m.");

  while(fgets(grid[y++],80,fp))
    ;
  printgrid(grid);
  xplor(grid);
  printgrid(grid);

  printf("Welp, see ya.\n");
  fclose(fp);
  return 0;
}
