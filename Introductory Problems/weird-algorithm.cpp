#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s(n,'0');
    int indx = n-1;
    int fix = n-3;
    char f = '1';
    if(n == 2){
        int tmp = indx;
        while(tmp >= -1){
            cout<<s<<endl;
            if(tmp >= 0){
                s[tmp] = '1';
            }
            --tmp;
        }
        tmp = indx;
        while(tmp >= 1){
            s[tmp] = '0';
            cout<<s<<endl;
            --tmp;
        }
        return 0;
    }
    while(fix >= 0){
        for(int i = 1; i <= 2; ++i){
            f = f == '1'?'0':'1';
            int tmp = indx;
            while(tmp >= fix){
                for(int i = 0; i < n; ++i){
                    if(i == fix){
                        cout<<f;
                    }else{
                        cout<<s[i];
                    }
                }
                cout<<endl;
                s[tmp]= '1';
                --tmp;
            }
            tmp = indx;
            while(tmp > fix+1){
                s[tmp] = '0';
                for(int i = 0; i < n; ++i){
                    if(i == fix){
                        cout<<f;
                    }else{
                        cout<<s[i];
                    }
                }
                cout<<endl;
                --tmp;
            }
            s[tmp] = '0';
        }
        --indx;
        --fix;
    }
    

}
