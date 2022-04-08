#include "bits/stdc++.h"
using namespace std;


class MaxPriorityQueue {
    private:
        vector<int> pq;

   public:
    void insert(int element) {
        pq.push_back(element) ;
        int ci = pq.size()-1 ;
        int pi = (ci-1)/2 ;
        while(ci>=0){
            if(pq[pi]<pq[ci]){
                swap(pq[ci],pq[pi]) ;
            }else{
                break ;
            }
            ci = pi ;
            pi = (ci-1)/2 ;
        }
        return ;
    }

    int getMax() {
        if(pq.size()==0){
            return 0 ;
        }
        return pq[0] ;
    }

    int removeMax() {
        int ans = pq[0] ;
        swap(pq[0],pq[pq.size()-1]) ;
        pq.pop_back() ; 
        int pi = 0 ;
        
        while(2*pi+1 < pq.size()){
            int c1 = 2*pi + 1 ;
            int c2 = 2*pi+2 ;
            int c ;
            
            if(c2>=pq.size()){
                c = c1 ;
            }else{
                if(pq[c1] >= pq[c2]){
                    c = c1 ;
                }else{
                    c = c2 ;
                }
            }
            
            if(pq[pi]<pq[c]){
                swap(pq[pi],pq[c]) ;
            }else{
                break ;
            }
            
            pi = c ;
        }
        return ans ;
    }

    int getSize() { 
        return pq.size() ;
    }

    bool isEmpty() {
        return getSize()==0 ;
    }
    ~MaxPriorityQueue(){
        cout<<endl<<"See You!"<<endl;
    }
};

int main() {
    MaxPriorityQueue pq;
    cout << "Size of heap: ";
    int size; cin >> size;
    cout << "Enter the array to heapify: ";
    for(int i = 0; i < size; i++){
        int temp; cin >> temp;
        pq.insert(temp);
    }
    int choice;
    cout<<endl<<"---Menu---"<<endl<<endl;
    cout<<"1. Insert\n2. Get Maximum\n3. Remove Maximum\n4. Get Size\n5. Check if Empty\n6. Exit"<<endl<<endl;
    cout<<"Enter Choice : ";
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << "Max removed : "<< pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "Empty" : "Not Empty")<<endl;
                break;
            case 6:
                return 0;
        }
        cout<<"Enter Choice : ";
        cin >> choice;
    }

}