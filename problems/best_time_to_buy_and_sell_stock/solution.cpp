
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minStockPriceDay = 0, profit = -1;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[minStockPriceDay] > prices[i])
            {
                minStockPriceDay = i;
            }
            else if (profit < (prices[i] - prices[minStockPriceDay]))
            {
                profit = prices[i] - prices[minStockPriceDay];
            }
        }
        return profit;
    }
};

// // TC- O(N), SC-O(1)
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int tempBuy = 0, tempSell = 0, maxProfit = 0, leastBuy = 0, highSell = 0;
//         for (int i = 0; i < prices.size(); i++)
//         {
//             if (prices[tempBuy] > prices[i])
//             {
//                 tempBuy = i;
//                 tempSell = i;
//                 continue;
//             }
//             if (prices[tempSell] < prices[i])
//             {
//                 tempSell = i;
//                 int profitBook = prices[tempSell] - prices[tempBuy];
//                 if (profitBook > maxProfit)
//                 {
//                     maxProfit = profitBook;
//                     leastBuy = tempBuy;
//                     highSell = tempSell;
//                 }
//             }
//         }
//         return maxProfit;
//     }
// };