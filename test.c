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

xplor(y,x,grid)
   int x,y;
   char grid[15][25];
{
  grid[y][x]='@';
  if(grid[11,19]=="@")
    return 1;
  if(grid[y+1][x]==' ')
    xplor(y+1,x,grid);
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
  printf("I've just read in this maze:\n");
  printgrid(grid);
  printf("So let's start!\n");
  xplor(1,1,grid);
  printgrid(grid);

  printf("Welp, see ya.\n");
  fclose(fp);
  return 0;
}
