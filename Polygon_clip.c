
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawpolygon(float[][3],int);
void lclip(float [][3],int);
void rclip(float[][3],int);
void bclip(float[][3],int);
void tclip(float[][3],int);
float xmin=100,ymin=100,xmax=200,ymax=200;

void drawpolygon(float a[100][3],int n)
{
int i;
	for(i=0;i<n;i++)
	{
	line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}
}

void lclip(float a[100][3],int n)//Left Clipping
{
int i,k=0;
float p[100][3];
	for(i=0;i<n;i++)
	{
	if(a[i][0]<xmin && a[i+1][0]>=xmin)
		{
		p[k][1]=a[i][1]+(((a[i+1][1]-a[i][1])/(a[i+1][0]-a[i][0]))*(xmin-a[i][0]));
p[k][0]=xmin;
k++;
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}

if(a[i][0]>=xmin && a[i+1][0]>=xmin)
{
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}
if(a[i][0]>=xmin && a[i+1][0]<xmin)
{
p[k][1]=a[i][1]+(((a[i+1][1]-a[i][1])/(a[i+1][0]-a[i][0]))*(xmin-a[i][0]));
p[k][0]=xmin;
k++  ;
}
}
for(i=0;i<k;i++)
{
a[i][0]=p[i][0];
a[i][1]=p[i][1];
printf("after left %f %f",p[i][0],p[i][1]);
}
  a[k][0]=p[0][0];
  a[k][1]=p[0][1];

  rectangle(xmin,ymin,xmax,ymax);
//printf(" %f %f",a[k][0],a[k][1]);
setcolor(2);
outtextxy(100,250,"Left Clipping");
drawpolygon(a,k);

getch();
//delay(1000);
cleardevice();
rclip(a,k);
}
void rclip(float a[100][3],int n)//Right Clipping
{
int i,k=0;
float p[100][3];
	for(i=0;i<n;i++)
	{
	if(a[i][0]>xmax && a[i+1][0]<=xmax)
		{
		p[k][1]=a[i][1]+(((a[i+1][1]-a[i][1])/(a[i+1][0]-a[i][0]))*(xmax-a[i][0]));
p[k][0]=xmax;
k++;
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}

if(a[i][0]<=xmax && a[i+1][0]<=xmax)
{
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}
if(a[i][0]<=xmax && a[i+1][0]>xmax)
{
p[k][1]=a[i][1]+(((a[i+1][1]-a[i][1])/(a[i+1][0]-a[i][0]))*(xmin-a[i][0]));
p[k][0]=xmax;
k++  ;
}
}
for(i=0;i<k;i++)
{
a[i][0]=p[i][0];
a[i][1]=p[i][1];
printf("after left %f %f",p[i][0],p[i][1]);
}

  a[k][0]=p[0][0];
  a[k][1]=p[0][1];
printf("after left %f %f",a[k][0],a[k][1]);
outtextxy(100,250,"Right Clipping");
  setcolor(WHITE);
  rectangle(xmin,ymin,xmax,ymax);
setcolor(GREEN);
drawpolygon(a,k);
getch();
//delay(1000);
clrscr();
bclip(a,k);

}
void bclip(float a[100][3],int n)//Bottom Clipping
{
int i,k=0;
float p[100][3];
	for(i=0;i<n;i++)
	{
	if(a[i][1]>ymax && a[i+1][1]<=ymax)
		{
		p[k][0]=a[i][0]+((ymax-a[i][1])*(a[i+1][0]-a[i][0])/(a[i+1][1]-a[i][1]));
p[k][1]=ymax;
k++;
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}


if(a[i][1]<=ymax && a[i+1][1]<=ymax)
{
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}
if(a[i][1]<=ymax && a[i+1][1]>ymax)
{
	p[k][0]=a[i][0]+((ymax-a[i][1])*(a[i+1][0]-a[i][0])/(a[i+1][1]-a[i][1]));
p[k][1]=ymax;
k++  ;
}
}
for(i=0;i<k;i++)
{
a[i][0]=p[i][0];
a[i][1]=p[i][1];
printf("after left %f %f",p[i][0],p[i][1]);
}

  a[k][0]=p[0][0];
  a[k][1]=p[0][1];
printf("after left %f %f",a[k][0],a[k][1]);
outtextxy(100,250,"Bottom Clipping");
  setcolor(WHITE);
  rectangle(xmin,ymin,xmax,ymax);
setcolor(RED);
drawpolygon(a,k);


getch();
cleardevice();
tclip(a,k);
}

void tclip(float a[100][3],int n)//Top Clipping
{
int i,k=0;
float p[100][3];
	for(i=0;i<n;i++)
	{
	if(a[i][1]<ymin && a[i+1][1]>=ymin)
		{
		p[k][0]=a[i][0]+((ymin-a[i][1])*(a[i+1][0]-a[i][0])/(a[i+1][1]-a[i][1]));
p[k][1]=ymin;
k++;
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}

if(a[i][1]>=ymin && a[i+1][1]>=ymin)
{
p[k][0]=a[i+1][0];
p[k][1]=a[i+1][1];
k++;
}
if(a[i][1]>=ymin && a[i+1][1]<ymin)
{
	p[k][0]=a[i][0]+((ymin-a[i][1])*(a[i+1][0]-a[i][0])/(a[i+1][1]-a[i][1]));
p[k][1]=ymin;
k++  ;
}
}
for(i=0;i<k;i++)
{
a[i][0]=p[i][0];
a[i][1]=p[i][1];
printf("after left %f %f",p[i][0],p[i][1]);
}

  a[k][0]=p[0][0];
  a[k][1]=p[0][1];
printf("after left %f %f",a[k][0],a[k][1]);
  setcolor(WHITE);
  rectangle(xmin,ymin,xmax,ymax);
setcolor(RED);
drawpolygon(a,k);
//delay(600);
//clrscr();
getch();
}
void main()
{
	    int n=3,gd=DETECT,gm,j;
	    float m;
	//float a[100][3];
	  float a[100][3]={{50,220},{220,220},{130,70},{50,220}};
          int i,x,y;
	    clrscr();  
	    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   //printf("Enter  clipping window:\n");
   // scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);

	/*    printf("Enter no of edges\n");

	    scanf("%d",&n);
printf("enter polygon coordinate");
for(i=0;i<=n;i++)
{

scanf("%f%f",&a[i][0],&a[i][1]);

}                                 
	     for(i=0;i<n;i++)
printf("values are  %f %f",a[i][0],a[i][1]);*/
	      rectangle(xmin,ymin,xmax,ymax);
	    drawpolygon(a,n);
	    getch();
	    clrscr();

	lclip(a,n);
	    getch();
	     closegraph();
}
