#include "bits/stdc++.h"
using namespace std;


class MinPriorityQueue {
    private:
        vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(pq.size()==0){
            return 0 ;
        }
        int ans = pq[0] ;
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int pi = 0 ;
        while(2*pi+1 < pq.size()){
            int c1 = 2*pi+1 ;
            int c2 = 2*pi+2 ;
            int c;
            if(c2>=pq.size()){
                c = c1 ;
            }else{
                if(pq[c1]<pq[c2]){
                    c = c1 ;
                }else{
                    c = c2 ;
                }
            }
            
            if(pq[pi] > pq[c]){
                swap(pq[pi],pq[c]) ;
            }else{
                break ;
            }
            pi = c ;
           
        }
        return ans ;
    }
};

int main() {
    MinPriorityQueue pq;
    cout<<"---Minimum Priority Queue---"<<endl<<endl;
    cout<<"1. Insert\n2. Get Minimum\n3. Remove Minimum\n4. Get Size\n5. Check if Empty\n6. Exit"<<endl<<endl;
    cout<<"Enter Choice : ";
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cout<<"Enter Number : ";
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMin
                cout << "Min removed : "<<pq.removeMin() << "\n";
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