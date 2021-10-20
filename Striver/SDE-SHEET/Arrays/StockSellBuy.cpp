/*
Approaches
-----------
1) Brute force -> TC :o(n^2) , SC: o(1)
2) efficient -> TC: o(n) , SC: o(1)
*/

// brute force

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int i = 0, j = 1, profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {

            for (int j = i + 1; j < prices.size(); j++)
            {

                if (prices[j] > prices[i])
                {
                    profit = max(profit, prices[j] - prices[i]);
                }
            }
        }

        return profit;
    }
};

// efficient approach

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int min = INT_MAX, profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {

            if (prices[i] < min)
                min = prices[i];

            profit = max(profit, prices[i] - min);
        }

        return profit;
    }
};
