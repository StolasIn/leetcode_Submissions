// https://leetcode.com/problems/richest-customer-wealth

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ma = -1
        for i in range(len(accounts)):
            ma=max(ma,sum(accounts[i]))
        return ma