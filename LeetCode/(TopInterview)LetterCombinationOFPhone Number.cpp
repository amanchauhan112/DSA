 vector<string> start= {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
      
        //let input =234
        
        vector<string>ans;
        
        if(digits=="")
                return ans;
       
        ans.push_back(""); //ans={""}
        
        for(int i=0;i<digits.length();i++) //for 2 and 3 and 4
        {
            vector<string>temp;
            for(auto numChars:start[digits[i]-'0']) // for abc and def and ghi of start 
            {
                for(auto s:ans)                 //for each charachter in ans vector
                {
                    temp.push_back(s+numChars);      
                }
            }
            ans.swap(temp);
            
// Stage 1 for number 2:

//     ans has {""}
//     numChars is "abc"
//     generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
//     tmp = {"a", "b","c"}
//     swap result and tmp (swap does not take memory copy) it is O(1) t.c.
//     Now result has {"a", "b", "c"}

// Stage 2 for number "2":

//     result has {"a", "b", "c"}
//     candidate is "def"
//     generate nine strings and put into tmp,
//     "a" + "d", "a"+"e", "a"+"f",
//     "b" + "d", "b"+"e", "b"+"f",
//     "c" + "d", "c"+"e", "c"+"f"
//     so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
//     swap result and tmp
//     Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }

// Stage 3 for number "3":

//     result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
//     candidate is "ghi"
//     generate 27 strings and put into tmp,
//     add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
//     add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
//     add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
//     so, tmp has
//     {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
//     "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
//     "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
//     swap result and tmp
//     Now result has
//     {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
//     "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
//     "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }

// Finally, return result.
            
        }
        
        return ans;
     // or
        
//         vector letterCombinations(string digits) {
// vector res;
// res.push_back("");
// map<char,string> map;
// map={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
// for (int i = 0; i <digits.size() ; ++i) {
// if(digits[i]<'2'||digits[i]>'9') {
// continue;
// }
// string cand=map[digits[i]];
// vector tmp;
// for (int j = 0; j < cand.size(); ++j) {
// for (int k = 0; k < res.size(); ++k) {
// tmp.push_back(res[k]+cand[j]);
// }
// }
// res=tmp;
// tmp.clear();
// }
// return res;
// }
    
