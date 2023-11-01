dp[t^1][j] == dp[t^1][j+1]) 
                num[t^1][j+1] += num[t^1][j];
            if(dp[t][j+1] == dp[t^1][j+1]) 
                num[t^1][j+1] += num[t][j+1];
            if(dp[t^1][j+1] == dp[t][j]) 
                n