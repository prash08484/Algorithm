// parse line by line 

void solve(){  
  
  ll n; 
  cin>>n;   

   vll a(n); 
  read(a);  

  ll m; cin>>m; 

   // consume the buffer of m : m\n 
  string s;
  getline(cin,s);

  while(m--){

    // read entire line 
    getline(cin,s); 

    // put in a stream 
    istringstream iss(s);

    ll l,r;
    iss>>l>>r; 

    ll v; 
    if(iss>>v){ 
        // l,r,v
        // update

    }
    else{  
        // l,r
        // query 

    }



  }


  
}
