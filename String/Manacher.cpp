// longest Palindromic Substring in O(n)
vector<int>manacher(string &str){

  //  string transform for odd length handling
  //  insert # between each char

  string s=""; 
  for(char &it:str)
    s+=string("#")+it; 
  s+="#";

  int n=s.size();
  s="$" +s+ "^"; // to ensure end of string 
   
  vector<int>p(n+2,0); // radius of palindrome,center at i
  int l=0,r=0;
  
  for(int i=1;i<=n;i++){
    int j=l+r-i; // mirror pos of i wrt [l,r]
  
    p[i]=max(0,min(r-i,p[j]));

    while(s[i-p[i]]==s[i+p[i]])
      p[i]++; 
  
    // update [l,r]
    if(i+p[i]>r){
      l=i-p[i];
      r=i+p[i]; 
    }
  }

  return p;

}

 
