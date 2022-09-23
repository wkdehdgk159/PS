#https://school.programmers.co.kr/learn/courses/30/lessons/72412
#순위 검색(Level 2, 문자열)

from itertools import combinations
from collections import defaultdict

def solution(info, query):
    answer = []
    applicant_dic = defaultdict(list)
    
    for inf in info:
        inf = inf.split()
        condition = inf[:-1]
        score = int(inf[-1])
        for i in range(5):
            #점수 제외 나올 수 있는 모든 조합에
            types = list(combinations([0,1,2,3], i))
            for type in types:
                tmp = condition[:]
                #-의 가능성까지 고려한 조합 추가
                for idx in type:
                    tmp[idx] = "-"
                key = ''.join(tmp)
                applicant_dic[key].append(score)
    
    for value in applicant_dic.values():
        value.sort()
        
    for q in query:
        q = q.replace("and", "").split()
        condition = ''.join(q[:-1])
        score = int(q[-1])
        cnt = 0
        if condition in applicant_dic:
            d = applicant_dic[condition]
            start = 0
            end = len(d)
	#이분탐색 lower bound 찾기
            while end > start:
                mid = (start + end) // 2
                if d[mid] >= score:
                    end = mid
                else:
                    start = mid + 1
            cnt = len(d) - end
            answer.append(cnt)
        else:
            answer.append(0)
    return answer
#다른 사람의 풀이에 조합을 사용하지 않고 모든 경우의 수를 dict에 넣어준 후 바로 이분탐색을 진행하는 코드가 있었는데 아름다웠다.