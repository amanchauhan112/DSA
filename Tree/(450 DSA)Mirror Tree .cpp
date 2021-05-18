 int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        // vector<pair<int,int>>va,vb;//(previously)
        
        //At first I thought to store in vector from left
        //Then chk B array from right but runtimwe error
        
        // for(int i=0;i<n;i+=2)
        // {
        //     va.push_back({A[i],A[i+1]});

        // }
        
        // for(int i=n;i>=0;i-2)
        // {
        //     vb.push_back({B[i-1],B[i]});
        // }
        // for(int i=0;i<e;i++)
        // {
        //     if(va[i]!=vb[i])
        //         return 0;
        // }
   
           
        unordered_map<int,stack<int>>mp;
   
        for(int i=0;i<2*e;i+=2) //(previously)->n now 2*e
        {

            mp[A[i]].push(A[i+1]);
        }
          for(int i=0;i<2*e;i+=2)
        {
            if(mp[B[i]].top()!=B[i+1])
                return 0;
                
            mp[B[i]].pop();    
        }
        
        return 1;
    }
