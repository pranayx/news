#include <iostream>
using namespace std;
class obst{
    float a[20], b[20], wt[20][20], c[20][20];
    int r[20][20], n;
    public:
    obst(int x){
        n = x;
    }
    void input();
    void initialization();
    void cal_cost();
    void display();
    void print(int l1, int r1);
};
void obst :: input(){
    for(int i=1; i<=n; i++){
        cout<<"[p"<<i<<"]:";
        cin>>a[i];
    }
    for(int i=0; i<=n ;i++){
        cout<<"[q"<<i<<"]:";
        cin>>b[i];
    }
}

void obst :: initialization(){
    for(int i=0; i<n; i++){
        //Diagonal
        wt[i][i] = b[i];
        c[i][i] = 0.0;
        r[i][i] = 0;
        //First above diagonal
        wt[i][i+1] = b[i] + b[i+1] + a[i+1];
        c[i][i+1] = b[i] + b[i+1] + a[i+1];
        r[i][i+1] = i+1;
    }
    wt[n][n] = b[n];
    c[n][n] = 0.0;
    r[n][n] = 0;
}

void obst :: cal_cost(){
    for(int i=2; i<=n; i++){
        for(int j=0; j<=n; j++){
            wt[j][j+i] = a[j+i] + b[j+i] + wt[j][j+i-1];
            c[j][j+i] = 9999;
            for(int k=j+1; k<=j+i; k++){
                if(c[j][j+i] > (c[j][k-1]+c[k][j+i])){
                    c[j][j+i] = c[j][k-1]+c[k][j+i];
                    r[j][j+i] = k;
                }
            }
            c[j][j+i] += wt[j][j+i];
        }
    }
}

void obst :: display(){
    cout<<"Cost is:"<<c[0][n]<<endl;
    cout<<"Root is:"<<r[0][n]<<endl;
    cout<<"Weight is:"<<wt[0][n]<<endl;
}

void obst :: print(int l1, int r1){
    if(l1>=r1){
        return;
    }
    if(r[l1][r[l1][r1]-1] != 0){
        cout<<"Left child of "<<r[l1][r1]<<" is:"<<r[l1][r[l1][r1]-1]<<endl;
    }
    if(r[r[l1][r1]][r1] != 0){
        cout<<"Right child of "<<r[l1][r1]<<" is:"<<r[r[l1][r1]][r1]<<endl;
    }
    print(l1, r[l1][r1]-1);
    print(r[l1][r1], r1);
}
int main(){
    obst o(4);
    o.input();
    o.initialization();
    o.cal_cost();
    o.display();
    o.print(0, 4);
    return 0;
}