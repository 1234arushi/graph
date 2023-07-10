#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>rankk,parent,sizee;
public:
    DisjointSet(int n)
    {

        rankk.resize(n+1,0);
        parent.resize(n+1);
        sizee.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            sizee[i]=1;
        }
    }
    int findupar(int node)
    {
        if(node==parent[node])
        {

            return node;
        }
        return parent[node]=findupar(parent[node]);

    }
    void unionbyrank(int u,int v)
    {

        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u == ulp_v)return;
        if(rankk[ulp_u]<rankk[ulp_v])
        {

            parent[ulp_u]=ulp_v;
        }
        else if(rankk[ulp_v]<rankk[ulp_u])
        {

            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rankk[ulp_v]++;
        }
    }
    void unionbysize(int u,int v)
    {
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u == ulp_v)return;
        if(sizee[ulp_u] < sizee[ulp_v])
        {

            parent[ulp_u]=ulp_v;
            sizee[ulp_v]+=sizee[ulp_u];
        }
        else
        {
             parent[ulp_v]=ulp_u;
            sizee[ulp_u]+=sizee[ulp_v];


        }


    }
};
int main()

{

    DisjointSet ds(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);
    ds.unionbysize(1,2);
    if(ds.findupar(3)==ds.findupar(7))
    {

        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    ds.unionbysize(3,7);
    if(ds.findupar(3)==ds.findupar(7))
    {

        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}
