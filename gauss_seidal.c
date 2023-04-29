#include<stdio.h>
#include<math.h>
    int main()
    {
        float a[30][30],b[30],sum=0,newx[30]={0},oldx[30]={0},tor;
        int n,i,j,c=0;
        printf("Enter the no. of equations:\n");
        scanf("%d",&n);
        printf("Enter the values of the coeffients row-wise:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                    scanf("%f",&a[i][j]);
            }
        }
        printf("Enter the values of the right hand constants of the equations:\n");
        for(j=0;j<n;j++)
        {
            scanf("%f",&b[j]);
        }
        printf("Enter the tolerrence limit:\n");
        scanf("%f",&tor);
        do
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        sum=sum+(a[i][j]*newx[j]);
                    }
                }
                oldx[i]=newx[i];
                newx[i]=(b[i]-sum)/a[i][i];
                sum=0;
            }
            for(i=0;i<n;i++)
            {
                if(fabs(newx[i]-oldx[i])<tor)
                {
                    c++;
                }
            }
        } while (c<n);
        printf("The solution is:\n");
        for(j=0;j<n;j++)
        {
            printf("%f\n",newx[j]);
        }
        return 0;
    }