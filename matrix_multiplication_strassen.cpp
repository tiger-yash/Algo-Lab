
#include <bits/stdc++.h>
using namespace std;

// function to add two matrices of same size 

vector < vector < int > > add( vector < vector < int > > x , vector < vector < int >> y , int n ){
    for( int i = 0 ; i < n  ; i++ ){
        for( int j = 0 ;  j < n ; j++ ){
            x[i][j] += y[i][j] ; 
        }
    }
    return x ; 
} 

// function two subtract two matrices of same size 

vector < vector < int > > sub( vector < vector < int > > x , vector < vector < int >> y , int n ){
    for( int i = 0 ; i < n  ; i++ ){
        for( int j = 0 ;  j < n ; j++ ){
            x[i][j] -= y[i][j] ; 
        }
    }
    return x ; 
} 


vector < vector < int > > mul( vector < vector < int > > x , vector < vector < int >> y , int n ){

     if( n==1 ){ x[0][0]*= y[0][0] ; return x ;  }

     vector < vector < int > > x1( n / 2 , vector < int >( n / 2  , 0 ));  
     auto x2 = x1 , x3 = x1 , x4 = x1 , y1 = x1 , y2 = x1 , y3 = x1 , y4 = x1 ;  

     // now dividing the matrices x and y in 4 sub matrices of size n/2 
     // namely x -> x1 , x2 , x3 , x4       ,     y -> y1 , y2 , y3 , y4 
     // 1 -> 1st quadrant , 2 -> 2nd quadrant , 3 -> 3rd quadrant , 4-> 4th quadrant 
     

     for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i < n/2 and j < n/2 ){
                x1[i][j] = x[i][j] ; 
            }else if ( i >= n/2  and j < n/2 ){
                x3[i-n/2][j] = x[i][j];
            }else if ( i < n/2 and j >= n/2 ){
                x2[i][j-n/2] = x[i][j];
            }else{
                x4[i-n/2][j-n/2] = x[i][j] ; 
            }
        }
     }

     for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i < n/2 and j < n/2 ){
                y1[i][j] = y[i][j] ; 
            }else if ( i >= n/2  and j < n/2 ){
                y3[i-n/2][j] = y[i][j];
            }else if ( i < n/2 and j >= n/2 ){
                y2[i][j-n/2] = y[i][j];
            }else{
                y4[i-n/2][j-n/2] = y[i][j] ; 
            }
        }
     }

     // auto m1 = mul ( add(x1 , x3 , n/2 ) , add( y1 , y2 , n/2 ) , n/2 ) ; // (a+c)(e+f)
     // auto m2 = mul ( add(x2 , x4 , n/2 ) , add( y3 , y4 , n/2 ) , n/2 ) ; // (b+d)(g+h)
     // auto m3 = mul ( sub(x1 , x4 , n/2 ) , add( y1 , y4 , n/2 ) , n/2 ) ; // (a-d)(e+h)
     // auto m4 = mul ( x1 , sub( y2 , y4 , n/2 ) , n/2 ) ; // a(f-h)
     // auto m5 = mul ( add(x3 , x4 , n/2 ) , y1 , n/2 ) ;  // (c+d)e
     // auto m6 = mul ( add(x2 , x1 , n/2 ) , y4 , n/2 ) ;  // (a+b)h
     // auto m7 = mul ( x4 , sub( y3 , y1 , n/2 ) , n/2 ) ; // d(g-e)

     // auto r1 = sub( add( m2 , m3 , n/2 )  , add(m7 , m6 , n/2), n/2); // (m2+m3)-(m6+m7)
     // auto r2 = add( m4 , m6 , n/2 ); // m4 + m6
     // auto r3 = add( m5 , m7 , n/2 ); // m5 + m7
     // auto r4  = sub( m1 , add( m3 , add( m4 , m5 , n/2) , n/2 )  , n/2 ); // m1-(m3+m4+m5)


     auto p1 = mul ( x1 , sub( y2 , y4 , n/2 ) , n/2 ) ; // a(f-h)
     auto p2 = mul ( add(x1 , x2 , n/2 ) , y4 , n/2 ) ; // (a+b)h
     auto p3 = mul ( add(x3 , x4 , n/2 ) , y1 , n/2 ) ; // (c+d)e
     auto p4 = mul ( x4 , sub( y3 , y1 , n/2 ) , n/2 ) ; // d(g-e)
     auto p5 = mul ( add(x1 , x4 , n/2 ) , add(y1,y4,n/2) , n/2 ) ;  // (a+d)(e+h)
     auto p6 = mul ( sub(x2 , x4 , n/2 ) , add(y3,y4,n/2) , n/2 ) ;  // (b-d)(g+h)
     auto p7 = mul ( sub(x1,x3,n/2) , add( y1 , y2 , n/2 ) , n/2 ) ; // (a-c)(e+f)

     auto r1 = sub( add( p5 , p4 , n/2 )  , sub(p2 , p6 , n/2), n/2); // (p5+p4)-(p2-p6)
     auto r2 = add( p1 , p2 , n/2 ); // p1 + p2
     auto r3 = add( p3 , p4 , n/2 ); // p3 + p4
     auto r4  = sub( add(p1,p5,n/2) , add( p3 , p7 , n/2 )  , n/2 ); // (p1+p5)-(p3+p7)

     auto r = x ; 

     for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i < n/2 and j < n/2 ){
                r[i][j] = r1[i][j] ; 
            }else if ( i >= n/2  and j < n/2 ){
                r[i][j] = r3[i-n/2][j];
            }else if ( i < n/2 and j >= n/2 ){
                r[i][j] = r2[i][j-n/2];
            }else{
                r[i][j] = r4[i-n/2][j-n/2] ; 
            }
        }
     }

     return r ; 
} 


int main(){
    // pxq is the size of the first matrix and qxr is the size of the second matrix 
    // as the no of columns in first should be equal to no of rows in second 
    cout<<"Enter p,q,r i.e. dimensions of matrix 1 (pxq) & matrix 2 (qxr) : "<<endl;
    int p , q , r ; cin>>p>>q>>r;      

    int n = max( p , max( q , r ) ) ; 
    for( int i = 0 ; i <= 30 ; i++ ){
        if( (1<<i) >= n ){ n = (1<<i) ; break ;  }
    }
    // here n is the nearest greater power of 2 for each p , q , r  

    vector < vector < int > >  x( n , vector < int >( n , 0 )) , y( n , vector < int >( n , 0 )); 

    cout<<"Enter matrix 1 : "<<endl;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i >= p or j >= q ){
                x[i][j] = 0 ;
            }else{
                cin>>x[i][j]; 
            }
        }
    }

    cout<<"Enter matrix 2 : "<<endl;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i >= q or j >= r ){
                y[i][j] = 0 ;
            }else{
                cin>>y[i][j]; 
            }
        }
    }

    auto v = mul( x , y , n ); 
    // returns the multiplication of the two matrices 

    for( int i = 0 ; i < p ; i++ ){
        for( int j = 0 ; j < r ; j++ ){
            cout<<v[i][j]<<' '; 
        }
        cout<<'\n'; 
    }
    
return 0;
}
     
   
               
   

