//https://school.programmers.co.kr/learn/courses/30/lessons/118666
//성격 유형 검사하기

def solution(survey, choices):
    dic = {'R': 0, 'T':0, 'C':0, 'F':0, 'J':0, 'M':0, 'A':0, 'N':0}
    for i in range(len(survey)):
        if choices[i] >= 4:
            dic[survey[i][1]] += choices[i] - 4
        else:
            dic[survey[i][0]] += abs(choices[i] - 4)
        
    answer = ''
    if dic['R'] >= dic['T']:
        answer += 'R'
    else:
        answer += 'T'

    if dic['C'] >= dic['F']:
        answer += 'C'
    else:
        answer += 'F'

    if dic['J'] >= dic['M']:
        answer += 'J'
    else:
        answer += 'M'

    if dic['A'] >= dic['N']:
        answer += 'A'
    else:
        answer += 'N'
        
    return answer

//딕셔너리를 이용한 단순 구현문제