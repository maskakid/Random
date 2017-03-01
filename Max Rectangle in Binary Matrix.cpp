// http://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
// problem link: https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
#include<bits/stdc++.h>
using namespace std;

int histogram(vector<int>A)
{
    int ans=0;
    stack<int>st;

    int i=0;

    int sz=A.size();

    while(i<sz)
    {
        if(st.empty() or A[st.top()]<=A[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int x=st.top();
            st.pop();

            int mx= (st.empty()? i: (i-st.top()- 1) )* A[x];

            ans=max(ans,mx);
        }
    }

    while(!st.empty())
    {
        int x=st.top();
            st.pop();

            int mx= (st.empty()? i: (i-st.top()- 1) )* A[x];

            ans=max(ans,mx);
    }

    return ans;
}

int rectangle(vector<vector<int>>vc )
{
    int col=vc[0].size();
    int row=vc.size();

    int mx=histogram(vc[0]);
    for(int i=1 ; i<row; i++)
    {
        for(int j=0 ;j<col ; j++ )
        {
            if(vc[i][j]==1)
            vc[i][j]+=vc[i-1][j];
        }
        mx=max(mx,histogram(vc[i]));

    }
    return mx;
}

int main()
{
    vector<vector<int>>A={ {1 ,1 ,1}, {0 ,1, 1},  {1 ,0 ,0 } };
    return rectangle(A);
}
