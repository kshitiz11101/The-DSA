map<int,int>m;
          
          map<int,int>result;
          vector<int>ans;

          for(int i=0;i<nums1.size();i++)
          m[nums1[i]]++;


          for(int i=0;i<nums2.size();i++)
          {
              if(m.find(nums2[i])!=m.end())
               result[nums2[i]]++;
          }

          for(auto i:result)
          {
              ans.push_back(i.first);
          }

          return ans;