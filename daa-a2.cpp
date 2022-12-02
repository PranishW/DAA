#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, int src,vector<vector<int> > &a )
{
 	vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<a.size();j++){
            int u=a[j][0];
            int v=a[j][1];
            int d=a[j][2];
            if(dist[u]!=INT_MAX&&dist[u]+d<dist[v])
                dist[v]=dist[u]+d;
        }
    }
    bool isNegativeCycle=false;
    for(int j=0;j<a.size();j++){
        int u=a[j][0];
        int v=a[j][1];
    	int d=a[j][2];
		if(dist[u]!=INT_MAX&&dist[u]+d<dist[v]){
            dist[v]=dist[u]+d;
            isNegativeCycle=true;
        }
    }
    if(isNegativeCycle)
       cout<<"Negative Cycle Present"<<endl;
    else{
       for(int i=1;i<n+1;i++)
    		cout<<dist[i]<<" ";
        cout<<endl;
    }
}

int main(){
    cout<<"Enter Number of Vertices: ";
    int n;
    cin>>n;
    cout<<"Enter Number of Edges: ";
    int m;
    cin>>m;
    cout<<"Enter Source Node: ";
    int src;
    cin>>src;
    vector<vector<int> > a;
    for(int i=0;i<m;i++){
        int u,v,dist;
        cin>>u>>v>>dist;
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edge.push_back(dist);
        a.push_back(edge);

    }
    solve(n,m,src,a);
	return 0;
}
 /* Output
	Enter Number of Vertices: 5
	Enter Number of Edges: 8
	Enter Source Node: 1
	1 2 -1
	1 3 4
	2 3 3
	2 4 2
	2 5 2
	4 2 1
	4 3 5
	5 4 -3
	0 -1 2 -2 1
 */
