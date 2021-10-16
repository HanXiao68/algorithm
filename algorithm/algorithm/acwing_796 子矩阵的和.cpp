////
////  acwing_796 子矩阵的和.cpp
////  algorithm
////
////  Created by 韩霄 on 2021/10/8.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N = 1010;
//int a[N][N],sum[N][N];
//
//int main(){
//    int n,m,q;
//    cin>>n>>m>>q;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            scanf("%d",&a[i][j]);
//            
//        }
//    }
//    
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            sum[i][j] = sum[i-1][j] +sum[i][j-1] -sum[i-1][j-1] +a[i][j];
//        }
//    }
//    while(q--){
//        int x1,y1,x2,y2;
//        int res =0;
//        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//        res = sum[x2][y2]-sum[x1-1][y2] -sum[x2][y1-1] +sum[x1-1][y1-1];
//        printf("%d\n",res);
//    }
//    return 0;
//}
//
//
