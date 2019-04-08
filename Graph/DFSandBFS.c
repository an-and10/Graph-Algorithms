#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1,reach[20],n;;

void bfs(int v) {
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 q[++r] = i;
 if(f <= r) {
 visited[q[f]] = 1;
 bfs(q[f++]);
 }
}
void dfs(int v) {
    	int i;
    	reach[v]=1;
    	for (i=1;i<=n;i++)
    	  if(a[v][i] && !reach[i]) {
    		printf("\n %d-->%d",v,i);
    		dfs(i);
    	}
    }


void main() {
		 int i,j,count=0;
		 printf("\n Enter the number of vertices:");
		 scanf("%d", &n);
		 
		 for(i=1; i <= n; i++) {
		 q[i] = 0;
		 visited[i] = 0;
		 }
		 
		 printf("\n Enter graph data in matrix form:\n");
		 for(i=1; i<=n; i++) {
			for(j=1;j<=n;j++) {
				scanf("%d", &a[i][j]);
		 }
		 }
		  char ch;
		 do
		 {
		 
		 int choice;
		
		 printf("Press 1. Traverse BFS \nPress 2. Traverse DFS\n"); 
		 scanf("%d",&choice);
		 
			 switch(choice)
			 {
			 	case 1: 
		 
				 printf("\n Enter the starting vertex:");
				 int v;
				 scanf("%d", &v);
				 bfs(v);
				 printf("\n The node which are reachable are:\n");
				 
				 for(i=1; i <= n; i++) {
				 if(visited[i])
				 printf("%d-->", i);
				 else {
				 printf("\n BFS is not possible. Not all nodes are reachable");
				 break;
				 }
				 }
				 break;
			case 2: for (i=1;i<=n;i++) {
					reach[i]=0;
					for (j=1;j<=n;j++)
					   a[i][j]=0;
				}
					dfs(1);
					printf("\n");
					for (i=1;i<=n;i++) {
						if(reach[i])
						   count++;
					}
					if(count==n)
					  printf("\n Graph is connected"); else
					  printf("\n Graph is not connected");
					  break;
			default: printf("\nYou entered a Wrong Key");
					break;
					}
					printf("\nDo you want to Continue...Press Y or N?\n");
					scanf(" %c",&ch);
				}
					while(ch=='Y' || ch=='y');
		}