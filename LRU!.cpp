 #include<stdio.h>
 #include <windows.h>
 
int main()

{
	system("Color b1");
	
int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];

printf("Enter no of pages:");

scanf("%d",&n);   


printf("Enter the reference string:");

for(i=0;i<n;i++)
   
   scanf("%d",&p[i]);// enter pages
   
printf("Enter no of frames:");

scanf("%d",&f);

q[k]=p[k];

printf("\n\t%d\n",q[k]);

c++;  //counter for page miss

k++;


for(i=1;i<n;i++)

            {

                        c1=0;

                        for(j=0;j<f;j++)   // checking in the frame

                        {

                                    if(p[i]!=q[j])

                                    c1++;

                        }

                        if(c1==f) // not found anywhere in q , ie page fault

                        {

                                    c++;

                                    if(k<f)   // check for space in frame

                                    {

                                                q[k]=p[i];     // k is the index to frame

                                                k++;

                                                for(j=0;j<k;j++)

                                                printf("\t%d",q[j]);

                                                printf("\n");

                                    }

                                    else  // LRU

                                    {

                                                for(r=0;r<f;r++)

                                                {

                                                            c2[r]=0;

                                                            for(j=i-1;j<n;j--)

                                                            {

                                                            if(q[r]!=p[j])   // maintaining counter for least recently used

                                                            c2[r]++;

                                                            else

                                                            break;

                                                	     }

                                   		 }

                                    for(r=0;r<f;r++)

                                     b[r]=c2[r];

                                    for(r=0;r<f;r++)

                                    {

                                                for(j=r;j<f;j++)

                                                {

                                                            if(b[r]<b[j])

                                                            {

                                                                        t=b[r];

                                                                        b[r]=b[j];

                                                                        b[j]=t;     // swapping to make the lru at 0th index

                                                            }

                                                }

                                    }

                                    for(r=0;r<f;r++)
                                    {
                                   
								                if(c2[r]==b[0])   

                                                q[r]=p[i];     // replacing
                                   
								                printf("\t%d",q[r]);
                                    }
                                   
								    printf("\n");
                                   
								     }  // end else
                                     
          
		    }  // end main if
            
}  // end for

printf("\nThe no of page faults is %d",c);

} // end main








