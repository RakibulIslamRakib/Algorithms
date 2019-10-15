//we can update an element of the array at an specific index;


#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int arr[MAX];
int tree[MAX*3];

void built(int node,int beginn,int endd){
    if(beginn==endd){
        tree[node]=arr[endd];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beginn+endd)/2;
    built(left,beginn,mid);
    built(right,mid+1,endd);
    tree[node]=tree[left]+tree[right];

}

void update(int node,int beginn,int endd,int index,int value){
    if(index<beginn||endd<index){
        return;
    }
    if(beginn==endd){
        tree[node]=value;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beginn+endd)/2;
    update(left,beginn,mid,index,value);
    update(right,mid+1,endd,index,value);
    tree[node]=tree[left]+tree[right];

}


int query(int node,int beginn,int endd,int begrange,int endrange){
    if(begrange<=beginn && endd<=endrange){
        return tree[node];
    }
    if(endrange<beginn||endd<begrange){
        return 0;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(beginn+endd)/2;
    int qleft=query(left,beginn,mid,begrange,endrange);
    int qright=query(right,mid+1,endd,begrange,endrange);
    return qleft+qright;
}


int main(){
    int array_size;
    cin>>array_size;
    for(int i=1;i<=array_size;i++){
        cin>>arr[i];
    }
   built(1,1,array_size);

    int query_number;
    cin>>query_number;
    for (int q=0;q<query_number;q++){
        int query_type;
        cin>>query_type;
        if(query_type==1){
            int index,value;
            cin>>index>>value;
            update(1,1,array_size,index,value);
        }
        else{
            int begrange,endrange;
            cin>>begrange>>endrange;
            int x=query(1,1,array_size,begrange,endrange);
            cout<<x<<endl;
        }
    }

}

