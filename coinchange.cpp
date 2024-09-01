#include <cinttypes>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> init_vector(){
    vector<int> c = {1,5,10,25,50};
    return c;
}
int tabulation_dp_slove_coinchange(int arr[][6],int i,int j){
    vector<int> v = init_vector();
    // vector<int> arr [i];
    arr[0][0] = 1;
    arr[1][1] = 1;

    for(int y = 0 ; y <= j;y++ ){
        arr[1][y] = 1;
        arr[0][y] = 1;
    }
    for(int x = 0 ; x <= i;x++ ){
        arr[x][1] = 1;
    }
    for(int x = 2;x <= i;x++){
        for(int y = 2 ; y <= j ; y++){
            if((x- v[y-1]) >= 0){
                arr[x][y] =  arr[x][y-1] +  arr[x-v[y-1]][y];
            }else{
                arr[x][y] =  arr[x][y-1];
            }
        }
    }
    // for(int x = 0 ; x <= i; x++){
    //     cout  << x << " : ";
    //     for(int y = 0; y <= 5;y++ ){
    //         cout << arr[x][y] << " ";
    //     }
    //     cout << endl;
    // }
    return arr[i][j];
}
int main(){
    int c;
    while(!cin.eof()){

        cin >> c;
        if(cin.eof()){
            break;
        }
         int arr [c+1][6];
        for(int i = 0 ; i <= c; i++){
            for(int j = 0; j <= 5;j++ ){
                arr[i][j] = 0;
            }
        }
        // for(int i = 0 ; i <= c; i++){
        //     for(int j = 0; j <= 5;j++ ){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int witee = tabulation_dp_slove_coinchange(arr,c,5);
        cout << witee << endl;
    }
    return 0;
}
