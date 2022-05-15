#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ld part_A(void){
    ll n;
    cout<<"Enter n\n";
    cin >> n;
    ld arr[n];
    cout<<"Enter elements of array\n";
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    ld max = 0, max_profit=0;
    for(ll i=0; i<n-1; i++){
        for(ll j=i+1; j<n; j++){
            if(max<(arr[j]-arr[i])){max = arr[j]-arr[i];}
        }
        if(max>max_profit){max_profit=max;}
    }
    cout<<max_profit<<endl;
    return max_profit;
}

ld part_B(void){
    ll n;
    ld temp;
    cout<<"Enter n\n";
    cin >> n;
    vector<ld> v;
    cout<<"Enter elements of array\n";
    vector<ll> buy;
    vector<ll> sell;
    bool status=0;
    for(ll i=0; i<n; i++){
        cin>>temp;
        v.pb(temp);        
    }
    for(ll i=0; i<n-1; i++){
        if(v[i]<v[i+1] && status==0){
            buy.pb(i);
            status = 1;            
        }
        if(v[i]>v[i+1] && status==1){
            sell.pb(i);
            status = 0;
        }
        if(i==n-2 && v[n-2]<v[n-1] && status==1){
            sell.pb(n-1);
            status = 0;
        }
    }
    if(status==1){
        buy.pop_back();
    }
    ll size = buy.size();
    ld max_profit=0;
    for(ll i=0; i<size; i++){
        max_profit = v[buy[i]]-v[sell[i]];
    }
    cout<<max_profit<<endl;
    return max_profit;
}

ld part_C(void){
    ll n;
    ld temp;
    cout<<"Enter n\n";
    cin >> n;
    ld x=0;
    cout<<"Enter Tax Percent\n";
    cin>>x;
    vector<ld> v;
    cout<<"Enter elements of array\n";
    for(ll i=0; i<n; i++){
        cin>>temp;
        v.pb(temp);        
    }
    ld var=0;
    vector<ld> temp_profit;
    vector<ld> profit_record;
    for(ll i=0; i<n-1; i++){
        for(ll j=i+1; j<n; j++){
            if(v[j]>v[i]){
                temp = (v[j]-v[i]) - (x/100)*(v[i]+v[j]);
                temp_profit.pb(temp);
            }
        }
        var = *max_element(temp_profit.begin(), temp_profit.end());
        if(var>0){
            profit_record.pb(var);
        }
        else{
            profit_record.pb(0);
        }
        temp = 0;
        temp_profit.clear();
    }
    ld max_profit = 0, max=0;
    for(ll i=0; i<profit_record.size(); i++){
        if(profit_record[i]>0){
            if(profit_record[i]>max){
                max = profit_record[i];
            }
            if(profit_record[i]<=0){
                max_profit+=max;
                max=0;
            }
        }
        if(i==(profit_record.size()-1)&&max>0&&max_profit==0){
            max_profit+=max;
        }
    }
    cout<<max_profit<<endl;
    return max_profit;
}

int main(void){
    char c;
    cout<<"For part A, press 'A'\n";
    cout<<"For part B, press 'B'\n";
    cout<<"For part C, press 'C'\n";
    cout<<"Enter character : ";
    cin>>c;
    if(c=='A'){
        part_A();
    }
    else if(c=='B'){
        part_B();
    }
    else{
        part_C();
    }
    return 0;
}