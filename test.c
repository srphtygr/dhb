#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

printgrid(grid,maxy,maxx)
  char grid[69][135];
  int maxy,maxx;
{
  int x,y;
  for(y=0;y<=maxy;y++)
    {
    for(x=0;x<=maxx;x++)
      printf("%c",grid[y][x]);
    printf("\n");
    }
sleep(1);
  return 0;
}

xplor(y,x,grid,maxy,maxx)
   int x,y;
   char grid[69][135];
   int maxy,maxx;
{
/*mark our spot@*/
  grid[y][x]='@';
  printgrid(grid,maxy,maxx);
  printf("We're at %d vertical and %d horizontal.\n",y,x);
/*check if we are at the end of the maze*/
  if(y==maxy && x==maxx)
    {
    printf("Yay, we made it!\n");
    exit(0);
    }
/*check if we can go south*/
  if(grid[y+1][x]==' ')
    xplor(y+1,x,grid,maxy,maxx);

/*check if we can go east*/
  if(grid[y][x+1]==' ')
    xplor(y,x+1,grid,maxy,maxx);

/*check if we can go north*/
  if(grid[y-1][x]==' ')
    xplor(y-1,x,grid,maxy,maxx);

/*check if we can go west*/
  if(grid[y][x-1]==' ')
    xplor(y,x-1,grid,maxy,maxx);
  grid[y][x]='&';
  return 0;
}

main() {
  int x=0,y=0,maxy=0,maxx=0;
  FILE * fp;
  char grid[69][135];

  if (!(fp=fopen("maze","r")))
    perror("Error opening maze.");

  while(fgets(grid[y],134,fp))
    {
    printf("%lu\n",strlen(grid[y]));
    if(strlen(grid[y])-2 > maxx)
      maxx = strlen(grid[y])-2;
      y++;
    }
  maxy=--y;
  printf("I've just read in a %d tall by %d wide maze:\n",maxy,maxx);
  printgrid(grid,maxy,maxx);
  printf("So let's start!\n");
  xplor(1,1,grid,maxy,maxx);
  printgrid(grid,maxy,maxx);

  printf("Welp, see ya.\n");
  fclose(fp);
  return 0;
}
