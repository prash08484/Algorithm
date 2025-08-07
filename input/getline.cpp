// parse line by line 


void solve(){  

  int m; cin>>m; 

   // consume the buffer of m : m\n 
  string s;
  getline(cin,s);

  while(m--){

    // read entire line 
    getline(cin,s); 

    // put in a stream 
    istringstream iss(s);

    int l,r;
    iss>>l>>r; 

    int v; 
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
