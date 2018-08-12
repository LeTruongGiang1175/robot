#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//  tao 1 do thi moi voi moi dinh cua do thi la 2 dinh cua do thi cu

int w[100][100], h[100][100], truoc[100][100], a, b, c, d, r, n, m;
int g[100][100][100][100];
bool chuaxet[100][100];

int min(int a, int b) {
	if (a<b) return a; else return b;

}

void BFS(int x, int y) {
	queue<int> Q;
	Q.push(x*100+y);
	chuaxet[x][y]=false;
	while (!Q.empty()) {
		int z=Q.front();
		Q.pop();
		int u=z/100, v=z%100;
		for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (chuaxet[i][j] && g[u][v][i][j]==1) {
				Q.push(i*100+j);
				chuaxet[i][j]=false;
				truoc[i][j]=z;
			}
	}
}	// duyet BFS


main(){
	cout<<"nhap so dinh va so canh"<<endl;
	cin>>n>>m;
	cout<<endl;
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		{
			if (i==j) {
				w[i][j]=0;
				h[i][j]=1;
			} else w[i][j]=999999; 
			chuaxet[i][j]=true;			// dinh (i, j) chua xet
		}
	cout<<"nhap cac canh va khoang cach"<<endl;
	for (int i=0; i<m; i++){
		int x, y;
		cin>>x>>y; cin>>w[x][y]; w[y][x]=w[x][y];
		h[x][y]=1; h[y][x]=1;				// h[x][y]=1 tuc la x gan ke y;
	}
	cout<<"nhap cac dinh bat dau, ket thuc va chi so r"<<endl;
	cin>>a>>b>>c>>d>>r;
	for (int k=1; k<=n; k++)
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
		w[i][j]=min(w[i][j], w[i][k]+w[k][j]); 
		// w[i][j] la khoang cach ngan nhat tu i den j
	
	if (a==c && b==d && w[a][b]>r) 
		cout<<"Duong di ngan nhat la:"<<endl<<a<<" "<<b<<endl<<c<<" "<<d; // robot dung yen
	else {
		for (int x1=1; x1<=n; x1++)
	for (int y1=1; y1<=n; y1++)
	for (int x2=1; x2<=n; x2++)
	for (int y2=1; y2<=n; y2++)
	if (h[x1][x2]==1 && h[y1][y2]==1 && w[x1][y1]>r && w[x2][y2]>r) g[x1][y1][x2][y2]=1;
        // neu dinh x1 ke dinh x2 && dinh y1 ke dinh y2 && kcnn(x1, y1)>r && kcnn(x2, y2)>r thi do la 1 canh cua do thi moi
    
	BFS(a, b); // duyet BFS do thi moi
	
	if (truoc[c][d]==0) cout<<"Khong tim duoc duong di!";
	else {
	    cout<<"Tim duoc duong di sau:"<<endl;
	    stack<int> stack;
	    int x=c, y=d;
	    while (truoc[x][y]!=0){
	        stack.push(x*100+y);
	        int z=truoc[x][y];
	        x=z/100;
	        y=z%100;
	    }
	    cout<<a<<" "<<b<<endl;
	    while (!stack.empty()){
	        int z=stack.top();
	        stack.pop();
	        cout<<z/100<<" "<<z%100<<endl;
	    }
	}
	}
		
}
