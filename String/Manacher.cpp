// longest Palindromic Substring in O(n)
vector<int>manacher_odd(string &s){

int n=s.size();
s="$" +s+ "^"; // to ensure end of string 
 
vector<int>p(n+2); 
int l=0,r=1;

for(int i=1;i<=n;i++){
  int j=l+r-i; // mirror pos of i wrt [l,r]

  p[i]=min(r-i,p[j]);
  while(s[i-p[i]]==s[i+p[i]]){
    p[i]++; }

// update [l,r]
  if(i+p[i]>r){
    l=i-p[i],r=i+p[i]; }
}

return vector<int>(begin(p)+1,end(p)-1); 

}

vector<int> manacher(string &s){
    string t=""; // make odd string 
    for(char &it:s){
        t+=string("#")+it; }
    vector<int>p=manacher_odd(t+"#");
    return vector<int>(begin(p)+1,end(p)-1); 
}
