#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
struct {
int node,prop=0;
}tree[MAX*3];
int array_inp[MAX];


void built(int node,int beginn,int endd){
if(beginn==endd){
    tree[node].node=array_inp[endd];
    return;
}
int left=node*2;int right=left+1;
int mid=(beginn+endd)/2;
built(left,beginn,mid);
built(right,mid+1,endd);
tree[node].node=tree[left].node+tree[right].node;
}

void update(int node,int beginn,int endd,int index,int newvalue){
if(index<beginn||index>endd)return;
if(beginn==endd){tree[node].node=newvalue;return;}
int left=node*2;int right=left+1;
int mid=(beginn+endd)/2;
update(left,beginn,mid,index,newvalue);
update(right,mid+1,endd,index,newvalue);
tree[node].node=tree[left].node+tree[right].node;
}

int query(int node,int beginn,int endd,int start_range,int end_range){
if(start_range<beginn || end_range>endd || start_range>endd)
    return 0;
if(start_range<=beginn && end_range>=endd)
    return tree[node].node;
int left=node*2;int right=left+1;
int mid=(beginn+endd)/2;
int left_node_value=query(left,beginn,mid,start_range,end_range);
int right_node_value=query(right,mid+1,endd,start_range,end_range);
return left_node_value+right_node_value;
}

int main(){
int array_size;
cin>>array_size;
for(int i=1;i<=array_size;i++){

    cin>>array_inp[i];
}
built(1,1,array_size);

int number_of_query;cin>>number_of_query;
for(int j=0;j<number_of_query;j++){
    int query_type;cin>>query_type;
    if(query_type==1){
        int index,newvalue;cin>>index>>newvalue;
        update(1,1,array_size,index,newvalue);
    }
    else if(query_type==2){
        int start_range,end_range;cin>>start_range>>end_range;
        cout<<query(1,1,array_size,start_range,end_range)<<endl;
    }
}

}
