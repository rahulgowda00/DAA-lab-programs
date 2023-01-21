#include<stdio.h>

int main(){    
    int n,a[20][20],i,j,min,mincost,u,v,ne,vis[20];    
    printf("Enter the number of nodes\n");    
    scanf("%d",&n);    
    for(i=1;i<=n;i++) 
        vis[i]=0;    
    printf("Enter the Cost matrix or Adjacency matrix\n");    
    for(i=1;i<=n;i++){ 
        for(j=1;j<=n;j++){     
            scanf("%d",&a[i][j]);      
            if(a[i][j]==0){  
                a[i][j]=999;     
            } 
        }    
    }    
    vis[1]=1;    
    ne=1;   
    mincost=0;    
    while(ne<n){ 
        for(i=1,min=999;i<=n;i++){     
            for(j=1;j<=n;j++){  
                if((a[i][j]<min) && (vis[i]!=0)){      
                    min=a[i][j];      
                    u=i;      
                    v=j;
                }     
            } 
        } 
        if(vis[v]==0){
            printf("Edge %d : (%d %d) cost %d\n", ne,u,v,a[u][v]);     
            mincost+=a[u][v];     
            ne+=1;     
            vis[v]=1; 
        } 
        a[u][v]=a[v][u]=999;    
    }    
    printf("Minimum Cost = %d\n",mincost);
}