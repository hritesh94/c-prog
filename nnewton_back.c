#include<stdio.h>
#include<math.h>
float factorial(float k)
{
if(k==0)
{
return 1;
}
else return k*factorial(k-1);
}
float result (float p ,int k)
{
int m ;
float pro = 1;
if(k==0)
{
return 1;
}
for(m=0;m<k;m++)
{
pro=pro*(p+m);
}
return pro;
}

int main()
{
int i,j,k,n;
float arr[20][20],x,h,p,res=0;
printf("Enter the no of given points :\n");
scanf("%d",&n);
printf("Enter the given vlaues of x in the table;\n");
for(i=0;i<n;i++)
{
scanf("%f",&arr[i][0]);
}
printf("Enter the given values of y in the table:\n");
for(i=0;i<n;i++)
{
scanf("%f",&arr[i][1]);
}
printf("Enter the value of interpolating point: \n");
scanf("%f",&x);



for(j=2;j<n+1;j++)
{
for(i=j-2;i<n;i++)
{
arr[i+1][j]=arr[i+1][j-1]-arr[i][j-1];
}
}
printf("The backward Interpolation table : \n");
for(i=0;i<n;i++)
{

for(j=0;j<n+1;j++)
{
if(arr[i][j]==0)
{
continue;
}
else{
printf(" %.5f ",arr[i][j]);
}
}
printf("\n");
}

printf("\n");
h=arr[1][0]-arr[0][0];
p=(x-arr[n-1][0])/h;
for(k=0;k<n;k++)
{
res=res+(result(p,k)/factorial(k))*arr[n-1][k+1];
}
printf("THe value of point %.2f is %.5f",x,res);
return 0;

}
