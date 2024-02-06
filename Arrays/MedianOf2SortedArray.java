class GFG 

{ 

    static double medianOfArrays(int n, int m, int a[], int b[]) 

    {

         int c[] = new int[m +n];

          int s=0;

          for(int i=0;i<n;i++) {

           c[s] = a[i];

           s++;

          }

          for(int i=0;i<m;i++) {

          c[s] = b[i];

          s++;

         }

         Arrays.sort(c);

                  if((m+n)%2==0) {

                 int  d = (m+n)/2;

                 int  e =((m+n)-1)/2;

                double j  = ((double)c[d] + c[e])/2;

                 return j;

                  }

                  else

                  return c[(int )((m+n)-1)/2];

        

    }

}