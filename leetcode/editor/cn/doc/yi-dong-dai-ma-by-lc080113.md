### 解题思路
 [QQ截图20200703095728.jpg](https://pic.leetcode-cn.com/a0fcd639d0bf33692612f78e9714e7500f000789ae0ad5f31fada94a6b225dda-QQ%E6%88%AA%E5%9B%BE20200703095728.jpg)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int a=0,b=0;
        int hash[10]={0};
        int n=secret.length();
        for(int i=0;i<n;i++){
            hash[secret[i]-'0']++;
            hash[guess[i]-'0']--;
            if(secret[i]==guess[i]){
                a++;
            }
        }
        int df=0;
        for(int i=0;i<10;i++){
            if(hash[i]>0) df+=hash[i];   
        }
        b=n-a-df;
        res=to_string(a)+"A"+to_string(b)+"B";
        return res;
    }
};
```