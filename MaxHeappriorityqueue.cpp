#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    private:
        int _size{1};
        vector<int> vect = {-1};
        int p(int i){return i>>1;}; // i/2 equivalent to i>>1
        int l(int i){return i<<1;}; // i*2 equivalent to i<<1
        int r(int i){return i<<1+1;};//i*2+1
    
    public:
        bool isEmpty() const {return _size == 0;};
        int getMax() const {return vect[1];};
        void insert(int val);
        void shiftUp(int i);
        int extractMax();
        void shiftDown(int i);
        void print();
};

void MaxHeap::shiftUp(int i){
    if(i > _size)return;
    if(i == 1)return;//Base case
    if(vect[i] > vect[p(i)]) {
        swap(vect[p(i)] , vect[i]);
    }
    shiftUp(p(i));
}

void MaxHeap::shiftDown(int i){
    if(i>_size)return;

    int swapID = i;
    if(l(i) <= _size && vect[i] < vect[l(i)]){
        swapID = l(i);
    }
    if(r(i) <= _size && vect[swapID] < vect[r(i)]){
        swapID = r(i);
    }
    if(swapID != i){
        swap(vect[i],vect[swapID]);
        shiftDown(swapID);
    }
    return;
}

int MaxHeap::extractMax(){
    int maxnum = vect[1];
    cout<<"Before swapping"<<vect[1]<<" "<<vect[_size]<<endl;
    swap(vect[1],vect[_size]);//We are swapping the max with min and than reducin the _size to delete the max it is still there but we will not be able to access it as it is at a index greater than our _size
    cout<<"After swapping"<<vect[1]<<" "<<vect[_size]<<endl;
    _size--;
    vect.pop_back();
    shiftDown(1);
    return maxnum;
}

void MaxHeap::insert(int val){
    if(_size+1 > vect.size()){
        vect.push_back(val);
    }
    _size++;
    // vect[_size] = val;// incrementing size by 1 and at that index we have zero in our vect so we are placing our val
    shiftUp(_size);//Shift the element up to its suitable postion
    return;
}

void MaxHeap::print(){
    for(int k=0;k<_size;k++){
        cout<<vect[k]<<" ";
    }
}

int main(){
    MaxHeap* PriorityQueue = new MaxHeap();

    PriorityQueue->insert(100);
    // PriorityQueue->print();
    // cout<<endl;

    PriorityQueue->insert(30);
    // PriorityQueue->print();
    // cout<<endl;

    PriorityQueue->insert(45);
    // PriorityQueue->print();
    // cout<<endl;
    
    PriorityQueue->insert(65);
    // PriorityQueue->print();
    // cout<<endl;

    PriorityQueue->print();
    cout<<endl;
    PriorityQueue->extractMax();
    // cout<<PriorityQueue->getMax()<<endl;

    PriorityQueue->print();
    cout<<endl;
    // PriorityQueue->extractMax();
    // // cout<<PriorityQueue->getMax()<<endl;

    // PriorityQueue->print();
    return 0;
}