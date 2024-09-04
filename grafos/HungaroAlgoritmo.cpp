#include<bits/stdc++.h>
using namespace std;

int m[3][3] = {	{10,15,9},
				{9,10,15},
				{20,5,15}};
				
int a[3][3] = {	{0,0,0},
				{0,0,0},
				{0,0,0}};
struct cost{
	int x,y,c;
};
cost aux[3];
int main(){
	int minim;
	for(int i=0;i<3;i++){
		minim=999;
		for(int j=0;j<3;j++){
			if(m[i][j]<minim){
				minim=m[i][j];
				aux[i].x=j;
				aux[i].y=i;
				aux[i].c=m[i][j];
			}
		}
	}
	
	for(int i=0;i<3;i++){
		a[aux[i].y][aux[i].x]=aux[i].c;
	}
	for(int k=0;k<3;k++){
		switch(k){
			case 0:for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
			case 1: for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
			case 2: for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
		}
		cout<<"\n";
	}

}