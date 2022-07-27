class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        # dp=[0]*n
        # max_so_far=prices[n-1]
        # for i in range(n-2,-1,-1):
        #     if prices[i]>=max_so_far:
        #         max_so_far=prices[i]
        #         dp[i]=dp[i-1]
        #     else:
        #         dp[i]=max(dp[i+1], max_so_far-prices[i])
        # res=max(dp)
        # res_one=0
        # min_so_far=prices[0]
        # for i in range(len(prices)-1):
        #     min_so_far=min(min_so_far, prices[i])
        #     res_one=max(prices[i]-min_so_far,res_one)
        #     res=max(res,res_one+dp[i+1])
        # res=max(res, prices[len(prices)-1]-min_so_far)
        # return res
        buy1=-100000000000000
        sell1=0
        buy2=-100000000000000
        sell2=0
        for i in prices:
            buy1=max(buy1, -i)
            sell1=max(sell1,buy1+i)
            buy2=max(buy2, sell1-i)
            sell2=max(sell2, buy2+i)
        return max(sell2,sell1,0)