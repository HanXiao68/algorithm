class Solution {
public:
     vector<string> res;
     vector<string> restoreIpAddresses(string s) {
      helper(s,"",4);
      return res;
    }

    void helper(string s,string out ,int k){
        if(k==0){
            if(s.empty()){
                res.push_back(out);
            }
        }
        else{
            for(int i =1;i<=3;i++){
                if(s.size() >= i&& isvalid(s.substr(0,i))){
                    if(k ==1){
                        helper(s.substr(i),out + s.substr(0,i),k-1);
                    }else{
                        helper(s.substr(i),out + s.substr(0,i)+".",k-1);
                    }
                }
            }
            
        }
    }
    bool isvalid(string s){
        if(s.empty() || s.size()>3 ||(s.size()>1 &&s[0] =='0')){
            return false;

        }
        int num = atoi(s.c_str());
        return num >=0&& num <=255;
    }
};
