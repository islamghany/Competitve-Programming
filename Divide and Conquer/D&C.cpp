#include <bits/stdc++.h>
using namespace std;
int num;
int values[8]={20,5,1,13,6,11,40};
int numberFactor(int n){
  if(n > num) return 0;
  if(n==num) return 1;
  return numberFactor(n+1)+numberFactor(n+3)+numberFactor(n+4);
}

int houseThief(int i){
  if(i >= 7) return 0;
  return max(houseThief(i+1),houseThief(i+2)+values[i]);
}

string s="tableeeeee",p="tab";
int n=5,m=6;
int convertStringWithMin(int i,int j){
  if(i>= n || j>=m) return 0;
  if(i == n && j<m)return m-j;
  if(i==n)return abs(i-j);
  if(s[i] == p[j]) return convertStringWithMin(i+1,j+1);
  else
    return min(min(convertStringWithMin(i+1,j)+1,convertStringWithMin(i+1,j+1)+1),convertStringWithMin(i,j+1)+1);

}

int W=7,val[4]={31,26,72,17},wght[4]={3,1,5,2};
int knapsack(int n,int i){
   if(i>=4 || n==0) return 0;
   if(wght[i]>n) return knapsack(n,i+1);
   return max(knapsack(n,i+1) , knapsack(n-wght[i],i+1)+val[i]);
}
int maxContSub(int i,int j,string s, string p){
  if(i>=s.size() || j>=p.size()) return 0;
  int ch0=0,ch1=0;
  if( s[i]==p[j]) ch0= maxContSub(i+1,j+1,s,p)+1;
  ch1= max(max(maxContSub(i+1,j,s,p),maxContSub(i+1,j+1,s,p)),maxContSub(i,j+1,s,p));
  return max(ch0,ch1);
}
int longPlindroomSubseq(int i ,int j,string s){
  if(i>j)return 0;
  if(i==j) return s[i]==s[j];
  int ch0=0,ch1=0;
  if(s[i]==s[j]) ch0=longPlindroomSubseq(i+1,j-1,s)+2;
  ch1=max(longPlindroomSubseq(i,j-1,s),longPlindroomSubseq(i+1,j,s));
  return max(ch1,ch0);
}

int longPlindroomSubstr(int i,int j ,string s){
     if(i>j)return 0;
     if(i==j) return s[i]==s[j];
     int ch0=0,ch1=0;
     if(s[i]==s[j]){
       int rem =i-j-1;
       if(rem == longPlindroomSubstr(i+1,j-1,s)) ch0=rem+2;
       }
       ch1=max(longPlindroomSubstr(i,j-1,s),longPlindroomSubstr(i+1,j,s));
         return max(ch1,ch0);

}

int a[100][100];
int n1,m1,sum;
bool valid(int i ,int j){
  return (i<n1 && i>=0 &&j<m1&&j>=0);
}
int minCostLastCell(int i , int j){
  if(!valid(i,j))return 1000;
  if(i==n1-1 && j==m1-1) return a[n1-1][m1-1];
  return min(minCostLastCell(i+1,j)+a[i][j],minCostLastCell(i,j+1)+a[i][j]);

}
int numOfPathToLastCell(int i,int j,int l){
  if(!valid(i,j) || l > sum)return 0;
  if(i==n1-1 && j==m1-1){
    if(sum == l) return 1;
    return 0;
  }
  int res=0;
   res+=numOfPathToLastCell(i+1,j,l+a[i][j])+numOfPathToLastCell(i,j+1,l+a[i][j]);
  return res;
}
int main() {

  //4 5 25 0 3 1 2 9 7 3 4 9 9 1 7 5 5 3 2 3 4 2 5
  cin>>n1>>m1>>sum;
  for(int i=0;i<n1;i++){
    for(int j=0;j<m1;j++){
      cin>>a[i][j];
    }
  }
  cout<<numOfPathToLastCell(0,0,0);
}
