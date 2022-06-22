// https://leetcode.com/problems/matrix-cells-in-distance-order

class Solution:
    def allCellsDistOrder(self, r: int, c: int, rc: int, cc: int) -> List[List[int]]:
        q = deque()
        q.append([rc,cc])
        ans=[];
        vis=[[False for i in range(c)] for j in range(r)];
        while q :
            t = q.popleft()
            
            if t[0]<0 or t[0]>=r or t[1]<0 or t[1]>=c :
                continue

            if(vis[t[0]][t[1]]==True):
                continue
                
            vis[t[0]][t[1]]=True
            ans.append(t)
            q.append([t[0]-1,t[1]])
            q.append([t[0],t[1]-1])
            q.append([t[0]+1,t[1]])
            q.append([t[0],t[1]+1])
        
        return ans
        