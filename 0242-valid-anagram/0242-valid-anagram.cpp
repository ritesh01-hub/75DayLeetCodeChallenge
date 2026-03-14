class Solution {
public:
    bool isAnagram(string s, string t) {
       // int s = s.length();
        //int t = t.lenght();
        // sort it and then check it 
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
        
    }
};