#include <bits/stdc++.h>
using namespace std;

bool LLSRecursor(int target,int* weights,int* freq)
{
    if(target == 0)
    {
        return true;
    }
    bool ret = false;
    for(int i = 25;i>=0;--i)
    {
        if(weights[i]<=target)
        {
            ++freq[i];
            ret = LLSRecursor(target - weights[i],weights, freq);
            if(ret == true)
                break;
            else
                --freq[i];
        }
    }
    return ret;
}

string LLS(int target,int* weights)
{
    int freq[26];
    for(int i=0;i<26;++i)
    {
        freq[i] = 0;
    }
    if(LLSRecursor(target,weights,freq) == true)
    {
        string answer = "";
        for(int i=25;i>=0;--i)
        {
            while(freq[i])
            {
                answer += char('a'+ i);
                --freq[i];
            }
        }
        return answer;
    }
    else
    {
        return "##### No such string exists #####";
    }
}

int main()
{
    int T,weights[26],target;
    cin >> T;
    for(int i=0;i<26;++i)
    {
        cin >> weights[i];
    }
    while(T)
    {
        cin >> target;
        cout << LLS(target,weights);
        --T;
    }
    return 0;
}
