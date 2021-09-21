
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
repeat and missing
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
approach 1: hashing
      int *findTwoElement(int *a, int n) {
        // code here
        int *res = new int(2);
        unordered_map<int,int>m;
        int r,mi;
        for(int i=0;i<n;i++)m[a[i]]++;
        for(int i=0;i<n;i++)
        {
            if(m[a[i]]==2)
              r=a[i];
              
              if(m[i+1]==0)
                 mi=i+1;
              
        }
        res[0]=r;
        res[1]=mi;
        
        
        
        return res;
    }

approach 2: 2 equations 
       tc:o(n)
       sc:o(1)
  int *findTwoElement(int *a, int n) {
        // code here
       
        int *res = new int(2);
         long long s=(n*(n+1))/2;
         long long s2=(n*(n+1)*(2*n+1))/6;
         long long x=0,y=0;
        for(int i=0;i<n;i++)
        { x+=a[i];
          y+=a[i]*a[i];    
        }
       x=s-x;
       y=s2-y;
    int p,q,m,r;
      q=y/x;
    
   
      m=(x+q)/2;
      r=m-x;    
       res[0]=r;
       res[1]=m;
        return res;
    }


approach 3:
     XOR OPERATION
     tc:o(n)
     sc:o(1)

     int *findTwoElement(int *a, int n) {
        // code here
        int *res = new int(2);
          int x=0,y=0;
         for(int i=0;i<n;i++)
           { x=x^(a[i]);
             y=y^(i+1);  
           }
         
         int z=x^y;
        
         int b1=0,b2=0;
         
         //to find rightmost set bit
            int setno= z&(~z+1);
            
          for(int i=0;i<n;i++)
          {  if(a[i]&setno)
                b1=b1^a[i];
                else
                b2=b2^a[i];
              
          }
        
          for(int i=1;i<=n;i++)
          {  if(i&setno)
                b1=b1^i;
                else
                b2=b2^i;
              
          }
          
          int c=0;
           for(int i=0;i<n;i++)
           { if(a[i]==b1)
                c++;
           }
           int r,m;
           if(c==2)
             {r=b1;m=b2;}
             else
              {r=b2;m=b1;}
         res[0]=r;
         res[1]=m;
        return res;
    } 


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
MERGE WITHOUT EXTRA  SPACE  
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

approach 3:
      GAP METHOD 
       
       

approach 4:
      taking advantage it is sorted 
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for(long long i=n-1,j=0;i>=0&&j<m;i--)
             { if(arr1[i]>arr2[j])
                  { swap(arr1[i],arr2[j]);
                     j++;
                  }
                 else
                 break;
                 
             }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
           
        }     



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Kadane's Algorithm 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22
    approach 1 : calcualte all sub arrays
        tc : o(n *n)
         sc : o(1)

   int maxSubarraySum(int a[], int n)
{
  int m = a[0];

  for (int i = 0; i < n; i++)
  {
    int s = 0;
    for (int j = i; j < n; j++)
    {
      s = s + a[j];
      m = max(s, m);
    }
  }

  return m;
}

approach 2 : kadane algo
            tc : o(n)
           sc : o(1)

   int maxSubarraySum(int a[], int n)
{
  int s = 0, m = a[0];

  for (int i = 0; i < n; i++)
  {
    s = s + a[i];
    m = max(s, m);
    if (s < 0)
      s = 0;
  }

  return m;
}

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Merge Intervals
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

approach 1: NAIVE
     o(n*n) +o(nlogn)
     o(1)

 approach 2: stack
     o(n) +o(nlogn)
     o(n)  


 approach 3: 
     o(n) +o(nlogn)
     o(1)



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
SET MATRIX ZERO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Approach 1 :   setting paricular row and column as -1 (works only if matrix is boolean)
          
          TC: o(n*m)*o(n+m) +o(n*m)
          SC:o(1)
void setZeroes(vector<vector<int>>& v)
    {    
     
    int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++)
           { for(int j=0;j<m;j++)
                 { if(v[i][j]==0)
                    { for(int k=0;k<n;k++)
                          {  if(v[k][j]!=0)v[k][j]=-1;}
                      for(int k=0;k<m;k++)
                        { if(v[i][k]!=0) v[i][k]=-1;}
                    }
        
                 }
           }
    
    
          for(int i=0;i<n;i++)
           { for(int j=0;j<m;j++)
                  {if(v[i][j]==-1)
                       v[i][j]=0;
                      
                  }
           }      
             
    }  
Approach 2 :    using two extra vector to mark which col and row should be zero
          
          TC: o(n*m) +o(n*m) +o(n*m)
          SC:o(n)+o(m)
void setZeroes(vector<vector<int>>& v)
    {    int n=v.size();
         int m=v[0].size();
        
     vector<int>row(n,1);
      vector<int>col(m,1);
     
        for(int i=0;i<n;i++)
           { for(int j=0;j<m;j++)
                 { if(v[i][j]==0)
                    {row[i]=0;
                     col[j]=0;
                    }
                 }
           }
    
    
          for(int i=0;i<n;i++)
           {   if(row[i]==0)
                { for(int j=0;j<m;j++)
                  v[i][j]=0;
                }
           }      
             
          for(int i=0;i<m;i++)
           {   if(col[i]==0)
                {
                 for(int j=0;j<n;j++)
                  v[j][i]=0;
                }
           } 
    }

Approach 2 :    In same matrix mark which col and row should be zero
                using first row and first column of same matrix
          
          TC: o(n*m) +o(n*m) +o(n*m)
          SC:o(1)

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
INVERSIONS IN AN ARRAY
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Approach 1 :   
          TC: o(n*n)
          SC:o(1)
   long long int inversionCount(long long a[], long long n)
    {
       long long c=0;
       
        for(long long i=0;i<n;i++)
            { for(long long j=i+1;j<n;j++)
               {  if(a[i]>a[j]&&i<j)
                        c++;
               }
            }  
        
        return c;
    }

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
stock buy and sell
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


      int maxProfit(vector<int>& a) {
       
         int profit=0;
        
        for(int i=0;i<a.size();i++)
        {
           for(int j=i+1;j<a.size();j++)
              
                   profit=max(a[j]-a[i],profit);
        
        
        }
        
        return profit;
    }




  
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
ROTATE IMAGE
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  

approach 1: COPY IN ANOTHER MATRIX
    tc:o(n*n)+o(n*n)
    sc:o(n*n)

    void rotate(vector<vector<int>>& matrix)
    {   int n=matrix.size();
         
        vector<vector<int>>v(n, vector<int>(n));
     
        for(int i=0;i<n;i++)
        { for(int j=n-i-1,k=0;k<n;k++)
            v[k][j]=matrix[i][k];
        }
        for(int i=0;i<n;i++)
        { for(int j=0;j<n;j++)
           matrix[i][j]=v[i][j];
        }
        
        
    }

    approach 2:  TRANSPOSE 
                 REVERSE
    tc:o(n*n)+o(n*n)
    sc:o(1)

     void rotate(vector<vector<int>>& matrix)
    {   int n=matrix.size();
         
     
        for(int i=0;i<n;i++)
        { for(int j=i;j<n;j++)
            swap(matrix[i][j],matrix[j][i]);
        }
        for(int i=0;i<n;i++)
        {  reverse(matrix[i].begin(),matrix[i].end());
        }
        
        
    }

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
NEXT PERMUTATION
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     

APPROACH 1: USING C++ STL 

       Overall time complexity is O(n).

 void nextPermutation(vector<int>& nums) {
      
        bool val= next_permutation(nums.begin(),nums.end());
       if (val == false)
           sort(nums.begin(),nums.end());
              
         
            

        
    } 
   pre-requisite / print all possible permutations/ 
APPROACH 2: GENERATE ALL PERMUTATIONS IN DICTIONARY
            ORDER  

           TC: O(n*n!).

 void nextPermutation(vector<int>& nums) {
  
  
    } 


 APPROACH 3:   